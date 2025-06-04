#include<lpc21xx.h>
#include "delay.h"
#include "types.h"
#include<stdlib.h>

#define LED_8_AL 8 //@p0.4 to p0.11
u32 seed=0;
main()
{
   u32 face_val;
	
	
	//cfg p0.4 to p0.11 as gpio out pins
	
	IODIR0 |= 0XFF<<LED_8_AL;
	
	while(1)
	{
	   face_val=(rand()%6)+1;
		IOPIN0 =((IOPIN0&~(0XFF<<LED_8_AL))| (~face_val<<LED_8_AL));
		delay_ms(1000);
		srand(seed++);
	}

}
