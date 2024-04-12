#include "MinMax.hpp"
MinMax::MinMax()
{
    // Inicialização do vetor tempoMedioMinMax1
    tempoMedioMinMax1 = vector<vector<float>>(4, vector<float>(3, 0.0));
    tempoMedioMinMax2 = vector<vector<float>>(4, vector<float>(3, 0.0));
    tempoMedioMinMax3 = vector<vector<float>>(4, vector<float>(3, 0.0));
    apagarArquivos();
}

void MinMax::Execute()
{
    randomVetores();
    vector<int> v = {1000, 10000, 100000, 500000};
    for (int i = 0; i < 10; i++)
    {

        for (int j = 0; j < 4; j++)
        {
            int tamanho = v[j];

            MinMax1(tamanho, j);

            MinMax2(tamanho, j);

            MinMax3(tamanho, j);
        }
    }
    calculodasmedias();
    printMedia();
    clearVector();
}

void MinMax::apagarArquivos()
{
    ofstream arquivo;

    arquivo.open("datasets/MinMax1.csv");
    arquivo.close();

    arquivo.open("datasets/MinMax2.csv");
    arquivo.close();

    arquivo.open("datasets/MinMax3.csv");
    arquivo.close();

    arquivo.open("datasets/MediaGeral.txt");
    arquivo.close();
}

void MinMax::randomVetores()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(0, 1000);

    // filling the vector 1.000
    for (int i = 0; i < 1000; ++i)
    {
        vetor1000.push_back(dis(gen)); // Generate a random number and add it to the vector
    }

    // filling the vector 10.000
    for (int i = 0; i < 10000; ++i)
    {
        vetor10000.push_back(dis(gen)); // Generate a random number and add it to the vector
    }

    // filling the vector 100.000
    for (int i = 0; i < 100000; ++i)
    {
        vetor100000.push_back(dis(gen)); // Generate a random number and add it to the vector
    }

    // filling the vector 500.000
    for (int i = 0; i < 500000; ++i)
    {
        vetor500000.push_back(dis(gen)); // Generate a random number and add it to the vector
    }
}

float MinMax::duracaoMinMax1(vector<int> vetor, int tam)
{
    int min = vetor[0];
    int max = vetor[0];

    auto start = chrono::high_resolution_clock::now();

    for (int i = 1; i < tam; i++)
    {
        if (vetor[i] < min)
        {
            min = vetor[i];
        }

        if (vetor[i] > max)
        {
            max = vetor[i];
        }
    }

    auto end = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

    return duration.count();
}

float MinMax::duracaoMinMax2(vector<int> vetor, int tam)
{
    int min = vetor[0];
    int max = vetor[0];

    auto start = chrono::high_resolution_clock::now();

    for (int i = 1; i < tam; i++)
    {
        if (vetor[i] > max)
        {
            max = vetor[i];
        }
        else if (vetor[i] < min)
        {
            min = vetor[i];
        }
    }

    auto end = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

    return duration.count();
}

float MinMax::duracaoMinMax3(vector<int> vetor, int tam)
{
    int i = 0, FimDoAnel = 0, min, max;

    auto start = chrono::high_resolution_clock::now();

    if (tam % 2 > 0)
    {
        vetor.push_back(vetor[tam - 1]);
        FimDoAnel = tam;
    }
    else
    {
        FimDoAnel = tam - 1;
    }

    if (vetor[0] > vetor[1])
    {
        max = vetor[0];
        min = vetor[1];
    }
    else
    {
        max = vetor[1];
        min = vetor[0];
    }

    i = 2;

    while (i <= FimDoAnel)
    {
        if (vetor[i] > vetor[i + 1])
        {
            if (vetor[i] > max)
                max = vetor[i];
            if (vetor[i + 1] < min)
                min = vetor[i + 1];
        }
        else
        {
            if (vetor[i + 1] > max)
                max = vetor[i + 1];
            if (vetor[i] < min)
                min = vetor[i];
        }
        i = i + 2;
    }

    auto end = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

    return duration.count();
}

