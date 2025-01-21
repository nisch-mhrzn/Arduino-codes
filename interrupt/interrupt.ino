volatile bool bTog = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(2,INPUT_PULLUP);
  pinMode(10,OUTPUT);
  pinMode(12,OUTPUT);
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(2),swtch,RISING);
}

void swtch(){  // put your main code here, to run repeatedly:
  //+Serial.println(bTog);
  if(digitalRead(2)==LOW){
    bTog=!bTog;
    digitalWrite(10,bTog);
    }
}
void loop(){
  
  digitalWrite(12,HIGH);
  delay(500);
  digitalWrite(12,LOW);
  delay(500);
  
}

