// Date and time functions using a DS1307 RTC 
// original sketck from http://learn.adafruit.com/ds1307-real-time-clock-breakout-board-kit/
// add part with SQW=1Hz from http://tronixstuff.wordpress.com/ & http://www.bristolwatch.com/arduino/arduino_ds1307.htm
// original article from http://nicuflorica.blogspot.ro/2013/06/ceas-de-timp-real-rtc-cu-ds1307-si.html
// original sketch by Nicu FLORICA (niq_ro) from http://nicuflorica.blogspot.ro/

#include <Wire.h>
#include "RTClib.h"

#include <SoftwareSerial.h>
#include <SerLCD.h>
// Make a SoftwareSerial object, and a new SerLCD object, 
// which points at the NewSoftSerial object. 
//
// In this demo the Rx pin of the SerLCD is connected to 
// Arduino digital pin 4 (Tx)  We set the SoftwareSerial 
// Rx to 0 because the SerLCD has no facility to transmit
// back. 
//
SoftwareSerial NSS(255,4,1);
SerLCD lcd(NSS,20,4); 

#define gol 160
#define sus 5
#define jos 4
#define plin 255

RTC_DS1307 RTC;

int zora, uora, ora;
int zminut, uminut, minut;
int puls;

int x = 0;

void custom0()
{ // uses segments to build the number 0 - https://www.seetron.com/bpk000/bpk000prog.html
  lcd.setPosition(1,x); 
  lcd.write(jos);   // down
  lcd.write(sus);   // up
  lcd.write(sus);
  lcd.write(jos);
  lcd.setPosition(2,x); 
  lcd.write(plin);  // solid
  lcd.write(gol);  // empty
  lcd.write(gol);
  lcd.write(plin); 
  lcd.setPosition(3,x); 
  lcd.write(plin);  // solid
  lcd.write(gol);  // empty
  lcd.write(gol);
  lcd.write(plin); 
  lcd.setPosition(4,x); 
  lcd.write(sus);
  lcd.write(jos);  
  lcd.write(jos);
  lcd.write(sus);    
}

void custom1()
{ // uses segments to build the number 1 - https://www.seetron.com/bpk000/bpk000prog.html
  lcd.setPosition(1,x); 
  lcd.write(gol); // empty
  lcd.write(jos);   // down
  lcd.write(plin); // solid
  lcd.write(gol); // empty
  lcd.setPosition(2,x); 
  lcd.write(sus);    // up
  lcd.write(gol);  // empty
  lcd.write(plin);  // solid
  lcd.write(gol);  // solid
  lcd.setPosition(3,x); 
  lcd.write(gol);  
  lcd.write(gol);  
  lcd.write(plin);
  lcd.write(gol); 
  lcd.setPosition(4,x); 
  lcd.write(jos);
  lcd.write(jos);  
  lcd.write(plin);
  lcd.write(jos);    
}

void custom2()
{ // uses segments to build the number 2 - https://www.seetron.com/bpk000/bpk000prog.html
  lcd.setPosition(1,x); 
  lcd.write(jos);  // down
  lcd.write(sus);  // up
  lcd.write(sus);  // up
  lcd.write(jos);  // down
  lcd.setPosition(2,x); 
  lcd.write(sus);    // up
  lcd.write(gol);  // empty
  lcd.write(gol);  // empty
  lcd.write(plin); // solid
  lcd.setPosition(3,x); 
  lcd.write(gol);  
  lcd.write(jos);  
  lcd.write(sus);
  lcd.write(gol); 
  lcd.setPosition(4,x); 
  lcd.write(plin);
  lcd.write(jos);  
  lcd.write(jos);
  lcd.write(jos);    
}

void custom3()
{ // uses segments to build the number 3 - https://www.seetron.com/bpk000/bpk000prog.html
  lcd.setPosition(1,x); 
  lcd.write(jos); 
  lcd.write(sus);   
  lcd.write(sus);
  lcd.write(jos); 
  lcd.setPosition(2,x); 
  lcd.write(gol);  
  lcd.write(jos);  
  lcd.write(jos);  
  lcd.write(sus);  
  lcd.setPosition(3,x); 
  lcd.write(gol);  
  lcd.write(gol);  
  lcd.write(gol);
  lcd.write(plin); 
  lcd.setPosition(4,x); 
  lcd.write(sus);
  lcd.write(jos);  
  lcd.write(jos);
  lcd.write(sus);    
}

