#ifndef __MyTask_H_
#define __MyTask_H_

//����ṹ������
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
