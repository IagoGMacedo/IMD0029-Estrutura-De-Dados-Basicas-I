#include "../include/ListaDuplamenteEncadeada.h"
#include "../src/InsertionSort.hpp"


#include "iostream"
int main(void){
    /*
    ListaDuplamenteEncadeada lista;
    
    std::string v[] = {"alpha","bravo","charlie","delta","echo","fox","golf","hotel","india","juliet"};
    int tamanhoAntes = lista.tamanho();
    bool inseriu = lista.inserir( 1, v[0] );
    std::cout << "inserindo na cabeça: "<< std::endl;
    std::cout << "inseriu: "<< inseriu << std::endl;
    std::cout << "novo tamanho: "<< lista.tamanho() << std::endl;
    auto verificada = lista.checarConsistencia();
    std::cout << "status da lista: "<< verificada << std::endl;
    std::cout << "iterando"<< std::endl;
    int i = 1;
    for(auto s : v)
    {
        int tamanhoAntes = lista.tamanho();
        
        std::string valorInserido = s;
        
        int indice = i % 2 == 0 ? 2 : 1;
        
        verificada = lista.checarConsistencia();
//        std::cout << "status da lista: "<< verificada << std::endl;
        
        inseriu = lista.inserir(indice, valorInserido);
        std::cout << "inseriu: "<< inseriu << std::endl;
        auto valorRetornado = lista.recuperar(indice);
        std::cout << "valor retornado, valor inserido: "<< valorRetornado <<", "<< valorInserido << std::endl;
        int tamanhoDepois = lista.tamanho();
        std::cout << "novo tamanho:"<< tamanhoDepois <<", "<< valorInserido << std::endl;
        ++i;
    }
    */

   InsertionSort insertio;
   int valores[] = {200,8,5,2,4,1,100};
   insertio.ordenarTeste(valores, 7);
    return 0;
}