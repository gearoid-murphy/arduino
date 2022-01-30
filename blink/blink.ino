const int led_pin =  13;

int led_state = LOW;

long interval = 1000;

void setup() {
    pinMode(led_pin, OUTPUT);
}

void loop()
{
    while(true)
    {
        digitalWrite(led_pin, HIGH);
        delay(100);
        digitalWrite(led_pin, LOW);
        delay(100);
    }
}

