int switchState = 0;
void setup(){
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
}
void loop(){
//  switchState = digitalRead(2);
//  if(switchState==HIGH){
  for(int pinNumber=2; pinNumber<6;pinNumber++){
      digitalWrite(pinNumber, HIGH);
      delay(2000);
      digitalWrite(pinNumber, LOW);
      delay(2000);
//  }
}
}
