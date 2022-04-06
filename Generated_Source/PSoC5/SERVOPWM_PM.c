/*******************************************************************************
* File Name: SERVOPWM_PM.c
* Version 3.30
*
* Description:
*  This file provides the power management source code to API for the
*  PWM.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "SERVOPWM.h"

static SERVOPWM_backupStruct SERVOPWM_backup;


/*******************************************************************************
* Function Name: SERVOPWM_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the current user configuration of the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  SERVOPWM_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void SERVOPWM_SaveConfig(void) 
{

    #if(!SERVOPWM_UsingFixedFunction)
        #if(!SERVOPWM_PWMModeIsCenterAligned)
            SERVOPWM_backup.PWMPeriod = SERVOPWM_ReadPeriod();
        #endif /* (!SERVOPWM_PWMModeIsCenterAligned) */
        SERVOPWM_backup.PWMUdb = SERVOPWM_ReadCounter();
        #if (SERVOPWM_UseStatus)
            SERVOPWM_backup.InterruptMaskValue = SERVOPWM_STATUS_MASK;
        #endif /* (SERVOPWM_UseStatus) */

        #if(SERVOPWM_DeadBandMode == SERVOPWM__B_PWM__DBM_256_CLOCKS || \
            SERVOPWM_DeadBandMode == SERVOPWM__B_PWM__DBM_2_4_CLOCKS)
            SERVOPWM_backup.PWMdeadBandValue = SERVOPWM_ReadDeadTime();
        #endif /*  deadband count is either 2-4 clocks or 256 clocks */

        #if(SERVOPWM_KillModeMinTime)
             SERVOPWM_backup.PWMKillCounterPeriod = SERVOPWM_ReadKillTime();
        #endif /* (SERVOPWM_KillModeMinTime) */

        #if(SERVOPWM_UseControl)
            SERVOPWM_backup.PWMControlRegister = SERVOPWM_ReadControlRegister();
        #endif /* (SERVOPWM_UseControl) */
    #endif  /* (!SERVOPWM_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: SERVOPWM_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration of the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  SERVOPWM_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void SERVOPWM_RestoreConfig(void) 
{
        #if(!SERVOPWM_UsingFixedFunction)
            #if(!SERVOPWM_PWMModeIsCenterAligned)
                SERVOPWM_WritePeriod(SERVOPWM_backup.PWMPeriod);
            #endif /* (!SERVOPWM_PWMModeIsCenterAligned) */

            SERVOPWM_WriteCounter(SERVOPWM_backup.PWMUdb);

            #if (SERVOPWM_UseStatus)
                SERVOPWM_STATUS_MASK = SERVOPWM_backup.InterruptMaskValue;
            #endif /* (SERVOPWM_UseStatus) */

            #if(SERVOPWM_DeadBandMode == SERVOPWM__B_PWM__DBM_256_CLOCKS || \
                SERVOPWM_DeadBandMode == SERVOPWM__B_PWM__DBM_2_4_CLOCKS)
                SERVOPWM_WriteDeadTime(SERVOPWM_backup.PWMdeadBandValue);
            #endif /* deadband count is either 2-4 clocks or 256 clocks */

            #if(SERVOPWM_KillModeMinTime)
                SERVOPWM_WriteKillTime(SERVOPWM_backup.PWMKillCounterPeriod);
            #endif /* (SERVOPWM_KillModeMinTime) */

            #if(SERVOPWM_UseControl)
                SERVOPWM_WriteControlRegister(SERVOPWM_backup.PWMControlRegister);
            #endif /* (SERVOPWM_UseControl) */
        #endif  /* (!SERVOPWM_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: SERVOPWM_Sleep
********************************************************************************
*
* Summary:
*  Disables block's operation and saves the user configuration. Should be called
*  just prior to entering sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  SERVOPWM_backup.PWMEnableState:  Is modified depending on the enable
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void SERVOPWM_Sleep(void) 
{
    #if(SERVOPWM_UseControl)
        if(SERVOPWM_CTRL_ENABLE == (SERVOPWM_CONTROL & SERVOPWM_CTRL_ENABLE))
        {
            /*Component is enabled */
            SERVOPWM_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            SERVOPWM_backup.PWMEnableState = 0u;
        }
    #endif /* (SERVOPWM_UseControl) */

    /* Stop component */
    SERVOPWM_Stop();

    /* Save registers configuration */
    SERVOPWM_SaveConfig();
}


/*******************************************************************************
* Function Name: SERVOPWM_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration. Should be called just after
*  awaking from sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  SERVOPWM_backup.pwmEnable:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void SERVOPWM_Wakeup(void) 
{
     /* Restore registers values */
    SERVOPWM_RestoreConfig();

    if(SERVOPWM_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        SERVOPWM_Enable();
    } /* Do nothing if component's block was disabled before */

}


/* [] END OF FILE */
