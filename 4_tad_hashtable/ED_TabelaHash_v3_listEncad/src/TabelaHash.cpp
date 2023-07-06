//
//  TabelaHash.cpp
//
//  Criado por Eiji Adachi Medeiros Barbosa
//

#include "../include/TabelaHash.h"
#include <string>
#include <iostream>

using namespace std;

Par<std::string, std::string> *REMOVIDO = (Par<std::string,std::string>*)(-1);

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
    this->tabela = new Par<std::string, string>*[ this->getTamanho() ];
    this->quantidade = 0;
    for( std::size_t i = 0; i < this->getTamanho(); i++ )
    {
        this->tabela[i] = nullptr;
    }
}

TabelaHash::~TabelaHash()
{
    for( std::size_t i = 0; i < this->getTamanho(); i++ )
    {
        Par<string, string>* entry = this->tabela[i];
        
        if( entry != nullptr && entry != REMOVIDO )
        {
            delete entry;
        }
    }
    delete [] tabela;
}

/**
 Este método deve inserir na tabela um novo Par com 'chave' e 'valor' recebidos como parâmetros. Neste caso, a quantidade de itens na tabela deve ser incrementada e retorna-se 'true'.
 Caso já exista um Par com atributo 'chave' == parâmetro 'chave', deve apenas atualizar o atributo 'valor' do Par. Neste caso, a quantidade de itens na tabela não é modificada e retorna-se 'true'.
 */
bool TabelaHash::inserir(const string chave, const string valor)
{
    /*
        entendi o erro aqui:
        como meu critério é nulo OU removido, ele não percorre
        o suficiente até chegar no ponto em que ele iria atualizar
        por isso eu tenho que percorrer, ver se acho, e só depois
        inserir em um removido.
    */
    std::size_t indiceBase = this->hash(chave);
    std::size_t indiceRemover = 0;
    for(std::size_t delta = 0; delta<this->getTamanho(); delta++){
        std::size_t indiceAtual = (indiceBase + delta) % this->getTamanho();
        if(this->tabela[indiceAtual] == REMOVIDO){
            indiceRemover = indiceAtual;
        }else if(this->tabela[indiceAtual]==nullptr){
            this->tabela[indiceAtual] = new Par<std::string, std::string>(chave,valor);
            this->quantidade++;

            if(this->fatorDeCarga()>= CARGA_LIMITE_SUPERIOR){
                this->aumentar();
            }
            return true;
        } else if(this->tabela[indiceAtual]->getChave() == chave){
            this->tabela[indiceAtual]->setValor(valor);
            return true;
        } 
    }
    this->tabela[indiceRemover] = new Par<std::string, std::string>(chave,valor);
    this->quantidade++;
    return true;
}

/**
 Este método deve buscar na tabela um Par com 'chave', retornando o 'valor' associado. 
 */
std::string TabelaHash::buscar(const string chave)
{
    if(this->vazia()){
        return "TABELA VAZIA";
    }
    auto indiceBase = this->hash(chave);
    for(std::size_t delta = 0; delta<this->getTamanho(); delta++){
        auto indiceAtual = (indiceBase + delta) % this->getTamanho();
        if(this->tabela[indiceAtual] != nullptr && this->tabela[indiceAtual] != REMOVIDO && this->tabela[indiceAtual]->getChave() == chave){
            return this->tabela[indiceAtual]->getValor();
        }
    }
    return "NÃO ACHOU";
}

/**
 Este método deve remover da tabela o Par cujo atributo 'chave' == parâmetro 'chave'. Neste caso, a quantidade de itens na tabela deve ser dencrementada e retorna-se 'true'.
 Caso não exista um Par com atributo 'chave' == parâmetro 'chave',a quantidade de itens na tabela não é modificada e retorna-se 'false'.
 */
bool TabelaHash::remover(const string chave)
{
    if(this->vazia()){
        return false;
    }
    auto indiceBase = this->hash(chave);
    for(std::size_t delta = 0;delta<this->getTamanho();delta++){
        auto indiceAtual = (indiceBase+delta) % this->getTamanho();
        if(this->tabela[indiceAtual] != nullptr && this->tabela[indiceAtual] != REMOVIDO && this->tabela[indiceAtual]->getChave() == chave){
            this->tabela[indiceAtual] = REMOVIDO;
            this->quantidade--;
            if(this->fatorDeCarga()<CARGA_LIMITE_INFERIOR){
                this->diminuir();
            }
            return true;
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

void TabelaHash::redimensionar(std::size_t tamanhoNovo)
{
    std::size_t tamanhoVelho = this->getTamanho();
    //Par<std::string, std::string> **antigaTabela = this->tabela;

    Par<std::string, std::string> **novaTabela = new Par<std::string, string>*[tamanhoNovo];
    for(std::size_t i =0;i<tamanhoNovo;i++){
        novaTabela[i] = nullptr;
    }

    //percorrendo o array velho
    this->setTamanho(tamanhoNovo);
    for(std::size_t i =0;i<tamanhoVelho;i++){
        auto elementoAtual = this->tabela[i];
        if(elementoAtual != nullptr && elementoAtual != REMOVIDO){
            auto indiceBase = this->hash(elementoAtual->getChave());
            for(std::size_t delta = 0; delta<tamanhoNovo;delta++){
                auto indiceAtual = (indiceBase + delta) % tamanhoNovo;
                if(novaTabela[indiceAtual] == nullptr){
                    novaTabela[indiceAtual] = elementoAtual;
                    break;
                }
            }
        }
    }
    delete this->tabela;
    this->tabela = novaTabela;
}

std::size_t TabelaHash::preHash(const string chave)
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

std::size_t TabelaHash::hash(const string chave)
{
    std::size_t hashValue = this->preHash(chave);
    return hashValue % this->getTamanho();
}

std::size_t TabelaHash::getTamanho()
{
    return this->tamanho;
}

void TabelaHash::setTamanho(std::size_t tamanhoNovo)
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
    
    for(std::size_t i = 0; i < tamanho; ++i)
    {
        auto elementoI = this->tabela[i];
        if(elementoI != nullptr && elementoI != REMOVIDO)
        {
            for(std::size_t j = i+1; j < tamanho; ++j)
            {
                auto elementoJ = this->tabela[j];
                if(elementoJ != nullptr && elementoJ != REMOVIDO)
                {
                    if(elementoI->getChave() == elementoJ->getChave())
                    {
                        // Repetição de chaves
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

void TabelaHash::imprimir()
{
    for(std::size_t  i = 0; i < this->getTamanho(); i++)
    {
        Par<string, string> * entry = tabela[i];
        if( entry == REMOVIDO )
        {
            std::cout << i << ": REMOVIDO" << std::endl;
        }
        else if( entry != nullptr )
        {
            std::cout << i << ": " << entry->getChave() << ":" << entry->getValor() << std::endl;
        }
        else
        {
            std::cout << i << ": []" << std::endl;
        }
    }
}