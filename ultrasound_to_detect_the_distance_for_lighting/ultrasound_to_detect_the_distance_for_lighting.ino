int trig=9;
int echo=10;

void setup() {
  // put your setup code here, to run once:
  
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(13,OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  
  // put your main code here, to run repeatedly:
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  long t=pulseIn(echo,HIGH);
  int d=(0.032*t)/2;
  Serial.println(d);
  if(d<20){
    digitalWrite(13,HIGH);
  }
  else{
    digitalWrite(13,LOW);
  }
  

}
