/*******************************************************************************
* File Name: nSW1.h  
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

#if !defined(CY_PINS_nSW1_H) /* Pins nSW1_H */
#define CY_PINS_nSW1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "nSW1_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 nSW1__PORT == 15 && ((nSW1__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    nSW1_Write(uint8 value);
void    nSW1_SetDriveMode(uint8 mode);
uint8   nSW1_ReadDataReg(void);
uint8   nSW1_Read(void);
void    nSW1_SetInterruptMode(uint16 position, uint16 mode);
uint8   nSW1_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the nSW1_SetDriveMode() function.
     *  @{
     */
        #define nSW1_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define nSW1_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define nSW1_DM_RES_UP          PIN_DM_RES_UP
        #define nSW1_DM_RES_DWN         PIN_DM_RES_DWN
        #define nSW1_DM_OD_LO           PIN_DM_OD_LO
        #define nSW1_DM_OD_HI           PIN_DM_OD_HI
        #define nSW1_DM_STRONG          PIN_DM_STRONG
        #define nSW1_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define nSW1_MASK               nSW1__MASK
#define nSW1_SHIFT              nSW1__SHIFT
#define nSW1_WIDTH              1u

/* Interrupt constants */
#if defined(nSW1__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in nSW1_SetInterruptMode() function.
     *  @{
     */
        #define nSW1_INTR_NONE      (uint16)(0x0000u)
        #define nSW1_INTR_RISING    (uint16)(0x0001u)
        #define nSW1_INTR_FALLING   (uint16)(0x0002u)
        #define nSW1_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define nSW1_INTR_MASK      (0x01u) 
#endif /* (nSW1__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define nSW1_PS                     (* (reg8 *) nSW1__PS)
/* Data Register */
#define nSW1_DR                     (* (reg8 *) nSW1__DR)
/* Port Number */
#define nSW1_PRT_NUM                (* (reg8 *) nSW1__PRT) 
/* Connect to Analog Globals */                                                  
#define nSW1_AG                     (* (reg8 *) nSW1__AG)                       
/* Analog MUX bux enable */
#define nSW1_AMUX                   (* (reg8 *) nSW1__AMUX) 
/* Bidirectional Enable */                                                        
#define nSW1_BIE                    (* (reg8 *) nSW1__BIE)
/* Bit-mask for Aliased Register Access */
#define nSW1_BIT_MASK               (* (reg8 *) nSW1__BIT_MASK)
/* Bypass Enable */
#define nSW1_BYP                    (* (reg8 *) nSW1__BYP)
/* Port wide control signals */                                                   
#define nSW1_CTL                    (* (reg8 *) nSW1__CTL)
/* Drive Modes */
#define nSW1_DM0                    (* (reg8 *) nSW1__DM0) 
#define nSW1_DM1                    (* (reg8 *) nSW1__DM1)
#define nSW1_DM2                    (* (reg8 *) nSW1__DM2) 
/* Input Buffer Disable Override */
#define nSW1_INP_DIS                (* (reg8 *) nSW1__INP_DIS)
/* LCD Common or Segment Drive */
#define nSW1_LCD_COM_SEG            (* (reg8 *) nSW1__LCD_COM_SEG)
/* Enable Segment LCD */
#define nSW1_LCD_EN                 (* (reg8 *) nSW1__LCD_EN)
/* Slew Rate Control */
#define nSW1_SLW                    (* (reg8 *) nSW1__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define nSW1_PRTDSI__CAPS_SEL       (* (reg8 *) nSW1__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define nSW1_PRTDSI__DBL_SYNC_IN    (* (reg8 *) nSW1__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define nSW1_PRTDSI__OE_SEL0        (* (reg8 *) nSW1__PRTDSI__OE_SEL0) 
#define nSW1_PRTDSI__OE_SEL1        (* (reg8 *) nSW1__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define nSW1_PRTDSI__OUT_SEL0       (* (reg8 *) nSW1__PRTDSI__OUT_SEL0) 
#define nSW1_PRTDSI__OUT_SEL1       (* (reg8 *) nSW1__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define nSW1_PRTDSI__SYNC_OUT       (* (reg8 *) nSW1__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(nSW1__SIO_CFG)
    #define nSW1_SIO_HYST_EN        (* (reg8 *) nSW1__SIO_HYST_EN)
    #define nSW1_SIO_REG_HIFREQ     (* (reg8 *) nSW1__SIO_REG_HIFREQ)
    #define nSW1_SIO_CFG            (* (reg8 *) nSW1__SIO_CFG)
    #define nSW1_SIO_DIFF           (* (reg8 *) nSW1__SIO_DIFF)
#endif /* (nSW1__SIO_CFG) */

/* Interrupt Registers */
#if defined(nSW1__INTSTAT)
    #define nSW1_INTSTAT            (* (reg8 *) nSW1__INTSTAT)
    #define nSW1_SNAP               (* (reg8 *) nSW1__SNAP)
    
	#define nSW1_0_INTTYPE_REG 		(* (reg8 *) nSW1__0__INTTYPE)
#endif /* (nSW1__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_nSW1_H */


/* [] END OF FILE */
