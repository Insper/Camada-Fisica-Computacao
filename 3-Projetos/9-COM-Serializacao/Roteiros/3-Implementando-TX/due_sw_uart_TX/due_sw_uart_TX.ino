#include "sw_uart.h"

due_sw_uart uart;

void setup() {
  sw_uart_setup(&uart, 19, 18, 1, 8, SW_UART_EVEN_PARITY);
}

void loop() {
 test_write();
}

void test_write() {
  sw_uart_write_string(&uart,"Cam-Fisica\n");
  delay(50);
}

void test_receive() {
}

