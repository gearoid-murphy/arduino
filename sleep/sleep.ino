#include <avr/sleep.h>
// https://www.nongnu.org/avr-libc/user-manual/group__avr__sleep.html

void setup() {}

void loop()
{
  cli();
  sleep_enable();
  sleep_cpu();
}

