
#include <lpc21xx.h>
#include "lcd.h"
#include "lcd_defines.h"
#include "delay.h"

main()
{
 InitLCD();
 charLCD('A');
	delay_s(1);
 charLCD(' ');
 strLCD("mahesh");
 charLCD(' ');
 u32LCD(23);
 charLCD(' ');
 cmdLCD(GOTO_LINE2_POS0);
 s32LCD(-12456);
 charLCD(' ');
 f32LCD(123.456,3);//while(1);
}

