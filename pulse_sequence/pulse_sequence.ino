// https://www.arduino.cc/en/Reference/PortManipulation
#define PIN8_ON PORTB |= 0x1
#define PIN8_OFF PORTB &= ~0x1
#define PIN13_ON PORTB |= 0x20
#define PIN13_OFF PORTB &= ~0x20
#define PIN3_ON PORTD |= 0x8
#define PIN3_OFF PORTD &= ~0x8

#define NOP __asm__ __volatile__ ("nop\n\tnop\n\tnop\n\tnop\n\tnop\n\t")

#define SLEEP(T) { for(int i=0; i<T; i++) { NOP; } }
#define PAUSE(T) { PIN13_OFF; SLEEP(T); }
#define PULSE(T) { PIN13_ON; SLEEP(T); }
#define PULSE_SEQUENCE(P, T) { for(int i=0; i<P; i++) { PULSE(T); PAUSE(T); } }

void setup() {
    pinMode(13, OUTPUT);
}

void loop()
{
    cli();
    while(true) {
      PULSE_SEQUENCE(5, 50);
      // PAUSE(2500);
    }
}