void MinMax::MinMax1(int tam, int pos)
{
    ofstream arquivo;

    float tempoaux = 0;

    arquivo.open("datasets/MinMax1.csv", ios::app);

    if (!arquivo)
    {
        cerr << "Erro ao abrir o arquivo." << endl;
        exit(1);
    }

    arquivo << tam << " ";

    if (pos == 0)
    {
        // vetor 1.000

        tempoaux = duracaoMinMax1(vetor1000, 1000);
        arquivo << tempoaux << " ";
        tempoMedioMinMax1[pos][0] += tempoaux;

        tempoaux = duracaoMinMax1(organizarCrescente(vetor1000), 1000);
        arquivo << tempoaux << " ";
        tempoMedioMinMax1[pos][1] += tempoaux;

        tempoaux = duracaoMinMax1(organizarDecrescente(vetor1000), 1000);
        arquivo << tempoaux << endl;
        tempoMedioMinMax1[pos][2] += tempoaux;
    }
    else if (pos == 1)
    {
        // vetor 10.000
        tempoaux = duracaoMinMax1(vetor10000, 10000);
        arquivo << tempoaux << " ";
        tempoMedioMinMax1[pos][0] += tempoaux;

        tempoaux = duracaoMinMax1(organizarCrescente(vetor10000), 10000);
        arquivo << tempoaux << " ";
        tempoMedioMinMax1[pos][1] += tempoaux;

        tempoaux = duracaoMinMax1(organizarDecrescente(vetor10000), 10000);
        arquivo << tempoaux << endl;
        tempoMedioMinMax1[pos][2] += tempoaux;
    }
    else if (pos == 2)
    {
        // vetor 100.000
        tempoaux = duracaoMinMax1(vetor100000, 100000);
        arquivo << tempoaux << " ";
        tempoMedioMinMax1[pos][0] += tempoaux;

        tempoaux = duracaoMinMax1(organizarCrescente(vetor100000), 100000);
        arquivo << tempoaux << " ";
        tempoMedioMinMax1[pos][1] += tempoaux;

        tempoaux = duracaoMinMax1(organizarDecrescente(vetor100000), 100000);
        arquivo << tempoaux << endl;
        tempoMedioMinMax1[pos][2] += tempoaux;
    }
    else if (pos == 3)
    {
        // vetor 500.000
        tempoaux = duracaoMinMax1(vetor500000, 500000);
        arquivo << tempoaux << " ";
        tempoMedioMinMax1[pos][0] += tempoaux;

        tempoaux = duracaoMinMax1(organizarCrescente(vetor500000), 500000);
        arquivo << tempoaux << " ";
        tempoMedioMinMax1[pos][1] += tempoaux;

        tempoaux = duracaoMinMax1(organizarDecrescente(vetor500000), 500000);
        arquivo << tempoaux << endl;
        tempoMedioMinMax1[pos][2] += tempoaux;
    }

    arquivo.close();
}

