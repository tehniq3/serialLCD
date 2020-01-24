// NTP clock on serial LCD2004

// original sketch by Nicu FLORICA (niq_ro) from http://nicuflorica.blogspot.ro/

#include <SoftwareSerial.h>
#include <SerLCD.h>
// Make a SoftwareSerial object, and a new SerLCD object, 
// which points at the NewSoftSerial object. 
//
// In this demo the Rx pin of the SerLCD is connected to 
// NodeMCU digital pin D8/GPIO14 (Tx)  We set the SoftwareSerial 
// Rx to 255 because the SerLCD has no facility to transmit
// back. 
//

SoftwareSerial NSS(255,13,1);
SerLCD lcd(NSS,20,4); 

#define gol 160
#define sus 5
#define jos 4
#define plin 255


int zora, uora, ora;
int zminut, uminut, minut;
byte puls = 0;

int x = 0;

#include <ESP8266WiFi.h>
#include <NTPtimeESP.h>


NTPtime NTPch("ch.pool.ntp.org");   // Choose server pool as required
char *ssid      = "bbk2";               // Set you WiFi SSID
char *password  = "internet2";               // Set you WiFi password

/*
 * The structure contains following fields:
 * struct strDateTime
{
  byte hour;
  byte minute;
  byte second;
  int year;
  byte month;
  byte day;
  byte dayofWeek;
  boolean valid;
};
 */
strDateTime dateTime;



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
  Serial.begin(9600);
  NSS.begin(9600); 
  lcd.begin();
  
  lcd.clear(); 
  // Print a logo message to the LCD.
  lcd.setPosition(1, 1);
  lcd.print("arduinotehniq.com");  
  lcd.setPosition(2, 2);
  lcd.print("made by niq_ro");
  lcd.setPosition(4, 0);
  lcd.print("Connecting to Wi-Fi");
  delay (2500);
  
  WiFi.mode(WIFI_STA);
  WiFi.begin (ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println("WiFi connected");
  lcd.setPosition(4, 0);
  lcd.print("WiFi connected     ");
  
  delay (2500);
  lcd.clear();
}

void loop () {
if (puls == 0)
{
   // first parameter: Time zone in floating point (for India); second parameter: 1 for European summer time; 2 for US daylight saving time (contributed by viewwer, not tested by me)
  dateTime = NTPch.getNTPtime(2.0, 1);

  // check dateTime.valid before using the returned time
  // Use "setSendInterval" or "setRecvTimeout" if required
  if(dateTime.valid){
    NTPch.printDateTime(dateTime);

    ora = dateTime.hour;
    minut = dateTime.minute;
 /*
    byte actualsecond = dateTime.second;
    int actualyear = dateTime.year;
    byte actualMonth = dateTime.month;
    byte actualday =dateTime.day;
    byte actualdayofWeek = dateTime.dayofWeek;
    */
  } 
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
}

//puls = millis()/500;
puls = puls +1;
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

