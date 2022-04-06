/*******************************************************************************
* File Name: inTemp.h  
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

#if !defined(CY_PINS_inTemp_H) /* Pins inTemp_H */
#define CY_PINS_inTemp_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "inTemp_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 inTemp__PORT == 15 && ((inTemp__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    inTemp_Write(uint8 value);
void    inTemp_SetDriveMode(uint8 mode);
uint8   inTemp_ReadDataReg(void);
uint8   inTemp_Read(void);
void    inTemp_SetInterruptMode(uint16 position, uint16 mode);
uint8   inTemp_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the inTemp_SetDriveMode() function.
     *  @{
     */
        #define inTemp_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define inTemp_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define inTemp_DM_RES_UP          PIN_DM_RES_UP
        #define inTemp_DM_RES_DWN         PIN_DM_RES_DWN
        #define inTemp_DM_OD_LO           PIN_DM_OD_LO
        #define inTemp_DM_OD_HI           PIN_DM_OD_HI
        #define inTemp_DM_STRONG          PIN_DM_STRONG
        #define inTemp_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define inTemp_MASK               inTemp__MASK
#define inTemp_SHIFT              inTemp__SHIFT
#define inTemp_WIDTH              1u

/* Interrupt constants */
#if defined(inTemp__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in inTemp_SetInterruptMode() function.
     *  @{
     */
        #define inTemp_INTR_NONE      (uint16)(0x0000u)
        #define inTemp_INTR_RISING    (uint16)(0x0001u)
        #define inTemp_INTR_FALLING   (uint16)(0x0002u)
        #define inTemp_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define inTemp_INTR_MASK      (0x01u) 
#endif /* (inTemp__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define inTemp_PS                     (* (reg8 *) inTemp__PS)
/* Data Register */
#define inTemp_DR                     (* (reg8 *) inTemp__DR)
/* Port Number */
#define inTemp_PRT_NUM                (* (reg8 *) inTemp__PRT) 
/* Connect to Analog Globals */                                                  
#define inTemp_AG                     (* (reg8 *) inTemp__AG)                       
/* Analog MUX bux enable */
#define inTemp_AMUX                   (* (reg8 *) inTemp__AMUX) 
/* Bidirectional Enable */                                                        
#define inTemp_BIE                    (* (reg8 *) inTemp__BIE)
/* Bit-mask for Aliased Register Access */
#define inTemp_BIT_MASK               (* (reg8 *) inTemp__BIT_MASK)
/* Bypass Enable */
#define inTemp_BYP                    (* (reg8 *) inTemp__BYP)
/* Port wide control signals */                                                   
#define inTemp_CTL                    (* (reg8 *) inTemp__CTL)
/* Drive Modes */
#define inTemp_DM0                    (* (reg8 *) inTemp__DM0) 
#define inTemp_DM1                    (* (reg8 *) inTemp__DM1)
#define inTemp_DM2                    (* (reg8 *) inTemp__DM2) 
/* Input Buffer Disable Override */
#define inTemp_INP_DIS                (* (reg8 *) inTemp__INP_DIS)
/* LCD Common or Segment Drive */
#define inTemp_LCD_COM_SEG            (* (reg8 *) inTemp__LCD_COM_SEG)
/* Enable Segment LCD */
#define inTemp_LCD_EN                 (* (reg8 *) inTemp__LCD_EN)
/* Slew Rate Control */
#define inTemp_SLW                    (* (reg8 *) inTemp__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define inTemp_PRTDSI__CAPS_SEL       (* (reg8 *) inTemp__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define inTemp_PRTDSI__DBL_SYNC_IN    (* (reg8 *) inTemp__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define inTemp_PRTDSI__OE_SEL0        (* (reg8 *) inTemp__PRTDSI__OE_SEL0) 
#define inTemp_PRTDSI__OE_SEL1        (* (reg8 *) inTemp__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define inTemp_PRTDSI__OUT_SEL0       (* (reg8 *) inTemp__PRTDSI__OUT_SEL0) 
#define inTemp_PRTDSI__OUT_SEL1       (* (reg8 *) inTemp__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define inTemp_PRTDSI__SYNC_OUT       (* (reg8 *) inTemp__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(inTemp__SIO_CFG)
    #define inTemp_SIO_HYST_EN        (* (reg8 *) inTemp__SIO_HYST_EN)
    #define inTemp_SIO_REG_HIFREQ     (* (reg8 *) inTemp__SIO_REG_HIFREQ)
    #define inTemp_SIO_CFG            (* (reg8 *) inTemp__SIO_CFG)
    #define inTemp_SIO_DIFF           (* (reg8 *) inTemp__SIO_DIFF)
#endif /* (inTemp__SIO_CFG) */

/* Interrupt Registers */
#if defined(inTemp__INTSTAT)
    #define inTemp_INTSTAT            (* (reg8 *) inTemp__INTSTAT)
    #define inTemp_SNAP               (* (reg8 *) inTemp__SNAP)
    
	#define inTemp_0_INTTYPE_REG 		(* (reg8 *) inTemp__0__INTTYPE)
#endif /* (inTemp__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_inTemp_H */


/* [] END OF FILE */
