/*
 * setOnFlag.c
 *
 *  Created on: 7 Nov 2023
 *      Author: Ayaya
 */


#include "setOnFlag.h"



void SERVICE_SET_ON_FLAG()
{
	lockedFlag =0;
	onFlag =1 ;

	SERVICE_EVERYTHING_ON();
}
