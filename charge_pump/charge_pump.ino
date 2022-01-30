    #define PIN3_ON PORTD |= 0x8
    #define PIN3_OFF PORTD &= ~0x8
    #define NOP __asm__ __volatile__ ("nop\n\tnop\n\tnop\n\tnop\n\tnop\n\t")

    // http://www.stephenhobley.com/blog/2011/03/28/
    // creating-a-negative-voltage-from-a-positive-one/

    void setup() {
        pinMode(3, OUTPUT);
    }

    void loop()
    {
        cli();
        while (1) {
            PIN3_ON;
            NOP;
            NOP;
            PIN3_OFF;
            NOP;
            NOP;
        }
    }

