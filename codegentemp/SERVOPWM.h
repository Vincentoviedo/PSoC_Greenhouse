/*******************************************************************************
* File Name: SERVOPWM.h
* Version 3.30
*
* Description:
*  Contains the prototypes and constants for the functions available to the
*  PWM user module.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
********************************************************************************/

#if !defined(CY_PWM_SERVOPWM_H)
#define CY_PWM_SERVOPWM_H

#include "cyfitter.h"
#include "cytypes.h"
#include "CyLib.h" /* For CyEnterCriticalSection() and CyExitCriticalSection() functions */

extern uint8 SERVOPWM_initVar;


/***************************************
* Conditional Compilation Parameters
***************************************/
#define SERVOPWM_Resolution                     (16u)
#define SERVOPWM_UsingFixedFunction             (0u)
#define SERVOPWM_DeadBandMode                   (0u)
#define SERVOPWM_KillModeMinTime                (0u)
#define SERVOPWM_KillMode                       (0u)
#define SERVOPWM_PWMMode                        (0u)
#define SERVOPWM_PWMModeIsCenterAligned         (0u)
#define SERVOPWM_DeadBandUsed                   (0u)
#define SERVOPWM_DeadBand2_4                    (0u)

#if !defined(SERVOPWM_PWMUDB_genblk8_stsreg__REMOVED)
    #define SERVOPWM_UseStatus                  (1u)
#else
    #define SERVOPWM_UseStatus                  (0u)
#endif /* !defined(SERVOPWM_PWMUDB_genblk8_stsreg__REMOVED) */

#if !defined(SERVOPWM_PWMUDB_genblk1_ctrlreg__REMOVED)
    #define SERVOPWM_UseControl                 (1u)
#else
    #define SERVOPWM_UseControl                 (0u)
#endif /* !defined(SERVOPWM_PWMUDB_genblk1_ctrlreg__REMOVED) */

#define SERVOPWM_UseOneCompareMode              (1u)
#define SERVOPWM_MinimumKillTime                (1u)
#define SERVOPWM_EnableMode                     (0u)

#define SERVOPWM_CompareMode1SW                 (0u)
#define SERVOPWM_CompareMode2SW                 (0u)

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component PWM_v3_30 requires cy_boot v3.0 or later
#endif /* (CY_ PSOC5LP) */

/* Use Kill Mode Enumerated Types */
#define SERVOPWM__B_PWM__DISABLED 0
#define SERVOPWM__B_PWM__ASYNCHRONOUS 1
#define SERVOPWM__B_PWM__SINGLECYCLE 2
#define SERVOPWM__B_PWM__LATCHED 3
#define SERVOPWM__B_PWM__MINTIME 4


/* Use Dead Band Mode Enumerated Types */
#define SERVOPWM__B_PWM__DBMDISABLED 0
#define SERVOPWM__B_PWM__DBM_2_4_CLOCKS 1
#define SERVOPWM__B_PWM__DBM_256_CLOCKS 2


/* Used PWM Mode Enumerated Types */
#define SERVOPWM__B_PWM__ONE_OUTPUT 0
#define SERVOPWM__B_PWM__TWO_OUTPUTS 1
#define SERVOPWM__B_PWM__DUAL_EDGE 2
#define SERVOPWM__B_PWM__CENTER_ALIGN 3
#define SERVOPWM__B_PWM__DITHER 5
#define SERVOPWM__B_PWM__HARDWARESELECT 4


/* Used PWM Compare Mode Enumerated Types */
#define SERVOPWM__B_PWM__LESS_THAN 1
#define SERVOPWM__B_PWM__LESS_THAN_OR_EQUAL 2
#define SERVOPWM__B_PWM__GREATER_THAN 3
#define SERVOPWM__B_PWM__GREATER_THAN_OR_EQUAL_TO 4
#define SERVOPWM__B_PWM__EQUAL 0
#define SERVOPWM__B_PWM__FIRMWARE 5



/***************************************
* Data Struct Definition
***************************************/


/**************************************************************************
 * Sleep Wakeup Backup structure for PWM Component
 *************************************************************************/
