/*******************************************************************************
* File Name: UVLight.h  
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

#if !defined(CY_PINS_UVLight_H) /* Pins UVLight_H */
#define CY_PINS_UVLight_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "UVLight_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 UVLight__PORT == 15 && ((UVLight__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    UVLight_Write(uint8 value);
void    UVLight_SetDriveMode(uint8 mode);
uint8   UVLight_ReadDataReg(void);
uint8   UVLight_Read(void);
void    UVLight_SetInterruptMode(uint16 position, uint16 mode);
uint8   UVLight_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the UVLight_SetDriveMode() function.
     *  @{
     */
        #define UVLight_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define UVLight_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define UVLight_DM_RES_UP          PIN_DM_RES_UP
        #define UVLight_DM_RES_DWN         PIN_DM_RES_DWN
        #define UVLight_DM_OD_LO           PIN_DM_OD_LO
        #define UVLight_DM_OD_HI           PIN_DM_OD_HI
        #define UVLight_DM_STRONG          PIN_DM_STRONG
        #define UVLight_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define UVLight_MASK               UVLight__MASK
#define UVLight_SHIFT              UVLight__SHIFT
#define UVLight_WIDTH              1u

/* Interrupt constants */
#if defined(UVLight__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in UVLight_SetInterruptMode() function.
     *  @{
     */
        #define UVLight_INTR_NONE      (uint16)(0x0000u)
        #define UVLight_INTR_RISING    (uint16)(0x0001u)
        #define UVLight_INTR_FALLING   (uint16)(0x0002u)
        #define UVLight_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define UVLight_INTR_MASK      (0x01u) 
#endif /* (UVLight__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define UVLight_PS                     (* (reg8 *) UVLight__PS)
/* Data Register */
#define UVLight_DR                     (* (reg8 *) UVLight__DR)
/* Port Number */
#define UVLight_PRT_NUM                (* (reg8 *) UVLight__PRT) 
/* Connect to Analog Globals */                                                  
#define UVLight_AG                     (* (reg8 *) UVLight__AG)                       
/* Analog MUX bux enable */
#define UVLight_AMUX                   (* (reg8 *) UVLight__AMUX) 
/* Bidirectional Enable */                                                        
#define UVLight_BIE                    (* (reg8 *) UVLight__BIE)
/* Bit-mask for Aliased Register Access */
#define UVLight_BIT_MASK               (* (reg8 *) UVLight__BIT_MASK)
/* Bypass Enable */
#define UVLight_BYP                    (* (reg8 *) UVLight__BYP)
/* Port wide control signals */                                                   
#define UVLight_CTL                    (* (reg8 *) UVLight__CTL)
/* Drive Modes */
#define UVLight_DM0                    (* (reg8 *) UVLight__DM0) 
#define UVLight_DM1                    (* (reg8 *) UVLight__DM1)
#define UVLight_DM2                    (* (reg8 *) UVLight__DM2) 
/* Input Buffer Disable Override */
#define UVLight_INP_DIS                (* (reg8 *) UVLight__INP_DIS)
/* LCD Common or Segment Drive */
#define UVLight_LCD_COM_SEG            (* (reg8 *) UVLight__LCD_COM_SEG)
/* Enable Segment LCD */
#define UVLight_LCD_EN                 (* (reg8 *) UVLight__LCD_EN)
/* Slew Rate Control */
#define UVLight_SLW                    (* (reg8 *) UVLight__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define UVLight_PRTDSI__CAPS_SEL       (* (reg8 *) UVLight__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define UVLight_PRTDSI__DBL_SYNC_IN    (* (reg8 *) UVLight__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define UVLight_PRTDSI__OE_SEL0        (* (reg8 *) UVLight__PRTDSI__OE_SEL0) 
#define UVLight_PRTDSI__OE_SEL1        (* (reg8 *) UVLight__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define UVLight_PRTDSI__OUT_SEL0       (* (reg8 *) UVLight__PRTDSI__OUT_SEL0) 
#define UVLight_PRTDSI__OUT_SEL1       (* (reg8 *) UVLight__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define UVLight_PRTDSI__SYNC_OUT       (* (reg8 *) UVLight__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(UVLight__SIO_CFG)
    #define UVLight_SIO_HYST_EN        (* (reg8 *) UVLight__SIO_HYST_EN)
    #define UVLight_SIO_REG_HIFREQ     (* (reg8 *) UVLight__SIO_REG_HIFREQ)
    #define UVLight_SIO_CFG            (* (reg8 *) UVLight__SIO_CFG)
    #define UVLight_SIO_DIFF           (* (reg8 *) UVLight__SIO_DIFF)
#endif /* (UVLight__SIO_CFG) */

/* Interrupt Registers */
#if defined(UVLight__INTSTAT)
    #define UVLight_INTSTAT            (* (reg8 *) UVLight__INTSTAT)
    #define UVLight_SNAP               (* (reg8 *) UVLight__SNAP)
    
	#define UVLight_0_INTTYPE_REG 		(* (reg8 *) UVLight__0__INTTYPE)
#endif /* (UVLight__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_UVLight_H */


/* [] END OF FILE */
