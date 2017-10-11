---
title: Camada Física -  Dicas APS 5 - DTMF - Encode
author: Rafael Corsi - rafael.corsi@insper.edu.br
date: 2017
---

# Dicas de implementação :

A seguir algumas dicas para a implementação do projeto 7 - Modulação

- https://epxx.co/artigos/ammodulation.html

## Ordem de execução :

1. Modulação
    - Importe os áudios m1(t) e m2(t)
    - Aplique o filtro passa baixas, que resultará em dois novos sinais:
         - m1F(t) e m2F(t)
         - Defina a frequÊncia de corte do filtro.
         - Exiba o Fourier dos sinais 
         - Reproduza o áudio (teve perda ?)
     - Portadora
         - Defina as frequências das portadoras :
              - fc1 e fc2
         - Gere as portadoras c1(t) e c2(t)
              - o sinal gerado deve ter o mesmo comprimento de m1(t) e m2(t)
         - Exiba o Fourier dos sinais
    - Modulação
         - Module as mensagens com as portadora, resultando em am1(t) e am2(t)
              - Exiba o Fourier dos sinais
              - Reproduza os áudios individuais
    - Soma
         - Some os sinais modulados am1(t) e am2(t)
              - Exiba o Fourier resultante da soma
                
     - Transmissão :
          - Reproduza sinal resultante
         
2. Demodulação
     - Grave o áudio da transmissão
         - Exiba o Fourier do sinal recebido
     - Reconstrua as duas portadoras originais
     - Demodule um sinal por vez 
          - A demodulação é feita pela multiplicação do sinal com a portadora
          - resultando em : m1'(t) e m2'(t)
              - Exiba o Fourier dos sinais
     - Filtro
          - Aplique o filtro passa baixas de mesma frequência de corte nas mensagens m1'(t) e m2'(t), resultando em :
               - m1(t) e m2(t)
               - Exiba o Fourier dos sinais
               - reproduza os sinais
     - Salvar
          - Salve os sinais recuperados, qual a qualidade do áudio ?
          
## Filtro passa baixas 

A função a seguir aplica um filtro passa baixas de frequência de corte : *cutoff_hz* e frequência de amostragem *fs* no sinal *signal* passado. 

```
from scipy import signal as sg

def LPF(signal, cutoff_hz, fs):
        #####################
        # Filtro
        #####################
        # https://scipy.github.io/old-wiki/pages/Cookbook/FIRFilter.html
        nyq_rate = fs/2
        width = 5.0/nyq_rate
        ripple_db = 60.0 #dB
        N , beta = sg.kaiserord(ripple_db, width)
        cutoff_hz = 4000.0
        taps = sg.firwin(N, cutoff_hz/nyq_rate, window=('kaiser', beta))
        return( sg.lfilter(taps, 1.0, signal))
```

Exemplo de uso :

``` 
    yDemodFiltrado  = LPF(yDemod, 4000, fs)    
```
