#include<lpc21xx.h>
#include"delay.h"
#include"types.h"
#include"kpm_defines.h"
#include"kpm.h"

u32 kpmLUT[4][4]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};

void Initkpm(void)
{
IODIR1 |= 15<<ROW0;
}


u32 colscan(void)
{
	return (((IOPIN1>>COL0)&15)<15)?0:1;
}

u32 rowcheck(void)
{
u32 r;
	for(r=0;r<=3;r++)
	{
			IOPIN1=((IOPIN1&~(15<<ROW0))|((~(1<<r))<<ROW0));
		if(colscan()==0)
		{
		 break;
		}
	}
	IOCLR1=15<<ROW0;
	return r;
}

u32 colcheck(void)
{
 u32 c;
	for(c=0;c<=3;c++)
	{
	if((IOPIN1>>(COL0+c)&1)==0)
	{
	break;
	}
	}
	return c;
}

u32 keyscan(void)
{
	u32 r,c,keyv;
   while(colscan());
	r=rowcheck();
	c=colcheck();
	keyv=kpmLUT[r][c];
	return keyv;
	
}
