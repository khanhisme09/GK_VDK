#include <REGX51.H>

void Timer0() interrupt 1{
	
	TH0 = 0xFB;
	TL0 = 0xDC;
	
	P1 = 0x80;
}
	
void main(void){
	
	TMOD = 0x01;
	
	TH0 = 0xFB;
	TL0 =0xDC;
	
	ET0 = 1;
	EA = 1;
	
	TR0 = 1;
	while(1){}
	
}