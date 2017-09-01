---
title: Camada Física -  Projeto 4 - Fragmentação e Detecção de Erros
author: Rafael Corsi - rafael.corsi@insper.edu.br
date: Agosto - 2017
---

*Entrega : Até o começo da aula do dia 07/9*

![Etapa Atual](doc/etapaAtualPilhaEnlace.png){ width=30% }

# Índice

- [1- COM - Client Server](https://github.com/Insper/Camada-Fisica-Computacao/tree/master/3-Projetos/1-COM-Client%20Server)
- [2- COM - Datagrama](https://github.com/Insper/Camada-Fisica-Computacao/tree/master/3-Projetos/2-COM-Datagrama)
- [3- COM - HandShake Ack e NACk](https://github.com/Insper/Camada-Fisica-Computacao/tree/master/3-Projetos/3-COM-HandShake-ACK-nACK)
- [4- COM - Fragmentação e Deteçao de erros](https://github.com/Insper/Camada-Fisica-Computacao/tree/master/3-Projetos/4-COM-Fragmentacao-CheckSum)
    - **README**
    - Dicas

# Projeto 4 : Fragmentamcão e Detecção de Erros

Implementar a fragmentação dos dados na camada de enlace para possibilitar o reenvio mais eficiente caso algum erro nos dados for detectado. Para a deteção de erros na transmissão, adicione um CRC ao HEAD e outro ao Payload, enviando um ACK/NACK em resposta se o pacote foi recebido corretamente ou não.

- [Lista aula 7 ](https://github.com/Insper/Camada-Fisica-Computacao/blob/master/2-Aulas/7-Fragmentacao/7-Lista-Fragmentacao.pdf)

- [Lista aula 8 ](https://github.com/Insper/Camada-Fisica-Computacao/blob/master/2-Aulas/8-Deteccao-De-Erros/8-Lista-Deteccao.pdf)

- [Dicas de implementação](https://github.com/Insper/Camada-Fisica-Computacao/blob/master/3-Projetos/4-COM-Fragmentacao-CheckSum/04-COM-Dicas-Fragmentacao-CheckSum.md)
  
# Requisitos

Requisitos de projeto :

1. Fragmentação 
    - O envio de um payload deve ser fragmentado em pacotes com no **máximo 2048 bytes**.
        - (configurar esse valor na inicialização do enlace)
    - O fragmento deve ser reconstruido pela camada de enlace
    - Cada fragmento enviado deve vir acompanhado de uma resposta : ACK e NACK
    - A fragmentação/ desfragmentação deve ser transparente para a aplicação
    
    1. Retransmissão
        - Caso o transmissor receba um NACK deve reenviar o pacote.
        - Caso o transmissor não receba uma resposta em x segundos (timeout) deve reenviar o pacote.
    
1. Detecção de erros
    - Pacote :
        - Implementar um CRC para o HEAD
        - Implementar um CRC para o payload
    - Recebimento :
        - Todo pacote recebido deve ser verificado :
             - Se o tamanho do payload confere com o tamanho enviado no HEAD
             - Se o CRC do head calculado confere com o CRC enviado no HEAD
             - Se o CRC do payload calculado confere com o CRC enviado para o payload
        - Se houver falha em algum dos casos anteriores, responder com o NACK e aguardar o reenvio do pacote.
        
1. Software
    - A enlace (recepção E transmissão) deve imprimir na tela algo parecido como :
    
```
(Envio)
Enviando 6170 bytes em 4 pacotes :
    - pacote 1/4 : 2048 bytes
      - ACK (ok)
    - pacote 2/4 : 2048 bytes
      - ACK (ok)
    - pacote 3/4 : 2048 bytes
      - NACK (falha)
    - pacote 3/4 : 2048
      - ACK (ok)
    - pacote 4/4 : 26 bytes
      - TimeOut (falha)
    - pacote 4/4 : 26 bytes
      - ACK (ok)
Final da transmissão
```

1. Documentação
    - Descrever a framentação 
    - Descrever os campos do HEAD
    - Descrever o tempo de timeout utilizado (e o porque desse valor).
    - Explicar qual polinómio foi utilizado para o CRC.
    
## Itens extras

1. Implementar o Go-Back-N
1. Fazer a implementação própria do CRC

## Validação

- Inicializar o Client e não conectar o Server. Nenhuma imagem deve ser enviada.
- Após algum tempo inicializar o Server, deve acontecer o handshake e a transferência deve ser executada.
- Durante a transmissão, desconectar o fio que transmite dados entre Client e Server
    - Server deve responder com nACK
    - Client deve retransmitir o pacote.

## Rubricas

| Nota máxima | Descritivo                                                |
|-------------|-----------------------------------------------------------|
| A           | - Entregue no prazo                                       |
|             | - Implementado extras                                     |
| B           | - Entregue no prazo                                       |
|             | - Implementado requisitos necessários                     |
| C           | - Entregue fora do prazo                                  |
|             | - Implementando requisitos necessários                    |
| D           | - Nem todos os requisitos necessários foram implementados |
| I           | - Não entregue                                            |



