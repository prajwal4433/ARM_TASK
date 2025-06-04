#include<lpc21xx.h>
#include "delay.h"
#include "types.h"
//#include "defines.h"
#define LED_8_AL 8
main()
{
u32 i;
	u8 pattern[4]={0x81,0x42,0x24,0x18};
	IODIR0 |=0XFF<<LED_8_AL;
	
	while(1)
	{ 
		IOPIN0=(IOPIN0&(0XFF<<LED_8_AL))|(u32)~(0x00);
   delay_ms(1000);
   for(i=0;i<4;i++)
   {	 	
	  IOPIN0=(IOPIN0&~(0XFF<<LED_8_AL))|~(pattern[i]);
		 delay_ms(100*(i+1));
	 }
  }
}
