#ifndef MINMAX_HPP
#define MINMAX_HPP
#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>
#include <fstream>

using namespace std;

class MinMax
{
private:
    // coluna 0 aleatorio, coluna 1 crescente, coluna 2 decrescente;
    // linha 0 vetor 1000, linha 1 vetor 10.000, linha 2 vetor 100.000, linha 3 vetor 500.000;
    vector<vector<float>> tempoMedioMinMax1;

    vector<vector<float>> tempoMedioMinMax2;

    vector<vector<float>> tempoMedioMinMax3;

    vector<int> vetor1000, vetor10000, vetor100000, vetor500000;

public:
    void randomVetores();
    void apagarArquivos();
    vector<int> organizarCrescente(vector<int> vetor);
    vector<int> organizarDecrescente(vector<int> vetor);
    float duracaoMinMax1(vector<int> vetor, int tam);
    float duracaoMinMax2(vector<int> vetor, int tam);
    float duracaoMinMax3(vector<int> vetor, int tam);
    void Execute();
    void MinMax1(int tam, int pos);
    void MinMax2(int tam, int pos);
    void MinMax3(int tam, int pos);
    void clearVector();
    void calculodasmedias();
    MinMax();
    void printMedia();
};

#endif