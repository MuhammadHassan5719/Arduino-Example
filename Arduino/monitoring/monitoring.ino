/*
   -- New project --
   
   This source code of graphical user interface 
   has been generated automatically by RemoteXY editor.
   To compile this code using RemoteXY library 3.1.13 or later version 
   download by link http://remotexy.com/en/library/
   To connect using RemoteXY mobile app by link http://remotexy.com/en/download/                   
     - for ANDROID 4.13.13 or later version;
     - for iOS 1.10.3 or later version;
    
   This source code is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.    
*/

//////////////////////////////////////////////
//        RemoteXY include library          //
//////////////////////////////////////////////
// dht library
#
#include <DHT.h>
DHT dht(4, DHT11);
// you can enable debug logging to Serial at 115200
//#define REMOTEXY__DEBUGLOG    

// RemoteXY select connection mode and include library 
#define REMOTEXY_MODE__ESP32CORE_BLE

#include <BLEDevice.h>

// RemoteXY connection settings 
#define REMOTEXY_BLUETOOTH_NAME "Monitoring"


#include <RemoteXY.h>

// RemoteXY GUI configuration  
#pragma pack(push, 1)  
uint8_t RemoteXY_CONF[] =   // 116 bytes
  { 255,0,0,11,0,21,0,17,0,0,0,31,1,106,200,1,1,1,0,67,
  3,103,102,12,5,16,26,11 };
  
 
  
// this structure defines all the variables and events of your control interface 
struct {
  char Temp[100] = {printf("Temperature: %c/nHumadity%c",ctemp,chum)};
char chum[10];
char ctemp[10];
    // output variables
  // char Humadity[11]; // string UTF8 end zero
// string UTF8 end zero
  //float instrument_01; // from 0 to 100

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0

} RemoteXY;   
#pragma pack(pop)
 
/////////////////////////////////////////////
//           END RemoteXY include          //
/////////////////////////////////////////////




void setup() 
{
  dht.begin();
  RemoteXY_Init (); 
  
  
  // TODO you setup code
  
}

void loop() 
{ 
  float dtemp = dht.readTemperature();
  float dhumadity = dht.readHumidity();
   
  dtostrf(dtemp, 0, 1, RemoteXY.ctemp);
  dtostrf(dhumadity, 0, 1,RemoteXY.chum);
   
 
 // RemoteXY.instrument_01 = dhumadity;
  RemoteXY_Handler ();
 
  
  
  // TODO you loop code
  // use the RemoteXY structure for data transfer
  // do not call delay(), use instead RemoteXY_delay() 


}