typedef struct
{

    uint8 PWMEnableState;

    #if(!SERVOPWM_UsingFixedFunction)
        uint16 PWMUdb;               /* PWM Current Counter value  */
        #if(!SERVOPWM_PWMModeIsCenterAligned)
            uint16 PWMPeriod;
        #endif /* (!SERVOPWM_PWMModeIsCenterAligned) */
        #if (SERVOPWM_UseStatus)
            uint8 InterruptMaskValue;   /* PWM Current Interrupt Mask */
        #endif /* (SERVOPWM_UseStatus) */

        /* Backup for Deadband parameters */
        #if(SERVOPWM_DeadBandMode == SERVOPWM__B_PWM__DBM_256_CLOCKS || \
            SERVOPWM_DeadBandMode == SERVOPWM__B_PWM__DBM_2_4_CLOCKS)
            uint8 PWMdeadBandValue; /* Dead Band Counter Current Value */
        #endif /* deadband count is either 2-4 clocks or 256 clocks */

        /* Backup Kill Mode Counter*/
        #if(SERVOPWM_KillModeMinTime)
            uint8 PWMKillCounterPeriod; /* Kill Mode period value */
        #endif /* (SERVOPWM_KillModeMinTime) */

        /* Backup control register */
        #if(SERVOPWM_UseControl)
            uint8 PWMControlRegister; /* PWM Control Register value */
        #endif /* (SERVOPWM_UseControl) */

    #endif /* (!SERVOPWM_UsingFixedFunction) */

}SERVOPWM_backupStruct;


/***************************************
*        Function Prototypes
 **************************************/

void    SERVOPWM_Start(void) ;
void    SERVOPWM_Stop(void) ;

#if (SERVOPWM_UseStatus || SERVOPWM_UsingFixedFunction)
    void  SERVOPWM_SetInterruptMode(uint8 interruptMode) ;
    uint8 SERVOPWM_ReadStatusRegister(void) ;
#endif /* (SERVOPWM_UseStatus || SERVOPWM_UsingFixedFunction) */

#define SERVOPWM_GetInterruptSource() SERVOPWM_ReadStatusRegister()

#if (SERVOPWM_UseControl)
    uint8 SERVOPWM_ReadControlRegister(void) ;
    void  SERVOPWM_WriteControlRegister(uint8 control)
          ;
#endif /* (SERVOPWM_UseControl) */

#if (SERVOPWM_UseOneCompareMode)
   #if (SERVOPWM_CompareMode1SW)
       void    SERVOPWM_SetCompareMode(uint8 comparemode)
               ;
   #endif /* (SERVOPWM_CompareMode1SW) */
#else
    #if (SERVOPWM_CompareMode1SW)
        void    SERVOPWM_SetCompareMode1(uint8 comparemode)
                ;
    #endif /* (SERVOPWM_CompareMode1SW) */
    #if (SERVOPWM_CompareMode2SW)
        void    SERVOPWM_SetCompareMode2(uint8 comparemode)
                ;
    #endif /* (SERVOPWM_CompareMode2SW) */
#endif /* (SERVOPWM_UseOneCompareMode) */

#if (!SERVOPWM_UsingFixedFunction)
    uint16   SERVOPWM_ReadCounter(void) ;
    uint16 SERVOPWM_ReadCapture(void) ;

    #if (SERVOPWM_UseStatus)
            void SERVOPWM_ClearFIFO(void) ;
    #endif /* (SERVOPWM_UseStatus) */

    void    SERVOPWM_WriteCounter(uint16 counter)
            ;
#endif /* (!SERVOPWM_UsingFixedFunction) */

void    SERVOPWM_WritePeriod(uint16 period)
        ;
uint16 SERVOPWM_ReadPeriod(void) ;

#if (SERVOPWM_UseOneCompareMode)
    void    SERVOPWM_WriteCompare(uint16 compare)
            ;
    uint16 SERVOPWM_ReadCompare(void) ;
#else
    void    SERVOPWM_WriteCompare1(uint16 compare)
            ;
    uint16 SERVOPWM_ReadCompare1(void) ;
    void    SERVOPWM_WriteCompare2(uint16 compare)
            ;
    uint16 SERVOPWM_ReadCompare2(void) ;
#endif /* (SERVOPWM_UseOneCompareMode) */


#if (SERVOPWM_DeadBandUsed)
    void    SERVOPWM_WriteDeadTime(uint8 deadtime) ;
    uint8   SERVOPWM_ReadDeadTime(void) ;
#endif /* (SERVOPWM_DeadBandUsed) */

#if ( SERVOPWM_KillModeMinTime)
    void SERVOPWM_WriteKillTime(uint8 killtime) ;
    uint8 SERVOPWM_ReadKillTime(void) ;
#endif /* ( SERVOPWM_KillModeMinTime) */

void SERVOPWM_Init(void) ;
void SERVOPWM_Enable(void) ;
void SERVOPWM_Sleep(void) ;
void SERVOPWM_Wakeup(void) ;
void SERVOPWM_SaveConfig(void) ;
void SERVOPWM_RestoreConfig(void) ;


