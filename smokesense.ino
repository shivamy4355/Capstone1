
int buzzer = 11;
int smokeA0 = A0;

// Your threshold value. You might need to change it.
int sensorThres = 10;

void setup() {
  pinMode(buzzer, OUTPUT);
  pinMode(smokeA0, INPUT);
  Serial.begin(9600);
  Serial.println("CLEARDATA");
  Serial.println("Smoke value start from 320");
  Serial.println("RESETTIMER");
}

void loop() {
  int analogSensor = analogRead(smokeA0);

  Serial.print("Smoke value is: ");
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
}
