/*******************************************************************************
* File Name: SERVO1.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_SERVO1_H) /* Pins SERVO1_H */
#define CY_PINS_SERVO1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "SERVO1_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 SERVO1__PORT == 15 && ((SERVO1__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    SERVO1_Write(uint8 value);
void    SERVO1_SetDriveMode(uint8 mode);
uint8   SERVO1_ReadDataReg(void);
uint8   SERVO1_Read(void);
void    SERVO1_SetInterruptMode(uint16 position, uint16 mode);
uint8   SERVO1_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the SERVO1_SetDriveMode() function.
     *  @{
     */
        #define SERVO1_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define SERVO1_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define SERVO1_DM_RES_UP          PIN_DM_RES_UP
        #define SERVO1_DM_RES_DWN         PIN_DM_RES_DWN
        #define SERVO1_DM_OD_LO           PIN_DM_OD_LO
        #define SERVO1_DM_OD_HI           PIN_DM_OD_HI
        #define SERVO1_DM_STRONG          PIN_DM_STRONG
        #define SERVO1_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define SERVO1_MASK               SERVO1__MASK
#define SERVO1_SHIFT              SERVO1__SHIFT
#define SERVO1_WIDTH              1u

/* Interrupt constants */
#if defined(SERVO1__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in SERVO1_SetInterruptMode() function.
     *  @{
     */
        #define SERVO1_INTR_NONE      (uint16)(0x0000u)
        #define SERVO1_INTR_RISING    (uint16)(0x0001u)
        #define SERVO1_INTR_FALLING   (uint16)(0x0002u)
        #define SERVO1_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define SERVO1_INTR_MASK      (0x01u) 
#endif /* (SERVO1__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define SERVO1_PS                     (* (reg8 *) SERVO1__PS)
/* Data Register */
#define SERVO1_DR                     (* (reg8 *) SERVO1__DR)
/* Port Number */
#define SERVO1_PRT_NUM                (* (reg8 *) SERVO1__PRT) 
/* Connect to Analog Globals */                                                  
#define SERVO1_AG                     (* (reg8 *) SERVO1__AG)                       
/* Analog MUX bux enable */
#define SERVO1_AMUX                   (* (reg8 *) SERVO1__AMUX) 
/* Bidirectional Enable */                                                        
#define SERVO1_BIE                    (* (reg8 *) SERVO1__BIE)
/* Bit-mask for Aliased Register Access */
#define SERVO1_BIT_MASK               (* (reg8 *) SERVO1__BIT_MASK)
/* Bypass Enable */
#define SERVO1_BYP                    (* (reg8 *) SERVO1__BYP)
/* Port wide control signals */                                                   
#define SERVO1_CTL                    (* (reg8 *) SERVO1__CTL)
/* Drive Modes */
#define SERVO1_DM0                    (* (reg8 *) SERVO1__DM0) 
#define SERVO1_DM1                    (* (reg8 *) SERVO1__DM1)
#define SERVO1_DM2                    (* (reg8 *) SERVO1__DM2) 
/* Input Buffer Disable Override */
#define SERVO1_INP_DIS                (* (reg8 *) SERVO1__INP_DIS)
/* LCD Common or Segment Drive */
#define SERVO1_LCD_COM_SEG            (* (reg8 *) SERVO1__LCD_COM_SEG)
/* Enable Segment LCD */
#define SERVO1_LCD_EN                 (* (reg8 *) SERVO1__LCD_EN)
/* Slew Rate Control */
#define SERVO1_SLW                    (* (reg8 *) SERVO1__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define SERVO1_PRTDSI__CAPS_SEL       (* (reg8 *) SERVO1__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define SERVO1_PRTDSI__DBL_SYNC_IN    (* (reg8 *) SERVO1__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define SERVO1_PRTDSI__OE_SEL0        (* (reg8 *) SERVO1__PRTDSI__OE_SEL0) 
#define SERVO1_PRTDSI__OE_SEL1        (* (reg8 *) SERVO1__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define SERVO1_PRTDSI__OUT_SEL0       (* (reg8 *) SERVO1__PRTDSI__OUT_SEL0) 
#define SERVO1_PRTDSI__OUT_SEL1       (* (reg8 *) SERVO1__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define SERVO1_PRTDSI__SYNC_OUT       (* (reg8 *) SERVO1__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(SERVO1__SIO_CFG)
    #define SERVO1_SIO_HYST_EN        (* (reg8 *) SERVO1__SIO_HYST_EN)
    #define SERVO1_SIO_REG_HIFREQ     (* (reg8 *) SERVO1__SIO_REG_HIFREQ)
    #define SERVO1_SIO_CFG            (* (reg8 *) SERVO1__SIO_CFG)
    #define SERVO1_SIO_DIFF           (* (reg8 *) SERVO1__SIO_DIFF)
#endif /* (SERVO1__SIO_CFG) */

/* Interrupt Registers */
#if defined(SERVO1__INTSTAT)
    #define SERVO1_INTSTAT            (* (reg8 *) SERVO1__INTSTAT)
    #define SERVO1_SNAP               (* (reg8 *) SERVO1__SNAP)
    
	#define SERVO1_0_INTTYPE_REG 		(* (reg8 *) SERVO1__0__INTTYPE)
#endif /* (SERVO1__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_SERVO1_H */


/* [] END OF FILE */