/***************************************
*         Initialization Values
**************************************/
#define SERVOPWM_INIT_PERIOD_VALUE          (19999u)
#define SERVOPWM_INIT_COMPARE_VALUE1        (127u)
#define SERVOPWM_INIT_COMPARE_VALUE2        (63u)
#define SERVOPWM_INIT_INTERRUPTS_MODE       (uint8)(((uint8)(0u <<   \
                                                    SERVOPWM_STATUS_TC_INT_EN_MASK_SHIFT)) | \
                                                    (uint8)((uint8)(0u <<  \
                                                    SERVOPWM_STATUS_CMP2_INT_EN_MASK_SHIFT)) | \
                                                    (uint8)((uint8)(0u <<  \
                                                    SERVOPWM_STATUS_CMP1_INT_EN_MASK_SHIFT )) | \
                                                    (uint8)((uint8)(0u <<  \
                                                    SERVOPWM_STATUS_KILL_INT_EN_MASK_SHIFT )))
#define SERVOPWM_DEFAULT_COMPARE2_MODE      (uint8)((uint8)4u <<  SERVOPWM_CTRL_CMPMODE2_SHIFT)
#define SERVOPWM_DEFAULT_COMPARE1_MODE      (uint8)((uint8)4u <<  SERVOPWM_CTRL_CMPMODE1_SHIFT)
#define SERVOPWM_INIT_DEAD_TIME             (1u)


/********************************
*         Registers
******************************** */

#if (SERVOPWM_UsingFixedFunction)
   #define SERVOPWM_PERIOD_LSB              (*(reg16 *) SERVOPWM_PWMHW__PER0)
   #define SERVOPWM_PERIOD_LSB_PTR          ( (reg16 *) SERVOPWM_PWMHW__PER0)
   #define SERVOPWM_COMPARE1_LSB            (*(reg16 *) SERVOPWM_PWMHW__CNT_CMP0)
   #define SERVOPWM_COMPARE1_LSB_PTR        ( (reg16 *) SERVOPWM_PWMHW__CNT_CMP0)
   #define SERVOPWM_COMPARE2_LSB            (0x00u)
   #define SERVOPWM_COMPARE2_LSB_PTR        (0x00u)
   #define SERVOPWM_COUNTER_LSB             (*(reg16 *) SERVOPWM_PWMHW__CNT_CMP0)
   #define SERVOPWM_COUNTER_LSB_PTR         ( (reg16 *) SERVOPWM_PWMHW__CNT_CMP0)
   #define SERVOPWM_CAPTURE_LSB             (*(reg16 *) SERVOPWM_PWMHW__CAP0)
   #define SERVOPWM_CAPTURE_LSB_PTR         ( (reg16 *) SERVOPWM_PWMHW__CAP0)
   #define SERVOPWM_RT1                     (*(reg8 *)  SERVOPWM_PWMHW__RT1)
   #define SERVOPWM_RT1_PTR                 ( (reg8 *)  SERVOPWM_PWMHW__RT1)

