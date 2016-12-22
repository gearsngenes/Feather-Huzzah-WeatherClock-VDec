// Date and time functions using a DS3231 RTC connected via I2C and Wire lib
#include <Wire.h>
#include "RTClib.h"
#include <SPI.h>
//#include "Adafruit_HTU21DF.h"
#include <Adafruit_ILI9341.h>
#include "Adafruit_Si7021.h"
#include <Wire.h>


// ---------Huzzah related setup
 
#include <ESP8266WiFi.h>
#include "Adafruit_IO_Client.h"


// Configure WiFi access point details.
#define WLAN_SSID  "kvlan72013"
#define WLAN_PASS  "covada6164covada6164"

// Configure Adafruit IO access.
#define AIO_KEY    "a360176a7b68f1656bdc538729988443d8969a01"


//--------------- DHT SENSOR -----------------------------
#include "DHT.h"

#define DHTPIN 2     // what digital pin we're connected to
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
DHT dht(DHTPIN, DHTTYPE,15);
//-------------------- Si7021 Sensor---------------------------
Adafruit_Si7021 sensor = Adafruit_Si7021();
//----------------------------------------------------
// Create an ESP8266 WiFiClient class to connect to the AIO server.
WiFiClient client;


Adafruit_IO_Client aio = Adafruit_IO_Client(client, AIO_KEY);


Adafruit_IO_Feed tempFeed = aio.getFeed("temperature");
Adafruit_IO_Feed humidityFeed = aio.getFeed("humidity");

// ----------------------------

#include "Adafruit_LEDBackpack.h"             // Support for the LED Backpack FeatherWing
#include "Adafruit_GFX.h"                     // Adafruit's graphics library

char daysOfTheWeek[7][4] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
char monthsOfTheYear[12][4] = {"JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"};

  int prevHr ;

RTC_DS3231 rtc;
//Adafruit_HTU21DF htu = Adafruit_HTU21DF();

#ifdef ESP8266
   #define STMPE_CS 16
   #define TFT_CS   0
   #define TFT_DC   15
   #define SD_CS    2
#endif
 #define TIME_24_HOUR true
 
 int humidity, prevHum, inHum;
 int  temp,prevTemp, inTemp;
 
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);

DateTime now;
DateTime now16;
bool blinkColon = false;
bool tempChange=false;
bool humChange = false;



void setup () {


  Serial.begin(115200);

  delay(50); // wait for console opening
RTCSetup();
// HTU21DFSetup();
  TFTsetup();
  huzzahSetup ();
//  DHT22Setup();
  Si7021Setup();

}


void loop () {
  //DateTime
  prevHr = now16.hour();
  now = rtc.now();
  now16 = DateTime(now + TimeSpan(0, 0, 0, 42)); // ESP82366 takes a lot more time to compile.
 // {delay(100); serialPrintTime();}
//  now16 = DateTime(now + TimeSpan(0, 0, 36, 36));
 
  /* it takes approximately 16 seconds to compile, run and display.
    So, adding 16 seconds to compile time will give the right "now" time */

  TFTPrint();
  //if ((!(now16.second()==59))||(!(now16.second()==60))) {if (now16.second() %3 ==0) {processTempHum();}}
//Serial.print("Hum:");Serial.println(humidity,0);Serial.print("Tmp:");Serial.println(temp,0);



 if ((!(now16.second()==59))||(!(now16.second()==60))) {if ((now16.second() %37 ==0)&&(now16.minute()%1==0)) { // just so it happens only at 23 seconds and 46 seconds has enough time to do the sensoring.
//   getANDprocessFeeds() ;
 processTempHum();
 }}

  delay(10);
}
