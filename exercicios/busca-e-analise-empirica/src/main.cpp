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
#include "../include/busca.h"

using namespace std;

void ler_entrada(const string, string[]);
void testar_busca(string[], int);

const int NAO_ENCONTRADO = -1;
const int TAMANHO = 10000000;
const string ARQUIVO = "./data/input.txt";

int main(int argc, const char * argv[]) 
{
    string *v = new string[TAMANHO];

    ler_entrada(ARQUIVO, v);

    testar_busca(v, TAMANHO);    

    delete [] v;

    return 0;
}

void testar_busca(string entrada[], int tamanho_total)
{
    // Essa chave não existe no arquivo, logo, estaremos exercitando o pior caso da busca
    string chave = "0000_XXXX_ZZZZ_7777_!!!!!";

    int quantidade_medicoes = 100;
    int incremento = tamanho_total / quantidade_medicoes;
    int tamanho_busca = tamanho_total / quantidade_medicoes;
    
    cout << "Tamanho,Tempo(microsegundos)" << endl;
    while(tamanho_busca <= tamanho_total)
    {
        auto inicio = std::chrono::high_resolution_clock::now();
        int indice_retornado = busca(entrada, tamanho_busca, chave);
        auto fim = std::chrono::high_resolution_clock::now();

        auto duracao = std::chrono::duration_cast<std::chrono::microseconds>(fim - inicio).count();

        cout << tamanho_busca << "," << duracao << endl;

        tamanho_busca += incremento;

        assert( indice_retornado == NAO_ENCONTRADO );
    }
}

void ler_entrada(const string arquivo, string v[]){
    ifstream arquivo_stream(arquivo);
    
    if(!arquivo_stream.good())
    {
        cout << "ERRO: Arquivo não encontrado: " << arquivo << endl;
        exit(-1);
    }
    
    int i = 0;

    while( ! arquivo_stream.eof() ){
        string x;
        arquivo_stream >> x;
        v[i] = x;
        i++;
    }
    
    arquivo_stream.close();
}
