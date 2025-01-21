int Trig=10;
int Echo=9;
int a;
int b;
void setup() {
  // put your setup code here, to run once:
  pinMode(Trig,OUTPUT);
  pinMode(Echo,INPUT);
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  pinMode(A0,INPUT);

}

void loop() {
  // put your main code here, to run repeate
  b=analogRead(A0);
  digitalWrite(Trig,LOW);
  delayMicroseconds(2);
  digitalWrite(Trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig,LOW);
  long t=pulseIn(Echo,HIGH);
  int d= (0.034*t)/2;
  Serial.println("Distance in cm = ");
  Serial.println(d);
  delay(200);

if (d>=20 && b>=500){
  //digitalWrite(8,LOW);
  digitalWrite(13,HIGH);
}
else{
  digitalWrite(13,LOW);
  //digitalWrite(8,LOW);
  
}

}
