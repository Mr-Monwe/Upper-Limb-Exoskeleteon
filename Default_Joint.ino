#define pwmPin 5
#define dirPin  4
#define outputA 11
#define outputB 12
int counter = 0;
int angle = 0;
int aState;
int aLastState;

void setup() {
  // Sets the two pins as Outputs
  pinMode(pwmPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode (outputA, INPUT);
  pinMode (outputB, INPUT);

  aLastState = digitalRead(outputA);
}
void loop() {
  aState = digitalRead(outputA);

  if (aState != aLastState) {
    if (digitalRead(outputB) != aState) {
      counter ++;
      angle ++;
      rotateCW();
    }
    else {
      counter--;
      angle --;
      rotateCCW();
    }
    if (counter >= 30 ) {
      counter = 0;
    }
  }
  aLastState = aState;
}
void rotateCW() {
  digitalWrite(dirPin, LOW);
  analogWrite(pwmPin, 255);
  delayMicroseconds(5000);
  digitalWrite(pwmPin, LOW);
  delayMicroseconds(5000);
}
void rotateCCW() {
  digitalWrite(dirPin, HIGH);
  analogWrite(pwmPin, -255);
  delayMicroseconds(5000);
  digitalWrite(pwmPin, HIGH);
  delayMicroseconds(5000);
}
