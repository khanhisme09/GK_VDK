#include <REGX52.H>

#define TIMER_PRESCALER 12  
#define DUTY_CYCLE_PERCENTAGE 30  

void delay(unsigned int count) {
    unsigned int i;
    for (i = 0; i < count; i++);
}

void main() {
    TMOD = 0x01;  
    
    while(1) {
        TH0 = 0xFF;   
        TL0 = 0xD8;   

        P2 |= (1 << 0);

        delay((DUTY_CYCLE_PERCENTAGE * TIMER_PRESCALER) / 100);

        P2 &= ~(1 << 0);
        delay(((100 - DUTY_CYCLE_PERCENTAGE) * TIMER_PRESCALER) / 100);
    }
}
