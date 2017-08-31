---
title: Camada Física -  Dicas Projeto 2 - COM-Datagrama 
author: Rafael Corsi - rafael.corsi@insper.edu.br
date: 2017
---

# Dicas de implementação :

A seguir algumas dicas para a implementação do projeto 4 - COM - Fragmentação e Deteção de Erros

## Ordem de execução

1. Implemente primeiro a fragmentação
    - Defina os novos campos dos pacotes
        - Documente !
    - Faça o envio e recepção desse novo formato de pacote (um único pacote com todo o payload)
        - Imprima na tela do receptor (server) as informações extraídas do HEAD
        - Verifique se o server está enviando o ACK.
    - Implemente o reenvio de dados no caso de falhas :
        - Reenvio em caso de ACK/NACK :
            - Simule uma falha, faça o server enviar um NACK. O client deve reenviar o pacote.
        - TimeOut :
            - Simule uma falha, retire o envio do ACK do server, o client deve reenviar o pacote quando o timer estourar.
    - Faço a fragmentação em apenas dois pacotes (esqueça por hora o envio de no máximo 2048 bytes)
        - Verifique se o transmissor (client) está :
            1. Fragmentando os dados corretamente
            1. Aguardando a recepção de um ACK/NACK a cada pacote
        - Verifique se o receptor (server) está :
            1. Detectando o número total de pacotes a serem recebidos
            1. Detectando o número atual do pacote
            1. Enviando um ACK/NACK a cada pacote
   
