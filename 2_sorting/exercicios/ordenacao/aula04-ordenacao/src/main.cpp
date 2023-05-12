//
//  main.cpp
//
//  Created by Eiji Adachi Medeiros Barbosa 
//
#include <chrono>
#include <iostream>
#include <string>
#include <cassert>
#include <fstream>
#include "../include/ordenar.h"

using namespace std;

void ler_entrada(const string, string[], int);
void testar_ordenacao(string[], int);

const string ARQUIVO_DADOS_ENTRADA = "./data/input.txt";

int main(int argc, const char * argv[]) 
{
    if(argc != 2)
    {
        cerr << "ERRO: É necessário informar o tamanho do array a ser realizada a busca." << endl;
        exit(-1);
    }
    int tamanho = atoi(argv[1]);

    string *v = new string[tamanho];

    ler_entrada(ARQUIVO_DADOS_ENTRADA, v, tamanho);

    testar_ordenacao(v, tamanho);    

    delete [] v;

    return 0;
}

void testar_ordenacao(string entrada[], int tamanho_total)
{
    int quantidade_medicoes = 10;
    int incremento = tamanho_total / quantidade_medicoes;
    int tamanho_ordenacao = tamanho_total / quantidade_medicoes;
    
    cout << "Tamanho,Tempo(milisegundos)" << endl;
    while(tamanho_ordenacao <= tamanho_total)
    {
        auto inicio = std::chrono::high_resolution_clock::now();
        ordenar(entrada, tamanho_ordenacao);
        auto fim = std::chrono::high_resolution_clock::now();

        auto duracao = std::chrono::duration_cast<std::chrono::milliseconds>(fim - inicio).count();

        cout << tamanho_ordenacao << "," << duracao << endl;

        tamanho_ordenacao += incremento;
    }
}

void ler_entrada(const string arquivo, string v[], int TAMANHO){
    ifstream arquivo_stream(arquivo);
    
    if(!arquivo_stream.good())
    {
        cout << "ERRO: Arquivo não encontrado: " << arquivo << endl;
        exit(-1);
    }
    
    int i = 0;

    while( ! arquivo_stream.eof() && i < TAMANHO)
    {
        string x;
        arquivo_stream >> x;
        if(x.empty())
        {
            continue;
        }
        v[i] = x;
        i++;
    }
    
    arquivo_stream.close();
}
