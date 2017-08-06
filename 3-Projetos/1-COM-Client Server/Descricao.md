---
title: Camada Física -  Client - Server : Requisitos
subtitlepage-note: Client Server
author: Rafael Corsi - rafael.corsi@insper.edu.br
date: 2017
---

# Projeto 

Essa etapa do projeto consiste na modificação da comunicação em modo loopback
para uma comunicação ponto a ponto entre dois computadores via a interface UART.
Como ilustrado no diagrama a seguir :

![Comunicação entre dois computadores](imgs/clientServer.pdf){ width=100% }

Para tanto será necessário modificar o exemplo original (localizado no repositório em : /3-Projetos/1-Comunicacao-Pnt-Pnt/) para passar a funcionar de uma comunicação em modo loopback para uma comunicação ponto a ponto entre dois computadores.

Ler a respeito do modo loopback em :

- dwdadawda


## Papeis

- Client : O papel do client nesse caso será o do envio de uma imagem para o server.
- Server : O papel do server será o da recepção de uma imagem enviada pelo
  client.
  
## Requisitos

1. Criar os papeis de Client e Servidor
1. Comunicar dois computadores distintos enviando um arquivo entre eles
1. Documentar o protocolo.

## Validação

- Conectar dois computadores via arduino e transmitir um arquivo de tamanho definido entre os dois nós.

# Avaliação :

## Itens necessários para o aceite
- Aplicação
    - Possui Client e Server como aplicações distintas
    - Client
        - Lê um arquivo do computador e o transmite via enlace.
        - Cálculo do tempo de transmissão
    - Server 
        - Lê um arquivo via enlace e salva no computador.
        - Cálculo do tempo de recepção 
- Documentação
    - Diagrama de funcionamento
    - Diagrama de camadas

## Itens extras

- Aplicação
    - Interface gráfica para seleção de imagem a ser lida e salva

## Rubricas

| Nota máxima | Descritivo                                           |
|-------------|------------------------------------------------------|
| A           | - Entregue no prazo                                  |
|             | - Implementado extras                                |
| B           | - Entregue no prazo                                  |
|             | - Implementado itens necessários                     |
| C           | - Entregue fora do prazo                             |
|             | - Implementando itens ncessários                     |
| D           | - Nem todos os itens necessários foram implementados |
| I           | - Não entregue                                       |



