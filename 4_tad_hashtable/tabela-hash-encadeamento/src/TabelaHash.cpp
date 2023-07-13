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
    std::size_t indiceBase = this->hash(chave);
    if(this->tabela[indiceBase] == nullptr){
        Elemento* novoElemento = new Elemento(chave, valor);
        this->tabela[indiceBase] = novoElemento;
        this->quantidade++;
        return true;
    } else{
        Elemento * pAuxiliar = this->tabela[indiceBase];
        while(pAuxiliar != nullptr){
            if(pAuxiliar->getChave() == chave){
                pAuxiliar->setValor(valor);
                return true;
            }
            pAuxiliar = pAuxiliar->getProximo();
        }
        Elemento* novoElemento = new Elemento(chave, valor);
        novoElemento->setProximo(this->tabela[indiceBase]);
        this->tabela[indiceBase] = novoElemento;
        this->quantidade++;
        return true;
    }
    
}

const std::string* TabelaHash::buscar(const std::string& chave)
{
    std::size_t indiceBase = this->hash(chave);
    if(this->tabela[indiceBase] == nullptr){
        return nullptr;
    }else{
        Elemento * pAuxiliar = this->tabela[indiceBase];
        while(pAuxiliar != nullptr){
            if(pAuxiliar->getChave() == chave){
                return pAuxiliar->getValor();
            }
            pAuxiliar = pAuxiliar->getProximo();
        }
        return nullptr;
    }
}

bool TabelaHash::remover(const std::string& chave)
{
    std::size_t indiceBase = this->hash(chave);
    if(this->tabela[indiceBase] == nullptr){
        return false;
    }else{
        Elemento * pAuxiliar = this->tabela[indiceBase];
        Elemento * pAuxiliar2 = pAuxiliar;
        Elemento * pRemover;
        while(pAuxiliar != nullptr){
            if(pAuxiliar->getChave() == chave){
                if(pAuxiliar2==pAuxiliar){
                    //primeiro caso
                    if(pAuxiliar->getProximo() != nullptr){
                        this->tabela[indiceBase] = pAuxiliar->getProximo();
                    } else{
                        this->tabela[indiceBase] = nullptr;
                    }
                } else{
                    //diferente, anterior
                    pAuxiliar2->setProximo(pAuxiliar->getProximo());
                }
                pRemover = pAuxiliar;
                this->quantidade--;
                delete pRemover;
                return true;
            }
            pAuxiliar2 = pAuxiliar; //sempre eh o anterior
            pAuxiliar = pAuxiliar->getProximo();
        }
    }
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
    Elemento** dadosNovo = new Elemento*[tamanhoNovo];
    std::size_t tamanhoVelho =  this->tamanho;
    this->setTamanho(tamanhoNovo);
    Elemento** dadosVelho = this->tabela;
    Elemento* pAuxiliar;
    Elemento* pAuxiliar2;

    for(std::size_t i =0 ;i<tamanhoVelho;i++){
        if(dadosVelho[i] != nullptr){
            pAuxiliar = dadosVelho[i];
            while(pAuxiliar != nullptr){
                pAuxiliar2 = pAuxiliar;
                pAuxiliar = pAuxiliar->getProximo();
                std::size_t indice = this->hash(pAuxiliar2->getChave());
                if(dadosNovo[indice]==nullptr){
                    dadosNovo[indice] = pAuxiliar2;
                    dadosNovo[indice]->setProximo(nullptr);
                } else{
                    pAuxiliar2->setProximo(dadosNovo[indice]);
                    dadosNovo[indice] = pAuxiliar2;
                }

            }
        }
    }
    delete this->tabela;
    this->tabela = dadosNovo;
    this->setTamanho(tamanhoNovo);
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
