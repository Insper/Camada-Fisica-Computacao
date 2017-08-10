# Camada Física da Computação
- Professor : Rafael Corsi
- Auxiliar de ensino : Eng. Eduardo Marossi 
- Aulas : Quintas e Sextas às 13h30 - 15h30
- Atendimentos segundas feiras às 13h30.

### Canais de comunicação 

Caso deseje conversar ou tirar dúvidas, favor usar um dos meios de comunicação a baixo :

- Rafael Corsi : rafael.corsi@insper.edu.br
    - Sala engenharia 6 andar

- Slack : https://camada-fisica.slack.com
 
### Sobre o curso

- [Critérios de avaliação 
](https://github.com/Insper/Camada-Fisica-Computacao/wiki/Crit%C3%A9rios-de-Avalia%C3%A7%C3%A3o)
- [Plano de aula]()

# Visão geral

Sistema de comunicação entre computadores e dispositivos é um tópico
presente em qualquer produto moderno. Devido a enorme opção de
protocolos existentes no mercado (wifi, ethernet, bluetooth) o
entendimento de conceitos elementares envolvidos nos mais diversos tipos
de comunicação se torna essencial para que o aluno acompanhe novas
tecnologias e saiba projetar de forma eficiente sistemas que a utilizem.

Nesse curso, trataremos das camadas mais baixas de uma comunicação entre
computadores (antigo OSI), as chamadas: camadas de *física* e *Enlace de
dados*. A camada física é responsável pela transmissão de
um sinal por um meio físico, esse meio pode ser um cabo ou o espaço aberto (AR)
. Já a camada de enlace de dados é responsável por manter um link
estável e com o menor nível de erros possíveis entre dois pontos, para
isso, inclui uma série de técnicas de tratamento de erro e recuperação
de dados.

Na questão energética iremos lidar com a análise de datacenters e os impactos
na escolha de tecnologias no consumo de energi. Uma abordagem mais ampla será
utilizada nesse assunto, com questões sociais.

## Detalhamento 

![Linha do Tempo](imgs/linhaDoTempo.pdf){ width=100% }

### Geração/ Distribuição e Transmissão de Energia Elétrica

Sistemas computacionais tendem cada vez mais a serem mais complexos e consumidores
excessivos de energia elétrica. Centros unificados de processamento tais como
*datacentes* possuem uma grande demanda energética devido a grande quantidade de
dispositivos digitais que consomem energia e necessitam de refrigeração.

Estudas o sistema nacional de geração distribuição e transmissão de energia elétrica
possibilitará que o aluno compreenda o impacto e a magnitude (ambientais e
financeiras) de decisões da escolha da infraestrutura para um determinado projeto.

### Eletrônica analógica e digital

Eletrônica analógica trata das propriedades físicas de circuitos elétricos,
basicamente todos dispositivos tidos como digitais (computadores) são compostos por
dispositivos que possuem comportamentos analógicos. Formas de comunicações 
digitais (telefonia, internet, televisão) são em seus extremos pontos analógicos
de comunicação, trafegando dados digitais. 

### Princípios de comunicação


Diferentes aplicações demandam diferentes meios de comunicações, a tecnologia
utilizada para a comunicação entre a terra e um satélite possui demanda diferente
de uma aplicação biomédica. 

O entendimento dos princípios de comunicação possibilita o entendimento correto
das tecnologias existentes e do entendimento das novas que estão por surgir, para
então sugerir o uso correto ....

### Artigo Técnico/Científico

Profissionais que estão no limiar do desenvolvimento tecnológico fazem uso constante
da leitura de artigos técnicos e científicos como canal confiável de acesso
ao conhecimento. Os artigos são também utilizados para divulgação (e revisão)
de novas pesquisas e resultados em um determinado assunto.

O contato com esse tipo de literatura na graduação é muitas vezes penoso já que a
literatura técnica e científica não possui um foco didático. Pretende-se nessa
disciplina introduzir os alunos a escrita técnica e científica por meio da criação
de um artigo técnico em um assunto escolhido pelo aluno.

O artigo criado passará por um processo de submissão e revisão, assim como acontece em
periódicos e congressos, e ao final do curso os alunos poderão apresentar em um
seminário seus estudos.

Os artigos terão um conteúdo técnico mas não trarão dados inovadores, a ideia por
traz dessa experiência é colocar o aluno em contato com o formato de escrita e leitura
desse tipo de forma de comunicação por meio de um exercício prático.

## Modelo Insper de comunicação

Os alunos serão expostos as técnicas de comunicação e programação em camadas via
o projeto de um protocolo de comunicação customizado que irá conter a camada de
enlace e a camada física . 

![Pilha de comunicação](imgs/pilhaInsper.pdf){ width=50% }

- Aplicação : será composta de um software em Python que inicialmente envia
e recebe uma imagem via a camada de enlace.

- Enlace : Software escrito em python que trata de fragmentar a mensagem;
inserir cabeçalhos e técnicas de correção de erros (CRC + ACK/NACK) a fim de manter
um canal de comunicação com a menor taxa de erros.

- Física : Etapa da camada executada por um hardware externo (Arduino) irá ser o
responsável por serializar/deserializar o dado recebido pela camada de enlace e
transportar o dado pelo meio físico (par trançado/ fibra ótica/ comunicação sem fio).

- Meio : Canal pelo qual o dado será propagado

Em um sistema real, as camadas **Enlace** e **Física** estariam implementado em um
hardware (placa de rede), no caso da disciplina por razões didáticas [^1] a camada
de **Enlace** será implementada via software, isso possibilita uma maior agilidade
no desenvolvimento já que questões referentes especificamente a implementação
serão minimizadas. A camada  **Física** por razões de construção não pode ser
separada de um hardware dedicado. Utilizaremos nesse caso uma placa Arduino
para a implementação da serialização e deserialização. 

![Interface de comunicação entre camadas](imgs/pilhaInsper2.pdf){width=80%}

