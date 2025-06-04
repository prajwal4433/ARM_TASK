#include<lpc21xx.h>
#include"delay.h"
#include"lcd_defines.h"

#define LCD_DATA 8
#define LCD_RS   16
#define LCD_RW   17
#define LCD_EN   18

void writeLCD(u8 Dat)
{
IOPIN0=(IOPIN0&~(0XFF<<LCD_DATA))|(Dat<<LCD_DATA);
IOCLR0=1<<LCD_RW;
	IOSET0=1<<LCD_EN;
	delay_us(1);
	IOCLR0=1<<LCD_EN;
	delay_ms(2);
}

void cmdLCD(u8 cmd)
{
  IOCLR0=1<<LCD_RS;
	writeLCD(cmd);
}

void InitLCD(void)
{
	
	IODIR0 |= 0XFF<<LCD_DATA|1<<LCD_RS|1<<LCD_RW|1<<LCD_EN;
	delay_ms(15);
	cmdLCD(0x30);
	delay_ms(2);
	delay_us(100);
	cmdLCD(0x30);
	delay_us(100);
	cmdLCD(MODE_8BIT_2LINE);
	cmdLCD(DISP_ON_CUR_BLK);
	cmdLCD(CLRLCD);
	cmdLCD(SFT_DISP_RGT);
	
}

void charLCD(u8 ascii)
{
  IOSET0=1<<LCD_RS;
	writeLCD(ascii);
}

main()
{
  InitLCD();
	charLCD('1');
	//delay_s(1);
//	charLCD('a');
	cmdLCD(GOTO_LINE2_POS0);
	charLCD('B');
	delay_s(1);
}
