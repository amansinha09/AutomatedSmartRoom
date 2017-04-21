int a;
void setup() {

pinMode(7,INPUT);
pinMode(4,OUTPUT);


Serial.begin(9600);
}

void loop() {
 
  a=digitalRead(7);
  if(a==1)
  digitalWrite(4,HIGH);
  else
  digitalWrite(4,LOW);
  
} 
