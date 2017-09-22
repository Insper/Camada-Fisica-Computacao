---
title: Camada Física -  Fragmentação
author: Rafael Corsi - rafael.corsi@insper.edu.br
date: Agosto - 2017
---

# Fragmentação

Muitas vezes é necessário realizar a fragmentação de um payload em diversos pacotes, entre algumas causa podemos listar :

1. O payload excede o tamanho máximo do pacote (extrapola o campo do HEAD que indica o tamanho do payload)
1. Existe alguma limitação de hardware (buffer reservado para a mensagem)
1. Desejo de aumentar o *throughput* da rede (retransmitindo pacotes menores)
1. Limitar o tempo na qual o envio do pacote ocupa um determinado meio.


> Questão:
>
> O que é a colisão na ethernet ?

A figura a seguir ilustra uma fragmentação de um dado pela camada de enlace :

![Fragmentação](figs/fragmentacao.pdf){width=50%}

A fragmentação pode ocorrer em camadas distintas da comunicação, podendo inclusive ocorrer múltiplas fragmentações de um mesmo payload. Como acontece com um pacote TCP/IP enviado pelo Wireless, o payload será primeiramente fragmentado pela camada de transporte, depois esse dado será encapsulado em um pacote IP para então ser fragmentado novamente pela camada de enlace. Como mostrado na figura a seguir :

![Fragmentação](figs/fragmentacaoLayers.pdf){width=80%}

Em uma rede complexa como a internet, onde um pacote é fragmentando em múltiplos pacotes e enviado para a um destinatário na rede, cada pacote pode assumir uma rota distinta e chegar de maneira desordenada ao destinatário. O protocolo por sua vez, deve conseguir receber pacotes fora de ordem e reordenar-los a fim de reconstruir corretamente o pacote original.

![Rede com múltiplos pontos de roteamento](figs/pacoteRede.pdf){width=60%}

Para contornar esse problema, deve-se adicionar a um dos campos do HEAD informação sobre o número do pacote, dessa forma o receptor conseguirá reordenar os pacotes e recuperar corretamente o dado.

## Campos no HEAD

Para a fragmentação ocorrer é necessário adicionarmos informações no HEAD de cada pacote que permitirá ao receptor reconstruir o pacote original e passar essa informação a camada superior. Essa informação varia conforme cada protocolo, mas ao menos as seguintes informações estarão presentes:

1. Número total de fragmentos
1. Número atual do pacote

### IEEE 802.11 (wireless)

![[REF 1] Modelo OSI e wireless](figs/microsoft-OSI.gif){width=70%}

Os pacotes que trafegam via rede wireless ieee 802.11 sofrem fragmentação a nível da camada de enlace (data link), os pacotes que trafegam no wireless são empacotados utilizando o cabeçalho a seguir : 

![[REF 1] Frame Control Field](figs/microsoft-wireless-frame.gif){wifth=70%}

Um dos campos desse HEAD é o campo *Sequence Control*, ele é composto por 6 bytes e possui a seguinte distribuição :

![[REF 1] Sequence Control field](figs/microsoft-sc.gif){wifth=20%}

Onde :

- *Sequence Number* : Número mais geral que "etiqueta" o pacote atual, ele é utilizado para indicar o pacote na qual o fragmento pertence.

- *Fragment Number* : Campo para indicar o número do fragmento que o pacote pertence.

Os fragmentos devem ser de tamanho igual, com exceção o último fragmento, que pode ter tamanho menor que os demais.

## ACK e NACK 

Devido a fragmentação podemos definir diversas formas de implementar o reconhecimento do pacote, analise o applet a seguir :

>  http://www.ccs-labs.org/teaching/rn/animations/gbn_sr/

#### Envio com espera

Envia-se um pacote e aguarda pela sua resposta, em caso de erro, reenvia o pacote. Os diagramas a seguir demonstra esse modo de ack/nack :

![Envio com espera](figs/ackComEspera.pdf){wifth=100%}

#### Go-Back-n

Envia-se N pacotes e aguarda por um N ACKs, caso algum falhe, reenvia todos os pacotes novamente.

> Questão
>
> Faça um diagrama do modo Go-Back-N, simulando uma falha em um dos pacotes.

#### Repetição Seletica (SR)

Envia-se N pacotes e aguarda por N ACKs, caso algum falhe, reenvia somente o que foi perdido.

> Questão
>
> Faça um diagrama do modo SR, simulando uma falha em um dos pacotes.


> Questão
>
> O que é o tamanho da janela ?

# Referências :

- [1] : https://technet.microsoft.com/en-us/library/cc757419(v=ws.10).aspx
- [2] : https://mrncciew.com/2014/11/03/cwap-802-11-fragmentation/
