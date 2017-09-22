---
title: Camada Física -  APS 6 - DTMF - Decodificação
author: Rafael Corsi - rafael.corsi@insper.edu.br
date: Setembro - 2017
---

![DTMF](doc/sistema.png)

*Entrega : Até o começo da aula do dia 05/10*

# APS 6 : DTMF - Decodificação

Implementar a decodificação do sinal de áudio recebido pelo computador para identificar o símbolo DTMF codificado.

## Dicas

Algumas dicas de implementação podem ser lidas em : 
 
- [Dicas](https://github.com/Insper/Camada-Fisica-Computacao/blob/master/3-Projetos/6-DTMF-Decoder/6-DTMF-Dicas-Decoder.pdf)

# Requisitos

Requisitos de projeto :

1. decoderDTMF.py
    - Exibição 
        - Plotar o sinal recebido no tempo (a cada x segundos)
        - Plotar a transformada de Fourier do sinal recebido (a cada x segundos)
             - Eixo y em dB (decibel)
             - Eixo x em Hz
    - Decodificação
        - Dois modos de operação :
             - Carrega arquivo pré gravado
             - Modo on-the-fly, atualiza a cada x segundos.
        - Receber um sinal de áudio e identificar o tom nele contido (se existir)
        - Exibir um log das frequências principais que compõem o sinal recebido.
            - (mesmo que não tiver tom algum)
            
1. Documentação
    - Exibir o Fourier do sinal transmitido (original)
    - Exibir o Fourier do sinal recebido
    - Registrar as frequências recebidas e a enviadas de cada tom (divergências)
    - Justificar os tempos utilizados (geração e recepção dos sinais)
    
## Itens extras

1. Transmitir mais de um símbolo por vez.

## Validação

- Detectar os símbolos gerados por computador (outra dupla)

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



