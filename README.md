# -Análise Comparativa de Implementações do Algoritmos MinMax-

## Introdução

Neste projeto, foi realizado uma análise comparativa de três implementações diferentes do algoritmo MinMax, onde
a partir do que foi trabalhado em sala, foi proposto a implementação em C/C++ de 3 algoritmos diferentes com o 
mesmo objetivo, o qual era procurar o menor valor e o maior valor.

## Objetivos

O objetivo principal desta atividade é observar o impacto das diferentes implementações do algoritmo MinMax na prática 
e comparar o seus tempos de execução referentes aos diferentes modelos de entrada, os quais eram vetores aleatórios com 
valores contidos entre 0 a 1000, além de 3 modelos de vetores, os aleatórios, os ordenados crescentemente e os ordenados
decrescentemente. Para isso se concretizar, foram propostos os seguintes objetivos:

1- **Implementação dos Algoritmos**: Implementar os três algoritmos Minimax - Minimax1, Minimax2 e Minimax3 - utilizando C/C++ e aderindo às melhores práticas de programação.

2- **Avaliação dos Métodos**: Avaliar os métodos utilizando diferentes tamanhos de entrada, sendo esses 1.000, 10.000, 100.000 e 500.000 elementos do tipo inteiro. Cada algoritmo será executado
10 vezes para cada tamanho de entrada, e o tempo de execução será a média dessas 10 execuções. Além disso é crucial ressaltar que os dados iniciais devem ser os mesmos para todas avaliações do 
vetor de mesmo tamanho N.

3- **Elaboração de Planilha e Gráficos**: Com base nos tempos obtidos, elaborar uma planilha no Excel para analisar as relações de tempo de forma gráfica. Recomenda-se categorizar
os dados por classes e detalhar comparações por algoritmo quando os dados mudam, considerando tanto conjuntos de dados em ordem crescente quanto decrescente.

4- **Disponibilização do Código no Git**: Subir o código desenvolvido para um repositório Git e detalhar os experimentos realizados no arquivo README.md. Além disso, relacionar os
resultados com os conceitos de análise assintótica discutidos em sala.

5- **Pontos Extras com gnuplot**: Os alunos que utilizarem o gnuplot para plotar os gráficos e disponibilizarem o script utilizado para geração junto com o código no Git receberão 2 pontos de crédito na disciplina.

## Arquivos Do Código

- **main.cpp**
- **MinMax.cpp**
- **MinMax.hpp**

## Código 

### MinMax.cpp

- **MinMax():** É o construtor da classe, ele inicializa os vetores de média que são os atributos da classe MinMax, além de resetar os arquivos para serem escritos;
- **void randomVetores():** A função tem o objetivo de atribuir valores randomicos aos 4 vetores que são atributos da classe MinMax;
- **void apagarArquivos():** A função que é chamada pelo construtor e tem como objetivo apagar o que estiver dentro do arquivo;
- **vector<int> organizarCrescente(vector<int> vetor):** A função que recebe um vetor e o retorna organizado crescentemente;
- **vector<int> organizarDecrescente(vector<int> vetor):** A função que recebe um vetor e o retorna organizado decrescentemente;
- **float duracaoMinMax1(vector<int> vetor, int tam):** A função que calcula a partir de um vetor e o tamanho desse vetor o tempo gasto para se encontrar o valor minimo e maximo utilizando o algoritmo MinMax1;
- **float duracaoMinMax2(vector<int> vetor, int tam):** A função que calcula a partir de um vetor e o tamanho desse vetor o tempo gasto para se encontrar o valor minimo e maximo utilizando o algoritmo MinMax2;
- **float duracaoMinMax3(vector<int> vetor, int tam):** A função que calcula a partir de um vetor e o tamanho desse vetor o tempo gasto para se encontrar o valor minimo e maximo utilizando o algoritmo MinMax3;
- **void Execute():** A função que executa todo o código, ela roda 10 vezes as funções que calculam o tempo e chama as demais funções;
- **void MinMax1(int tam, int pos):** A função que chama a função que calcula o tempo do minmax1 e faz com que ele rode com todos os vetores, além de printar no arquivo os resultados;
- **void MinMax2(int tam, int pos):** A função que chama a função que calcula o tempo do minmax2 e faz com que ele rode com todos os vetores, além de printar no arquivo os resultados;
- **void MinMax3(int tam, int pos):** A função que chama a função que calcula o tempo do minmax3 e faz com que ele rode com todos os vetores, além de printar no arquivo os resultados;
- **void clearVector():** A função que limpa os vetores para que não acumule memória após o término do programa;
- **void calculodasmedias():** A função que realiza o calculo das médias de todos os algoritmos;
- **void printMedia():** A função que cria um arquivo de texto com todas a médias dos 3 algoritmos.

### Bibliotecas

- **algorithm:** Biblioteca utilizada para ordenar os vetores utilizando a função sort;
- **chronos:** Biblioteca utilizada para demarcar o tempo gasto por cada algoritmo MinMax(tempo é demarcado em ms);
- **fstream:** Biblioteca utilizada para manipulação de arquivos;
- **random:** Biblioteca utilizada para relizar o preenchimento dos vetores de forma aleatória;

