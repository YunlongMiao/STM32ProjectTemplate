#ifndef __DELAY_H
#define __DELAY_H 			   
#include <sys.h>	  

//********************************************************************************
//修改说明
//无
////////////////////////////////////////////////////////////////////////////////// 	 
void delay_init(u8 SYSCLK);
void delay_ms(u16 nms);
void delay_us(u32 nus);

#endif





























