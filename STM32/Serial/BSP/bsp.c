#include "bsp.h"

// LED显示当前运行状态，每10毫秒调用一次，LED灯每200毫秒闪烁一次。
// The LED displays the current operating status, which is invoked every 10 milliseconds, and the LED blinks every 200 milliseconds.  
void Bsp_Led_Show_State_Handle(void)
{
	static uint8_t led_count = 0;
	led_count++;
	if (led_count > 20)
	{
		led_count = 0;
		LED_TOGGLE();
	}
}


// The peripheral device is initialized  外设设备初始化
void Bsp_Init(void)
{

	USART1_Init();
	Motor_Init();
	Encoder_Init();
	PID_Param_Init();
	PwmServo_Init();
//	uint8_t res = 0;
//	res = MPU9250_Init();
//	if (res != 0)
//	{
//		printf("MPU9250 INIT ERROR\n");
//		while(1);
//	}
	Beep_On_Time(50);
}

//int encoder[4] = {0};
//int show_encoder = 0;
int car_state = 0;
// main.c中循环调用此函数，避免多次修改main.c文件。
// This function is called in a loop in main.c to avoid multiple modifications to the main.c file
void Bsp_Loop(void)
{
	Motion_Handle();
	//MPU9250_Read_Data_Handle();
	if (Key1_State(1))
	{

		Beep_On_Time(50);
		if (car_state == 0)
		{
			//Motion_Ctrl(0, 0, 500);
			//PwmServo_Set_Angle(0,50);
			PwmServo_Set_Angle_All(50, 50, 50, 50);
			car_state = 1;

		}
		else
		{
			//Motion_Stop(STOP_BRAKE);
			//PwmServo_Set_Angle(0,100);
			PwmServo_Set_Angle_All(150, 150, 150, 150);
			car_state = 0;
		}
	}

//	show_encoder++;
//	if(show_encoder > 10) {
//		show_encoder = 0;
//		Encoder_Get_ALL(encoder);
//		printf("Encoder:%d. %d, %d, %d\n", encoder[0], encoder[1], encoder[2], encoder[3]);
//	}

	Bsp_Led_Show_State_Handle();
	// The buzzer automatically shuts down when times out   蜂鸣器超时自动关闭
	Beep_Timeout_Close_Handle();
	HAL_Delay(10);
}
