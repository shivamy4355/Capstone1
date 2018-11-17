#include <dht.h>
#define dht_apin A1


dht DHT;

void setup(){
  Serial.begin(9600);
  delay(500);
  Serial.println("DHT11 Humidity & Temperature Sensor\n\n");
  delay(1000);
}


void loop()
{
   DHT.read11(dht_apin);
   Serial.print("Current Humidity =");
  Serial.print(DHT.humidity);
  Serial.print("%\n ");
  Serial.print("Temperature =");
  Serial.print(DHT.temperature);
  Serial.print("C ");
  delay(5000);
}