void custom4()
{ // uses segments to build the number 4 - https://www.seetron.com/bpk000/bpk000prog.html
  lcd.setPosition(1,x); 
  lcd.write(jos); 
  lcd.write(sus);  
  lcd.write(gol);
  lcd.write(plin);
  lcd.setPosition(2,x); 
  lcd.write(plin);  
  lcd.write(jos);  
  lcd.write(jos);  
  lcd.write(plin); 
  lcd.setPosition(3,x); 
  lcd.write(gol);  
  lcd.write(gol);  
  lcd.write(gol);
  lcd.write(plin); 
  lcd.setPosition(4,x); 
  lcd.write(gol);  
  lcd.write(gol);  
  lcd.write(gol);
  lcd.write(plin);   
}

void custom5()
{ // uses segments to build the number 5 - https://www.seetron.com/bpk000/bpk000prog.html
  lcd.setPosition(1,x); 
  lcd.write(plin); 
  lcd.write(sus);  
  lcd.write(sus);
  lcd.write(sus);
  lcd.setPosition(2,x); 
  lcd.write(plin);  
  lcd.write(jos);  
  lcd.write(jos);  
  lcd.write(gol); 
  lcd.setPosition(3,x); 
  lcd.write(gol);  
  lcd.write(gol);  
  lcd.write(gol);
  lcd.write(plin); 
  lcd.setPosition(4,x); 
  lcd.write(sus);  
  lcd.write(jos);  
  lcd.write(jos);
  lcd.write(sus);   
}

void custom6()
{ // uses segments to build the number 6 - https://www.seetron.com/bpk000/bpk000prog.html
  lcd.setPosition(1,x); 
  lcd.write(jos); 
  lcd.write(sus);  
  lcd.write(sus);
  lcd.write(jos);
  lcd.setPosition(2,x); 
  lcd.write(plin);  
  lcd.write(jos);  
  lcd.write(jos);  
  lcd.write(gol); 
  lcd.setPosition(3,x); 
  lcd.write(plin);  
  lcd.write(gol);  
  lcd.write(gol);
  lcd.write(plin); 
  lcd.setPosition(4,x); 
  lcd.write(sus);  
  lcd.write(jos);  
  lcd.write(jos);
  lcd.write(sus);   
}

void custom7()
{ // uses segments to build the number 7 - https://www.seetron.com/bpk000/bpk000prog.html
  lcd.setPosition(1,x); 
  lcd.write(plin); 
  lcd.write(sus);  
  lcd.write(sus);
  lcd.write(plin);
  lcd.setPosition(2,x); 
  lcd.write(gol);  
  lcd.write(gol);  
  lcd.write(jos);  
  lcd.write(sus); 
  lcd.setPosition(3,x); 
  lcd.write(gol);  
  lcd.write(jos);  
  lcd.write(sus);
  lcd.write(gol); 
  lcd.setPosition(4,x); 
  lcd.write(gol);  
  lcd.write(plin);  
  lcd.write(gol);
  lcd.write(gol);   
}

void custom8()
{ // uses segments to build the number 8 - https://www.seetron.com/bpk000/bpk000prog.html
  lcd.setPosition(1,x); 
  lcd.write(jos); 
  lcd.write(sus);  
  lcd.write(sus);
  lcd.write(jos);
  lcd.setPosition(2,x); 
  lcd.write(sus);  
  lcd.write(jos);  
  lcd.write(jos);  
  lcd.write(sus); 
  lcd.setPosition(3,x); 
  lcd.write(plin);  
  lcd.write(gol);  
  lcd.write(gol);
  lcd.write(plin); 
  lcd.setPosition(4,x); 
  lcd.write(sus);  
  lcd.write(jos);  
  lcd.write(jos);
  lcd.write(sus);   
}

