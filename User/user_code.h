#ifndef __USERCODE_H
#define __USERCODE_H 	

#include "user_common.h"

extern TaskHandle_t StartTask_Handler;     //������

#define START_TASK_PRIO		1         //�������ȼ�
#define START_STK_SIZE 		128       //�����ջ��С	

void start_task(void *pvParameters);//������
void OS_Start(void);
	
#endif /* __USERCODE_H */

