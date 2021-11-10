/**
 * This example turns the ESP32 into a Bluetooth LE keyboard that writes the words, presses Enter, presses a media key and then Ctrl+Alt+Delete
 */
#include <BleKeyboard.h>
#include <numeric>
using namespace std;

int analogPin = 25;
int val = 0;

char tx1[] = "This trail was added in November 2021 as part of the German State Audit.";
char tx2[] = "This trail was edited in November 2021 as part of the German State Audit.";
char tx3[] = "This trail was added in November 2021 as part of the German State Audit. & This trail was edited in November 2021 as part of the German State Audit.";

BleKeyboard bleKeyboard("AllTrails Pad", "Benedikt Maier", 100);

int average = 0;
int indexB = 0;
int total[10000];

void setup() {
  Serial.begin(9600);
  Serial.println("Starting BLE work!");
  bleKeyboard.begin();
}

void loop() {
  if(bleKeyboard.isConnected()) {
    int reading = analogRead(analogPin);
    if (reading > 50) {
       Serial.print(indexB);
       Serial.print(" reading:");
       Serial.println(reading);
       total[indexB] = reading;
       indexB = indexB + 1;
       reading= 0;

      } else if (reading < 50) {
        if (indexB != 0) {
        average =  accumulate(begin(total), end(total), 0, plus<int>()) / indexB;
        Serial.print("average:");
          Serial.println(average);

         if(average > 3800 ) {
          //bleKeyboard.print(tx1);
        Serial.println("12 pressed" );
        delay(100);
      } else if (average > 3500 ) {
          //bleKeyboard.print(tx2);
        Serial.println("11 pressed" );
        delay(100);
      } else if(average > 3000 ) {
          //bleKeyboard.print(tx3);
        Serial.println("10 pressed" );
        delay(100);
      } else if(average > 2780 ) {
        bleKeyboard.press(130);
        bleKeyboard.press(111);
        delay(100);
        bleKeyboard.releaseAll();
        Serial.println("9 pressed" );
      } else if(average >  2580 ) {
        bleKeyboard.press(130);
        bleKeyboard.press(108);
        delay(100);
        bleKeyboard.releaseAll();
        Serial.println("8 pressed" );
      } else if(average >  2380) {
       bleKeyboard.press(130);
        bleKeyboard.press(107);
        delay(100);
        bleKeyboard.releaseAll();
        Serial.println("7 pressed" );
      } else if(average >  2200) {
        bleKeyboard.press(130);
        bleKeyboard.press(115);
        delay(100);
        bleKeyboard.releaseAll();
        Serial.println("6 pressed" );
      } else if(average >  2080) {
        bleKeyboard.press(130);
        bleKeyboard.press(101);
        delay(100);
        bleKeyboard.releaseAll();
        Serial.println("5 pressed" );
      } else if(average >  1980) {
        bleKeyboard.press(130);
        bleKeyboard.press(102);
        delay(100);
        bleKeyboard.releaseAll();
        Serial.println("4 pressed" );
      } else if(average >  1880) {
       bleKeyboard.press(134);
        delay(100);
       bleKeyboard.releaseAll();
        Serial.println("3 pressed" );
      } else if(average >  1780) {
        bleKeyboard.press(130);
        bleKeyboard.press(122);
        delay(100);
        bleKeyboard.releaseAll();
        Serial.println("2 pressed" );
      } else if(average < 1780) {
        bleKeyboard.press(130);
        bleKeyboard.press(98);
        delay(100);
        bleKeyboard.releaseAll();
        Serial.println("1 pressed" );
      }

          std::fill_n(total, indexB, 0);
          indexB = 0;
          average = 0;
          reading= 0;


        };
    }
  } else {
  delay(5000);
  Serial.println("wait wait wait");


  }
}
