---
title: Camada Física -  HandShake / ACK e nACK
author: Rafael Corsi - rafael.corsi@insper.edu.br
date: Agosto - 2017
---

# HandShake

Handskake (aperto de mão) é um mecanismo de negociação entre nós de uma rede, o handshake pode existir em diversas camadas da pilha de comunicação. O handshake pode ser utilizado para a configuração automática de parâmetros da rede, tal como: velocidade de transmissão, codificação, chaves públicas, entre outos.


## TCP-3-Way-Handshake

O [TCP 3Way handshake](https://en.wikipedia.org/wiki/Transmission_Control_Protocol#Connection_establishment) acontece na camada de transporte, ele é utilizado para inicializar a comunicação entre dois nós em uma comunicação TCP/IP (Transmission Control Protocol). A comunicação TCP/IP difere da UDP (User Datagrama Protocol) pela garantia da transmissão do dado, em um canal TCP um dado só será transmitido se o Server concordar (ou estar habilitado) para receber um ou mais pacotes. Pacotes não serão enviados caso um dos nós da comunicação não esteja preparado.

A negociação de três etapas acontece da seguinte maneira :

1. Client inicializa a comunicação enviando um pacote de : **SYN**
1. Server confirma o recebimento do pacote com um pacote de : **ACK**
1. Server envia agora um pacote de sincronismo : **SYN**
1. Client confirma o recebimento do pacote de sincronismo com um pacote de : **ACK**
1. A comunicação está estabelecida.

Para isso acontecer, devemos ter trafegando entre os dois nós pacotes de comando. Pacotes de comando não trafegam carga útil (payload) e possuem um formato bem definido, eles possibilitam a troca de comandos entre os dois nós de uma comunicação. No handshake do TCP temos quatro tipos de pacotes de comando:

- **SYN** (Synchronize) - Inicializa uma comunicação
- **ACK** (Acknowledge) - Comunica o recebimento correto de um pacote (dado ou comando)
- **nACK** (no Acknowledge) - Comunica o não recebimento ou negação de um pacote (dado ou comando)
- **FIN** (Final) - Finaliza uma comunicação

O diagrama a seguir exibe um handshake entre um client e um server :

![TCP-3-Way-Handshake](figs/3wayhandshake.pdf){width=35%}

> Questão :
> No handshake o que acontece se o Server responder com um nACK logo após o recebimento do SYN?
>
> - O que isso significa ?xr

> Questão :
> O que é timeout ? Como o mesmo é calculado.

> Questão :
> O que acontece caso o pacote SYN enviado pelo server for perdido/corrompido ?

> Questão :
> O que é *TCP SYN FOOD* ? Qual a solução para o mesmo ?


## 802.11 (WPA)

O Handshake é utilizado por exemplo para estabelecer uma conexão *wireless* (WPA), nessa conexão existe uma negociação entre o *access point* (AP) e a estação (STA) para trocarem chave pública. Nesse caso é utilizado uma negociação de quatro etapas (chamada 4Way-Handshake) conforme a figura a seguir :

![4-Way-Handshake. Ref: https://en.wikipedia.org/wiki/IEEE_802.11i-2004](figs/4-way-handshake.png){width=40%}

Essa negociação acontece na camada mais baixa (*link layer*, internet model) e é executada pela placa de rede do dispositivo, sem o intermédio do computador/ sistema operacional.

> Questão:
> O que é a normal IEE 802 ? 

> Questão:
> Como é feito a criptografia com chaves públicas e privadas (assimétrica)

# ACK/nACK

O reconhecimento (ACK,acknologment) ou não reconhecimento (nACK, no acknologment) utilizado no handshake também é utilizado para informar o recebimento de um pacote de dados, ou recebimento com valores não corretos. Esse mecanismo é empregado em qualquer meio de comunicação seguro possibilitando que os dois nós da comunicação troquem informações sobre a integridade dos pacotes.

O diagrama a seguir ilustra uma comunicação entre dois nós (Client e Server) em uma conexão com reconhecimento (acknowledgement).

![ACKs positivos](figs/ack1.pdf){width=30%}

Esse formato de comunicação permite que o remetende da mensagem tenha conhecimento do seu recebimento, em muitos os caso, onde o canal físico de comunicação não é confiável pode haver perdas de dados do pacote ou até o não recebimento do mesmo (falha no roteamento). Como nas figuras a seguir :

![Falhas na comunicação](figs/ack23.pdf){width=70%}

No primeiro diagrama, o pacote enviado pelo cliente não alcança o servidor, isso pode acontecer por diversos motivos tais como : falha no roteamento; problemas na recepção do server; se for uma rede sem fio o client/server podem estar em um ponto sem conexão. Nesse caso o Client envia um pacote e aguarda por tempo até a resposta do Server, caso essa resposta não chegue em um tempo pré determinado, o Client reenvia a mensagem.

No segundo datagrama, o pacote é recebido pelo server mas no meio do caminho sofreu algum tipo de alteração (ou por interferência ou por colisão) e essa alteração foi detectada pelo servidor a partir de informações extraídas do HEAD e EOP. Como o pacote estava defeituoso foi enviado um **nACK** alertando o cliente que o pacote deve ser reenviado.

> Questão:
>
> O padrão 802.11 (wireless) define o conceito de *Block Acknowledgement* o que é isso ?Qual sua vantagem ?

> Questão:
>
> O que é *automatic repeat request* (ARQ) ?

> Questão:
>
> Quais as diferenças entre :
>
> - Stop-and-Wait ARQ
> - Go-Back-N ARQ
> - Repeat ARQ/ Selective Reject

# Referências 

- https://en.wikipedia.org/wiki/IEEE_802
- https://en.wikipedia.org/wiki/Automatic_repeat_request
- https://www.safaribooksonline.com/library/view/80211-wireless-networks/0596100523/ch04.html
