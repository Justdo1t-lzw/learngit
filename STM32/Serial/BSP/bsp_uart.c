/*
 * bsp_uart.c
 *
 *  Created on: Mar 4, 2022
 *      Author: Administrator
 */

#include "bsp_uart.h"
#include "bsp.h"

#define ENABLE_UART_DMA    1

uint8_t RxTemp = 0;
uint8_t TestTemp = 0;
uint8_t RxBuffer[8];


// Initialize USART1  初始化串口1
void USART1_Init(void)
{
//    HAL_UART_Receive_IT(&huart1, (uint8_t *)&RxTemp, 1);
	HAL_UART_Receive_IT(&huart1, (uint8_t *)&RxBuffer, 8);
}

// The serial port sends one byte  串口发送一个字节
void USART1_Send_U8(uint8_t ch)
{
    HAL_UART_Transmit(&huart1, (uint8_t *)&ch, 1, 0xFFFF);
}

// The serial port sends a string of data  串口发送一串数据
void USART1_Send_ArrayU8(uint8_t *BufferPtr, uint16_t Length)
{
    #if ENABLE_UART_DMA
    HAL_UART_Transmit_DMA(&huart1, BufferPtr, Length);
    #else
    while (Length--)
    {
        USART1_Send_U8(*BufferPtr);
        BufferPtr++;
    }
    #endif
}

// The serial port receiving is interrupted. Procedure  串口接收完成中断
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    /* Prevent unused argument(s) compilation warning */
    UNUSED(huart);
    /* NOTE : This function should not be modified, when the callback is needed,
              the HAL_UART_RxCpltCallback can be implemented in the user file
     */
    // 测试发送数据，实际应用中不应该在中断中发送数据
    // Test sending data. In practice, data should not be sent during interrupts  
//    USART1_Send_U8(RxTemp);
//    printf("receive:%d\n", TestTemp);
    uint8_t fun = RxBuffer[3];
    if(fun == 0x03){
    	uint8_t servoID = RxBuffer[4];
		uint8_t angle = RxBuffer[5];
		PwmServo_Set_Angle(servoID - 1, angle);
    }

//    if(fun == 0x11){
//		uint8_t carStatus = RxBuffer[5];
//		uint8_t carSpeed = RxBuffer[6];
//		uint16_t speed = (uint16_t)carSpeed * 10;
//	//    USART1_Send_U8(carStatus);
//	//    USART1_Send_U8(carSpeed);
//
//	//    carSpeed = 250;
//	//    int speed = 0;
//		switch(carStatus)
//		{
//			case 0x00: // 停车
//				// 调用停车函数
//				Motion_Ctrl(0, 0, 0);
//	//			Motor_Stop(0);
//				break;
//			case 0x01: // 前进
//	//			USART1_Send_U8(carStatus);
//				// 调用前进函数
//				Motion_Ctrl(speed, 0, 0);
//	//			speed = 2000;
//	//			Motor_Set_Pwm(MOTOR_ID_M1, speed);
//	//			Motor_Set_Pwm(MOTOR_ID_M2, speed);
//	//			Motor_Set_Pwm(MOTOR_ID_M3, speed);
//	//			Motor_Set_Pwm(MOTOR_ID_M4, speed);
//				break;
//			case 0x02: // 后退
//				// 调用后退函数
//				Motion_Ctrl(-speed, 0, 0);
//	//			speed = -2000;
//	//			Motor_Set_Pwm(MOTOR_ID_M1, speed);
//	//			Motor_Set_Pwm(MOTOR_ID_M2, speed);
//	//			Motor_Set_Pwm(MOTOR_ID_M3, speed);
//	//			Motor_Set_Pwm(MOTOR_ID_M4, speed);
//				break;
//			case 0x05: // 左旋转
//	//			USART1_Send_U8(carSpeed);
//				// 调用左旋转函数
//				Motion_Ctrl(0, 0, speed);
//				break;
//			case 0x06: // 右旋转
//				// 调用右旋转函数
//				Motion_Ctrl(0, 0, -speed);
//				break;
//			default:
//				// 其他情况，不做处理
//				Motion_Ctrl(0, 0, 0);
//				break;
//		}
//    }
    // Continue receiving data  继续接收数据
//    HAL_UART_Receive_IT(&huart1, (uint8_t *)&RxTemp, 1);
    HAL_UART_Receive_IT(&huart1, (uint8_t *)&RxBuffer, 8);
}



#ifdef __GNUC__
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif /* __GNUC__ */
PUTCHAR_PROTOTYPE
{
    /* Place your implementation of fputc here */
    /* e.g. write a character to the EVAL_COM1 and Loop until the end of transmission */
    HAL_UART_Transmit(&huart1, (uint8_t *)&ch, 1, 0xFFFF);
    return ch;
}
