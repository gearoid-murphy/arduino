// https://www.arduino.cc/en/Reference/PortManipulation
#define PIN8_ON PORTB |= 0x1
#define PIN8_OFF PORTB &= ~0x1
#define PIN13_ON PORTB |= 0x20
#define PIN13_OFF PORTB &= ~0x20
#define PIN3_ON PORTD |= 0x8
#define PIN3_OFF PORTD &= ~0x8

#define NOP __asm__ __volatile__ ("nop\n\tnop\n\tnop\n\tnop\n\tnop\n\t")


void setup() {
    pinMode(13, OUTPUT);
}

void loop()
{
    cli();
    const int long_cycle_count = 1000;
    const int small_cycle_count = long_cycle_count / 20;
    const int primary_cycle_count = 100;
    const int secondary_cycle_count = 5;
    for(int i=0; i<primary_cycle_count; i++) {
        PIN13_ON;
        for(int i=0; i<small_cycle_count; i++) {
          NOP;
        }
        PIN13_OFF;
        for(int i=0; i<long_cycle_count; i++) {
          NOP;
        }
    }

    for(int i=0; i<secondary_cycle_count; i++) {
        PIN13_ON;
        for(int i=0; i<long_cycle_count; i++) {
          NOP;
        }
        PIN13_OFF;
        for(int i=0; i<small_cycle_count; i++) {
          NOP;
        }
    }
}


