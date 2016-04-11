#include <reg52.h>

sbit BY1=P3^4;       //定义按键的输入端S2键
unsigned char count; //按键计数,每按一下,count加1
unsigned char temp;
unsigned char a,b;

void delay10ms(void) //延时程序
{
	unsigned char i,j;
	for(i=20;i>0;i--)
	for(j=248;j>0;j--);
}
key()           //按键判断程序
{
	if(BY1==0)  //判断是否按下键盘
	{
	  delay10ms(); //延时,软件去干扰
	  if(BY1==0)   //确认按键按下
	   {
	   count++;     //按键计数加1
	   if(count==8) //计8次重新计数
	   {
        count=0;    //将count清零
	   }
	 }
	while(BY1==0);//按键锁定,每按一次count只加1.
	}
}
 move()         //广告灯向左移动移动函数
{
	a=temp<<count;
	b=temp>>(8-count);
	P1=a|b;
}

main()
{
 count=0;  //初始华参数设置
 temp=0xfe;
 P1=0xff;
 P1=temp;
 while(1)  //永远循环,扫描判断按键是否按下
 {
   key();    //调用按键识别函数
   move();   //调用广告灯移动函数
 }
}



