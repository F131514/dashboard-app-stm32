#include "display_fft.h"



long lBufInArray[NPT];
long lBufOutArray[NPT/2];
long lBufMagArray[NPT/2];

uint8_t prt = 3;	//������ʾ�ı���

uint32_t adc_buf[NPT]={0};  
uint8_t fall_pot[128];	//��¼����������
uint8 fft_num = 1;
uint8 fft_auto_flag = 0;

/*��״��ʾ*/
void display_fft_1(void)
{
	uint16_t i = 0;
	uint8_t x = 0;
	uint8_t y = 0;
	
	/*******************��ʾ*******************/
	OLED_Only_Clear();
	for(i = 0; i < 32; i++)	//�����ȡ32��Ƶ�ʳ�����ʾ
	{
		x = (i<<2);	//i*4
		y = 63-(lBufMagArray[x+1]/prt)-2;	//��1��Ϊ�˶�����һ��ֱ������
		if(y>63) y = 63;
		
		GUI_LineWith(x,y,x,63,3,1);
		
		//������ĵ�
		if(fall_pot[i]>y) fall_pot[i] = y;
		else
		{
				if(fall_pot[i]>63) fall_pot[i]=63;
				GUI_LineWith(x,fall_pot[i],x,fall_pot[i]+3,3,1);
				fall_pot[i] += 2 ;
		}
	}
	OLED_Refresh();
}
/*����״��ʾ*/
void display_fft_2(void)
{
	uint16_t i = 0;
	uint8_t y = 0;
	
	/*******************��ʾ*******************/
	OLED_Only_Clear();
	for(i = 1; i < 128; i++)	
	{
		y = 63-(lBufMagArray[i]/prt)-2;
		if(y>63) y = 63;
		
		GUI_RLine(i,y,63,1);		
		//������ĵ�
		if(fall_pot[i]>y) fall_pot[i] = y;
		else
		{
				if(fall_pot[i]>63) fall_pot[i]=63;
				GUI_RLine(i,fall_pot[i],fall_pot[i]+1,1);
				fall_pot[i] += 2 ;
		}
	}
	OLED_Refresh();
}
/*������ʾ �м�Գ�*/
void display_fft_3(void)
{
	uint16_t i = 0;
	uint8_t y = 0;
	
	/*******************��ʾ*******************/
	OLED_Only_Clear();
	for(i = 0; i < 127; i++)	
	{
		y = 31-(lBufMagArray[i+1]/prt)-2;	//��1��Ϊ�˶�����һ��ֱ������
		if(y>31) y = 31;
		
		GUI_RLine(i,32,y,1);
		GUI_RLine(i,32,63-y,1);
		
		//������ĵ�
		if(fall_pot[i]>y) fall_pot[i] = y;
		else
		{
				if(fall_pot[i]>30) fall_pot[i]=30;
				GUI_RLine(i,fall_pot[i],fall_pot[i]+1,1);
				GUI_RLine(i,63-fall_pot[i],63-(fall_pot[i]+1),1);
				fall_pot[i] += 2 ;
		}
	}
	OLED_Refresh();
}
/*��״״��ʾ �м�Գ�*/
void display_fft_4(void)
{
	uint16_t i = 0;
	uint8_t x = 0;
	uint8_t y = 0;
	
	/*******************��ʾ*******************/
	OLED_Only_Clear();
	for(i = 0; i < 32; i++)	//�����ȡ32��Ƶ�ʳ�����ʾ
	{
		x = (i<<2);	//i*4
		y = 31-(lBufMagArray[x+1]/prt)-2;	//��1��Ϊ�˶�����һ��ֱ������
		if(y>31) y = 31;
		
		GUI_LineWith(x,y,x,32,3,1);
		GUI_LineWith(x,63-y,x,32,3,1);
		
		//������ĵ�
		if(fall_pot[i]>y) fall_pot[i] = y;
		else
		{
				if(fall_pot[i]>31) fall_pot[i]=31;
				GUI_LineWith(x,fall_pot[i],x,fall_pot[i]+3,3,1);
				GUI_LineWith(x,63 - fall_pot[i],x,63 - fall_pot[i]-3,3,1);
				fall_pot[i] += 2 ;
		}
	}
	OLED_Refresh();
}


//��ȡFFT���ֱ������
void GetPowerMag(void)
{
    signed short lX,lY;
    float X,Y,Mag;
    unsigned short i;
    for(i=0; i<NPT/2; i++)
    {
        lX  = (lBufOutArray[i] << 16) >> 16;
        lY  = (lBufOutArray[i] >> 16);
			
				//����32768�ٳ�65536��Ϊ�˷��ϸ������������
        X = NPT * ((float)lX) / 32768;
        Y = NPT * ((float)lY) / 32768;
        Mag = sqrt(X * X + Y * Y)*1.0/ NPT;
        if(i == 0)	
            lBufMagArray[i] = (unsigned long)(Mag * 32768);
        else
            lBufMagArray[i] = (unsigned long)(Mag * 65536);
    }
}







