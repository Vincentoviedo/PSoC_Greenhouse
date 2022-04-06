/*******************************************************************************
* File Name: HeatPad.h  
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

#if !defined(CY_PINS_HeatPad_H) /* Pins HeatPad_H */
#define CY_PINS_HeatPad_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "HeatPad_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 HeatPad__PORT == 15 && ((HeatPad__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    HeatPad_Write(uint8 value);
void    HeatPad_SetDriveMode(uint8 mode);
uint8   HeatPad_ReadDataReg(void);
uint8   HeatPad_Read(void);
void    HeatPad_SetInterruptMode(uint16 position, uint16 mode);
uint8   HeatPad_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the HeatPad_SetDriveMode() function.
     *  @{
     */
        #define HeatPad_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define HeatPad_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define HeatPad_DM_RES_UP          PIN_DM_RES_UP
        #define HeatPad_DM_RES_DWN         PIN_DM_RES_DWN
        #define HeatPad_DM_OD_LO           PIN_DM_OD_LO
        #define HeatPad_DM_OD_HI           PIN_DM_OD_HI
        #define HeatPad_DM_STRONG          PIN_DM_STRONG
        #define HeatPad_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define HeatPad_MASK               HeatPad__MASK
#define HeatPad_SHIFT              HeatPad__SHIFT
#define HeatPad_WIDTH              1u

/* Interrupt constants */
#if defined(HeatPad__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in HeatPad_SetInterruptMode() function.
     *  @{
     */
        #define HeatPad_INTR_NONE      (uint16)(0x0000u)
        #define HeatPad_INTR_RISING    (uint16)(0x0001u)
        #define HeatPad_INTR_FALLING   (uint16)(0x0002u)
        #define HeatPad_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define HeatPad_INTR_MASK      (0x01u) 
#endif /* (HeatPad__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define HeatPad_PS                     (* (reg8 *) HeatPad__PS)
/* Data Register */
#define HeatPad_DR                     (* (reg8 *) HeatPad__DR)
/* Port Number */
#define HeatPad_PRT_NUM                (* (reg8 *) HeatPad__PRT) 
/* Connect to Analog Globals */                                                  
#define HeatPad_AG                     (* (reg8 *) HeatPad__AG)                       
/* Analog MUX bux enable */
#define HeatPad_AMUX                   (* (reg8 *) HeatPad__AMUX) 
/* Bidirectional Enable */                                                        
#define HeatPad_BIE                    (* (reg8 *) HeatPad__BIE)
/* Bit-mask for Aliased Register Access */
#define HeatPad_BIT_MASK               (* (reg8 *) HeatPad__BIT_MASK)
/* Bypass Enable */
#define HeatPad_BYP                    (* (reg8 *) HeatPad__BYP)
/* Port wide control signals */                                                   
#define HeatPad_CTL                    (* (reg8 *) HeatPad__CTL)
/* Drive Modes */
#define HeatPad_DM0                    (* (reg8 *) HeatPad__DM0) 
#define HeatPad_DM1                    (* (reg8 *) HeatPad__DM1)
#define HeatPad_DM2                    (* (reg8 *) HeatPad__DM2) 
/* Input Buffer Disable Override */
#define HeatPad_INP_DIS                (* (reg8 *) HeatPad__INP_DIS)
/* LCD Common or Segment Drive */
#define HeatPad_LCD_COM_SEG            (* (reg8 *) HeatPad__LCD_COM_SEG)
/* Enable Segment LCD */
#define HeatPad_LCD_EN                 (* (reg8 *) HeatPad__LCD_EN)
/* Slew Rate Control */
#define HeatPad_SLW                    (* (reg8 *) HeatPad__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define HeatPad_PRTDSI__CAPS_SEL       (* (reg8 *) HeatPad__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define HeatPad_PRTDSI__DBL_SYNC_IN    (* (reg8 *) HeatPad__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define HeatPad_PRTDSI__OE_SEL0        (* (reg8 *) HeatPad__PRTDSI__OE_SEL0) 
#define HeatPad_PRTDSI__OE_SEL1        (* (reg8 *) HeatPad__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define HeatPad_PRTDSI__OUT_SEL0       (* (reg8 *) HeatPad__PRTDSI__OUT_SEL0) 
#define HeatPad_PRTDSI__OUT_SEL1       (* (reg8 *) HeatPad__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define HeatPad_PRTDSI__SYNC_OUT       (* (reg8 *) HeatPad__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(HeatPad__SIO_CFG)
    #define HeatPad_SIO_HYST_EN        (* (reg8 *) HeatPad__SIO_HYST_EN)
    #define HeatPad_SIO_REG_HIFREQ     (* (reg8 *) HeatPad__SIO_REG_HIFREQ)
    #define HeatPad_SIO_CFG            (* (reg8 *) HeatPad__SIO_CFG)
    #define HeatPad_SIO_DIFF           (* (reg8 *) HeatPad__SIO_DIFF)
#endif /* (HeatPad__SIO_CFG) */

/* Interrupt Registers */
#if defined(HeatPad__INTSTAT)
    #define HeatPad_INTSTAT            (* (reg8 *) HeatPad__INTSTAT)
    #define HeatPad_SNAP               (* (reg8 *) HeatPad__SNAP)
    
	#define HeatPad_0_INTTYPE_REG 		(* (reg8 *) HeatPad__0__INTTYPE)
#endif /* (HeatPad__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_HeatPad_H */


/* [] END OF FILE */
