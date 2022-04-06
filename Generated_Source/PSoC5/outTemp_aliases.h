/*******************************************************************************
* File Name: outTemp.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_outTemp_ALIASES_H) /* Pins outTemp_ALIASES_H */
#define CY_PINS_outTemp_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define outTemp_0			(outTemp__0__PC)
#define outTemp_0_INTR	((uint16)((uint16)0x0001u << outTemp__0__SHIFT))

#define outTemp_INTR_ALL	 ((uint16)(outTemp_0_INTR))

#endif /* End Pins outTemp_ALIASES_H */


/* [] END OF FILE */
