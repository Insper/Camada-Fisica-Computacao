void setup() {
  Serial1.begin(9600,SERIAL_8O2);   
}

void loop() {
 test_write();
}

void test_write() {
    Serial1.write("Cam Fisica");
    delay(1);
}

void test_receive() {
}
