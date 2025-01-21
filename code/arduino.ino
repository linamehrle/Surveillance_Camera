#define stepPin 2
#define dirPin 5


int MOTION = 6;
int STATE = 0;

int MOTION2 = 4;
int STATE2 = 0;

int customDelay, customDelayMapped;

void setup()
{
  
  pinMode(MOTION, INPUT);
  pinMode(MOTION2, INPUT);
  Serial.begin(9600);

  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{

  STATE = digitalRead(MOTION);
  STATE2 = digitalRead(MOTION2);

  if (STATE == HIGH) //If Sensor1 = HIGH
  {
    Serial.println("sensor one");
    digitalWrite(dirPin, HIGH);
    for (int i = 0; i < 60; i++) { //turn quater
      digitalWrite(stepPin, HIGH);
      delayMicroseconds(2000);
      digitalWrite(stepPin, LOW);
      delayMicroseconds(2000);
    }
    delay(1000);
    
    takepicture();

    digitalWrite(dirPin, LOW); //change direction i guess?
    for (int i = 0; i < 60; i++) { //turn quater back
      digitalWrite(stepPin, HIGH);
      delayMicroseconds(2000);
      digitalWrite(stepPin, LOW);
      delayMicroseconds(2000);
    }
    delay(1000);
    Serial.println("finished sensor one");

  } if (STATE2 == HIGH) { //I Sensor2 = HIGH
    Serial.println("sensor two detected");
    digitalWrite(dirPin, LOW); //change direction i guess?
    for (int i = 0; i < 100; i++) { //turn quater
      digitalWrite(stepPin, HIGH);
      delayMicroseconds(2000);
      digitalWrite(stepPin, LOW);
      delayMicroseconds(2000);
    }
    delay(1000);

    takepicture();

    digitalWrite(dirPin, HIGH);
    for (int i = 0; i < 60; i++) { //turn quater back
      digitalWrite(stepPin, HIGH);
      delayMicroseconds(2000);
      digitalWrite(stepPin, LOW);
      delayMicroseconds(2000);
    }
    delay(1000);
    Serial.println("finished sensor two");
  }

}

void takepicture(){

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
