---
title: Camada Física - DTMF - Geração de tons
author: Rafael Corsi - rafael.corsi@insper.edu.br
date: Setembro - 2017
---
 
# Sinais

[Sinais](https://en.wikipedia.org/wiki/Signal) podem ser descritos como (mas não necessariamente) a variação temporal de uma grandeza física ao longo do tempo. Sinais podem representar batimentos cardíacos, tremores de terra, vibrações, variações térmicas, variação da bolsa de valores, ... . 

Sinais podem ser medidas de uma ou mais dimensões (um sinal de mono de áudio é um exemplo de um sinal de uma dimensão, já uma imagem é um exemplo de um sinal de duas dimensões).

Um sinal no mundo real é contínuo (x(t)), um sinal contínuo é aquele que não apresenta descontinuidade em nenhum de seus eixos e que possui infinitos pontos em todas as suas dimensões.

![Sinal Contínuo - REF [1]](figs/signalContinuo.png){width=50%}

Esse sinal deve ser amostrado e quantizado para poder ser armazenado em um sistema digital (computador) para então ser manipulado. Esse processo é chamado de **digitalização**. A amostragem é o processo de coletar uma "amostra" do sinal em um determinado momento, e a quantização, é o processo de atribuirmos um valor a essa amostra. A figura a seguir demonstra os dois processos :

![Sinal Digitalizado - REF [1]](figs/signalDigitalizado.png){width=50%}

O sinal resultante da digitalização é chamado de discreto (x[n]). 

```

              contínuo                         discreto
                          |---------------|
               x(t) ----> | Digitalização | ----> x[n]
                          |---------------|
```

## Amostragem 

A [amostragem](https://en.wikipedia.org/wiki/Sampling_(signal_processing)) é o processo de discretizar o tempo. A amostragem de um sinal é normalmente realizada em uma frequência determinada (o espaçamento de cada amostra é constante), esse espaçamento (quando no tempo) é chamado de Período de amostragem ($Ts$: [segundos]) e e sua frequência equivalente é chamada de Frequência de amostragem ($Fs$: [Hertz]), sendo :

$Ts = 1/Fs$

![Amostragem. REF: https://en.wikipedia.org/wiki/File:Signal_Sampling.png](figs/sampling.png){width=100%}

A frequência de amostragem de um sinal indica quantas amostras compõem um sinal em um determinado intervalo de tempo. Uma frequência de amostragem de 1000Hz indica que um sinal terá 1000 amostras em segundo.

> Pergunta :
> 
> Dado que fs de um sistema é 1.2kHz, quantos pontos teremos em 1.5 segundos de dados ?

> Pergunta :
>
> Dado que Ts de um sinal discreto é 12us, quantos pontos teremos em 1.5 segundos de dados?

> Pergunta :
>
> Um sinal amostrado em 44100Hz possui 1323000 amostras, isso equivale a quantos milessegundos de dados ?

> Dica :
> Saiba transformar :
> - 0.001 em : mile (m), micron (u), nano
> - 10000 em : kilo amostras (K), mega amostras (M) e giga amostras (G)

## Quantização

Os valores convertidos de analógico para digital sofrem da problemática da quantização (resolução), que é a associação de uma amostra que pode assumir infinitos valores 

($2^n-1$ = quantidade de bits) um sinal analógico que pode assumir infinitos valores entre um ponto e outro

O processo de quantização é o processo de mapear um valor contínuo (eixo y) em um valor que possa ser armazenado pelo computador, conforme ilustrado na figura a seguir :

![Quantização 2 bits. REF Wiki](figs/2-bit_resolution_analog_comparison.png){width=50%}

Quanto maior a quantidade de bits disponível para a quantização mais "preciso" será o sinal digitalizado. Na figura a seguir, temos uma quantização de N=3, ou seja 8 possíveis opções na qual um determinado ponto pode ser enquadrado.

![Quantização 3 bits. REF [WIKI]](figs/3-bit_resolution_analog_comparison.png){width=50%}

> Quantos bits são utilizados na quantização para digitalizar sinais das aplicações :
>
> - Telefonia
> - MP3
> - Câmera fotográfica

> Um sinal foi quantizado com uma resolução de 3 bits a uma taxa de 2Hz e armazenado na variável b:
>
> b = [000 010 100 110 000 010 100 110 000]
>
> Desenhe em um gráfico (Amplitude vs tempo) o sinal digitalizado.

> Um sinal de eletrocardiograma (ECG) de 5 minutos necessita ser enviado por uma enlace de comunicação que consegue transmitir dados a um baudrate de 1000bps porém possui um overhead de 10% a cada 1024 bytes enviados. O ECG é amostrado a uma taxa de 1kHz e possui resolução de 14 bits. Enquanto tempo o ECG será transmitido ?

# DTMF

O *dual tone multi frequency* (DTMF) é um sinal de áudio utilizado pelas empresas de telefonia para detectar o sinal apertado pelo usuário, muito utilizada em menus de telemarketing para guiar o usuário pelas opções. A partir da definição de 8 frequências bases, obtém-se 16 diferentes símbolos, conforme a tabela a seguir :

|            | 	1209 Hz | 1336 Hz	 | 1477 Hz	 | 1633 Hz |
|------------|-------------|-------------|-------------|---------|
| 697 Hz	 | **1**       | **2**       | **3**       | **A**   |
| 770 Hz	 | **4**       | **5**       | **6**       | **B**   |
| 852 Hz	 | **7**       | **8**       | **9**       | **C**   |
| 941 Hz	 | **X**       | **0**       | **#**       | **D**   |

Nessa de codificação, define-se uma maneira de codificar os sinais 0,1,2,..9,*,#,A,B,C,D em símbolos 16 (2^4), onde cada símbolo é composto por duas frequências dominantes, o sinal resultante dessa composição é chamado de tom.

## Símbolos

Símbolos em sistemas de comunicações são a maneira de codificar um sinal para a transmissão. Por exemplo um bit (1 ou 0) pode ser codificado em um símbolo que o valor 1 é equivalente a uma tensão elétrica de 5V e o valor bit 0 é codificado em um valor de tensão equivalente a -5V.

## Tons

Os tons são gerados a partir da composição de duas frequências bases, esses sinais são gerados por senoides com a frequência defina na tabela. Por exemplo o símbolo 0 é codificado a partir de uma senoide de frequência 941Hz e outra senoide de frequência 1136Hz.

$Ton_0(t) = sin(2 \pi 941 * t)+sin(2 \pi 1136 * t)$

> Em uma recepção dos tons detectou-se as seguintes frequências, encontre o símbolo original :
> 
> | F1      (Hz) | 	F2 (Hz) | Símbolo recuperado|
> |--------------|-------------|---------|
> |         1477 |         770 |         |
> |         1633 |         941 |         |
> |         1400 |         775 |         |
> |        1200  |         850 |         |
 
> Desenhe um gráfico (amplitude vs frequência) e localize nesse gráfico as frequências utilizadas pelo DTMF

> Quais são os símbolos que apresentam menor diferença de frequência ? por exemplo, o símbolo 2 e 3 possuem a mesma frequência Y (697 Hz) mas diferentes frequências em X (1336 e 1477), a diferença de frequência é de 141 Hz.

# Referências :

- [1] :Alan Oppenheim. RES.6-007 Signals and Systems. Spring 2011. Massachusetts Institute of Technology: MIT OpenCourseWare, https://ocw.mit.edu. 
