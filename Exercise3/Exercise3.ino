int switchState = 0;
void setup(){
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
}
void loop(){
  switchState = digitalRead(2);
  if(switchState==HIGH){
  digitalWrite(5, LOW);
  delay(3000);
  digitalWrite(5, HIGH);
}
}
