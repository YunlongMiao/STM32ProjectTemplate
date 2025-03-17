#ifndef __MyTask_H_
#define __MyTask_H_

//定义结构体类型
typedef struct
{
	void (*AppTaskCreate)(void);
} MyTask_t;

/* extern variables-----------------------------------------------------------*/
extern MyTask_t  MyTask;
#endif
/********************************************************
  End Of File
********************************************************/
