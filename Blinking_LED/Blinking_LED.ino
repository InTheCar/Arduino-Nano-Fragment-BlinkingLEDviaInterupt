#include <TimerOne.h>
#define PIN_LED 13 // Build in LED
#define on 1 // for LEDstatus, on off blinking
#define off 0 // for LEDstatus, on off blinking
#define blinking 2 // for LEDstatus, on off blinking

volatile int LEDstatus = off;   // global variable also accessable from
                                // interrupt rutine led_handle()
                                // volatile is nessesary to be sure that the variable
                                // is loaded from the RAM and not from a storage register
void led_handle(void);
void setup() {
  pinMode(PIN_LED, OUTPUT); // initialise the pin for the LED as output
  Timer1.initialize(100000); // call every 0,1 the interrupt rutine
  Timer1.attachInterrupt(led_handle); // use led_handle as interrupt rutine
}
void loop() {
  delay(5000); //the delay is needed for demonstration
  LEDstatus = on;
  delay(5000); //the delay is needed for demonstration
  LEDstatus = blinking;
  delay(5000); //the delay is needed for demonstration
  LEDstatus = off;
}
void led_handle(void){
  if (LEDstatus == blinking){
    if (digitalRead(PIN_LED) == LOW) {
      digitalWrite(PIN_LED, HIGH);
    } else {
      digitalWrite(PIN_LED, LOW);
    }
  }
  else if (LEDstatus == off){
    if (digitalRead(PIN_LED) == HIGH) {
      digitalWrite(PIN_LED, LOW);
    }
  }
  else if (LEDstatus == on){
    if (digitalRead(PIN_LED) == LOW) {
      digitalWrite(PIN_LED, HIGH);
    }
  }
}
