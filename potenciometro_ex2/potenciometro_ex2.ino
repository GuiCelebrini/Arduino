int pwmLedPin = 17;
int sensorPin = 15;
int sensorValue = 0;

const int channel = 0;
const int freq = 5000;
const int resolution = 8;

void setup() {
  Serial.begin(9600);

  ledcSetup(channel, freq, resolution);
  ledcAttachPin(pwmLedPin, channel);

  delay(500);
}

void loop() {

  sensorValue = analogRead(sensorPin);
  Serial.println(sensorValue);

  //int outputValue = (sensorValue/16)-1;
  int outputValue = map(sensorValue, 0, 4095, 0, 255);
  Serial.println(outputValue);

  //ledcWrite(channel, outputValue);
  analogWrite(pwmLedPin, outputValue);

  /*digitalWrite(ledPin, HIGH);
  delay(sensorValue);
  digitalWrite(ledPin, LOW);
  delay(sensorValue);*/

}
