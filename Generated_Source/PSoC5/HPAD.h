/*******************************************************************************
* File Name: HPAD.h  
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

#if !defined(CY_PINS_HPAD_H) /* Pins HPAD_H */
#define CY_PINS_HPAD_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "HPAD_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 HPAD__PORT == 15 && ((HPAD__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    HPAD_Write(uint8 value);
void    HPAD_SetDriveMode(uint8 mode);
uint8   HPAD_ReadDataReg(void);
uint8   HPAD_Read(void);
void    HPAD_SetInterruptMode(uint16 position, uint16 mode);
uint8   HPAD_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the HPAD_SetDriveMode() function.
     *  @{
     */
        #define HPAD_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define HPAD_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define HPAD_DM_RES_UP          PIN_DM_RES_UP
        #define HPAD_DM_RES_DWN         PIN_DM_RES_DWN
        #define HPAD_DM_OD_LO           PIN_DM_OD_LO
        #define HPAD_DM_OD_HI           PIN_DM_OD_HI
        #define HPAD_DM_STRONG          PIN_DM_STRONG
        #define HPAD_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define HPAD_MASK               HPAD__MASK
#define HPAD_SHIFT              HPAD__SHIFT
#define HPAD_WIDTH              1u

/* Interrupt constants */
#if defined(HPAD__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in HPAD_SetInterruptMode() function.
     *  @{
     */
        #define HPAD_INTR_NONE      (uint16)(0x0000u)
        #define HPAD_INTR_RISING    (uint16)(0x0001u)
        #define HPAD_INTR_FALLING   (uint16)(0x0002u)
        #define HPAD_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define HPAD_INTR_MASK      (0x01u) 
#endif /* (HPAD__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define HPAD_PS                     (* (reg8 *) HPAD__PS)
/* Data Register */
#define HPAD_DR                     (* (reg8 *) HPAD__DR)
/* Port Number */
#define HPAD_PRT_NUM                (* (reg8 *) HPAD__PRT) 
/* Connect to Analog Globals */                                                  
#define HPAD_AG                     (* (reg8 *) HPAD__AG)                       
/* Analog MUX bux enable */
#define HPAD_AMUX                   (* (reg8 *) HPAD__AMUX) 
/* Bidirectional Enable */                                                        
#define HPAD_BIE                    (* (reg8 *) HPAD__BIE)
/* Bit-mask for Aliased Register Access */
#define HPAD_BIT_MASK               (* (reg8 *) HPAD__BIT_MASK)
/* Bypass Enable */
#define HPAD_BYP                    (* (reg8 *) HPAD__BYP)
/* Port wide control signals */                                                   
#define HPAD_CTL                    (* (reg8 *) HPAD__CTL)
/* Drive Modes */
#define HPAD_DM0                    (* (reg8 *) HPAD__DM0) 
#define HPAD_DM1                    (* (reg8 *) HPAD__DM1)
#define HPAD_DM2                    (* (reg8 *) HPAD__DM2) 
/* Input Buffer Disable Override */
#define HPAD_INP_DIS                (* (reg8 *) HPAD__INP_DIS)
/* LCD Common or Segment Drive */
#define HPAD_LCD_COM_SEG            (* (reg8 *) HPAD__LCD_COM_SEG)
/* Enable Segment LCD */
#define HPAD_LCD_EN                 (* (reg8 *) HPAD__LCD_EN)
/* Slew Rate Control */
#define HPAD_SLW                    (* (reg8 *) HPAD__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define HPAD_PRTDSI__CAPS_SEL       (* (reg8 *) HPAD__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define HPAD_PRTDSI__DBL_SYNC_IN    (* (reg8 *) HPAD__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define HPAD_PRTDSI__OE_SEL0        (* (reg8 *) HPAD__PRTDSI__OE_SEL0) 
#define HPAD_PRTDSI__OE_SEL1        (* (reg8 *) HPAD__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define HPAD_PRTDSI__OUT_SEL0       (* (reg8 *) HPAD__PRTDSI__OUT_SEL0) 
#define HPAD_PRTDSI__OUT_SEL1       (* (reg8 *) HPAD__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define HPAD_PRTDSI__SYNC_OUT       (* (reg8 *) HPAD__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(HPAD__SIO_CFG)
    #define HPAD_SIO_HYST_EN        (* (reg8 *) HPAD__SIO_HYST_EN)
    #define HPAD_SIO_REG_HIFREQ     (* (reg8 *) HPAD__SIO_REG_HIFREQ)
    #define HPAD_SIO_CFG            (* (reg8 *) HPAD__SIO_CFG)
    #define HPAD_SIO_DIFF           (* (reg8 *) HPAD__SIO_DIFF)
#endif /* (HPAD__SIO_CFG) */

/* Interrupt Registers */
#if defined(HPAD__INTSTAT)
    #define HPAD_INTSTAT            (* (reg8 *) HPAD__INTSTAT)
    #define HPAD_SNAP               (* (reg8 *) HPAD__SNAP)
    
	#define HPAD_0_INTTYPE_REG 		(* (reg8 *) HPAD__0__INTTYPE)
#endif /* (HPAD__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_HPAD_H */


/* [] END OF FILE */
