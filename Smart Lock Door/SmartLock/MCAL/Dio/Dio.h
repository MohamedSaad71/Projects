




#ifndef DIO_H_
#define DIO_H_

#include <avr/io.h>
#include <util/delay.h>
#include "common_macros.h"
#include "../../std_types.h"
#include "Dio_types.h"
#include "Dio_Config.h"

extern Dio_pin_config pin[PIN_COUNT];




void Dio_init();
void Dio_Write(channel_t ch,Dio_state_t state);
Dio_state_t Dio_Read(channel_t ch);



#endif
