#include "types.h"
#include "delay.h"
#include <LPC21xx.h>
#include "lcd_defines.h"
void WriteLCD(u8 Dat)
{
	IOPIN0=((IOPIN0&~(0xFF<<LCD_DATA))|(Dat<<LCD_DATA));  //write on data pins 
	IOCLR0=1<<LCD_RW;  //activate write operation
	IOSET0=1<<LCD_EN;  //latch into cmd/data register
	delay_us(1);
	IOCLR0=1<<LCD_EN;  //internal oiperation upper bound time
	delay_ms(2);
}
void CmdLCD(u8 cmd)
{
	IOCLR0=1<<LCD_RS;  //select cmd reg
	WriteLCD(cmd);  //write to cmd reg	
}
void CharLCD(u8 ascii)
{
	IOSET0=1<<LCD_RS;  //select data reg
	WriteLCD(ascii);  //write to DDRAM/Display via data reg	
}
void InitLCD(void)
{
	IODIR0|=0xFF<<LCD_DATA|1<<LCD_RS|1<<LCD_RW|1<<LCD_EN;
	//Implement Initialization Algorithm
	delay_ms(15);
	CmdLCD(0x30);
	delay_ms(2);
	delay_us(100);
	CmdLCD(0x30);
	delay_us(100);
	CmdLCD(0x30);
	CmdLCD(MODE_8BIT_2LINE);
	CmdLCD(DISP_ON_CUR_BLK);
	CmdLCD(CLRLCD);
	CmdLCD(SFT_DISP_RGT);
}
void StrLCD(s8 *str)
{
	while(*str)
	CharLCD(*str++);
}
void u32LCD(u32 num)
{
	s8 a[10];
	s32 i=0;
	if(num==0)
		CharLCD('0');
	else
	{
		while(num>0)
		{
		a[i]=(num%10)+48;
		i++;
		num/=10;
		}
		for(--i;i>=0;i--)
		{
		CharLCD(a[i]);
		}
	}
}

void S32LCD (s32 num)
{
	if(num<0)
	{
		CharLCD('-');
		num=-num;
	}
	u32LCD(num);
}	
void F32LCD(f32 fnum,u32 nDP)
{
	u32 num,i;
	if(fnum<0.0)
	{
		CharLCD('-');
		fnum=-fnum;
	}
	num=fnum;
	u32LCD(num);
//	CharLCD('.');
	for(i=0;i<nDP;i++)
	{
		fnum=(fnum-num)*10;
		num=fnum;
		CharLCD(num+48);
	}
}
void hexLCD(u32 num)
{
	s8 a[8],t;
	s32 i=0;
	if(num==0)
	CharLCD('0');
	else
	{	
		while(num>0)
		{
			t=(num%16);
			t=(t>9)?('A'+(t-10)):(t+48);
			a[i]=t;
			i++;
			num/=16;
		}
		for(--i;i>=0;i--)
		CharLCD(a[i]);
	}
}
void OctLCD(u32 num)
{
	s8 a[11];
	s32 i=0;
	if(num==0)
		CharLCD('0');
	else
	{
		while(num>0)
		{
			a[i]=(num%8)+48;
			i++;
			num/=8;
	 	}
		for(--i;i>=0;i--)
			CharLCD(a[i]);
	}
}
void BinLCD(u32 num,u32 nBD)
{
	s32 i;
	for(i=(nBD-1);i>=0;i--)
		CharLCD(((num>>i)&1)+48);
}
void BuildCGRAM(u8 *p,u8 nBytes)
{
	u32 i;
	//position cursor to cgram start
	CmdLCD(CGRAM_START_ADDR);
	//write into cgram via data register
	for(i=0;i<nBytes;i++)
	{
		CharLCD(p[i]);
	}
	CmdLCD(GOTO_LINE1_POS0);
}
