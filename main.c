/* ========================================
 EE 4450 - Project by Team 10
 Carlos Ochoa
 Vincent Oviedo
 
===========================================
 Station 1
===========================================
SYSTEM
lcd 2[6:0]
uart 12[6,7]

INPUT 
tempin 3.2
tempout 3.4
pres 3.6

OUTPUT

uv light 1.4
servo 1.5
fan 1.6
hpad 1.7


SENSOR -> QUEUE                                       TASK 1
          QUEUE -> LCD                                TASK 2
(send)    QUEUE -> UART                               TASK 3
(recieve)          UART -> ISR -> MSG                 TASK 3
                                  MSG -> OUTPUT       TASK 4
===========================================
            
*/

#include "project.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>
//FREERTOS headers
#include "FreeRTOS_PSoC.h"
#include "FreeRTOS.h"
#include "task.h"
#include "timers.h"
#include "queue.h"
#include "event_groups.h"
#include "semphr.h"
#include "message_buffer.h"
/*
TODO DONE!
Finish Main x
create message buffer x
Write Messages
create tasks x
write tasks codeX
Write Queuex
ADD ISR X

Verify UART speaksX
manually test sensors x
*/

// global variables
MessageBufferHandle_t   xMessageBuffer = NULL; 
#define MESSAGE_BUFFER_SIZE 100
TaskHandle_t    		xTask4;

//our sensor structure
typedef struct Sensors {
    uint8_t     id;
    double      data[4];
   } Sensors;

//Queue info
#define QUEUE_LENGTH	8
#define QUEUE_ITEM_SIZE sizeof(Sensors)
QueueHandle_t 			xQueue = NULL;

//ISR stuff
CY_ISR_PROTO(MyUartISR);

// Creating our 4 task functions
void     vGetData       (void *pvParameters);
void     vDisplayData   (void *pvParameters);
void     vUARTComm      (void *pvParameters);
void     vTasks         (void *pvParameters);
float    GetTemp        (void);
bool     GetTemp2       (float *Temp);

void MyPSOCSetup();

int main(void)
{
    
    BaseType_t  err;
    //CyGlobalIntEnable; /* Enable global interrupts. */
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    
    //Starting up all our services, AMUX, RTOS, ADC, SERVO
    AMUX_Start();
    MyPSOCSetup();
    SARADC_Start();
    FreeRTOS_Init();
    SERVOPWM_Start();
    
    //Making message buffer
    xMessageBuffer = xMessageBufferCreate(MESSAGE_BUFFER_SIZE);
    
    
    if (xMessageBuffer == NULL) {
        // If message buffer was NOT created successfully
        LCD_Position(1,0);    
        LCD_PrintString("Can't create MsgBuf");
        while(1);
    }
       
    //MAKE QUEUE
	xQueue = xQueueCreate(QUEUE_LENGTH, QUEUE_ITEM_SIZE);
    if (xQueue == NULL) {
        LCD_Position(1,0);    
        LCD_PrintString("QUEUE ERROR");
        while(1);
    }
   
    // Create Tasks
    err = xTaskCreate ( vGetData, //TaskFunction_t  pvTaskCode,
                            "LCD Task", 
                            configMINIMAL_STACK_SIZE,
                            NULL, //void *pvParameters,
                            configMAX_PRIORITIES-1, //ubasetype_t uxpriority
                            NULL //taskhandle
    );
    
    if (err != pdPASS){
        LCD_Position(1,0);
        LCD_PrintString("Cannot create Task!");
        while(1){};
    }
     err = xTaskCreate ( vDisplayData, //TaskFunction_t  pvTaskCode,
                            "Show Readings", 
                            configMINIMAL_STACK_SIZE,
                            NULL, //void *pvParameters,
                            configMAX_PRIORITIES-1, //ubasetype_t uxpriority
                            NULL //taskhandle
    );
    if (err != pdPASS){
        LCD_Position(1,0);
        LCD_PrintString("Cannot create Task!");
        while(1){};
    }
	
     err = xTaskCreate ( vUARTComm, //TaskFunction_t  pvTaskCode,
                            "UART SynC", 
                            configMINIMAL_STACK_SIZE,
                            NULL, //void *pvParameters,
                            configMAX_PRIORITIES-1, //ubasetype_t uxpriority
                            NULL //taskhandle
    );
    if (err != pdPASS){
        LCD_Position(1,0);
        LCD_PrintString("Cannot create Task!");
        while(1){};
    }
	
     err = xTaskCreate ( vTasks, //TaskFunction_t  pvTaskCode,
                            "Adujusting Greenhouse", 
                            configMINIMAL_STACK_SIZE,
                            xMessageBuffer, //void *pvParameters,
                            6, //ubasetype_t uxpriority
                            NULL //taskhandle
    );
    if (err != pdPASS){
        LCD_Position(1,0);
        LCD_PrintString("Cannot create Task!");
        while(1){};
    }
    //start scheduler
    vTaskStartScheduler();
    
    for(;;)
    {
        /* Place your application code here. */
    }
}
void MyPSOCSetup()
{
    LCD_Start();
    LCD_ClearDisplay();
    LCD_Position(0,0);
    LCD_PrintString("EE4450 FREERTOS");
    LCD_ClearDisplay();
    CyDelay(1000);
    
    ISR_UART_StartEx(MyUartISR);
    UART_Start();
    UART_ClearRxBuffer();
    UART_ClearTxBuffer();
    //UART_PutString("Team 10 Greenhouse Final!");
    
}

