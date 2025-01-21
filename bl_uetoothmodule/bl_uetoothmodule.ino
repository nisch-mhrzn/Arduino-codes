#include <SoftwareSerial.h>
#define ENA 9
#define ENB 10
#define in1 3
#define in2 4
#define in3 5
#define in4 6


SoftwareSerial mySerial(7, 8);
int bval;
int rpm = 220;
void setup() {
  // put your setup code here, to run once:
  mySerial.begin(9600);
  Serial.begin(9600);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);


}

void loop() {
  // put your main code here, to run repeatedly:
  if (mySerial.available() > 0) {
    bval = mySerial.read();
    Serial.println(bval);
  }
  if (bval == 70) {
    forward();
  }
  if (bval == 66) {
    backward();
  }
  if (bval == 76) {
    left();
  }
  if (bval == 82) {
    right();
  }
  if (bval == 83) {
    pause();
  }
}

void forward() {
  analogWrite(ENA, rpm);
  analogWrite(ENB, rpm);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}
void backward() {
  analogWrite(ENA, rpm);
  analogWrite(ENB, rpm);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}
void left() {
  analogWrite(ENA, rpm);
  analogWrite(ENB, rpm);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}
void right() {
  analogWrite(ENA, rpm);
  analogWrite(ENB, rpm);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}
void pause() {
  analogWrite(ENA, rpm);
  analogWrite(ENB, rpm);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

