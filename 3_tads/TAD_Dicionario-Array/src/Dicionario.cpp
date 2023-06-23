#include "../include/Dicionario.h"
#include <iostream>

Dicionario::Dicionario(const int capacidade)
{
    this->elementos = new Par[capacidade];
    this->quantidade = 0;
    this->capacidade = capacidade;
}

Dicionario::~Dicionario()
{
    delete []this->elementos;
}

bool Dicionario::inserir(const std::string& chave, const int& valor)
{
    if(!buscar(chave)){
        if(this->quantidade<this->capacidade){
            Par novoPar = {chave, valor};
            this->elementos[this->quantidade] = novoPar;
            this->quantidade++;
            return true;
        } 
    }
    return false;
}

bool Dicionario::atualizar(const std::string& chave, const int& valor)
{
    if(buscar(chave)){
        //não sei se é ok fazer isso ou faço normal
        *buscar(chave) = valor;
    }
    return false;
}

bool Dicionario::remover(const std::string& chave)
{
    if(buscar(chave)){
        for(int i =0;i<this->quantidade;i++){
            if(this->elementos[i].chave==chave){
                Par auxiliar = this->elementos[i];
                this->elementos[i] = this->elementos[this->quantidade-1];
                this->elementos[this->quantidade-1] = auxiliar;
                this->quantidade--;
                return true;
            }
        }
    }
    return false;
}

int* Dicionario::buscar(const std::string& chave) const
{
    for(int i =0;i<this->quantidade;i++){
        if(this->elementos[i].chave == chave){
            return &this->elementos[i].valor;
        }
    }
    return nullptr;
}

int Dicionario::tamanho() const
{
    return this->quantidade;
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
