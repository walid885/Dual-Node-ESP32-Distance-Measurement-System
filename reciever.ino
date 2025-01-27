#define RXD2 16
#define TXD2 17
HardwareSerial SerialPort(2);
void setup() {
  Serial.begin(115200);  // PC Serial
  SerialPort.begin(9600, SERIAL_8N1, RXD2, TXD2);  // UART communication
  
  Serial.println("Receiver Node Initialized");
}
void loop() {
  // Check for incoming UART data
  if (SerialPort.available()) {
    String receivedData = SerialPort.readStringUntil('\n');
    
    // Display on Serial Monitor
    Serial.print("Received Distance: ");
    Serial.println(receivedData);
  }
}
