#include "ds1302.h"
#include <SoftSerial.h>     /* Allows Pin Change Interrupt Vector Sharing */
#include <TinyPinChange.h>  /* Ne pas oublier d'inclure la librairie <TinyPinChange> qui est utilisee par la librairie <RcSeq> */

SoftSerial mySerial(2, 3); // RX, TX

void setup()  
{
  mySerial.begin(4800);
  mySerial.println("Start Program ...");

  mySerial.println("DS1302 Init...");
  DS1302_init();
  
  mySerial.println("Setting Start time...");
  Time startTime;
  startTime.sc = 20;
  startTime.hr = 4;
  startTime.mi = 5;
  DS1302_set(startTime);
}

void loop() // run over and over
{
  Time curTime;
  DS1302_get(&curTime);
  mySerial.print(curTime.hr, DEC);
  mySerial.print(":");
  mySerial.print(curTime.mi, DEC);
  mySerial.print(":");
  mySerial.print(curTime.sc, DEC);
  mySerial.println();
  delay(1000);
}
