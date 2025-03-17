#ifndef __delay_H__
#define __delay_H__

#include "MyApplication.h"


typedef struct
{
    uint32_t SystemCoreClock;   //系统时钟频率(M)
    void (*delay_us)(uint32_t nus);

}Delay_t;

// typedef struct{

//     void (*delay_init)(uint8_t SYSCLK); //SYSCLK:系统时钟频率168
//     void (*delay_us)(uint32_t nus);     //无调度延时n_us
//     void (*delay_ms)(uint32_t nms);     //调度延时n_ms
//     void (*delay_xms)(uint32_t nms);     //无调度延时n_ms

// }Delay_t;

extern Delay_t Delay;

#endif
