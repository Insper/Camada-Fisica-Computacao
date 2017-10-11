---
title: Camada Física -  Aula 14 - Modulação em Frequência
subtitlepage-note: 
author: Rafael Corsi / Eduardo Marossi
date: outubro - 2017
---

# Materiais de aula

- [Lista Aula 14 - Modulacao.PDF](https://github.com/Insper/Camada-Fisica-Computacao/blob/master/2-Aulas/14-Modulacao/17-Lista-Modulacao.pdf)

# Projeto 7 - Modulação/Demodulação AM

**Entrega começo da aula do dia 19/10**

O projeto da semana consiste em modular duas mensagens em amplitude, transmitir a mensagem via o falante de um computador e recuperar as duas mensagens demodulando o sinal em outro computador.

- https://github.com/Insper/Camada-Fisica-Computacao/tree/master/3-Projetos/7-Modulacao-AM


# Configurando ambiente SDR

## Windows

### RTL-SDR
1. Obtenha o pacote do RTL-SDR (Windows - Installer) no [site oficial - AirSpy](http://airspy.com/download/).

2. Extraia para uma pasta, e execute o Instalador _install-rtlsdr.bat_, verifique se baixou RTLSDR Driver e ZADIG.

3. Na pasta agora, deve ter um aplicativo chamado Zadig, execute ele, procure nas Opções a opção "List all devices" e clique. Agora insira o dispositivo USB de Rádio e verifique se ele detecta na tela principal.

4. Clique em Install Driver e aguarde a instalação com sucesso.

Mais informações em: https://www.rtl-sdr.com/rtl-sdr-quick-start-guide/

## Ubuntu (Linux)

## OS X 

1. Obtenha o instalador CubicSDR para OS X no [site oficial](http://www.nooelec.com/store/sdr/sdr-receivers/nesdr-mini-rtl2832-r820t.html)

2. Execute o instalador cubicsdr_v0_2_0_os_x.app e instale em Aplicações.

3. Execute o CubicSDR e escolha o dispositivo Generic RTL-SDR

by: Eduardo Marossi
