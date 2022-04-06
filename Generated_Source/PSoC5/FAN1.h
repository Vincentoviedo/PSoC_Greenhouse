/*******************************************************************************
* File Name: FAN1.h  
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

#if !defined(CY_PINS_FAN1_H) /* Pins FAN1_H */
#define CY_PINS_FAN1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "FAN1_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 FAN1__PORT == 15 && ((FAN1__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    FAN1_Write(uint8 value);
void    FAN1_SetDriveMode(uint8 mode);
uint8   FAN1_ReadDataReg(void);
uint8   FAN1_Read(void);
void    FAN1_SetInterruptMode(uint16 position, uint16 mode);
uint8   FAN1_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the FAN1_SetDriveMode() function.
     *  @{
     */
        #define FAN1_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define FAN1_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define FAN1_DM_RES_UP          PIN_DM_RES_UP
        #define FAN1_DM_RES_DWN         PIN_DM_RES_DWN
        #define FAN1_DM_OD_LO           PIN_DM_OD_LO
        #define FAN1_DM_OD_HI           PIN_DM_OD_HI
        #define FAN1_DM_STRONG          PIN_DM_STRONG
        #define FAN1_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define FAN1_MASK               FAN1__MASK
#define FAN1_SHIFT              FAN1__SHIFT
#define FAN1_WIDTH              1u

/* Interrupt constants */
#if defined(FAN1__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in FAN1_SetInterruptMode() function.
     *  @{
     */
        #define FAN1_INTR_NONE      (uint16)(0x0000u)
        #define FAN1_INTR_RISING    (uint16)(0x0001u)
        #define FAN1_INTR_FALLING   (uint16)(0x0002u)
        #define FAN1_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define FAN1_INTR_MASK      (0x01u) 
#endif /* (FAN1__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define FAN1_PS                     (* (reg8 *) FAN1__PS)
/* Data Register */
#define FAN1_DR                     (* (reg8 *) FAN1__DR)
/* Port Number */
#define FAN1_PRT_NUM                (* (reg8 *) FAN1__PRT) 
/* Connect to Analog Globals */                                                  
#define FAN1_AG                     (* (reg8 *) FAN1__AG)                       
/* Analog MUX bux enable */
#define FAN1_AMUX                   (* (reg8 *) FAN1__AMUX) 
/* Bidirectional Enable */                                                        
#define FAN1_BIE                    (* (reg8 *) FAN1__BIE)
/* Bit-mask for Aliased Register Access */
#define FAN1_BIT_MASK               (* (reg8 *) FAN1__BIT_MASK)
/* Bypass Enable */
#define FAN1_BYP                    (* (reg8 *) FAN1__BYP)
/* Port wide control signals */                                                   
#define FAN1_CTL                    (* (reg8 *) FAN1__CTL)
/* Drive Modes */
#define FAN1_DM0                    (* (reg8 *) FAN1__DM0) 
#define FAN1_DM1                    (* (reg8 *) FAN1__DM1)
#define FAN1_DM2                    (* (reg8 *) FAN1__DM2) 
/* Input Buffer Disable Override */
#define FAN1_INP_DIS                (* (reg8 *) FAN1__INP_DIS)
/* LCD Common or Segment Drive */
#define FAN1_LCD_COM_SEG            (* (reg8 *) FAN1__LCD_COM_SEG)
/* Enable Segment LCD */
#define FAN1_LCD_EN                 (* (reg8 *) FAN1__LCD_EN)
/* Slew Rate Control */
#define FAN1_SLW                    (* (reg8 *) FAN1__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define FAN1_PRTDSI__CAPS_SEL       (* (reg8 *) FAN1__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define FAN1_PRTDSI__DBL_SYNC_IN    (* (reg8 *) FAN1__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define FAN1_PRTDSI__OE_SEL0        (* (reg8 *) FAN1__PRTDSI__OE_SEL0) 
#define FAN1_PRTDSI__OE_SEL1        (* (reg8 *) FAN1__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define FAN1_PRTDSI__OUT_SEL0       (* (reg8 *) FAN1__PRTDSI__OUT_SEL0) 
#define FAN1_PRTDSI__OUT_SEL1       (* (reg8 *) FAN1__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define FAN1_PRTDSI__SYNC_OUT       (* (reg8 *) FAN1__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(FAN1__SIO_CFG)
    #define FAN1_SIO_HYST_EN        (* (reg8 *) FAN1__SIO_HYST_EN)
    #define FAN1_SIO_REG_HIFREQ     (* (reg8 *) FAN1__SIO_REG_HIFREQ)
    #define FAN1_SIO_CFG            (* (reg8 *) FAN1__SIO_CFG)
    #define FAN1_SIO_DIFF           (* (reg8 *) FAN1__SIO_DIFF)
#endif /* (FAN1__SIO_CFG) */

/* Interrupt Registers */
#if defined(FAN1__INTSTAT)
    #define FAN1_INTSTAT            (* (reg8 *) FAN1__INTSTAT)
    #define FAN1_SNAP               (* (reg8 *) FAN1__SNAP)
    
	#define FAN1_0_INTTYPE_REG 		(* (reg8 *) FAN1__0__INTTYPE)
#endif /* (FAN1__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_FAN1_H */


/* [] END OF FILE */