void custom9()
{ // uses segments to build the number 9 - https://www.seetron.com/bpk000/bpk000prog.html
  lcd.setPosition(1,x); 
  lcd.write(jos); 
  lcd.write(sus);  
  lcd.write(sus);
  lcd.write(jos);
  lcd.setPosition(2,x); 
  lcd.write(sus);  
  lcd.write(jos);  
  lcd.write(jos);  
  lcd.write(plin); 
  lcd.setPosition(3,x); 
  lcd.write(gol);  
  lcd.write(gol);  
  lcd.write(gol);
  lcd.write(plin); 
  lcd.setPosition(4,x); 
  lcd.write(sus);  
  lcd.write(jos);  
  lcd.write(jos);
  lcd.write(sus);   
}

void spatiu()
{ // uses segments to clear a number - https://www.seetron.com/bpk000/bpk000prog.html
  lcd.setPosition(1,x); 
  lcd.write(gol); 
  lcd.write(gol);  
  lcd.write(gol);
  lcd.write(gol);
  lcd.setPosition(2,x); 
  lcd.write(gol);  
  lcd.write(gol);  
  lcd.write(gol);  
  lcd.write(gol); 
  lcd.setPosition(3,x); 
  lcd.write(gol);  
  lcd.write(gol);  
  lcd.write(gol);  
  lcd.write(gol); 
  lcd.setPosition(4,x); 
  lcd.write(gol);  
  lcd.write(gol);  
  lcd.write(gol);  
  lcd.write(gol);    
}

// subrutina de afisare a numerelor
void cifra(int numar)
{
  switch (numar)
  {
    case 0:
    custom0();
    break;

    case 1:
    custom1();
    break;

    case 2:
    custom2();
    break;

    case 3:
    custom3();
    break;

    case 4:
    custom4();
    break;

    case 5:
    custom5();
    break;

    case 6:
    custom6();
    break;

    case 7:
    custom7();
    break;

    case 8:
    custom8();
    break;

    case 9:
    custom9();
    break;
  }
}

void setup () {
  NSS.begin(9600); 
  lcd.begin();
  
  // DHT init
//  dht.begin();
  
  lcd.clear(); 
  // Print a logo message to the LCD.
  lcd.setPosition(1, 1);
  lcd.print("arduinotehniq.com");  
  lcd.setPosition(2, 2);
  lcd.print("made by niq_ro");
  delay (2500);
  lcd.clear();
    
   // Serial.begin(9600);
    Wire.begin();
  
// part code from http://tronixstuff.wordpress.com/
Wire.beginTransmission(0x68);
Wire.write(0x07); // move pointer to SQW address
Wire.write(0x10); // sends 0x10 (hex) 00010000 (binary) to control register - turns on square wave
Wire.endTransmission();
// end part code from http://tronixstuff.wordpress.com/

    RTC.begin();
  if (! RTC.isrunning()) {
    //Serial.println("RTC is NOT running!");
    // following line sets the RTC to the date & time this sketch was compiled
    RTC.adjust(DateTime(__DATE__, __TIME__));
  }
// RTC.adjust(DateTime(__DATE__, __TIME__)); // PC adjust
  
}

void loop () {
  DateTime now = RTC.now();
  ora = now.hour();
  minut = now.minute();
//  secunda = now.second();
  zora = ora/10;
  uora = ora%10;
  zminut = minut/10;
  uminut = minut%10;

x = 0;
if (zora == 0)
{
  spatiu();
}
else
  cifra(zora);
x = 5;
  cifra(uora);
x = 11;
  cifra(zminut);
x = 16;
  cifra(uminut);
 

puls = millis()/500;
  if (puls%2 == 1)
 {
  lcd.setPosition(2,10); 
  lcd.write(0b11011111);
  lcd.setPosition(3,10); 
  lcd.write(0b11011111);
 }
 else
 {
  lcd.setPosition(2,10); 
  lcd.write(gol);
  lcd.setPosition(3,10); 
  lcd.write(gol);
 }
  delay(500);
} // end main loop
