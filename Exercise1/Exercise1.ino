
int switchState = 0;
void setup(){
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(2,INPUT);
}
void loop(){
  switchState = digitalRead(2);
  digitalWrite(5,HIGH);
}
