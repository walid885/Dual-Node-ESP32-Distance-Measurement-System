#define TRIG_PIN 5
#define ECHO_PIN 18

// UART Communication Pins
#define RXD2 16
#define TXD2 17
HardwareSerial SerialPort(2);  // Use UART2
float measureDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  
  long duration = pulseIn(ECHO_PIN, HIGH);
  float distance = duration * 0.034 / 2;
  
  // Validate distance reading
  if (distance < 0 || distance > 400) {
    return -1;
  }
  
  return distance;
}
void setup() {
  Serial.begin(115200);  // Debug serial
  SerialPort.begin(9600, SERIAL_8N1, RXD2, TXD2);  // UART communication
  
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  
  Serial.println("Sensor Node Initialized");
}
void loop() {
  float distance = measureDistance();
  
  if (distance >= 0) {
    // Send distance via UART
    SerialPort.print(distance);
    SerialPort.println(" cm");
    
    Serial.print("Sent Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
  }
  
  delay(1000);
}
