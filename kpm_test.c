#include<lpc21xx.h>
#include"types.h"
#include"kpm_defines.h"
#include"lcd.h"
#include"delay.h"
#include"lcd_defines.h"
#include"kpm.h"
main()
{
	 u32 key;
   InitLCD();
	 Initkpm();
	StrLCD("4*4 kpm test");
	while(1)
	{
	  key=keyscan();
		CmdLCD(GOTO_LINE2_POS0);
		StrLCD("  ");
    CmdLCD(GOTO_LINE2_POS0);
    u32LCD(key);
		while(colscan()==0);
		// CmdLcD()
	}

}
