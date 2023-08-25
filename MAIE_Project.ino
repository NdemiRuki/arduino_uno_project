#include <Servo.h>


const int trigP = 9;
const int echoP = 10;

Servo servo1;
float distance;
float time;
int pos = 0;  // variable to store the servo position
void setup() {
  pinMode(trigP, OUTPUT); // sets the trigP as an Output
  pinMode(echoP, INPUT); // sets the echoP as an input 
  servo1.attach (7); // attach the servo on pin 7 to theservo object
  Serial.begin(9600); // Starts the serial communication
}

void loop() {

  // Clears trigP (Make sure it's set to low)
  digitalWrite(trigP, LOW);
  delayMicroseconds(2);
  digitalWrite(trigP, HIGH);
  delayMicroseconds(1);
  digitalWrite(trigP, LOW); // Reads the echoP, returns the sound wave travel time in microseconds
  time = pulseIn(echoP, HIGH);

    distance = (time/2) / 29.1;   // calculating the distance in cm
    Serial.print("Distance = "); 
    Serial.println(distance); // Reads the distance
    

for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    if(distance <= 30){
    servo1.write(pos);   // tell servo to go to position in variable 'pos'
    delay(15);  // waits 15 ms for the servo to reach the position
    }
   else if (distance <= 90) {
     servo1.write(pos);
     delay(10);
   }
   else{
     servo1.write(pos);
     delay(5);
   }
                           
  }

 
}
  