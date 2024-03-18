#include <REGX52.H>
unsigned char code Code7Seg[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};
#define led_port P0
sbit led1 = P2^0;
sbit led2 = P2^1;
sbit led3 = P2^2;
sbit led4 = P2^3;
int dv, chuc, tram, nghin;
int so=0000;

void delay_ms(unsigned int t){
	unsigned int x, y;
	for(x=0; x<t; x++){
		for(y=0; y<123; y++);
	}	
}

void show_led(unsigned int x){
	
	unsigned int temp;
	temp = x;
	dv = temp%10;
		temp = temp/10;
	chuc = temp%10;
		temp = temp/10;
	tram = temp%10;
		temp = temp/10;
	nghin = temp%10;
		temp = temp/10;
	
	led1 = 0;
	led2 = 0;
	led3 = 0;
	led4 = 0;
	
		led_port = Code7Seg[nghin];
		led1 = 0;
		delay_ms(1);
		led1 = 1;
		
		led_port = Code7Seg[tram];
		led2 = 0;
		delay_ms(1);
		led2 = 1;
		
		led_port = Code7Seg[chuc];
		led3 = 0;
		delay_ms(1);
		led3 = 1;
		
		led_port = Code7Seg[dv];
		led4 = 0;
		delay_ms(1);
		led4 = 1;
}


void main(){
	while(1){
		
		//tang
		if(P3_3==0){
		so++;
		while(P3_3==0);
		}
		//giam
		if(P3_7==0){
			if(so==0){
			so=9999;
			}
			else
			so--;
			while(P3_7==0);
		}
		show_led(so);
	}


}