void MinMax::MinMax2(int tam, int pos)
{
    ofstream arquivo;
    float tempoaux = 0;

    arquivo.open("datasets/MinMax2.csv", ios::app);

    if (!arquivo)
    {
        cerr << "Erro ao abrir o arquivo." << endl;
        exit(1);
    }

    arquivo << tam << " ";

    if (pos == 0)
    {
        // vetor 1.000

        tempoaux = duracaoMinMax2(vetor1000, 1000);
        arquivo << tempoaux << " ";
        tempoMedioMinMax2[pos][0] += tempoaux;

        tempoaux = duracaoMinMax2(organizarCrescente(vetor1000), 1000);
        arquivo << tempoaux << " ";
        tempoMedioMinMax2[pos][1] += tempoaux;

        tempoaux = duracaoMinMax2(organizarDecrescente(vetor1000), 1000);
        arquivo << tempoaux << endl;
        tempoMedioMinMax2[pos][2] += tempoaux;
    }
    else if (pos == 1)
    {
        // vetor 10.000
        tempoaux = duracaoMinMax2(vetor10000, 10000);
        arquivo << tempoaux << " ";
        tempoMedioMinMax2[pos][0] += tempoaux;

        tempoaux = duracaoMinMax2(organizarCrescente(vetor10000), 10000);
        arquivo << tempoaux << " ";
        tempoMedioMinMax2[pos][1] += tempoaux;

        tempoaux = duracaoMinMax2(organizarDecrescente(vetor10000), 10000);
        arquivo << tempoaux << endl;
        tempoMedioMinMax2[pos][2] += tempoaux;
    }
    else if (pos == 2)
    {
        // vetor 100.000
        tempoaux = duracaoMinMax2(vetor100000, 100000);
        arquivo << tempoaux << " ";
        tempoMedioMinMax2[pos][0] += tempoaux;

        tempoaux = duracaoMinMax2(organizarCrescente(vetor100000), 100000);
        arquivo << tempoaux << " ";
        tempoMedioMinMax2[pos][1] += tempoaux;

        tempoaux = duracaoMinMax2(organizarDecrescente(vetor100000), 100000);
        arquivo << tempoaux << endl;
        tempoMedioMinMax2[pos][2] += tempoaux;
    }
    else if (pos == 3)
    {
        // vetor 500.000
        tempoaux = duracaoMinMax2(vetor500000, 500000);
        arquivo << tempoaux << " ";
        tempoMedioMinMax2[pos][0] += tempoaux;

        tempoaux = duracaoMinMax2(organizarCrescente(vetor500000), 500000);
        arquivo << tempoaux << " ";
        tempoMedioMinMax2[pos][1] += tempoaux;

        tempoaux = duracaoMinMax2(organizarDecrescente(vetor500000), 500000);
        arquivo << tempoaux << endl;
        tempoMedioMinMax2[pos][2] += tempoaux;
    }

    arquivo.close();
}

void MinMax::MinMax3(int tam, int pos)
{
    ofstream arquivo;

    float tempoaux = 0;

    arquivo.open("datasets/MinMax3.csv", ios::app);

    if (!arquivo)
    {
        cerr << "Erro ao abrir o arquivo." << endl;
        exit(1);
    }

    arquivo << tam << " ";

    if (pos == 0)
    {
        // vetor 1.000

        tempoaux = duracaoMinMax3(vetor1000, 1000);
        arquivo << tempoaux << " ";
        tempoMedioMinMax3[pos][0] += tempoaux;

        tempoaux = duracaoMinMax3(organizarCrescente(vetor1000), 1000);
        arquivo << tempoaux << " ";
        tempoMedioMinMax3[pos][1] += tempoaux;

        tempoaux = duracaoMinMax3(organizarDecrescente(vetor1000), 1000);
        arquivo << tempoaux << endl;
        tempoMedioMinMax3[pos][2] += tempoaux;
    }
    else if (pos == 1)
    {
        // vetor 10.000
        tempoaux = duracaoMinMax3(vetor10000, 10000);
        arquivo << tempoaux << " ";
        tempoMedioMinMax3[pos][0] += tempoaux;

        tempoaux = duracaoMinMax3(organizarCrescente(vetor10000), 10000);
        arquivo << tempoaux << " ";
        tempoMedioMinMax3[pos][1] += tempoaux;

        tempoaux = duracaoMinMax3(organizarDecrescente(vetor10000), 10000);
        arquivo << tempoaux << endl;
        tempoMedioMinMax3[pos][2] += tempoaux;
    }
    else if (pos == 2)
    {
        // vetor 100.000
        tempoaux = duracaoMinMax3(vetor100000, 100000);
        arquivo << tempoaux << " ";
        tempoMedioMinMax3[pos][0] += tempoaux;

        tempoaux = duracaoMinMax3(organizarCrescente(vetor100000), 100000);
        arquivo << tempoaux << " ";
        tempoMedioMinMax3[pos][1] += tempoaux;

        tempoaux = duracaoMinMax3(organizarDecrescente(vetor100000), 100000);
        arquivo << tempoaux << endl;
        tempoMedioMinMax3[pos][2] += tempoaux;
    }
    else if (pos == 3)
    {
        // vetor 500.000
        tempoaux = duracaoMinMax3(vetor500000, 500000);
        arquivo << tempoaux << " ";
        tempoMedioMinMax3[pos][0] += tempoaux;

        tempoaux = duracaoMinMax3(organizarCrescente(vetor500000), 500000);
        arquivo << tempoaux << " ";
        tempoMedioMinMax3[pos][1] += tempoaux;

        tempoaux = duracaoMinMax3(organizarDecrescente(vetor500000), 500000);
        arquivo << tempoaux << endl;
        tempoMedioMinMax3[pos][2] += tempoaux;
    }

    arquivo.close();
}

