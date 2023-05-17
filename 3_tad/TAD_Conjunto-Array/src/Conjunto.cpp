#include "../include/Conjunto.h"
#include <iostream>

Conjunto::Conjunto(int capacidade)
{
    this->quantidade=0;
    this->capacidade=capacidade;
    this->elementos= new int[capacidade];
}

Conjunto::~Conjunto()
{
    delete []this->elementos;
}

bool Conjunto::buscar(int elemento) const
{
    for(int i =0;i<this->quantidade;i++){
        if(elemento==*(this->elementos+i)){
            return true;
        }
    }
    return false;
}

bool Conjunto::inserir(int elemento)
{
    if(this->quantidade<this->capacidade && !this->buscar(elemento)){
        this->elementos[this->capacidade] = elemento;
        this->quantidade++;
    } else{
        return false;
    }
    return elemento != 0;
}

bool Conjunto::remover(int elemento)
{
    int indiceSwap;
    if(buscar(elemento)){
        for(int i =0;i<this->quantidade;i++){
            if(this->elementos[i]==elemento){
                indiceSwap = i;
                break;
            }
        }
        this->elementos[indiceSwap] = this->elementos[this->quantidade-1];
        this->quantidade--;
        return true;
    }
    return false;
}

int Conjunto::tamanho() const
{
    return this->quantidade;
}

void Conjunto::imprimir() const
{
    std::cout << "{ ";
    for(int i = 0; i < this->quantidade; ++i)
    {
        std::cout << this->elementos[i] << " ";
    }
    std::cout << "}" << std::endl;
}
