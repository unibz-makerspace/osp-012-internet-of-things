int switchState = 0;
void setup(){
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(2,INPUT);
}

void loop(){
  digitalWrite(5, HIGH);
  switchState = digitalRead(2);
  if(switchState==1){
  digitalWrite(5, LOW);
  delay(3000);
}

}
