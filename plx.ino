#include <dht.h>
#define dht_apin A1
dht DHT;
int buzzer = 11;
int smokeA0 = A0;

// Your threshold value. You might need to change it.
int sensorThres = 320;
void setup() 
{
  
  pinMode(buzzer, OUTPUT);
  pinMode(smokeA0, INPUT);
  Serial.begin(9600);
 Serial.println("CLEARDATA");//clear excel sheet
  delay(500);
  Serial.println("DHT11 Humidity & Temperature Sensor\n\n");
  delay(1000);
 Serial.println("LABEL,current Time,Temperature,humidity,smoke");//label for ms-excel
}
void loop()
{
  int analogSensor = analogRead(smokeA0);

  Serial.print("Smoke Value ");
  Serial.println(analogSensor);
  // Checks if it has reached the threshold value
  if (analogSensor > sensorThres)
  {
    tone(buzzer, 1000, 200);
    
  }
  else
  {
    noTone(buzzer);
  }
  delay(100);

Serial.print("DATA,TIME,");
Serial.print(DHT.temperature);//random number generator from 0 to 100
Serial.print(",");//print "," for different value
Serial.println(DHT.humidity);
Serial.println(analogSensor);
delay(500);


 DHT.read11(dht_apin);
 
  Serial.println("Current Humidity =");
  Serial.print(DHT.humidity);
  Serial.print("%\n ");
  Serial.print("Temperature =");
  Serial.println(DHT.temperature);
 //Serial.print("C ");
 delay(5000);
}
