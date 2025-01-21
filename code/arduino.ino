#define stepPin 2
#define dirPin 5
#define motionPin1 6
#define motionPin2 4

int state1 = 0;
int state2 = 0;

void setup() {
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
  
  // Check for 2 seconds which sensor detects any movement 
  // We found this to work more reliably than only checking each sensor once
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

  if (state1 == HIGH && state2 == HIGH) {
    Serial.println("Both sensors");
    // Stay in the middle
    takePicture();
    
  } else if (state1 == HIGH) {
    Serial.println("Only Sensor 1");
    moveInDirection(1); // Move left
    takePicture();
    moveInDirection(0); // Move back
    
  } else if (state2 == HIGH) {
    Serial.println("Only Sensor 2");
    moveInDirection(0); // Move right
    takePicture();
    moveInDirection(1); // Move back
    
  }
  delay(500);
}

// direction: 0 for right, 1 for left
void moveInDirection(int dir) {
  digitalWrite(dirPin, dir);
  // Turn 60 steps
  for (int i = 0; i < 60; i++) {
      digitalWrite(stepPin, HIGH);
      delayMicroseconds(5000);
      digitalWrite(stepPin, LOW);
      delayMicroseconds(5000);
  }
  delay(1000);
}

void takePicture() {
    // Send high signal to ESP32-Cam and activate LED
    digitalWrite(7, HIGH);
    digitalWrite(LED_BUILTIN, HIGH);
    Serial.println("pin 7 HIGH");

    // Wait for picture to be taken
    delay(2000);

    // Deactivate signal again
    digitalWrite(7,LOW);
    Serial.println("pin 7 LOW");
    digitalWrite(LED_BUILTIN, LOW);
    delay(1000);
}
