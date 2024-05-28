#include <ESP32Servo.h>

const byte trig_pin=12;
const byte echo_pin=26;
const byte servo_pin = 19; 
const byte led_pin=21;

Servo servo;

void setup() {

  pinMode(trig_pin, OUTPUT);
  pinMode(echo_pin, INPUT);
  pinMode(led_pin,OUTPUT);

  servo.attach(servo_pin);
  Serial.begin(115200);
}

void loop() {

  long int distance=get_distance();

  if(distance<=15){
    Serial.println("Sanitizer ON");
    servo.write(180);
    digitalWrite(led_pin,HIGH); 

  }
  else{
    Serial.println("Sanitizer OFF");
    servo.write(0);
    digitalWrite(led_pin,LOW);
  }
  delay(10); 
}

int get_distance(){
  
  digitalWrite(trig_pin , LOW);
  delayMicroseconds(2);

  digitalWrite(trig_pin , HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin , LOW);

  long int duration = pulseIn(echo_pin , HIGH);
  
  long int distance = (duration * 0.034) / 2;

  return distance;
}