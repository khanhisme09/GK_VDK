#include <REGX52.H>

#define TIMER_PRESCALER 12  
#define DUTY_CYCLE_PERCENTAGE 50  


void delay(unsigned int count) {
    unsigned int i;
    for (i = 0; i < count; i++);
}

void main() {
    TMOD = 0x01;  
    
    while(1) {
        TH0 = 0xFE;   
        TL0 = 0x0C;   

        P1 |= (1 << 7);

        delay((DUTY_CYCLE_PERCENTAGE * TIMER_PRESCALER) / 100);

        P1 &= ~(1 << 7);
        delay(((100 - DUTY_CYCLE_PERCENTAGE) * TIMER_PRESCALER) / 100);
    }
}
