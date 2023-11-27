
#include "External_interrupt_register.h"
#include "External_interrupt_interface.h"


/* External interrupt 0 initialization */
E_Error_state MCAL_EXT_INT_0_init(EN_interrupt_sense_t sense)
{
	E_Error_state error =OK;
	if(Interrupt_STATUS_ERROR ==NOT_OK)
	{
		error =NOT_OK;
	}
	else
	{
		/* Enable the global interrupt */
		sei();
		/*  Choose the interrupt sense on external interrupt 0 */
		switch(sense)
		{
		/* Low level interrupt */
		case low_level_sense:
			MCUCR &=~ ((1<<ISC00)|(1<<ISC01));
			break;
			/* Any logical change */
		case anyLogicChange_sense:
			MCUCR |= (1<<ISC00);
			break;
			/* Falling edge trigger */
		case falling_edge_sense:
			MCUCR |= (1<<ISC01);
			break;
			/* Rising edge */
		case rising_edge_sense:
			MCUCR |= (1<<ISC01) | (1<<ISC00);
			break;
		default:
			break;
		}
		/* Enable the external interrupt 0 */
		GICR |= (1<<INT0);
	}
	return error;

}

/* External interrupt 1 initialization */
E_Error_state MCAL_EXT_INT_1_init(EN_interrupt_sense_t sense)
{
	E_Error_state error =OK;
	if(Interrupt_STATUS_ERROR ==NOT_OK)
	{
		error =NOT_OK;
	}
	else
	{

		/* Enable the global interrupt */
		sei();
		/* Choose the interrupt sense on external interrupt */
		switch(sense)
		{
		/* Low level interrupt */
		case low_level_sense:
			MCUCR &=~ ((1<<ISC10)|(1<<ISC11));
			break;
			/* Any logical change */
		case anyLogicChange_sense:
			MCUCR |= (1<<ISC10);
			break;
			/* Falling edge trigger */
		case falling_edge_sense:
			MCUCR |= (1<<ISC11);
			break;
			/* Rising edge */
		case rising_edge_sense:
			MCUCR |= (1<<ISC11) | (1<<ISC10);
			break;
		default:
			break;
		}
		/* Enable the external interrupt */
		GICR |= (1<<INT1);
	}
	return error;

}


/* External interrupt 2 initialization */
E_Error_state MCAL_EXT_INT_2_init(EN_interrupt_sense_t sense)
{
	E_Error_state error =OK;
	if(Interrupt_STATUS_ERROR ==NOT_OK)
	{
		error =NOT_OK;
	}
	else
	{
		/* Enable the global interrupt2 */
		sei();
		/* Choose the interrupt sense on external interrupt2 */
		switch(sense)
		{
		/* Falling edge trigger */
		case falling_edge_sense:
			MCUCSR &= ~(1<<ISC2);
			break;
			/* Rising edge */
		case rising_edge_sense:
			MCUCSR |= (1<<ISC2);
			break;
		default:
			break;
		}
		/* Enable the external interrupt2 */
		GICR |= (1<<INT2);
	}
	return error;

}


E_Error_state MCAL_Ext_INT_setCallBack(void(* ptr_to_ISR_ExT_INT)(void),ext_int interrupt)
{
	E_Error_state error=OK;
	if(Interrupt_STATUS_ERROR ==NOT_OK)
		{
			error =NOT_OK;
		}
		else
		{

	switch (interrupt)
	{
	case ext_int_0:
		if ((ptr_to_ISR_ExT_INT) != NULL)
		{
			ptr2fun_ext_int_0 = ptr_to_ISR_ExT_INT;
		}
		break;
	case ext_int_1:
		if( (ptr_to_ISR_ExT_INT) != NULL)
		{
			ptr2fun_ext_int_1 = ptr_to_ISR_ExT_INT;
		}
		break;
	case ext_int_2:
		if( (ptr_to_ISR_ExT_INT) != NULL)
		{
			ptr2fun_ext_int_2 = ptr_to_ISR_ExT_INT;
		}
		break;
	default:
		break;

	}
		}
	return error;
}


ISR(EXT_INT_0)
{
	if (ptr2fun_ext_int_0 != NULL)
	{
		ptr2fun_ext_int_0();
	}
}



ISR(EXT_INT_1)
{
	if (ptr2fun_ext_int_1 != NULL)
	{
		ptr2fun_ext_int_1();
	}
}



ISR(EXT_INT_2)
{
	if (ptr2fun_ext_int_2 != NULL)
	{
		ptr2fun_ext_int_2();
	}
}