//----------------------------
typedef enum STATES{
    S_IDLE,
    S_GOTDATA
} STATES;
#define START_CHAR '+'
#define STOP_CHAR ';'
//-----------------------------------------
CY_ISR(MyUartISR)
{
    static  char    buf[20];
    static  STATES  state = S_IDLE;
    static  int     idx = 0;
    char            ch;
    
    BaseType_t      xHigherPriorityTaskToken = pdFALSE; // Initialized to pdFALSE
    
    while ( UART_GetRxBufferSize() > 0) {   // As long as this function gives us any number bigger than 0, we still have more data!
        ch = UART_GetChar();
        if (ch == '\0')
            continue;   // go back to while loop
        switch (state) {
            case S_IDLE:
                if (ch == START_CHAR) {
                    idx = 0;
                    state = S_GOTDATA;
                 }            
                break;
            case S_GOTDATA:
                if (idx > 19) {
                    state = S_IDLE;
                } else if (ch == STOP_CHAR) {
                    buf[idx] = '\0';
                    idx++;
                    xMessageBufferSendFromISR(xMessageBuffer, buf, idx, &xHigherPriorityTaskToken);
                    state = S_IDLE;
                } else {
                    buf[idx] = ch;
                    idx++;
                }
                break;
        }
    }
    
    UART_ReadRxData();  // Clear UART INT signal
}
/*Read data from PhotoResistor, OutTEMP, InTemp, Humidifier.
 output to queue buffer */
void vGetData(void *pvParameters)
{
    Sensors 	sens;
    uint8_t     i=0;
    
    while(1){
        //AMUX loop, we're pulling data in this order
        for (i = 0; i < 3; i++){
            AMUX_Select(i);
            CyDelayUs(15);
            SARADC_StartConvert();
            SARADC_IsEndConversion(SARADC_WAIT_FOR_RESULT);
            if (i == 0) {
                sens.data[i] = SARADC_GetResult16();
            } 
            else if ((i == 1 ) | (i == 2)){
                sens.data[i] = GetTemp();
            }            
        }
        
        // Convert PhotoResistor to high low sensor > 105 means its bright out so we set the variable to 0.
        if (sens.data[0] > 105){
            sens.data[0] = 0;
        }else{
            sens.data[0] = 1;
        }
        
        //clean temperature data
        for (i = 0; i < 2; i++){  
            sens.data[i+1] = log(10000.0 * (256.0/sens.data[i+1] - 1));
            sens.data[i+1] = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * sens.data[i+1] * sens.data[i+1]))* sens.data[i+1]);
            sens.data[i+1] = sens.data[i+1] - 273.15;  
        }
        
       while (xQueueSendToBack(xQueue, &sens, pdMS_TO_TICKS(10)) != pdPASS){};
	   while (xQueueSendToBack(xQueue, &sens, pdMS_TO_TICKS(10)) != pdPASS){};
       vTaskDelay( pdMS_TO_TICKS(2000)); //Delay for 20ms
       }
}


