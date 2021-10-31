/**
 * This example turns the ESP32 into a Bluetooth LE keyboard that writes the words, presses Enter, presses a media key and then Ctrl+Alt+Delete
 */
#include <BleKeyboard.h>

int analogPin = 33;
int val = 0;

BleKeyboard bleKeyboard("AllTrails Pad", "Benedikt Maier", 100);

int average = 0;
int index = 0;
int total[index] = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("Starting BLE work!");
  bleKeyboard.begin();
}

void loop() {
  if(bleKeyboard.isConnected()) {
    if (analogRead(analogPin) > 50) {

        int anR = analogRead(analogPin);
        total[index] = anR;
        int index = index +1;

       // int average = (average + analogRead(analogPin)) / 2;
       // if (anR < 5) { break;
       // Serial.println(average);}

      } else if (analogRead(analogPin) < 50 && total != 0) {
        int average = total
    }
  }



// if(analogRead(analogPin) > 3110 ) {
////    bleKeyboard.press(KEY_LEFT_ALT);
////    bleKeyboard.press(122);
////    bleKeyboard.releaseAll();
//    Serial.println("12 pressed" );
//    delay(500);
//  } else if (analogRead(analogPin) > 2910 ) {
////    bleKeyboard.press(KEY_LEFT_ALT);
////    bleKeyboard.press(122);
////    bleKeyboard.releaseAll();
//    Serial.println("11 pressed" );
//  } else if(analogRead(analogPin) > 2750 ) {
////    bleKeyboard.press(KEY_LEFT_ALT);
////    bleKeyboard.press(122);
////    bleKeyboard.releaseAll();
//    Serial.println("10 pressed" );
//  } else if(analogRead(analogPin) > 2610 ) {
////    bleKeyboard.press(KEY_LEFT_ALT);
////    bleKeyboard.press(122);
////    bleKeyboard.releaseAll();
//    Serial.println("9 pressed" );
//    Serial.println(analogRead(analogPin));
//  } else if(analogRead(analogPin) >  2480) {
////    bleKeyboard.press(KEY_LEFT_ALT);
////    bleKeyboard.press(122);
////    bleKeyboard.releaseAll();
//    Serial.println("8 pressed" );
//  } else if(analogRead(analogPin) >  2372) {
////    bleKeyboard.press(KEY_LEFT_ALT);
////    bleKeyboard.press(122);
////    bleKeyboard.releaseAll();
//    Serial.println("7 pressed" );
//  } else if(analogRead(analogPin) >  2250) {
////    bleKeyboard.press(KEY_LEFT_ALT);
////    bleKeyboard.press(122);
////    bleKeyboard.releaseAll();
//    Serial.println("6 pressed" );
//  } else if(analogRead(analogPin) >  2170) {
////    bleKeyboard.press(KEY_LEFT_ALT);
////    bleKeyboard.press(122);
////    bleKeyboard.releaseAll();
//    Serial.println("5 pressed" );
//  } else if(analogRead(analogPin) >  2075) {
////    bleKeyboard.press(KEY_LEFT_ALT);
////    bleKeyboard.press(122);
////    bleKeyboard.releaseAll();
//    Serial.println("4 pressed" );
//  } else if(analogRead(analogPin) >  2000) {
////    bleKeyboard.press(KEY_LEFT_ALT);
////    bleKeyboard.press(122);
////    bleKeyboard.releaseAll();
//    Serial.println("3 pressed" );
//  } else if(analogRead(analogPin) >  1920) {
////    bleKeyboard.press(KEY_LEFT_ALT);
////    bleKeyboard.press(122);
////    bleKeyboard.releaseAll();
//    Serial.println("2 pressed" );
//  }}
}
