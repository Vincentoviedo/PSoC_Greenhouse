/*******************************************************************************
* File Name: PRes.h  
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

#if !defined(CY_PINS_PRes_H) /* Pins PRes_H */
#define CY_PINS_PRes_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "PRes_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 PRes__PORT == 15 && ((PRes__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    PRes_Write(uint8 value);
void    PRes_SetDriveMode(uint8 mode);
uint8   PRes_ReadDataReg(void);
uint8   PRes_Read(void);
void    PRes_SetInterruptMode(uint16 position, uint16 mode);
uint8   PRes_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the PRes_SetDriveMode() function.
     *  @{
     */
        #define PRes_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define PRes_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define PRes_DM_RES_UP          PIN_DM_RES_UP
        #define PRes_DM_RES_DWN         PIN_DM_RES_DWN
        #define PRes_DM_OD_LO           PIN_DM_OD_LO
        #define PRes_DM_OD_HI           PIN_DM_OD_HI
        #define PRes_DM_STRONG          PIN_DM_STRONG
        #define PRes_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define PRes_MASK               PRes__MASK
#define PRes_SHIFT              PRes__SHIFT
#define PRes_WIDTH              1u

/* Interrupt constants */
#if defined(PRes__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in PRes_SetInterruptMode() function.
     *  @{
     */
        #define PRes_INTR_NONE      (uint16)(0x0000u)
        #define PRes_INTR_RISING    (uint16)(0x0001u)
        #define PRes_INTR_FALLING   (uint16)(0x0002u)
        #define PRes_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define PRes_INTR_MASK      (0x01u) 
#endif /* (PRes__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define PRes_PS                     (* (reg8 *) PRes__PS)
/* Data Register */
#define PRes_DR                     (* (reg8 *) PRes__DR)
/* Port Number */
#define PRes_PRT_NUM                (* (reg8 *) PRes__PRT) 
/* Connect to Analog Globals */                                                  
#define PRes_AG                     (* (reg8 *) PRes__AG)                       
/* Analog MUX bux enable */
#define PRes_AMUX                   (* (reg8 *) PRes__AMUX) 
/* Bidirectional Enable */                                                        
#define PRes_BIE                    (* (reg8 *) PRes__BIE)
/* Bit-mask for Aliased Register Access */
#define PRes_BIT_MASK               (* (reg8 *) PRes__BIT_MASK)
/* Bypass Enable */
#define PRes_BYP                    (* (reg8 *) PRes__BYP)
/* Port wide control signals */                                                   
#define PRes_CTL                    (* (reg8 *) PRes__CTL)
/* Drive Modes */
#define PRes_DM0                    (* (reg8 *) PRes__DM0) 
#define PRes_DM1                    (* (reg8 *) PRes__DM1)
#define PRes_DM2                    (* (reg8 *) PRes__DM2) 
/* Input Buffer Disable Override */
#define PRes_INP_DIS                (* (reg8 *) PRes__INP_DIS)
/* LCD Common or Segment Drive */
#define PRes_LCD_COM_SEG            (* (reg8 *) PRes__LCD_COM_SEG)
/* Enable Segment LCD */
#define PRes_LCD_EN                 (* (reg8 *) PRes__LCD_EN)
/* Slew Rate Control */
#define PRes_SLW                    (* (reg8 *) PRes__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define PRes_PRTDSI__CAPS_SEL       (* (reg8 *) PRes__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define PRes_PRTDSI__DBL_SYNC_IN    (* (reg8 *) PRes__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define PRes_PRTDSI__OE_SEL0        (* (reg8 *) PRes__PRTDSI__OE_SEL0) 
#define PRes_PRTDSI__OE_SEL1        (* (reg8 *) PRes__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define PRes_PRTDSI__OUT_SEL0       (* (reg8 *) PRes__PRTDSI__OUT_SEL0) 
#define PRes_PRTDSI__OUT_SEL1       (* (reg8 *) PRes__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define PRes_PRTDSI__SYNC_OUT       (* (reg8 *) PRes__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(PRes__SIO_CFG)
    #define PRes_SIO_HYST_EN        (* (reg8 *) PRes__SIO_HYST_EN)
    #define PRes_SIO_REG_HIFREQ     (* (reg8 *) PRes__SIO_REG_HIFREQ)
    #define PRes_SIO_CFG            (* (reg8 *) PRes__SIO_CFG)
    #define PRes_SIO_DIFF           (* (reg8 *) PRes__SIO_DIFF)
#endif /* (PRes__SIO_CFG) */

/* Interrupt Registers */
#if defined(PRes__INTSTAT)
    #define PRes_INTSTAT            (* (reg8 *) PRes__INTSTAT)
    #define PRes_SNAP               (* (reg8 *) PRes__SNAP)
    
	#define PRes_0_INTTYPE_REG 		(* (reg8 *) PRes__0__INTTYPE)
#endif /* (PRes__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_PRes_H */


/* [] END OF FILE */
