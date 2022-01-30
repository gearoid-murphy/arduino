#include <avr/sleep.h>

#define PIN13_ON PORTB |= 0x20
#define PIN13_OFF PORTB &= ~0x20

#define NOP10 __asm__ __volatile__ ("nop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\t")

void setup() {
  pinMode(13, OUTPUT);
}

void loop()
{
  cli();
  while (1) {
    PIN13_ON;
    delayMicroseconds(20);
    PIN13_OFF;
    delayMicroseconds(20);
  }

  // sleep_enable();
  // sleep_cpu();
}

