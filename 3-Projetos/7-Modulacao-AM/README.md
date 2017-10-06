---
title: Camada Física -  APS 7 - Modulação/Demodulação AM
author: Rafael Corsi - rafael.corsi@insper.edu.br
date: Outubro - 2017
---

![](./doc/com.png)

# APS 7 : Modulação/DeModulação AM

Transmitir dois sinais de áudio em amplitude modulada via falante do computador, recuperar o sinal transmitido e decodificar os dois sinais de áudio.

## Dicas

Algumas dicas de implementação podem ser lidas em : 
 
- [Dicas](https://github.com/Insper/Camada-Fisica-Computacao/blob/master/3-Projetos/6-DTMF-Decoder/6-DTMF-Dicas-Decoder.pdf)

# Requisitos

Requisitos de projeto :

Você deve ter implementar a modulação e demodulação, não deve utilizar nessas etapas nenhum módulo. Dois códigos devem ser responsáveis por modular e demodular uma mensagem.

1. transmissor.py
 
 Responsável por ler e modular dois sinais de áudio.
 
    - Mensagem :
        - ler dois arquivos .wav, essas serão as mensagens (m1(t), m2(t)) a serem transmitidas.
    - Portadoras :
        - receber como parâmetro as frequências das portadoras (f1, f2)
    - Modulação :
        - modular em AM (ou FM) as mensagens m1 e m2 nas frequências f1 e f2
    - Transmissão :
        - transmitir o sinal modulado em áudio resultante de m1,f1 e m2,f2
    - Exibir :
        - os sinais (mensagens) a serem transmitidas no tempo
        - os Fourier dos sinais (frequência)
        - as portadoras no tempo
        - as mensagens moduladas no tempo
        - os Fourier das mensagens moduladas (frequência)
        
2. receptor.py

 Responsável por demodular e salvar dois sinais de áudio.

    - Portadoras :
        - receber como parâmetro as frequências das portadoras (f1, f2)
    - Sinal :
        - receber via microfone o sinal (y(t)) transmitido pelo computador com o transmissor.
    - Demodulação :
        - demodular o sinal AM (ou FM) recebido em :
            - m1 e m2
    - Mensagens
        - salvar as mensagens m1 e m2 em arquivos wav
        - reproduzir os sons recuperados.
    - Exibir :
        - o sinal y(t) no tempo
        - o sinal y(t) na frequência
        - os sinais (mensagens) recuperados (no tempo)
        - os sinais (mensagens) recuperados (na frequência)
        
1. Documentação
    
    - Descrever a modulação/ demodulação 
    - Descrever as frequências das portadoras utilizadas
    - Descrever as bandas ocupadas
    - Inserir ao menos um gráfico exemplo de cada item de exibição do :
         - transmissor
         - receptor
    - Comparar o resultado dos áudios transmitidos vs recebidos 
    
## Itens extras

1. Utilizar modulação FM

## Validação

  - Transmitir em sala de aula dois áudios e recuperar o mesmo em outro computador.


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