#else
   #if (SERVOPWM_Resolution == 8u) /* 8bit - PWM */

       #if(SERVOPWM_PWMModeIsCenterAligned)
           #define SERVOPWM_PERIOD_LSB      (*(reg8 *)  SERVOPWM_PWMUDB_sP16_pwmdp_u0__D1_REG)
           #define SERVOPWM_PERIOD_LSB_PTR  ((reg8 *)   SERVOPWM_PWMUDB_sP16_pwmdp_u0__D1_REG)
       #else
           #define SERVOPWM_PERIOD_LSB      (*(reg8 *)  SERVOPWM_PWMUDB_sP16_pwmdp_u0__F0_REG)
           #define SERVOPWM_PERIOD_LSB_PTR  ((reg8 *)   SERVOPWM_PWMUDB_sP16_pwmdp_u0__F0_REG)
       #endif /* (SERVOPWM_PWMModeIsCenterAligned) */

       #define SERVOPWM_COMPARE1_LSB        (*(reg8 *)  SERVOPWM_PWMUDB_sP16_pwmdp_u0__D0_REG)
       #define SERVOPWM_COMPARE1_LSB_PTR    ((reg8 *)   SERVOPWM_PWMUDB_sP16_pwmdp_u0__D0_REG)
       #define SERVOPWM_COMPARE2_LSB        (*(reg8 *)  SERVOPWM_PWMUDB_sP16_pwmdp_u0__D1_REG)
       #define SERVOPWM_COMPARE2_LSB_PTR    ((reg8 *)   SERVOPWM_PWMUDB_sP16_pwmdp_u0__D1_REG)
       #define SERVOPWM_COUNTERCAP_LSB      (*(reg8 *)  SERVOPWM_PWMUDB_sP16_pwmdp_u0__A1_REG)
       #define SERVOPWM_COUNTERCAP_LSB_PTR  ((reg8 *)   SERVOPWM_PWMUDB_sP16_pwmdp_u0__A1_REG)
       #define SERVOPWM_COUNTER_LSB         (*(reg8 *)  SERVOPWM_PWMUDB_sP16_pwmdp_u0__A0_REG)
       #define SERVOPWM_COUNTER_LSB_PTR     ((reg8 *)   SERVOPWM_PWMUDB_sP16_pwmdp_u0__A0_REG)
       #define SERVOPWM_CAPTURE_LSB         (*(reg8 *)  SERVOPWM_PWMUDB_sP16_pwmdp_u0__F1_REG)
       #define SERVOPWM_CAPTURE_LSB_PTR     ((reg8 *)   SERVOPWM_PWMUDB_sP16_pwmdp_u0__F1_REG)

   #else
        #if(CY_PSOC3) /* 8-bit address space */
            #if(SERVOPWM_PWMModeIsCenterAligned)
               #define SERVOPWM_PERIOD_LSB      (*(reg16 *) SERVOPWM_PWMUDB_sP16_pwmdp_u0__D1_REG)
               #define SERVOPWM_PERIOD_LSB_PTR  ((reg16 *)  SERVOPWM_PWMUDB_sP16_pwmdp_u0__D1_REG)
            #else
               #define SERVOPWM_PERIOD_LSB      (*(reg16 *) SERVOPWM_PWMUDB_sP16_pwmdp_u0__F0_REG)
               #define SERVOPWM_PERIOD_LSB_PTR  ((reg16 *)  SERVOPWM_PWMUDB_sP16_pwmdp_u0__F0_REG)
            #endif /* (SERVOPWM_PWMModeIsCenterAligned) */

            #define SERVOPWM_COMPARE1_LSB       (*(reg16 *) SERVOPWM_PWMUDB_sP16_pwmdp_u0__D0_REG)
            #define SERVOPWM_COMPARE1_LSB_PTR   ((reg16 *)  SERVOPWM_PWMUDB_sP16_pwmdp_u0__D0_REG)
            #define SERVOPWM_COMPARE2_LSB       (*(reg16 *) SERVOPWM_PWMUDB_sP16_pwmdp_u0__D1_REG)
            #define SERVOPWM_COMPARE2_LSB_PTR   ((reg16 *)  SERVOPWM_PWMUDB_sP16_pwmdp_u0__D1_REG)
            #define SERVOPWM_COUNTERCAP_LSB     (*(reg16 *) SERVOPWM_PWMUDB_sP16_pwmdp_u0__A1_REG)
            #define SERVOPWM_COUNTERCAP_LSB_PTR ((reg16 *)  SERVOPWM_PWMUDB_sP16_pwmdp_u0__A1_REG)
            #define SERVOPWM_COUNTER_LSB        (*(reg16 *) SERVOPWM_PWMUDB_sP16_pwmdp_u0__A0_REG)
            #define SERVOPWM_COUNTER_LSB_PTR    ((reg16 *)  SERVOPWM_PWMUDB_sP16_pwmdp_u0__A0_REG)
            #define SERVOPWM_CAPTURE_LSB        (*(reg16 *) SERVOPWM_PWMUDB_sP16_pwmdp_u0__F1_REG)
            #define SERVOPWM_CAPTURE_LSB_PTR    ((reg16 *)  SERVOPWM_PWMUDB_sP16_pwmdp_u0__F1_REG)
        #else
            #if(SERVOPWM_PWMModeIsCenterAligned)
               #define SERVOPWM_PERIOD_LSB      (*(reg16 *) SERVOPWM_PWMUDB_sP16_pwmdp_u0__16BIT_D1_REG)
               #define SERVOPWM_PERIOD_LSB_PTR  ((reg16 *)  SERVOPWM_PWMUDB_sP16_pwmdp_u0__16BIT_D1_REG)
            #else
               #define SERVOPWM_PERIOD_LSB      (*(reg16 *) SERVOPWM_PWMUDB_sP16_pwmdp_u0__16BIT_F0_REG)
               #define SERVOPWM_PERIOD_LSB_PTR  ((reg16 *)  SERVOPWM_PWMUDB_sP16_pwmdp_u0__16BIT_F0_REG)
            #endif /* (SERVOPWM_PWMModeIsCenterAligned) */

            #define SERVOPWM_COMPARE1_LSB       (*(reg16 *) SERVOPWM_PWMUDB_sP16_pwmdp_u0__16BIT_D0_REG)
            #define SERVOPWM_COMPARE1_LSB_PTR   ((reg16 *)  SERVOPWM_PWMUDB_sP16_pwmdp_u0__16BIT_D0_REG)
            #define SERVOPWM_COMPARE2_LSB       (*(reg16 *) SERVOPWM_PWMUDB_sP16_pwmdp_u0__16BIT_D1_REG)
            #define SERVOPWM_COMPARE2_LSB_PTR   ((reg16 *)  SERVOPWM_PWMUDB_sP16_pwmdp_u0__16BIT_D1_REG)
            #define SERVOPWM_COUNTERCAP_LSB     (*(reg16 *) SERVOPWM_PWMUDB_sP16_pwmdp_u0__16BIT_A1_REG)
            #define SERVOPWM_COUNTERCAP_LSB_PTR ((reg16 *)  SERVOPWM_PWMUDB_sP16_pwmdp_u0__16BIT_A1_REG)
            #define SERVOPWM_COUNTER_LSB        (*(reg16 *) SERVOPWM_PWMUDB_sP16_pwmdp_u0__16BIT_A0_REG)
            #define SERVOPWM_COUNTER_LSB_PTR    ((reg16 *)  SERVOPWM_PWMUDB_sP16_pwmdp_u0__16BIT_A0_REG)
            #define SERVOPWM_CAPTURE_LSB        (*(reg16 *) SERVOPWM_PWMUDB_sP16_pwmdp_u0__16BIT_F1_REG)
            #define SERVOPWM_CAPTURE_LSB_PTR    ((reg16 *)  SERVOPWM_PWMUDB_sP16_pwmdp_u0__16BIT_F1_REG)
        #endif /* (CY_PSOC3) */

       #define SERVOPWM_AUX_CONTROLDP1          (*(reg8 *)  SERVOPWM_PWMUDB_sP16_pwmdp_u1__DP_AUX_CTL_REG)
       #define SERVOPWM_AUX_CONTROLDP1_PTR      ((reg8 *)   SERVOPWM_PWMUDB_sP16_pwmdp_u1__DP_AUX_CTL_REG)

   #endif /* (SERVOPWM_Resolution == 8) */

   #define SERVOPWM_COUNTERCAP_LSB_PTR_8BIT ( (reg8 *)  SERVOPWM_PWMUDB_sP16_pwmdp_u0__A1_REG)
   #define SERVOPWM_AUX_CONTROLDP0          (*(reg8 *)  SERVOPWM_PWMUDB_sP16_pwmdp_u0__DP_AUX_CTL_REG)
   #define SERVOPWM_AUX_CONTROLDP0_PTR      ((reg8 *)   SERVOPWM_PWMUDB_sP16_pwmdp_u0__DP_AUX_CTL_REG)

