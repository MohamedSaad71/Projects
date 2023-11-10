/*
 * TIMERS_registers.h
 *
 * Created: 10/26/2023 2:22:11 PM
 *  Author: MERNA
 */ 


#ifndef TIMERS_REGISTERS_H_
#define TIMERS_REGISTERS_H_
#define ICF1	5
#define WGM00	6
#define WGM01	3
#define	COM00	4
#define	COM01	5
#define	CS00	0
#define	CS01	1
#define	CS02	2
#define TCNT0			*((volatile unsigned char*)(0x52))
#define TIMSK			*((volatile unsigned char*)(0x59))
#define TIFR             *((volatile unsigned char*)(0x58))
#define TCCR0			*((volatile unsigned char*)(0x53))
#define OCR0             *((volatile unsigned char*)(0x5C))
#define TCCR1A           *((volatile unsigned char*)(0x4F))
#define TCCR1B           *((volatile unsigned char*)(0x4E))
#define TCNT1            *((volatile unsigned short*)(0x4C))
#define TCNT1H           *((volatile unsigned char*)(0x4D))
#define TCNT1L           *((volatile unsigned char*)(0x4C))
#define OCR1A           *((volatile unsigned short*)(0x4A))
#define OCR1AH          *((volatile unsigned char*)(0x4B))
#define OCR1AL          *((volatile unsigned char*)(0x4A))
#define ICR1            *((volatile unsigned short*)(0x46))
#define ICR1H           *((volatile unsigned char*)(0x47))
#define ICR1L           *((volatile unsigned char*)(0x46))

#endif /* TIMERS_REGISTERS_H_ */