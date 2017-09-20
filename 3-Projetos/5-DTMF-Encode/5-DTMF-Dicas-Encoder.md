---
title: Camada Física -  Dicas APS 5 - DTMF - Encode
author: Rafael Corsi - rafael.corsi@insper.edu.br
date: 2017
---

# Dicas de implementação :

A seguir algumas dicas para a implementação do projeto 5 - DTMF - ENCODE

## Bibliotecas 

- numpy : para trabalhar gerar as senoides
- sounddevice : para reproduzir e gravar áudio
- matplotlib.pyplot : para exibir gráficos

## Códigos

- sounddevice :
    - Deve-se definir a frequência de amostragem (fs) tanto para receber um áudio pelo microfone quanto para reproduzir um áudio nos falantes. 
        - utilize o padrão : fs = 44100
    - Para gravar e reproduzir um áudio:
    
```python
import sounddevice as sd
fs = 44100
duration = 3

audio = sd.rec(int(duration*fs), fs, channels=1)
sd.wait()

y = audio[:,0]

# reproduz o som
sd.play(y, fs)

# aguarda fim da reprodução
sd.wait()

```

- Tons : Os tons do DTMF são formados pela composição de duas senoides em diferentes frequências.
    - os senos devem ser gerados com a mesma fs do utilizado no sounddevice (fs)
    - pré gere todos as frequências na inicialização do programa, e depois só as utilizar.
    
# Plot real time

```python
    # Cria plot
    plt.ion()
    fig = plt.figure("F(y)", figsize=(10,10))
    ax  = fig.add_subplot(111)
    
    ...
    ...
    # Atualiza plot
    ax.clear()
    ax.plot(X[0:3000],Y[0:3000])
    fig.canvas.draw()
```
