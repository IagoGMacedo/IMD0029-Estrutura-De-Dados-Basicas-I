#include "../include/Dicionario.h"
#include <iostream>

Dicionario::Dicionario(const int capacidade)
{
    // TO-DO
}

Dicionario::~Dicionario()
{
    // TO-DO
}

bool Dicionario::inserir(const std::string& chave, const int& valor)
{
    // TO-DO
    return true;
}

bool Dicionario::atualizar(const std::string& chave, const int& valor)
{
    // TO-DO
    return false;
}

bool Dicionario::remover(const std::string& chave)
{
    // TO-DO
    return false;
}

int* Dicionario::buscar(const std::string& chave) const
{
    // TO-DO
    return nullptr;
}

int Dicionario::tamanho() const
{
    return quantidade;
}

void Dicionario::imprimir() const
{
    std::cout << "{ ";
    for (int i = 0; i < quantidade; i++) 
    {
        std::cout << "(" << elementos[i].chave << ": " << elementos[i].valor << ") ";
    }
    std::cout << "}\n";
}
