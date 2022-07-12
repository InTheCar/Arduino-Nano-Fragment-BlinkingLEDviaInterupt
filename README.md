# Arduino-Nano-Fragment-Blinking-LED via Interrupt
 -the blinking should be realised by using an interrupt

 -the behavior should be set by a global variable

 -the delay function should not be used (used for demonstration only)

 -for demo the internal LED is used


 #include <TimerOne.h>
 #define PIN_LED 13
 //
 void setup() {
   Serial.begin(38400);
   pinMode(PIN_LED, OUTPUT);
   Timer1.initialize(500000);
   Timer1.attachInterrupt(led_handle);
 }
 int saved_switch_position=0;
 void loop() {
   static int saved_switch_position=0;
   static int actual_switch_position =0;
   actual_switch_position=get_switch_11_level(A0);
   delay(200);
   if(actual_switch_position !=  get_switch_11_level(A0)){
     actual_switch_position = saved_switch_position;
   }
   if (saved_switch_position != actual_switch_position){
     saved_switch_position = actual_switch_position;
     switch(actual_switch_position){
       case 1: Serial.println("Switch position 1");
         break;
       case 2: Serial.println("Switch position 2");
         break;
       case 3: Serial.println("Switch position 3");
         break;
       case 4: Serial.println("Switch position 4");
         break;
       case 5: Serial.println("Switch position 5");
         break;
       case 6: Serial.println("Switch position 6");
         break;
       case 7: Serial.println("Switch position 7");
         break;
       case 8: Serial.println("Switch position 8");
         break;
       case 9: Serial.println("Switch position 9");
         break;
       case 10: Serial.println("Switch position 10");
         break;
       case 11: Serial.println("Switch position 11");
         break;
     }
   }
 //  Serial.println(String(get_switch_11_level(A0)));
   
   
 }
 int get_switch_11_level(int AD_Wandler){
   int return_value = 0;
   int x = analogRead(AD_Wandler);
   if (x >= 0 && x <= 51){
     return_value = 1;
   }
   else if (x >= 52 && x <= 153){
     return_value = 2;
   }
   else if (x >= 154 && x <= 256){
     return_value = 3;
   }
   else if (x >= 257 && x <= 358){
     return_value = 4;
   }
   else if (x >= 359 && x <= 460){
     return_value = 5;
   }
   else if (x >= 461 && x <= 563){
     return_value = 6;
   }
   else if (x >= 564 && x <= 665){
     return_value = 7;
   }
   else if (x >= 666 && x <= 767){
     return_value = 8;
   }
   else if (x >= 768 && x <= 870){
     return_value = 9;
   }
   else if (x >= 871 && x <= 972){
     return_value = 10;
   }
   else if (x >= 973 && x <= 1023){
     return_value = 11;
   }
 return(return_value);
 }
 void led_handle(void){
   if (digitalRead(PIN_LED) == LOW) {
     digitalWrite(PIN_LED, HIGH);
   } else {
     digitalWrite(PIN_LED, LOW);
   }
 }
 //int switch_position





https://code.google.com/archive/p/arduino-timerone/downloads


 
 





