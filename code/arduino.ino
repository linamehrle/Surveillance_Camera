#define stepPin 2
#define dirPin 5
#define motionPin1 6
#define motionPin2 4

int state1 = 0;
int state2 = 0;

int customDelay, customDelayMapped;

void setup()
{
  
  pinMode(motionPin1, INPUT);
  pinMode(motionPin2, INPUT);
  Serial.begin(9600);

  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  state1 = 0;
  state2 = 0;
  Serial.println("Detection started");
  for (int i = 0; i < 200; i++) {
    if (digitalRead(motionPin1) == HIGH) {
      state1 = 1;
    }
    if (digitalRead(motionPin2) == HIGH) {
      state2 = 1;
    }
    delay(10);
  }
  Serial.println("Detection ended");

  if (state1 == HIGH && state2 == HIGH) {// Movement in the middle
    Serial.println("Both sensors");
    takePicture();
  } else if (state1 == HIGH) {
    Serial.println("Only Sensor 1");
    moveInDirection(1);
    takePicture();
    moveInDirection(0);
  } else if (state2 == HIGH) {
    Serial.println("Only Sensor 2");
    moveInDirection(0);
    takePicture();
    moveInDirection(1);
  }
  delay(500);
}

void moveInDirection(int dir) {
  digitalWrite(dirPin, dir);
  for (int i = 0; i < 60; i++) { //turn quater
      digitalWrite(stepPin, HIGH);
      delayMicroseconds(5000);
      digitalWrite(stepPin, LOW);
      delayMicroseconds(5000);
  }
  delay(1000);
}

void takePicture() {
   //take picture
    digitalWrite(7, HIGH);
    digitalWrite(LED_BUILTIN, HIGH);
    Serial.println("pin 7 HIGH");
    delay(2000);
    digitalWrite(7,LOW);
    Serial.println("pin 7 LOW");
    digitalWrite(LED_BUILTIN, LOW);

    delay(1000);
}
