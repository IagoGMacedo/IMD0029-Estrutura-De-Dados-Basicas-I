//
//  main.cpp
//
//  Criado por Eiji Adachi Medeiros Barbosa
//

#include "../include/TabelaHash.h"
#include <iostream>

int main(int argc, const char * argv[]) 
{
    unsigned long tamanhoInicial = 23;
    
    TabelaHash tabela(tamanhoInicial);

    std::string chave = "CHAVE";
    std::string valorInserido = "VALOR";
    std::cout << tabela.inserir(chave, valorInserido) <<std::endl;
    std::cout << tabela.buscar("CHAVE QUE NAO EXISTE") <<std::endl;
    auto valorRetornado = tabela.buscar(chave);
    std::cout << "iguais:"<< valorRetornado <<std::endl;
    auto quantidadeAntes = tabela.getQuantidade();
    auto removeu = tabela.remover(chave);
    auto quantidadeDepois = tabela.getQuantidade();
    std::cout << "removeu:"<< removeu <<std::endl;
    std::cout << "quantidade:"<< quantidadeDepois <<std::endl;


    valorRetornado = tabela.buscar(chave);
    std::cout << "valor retornado:"<< valorRetornado <<std::endl;
    return 0;
}

