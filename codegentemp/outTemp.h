/*******************************************************************************
* File Name: outTemp.h  
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

#if !defined(CY_PINS_outTemp_H) /* Pins outTemp_H */
#define CY_PINS_outTemp_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "outTemp_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 outTemp__PORT == 15 && ((outTemp__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    outTemp_Write(uint8 value);
void    outTemp_SetDriveMode(uint8 mode);
uint8   outTemp_ReadDataReg(void);
uint8   outTemp_Read(void);
void    outTemp_SetInterruptMode(uint16 position, uint16 mode);
uint8   outTemp_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the outTemp_SetDriveMode() function.
     *  @{
     */
        #define outTemp_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define outTemp_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define outTemp_DM_RES_UP          PIN_DM_RES_UP
        #define outTemp_DM_RES_DWN         PIN_DM_RES_DWN
        #define outTemp_DM_OD_LO           PIN_DM_OD_LO
        #define outTemp_DM_OD_HI           PIN_DM_OD_HI
        #define outTemp_DM_STRONG          PIN_DM_STRONG
        #define outTemp_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define outTemp_MASK               outTemp__MASK
#define outTemp_SHIFT              outTemp__SHIFT
#define outTemp_WIDTH              1u

/* Interrupt constants */
#if defined(outTemp__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in outTemp_SetInterruptMode() function.
     *  @{
     */
        #define outTemp_INTR_NONE      (uint16)(0x0000u)
        #define outTemp_INTR_RISING    (uint16)(0x0001u)
        #define outTemp_INTR_FALLING   (uint16)(0x0002u)
        #define outTemp_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define outTemp_INTR_MASK      (0x01u) 
#endif /* (outTemp__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define outTemp_PS                     (* (reg8 *) outTemp__PS)
/* Data Register */
#define outTemp_DR                     (* (reg8 *) outTemp__DR)
/* Port Number */
#define outTemp_PRT_NUM                (* (reg8 *) outTemp__PRT) 
/* Connect to Analog Globals */                                                  
#define outTemp_AG                     (* (reg8 *) outTemp__AG)                       
/* Analog MUX bux enable */
#define outTemp_AMUX                   (* (reg8 *) outTemp__AMUX) 
/* Bidirectional Enable */                                                        
#define outTemp_BIE                    (* (reg8 *) outTemp__BIE)
/* Bit-mask for Aliased Register Access */
#define outTemp_BIT_MASK               (* (reg8 *) outTemp__BIT_MASK)
/* Bypass Enable */
#define outTemp_BYP                    (* (reg8 *) outTemp__BYP)
/* Port wide control signals */                                                   
#define outTemp_CTL                    (* (reg8 *) outTemp__CTL)
/* Drive Modes */
#define outTemp_DM0                    (* (reg8 *) outTemp__DM0) 
#define outTemp_DM1                    (* (reg8 *) outTemp__DM1)
#define outTemp_DM2                    (* (reg8 *) outTemp__DM2) 
/* Input Buffer Disable Override */
#define outTemp_INP_DIS                (* (reg8 *) outTemp__INP_DIS)
/* LCD Common or Segment Drive */
#define outTemp_LCD_COM_SEG            (* (reg8 *) outTemp__LCD_COM_SEG)
/* Enable Segment LCD */
#define outTemp_LCD_EN                 (* (reg8 *) outTemp__LCD_EN)
/* Slew Rate Control */
#define outTemp_SLW                    (* (reg8 *) outTemp__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define outTemp_PRTDSI__CAPS_SEL       (* (reg8 *) outTemp__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define outTemp_PRTDSI__DBL_SYNC_IN    (* (reg8 *) outTemp__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define outTemp_PRTDSI__OE_SEL0        (* (reg8 *) outTemp__PRTDSI__OE_SEL0) 
#define outTemp_PRTDSI__OE_SEL1        (* (reg8 *) outTemp__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define outTemp_PRTDSI__OUT_SEL0       (* (reg8 *) outTemp__PRTDSI__OUT_SEL0) 
#define outTemp_PRTDSI__OUT_SEL1       (* (reg8 *) outTemp__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define outTemp_PRTDSI__SYNC_OUT       (* (reg8 *) outTemp__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(outTemp__SIO_CFG)
    #define outTemp_SIO_HYST_EN        (* (reg8 *) outTemp__SIO_HYST_EN)
    #define outTemp_SIO_REG_HIFREQ     (* (reg8 *) outTemp__SIO_REG_HIFREQ)
    #define outTemp_SIO_CFG            (* (reg8 *) outTemp__SIO_CFG)
    #define outTemp_SIO_DIFF           (* (reg8 *) outTemp__SIO_DIFF)
#endif /* (outTemp__SIO_CFG) */

/* Interrupt Registers */
#if defined(outTemp__INTSTAT)
    #define outTemp_INTSTAT            (* (reg8 *) outTemp__INTSTAT)
    #define outTemp_SNAP               (* (reg8 *) outTemp__SNAP)
    
	#define outTemp_0_INTTYPE_REG 		(* (reg8 *) outTemp__0__INTTYPE)
#endif /* (outTemp__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_outTemp_H */


/* [] END OF FILE */
