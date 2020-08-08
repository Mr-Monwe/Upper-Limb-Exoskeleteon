#include <Servo.h>
//Servo pins
#define ServONE 2
#define ServTWO 3
#define ServTHREE 4
#define ServFOUR 5
//Encoder pins
#define EncA1 7//White
#define EncB1 6//Black
#define EncA2 9//White
#define EncB2 8//Black
#define EncA3 11//Black
#define EncB3 10//White
#define EncA4 13//Black
#define EncB4 12//White
//Servo Objects
Servo servoObj1;
Servo servoObj2;
Servo servoObj3;
Servo servoObj4;
//Counters for incrementing and decrementing encoder movement
int counter1 = 0;
int counter2 = 0;
int counter3 = 0;
int counter4 = 0;
//Initial state of the encoder
int currentStateEncA1;
int currentStateEncA2;
int currentStateEncA3;
int currentStateEncA4;
//Final state of the encoders
int lastStateEncA1;
int lastStateEncA2;
int lastStateEncA3;
int lastStateEncA4;
//Setup function
void setup() {
  Serial.begin(9600);
  pinMode(EncA1, INPUT_PULLUP);
  pinMode(EncB1, INPUT_PULLUP);
  pinMode(EncA2, INPUT_PULLUP);
  pinMode(EncB2, INPUT_PULLUP);
  pinMode(EncA3, INPUT_PULLUP);
  pinMode(EncB3, INPUT_PULLUP);
  pinMode(EncA4, INPUT_PULLUP);
  pinMode(EncB4, INPUT_PULLUP);
  servoObj1.attach(ServONE);
  servoObj1.write(counter1);
  servoObj2.attach(ServTWO);
  servoObj2.write(counter2);
  servoObj3.attach(ServTHREE);
  servoObj3.write(counter3);
  servoObj4.attach(ServFOUR);
  servoObj4.write(counter4);
  lastStateEncA1 = digitalRead(EncA1);
  lastStateEncA2 = digitalRead(EncA2);
  lastStateEncA3 = digitalRead(EncA3);
  lastStateEncA4 = digitalRead(EncA4);
}
//Looping function
void loop() {
  //Call all move fucntions for each of the joints
  Joint1(EncA1, EncB1), Joint2(EncA2, EncB2), Joint3(EncA3, EncB3), Joint4(EncA4, EncB4);
}

void Joint1(int pinENCA, int pinENCB) {
  currentStateEncA1 = digitalRead(pinENCA);
  if (currentStateEncA1 != lastStateEncA1  && currentStateEncA1 == 1) {
    if (digitalRead(pinENCB) != currentStateEncA1) {
      counter1 --;
      if (counter1 < 0)
        counter1 = 0;
    } else {
      counter1 ++;
      if (counter1 > 180)
        counter1 = 180;
    }
    servoObj1.write(counter1);
  }
  lastStateEncA1 = currentStateEncA1;
}

void Joint2(int pinENCA, int pinENCB) {
  currentStateEncA2 = digitalRead(pinENCA);
  if (currentStateEncA2 != lastStateEncA2  && currentStateEncA2 == 1) {
    if (digitalRead(pinENCB) != currentStateEncA2) {
      counter2 --;
      if (counter2 < 0)
        counter2 = 0;
    } else {
      counter2 ++;
      if (counter2 > 60)
        counter2 = 60;
    }
    servoObj2.write(counter2);
  }
  lastStateEncA2 = currentStateEncA2;
}

void Joint3(int pinENCA, int pinENCB) {
  currentStateEncA3 = digitalRead(pinENCA);
  if (currentStateEncA3 != lastStateEncA3  && currentStateEncA3 == 1) {
    if (digitalRead(pinENCB) != currentStateEncA3) {
      counter3 --;
      if (counter3 < 0)
        counter3 = 0;
    } else {
      counter3 ++;
      if (counter3 > 90)
        counter3 = 90;
    }
    servoObj3.write(counter3);
  }
  lastStateEncA3 = currentStateEncA3;
}

void Joint4(int pinENCA, int pinENCB) {
  currentStateEncA4 = digitalRead(pinENCA);
  if (currentStateEncA4 != lastStateEncA4  && currentStateEncA4 == 1) {
    if (digitalRead(pinENCB) != currentStateEncA4) {
      counter4 --;
      if (counter4 < 0)
        counter4 = 0;
    } else {
      counter4 ++;
      if (counter4 > 90)
        counter4 = 90;
    }
    servoObj4.write(counter4);
  }
  lastStateEncA4 = currentStateEncA4;
}
