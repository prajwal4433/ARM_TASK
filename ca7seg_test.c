//common anode 7 segment display test
#include <LPC21xx.h>
#include "types.h"
#include "delay.h"

u8 ca_segLUT[10]=
{
0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90
};
#define CA_SEG 8 // a to dp @p0.8 to p0.15

main()
{
u32 i;
//cgg seg pins a to dp as gpio out
IODIR0 |=0XFF<<CA_SEG;	
while(1)
{
 for(i=0;i<=9;i++)
	{
  IOPIN0 = ((IOPIN0 & ~(0XFF<<CA_SEG))) | ((ca_segLUT[i]<<CA_SEG));
	delay_ms(100);
  }
}
}
