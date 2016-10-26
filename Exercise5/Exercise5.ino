int switchState = 0;
void setup(){
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(2,INPUT);
}
void loop(){
  switchState = digitalRead(2);
  if(switchState==1){
  for(int pinNumber=3; pinNumber<6;pinNumber++){
      digitalWrite(pinNumber, HIGH);
      delay(2000);
      digitalWrite(pinNumber, LOW);
      delay(2000);
 }
}
}
