/*2. Write a program to display the message “VECTOR” on the first Line and “Institute”
on the second line of a 2x16 LCD. Then make “Institute” flash at the rate of 1sec for 5
times, then clear the LCD screen*/

#include<lpc21xx.h>
#include"delay.h"
#include"types.h"
#define CLEAR_LCD 0X01
#define MODE_8BIT_2LINE 0x38
#define GOTO_LINE1_POS0 0X80
#define GOTO_LINE2_POS0 0XC0
#define GOTO_CGRAM_START 0X40
#define DSP_ON_CUR_BLK   0x0f
#define SHIFT_CUR_RIGHT  0x06
#define LCD_DATA 8
#define LCD_RS 16
#define LCD_RW 17
#define LCD_EN 18
void WriteLCD(u8 Data)
{
 //write on data pin
	IOPIN0 =(IOPIN0&~(0XFF<<LCD_DATA))|(Data<<LCD_DATA);
	//Activate write operation
	IOCLR0=1<<LCD_RW;
	//LATCH INTO CMD 1DATA REGISTER
	IOSET0=1<<LCD_EN;
	delay_us(1);
	IOCLR0=1<<LCD_EN;
	//INTERNAL OPERATION UPPER BOUND TIME
  delay_ms(2);
}


void CmdLCD(u8 Cmd)
{
   //select cmd reg
	IOCLR0 = 1<<LCD_RS;
	//WRITE TO CMD REG
	WriteLCD(Cmd);
}
void CharLCD(u8 ascii)
{
  //select data reg
	IOSET0=1<<LCD_RS;
	//wrte to DDRAM/display via data reg
	WriteLCD(ascii);
}
void StrLCD( s8 *str)
{
  while(*str)
		CharLCD(*str++);
}

void InitLCD(void)
{
IODIR0 |=0XFF<<LCD_DATA |1<<LCD_RS|1<<LCD_RW|1<<LCD_EN;
	delay_ms(15);
	CmdLCD(0x30);
	delay_ms(2);
	delay_us(100);
	CmdLCD(0x30);
	delay_us(100);
	CmdLCD(0x30);
	CmdLCD(MODE_8BIT_2LINE);
	CmdLCD(DSP_ON_CUR_BLK);
	CmdLCD(CLEAR_LCD);
	CmdLCD(SHIFT_CUR_RIGHT);

}
main()
{  
	u8 i;
   InitLCD();
	StrLCD("vector");
	for(i=0;i<5;i++)
	{
	  CmdLCD(GOTO_LINE2_POS0);
	  StrLCD("institute");
		delay_ms(100);
	  CmdLCD(GOTO_LINE2_POS0);
    StrLCD("                ");
		
	}
		  CmdLCD(CLEAR_LCD);
	while(1);
}
