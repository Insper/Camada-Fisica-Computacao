// stores received byte

void setup() {
  Serial.begin(115200);   
  Serial1.begin(9600,SERIAL_8O2);   
}

void loop() {
 test_receive();
}

void test_write() {
}

void test_receive() {
  byte rx_byte = 0;        
  if (Serial1.available()){
    rx_byte = Serial1.read();
    Serial.write(rx_byte);
  }           
}
