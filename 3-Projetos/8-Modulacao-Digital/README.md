---
title: Camada Física -  APS 8 - Modulação/Demodulação BPSK
author: Rafael Corsi - rafael.corsi@insper.edu.br
date: Outubro - 2017
---

![Interface entre módulos](./doc/diagrama.png){width=80%}

# APS 8 : Modulação/DeModulação BPSK

Esse projeto tem como objetivo o envio de mensagens de texto entre dois computadores via modulação digital em :

# Requisitos

A modulação/demodulação deve ser implementada no GNU Radio, um software em python deve emular um "chat" de uma única via, onde em um computador a mensagem é enviado e em outro a mensagem é recebida e exibida na tela. 

## Software

O software a ser disponível deverá utilizar como interface física um rádio criado a partir do GNURadio, a interface da aplicação com o GNURadio será via socket TCP/IP (tanto para transmissão dos dados quanto para recepção) conforme diagrama a seguir :

![Interface entre módulos](./doc/modulos.png)

### Pré requisitos: 

- Linux como sistema operacional, o GNURadio não opera corretamente no MAC e Windows.

- Instalar o GNURadio :
    - apt-get install gnuradio

- Instalar o netcat
    - apt-get install netcat
    

## Descrição 

1. transmissor.

     - Camada Física
         - Deve modular o sinal de áudio em BPSK
         - Deve abrir um "socket" e modular as mensagens digitais recebidas em BPSK via GNURadio
         - O sinal deve ser enviado via áudio
         - Deve possuir ajustes gráfico via GNURadio :
              - Símbolo por Sample (sps)
              - Frequência de transmissão
              - Volume
     - Camada Aplicação
         - Interface gráfica para envio de strings via socket.
2. Receptor
    - Camada Física
        - Deve demodular o sinal de áudio recebido em BPSK
        - Deve-se conectar a um socket e transmitir as mensagens digitais 
        
## Itens extras

O desenvolvimento de somente um dos itens extras será considerado como A.

- Fazer uma transmissão fullduplex (permitir os dois computadores enviar mensagens simultaneamente)
 
Ou 

- Implementar uma transmissão com mais de um símbolo (QPSK)

Ou

- Implementar algum tipo de correção de erro na mensagem enviada (CRC, ACK/NACK/ Paridade...)

## Validação

- Em sala de aula, abrir as duas aplicações em computadores distintos e transmitir uma frase entre eles via o pipeline desenvolvido anteriormente.

## Rubricas

| Nota | Descritivo                                                |
|------|-----------------------------------------------------------|
| A    | - Entregue no prazo                                       |
|      | - Implementado um item do extras                          |
| B    | - Entregue no prazo                                       |
|      | - Implementado requisitos necessários                     |
| C    | - Entregue fora do prazo                                  |
|      | - Implementando requisitos necessários                    |
| D    | - Nem todos os requisitos necessários foram implementados |
| I    | - Não entregue                                            |



