/*******************************************************************************
* File Name: Fan.h  
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

#if !defined(CY_PINS_Fan_H) /* Pins Fan_H */
#define CY_PINS_Fan_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Fan_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Fan__PORT == 15 && ((Fan__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Fan_Write(uint8 value);
void    Fan_SetDriveMode(uint8 mode);
uint8   Fan_ReadDataReg(void);
uint8   Fan_Read(void);
void    Fan_SetInterruptMode(uint16 position, uint16 mode);
uint8   Fan_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Fan_SetDriveMode() function.
     *  @{
     */
        #define Fan_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Fan_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Fan_DM_RES_UP          PIN_DM_RES_UP
        #define Fan_DM_RES_DWN         PIN_DM_RES_DWN
        #define Fan_DM_OD_LO           PIN_DM_OD_LO
        #define Fan_DM_OD_HI           PIN_DM_OD_HI
        #define Fan_DM_STRONG          PIN_DM_STRONG
        #define Fan_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Fan_MASK               Fan__MASK
#define Fan_SHIFT              Fan__SHIFT
#define Fan_WIDTH              1u

/* Interrupt constants */
#if defined(Fan__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Fan_SetInterruptMode() function.
     *  @{
     */
        #define Fan_INTR_NONE      (uint16)(0x0000u)
        #define Fan_INTR_RISING    (uint16)(0x0001u)
        #define Fan_INTR_FALLING   (uint16)(0x0002u)
        #define Fan_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Fan_INTR_MASK      (0x01u) 
#endif /* (Fan__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Fan_PS                     (* (reg8 *) Fan__PS)
/* Data Register */
#define Fan_DR                     (* (reg8 *) Fan__DR)
/* Port Number */
#define Fan_PRT_NUM                (* (reg8 *) Fan__PRT) 
/* Connect to Analog Globals */                                                  
#define Fan_AG                     (* (reg8 *) Fan__AG)                       
/* Analog MUX bux enable */
#define Fan_AMUX                   (* (reg8 *) Fan__AMUX) 
/* Bidirectional Enable */                                                        
#define Fan_BIE                    (* (reg8 *) Fan__BIE)
/* Bit-mask for Aliased Register Access */
#define Fan_BIT_MASK               (* (reg8 *) Fan__BIT_MASK)
/* Bypass Enable */
#define Fan_BYP                    (* (reg8 *) Fan__BYP)
/* Port wide control signals */                                                   
#define Fan_CTL                    (* (reg8 *) Fan__CTL)
/* Drive Modes */
#define Fan_DM0                    (* (reg8 *) Fan__DM0) 
#define Fan_DM1                    (* (reg8 *) Fan__DM1)
#define Fan_DM2                    (* (reg8 *) Fan__DM2) 
/* Input Buffer Disable Override */
#define Fan_INP_DIS                (* (reg8 *) Fan__INP_DIS)
/* LCD Common or Segment Drive */
#define Fan_LCD_COM_SEG            (* (reg8 *) Fan__LCD_COM_SEG)
/* Enable Segment LCD */
#define Fan_LCD_EN                 (* (reg8 *) Fan__LCD_EN)
/* Slew Rate Control */
#define Fan_SLW                    (* (reg8 *) Fan__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Fan_PRTDSI__CAPS_SEL       (* (reg8 *) Fan__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Fan_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Fan__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Fan_PRTDSI__OE_SEL0        (* (reg8 *) Fan__PRTDSI__OE_SEL0) 
#define Fan_PRTDSI__OE_SEL1        (* (reg8 *) Fan__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Fan_PRTDSI__OUT_SEL0       (* (reg8 *) Fan__PRTDSI__OUT_SEL0) 
#define Fan_PRTDSI__OUT_SEL1       (* (reg8 *) Fan__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Fan_PRTDSI__SYNC_OUT       (* (reg8 *) Fan__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Fan__SIO_CFG)
    #define Fan_SIO_HYST_EN        (* (reg8 *) Fan__SIO_HYST_EN)
    #define Fan_SIO_REG_HIFREQ     (* (reg8 *) Fan__SIO_REG_HIFREQ)
    #define Fan_SIO_CFG            (* (reg8 *) Fan__SIO_CFG)
    #define Fan_SIO_DIFF           (* (reg8 *) Fan__SIO_DIFF)
#endif /* (Fan__SIO_CFG) */

/* Interrupt Registers */
#if defined(Fan__INTSTAT)
    #define Fan_INTSTAT            (* (reg8 *) Fan__INTSTAT)
    #define Fan_SNAP               (* (reg8 *) Fan__SNAP)
    
	#define Fan_0_INTTYPE_REG 		(* (reg8 *) Fan__0__INTTYPE)
#endif /* (Fan__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Fan_H */


/* [] END OF FILE */
