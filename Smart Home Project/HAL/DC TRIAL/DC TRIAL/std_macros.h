//GUARDING LINE
#ifndef std_macros_H_
#define std_macros_h_
//zaghloul didn't include this external brackets but i thought so
//bit operations macro_functions
#define SET_BIT(reg,bit)	(reg|=(1<<bit)) 
#define CLR_BIT(reg,bit)	(reg&=~(1<<bit))
#define TOG_BIT(reg,bit)	(reg^=(1<<bit))
#define READ_BIT(reg,bit)	((reg&(1<<bit))>>bit)
#define IS_BIT_SET(reg,bit)	((reg&(1<<bit))>>bit)
#define IS_BIT_CLR(reg,bit) (!((reg&(1<<bit))>>bit))
//port opertions macro_functions
#define REG_SIZE 8
#define ROR(reg,num) 	(reg=(reg<<(REG_SIZE-num))/*to rotate the discarded bits*/|(reg>>num))
#define ROL(reg,num) 	(reg=(reg>>(REG_SIZE-num))/*to rotate the discarded bits*/|(reg<<num))
#define SET_PORT(reg)	(reg=0XFF)
#define CLR_PORT(reg)	(reg=0X00)
#define TOG_PORT(reg)	(reg=~reg)


#endif
