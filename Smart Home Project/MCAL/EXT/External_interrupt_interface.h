/*
 * External_interrupt_interface.h
 *
 *  Created on: Nov 6, 2023
 *      Author: pc
 */

#ifndef MCAL_EXT_EXTERNAL_INTERRUPT_INTERFACE_H_
#define MCAL_EXT_EXTERNAL_INTERRUPT_INTERFACE_H_


#include "External_interrupt_register.h"
#include "External_interrupt_private.h"
#include "External_interrupt_Types.h"
#include "External_interrupt_config.h"



/* External interrupt 0 initialization */
E_Error_state MCAL_EXT_INT_0_init(EN_interrupt_sense_t sense);
/* External interrupt 1 initialization */
E_Error_state MCAL_EXT_INT_1_init(EN_interrupt_sense_t sense);
/* External interrupt 2 initialization */
E_Error_state MCAL_EXT_INT_2_init(EN_interrupt_sense_t sense);
/* Call pack function to ISR of external interrupt 0 */
E_Error_state MCAL_Ext_INT_setCallBack(void(* ptr_to_ISR_ExT_INT_)(void),ext_int interrupt);


#endif /* MCAL_EXT_EXTERNAL_INTERRUPT_INTERFACE_H_ */