#endif /* (SERVOPWM_UsingFixedFunction) */

#if(SERVOPWM_KillModeMinTime )
    #define SERVOPWM_KILLMODEMINTIME        (*(reg8 *)  SERVOPWM_PWMUDB_sKM_killmodecounterdp_u0__D0_REG)
    #define SERVOPWM_KILLMODEMINTIME_PTR    ((reg8 *)   SERVOPWM_PWMUDB_sKM_killmodecounterdp_u0__D0_REG)
    /* Fixed Function Block has no Kill Mode parameters because it is Asynchronous only */
#endif /* (SERVOPWM_KillModeMinTime ) */

#if(SERVOPWM_DeadBandMode == SERVOPWM__B_PWM__DBM_256_CLOCKS)
    #define SERVOPWM_DEADBAND_COUNT         (*(reg8 *)  SERVOPWM_PWMUDB_sDB255_deadbandcounterdp_u0__D0_REG)
    #define SERVOPWM_DEADBAND_COUNT_PTR     ((reg8 *)   SERVOPWM_PWMUDB_sDB255_deadbandcounterdp_u0__D0_REG)
    #define SERVOPWM_DEADBAND_LSB_PTR       ((reg8 *)   SERVOPWM_PWMUDB_sDB255_deadbandcounterdp_u0__A0_REG)
    #define SERVOPWM_DEADBAND_LSB           (*(reg8 *)  SERVOPWM_PWMUDB_sDB255_deadbandcounterdp_u0__A0_REG)
