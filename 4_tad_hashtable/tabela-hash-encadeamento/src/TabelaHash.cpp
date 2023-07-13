//
//  TabelaHash.cpp
//
//  Criado por Eiji Adachi Medeiros Barbosa
//

#include "../include/TabelaHash.h"
#include <string>
#include <iostream>

TabelaHash::TabelaHash()
{
    this->tamanho = TAMANHO_PADRAO;
    iniciar();
}

TabelaHash::TabelaHash(const std::size_t tamanho)
{
    this->tamanho = tamanho;
    iniciar();
}

void TabelaHash::iniciar()
{
    this->tabela = new Elemento*[ this->getTamanho() ];
    this->quantidade = 0;
    for( std::size_t i = 0; i < this->getTamanho(); i++ )
    {
        this->tabela[i] = nullptr;
    }
}

TabelaHash::~TabelaHash()
{
}

bool TabelaHash::inserir(const std::string& chave, const std::string* valor)
{
    return chave == "" || *valor == "";
}

const std::string* TabelaHash::buscar(const std::string& chave)
{
    return nullptr;
}

bool TabelaHash::remover(const std::string& chave)
{
    return false;
}

float TabelaHash::fatorDeCarga()
{
    return (float)this->getQuantidade() / (float)this->getTamanho();
}

void TabelaHash::aumentar()
{
    std::size_t tamanhoNovo = 2*this->getTamanho() + 1;
    this->redimensionar(tamanhoNovo);
}

void TabelaHash::diminuir()
{
    std::size_t metadeTamanho = this->getTamanho()/2;
    std::size_t tamanhoNovo = metadeTamanho % 2 == 0 ? metadeTamanho + 1 : metadeTamanho;
    this->redimensionar(tamanhoNovo);
}

void TabelaHash::redimensionar(const std::size_t& tamanhoNovo)
{
    return;
}

std::size_t TabelaHash::preHash(const std::string& chave)
{
    std::size_t x = 0;
    for(std::size_t i = 0; i < chave.size(); i++)
    {
        // Não mudar!
        // Coloquei propositalmente uma versão simples pra facilitar a criação de colisões nos testes!
        x += chave.at(i);
    }
    return x;
}

std::size_t TabelaHash::hash(const std::string& chave)
{
    std::size_t hashValue = this->preHash(chave);
    return hashValue % this->getTamanho();
}

std::size_t TabelaHash::getTamanho()
{
    return this->tamanho;
}

void TabelaHash::setTamanho(const std::size_t& tamanhoNovo)
{
    this->tamanho = tamanhoNovo;
}

std::size_t TabelaHash::getQuantidade()
{
    return this->quantidade;
}

bool TabelaHash::vazia()
{
    return this->quantidade == 0;
}

bool TabelaHash::cheia()
{
    return this->quantidade == this->getTamanho();
}

bool TabelaHash::verificarDuplicatas()
{
    return true;
}

void TabelaHash::imprimir()
{
    for(std::size_t i = 0; i < this->getTamanho(); ++i)
    {
        if(this->tabela[i] == nullptr)
        {
            std::cout << "[" << i << "] = null" << std::endl;
        }
        else
        {
            std::cout << "[" << i << "] = " ;
            auto aux = this->tabela[i];
            while(aux!=nullptr)
            {
                std::cout << "{ " << aux->getChave() << "," << *aux->getValor() << " } -> ";
                
                aux = aux->getProximo();
            }
            std::cout << "null" << std::endl;
            
        }
    }
}
