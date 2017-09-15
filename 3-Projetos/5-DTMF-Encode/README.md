---
title: Camada Física -  APS 5 - DTMF - Encoder e recepção
author: Rafael Corsi - rafael.corsi@insper.edu.br
date: Setembro - 2017
---

![DTMF](doc/sistema.png)

*Entrega : Até o começo da aula do dia 21/9*

# Novas Duplas

Favor preencher o form com informações das novas duplas :

**Um novo repositório deve ser criado !!!**
 - https://goo.gl/forms/hE9Aow318dYQtO5u1


# APS 5 : DTMF - Encoder e recepção.

Implementar a codificação dos números 0,1,..9 em código DTMF, transmitir o sinal pelo falante de um computador e fazer o recebimento do áudio em outro computador. Não é necessário implementar a decodificação.

- [Lista aula 9 ](https://github.com/Insper/Camada-Fisica-Computacao/blob/master/2-Aulas/9-DTMF/9-Lista-DTMF.pdf)

## Dicas

Algumas dicas de implementação podem ser lidas em : 
 
- [Dicas](https://github.com/Insper/Camada-Fisica-Computacao/blob/master/3-Projetos/5-DTMF-Encode/5-DTMF-Dicas-Encoder.md)

# Requisitos

Requisitos de projeto :

1. encoderDTMF.py
    - Geração dos tons
        - Gerar os tons DTMF para cada um dos símbolos (0,1,..9)
        - Para cada símbolo plotar os sinais gerados (no tempo)

1. decoderDTMF.py
    - Recepção de áudio
        - Deve receber um áudio pelo microfone
        - A cada 1 segundo plotar o sinal recebido pelo microfone.
    - Tons
        - Receber cada um dos tons (1 segundo) e salvar os sinais para uso futuro.
    
1. Documentação
    - Descrever a geração dos tons
    - Descrever as frequências que compõem cada tom
    - Plotar e comentar os gráficos de cada tom com o do gerado e recebido.
    
## Itens extras

1. Interface gráfica para transmitir os tons
1. Exibir a transformada de Fourier dos sinais (transmitido e recuperado)

## Validação

- Gerar os tons e validar com um aplicativo no celular.
- Reproduzir o sinal salvo dos tons.

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



