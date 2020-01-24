// NTP clock on serial LCD2004
// original sketch by Nicu FLORICA (niq_ro) from http://nicuflorica.blogspot.ro/
// ver.2, use info from // https://lastminuteengineers.com/esp8266-ntp-server-date-time-tutorial/

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

#define rxPin 255       // Not used, so set to invalid pin #
#define txPin 13         // Connect BPI/BPK's SER input to this pin.
#define inverted 1     // In setup, 1=inverted, 0=noninverted

SoftwareSerial NSS(rxPin, txPin, inverted);  // 
SerLCD lcd(NSS,20,4); 

#define gol 160
#define sus 5
#define jos 4
#define plin 255


int zora, uora, ora;
int zminut, uminut, minut;
byte puls = 0;

int x = 0;

#include <NTPClient.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

const char *ssid     = "bere";
const char *password = "faceticinste";

const long utcOffsetInSeconds = 7200;

char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

// Define NTP Client to get time
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", utcOffsetInSeconds);


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
//  lcd.write(jos);
  lcd.write(gol);
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
  /*
  lcd.write(jos); 
  lcd.write(sus);  
  lcd.write(gol);
  lcd.write(plin);
  */
  lcd.write(gol); 
  lcd.write(plin);  
  lcd.write(gol);
  lcd.write(plin);
  lcd.setPosition(2,x); 
  /*
  lcd.write(plin);  
  lcd.write(jos);  
  lcd.write(jos);  
  lcd.write(plin); 
  */
  lcd.write(plin);  
  lcd.write(gol);  
  lcd.write(gol);
  lcd.write(plin);
  lcd.setPosition(3,x); 
  /*
  lcd.write(gol);  
  lcd.write(gol);  
  lcd.write(gol);
  lcd.write(plin); 
  */
  lcd.write(sus);  
  lcd.write(sus);  
  lcd.write(sus);
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


void ceas()
{
 timeClient.update();
/*
  Serial.print(daysOfTheWeek[timeClient.getDay()]);
  Serial.print(", ");
  Serial.print(timeClient.getHours());
  Serial.print(":");
  Serial.print(timeClient.getMinutes());
  Serial.print(":");
  Serial.println(timeClient.getSeconds());
  //Serial.println(timeClient.getFormattedTime());
*/
    ora = timeClient.getHours();
    minut = timeClient.getMinutes();
 /*
    byte actualsecond = dateTime.second;
    int actualyear = dateTime.year;
    byte actualMonth = dateTime.month;
    byte actualday =dateTime.day;
    byte actualdayofWeek = dateTime.dayofWeek;
    */
//} 
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



void setup () {
  digitalWrite(txPin, LOW);   // Stop bit state for inverted serial
  pinMode(txPin, OUTPUT);
  Serial.begin(9600);
  NSS.begin(9600); 
  delay(10); 
  lcd.begin();
  lcd.clear();
  delay(2000); 
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
 //   Serial.print(".");
   lcd.setPosition(4, 19);
   lcd.print(".");
    delay(500);
   lcd.setPosition(4, 19);
   lcd.print(" ");
  }
//  Serial.println("WiFi connected");
  lcd.setPosition(4, 0);
  lcd.print("WiFi connected      ");
  
  delay (1500);
  lcd.clear();
//  ceas();
timeClient.begin();
lcd.clear();
}



void loop () {
 ceas();

//puls = millis()/500;
puls = puls+1;
  if (puls%2 == 1)
 {
  lcd.setPosition(2,10); 
  lcd.write(0b11011111);
  lcd.setPosition(4,10); 
  lcd.write(0b11011111);
 }
 else
 {
  lcd.setPosition(2,10); 
  lcd.write(gol);
  lcd.setPosition(4,10); 
  lcd.write(gol);
 }
  delay(1000);
} // end main loop

