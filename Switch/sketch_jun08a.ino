volatile bool bTog = false;
int bstate;
int t;
void setup() {
  // put your setup code here, to run once:
  pinMode(8,INPUT);
  pinMode(10,OUTPUT);
  pinMode(12,OUTPUT);
  Serial.begin(9600);
}

void swtch(){
  // put your main code here, to run repeatedly:
   bstate=digitalRead(8);
   Serial.println(bstate);
   //delay(500);
   

  if(bstate==LOW){
    bTog=!bTog;
    digitalWrite(10,bTog);
    }
}
void loop(){
  swtch();
  
}

