#include <reg52.h>

sbit BY1=P3^4;       //���尴���������S2��
unsigned char count; //��������,ÿ��һ��,count��1
unsigned char temp;
unsigned char a,b;

void delay10ms(void) //��ʱ����
{
	unsigned char i,j;
	for(i=20;i>0;i--)
	for(j=248;j>0;j--);
}
key()           //�����жϳ���
{
	if(BY1==0)  //�ж��Ƿ��¼���
	{
	  delay10ms(); //��ʱ,���ȥ����
	  if(BY1==0)   //ȷ�ϰ�������
	   {
	   count++;     //����������1
	   if(count==8) //��8�����¼���
	   {
        count=0;    //��count����
	   }
	 }
	while(BY1==0);//��������,ÿ��һ��countֻ��1.
	}
}
 move()         //���������ƶ��ƶ�����
{
	a=temp<<count;
	b=temp>>(8-count);
	P1=a|b;
}

main()
{
 count=0;  //��ʼ����������
 temp=0xfe;
 P1=0xff;
 P1=temp;
 while(1)  //��Զѭ��,ɨ���жϰ����Ƿ���
 {
   key();    //���ð���ʶ����
   move();   //���ù����ƶ�����
 }
}



