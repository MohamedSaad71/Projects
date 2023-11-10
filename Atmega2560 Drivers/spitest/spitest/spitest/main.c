/*
 * spitest.c
 *
 * Created: 6/13/2023 5:19:40 PM
 * Author : pc
 */ 

#include <avr/io.h>
#include "common_macros.h"
#include "SPI.h"
#include "std_types.h"
#include "gpio.h"
#include "micros_config.h"
#include "MemMap.h"

int main(void)
{
	SPI_Init(MASTER);
	SPI_SendReceive('A');
    /* Replace with your application code */
    while (1) 
    {
    }
}

