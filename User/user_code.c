#include "user_code.h"

TaskHandle_t StartTask_Handler;     //任务句柄

/**
  * @brief  系统启动
  * @param  None
  * @retval None
  */
void OS_Start(void)
{
	//创建开始任务
	xTaskCreate((TaskFunction_t )start_task,            
							(const char*    )"start_task",          
							(uint16_t       )START_STK_SIZE,        
							(void*          )NULL,                  
							(UBaseType_t    )START_TASK_PRIO,       
							(TaskHandle_t*  )&StartTask_Handler);              
	vTaskStartScheduler();   
}

/**
  * @brief  开始任务，所有的任务创建
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

