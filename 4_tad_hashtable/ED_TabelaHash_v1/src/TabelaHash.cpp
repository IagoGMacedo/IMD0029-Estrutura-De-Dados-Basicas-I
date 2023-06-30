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

TabelaHash::TabelaHash(const unsigned long tamanho)
{ 
    this->tamanho = tamanho;
    iniciar();
}

void TabelaHash::iniciar()
{
    //ponteiro de ponteiro: entenda como um array de ponteiros
    this->tabela = new Par<std::string, string>*[ this->getTamanho() ];
    this->quantidade = 0;
    for( unsigned long i = 0; i < this->getTamanho(); i++ )
    {
        this->tabela[i] = nullptr;
    }
}

TabelaHash::~TabelaHash()
{
    for( unsigned i = 0; i < this->getTamanho(); i++ )
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
 Este método deve   na tabela um novo Par com 'chave' e 'valor' recebidos como parâmetros. Neste caso, a quantidade de itens na tabela deve ser incrementada e retorna-se 'true'.
 Caso já exista um Par com atributo 'chave' == parâmetro 'chave', deve apenas atualizar o atributo 'valor' do Par. Neste caso, a quantidade de itens na tabela não é modificada e retorna-se 'true'.
 */
bool TabelaHash::inserir(const string chave, const string valor)
{
    if(this->cheia()){
        return false;
    }
    /*
    auto codigohash = this->hash(chave);
    int deslocamento = 1;
    while(this->tabela[codigohash] != nullptr && this->tabela[codigohash] != REMOVIDO){
        if(this->tabela[codigohash]->getChave() == chave){
            //atualiza
            this->tabela[codigohash]->setValor(valor);
            return true;
        }
        codigohash = (codigohash+deslocamento) % this->getTamanho();
        std::cout << "novo cod: "<< codigohash << std::endl;
        deslocamento++;
    }
    this->tabela[codigohash] = new Par<std::string, std::string>(chave, valor);
    this->quantidade++;
    return true; */
    auto indiceBase = this->hash(chave);
    for(std::size_t delta = 0; delta<this->getTamanho();delta++){
        auto indiceAtual = (indiceBase + delta) % this->getTamanho();
        if(this->tabela[indiceAtual]==nullptr){
            tabela[indiceAtual] = new Par<std::string, std::string>(chave, valor);;
            this->quantidade++;
            return true;
        } else if(this->tabela[indiceAtual] != REMOVIDO && this->tabela[indiceAtual]->getChave() == chave){
            this->tabela[indiceAtual]->setValor(valor);
            return true;
        }
    }
    return false;

    /*
    int deslocamento = 0;
    for(int i = ((codigohash+deslocamento)%this->getTamanho()); i < this->getTamanho(); deslocamento++){
        if(this->tabela[i] == nullptr || this->tabela[i] == REMOVIDO){
            this->tabela[i] = new Par<std::string, std::string>(chave, valor);
            this->quantidade++;
            return true;
        } else if(this->tabela[i]->getChave() == chave){
            this->tabela[i]->setValor(valor);
            this->quantidade++;
            return true;
        }
    }
    return false;
    */
}

/**
 Este método deve buscar na tabela um Par com 'chave', retornando o 'valor' associado. 
 */
std::string TabelaHash::buscar(const string chave)
{
    if(this->vazia()){
        return "TABELA VAZIA";
    }
    auto codigohash = this->hash(chave);
    int deslocamento = 1;
    //talvez aqui seja melhor usar um for
    /*
    while(this->tabela[codigohash] != nullptr && this->tabela[codigohash] != REMOVIDO && this->tabela[codigohash]->getChave() != chave){
        codigohash = (codigohash+deslocamento) % this->getTamanho();
        deslocamento++;
    }
    */
    for(int i = codigohash;i<this->getTamanho();i++){
        if(this->tabela[i] != nullptr && this->tabela[i] != REMOVIDO && this->tabela[i]->getChave() == chave){
            return this->tabela[i]->getValor();
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
    std::cout << "começou o metodo" << std::endl;

    if(this->vazia()){
        return false;
    }
    auto hashValue = this->hash(chave);
    int deslocamento = 1;
    
    for(int i = hashValue; i<this->getTamanho();i++){
        if(this->tabela[i] != nullptr && this->tabela[i] != REMOVIDO &&  this->tabela[i]->getChave() == chave){
            Par<std::string, std::string> * removeItem = this->tabela[i];
            this->tabela[i] = REMOVIDO;
            this->quantidade--;
            delete removeItem;
            return true;
        }
    }
    /*
    while(this->tabela[hashValue]!=nullptr && this->tabela[hashValue]->getChave() != chave){
        hashValue = (hashValue+deslocamento)%this->getTamanho();
        deslocamento++;
    }
    Par<std::string, std::string> * removeItem = this->tabela[hashValue];
    this->tabela[hashValue] = REMOVIDO;
    this->quantidade--;
    delete removeItem;
    return true;
    std::cout << "fim do metodo" << std::endl;
    */
   return false;
    
}

unsigned long TabelaHash::preHash(const string chave)
{
    unsigned long x = 0;
    for(unsigned int i = 0; i < chave.size(); i++)
    {
        // Não mudar!
        // Coloquei propositalmente uma versão simples pra facilitar a criação de colisões nos testes!
        x += chave[i];
    }
    return x;
}

unsigned long TabelaHash::hash(const string chave)
{
    unsigned long hashValue = this->preHash(chave);
    return hashValue % this->getTamanho();
}

unsigned long TabelaHash::getTamanho()
{
    return this->tamanho;
}

unsigned long TabelaHash::getQuantidade()
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
    
    for(unsigned long i = 0; i < tamanho; ++i)
    {
        auto elementoI = this->tabela[i];
        if(elementoI != nullptr && elementoI != REMOVIDO)
        {
            for(unsigned long j = i+1; j < tamanho; ++j)
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
    for(unsigned long  i = 0; i < this->getTamanho(); i++)
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
