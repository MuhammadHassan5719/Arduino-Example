#include <DHT.h>
#include <BluetoothSerial.h>

BluetoothSerial serialBT;
DHT dht(26, DHT11);

void setup() {
 dht.begin();
 delay(2000);
 serialBT.begin("Esp32-BT");
}

void loop() {
 float temp = dht.readTemperature();
 float humidity = dht.readHumidity(); 
 if(serialBT.available()){
 serialBT.print("Temp: ");
 serialBT.print(temp);
 serialBT.println(" C ");
 serialBT.print("Humidity: ");
 serialBT.print(humidity);
 serialBT.println(" % ");
 }

 delay(2000);
}
