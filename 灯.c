#include<reg52.h>
#include<intrins.h>
void delayms(int);
void main()
{
    char aa;
	aa=0xFe;
	while(1)
	{
		P1=aa;
		delayms(500);
		aa=_crol_(aa,1);
	}
}
void delayms(int xms)
{
	int i,j;
	for(i=xms;i>0;i--)
	for(j=110;j>0;j--);
}
