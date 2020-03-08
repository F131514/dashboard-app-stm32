#ifndef __DISPLAY_MENU_H
#define __DISPLAY_MENU_H

#include "stm32f1xx_hal.h"
#include "oled.h"

typedef struct STRUCT_PC_DATA{
	u8 CPU_NAME[20];								//CPU�ͺ�
	u8 CPU_NMAE_LEN;								//CPU�ͺ������ж೤
	u8 GPU_NAME[20];								//GPU�ͺ�
	u8 GPU_NAME_LEN;								//GPU�ͺ������ж೤
	
	u8 MINUTE;											//��ǰ������ 0~59
	u8 HOUR;                        //��ǰ����  0~23
	u8 DAY;													//��ǰ����   1~31
	u8 WEEK_NUM;										//���ڼ�      1~7
	u8 MONTH_NUM;										//�·�				1~12
	u32 YEAR;												//���  0~9999
	
	
	u32 RAM_ALL;										//���ڴ�   0~99
	u32 RAM_USED_INTEGR;						//�Ѿ�ʹ���ڴ����������  0~99
	u32 RAM_USED_FRACTION;					//�Ѿ�ʹ���ڴ��С������  0~9
	u32 RAM_RATE;
	
	u32 VIDEO_MEMORY_ALL;						//���Դ�    0~99
	u32 VIDEO_MEMORY_INTEGR;				//�Ѿ�ʹ���Դ����������	0~99
	u32 VIDEO_MEMORY_FRACTION;			//�Ѿ�ʹ���Դ��С������	0~9
	u32 VIDEO_MEMORY_RATE;
	
	u32 CPU_FREQUENCY;							//CPUƵ��					0~9999
	u32 CPU_OCCUP_RATE;             //CPUռ����				0~99
	u32 CPU_TEMPERATURE;						//CPU�¶�					0~255
	
	u32 GPU_FREQUENCY;							//GPUƵ��				0~9999
	u32 GPU_OCCUP_RATE;             //GPUռ����			0~99
	u32 GPU_TEMPERATURE;						//GPU�¶�				0~255
	
	u32 SPEED_UP;           				//�ϴ�����			0~~999M
	u32 SPEED_DOWN; 								//��������			0~~999M
	
		
}PC_DATA;



void display_menu1(void);
void display_menu2(void);
void display_menu3(void);
void display_menu4_1(void);
void display_menu4_2(void);
void display_menu5(void);
void Init_PC_Data(void);
#endif

