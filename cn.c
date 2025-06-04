#include <lpc21xx.h>
#include "delay.h"
#define led 0
int IsPower(int i);
main()
{
unsigned int i;
IODIR0 |=0XFF;
for(i=0; i<=255; i++)
{
if(IsPower(i))
{
IOPIN0=((IOPIN0&~(255<<led))|(i<<led));
delay_ms(100);
}
}
}
int IsPower(int num)
{
while(num>0)
{
if((num%2)==0)
num=num/2;
else
break;
}
if(num==1)
return 1;
else
return 0;
}