void MinMax::clearVector()
{

    // clearing vectors
    vetor1000.clear();
    vetor10000.clear();
    vetor100000.clear();
    vetor500000.clear();
}

void MinMax::calculodasmedias()
{

    // MINMAX1
    //  coluna 0 aleatorio, coluna 1 crescente, coluna 2 decrescente;
    //  linha 0 vetor 1000, linha 1 vetor 10.000, linha 2 vetor 100.000, linha 3 vetor 500.000;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            tempoMedioMinMax1[i][j] = tempoMedioMinMax1[i][j] / 10;
            tempoMedioMinMax2[i][j] = tempoMedioMinMax2[i][j] / 10;
            tempoMedioMinMax3[i][j] = tempoMedioMinMax3[i][j] / 10;
        }
    }
}

vector<int> MinMax::organizarCrescente(vector<int> vetor)
{
    sort(vetor.begin(), vetor.end());
    return vetor;
}

vector<int> MinMax::organizarDecrescente(vector<int> vetor)
{
    sort(vetor.begin(), vetor.end(), [](int a, int b)
         { return a > b; });
    return vetor;
}

void MinMax::printMedia()
{
    ofstream arquivo;

    arquivo.open("datasets/MediaGeral.txt");

    arquivo << "MEDIA MINMAX 1:\n";
    // vetor             //aleatorio                       //crescente                       //decrescente
    arquivo << "1000 " << tempoMedioMinMax1[0][0] << " " << tempoMedioMinMax1[0][1] << " " << tempoMedioMinMax1[0][2] << endl;
    arquivo << "10000 " << tempoMedioMinMax1[1][0] << " " << tempoMedioMinMax1[1][1] << " " << tempoMedioMinMax1[1][2] << endl;
    arquivo << "100000 " << tempoMedioMinMax1[2][0] << " " << tempoMedioMinMax1[2][1] << " " << tempoMedioMinMax1[2][2] << endl;
    arquivo << "500000 " << tempoMedioMinMax1[3][0] << " " << tempoMedioMinMax1[3][1] << " " << tempoMedioMinMax1[3][2] << endl;

    arquivo << "MEDIA MINMAX 2:\n";
    // vetor             //aleatorio                       //crescente                       //decrescente
    arquivo << "1000 " << tempoMedioMinMax2[0][0] << " " << tempoMedioMinMax2[0][1] << " " << tempoMedioMinMax2[0][2] << endl;
    arquivo << "10000 " << tempoMedioMinMax2[1][0] << " " << tempoMedioMinMax2[1][1] << " " << tempoMedioMinMax2[1][2] << endl;
    arquivo << "100000 " << tempoMedioMinMax2[2][0] << " " << tempoMedioMinMax2[2][1] << " " << tempoMedioMinMax2[2][2] << endl;
    arquivo << "500000 " << tempoMedioMinMax2[3][0] << " " << tempoMedioMinMax2[3][1] << " " << tempoMedioMinMax2[3][2] << endl;

    arquivo << "MEDIA MINMAX 3:\n";
    // vetor             //aleatorio                       //crescente                       //decrescente
    arquivo << "1000 " << tempoMedioMinMax3[0][0] << " " << tempoMedioMinMax3[0][1] << " " << tempoMedioMinMax3[0][2] << endl;
    arquivo << "10000 " << tempoMedioMinMax3[1][0] << " " << tempoMedioMinMax3[1][1] << " " << tempoMedioMinMax3[1][2] << endl;
    arquivo << "100000 " << tempoMedioMinMax3[2][0] << " " << tempoMedioMinMax3[2][1] << " " << tempoMedioMinMax3[2][2] << endl;
    arquivo << "500000 " << tempoMedioMinMax3[3][0] << " " << tempoMedioMinMax3[3][1] << " " << tempoMedioMinMax3[3][2] << endl;
}