#elif(SERVOPWM_DeadBandMode == SERVOPWM__B_PWM__DBM_2_4_CLOCKS)
    
    /* In Fixed Function Block these bits are in the control blocks control register */
    #if (SERVOPWM_UsingFixedFunction)
        #define SERVOPWM_DEADBAND_COUNT         (*(reg8 *)  SERVOPWM_PWMHW__CFG0)
        #define SERVOPWM_DEADBAND_COUNT_PTR     ((reg8 *)   SERVOPWM_PWMHW__CFG0)
        #define SERVOPWM_DEADBAND_COUNT_MASK    (uint8)((uint8)0x03u << SERVOPWM_DEADBAND_COUNT_SHIFT)

        /* As defined by the Register Map as DEADBAND_PERIOD[1:0] in CFG0 */
        #define SERVOPWM_DEADBAND_COUNT_SHIFT   (0x06u)
    #else
        /* Lower two bits of the added control register define the count 1-3 */
        #define SERVOPWM_DEADBAND_COUNT         (*(reg8 *)  SERVOPWM_PWMUDB_genblk7_dbctrlreg__CONTROL_REG)
        #define SERVOPWM_DEADBAND_COUNT_PTR     ((reg8 *)   SERVOPWM_PWMUDB_genblk7_dbctrlreg__CONTROL_REG)
        #define SERVOPWM_DEADBAND_COUNT_MASK    (uint8)((uint8)0x03u << SERVOPWM_DEADBAND_COUNT_SHIFT)

        /* As defined by the verilog implementation of the Control Register */
        #define SERVOPWM_DEADBAND_COUNT_SHIFT   (0x00u)
    #endif /* (SERVOPWM_UsingFixedFunction) */
#endif /* (SERVOPWM_DeadBandMode == SERVOPWM__B_PWM__DBM_256_CLOCKS) */



#if (SERVOPWM_UsingFixedFunction)
    #define SERVOPWM_STATUS                 (*(reg8 *) SERVOPWM_PWMHW__SR0)
    #define SERVOPWM_STATUS_PTR             ((reg8 *) SERVOPWM_PWMHW__SR0)
    #define SERVOPWM_STATUS_MASK            (*(reg8 *) SERVOPWM_PWMHW__SR0)
    #define SERVOPWM_STATUS_MASK_PTR        ((reg8 *) SERVOPWM_PWMHW__SR0)
    #define SERVOPWM_CONTROL                (*(reg8 *) SERVOPWM_PWMHW__CFG0)
    #define SERVOPWM_CONTROL_PTR            ((reg8 *) SERVOPWM_PWMHW__CFG0)
    #define SERVOPWM_CONTROL2               (*(reg8 *) SERVOPWM_PWMHW__CFG1)
    #define SERVOPWM_CONTROL3               (*(reg8 *) SERVOPWM_PWMHW__CFG2)
    #define SERVOPWM_GLOBAL_ENABLE          (*(reg8 *) SERVOPWM_PWMHW__PM_ACT_CFG)
    #define SERVOPWM_GLOBAL_ENABLE_PTR      ( (reg8 *) SERVOPWM_PWMHW__PM_ACT_CFG)
    #define SERVOPWM_GLOBAL_STBY_ENABLE     (*(reg8 *) SERVOPWM_PWMHW__PM_STBY_CFG)
    #define SERVOPWM_GLOBAL_STBY_ENABLE_PTR ( (reg8 *) SERVOPWM_PWMHW__PM_STBY_CFG)


    /***********************************
    *          Constants
    ***********************************/

    /* Fixed Function Block Chosen */
    #define SERVOPWM_BLOCK_EN_MASK          (SERVOPWM_PWMHW__PM_ACT_MSK)
    #define SERVOPWM_BLOCK_STBY_EN_MASK     (SERVOPWM_PWMHW__PM_STBY_MSK)
    
    /* Control Register definitions */
    #define SERVOPWM_CTRL_ENABLE_SHIFT      (0x00u)

    /* As defined by Register map as MODE_CFG bits in CFG2*/
    #define SERVOPWM_CTRL_CMPMODE1_SHIFT    (0x04u)

    /* As defined by Register map */
    #define SERVOPWM_CTRL_DEAD_TIME_SHIFT   (0x06u)  

    /* Fixed Function Block Only CFG register bit definitions */
    /*  Set to compare mode */
    #define SERVOPWM_CFG0_MODE              (0x02u)   

    /* Enable the block to run */
    #define SERVOPWM_CFG0_ENABLE            (0x01u)   
    
    /* As defined by Register map as DB bit in CFG0 */
    #define SERVOPWM_CFG0_DB                (0x20u)   

    /* Control Register Bit Masks */
    #define SERVOPWM_CTRL_ENABLE            (uint8)((uint8)0x01u << SERVOPWM_CTRL_ENABLE_SHIFT)
    #define SERVOPWM_CTRL_RESET             (uint8)((uint8)0x01u << SERVOPWM_CTRL_RESET_SHIFT)
    #define SERVOPWM_CTRL_CMPMODE2_MASK     (uint8)((uint8)0x07u << SERVOPWM_CTRL_CMPMODE2_SHIFT)
    #define SERVOPWM_CTRL_CMPMODE1_MASK     (uint8)((uint8)0x07u << SERVOPWM_CTRL_CMPMODE1_SHIFT)

    /* Control2 Register Bit Masks */
    /* As defined in Register Map, Part of the TMRX_CFG1 register */
    #define SERVOPWM_CTRL2_IRQ_SEL_SHIFT    (0x00u)
    #define SERVOPWM_CTRL2_IRQ_SEL          (uint8)((uint8)0x01u << SERVOPWM_CTRL2_IRQ_SEL_SHIFT)

    /* Status Register Bit Locations */
    /* As defined by Register map as TC in SR0 */
    #define SERVOPWM_STATUS_TC_SHIFT        (0x07u)   
    
    /* As defined by the Register map as CAP_CMP in SR0 */
    #define SERVOPWM_STATUS_CMP1_SHIFT      (0x06u)   

    /* Status Register Interrupt Enable Bit Locations */
    #define SERVOPWM_STATUS_KILL_INT_EN_MASK_SHIFT          (0x00u)
    #define SERVOPWM_STATUS_TC_INT_EN_MASK_SHIFT            (SERVOPWM_STATUS_TC_SHIFT - 4u)
    #define SERVOPWM_STATUS_CMP2_INT_EN_MASK_SHIFT          (0x00u)
    #define SERVOPWM_STATUS_CMP1_INT_EN_MASK_SHIFT          (SERVOPWM_STATUS_CMP1_SHIFT - 4u)

    /* Status Register Bit Masks */
    #define SERVOPWM_STATUS_TC              (uint8)((uint8)0x01u << SERVOPWM_STATUS_TC_SHIFT)
    #define SERVOPWM_STATUS_CMP1            (uint8)((uint8)0x01u << SERVOPWM_STATUS_CMP1_SHIFT)

    /* Status Register Interrupt Bit Masks */
    #define SERVOPWM_STATUS_TC_INT_EN_MASK              (uint8)((uint8)SERVOPWM_STATUS_TC >> 4u)
    #define SERVOPWM_STATUS_CMP1_INT_EN_MASK            (uint8)((uint8)SERVOPWM_STATUS_CMP1 >> 4u)

    /*RT1 Synch Constants */
    #define SERVOPWM_RT1_SHIFT             (0x04u)

    /* Sync TC and CMP bit masks */
    #define SERVOPWM_RT1_MASK              (uint8)((uint8)0x03u << SERVOPWM_RT1_SHIFT)
    #define SERVOPWM_SYNC                  (uint8)((uint8)0x03u << SERVOPWM_RT1_SHIFT)
    #define SERVOPWM_SYNCDSI_SHIFT         (0x00u)

    /* Sync all DSI inputs */
    #define SERVOPWM_SYNCDSI_MASK          (uint8)((uint8)0x0Fu << SERVOPWM_SYNCDSI_SHIFT)

    /* Sync all DSI inputs */
    #define SERVOPWM_SYNCDSI_EN            (uint8)((uint8)0x0Fu << SERVOPWM_SYNCDSI_SHIFT)


