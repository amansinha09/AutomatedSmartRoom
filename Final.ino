#include <dht.h>
#define DHT11_PIN 3

dht DHT;
int x,lvl;
int t=0;
int doorPin1=12;
int doorPin2=13;
int ldrpin=0;
int pirsense=7;
int pirPin=0;
int c=0;
void sleep()
{
  t++;
  Serial.println(t);
}
void lightsoff()
{
  analogWrite(6,LOW); analogWrite(9,LOW);analogWrite(10,LOW);analogWrite(11,LOW);
}
void temp()
{
   int chk = DHT.read11(DHT11_PIN);
  float temp = DHT.temperature;
  float hum=DHT.humidity;
  Serial.print("Temperature = ");
  Serial.println(temp);
  Serial.print("Humidity = ");
  Serial.println(hum);
  if(hum>40)digitalWrite(5,HIGH);
  else digitalWrite(5,LOW);  
}
void lights()
{
   x=analogRead(ldrpin);
 x=constrain(x,110,560);
  int level=map(x,110,560,255,5);
  if(x<640)
  {
    analogWrite(6,level);
    analogWrite(9,level);
    analogWrite(10,level);
    analogWrite(11,level);
   }
}
void setup() {
  Serial.begin(9600);
 pinMode(6,OUTPUT);
pinMode(9,OUTPUT);
pinMode(10,OUTPUT);
pinMode(11,OUTPUT);
pinMode(doorPin1,INPUT);
pinMode(doorPin2,INPUT);
  pinMode(3,INPUT);
  pinMode(5,OUTPUT);
  }

void loop() 
{
  
  int a=digitalRead(doorPin1), b=digitalRead(doorPin2);
  if(a==1 || c>=0)
  {
    if(a!=0)
    c++;
    if(c>=1)
    {
      lights();
      sleep();
      temp();
     delay(500);
    } 
  }
  if(digitalRead(pirsense)==1)t=0;
  if (t==50) {
  Serial.println(t);
  
  if(t==50)t=0;
  while(1)
  {
     a=digitalRead(doorPin1), b=digitalRead(doorPin2);
      if(a==1 || c>=0)
  {
    if(a!=0)
    c++;
  }
     
    lightsoff();
    if(digitalRead(pirsense)==1)break; 
  }
  }
  
   if(b==1)
  {
    c--;
    if(c<0){
      c=0;
      lightsoff();
    }
  }
  
  Serial.print("Number of people inside the room:");
  Serial.println(c);
}


