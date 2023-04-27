/* Get tilt angles on X and Y, and rotation angle on Z
* Angles are given in degrees
*
* License: MIT
*/
#include "Wire.h"
#include "MPU6050_light.h"
int Q9=9,Q10=9,Q11=11,Q12=12; //Output pins to be connected
to 10, 11, 12, 13 of Decoder IC
long x; //Variable for storing X coordinates
long y; //Variable for storing Y coordinates
long z; //Variable for storing Z coordinates
MPU6050 mpu(Wire);
unsigned long timer = 0;
void setup() {
Serial.begin(9600);
Wire.begin();
pinMode(Q9,OUTPUT);
pinMode(Q10,OUTPUT);
pinMode(Q11,OUTPUT);
pinMode(Q12,OUTPUT);


byte status = mpu.begin();
Serial.print(F("MPU6050 status: "));
Serial.println(status);
while(status!=0){ } // stop everything if could not connect
to MPU6050
Serial.println(F("Calculating offsets, do not move
MPU6050"));
delay(1000);
Serial.println("Done!\n");
}
void loop() {
mpu.update();

if((millis()-timer)>10){ // print data every 10ms
Serial.print("X : ");
Serial.print(mpu.getAngleX());
Serial.print("\tY : ");
Serial.print(mpu.getAngleY());
Serial.print("\tZ : ");
Serial.println(mpu.getAngleZ());
timer = millis();
}
x = mpu.getAngleX();
y = mpu.getAngleY();
z = mpu.getAngleZ();
if(y>7) // Change the value for adjusting sensitivity
44
Forward();
else if(y<-9) // Change the value for adjusting sensitivity
Backward();
else if(z>10) // Change the value for adjusting sensitivity
Right();
else if(z<-9) // Change the value for adjusting sensitivity
Left();
else
Stop();
}
void Stop()
{
Serial.println("&");
Serial.println("STOP");
digitalWrite(Q9,LOW);
digitalWrite(Q10,LOW);
digitalWrite(Q11,LOW);
digitalWrite(Q12,LOW);
}
void Forward()
{
Serial.println("&");
Serial.println("Forward");
digitalWrite(Q9,HIGH);
digitalWrite(Q10,LOW);
digitalWrite(Q11,LOW);
digitalWrite(Q12,LOW);
}

void Backward()
{
Serial.println("&");
Serial.println("Backward");
digitalWrite(Q9,HIGH);
digitalWrite(Q10,LOW);
digitalWrite(Q11,HIGH);
digitalWrite(Q12,LOW);
}
void Left()
{
Serial.println("&");
Serial.println("Left");
digitalWrite(Q9,LOW);
digitalWrite(Q10,LOW);
digitalWrite(Q11,LOW);
digitalWrite(Q12,HIGH);
}
void Right()
{
Serial.println("&");
Serial.println("Right");
digitalWrite(Q9,LOW);
digitalWrite(Q10,LOW);
digitalWrite(Q11,HIGH);
digitalWrite(Q12,LOW);
}