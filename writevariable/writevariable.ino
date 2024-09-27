


#include <BluetoothSerial.h>
#include <Streaming.h>
#include <EEPROM.h>
#include <string.h>
#include <M5StickC.h>
BluetoothSerial serialBT;


int hold = 56;

void setup() {
 M5.begin();
 M5.Lcd.setRotation(3);
 serialBT.begin("Esp32-BT");
 M5.Lcd << hold << endl;
 delay(2000);
}

void loop() {
if(serialBT.available()){
    int updte = serialBT.read();
    hold = atoi(updte);
        
    M5.Lcd.print(hold);
    
  }
  
 delay(2000);
}