#else
    #define SERVOPWM_STATUS                (*(reg8 *)   SERVOPWM_PWMUDB_genblk8_stsreg__STATUS_REG )
    #define SERVOPWM_STATUS_PTR            ((reg8 *)    SERVOPWM_PWMUDB_genblk8_stsreg__STATUS_REG )
    #define SERVOPWM_STATUS_MASK           (*(reg8 *)   SERVOPWM_PWMUDB_genblk8_stsreg__MASK_REG)
    #define SERVOPWM_STATUS_MASK_PTR       ((reg8 *)    SERVOPWM_PWMUDB_genblk8_stsreg__MASK_REG)
    #define SERVOPWM_STATUS_AUX_CTRL       (*(reg8 *)   SERVOPWM_PWMUDB_genblk8_stsreg__STATUS_AUX_CTL_REG)
    #define SERVOPWM_CONTROL               (*(reg8 *)   SERVOPWM_PWMUDB_genblk1_ctrlreg__CONTROL_REG)
    #define SERVOPWM_CONTROL_PTR           ((reg8 *)    SERVOPWM_PWMUDB_genblk1_ctrlreg__CONTROL_REG)


    /***********************************
    *          Constants
    ***********************************/

    /* Control Register bit definitions */
    #define SERVOPWM_CTRL_ENABLE_SHIFT      (0x07u)
    #define SERVOPWM_CTRL_RESET_SHIFT       (0x06u)
    #define SERVOPWM_CTRL_CMPMODE2_SHIFT    (0x03u)
    #define SERVOPWM_CTRL_CMPMODE1_SHIFT    (0x00u)
    #define SERVOPWM_CTRL_DEAD_TIME_SHIFT   (0x00u)   /* No Shift Needed for UDB block */
    
    /* Control Register Bit Masks */
    #define SERVOPWM_CTRL_ENABLE            (uint8)((uint8)0x01u << SERVOPWM_CTRL_ENABLE_SHIFT)
    #define SERVOPWM_CTRL_RESET             (uint8)((uint8)0x01u << SERVOPWM_CTRL_RESET_SHIFT)
    #define SERVOPWM_CTRL_CMPMODE2_MASK     (uint8)((uint8)0x07u << SERVOPWM_CTRL_CMPMODE2_SHIFT)
    #define SERVOPWM_CTRL_CMPMODE1_MASK     (uint8)((uint8)0x07u << SERVOPWM_CTRL_CMPMODE1_SHIFT)

    /* Status Register Bit Locations */
    #define SERVOPWM_STATUS_KILL_SHIFT          (0x05u)
    #define SERVOPWM_STATUS_FIFONEMPTY_SHIFT    (0x04u)
    #define SERVOPWM_STATUS_FIFOFULL_SHIFT      (0x03u)
    #define SERVOPWM_STATUS_TC_SHIFT            (0x02u)
    #define SERVOPWM_STATUS_CMP2_SHIFT          (0x01u)
    #define SERVOPWM_STATUS_CMP1_SHIFT          (0x00u)

    /* Status Register Interrupt Enable Bit Locations - UDB Status Interrupt Mask match Status Bit Locations*/
    #define SERVOPWM_STATUS_KILL_INT_EN_MASK_SHIFT          (SERVOPWM_STATUS_KILL_SHIFT)
    #define SERVOPWM_STATUS_FIFONEMPTY_INT_EN_MASK_SHIFT    (SERVOPWM_STATUS_FIFONEMPTY_SHIFT)
    #define SERVOPWM_STATUS_FIFOFULL_INT_EN_MASK_SHIFT      (SERVOPWM_STATUS_FIFOFULL_SHIFT)
    #define SERVOPWM_STATUS_TC_INT_EN_MASK_SHIFT            (SERVOPWM_STATUS_TC_SHIFT)
    #define SERVOPWM_STATUS_CMP2_INT_EN_MASK_SHIFT          (SERVOPWM_STATUS_CMP2_SHIFT)
    #define SERVOPWM_STATUS_CMP1_INT_EN_MASK_SHIFT          (SERVOPWM_STATUS_CMP1_SHIFT)

    /* Status Register Bit Masks */
    #define SERVOPWM_STATUS_KILL            (uint8)((uint8)0x00u << SERVOPWM_STATUS_KILL_SHIFT )
    #define SERVOPWM_STATUS_FIFOFULL        (uint8)((uint8)0x01u << SERVOPWM_STATUS_FIFOFULL_SHIFT)
    #define SERVOPWM_STATUS_FIFONEMPTY      (uint8)((uint8)0x01u << SERVOPWM_STATUS_FIFONEMPTY_SHIFT)
    #define SERVOPWM_STATUS_TC              (uint8)((uint8)0x01u << SERVOPWM_STATUS_TC_SHIFT)
    #define SERVOPWM_STATUS_CMP2            (uint8)((uint8)0x01u << SERVOPWM_STATUS_CMP2_SHIFT)
    #define SERVOPWM_STATUS_CMP1            (uint8)((uint8)0x01u << SERVOPWM_STATUS_CMP1_SHIFT)

    /* Status Register Interrupt Bit Masks  - UDB Status Interrupt Mask match Status Bit Locations */
    #define SERVOPWM_STATUS_KILL_INT_EN_MASK            (SERVOPWM_STATUS_KILL)
    #define SERVOPWM_STATUS_FIFOFULL_INT_EN_MASK        (SERVOPWM_STATUS_FIFOFULL)
    #define SERVOPWM_STATUS_FIFONEMPTY_INT_EN_MASK      (SERVOPWM_STATUS_FIFONEMPTY)
    #define SERVOPWM_STATUS_TC_INT_EN_MASK              (SERVOPWM_STATUS_TC)
    #define SERVOPWM_STATUS_CMP2_INT_EN_MASK            (SERVOPWM_STATUS_CMP2)
    #define SERVOPWM_STATUS_CMP1_INT_EN_MASK            (SERVOPWM_STATUS_CMP1)

    /* Datapath Auxillary Control Register bit definitions */
    #define SERVOPWM_AUX_CTRL_FIFO0_CLR         (0x01u)
    #define SERVOPWM_AUX_CTRL_FIFO1_CLR         (0x02u)
    #define SERVOPWM_AUX_CTRL_FIFO0_LVL         (0x04u)
    #define SERVOPWM_AUX_CTRL_FIFO1_LVL         (0x08u)
    #define SERVOPWM_STATUS_ACTL_INT_EN_MASK    (0x10u) /* As defined for the ACTL Register */
#endif /* SERVOPWM_UsingFixedFunction */

#endif  /* CY_PWM_SERVOPWM_H */


/* [] END OF FILE */
