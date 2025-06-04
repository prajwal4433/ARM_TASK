#include<lpc21xx.h>
#include"types.h"
#include"lcd.h"
#include"lcd_defines.h"
#include"delay.h"


main()
{
	u32 i;
InitLCD();
	for(i=0;i<26;i++)
	{
	CharLCD('A'+i);
		CharLCD(' ');
		u32LCD('A'+i);
		CharLCD(' ');
		hexLCD('A'+i);
	  delay_ms(500);
		CmdLCD(CLRLCD);
	}
	while(1);
	
}
