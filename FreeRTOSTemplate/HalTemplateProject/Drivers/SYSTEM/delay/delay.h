#ifndef __delay_H__
#define __delay_H__

//#include "MyApplication.h"
#include "stdint.h"


typedef struct
{
    uint32_t SystemCoreClock;   //ϵͳʱ��Ƶ��(M)
    void (*delay_us)(uint32_t nus);

}Delay_t;

// typedef struct{

//     void (*delay_init)(uint8_t SYSCLK); //SYSCLK:ϵͳʱ��Ƶ��168
//     void (*delay_us)(uint32_t nus);     //�޵�����ʱn_us
//     void (*delay_ms)(uint32_t nms);     //������ʱn_ms
//     void (*delay_xms)(uint32_t nms);     //�޵�����ʱn_ms

// }Delay_t;

extern Delay_t Delay;

#endif