## Testes

### Base Dos Testes
Era esperado que os resultados dos algoritmos seguissem a base de lógica representada pelo seguinte quadro:

![funções](https://github.com/ByBrun0/MinMax/assets/143546997/970b83d0-1f6b-4b31-af5d-51582e6d8849)

Dessa forma é como se houvessem retas em um gráfico que tenham como suas funções as funções do gráfico, com n representando o tamanho do vetor e o f(n) o custo computacional.

### Realização Dos Testes

Durante a implementação do código foi realizado um programa que executava 10 vezes o calculo dos tempos, entretanto a cada verificação do tempo o vetor tinha seus valores alterados.
Após uma discussão com o professor, foi realizado a correção do códgio para que o vetor mantesse seus valores durante as 10 execuções, entretando pôde-se observar que a variação dos 
valores do vetor fazia com que os tempos em cada algoritmo fossem muitos diversificados, o que é resultado das diferentes formas que a organização impacta no algoritmo principalmente
quando se toma como referencia os algoritmos aplicados nos vetores aleatorios.

### Resultados Obtidos

A cada vez que se executa a main, é realizado o processo de criação de 4 arquivos, sendo eles:

- **MinMax1.csv:** Arquivo onde se encontra todos os tempos obtidos pelo algoritmo MinMax1;
- **MinMax2.csv:** Arquivo onde se encontra todos os tempos obtidos pelo algoritmo MinMax2;
- **MinMax3.csv:** Arquivo onde se encontra todos os tempos obtidos pelo algoritmo MinMax3;
- **MediaGeral.txt:** Arquivo onde se encontra todas as médias obtidas pelos 3 algoritmos;

Nos 3 primeiros arquivos há a seguinte formatação padrão:

| Tamanho do vetor | Tempo aleatório | Tempo crescente | Tempo decrescente |
|------------------|-----------------|-----------------|-------------------|
| 1000             | 2               | 6               | 7                 |
| 10000            | 22              | 35              | 32                |
| 100000           | 205             | 221             | 229               |
| 500000           | 1043            | 1077            | 1041              |

A qual se repete 10 vezes uma abaixo da outra por todo arquivo. Já a *MediaGeral.txt* se encontra formatada da mesma maneira porém
repetida 3 vezes para cada algoritmo do projeto.

### Planilha

Após o código realizar a criação dos arquivos, manualmente foi realizado a criação de uma planilha, a qual contém todos os dados dos 4 arquivos dentro de si. Eventulamente durante a reformulção do código
houve a perca da planilha que continha os valores quando o vetor era randomizado a cada execução, ficando apenas a ultima planilha com vetor constante durante as 10 execuções.

**Planilha:**

![planilha](https://github.com/ByBrun0/MinMax/assets/143546997/da35d0d4-4d0f-461a-ac31-9e287c4f7df4)

## Gnuplot

### Arquivos Para Graficos

Após a criação da planilha, houve a criação de 6 arquivos que contém uma formatação para a utlização do gnuplot a fim de criar gráficos que representem os algoritmos. Sendo esses os seguintes arquivos;

- **MediaAleatorio.csv**
- **MediaCrescente.csv**
- **MediaDecrescente.csv**
- **MediaMinMax1.csv**
- **MediaMinMax2.csv**
- **MediaMinMax3.csv**

Onde os 3 primerios tem a seguinte formatação:

| Tamanho do vetor | Tempo aleatório MinMax1| Tempo aleatório MinMax2 | Tempo aleatório MinMax3 |
|------------------|------------------------|-------------------------|-------------------------|
| 1000             | 2                      | 6                       | 7                       |
| 10000            | 22                     | 35                      | 32                      |
| 100000           | 205                    | 221                     | 229                     |
| 500000           | 1043                   | 1077                    | 1041                    |

Em que o que muda é o tempo se é a média dos aleatórios ou dos crescentes ou dos decrescentes. Enquanto que os outros 3 arquivos tem a seguinte formatação:

| Tamanho do vetor | Tempo aleatório | Tempo crescente | Tempo decrescente |
|------------------|-----------------|-----------------|-------------------|
| 1000             | 2               | 6               | 7                 |
| 10000            | 22              | 35              | 32                |
| 100000           | 205             | 221             | 229               |
| 500000           | 1043            | 1077            | 1041              |

Porém diferente do *MinMax1* esse não se repete 10 vezes, contendo apenas a média dos tempos de cada respectivo MinMax.

### Gráficos

Média - MinMax1     |  Média - MinMax2
:-------------------------:|:-------------------------:
![outputMinMax1](https://github.com/ByBrun0/MinMax/assets/143546997/03e01b04-9691-4327-87d0-b5b7a6f31424)  |  ![outputMinMax2](https://github.com/ByBrun0/MinMax/assets/143546997/97c3ad7e-3366-4360-bfe9-9269e8d8e4c2)


 
Média - MinMax3       |  Média - Aleatorio
:-------------------------:|:-------------------------:
![outputMinMax3](https://github.com/ByBrun0/MinMax/assets/143546997/065d76ea-5da6-4dc9-a733-0d778c3dbeed)  |  ![outputMediaAleatorio](https://github.com/ByBrun0/MinMax/assets/143546997/21c8d0df-504a-4ac9-af47-4b9be1a16f25)


 Média - Crescente      |  Média - Decrescente
:-------------------------:|:-------------------------:
![outputMediaCrescente](https://github.com/ByBrun0/MinMax/assets/143546997/f100049c-dead-4dc0-8aaf-dcfc9d28a28b)  |  ![outputMediaDecrescente](https://github.com/ByBrun0/MinMax/assets/143546997/d1c5d7e3-892e-4d8b-b126-f11055ffb9d9)


### Análise Dos Gráficos

- **Análise Média - MinMax1:** No gráfico do MinMax1, observa-se que a ordenação do vetor tem um impacto mínimo nos resultados de tempo, indicado pela proximidade das retas. Entretanto, ainda assim o vetor aleatório apressenta
vantagem em relação aos outros. 

- **Análise Média - MinMax2:** No gráfico do MinMax2, o impacto da ordenação do vetor nos resultados do algoritmo é ainda menor, como pode se observar pela aproximação das 3 retas, é quase impercepitivel a diferença das retas
dos vetores ordenados e diferença de tempo do aleatório caiu para os vetores ordenados. Vale ressaltar que o tempo piorou para o MinMax1.

- **Análise Média - MinMax3:** No gráfico do MinMax3, quando há a ordenação do vetor o impacto é significativo no custo do algoritmo, com tempos muitos maiores e que chegam a serem maiores que o dobro quando o vetor é aleatório 
em comparação com um vetor ordenado crescente ou decrescente.

- **Análise Média - Aleatório:** No gráfico de Aleatório, o MinMax1 leva uma ligeira vantagem sobre o MinMax2, enquanto que o MinMax3 teve um tempo estrondosamente maior com relação às outras retas, ressaltando a ineficiencia
do terceiro algoritmo quanto a vetores não ordenados.

- **Análise Média - Crescente:** No gráfico da Crescente, conseguimos observar uma melhora do algoritmo 3 e ele apresenta maior eficiência com relação aos outros 2 algoritmos para grandes massas de dados, enquanto que para pequenas
eles andam relativamente pertos e o ganho não é tão significativo.

- **Análise Média - Decrescentes:** No gráfico da Decrescente, podemos observar o mesmo acontecimento do gráfico **Média - Crescente**, em que os dois primeiros algoritmos se mantem juntos, apesar de apresentarem uma leve
separação de suas retas, enquanto que o algoritmo 3 não sofreu alteração e se manteve abaixo em comparação aos de mais para grandes vetores.

### Conclusão

Em resumo, os gráficos demonstram que o MinMax3 não lida bem com vetores aleatórios e pequenos, mas apresenta vantagem significativa com vetores ordenados e maiores. Enquanto que o MinMax1 e o 
MinMax2 apresentam uma consistencia maior quanto ao seus tempos, as retas não se distanciaram independente dos vetores, apesar de seus tempos não terem ganhos conforme o vetor aumenta. 
A análise dos gráficos revela insights valiosos sobre o desempenho dos algoritmos MinMax1, MinMax2 e MinMax3 em diferentes cenários de entrada. Em geral, observa-se que o comportamento 
dos algoritmos varia significativamente com base na ordenação e no tamanho dos vetores de entrada. Podemos chegar a conclusão que o MinMax1 é um dos piores em termo de tempo, enquanto que 
o MinMax2 se sobresai em relação ao MinMax3 em alguns aspectos da mesma forma que ocorre o inverso, logo concluimos que para escolher qual algoritmo iremos usar, é necessário que haja a verificação
do cenário onde esse algoritmo irá funcionar, tendo base quantidades ou tamanhos, modo como está inserido os dados, para que após analisar tudo isso, seja possível escolher o melhor algoritmo para aquele
caso em específico.

## Organização do Repositório

- **src/:** Onde se encontra a main.cpp e a classe MinMax;
- **Graphics/:** Onde se encontra os graficos e o script padrão utilizado para a montagem dos mesmos;
- **Docs/:** Onde se encontra a planilha e todos os arquivos .csv utilizados para criação dos gráficos;
- **datasets/:** Onde se encontra os arquivos gerados pelo programa;

## Ambiente de Execução

- **Processador**: Core i5-12450H 4,4 GHz
- **Placa de Vídeo**: RTX 3050 4gb
- **Memória RAM**: 16GB 2400MHz
- **Disco**: SSD 512 gb
- **IDE**: Visual Studio Code
- **SO**: Linux Zorin

# Compilação e Execução

O código disponibilizado possui um arquivo Makefile que realiza todo o procedimento de compilação e execução. Para tanto, temos as seguintes diretrizes de execução:

| Comando                |  Função                      |                     
| -----------------------| ---------------------------- |
|  `make r`              | Compilar o código            |



