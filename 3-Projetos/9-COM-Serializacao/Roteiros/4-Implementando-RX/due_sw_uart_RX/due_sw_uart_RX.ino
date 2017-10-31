#include "sw_uart.h"

due_sw_uart uart;

void setup() {
  sw_uart_setup(&uart, 19, 18, 1, 8, SW_UART_EVEN_PARITY);
}

void loop() {
 test_write();
}

void test_write() {
  sw_uart_write_string(&uart,"camFisica\n");
  delay(50);
}

void test_receive() {
  char data;
  int code = sw_uart_receive_byte(&uart, &data);
  if(code == SW_UART_SUCCESS) {
     Serial.print(data);
  } else if(code == SW_UART_ERROR_PARITY) {
    Serial.println("PARITY ERROR");
  } else {
    Serial.println("OTHER");
    Serial.print(code);
  }
}

