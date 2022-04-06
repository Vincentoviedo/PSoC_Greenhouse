/*******************************************************************************
* File Name: DHT.h  
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

#if !defined(CY_PINS_DHT_H) /* Pins DHT_H */
#define CY_PINS_DHT_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "DHT_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 DHT__PORT == 15 && ((DHT__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    DHT_Write(uint8 value);
void    DHT_SetDriveMode(uint8 mode);
uint8   DHT_ReadDataReg(void);
uint8   DHT_Read(void);
void    DHT_SetInterruptMode(uint16 position, uint16 mode);
uint8   DHT_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the DHT_SetDriveMode() function.
     *  @{
     */
        #define DHT_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define DHT_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define DHT_DM_RES_UP          PIN_DM_RES_UP
        #define DHT_DM_RES_DWN         PIN_DM_RES_DWN
        #define DHT_DM_OD_LO           PIN_DM_OD_LO
        #define DHT_DM_OD_HI           PIN_DM_OD_HI
        #define DHT_DM_STRONG          PIN_DM_STRONG
        #define DHT_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define DHT_MASK               DHT__MASK
#define DHT_SHIFT              DHT__SHIFT
#define DHT_WIDTH              1u

/* Interrupt constants */
#if defined(DHT__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in DHT_SetInterruptMode() function.
     *  @{
     */
        #define DHT_INTR_NONE      (uint16)(0x0000u)
        #define DHT_INTR_RISING    (uint16)(0x0001u)
        #define DHT_INTR_FALLING   (uint16)(0x0002u)
        #define DHT_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define DHT_INTR_MASK      (0x01u) 
#endif /* (DHT__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define DHT_PS                     (* (reg8 *) DHT__PS)
/* Data Register */
#define DHT_DR                     (* (reg8 *) DHT__DR)
/* Port Number */
#define DHT_PRT_NUM                (* (reg8 *) DHT__PRT) 
/* Connect to Analog Globals */                                                  
#define DHT_AG                     (* (reg8 *) DHT__AG)                       
/* Analog MUX bux enable */
#define DHT_AMUX                   (* (reg8 *) DHT__AMUX) 
/* Bidirectional Enable */                                                        
#define DHT_BIE                    (* (reg8 *) DHT__BIE)
/* Bit-mask for Aliased Register Access */
#define DHT_BIT_MASK               (* (reg8 *) DHT__BIT_MASK)
/* Bypass Enable */
#define DHT_BYP                    (* (reg8 *) DHT__BYP)
/* Port wide control signals */                                                   
#define DHT_CTL                    (* (reg8 *) DHT__CTL)
/* Drive Modes */
#define DHT_DM0                    (* (reg8 *) DHT__DM0) 
#define DHT_DM1                    (* (reg8 *) DHT__DM1)
#define DHT_DM2                    (* (reg8 *) DHT__DM2) 
/* Input Buffer Disable Override */
#define DHT_INP_DIS                (* (reg8 *) DHT__INP_DIS)
/* LCD Common or Segment Drive */
#define DHT_LCD_COM_SEG            (* (reg8 *) DHT__LCD_COM_SEG)
/* Enable Segment LCD */
#define DHT_LCD_EN                 (* (reg8 *) DHT__LCD_EN)
/* Slew Rate Control */
#define DHT_SLW                    (* (reg8 *) DHT__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define DHT_PRTDSI__CAPS_SEL       (* (reg8 *) DHT__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define DHT_PRTDSI__DBL_SYNC_IN    (* (reg8 *) DHT__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define DHT_PRTDSI__OE_SEL0        (* (reg8 *) DHT__PRTDSI__OE_SEL0) 
#define DHT_PRTDSI__OE_SEL1        (* (reg8 *) DHT__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define DHT_PRTDSI__OUT_SEL0       (* (reg8 *) DHT__PRTDSI__OUT_SEL0) 
#define DHT_PRTDSI__OUT_SEL1       (* (reg8 *) DHT__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define DHT_PRTDSI__SYNC_OUT       (* (reg8 *) DHT__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(DHT__SIO_CFG)
    #define DHT_SIO_HYST_EN        (* (reg8 *) DHT__SIO_HYST_EN)
    #define DHT_SIO_REG_HIFREQ     (* (reg8 *) DHT__SIO_REG_HIFREQ)
    #define DHT_SIO_CFG            (* (reg8 *) DHT__SIO_CFG)
    #define DHT_SIO_DIFF           (* (reg8 *) DHT__SIO_DIFF)
#endif /* (DHT__SIO_CFG) */

/* Interrupt Registers */
#if defined(DHT__INTSTAT)
    #define DHT_INTSTAT            (* (reg8 *) DHT__INTSTAT)
    #define DHT_SNAP               (* (reg8 *) DHT__SNAP)
    
	#define DHT_0_INTTYPE_REG 		(* (reg8 *) DHT__0__INTTYPE)
#endif /* (DHT__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_DHT_H */


/* [] END OF FILE */
