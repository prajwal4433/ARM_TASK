#include<lpc21xx.h>
#include"types.h"
#include"lcd_defines.h"
#include"lcd.h"

void delay_ms(u32);
int main()
{
	s32 i;

  InitLCD();
	while(1)
	{
		for(i=0;i<=16;i++)
		{
			CmdLCD(GOTO_LINE1_POS0+i);
			StrLCD("vector");
			delay_ms(100);
	    CmdLCD(CLRLCD);
		}
    for(i=15;i>=0;i--)
    {
       CmdLCD(GOTO_LINE1_POS0+i);
			 StrLCD("vector");
			 delay_ms(100);
			 CmdLCD(CLRLCD);
    }		
	}
}
