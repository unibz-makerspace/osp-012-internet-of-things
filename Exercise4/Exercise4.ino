int switchState = LOW;
void setup(){
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
}

void loop(){
  digitalWrite(5, HIGH);
  switchState = digitalRead(2);
  if(switchState==HIGH){
  digitalWrite(5, LOW);
  delay(3000);
}

}
