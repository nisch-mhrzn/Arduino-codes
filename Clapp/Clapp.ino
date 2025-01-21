static bool btog= false;
void setup() {
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  pinMode(A1,INPUT);
  
}

void loop() {
  int d =analogRead(A1);
  if(d>=20)
  {
  Serial.println(d);
  btog=!btog;
  digitalWrite(13,btog);
  delay(150);
}
}



