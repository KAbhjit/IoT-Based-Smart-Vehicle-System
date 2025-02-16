const int drowsinessInputPin = 5;      // Pin to receive drowsiness signal from IR sensor
const int buzzerPin = 11;              // Pin to control buzzer
const int enginePin = 6;               // Pin to control DC motor (engine)

// Time for alerts (in milliseconds)
const int alertDuration = 2000;        // Duration for buzzer and engine lock

void setup() {
  Serial.begin(9600);                  // Initialize serial communication
  pinMode(drowsinessInputPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(enginePin, OUTPUT);

  // Start with buzzer and engine running
  digitalWrite(buzzerPin, LOW);
  digitalWrite(enginePin, HIGH);       // Assume HIGH keeps engine running
}

void loop() {
  // Check if drowsiness is detected via IR sensor
  if (digitalRead(drowsinessInputPin) == HIGH) {
    Serial.println("Drowsiness Detected - Activating buzzer and locking engine...");
    
    // Activate buzzer and stop the engine
    digitalWrite(buzzerPin, HIGH);     // Turn on buzzer
    digitalWrite(enginePin, LOW);      // Stop engine
    delay(alertDuration);              // Run for alert duration

    // Deactivate buzzer and restart the engine
    digitalWrite(buzzerPin, LOW);      // Turn off buzzer
    digitalWrite(enginePin, HIGH);     // Restart engine
  }

  delay(100);  // Small delay to stabilize readings
}
