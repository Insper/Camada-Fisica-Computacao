---
title: Camada Física -  Dicas Projeto 3 - COM-HandShake-ACK-NACK
author: Rafael Corsi - rafael.corsi@insper.edu.br
date: agosto 2017
---

# Dicas de implementação :

A seguir algumas dicas para a implementação do projeto 3 - COM-HandShake-ACK-nACK.

## Ordem de execução

1. Redefina o HEAD agora para suportar dois tipos de pacotes distintos :
    - payload
    - comando
    - Modifique a implementação (se usou o construct fica fácil !)
1. Defina os três tipos de comandos e como serão identificados no pacote.
    - SYN
    - ACK
    - NACK
1. Documente (você já vai precisar fazer isso mesmo !)
1. Enlace, empacotamento :
    - Implemente métodos distintos para criar os pacotes de comando e um para criar o pacote de dados:
    
```python
        def buildSynPacket(self):
            ...
            return(p)

        def buildAckPacket(self):
            ...
            return(p)

        def buildNackPacket(self):
            ...
            return(p)
            
        def buildDataPacket(self, data):
            ...
            return(p)
```
1. Enlace, desempacotamento :
    - Implemente uma classe que classifica o pacote como comando/ dado
    - Implemente uma classe que recebe um pacote de comando e retorna o seu tipo (SYN,ACK,NACK)


```python
        def getPacketType(self):
            ...
            # retorna "Comando", "Dado" ou "ERRO"
            return(type) 

        def getCommandType(self):
            ...
            # retorna "SYN", "ACK", "NACK" ou "ERRO"
            return(p)
```
1. Enlace, TX e RX :
    - Teste cada pacote de comando independentemente 
1. enlace, client:
    - Implemente uma máquina de estados para o handshake e envio de pacotes.
1. enlace, server :
    - Implemente uma máquina de estados para o handshake o recebimento de pacotes.

