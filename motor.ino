#include <SoftwareSerial.h>

const int motor= 11; //LED connected to digital pin 10
#define trigPin1 6
#define echoPin1 7
long duration1;
int distance1;
int state = 0;
float ph;
float turbidity;

void setup()
{
pinMode(motor, OUTPUT); //sets the digital pin as output
pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);

  //Begin Serial communication at a baudrate of 9600:
  Serial.begin(9600);
}

void loop()
{
  if(Serial.available() > 0)
  {
    state = Serial.read();
  }
  if(state == '0') {
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(5);
  // Trigger the sensor by setting the trigPin high for 10 microseconds:
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  // Read the echoPin, pulseIn() returns the duration (length of the pulse) in microseconds:
  duration1 = pulseIn(echoPin1, HIGH);
  // Calculate the distance:
  distance1= duration1*0.034/2;
  Serial.println(distance1);
  delay(50);        
  if(distance1 < 7)
  {
    digitalWrite(motor,HIGH);
  }
  else
  {
    digitalWrite(motor,LOW);
  }
  state = 0;
  }
  else if (state == '1') {
state = 0;
}
}