//Show our data locally via message/buffer on LCD screen
void vDisplayData(void *pvParameters)
{
   char        str[5];
   Sensors      sens;
    
    while(1){
        if (xQueueReceive(xQueue, &sens, 0) == pdPASS){
            
            if (sens.data[0] == 1){
                LCD_Position(0,0);
                sprintf(str, "No Sunlight");
                LCD_PrintString(str);
            }
            else if (sens.data[0] == 0){
                LCD_Position(0,0);
                sprintf(str, "Sunlight OK");
                LCD_PrintString(str);
            }
            sprintf(str, "OT%3.0f", sens.data[2]);
            LCD_Position(1,0);
            LCD_PrintString(str);
            sprintf(str, "IT%2.0f", sens.data[1]);
            LCD_Position(1,7);
            LCD_PrintString(str);
        
        }
        
}
    vTaskDelay(pdMS_TO_TICKS(1000)); //delay for 500ms
}

//send or recieve UART data
void vUARTComm(void *pvParameters)
{
   char        str[30];
   Sensors      sens;
    
    while(1){
        if (xQueueReceive(xQueue, &sens, 0) == pdPASS){
            if (sens.data[0] == 1){
                sprintf(str, "+PRESON;");
            }
            else if (sens.data[0] == 0){
                sprintf(str, "+PRESOFF;");
            }
            sprintf(str, "%s+OTEMP:%3.0f;+INTEMP:%2.0f;", str, sens.data[2],sens.data[1]);
            UART_PutString(str);
            sprintf(str, "\r\n");
            UART_PutString(str);
            
        }
        
}
    vTaskDelay(pdMS_TO_TICKS(1000)); //delay for 500ms
}



//we're going to perform tasks based on what we get from UART
void vTasks(void *pvParameters)
{
	MessageBufferHandle_t   xMesgBuf;
    char                    buf[20];
    char                    str[60];
    size_t                  xReceivedBytes;
    
    
   xMesgBuf = pvParameters;
    
    while(1){
        xReceivedBytes = xMessageBufferReceive(xMesgBuf, buf, sizeof(buf), pdMS_TO_TICKS(20));
        if (xReceivedBytes > 0 ){
            //CHECK LED COMMAND
            if (strcmp(buf, "LON") == 0) {
                //Testing UART
                //UART_PutString("Turning on LED");
                //Turn on LED
                UVLight_Write(1);
                
            } else if (strcmp(buf, "LOFF") == 0){
                //Testing UART
                //UART_PutString("Turning off LED");
                //Turn off LED
                UVLight_Write(0);                
                
            }
            
            //Window Tasks
            if (strcmp(buf, "WOPEN") == 0){
                //Testing UART
                //UART_PutString("Opening Window");
                //OPEN Window
                SERVOPWM_WriteCompare(18000);
                
                
            } else if (strcmp (buf, "WCLOSE") == 0){
                //Testing UART
                //UART_PutString("Closing Window\n");
                //OPEN Window
                 SERVOPWM_WriteCompare(19000);
                    
                    
            }
            
            //Fan Tasks
            if (strcmp(buf, "FON") == 0) {
                //Testing UART
                //UART_PutString("Turning on FAN\n");
                //Fan on
                Fan_Write(1);
            } else if (strcmp (buf, "FOFF") == 0) {
                //Testing UART
                //UART_PutString("Turning off FAN\n");
                //Fan off
                Fan_Write(0);
            }
            
            //Heatpad Tasks
            if (strcmp(buf, "HON") == 0){
                //Testing UART
                //UART_PutString("Heating up!\n");
                //Turn on Heat Pad
                HeatPad_Write(1);
            } else if (strcmp (buf, "HOFF") == 0){
                //Testing UART
                //UART_PutString("Heating off!\n");
                //Turn off Heat Pad
                HeatPad_Write(0);
            }
           
        vTaskDelay(pdMS_TO_TICKS(1000));                
                
        
    }
    }
    
    
}
//Our Calculate Temperature reading
float GetTemp(void)
{
    float   temp = 0;
    int     i;
    for (i=0; i < 10; i++) {
        temp = (temp + SARADC_GetResult16());
    }
    temp = temp / 10;
    
    return temp;
}   
    
