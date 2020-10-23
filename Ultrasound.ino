#define TRIG_PIN 3
#define ECHO_PIN 2

float getDistance()
{
  long duration, distanceCm;
   
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  
  duration = pulseIn(ECHO_PIN, HIGH);
 
  // convert to distance
  distanceCm = duration / 29.1 / 2;
  
  return distanceCm;
}

void setup() {  
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

void loop() {
  long distance = getDistance();
  Serial.println(distance);
  delay(1000);
}
