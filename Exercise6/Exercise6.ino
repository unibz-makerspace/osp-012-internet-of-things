int switchState = 0;
void setup(){
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(2,INPUT);
}
void loop(){
//  switchState = digitalRead(2);
//  if(switchState==HIGH){
  for(int pinNumber=3; pinNumber<6;pinNumber++){
      digitalWrite(pinNumber, HIGH);
      delay(1000);
      digitalWrite(pinNumber+1, HIGH);
      delay(1000);
      digitalWrite(pinNumber+2, HIGH);
       delay(1000);
}
for(int pinNumber=2; pinNumber<6;pinNumber++){
      digitalWrite(pinNumber+3, LOW);
      delay(1000);
      digitalWrite(pinNumber+2, LOW);
      delay(1000);
      digitalWrite(pinNumber+1, LOW);
      delay(1000);
}
}
