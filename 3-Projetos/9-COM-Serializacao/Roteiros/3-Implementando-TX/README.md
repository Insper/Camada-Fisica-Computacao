---
title: Camada Física -  APS 9 - Roteiro 3 - Implementando a trasmissão
author: Rafael Corsi - rafael.corsi@insper.edu.br
date: Outubro - 2017
---

# Transmissão 

Utilizando a estrutura de código disponível em : due_sw_uart_tx implemente um código que realiza a transmissão dos dados da serial 1 a uma taxa de 9600 bits por segundo.

O projeto no arduino possui os seguintes arquivos :

 - due_sw_uart_TX.ino : arquivo principal do arduino
 - sw_uart.cpp : código em c++ a ser implementando a transmissão
 - sw_uart.h : cabeçalho C com diversas definições para o módulo sw_uart.cpp

As funções que devem ser implementadas nessa etapa são :

```
// Funcao para calcular paridade impar
// retorna paridade
int calc_even_parity(char data) {
  
}
```

```
// Funcao para enviar um char (data 8 bits) via uart
void sw_uart_write_byte(due_sw_uart *uart, char data) {
  
  // variável para armazenar paridade
  int parity = 0;

  // atualiza valor da paridade
  if(uart->paritybit == SW_UART_EVEN_PARITY) {
     parity = calc_even_parity(data);
  } else if(uart->paritybit == SW_UART_ODD_PARITY) {
     parity = !calc_even_parity(data);
  }
  
  // envia start bit
  _sw_uart_wait_T(uart);
  
  // envia payload
  for(int i = 0; i < uart->databits; i++) {
    // ....
    _sw_uart_wait_T(uart);
  }

  // envia paridade, se existir
  if(uart->paritybit != SW_UART_NO_PARITY) {
   // ...
  }
  
  // envia stop bit, se existir
  for(int i = 0; i < uart->stopbits; i++) {
       // ...
  } 
}
```
