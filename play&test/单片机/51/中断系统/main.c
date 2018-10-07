#include<reg52.h>

#define uint unsigned int 
#define uchar unsigned char 

sbit wela = P2^7;
sbit dula = P2^6;
sbit d1=P1^0;

uchar num;
uchar code table[]={
0x3f,0x06,0x5b,0x4f,
0x66,0x6d,0x7d,0x07,
0x7f,0x6f,0x77,0x7c,
0x39,0x5e,0x79,0x71};

void delay(uint xms);

void main()
{
	EA=1;
	EX0=1;
	IT0=0;
	wela=1;
	P0=0;
	wela=0;
	while(1)
	{
		for(num=0;num<16;num++)
		{	d1=1;
			dula=1;
			P0=table[num];
			dula=0;
			delay(1000);
		}
	}
}
void exter0() interrupt 0
{
	d1=0;
}
void delay(uint xms)
{
	uint i,j;
	for(i=xms;i>0;i--)
		for (j=110;j>0;j--);
} 