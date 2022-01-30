// https://programmingelectronics.com/an-easy-way-to-make-noise-with-arduino-using-tone/
// Specify digital pin on the Arduino that the positive lead of piezo buzzer is attached.
int piezoPin = 8;

void setup() {}


void loop() {

  // Tone needs 2 arguments, but can take three
  //   1) Pin#
  //   2) Frequency - this is in hertz (cycles per second) which determines the pitch of the noise made
  //   3) Duration - how long teh tone plays

  tone(piezoPin, 900, 500);

  //tone(piezoPin, 1000, 500);
  //delay(1000);

}
