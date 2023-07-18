//
//  HashTable.cpp
//
//  Created by Eiji Adachi Medeiros Barbosa
//

#include "HashTable.h"
#include <string>
#include <iostream>

using namespace std;

HashEntry<std::string, std::string> *ENTRY_DELETED = (HashEntry<std::string,std::string>*)(-1);

HashTable::~HashTable()
{
    for( int i = 0; i < this->getSize(); i++ )
    {
        auto entry = this->data[i];
        
        if( entry != nullptr && entry != ENTRY_DELETED )
        {
            delete entry;
        }
    }
    delete [] data;
}

/**
 Este método deve inserir na tabela um novo HashEntry com 'key' e 'value' recebidos como parâmetros. Neste caso, a quantidade de itens na tabela deve ser incrementada e retorna-se 'true'.
 Caso já exista um HashEntry com atributo 'key' == parâmetro 'key', deve apenas atualizar o atributo 'value' do HashEntry. Neste caso, a quantidade de itens na tabela não é modificada e retorna-se 'true'.
 */
bool HashTable::put(const string key, const string value)
{
    int indiceBase = this->hash(key);
    int ultimaPosicaoDeletada;
    for(int delta = 0;delta<this->getSize();delta++){
        int posicaoAtual = (indiceBase + delta) % this->getSize();
        if(this->data[posicaoAtual]==ENTRY_DELETED){
            this->data[posicaoAtual] = new HashEntry<std::string,std::string>(key,value);
            this->quantity++;
            return true;
        } else if(this->data[posicaoAtual]==nullptr){
            this->data[posicaoAtual] = new HashEntry<std::string,std::string>(key,value);
            this->quantity++;
            return true;
        }else if(this->data[posicaoAtual]->getKey() == key){
            this->data[posicaoAtual]->setValue(value);
            return true;
        }
    }
    this->data[ultimaPosicaoDeletada] = new HashEntry<std::string,std::string>(key,value);
    this->quantity++;
    return true;
}

/**
 Este método deve remover da tabela o HashEntry cujo atributo 'key' == parâmetro 'key'. Neste caso, a quantidade de itens na tabela deve ser dencrementada e retorna-se 'true'.
 Caso não exista um HashEntry com atributo 'key' == parâmetro 'key',a quantidade de itens na tabela não é modificada e retorna-se 'false'.
 */
bool HashTable::remove(const string key)
{
    cout << "ERRO: Método HashTable::remove ainda não foi implementado.\n";
    abort();
}

/**
 Este método deve fazer o reajuste do tamanho do array interno da tabela.

 */
void HashTable::resize(const unsigned long newSize)
{
    cout << "ERRO: Método HashTable::resize ainda não foi implementado.\n";
    abort();
}

/***
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 !!!!!! NÃO MUDE QUALQUER FUNÇÃO DAQUI PARA BAIXO !!!!!! 
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 ***/

HashTable::HashTable(const unsigned long size)
{
    this->size = size;
    this->data = new HashEntry<std::string, string>*[this->getSize()];
    this->quantity = 0;
    for( int i = 0; i < this->getSize(); i++ )
    {
        // Atribui-se nulo às posições da tabela para termos certeza de que estão vazias
        this->data[i] = nullptr;
    }
}

unsigned long HashTable::preHash(const string key)
{
    unsigned long x = 0;
    for(unsigned int i = 0; i < key.size(); i++)
    {
        // Não mudar!
        // Coloquei propositalmente uma versão simples pra facilitar a criação de colisões nos testes!
        x += key.at(i);
    }
    return x;
}

unsigned long HashTable::hash(const string key)
{
    unsigned long hashValue = this->preHash(key);
    return hashValue % this->getSize();
}

unsigned long HashTable::getSize()
{
    return this->size;
}

unsigned long HashTable::getQuantity()
{
    return this->quantity;
}

bool HashTable::isEmpty()
{
    return this->quantity == 0;
}

bool HashTable::isFull()
{
    return this->quantity == this->getSize();
}

void HashTable::print()
{
    for(int i = 0; i < this->getSize(); i++)
    {
        HashEntry<string, string> * entry = data[i];
        if( entry == ENTRY_DELETED )
        {
            std::cout << i << ": DELETED" << std::endl;
        }
        else if( entry != nullptr )
        {
            std::cout << i << ": " << entry->getKey() << ":" << entry->getValue() << std::endl;
        }
        else
        {
            std::cout << i << ": []" << std::endl;
        }
    }
}