/*
   -- New project --
   
   This source code of graphical user interface 
   has been generated automatically by RemoteXY editor.
   To compile this code using RemoteXY library 3.1.13 or later version 
   download by link http://remotexy.com/en/library/
   To connect using RemoteXY mobile app by link http://remotexy.com/en/download/                   
     - for ANDROID 4.14.08 or later version;
     - for iOS 1.11.2 or later version;
    
   This source code is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.    
*/

//////////////////////////////////////////////
//        RemoteXY include library          //
//////////////////////////////////////////////

// you can enable debug logging to Serial at 115200
//#define REMOTEXY__DEBUGLOG    

// RemoteXY select connection mode and include library 
#define REMOTEXY_MODE__WIFI_POINT

#include <WiFi.h>

// RemoteXY connection settings 
#define REMOTEXY_WIFI_SSID "Zaincom-Stormfiber"
#define REMOTEXY_WIFI_PASSWORD "syedamin110"
#define REMOTEXY_SERVER_PORT 6377


#include <RemoteXY.h>
#include <BluetoothSerial.h>
#include <Streaming.h>
#include <EEPROM.h>
#include <M5StickC.h>
BluetoothSerial serialBT;
// RemoteXY GUI configuration  
#pragma pack(push, 1)  
uint8_t RemoteXY_CONF[] =   // 47 bytes
  { 255,12,0,0,0,40,0,18,0,0,0,31,1,106,200,1,1,2,0,7,
  31,111,40,10,101,0,2,26,2,11,10,37,134,24,24,48,4,26,31,79,
  78,0,31,79,70,70,0 };
  
// this structure defines all the variables and events of your control interface 
struct {

    // input variables
  char threshold[11]; // string UTF8 end zero
  uint8_t submit; // =1 if state is ON, else =0

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0

} RemoteXY;   
#pragma pack(pop)
 
/////////////////////////////////////////////
//           END RemoteXY include          //
/////////////////////////////////////////////


  
void setup() 
{ serialBT.begin("Esp32-BT");
  RemoteXY_Init (); 

  
  // TODO you setup code
  
}

void loop() 
{ float th=0;
  RemoteXY_Handler ();
  dtostrf(th, 0, 1, RemoteXY.threshold);
  if(RemoteXY.submit==1 && serialBT.available()){
    serialBT.print("Threshold:");
    serialBT.print(th);
  }
  
  // TODO you loop code
  // use the RemoteXY structure for data transfer
  // do not call delay(), use instead RemoteXY_delay() 


}
