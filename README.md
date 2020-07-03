# ATAD-BasketScore
Manipulation of Basketball stats


##### ESCOLA SUPERIOR DE TECNOLOGIA DE SETÚBAL

Licenciatura em Engenharia Informática

# Basket Scores

#### Unidade Curricular : Algoritmos e Tipos Abstratos de Dados

#### Docente: Aníbal Ponte

#### Aluno: Miguel Pires Nº

#### Aluno: João Gomes Nº

#### Ano Letivo 2017/


## Indice

- Introdução
- Descrição das Estruturas de Dados
- Comandos e Resultados
   - 1) LOAD Jogadores e Jogos
   - 2) Informação sobre os Jogadores
      - 2.1) Command SHOW
      - 2.2) Command SORT
      - 2.3) Command AVG
      - 2.4) Command TYPE
      - 2.5) Command CHECKTYPE
- Limitações
- Conclusão


## Introdução

No âmbito da Unidade Curricular de Algoritmos e Tipos Abstratos de Dados foi proposto a


elaboração de um programa em linguagem C para extrair informação útil de ficheiros com dados
sobre os jogadores e os jogos de basquetebol. Este programa consiste num interpretador de
comandos que o utilizador irá usar para obter os diversos tipos de informação, principalmente
informação sobre a parte das estatísticas.

Na realização deste projeto foi aplicada apenas a matéria lecionada nas aulas Teórico-práticas e Laboratoriais.


## Descrição das Estruturas de Dados

Neste projeto foram implementadas as seguintes estruturas de dados:


Estrutura Date utilizada
posteriormente na criação de um
Player.

Estrutura de Estatísticas, onde ira
guardar as estatísticas dos todos
os jogos, bem como o número de
jogos.


Estrutura de Player, onde se
criará um jogador já com uma
data de nascimento e estatísticas
desse Jogador



Estrutura de TadList

Estrutura de ListElem, onde se
define o tipo de dados a guardar
no TAD List.


Estrutura do tipo de dados a
guardar no TAD Map.

Estrutura de TadMap para a
execução do comando
CHECKTYPE.


Modulo Functions onde
colocamos as funções auxiliares
para os comandos solicitados.


Módulo Command onde são
chamadas as funções auxiliares
que fazem com que o comando
execute o pretendido.



## Comandos e Resultados

##### NOTA: ALGUNS DOS RESULTADOS EXEMPLIFICATIVOS NÃO SÃO COMPLETOS DEVIDO Á

##### EXTENSIVIDADE DOS MESMOS.

### 1) LOAD Jogadores e Jogos


Na Consola:


### 2) Informação sobre os Jogadores

#### 2.1) Command SHOW

Na consola:


#### 2.2) Command SORT

Este método ordena a lista de jogadores por NOME, BIRTHDAY e GAMES PLAYED pedindo ao
utilizador se quer que seja ordenada de NOME (opção 1) ,BIRTHDAY (opção 2) ) , GAMES
PLAYED (opção 3).

Na consola:

Opção 1


Opção 2

Opção 3

#### 2.3) Command AVG


Este método retorna lista de jogadores com as suas estatísticas calculadas e que tenham
jogado pelo menos um jogo. Como nos é mandado no Enunciado:

#### 2.4) Command TYPE


A partir da averageList este método define-nos o tipo de jogador dependendo das estatísticas
do jogador em comparação das estatísticas globais de todos os jogadores.

Sendo os tipos definidos pelas seguintes métricas:

#### 2.5) Command CHECKTYPE

Neste método primeiramente temos de definir o tipo de jogador numa estrutura igual a está.


## Limitações

Neste projeto dos comandos pedidos apenas um não foi implementado, o comando Kmeans.


## Conclusão

Após concluirmos o projeto podemos fazer um balanço positivo, as dificuldades que surgiram


foram ultrapassadas com sucesso, umas com mais facilidade que outras. A única dificuldade
que nos deparamos, e não tendo conseguido resolver, foi o comando Kmeans.

Em suma, podemos dizer que consolidamos melhor a matéria lecionada que foi necessária


para a elaboração deste Mini Projeto2, e que alcançamos todos os objetivos traçados para o
mesmo.


