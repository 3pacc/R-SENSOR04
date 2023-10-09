#define echo 2
#define trig 3

#define LED8 13
#define LED7 12
#define LED6 11
#define LED5 10
#define LED4 7
#define LED3 6
#define LED2 5
#define LED1 4
#define BUZZER 9

float   duration;
float   distance;

void setup() {

  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

  for (int i = 4; i <= 11; i++)
    pinMode(i, OUTPUT);


  Serial.begin(9600);

}

void loop() {

  time_Measurement();
  distance = duration * (0.0343) / 2;
  Serial.println(distance);

  led_Check();
  delay(10);

  for (int i = LED1; i <= LED8; i++) {
    digitalWrite(i, LOW);
  }
}


void time_Measurement()
{
  digitalWrite(trig, LOW);
  delayMicroseconds(2);

  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  duration = pulseIn(echo, HIGH);
}

void led_Check() {

  if (90 < distance && distance <= 100) {
    digitalWrite(LED8, HIGH);
    analogWrite(9, 250);
  }
  else if (80 < distance && distance <= 90) {
    digitalWrite(LED7, HIGH);
    analogWrite(9, 225);
  }
  else if (70 < distance && distance <= 80) {
    digitalWrite(LED6, HIGH);
    analogWrite(9, 200);
  }
  else if (60 < distance && distance <= 70) {
    digitalWrite(LED5, HIGH);
    analogWrite(9, 150);
  }
  else if (50 < distance && distance <= 60) {
    digitalWrite(LED4, HIGH);
    analogWrite(9, 125);
  }
  else if (40 < distance && distance <= 50) {
    digitalWrite(LED3, HIGH);
    analogWrite(9, 100);
  }
  else if (30 < distance && distance <= 40) {
    digitalWrite(LED2, HIGH);
    analogWrite(9, 75);
  }
  else if (0 < distance && distance <= 30) {
    digitalWrite(LED1, HIGH);
    analogWrite(9, 50);
  }

  else {
    for (int i = LED1; i <= LED8; i++)
      digitalWrite(i, LOW);
    analogWrite(9, 0);
  }

}

