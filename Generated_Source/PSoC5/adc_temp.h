/*******************************************************************************
* File Name: adc_temp.h  
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

#if !defined(CY_PINS_adc_temp_H) /* Pins adc_temp_H */
#define CY_PINS_adc_temp_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "adc_temp_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 adc_temp__PORT == 15 && ((adc_temp__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    adc_temp_Write(uint8 value);
void    adc_temp_SetDriveMode(uint8 mode);
uint8   adc_temp_ReadDataReg(void);
uint8   adc_temp_Read(void);
void    adc_temp_SetInterruptMode(uint16 position, uint16 mode);
uint8   adc_temp_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the adc_temp_SetDriveMode() function.
     *  @{
     */
        #define adc_temp_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define adc_temp_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define adc_temp_DM_RES_UP          PIN_DM_RES_UP
        #define adc_temp_DM_RES_DWN         PIN_DM_RES_DWN
        #define adc_temp_DM_OD_LO           PIN_DM_OD_LO
        #define adc_temp_DM_OD_HI           PIN_DM_OD_HI
        #define adc_temp_DM_STRONG          PIN_DM_STRONG
        #define adc_temp_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define adc_temp_MASK               adc_temp__MASK
#define adc_temp_SHIFT              adc_temp__SHIFT
#define adc_temp_WIDTH              1u

/* Interrupt constants */
#if defined(adc_temp__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in adc_temp_SetInterruptMode() function.
     *  @{
     */
        #define adc_temp_INTR_NONE      (uint16)(0x0000u)
        #define adc_temp_INTR_RISING    (uint16)(0x0001u)
        #define adc_temp_INTR_FALLING   (uint16)(0x0002u)
        #define adc_temp_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define adc_temp_INTR_MASK      (0x01u) 
#endif /* (adc_temp__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define adc_temp_PS                     (* (reg8 *) adc_temp__PS)
/* Data Register */
#define adc_temp_DR                     (* (reg8 *) adc_temp__DR)
/* Port Number */
#define adc_temp_PRT_NUM                (* (reg8 *) adc_temp__PRT) 
/* Connect to Analog Globals */                                                  
#define adc_temp_AG                     (* (reg8 *) adc_temp__AG)                       
/* Analog MUX bux enable */
#define adc_temp_AMUX                   (* (reg8 *) adc_temp__AMUX) 
/* Bidirectional Enable */                                                        
#define adc_temp_BIE                    (* (reg8 *) adc_temp__BIE)
/* Bit-mask for Aliased Register Access */
#define adc_temp_BIT_MASK               (* (reg8 *) adc_temp__BIT_MASK)
/* Bypass Enable */
#define adc_temp_BYP                    (* (reg8 *) adc_temp__BYP)
/* Port wide control signals */                                                   
#define adc_temp_CTL                    (* (reg8 *) adc_temp__CTL)
/* Drive Modes */
#define adc_temp_DM0                    (* (reg8 *) adc_temp__DM0) 
#define adc_temp_DM1                    (* (reg8 *) adc_temp__DM1)
#define adc_temp_DM2                    (* (reg8 *) adc_temp__DM2) 
/* Input Buffer Disable Override */
#define adc_temp_INP_DIS                (* (reg8 *) adc_temp__INP_DIS)
/* LCD Common or Segment Drive */
#define adc_temp_LCD_COM_SEG            (* (reg8 *) adc_temp__LCD_COM_SEG)
/* Enable Segment LCD */
#define adc_temp_LCD_EN                 (* (reg8 *) adc_temp__LCD_EN)
/* Slew Rate Control */
#define adc_temp_SLW                    (* (reg8 *) adc_temp__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define adc_temp_PRTDSI__CAPS_SEL       (* (reg8 *) adc_temp__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define adc_temp_PRTDSI__DBL_SYNC_IN    (* (reg8 *) adc_temp__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define adc_temp_PRTDSI__OE_SEL0        (* (reg8 *) adc_temp__PRTDSI__OE_SEL0) 
#define adc_temp_PRTDSI__OE_SEL1        (* (reg8 *) adc_temp__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define adc_temp_PRTDSI__OUT_SEL0       (* (reg8 *) adc_temp__PRTDSI__OUT_SEL0) 
#define adc_temp_PRTDSI__OUT_SEL1       (* (reg8 *) adc_temp__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define adc_temp_PRTDSI__SYNC_OUT       (* (reg8 *) adc_temp__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(adc_temp__SIO_CFG)
    #define adc_temp_SIO_HYST_EN        (* (reg8 *) adc_temp__SIO_HYST_EN)
    #define adc_temp_SIO_REG_HIFREQ     (* (reg8 *) adc_temp__SIO_REG_HIFREQ)
    #define adc_temp_SIO_CFG            (* (reg8 *) adc_temp__SIO_CFG)
    #define adc_temp_SIO_DIFF           (* (reg8 *) adc_temp__SIO_DIFF)
#endif /* (adc_temp__SIO_CFG) */

/* Interrupt Registers */
#if defined(adc_temp__INTSTAT)
    #define adc_temp_INTSTAT            (* (reg8 *) adc_temp__INTSTAT)
    #define adc_temp_SNAP               (* (reg8 *) adc_temp__SNAP)
    
	#define adc_temp_0_INTTYPE_REG 		(* (reg8 *) adc_temp__0__INTTYPE)
#endif /* (adc_temp__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_adc_temp_H */


/* [] END OF FILE */
