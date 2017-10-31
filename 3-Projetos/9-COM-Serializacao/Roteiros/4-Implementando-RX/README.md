---
title: Camada Física -  APS 9 - Roteiro 3 - Implementando a recepção
author: Rafael Corsi - rafael.corsi@insper.edu.br
date: Outubro - 2017
---

# Transmissão 

Utilizando a estrutura de código disponível em : due_sw_uart_rx implemente um código que realiza a recepção dos dados da serial 1 a uma taxa de 9600 bits por segundo.

O projeto no arduino possui os seguintes arquivos :

 - due_sw_uart_RX.ino : arquivo principal do arduino
 - sw_uart.cpp : código em c++ a ser implementando a transmissão
 - sw_uart.h : cabeçalho C com diversas definições para o módulo sw_uart.cpp

As funções que devem ser implementadas nessa etapa são :

(já deve estar pronta da etapa anterior)
```
// Funcao para calcular paridade impar
// retorna paridade
int calc_even_parity(char data) {
  
}
```

```
// recebimento de dados da serial
int sw_uart_receive_byte(due_sw_uart *uart, char* data) {

  // variavel para recebimento de dados
  char nchar  = 0;
  
  // variavel para calculo da paridade
  char parity, rx_parity;
  
  // aguarda start bit

  // Confirma start BIT
  
  // checa se bit ainda é 0
  
  // recebe dados

  // recebe paridade

  // recebe stop bit
  
  // checa paridade
  if(parity != rx_parity) {
    return SW_UART_ERROR_PARITY;
  }
  
  *data = nchar;
  return SW_UART_SUCCESS;
}
```
