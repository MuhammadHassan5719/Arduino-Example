

#include <NewPing.h>

#include <Servo.h>

Servo servoMain; // Define our Servo

int  trigpin = 3;

int echopin = 2;

int distance;

float duration;

float  cm;

void setup()

{
  Serial.begin(115200);

servoMain.attach(9); // servo on digital  pin 10

pinMode(trigpin, OUTPUT);

pinMode(echopin, INPUT);

}

void  loop()

{

digitalWrite(trigpin, LOW);

delay(2);

digitalWrite(trigpin,  HIGH);

delayMicroseconds(10);

digitalWrite(trigpin, LOW);

duration  = pulseIn(echopin, HIGH);

cm = (duration/58.82);

distance = cm;


if(distance<30)

{

servoMain.write(90);  // Turn Servo back to center position (90 degrees)

delay(3000);

}

else{

servoMain.write(180);

delay(50);

}
Serial.println(distance);
}