#include "../include/Conjunto.h"
#include <iostream>

Conjunto::Conjunto(int capacidade)
{
    this->capacidade=capacidade;
    this->elementos = new int[capacidade];
    this->quantidade = 0;
    //TO-DO
}

Conjunto::~Conjunto()
{
    //TO-DO
    delete []this->elementos;
}

bool Conjunto::buscar(int elemento) const
{
    for(int i =0;i<this->quantidade;i++){
        if(this->elementos[i]==elemento){
            return true;
        } 
    }
    return false;

}

bool Conjunto::inserir(int elemento)
{
    if(this->quantidade<this->capacidade && !this->buscar(elemento)){
        this->elementos[quantidade] = elemento;
        this->quantidade++;
        return true;
    } 
    return false;
}

bool Conjunto::remover(int elemento)
{
    //TO-DO
    if(this->buscar(elemento)){
        for(int i =0;i<this->quantidade;i++){
            if(this->elementos[i]==elemento){
                //abordagem de fazer swap
                int auxiliar = this->elementos[i];
                this->elementos[i] = this->elementos[this->quantidade-1];
                this->elementos[this->quantidade-1] = auxiliar;
                this->quantidade--;
                return true;
            }
        }
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
    for(int i = 0; i < quantidade; ++i)
    {
        std::cout << this->elementos[i] << " ";
    }
    std::cout << "}" << std::endl;
}
