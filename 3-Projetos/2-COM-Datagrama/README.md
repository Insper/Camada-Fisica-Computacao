---
title: Camada Física -  Projeto 2 - COM-Datagrama 
author: Rafael Corsi - rafael.corsi@insper.edu.br
date: 2017
---

*Entrega : Até o começo da aula do dia 24/8*

![Etapa Atual](doc/etapaAtualPilhaEnlace.png){ width=30% }

# Projeto 2 : Datagrama

Essa etapa do projeto consiste na criação de um protocolo de comunicação entre o client e o server, para isso, deveremos agora encapsular os dados em um pacote (ou datagrama) que carregará os dados a serem transmitidos. Com esse datagrama será possível o envio de imagens sem o conhecimento prévio do tamanho entre os nós.

Para isso, será necessário agora modificarmos a camada de enlace, ela será responsável pelo encapsulamento e desencapsulamento dos dados. Para as aplicações essa manipulação deve ser transparente (ela não deve participar). Para um melhor entendimento ler o estudo dirigido da aula 3 :

- [Lista aula 3]

## Dicas

Algumas dicas de implementação podem ser lidas em : 
 
- [Dicas]()
  
# Requisitos

Requisitos de projeto :

1. O pacote deve possuir
    - HEAD
    - EOP
1. O HEAD deve possuir o tamanho total da carga útil
1. As aplicações client e server devem compartilhar a mesma implementação do enlace/ fisica.
1. Documentar o protocolo
    - HEAD e EOP utilizados
         - "desenhar pacote"
         - Quantidade de bytes para cada parte do HEAD e EOP
    - Cálculo do Overhead 
    - Cálculo do tempo teórico de transmissão de uma imagem qualquer
    - Cálculo do Troughput
1. Encapsular o dado (imagem) a ser transmitida em um pacote

## Itens extras

1. O server deve fazer a verificação da quantidade de dados que chegou com o enviado pelo HEAD, um log deve ser gerado.
1. Fragmentar o pacote em n pacotes menores.

## Validação

- Conectar os dois computadores e transmitir entre o Client e o Server uma imagem de tamanho desconhecida do Server. Essa imagem deve estar encapsulada em um protocolo.

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



