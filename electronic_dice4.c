#include<lpc21xx.h>
#include"lcd.h"
#include"lcd_defines.h"
#include"delay.h"
#include"types.h"
#include<stdlib.h>

#define ROLL_SW 16

main()
{
	
u32 faceval=0,seed=1;
	InitLCD();
	StrLCD("Electronic Dice");
  while(1)
	{
	    CmdLCD(GOTO_LINE2_POS0);
		  u32LCD(faceval);
		if(((IOPIN1>>ROLL_SW)&1)==0)
		{
		  faceval=(rand()%6);
		  srand(++seed);
			delay_ms(10);
		}
	
	}
}
