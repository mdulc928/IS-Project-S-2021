#include <Adafruit_LSM303_Accel.h>  //Accelerometer library.
#include <Adafruit_Sensor.h>   
#include <Wire.h>   //Working with SDA and SCL
#include <SPI.h>    //also for SD card
#include <SD.h>     //SD card library
//#include <RTClib.h> //ChronoDot v2.1


/* Assign a unique ID to this sensor at the same time */
Adafruit_LSM303_Accel_Unified accel = Adafruit_LSM303_Accel_Unified(54321);

//Declare the chronodot sensor
//RTC_DS1307 RTC;

// set up variables using the SD utility library functions:

const int chipSelect = 10;

void setup(void) {
  //----------------------------Accelerometer Init-----------------------------------
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  /* Initialise the accelerometer sensor */
  while (!accel.begin());
  
  accel.setRange(LSM303_RANGE_4G);                    //need to read up on this still
  lsm303_accel_range_t new_range = accel.getRange();
  accel.setMode(LSM303_MODE_NORMAL);

  //----------------------------Chronodot Setup---------------------------------
  /* Wire.begin();
  RTC.begin();

  while(!RTC.isrunning());

  //Not necessary, but it's nice to have accurate time although, I really just need to keep track of timespan.
  DateTime now = RTC.now();
  DateTime compiled = DateTime(__DATE__, __TIME__);

  if(now.unixtime() < compiled.unixtime()){ //checking to make sure we don't need to adjust the RTC time.
    RTC.adjust(DateTime(__DATE__, __TIME__));
    } */

  //---------------------------SD setup ---------------------------------------

  pinMode(chipSelect, OUTPUT);
  //Testing that all the wiring is correct and SD card is present;
  Serial.println("Done");
}

void loop(void) {
  if(!SD.begin(chipSelect)){
    Serial.println("Cannot find sd");
  }
    
  File datal = SD.open("track.txt", FILE_WRITE);
  //DateTime now = RTC.now();
  sensors_event_t event;
  accel.getEvent(&event);

  Serial.println("Writing");

  /*datal.print(now.year(), DEC);
  datal.print('/');
  datal.print(now.month(), DEC);
  datal.print('/');
  datal.print(now.day(), DEC);
  datal.print(' ');
  datal.print(now.hour(), DEC);
  datal.print(':');
  datal.print(now.minute(), DEC);
  datal.print(':');
  datal.print(now.second(), DEC);
  datal.print(' ');*/
  datal.print('(');
  datal.print(event.acceleration.x);
  datal.print(",");
  datal.print(event.acceleration.y);
  datal.print(",");
  datal.print(event.acceleration.z);
  datal.print(") m/s^2| ");
  datal.close();
  Serial.println("Done");
  delay(500);
}
