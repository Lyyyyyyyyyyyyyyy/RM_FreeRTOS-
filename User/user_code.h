#ifndef __USERCODE_H
#define __USERCODE_H 	

#include "user_common.h"

extern TaskHandle_t StartTask_Handler;     //任务句柄

#define START_TASK_PRIO		1         //任务优先级
#define START_STK_SIZE 		128       //任务堆栈大小	

void start_task(void *pvParameters);//任务函数
void OS_Start(void);
	
#endif /* __USERCODE_H */

