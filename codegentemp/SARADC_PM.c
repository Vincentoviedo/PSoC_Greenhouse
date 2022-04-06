/*******************************************************************************
* File Name: SARADC_PM.c
* Version 3.10
*
* Description:
*  This file provides Sleep/WakeUp APIs functionality.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "SARADC.h"


/***************************************
* Local data allocation
***************************************/

static SARADC_BACKUP_STRUCT  SARADC_backup =
{
    SARADC_DISABLED
};


/*******************************************************************************
* Function Name: SARADC_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the current user configuration.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void SARADC_SaveConfig(void)
{
    /* All configuration registers are marked as [reset_all_retention] */
}


/*******************************************************************************
* Function Name: SARADC_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void SARADC_RestoreConfig(void)
{
    /* All congiguration registers are marked as [reset_all_retention] */
}


/*******************************************************************************
* Function Name: SARADC_Sleep
********************************************************************************
*
* Summary:
*  This is the preferred routine to prepare the component for sleep.
*  The SARADC_Sleep() routine saves the current component state,
*  then it calls the ADC_Stop() function.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  SARADC_backup - The structure field 'enableState' is modified
*  depending on the enable state of the block before entering to sleep mode.
*
*******************************************************************************/
void SARADC_Sleep(void)
{
    if((SARADC_PWRMGR_SAR_REG  & SARADC_ACT_PWR_SAR_EN) != 0u)
    {
        if((SARADC_SAR_CSR0_REG & SARADC_SAR_SOF_START_CONV) != 0u)
        {
            SARADC_backup.enableState = SARADC_ENABLED | SARADC_STARTED;
        }
        else
        {
            SARADC_backup.enableState = SARADC_ENABLED;
        }
        SARADC_Stop();
    }
    else
    {
        SARADC_backup.enableState = SARADC_DISABLED;
    }
}


/*******************************************************************************
* Function Name: SARADC_Wakeup
********************************************************************************
*
* Summary:
*  This is the preferred routine to restore the component to the state when
*  SARADC_Sleep() was called. If the component was enabled before the
*  SARADC_Sleep() function was called, the
*  SARADC_Wakeup() function also re-enables the component.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  SARADC_backup - The structure field 'enableState' is used to
*  restore the enable state of block after wakeup from sleep mode.
*
*******************************************************************************/
void SARADC_Wakeup(void)
{
    if(SARADC_backup.enableState != SARADC_DISABLED)
    {
        SARADC_Enable();
        #if(SARADC_DEFAULT_CONV_MODE != SARADC__HARDWARE_TRIGGER)
            if((SARADC_backup.enableState & SARADC_STARTED) != 0u)
            {
                SARADC_StartConvert();
            }
        #endif /* End SARADC_DEFAULT_CONV_MODE != SARADC__HARDWARE_TRIGGER */
    }
}


/* [] END OF FILE */
