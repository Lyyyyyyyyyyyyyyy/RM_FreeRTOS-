#include "user_code.h"

TaskHandle_t StartTask_Handler;     //������

/**
  * @brief  ϵͳ����
  * @param  None
  * @retval None
  */
void OS_Start(void)
{
	//������ʼ����
	xTaskCreate((TaskFunction_t )start_task,            
							(const char*    )"start_task",          
							(uint16_t       )START_STK_SIZE,        
							(void*          )NULL,                  
							(UBaseType_t    )START_TASK_PRIO,       
							(TaskHandle_t*  )&StartTask_Handler);              
	vTaskStartScheduler();   
}

/**
  * @brief  ��ʼ�������е����񴴽�
  * @param  None
  * @retval None
  */
void start_task(void *pvParameters)
{
	taskENTER_CRITICAL();
							
	vTaskDelete(StartTask_Handler); 
	StartTask_Handler=NULL;
	taskEXIT_CRITICAL();
}

