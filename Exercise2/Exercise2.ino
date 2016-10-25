
void setup(){
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
}
void loop(){
  digitalWrite(5,HIGH);
  delay(400);
  digitalWrite(5, LOW);
  delay(400);
  digitalWrite(5, HIGH);
}
