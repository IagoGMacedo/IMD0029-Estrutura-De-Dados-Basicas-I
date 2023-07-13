//
//  TabelaHash.h
//
//  Created by Eiji Adachi Medeiros Barbosa
//

#ifndef TabelaHash_h
#define TabelaHash_h

#include "Par.h"
#include <string>

using Elemento = Par<const std::string, const std::string*>;

static const std::size_t TAMANHO_PADRAO = 17;
static const float CARGA_LIMITE_INFERIOR = 2.0f;
static const float CARGA_LIMITE_SUPERIOR = 8.0f;

class TabelaHash {
private:
    Elemento **tabela;
    
    std::size_t tamanho;
    
    std::size_t quantidade;

    void setTamanho(const std::size_t&);
    
public:    
    void iniciar();
    
    std::size_t preHash(const std::string&);
    
    std::size_t hash(const std::string&);
    
    TabelaHash();
    
    TabelaHash(const std::size_t tamanho);
    
    ~TabelaHash();    
    
    const std::string* buscar(const std::string& chave);
    
    bool inserir(const std::string& chave, const std::string* valor);
    
    bool remover(const std::string& chave);
    
    std::size_t getTamanho();
    
    std::size_t getQuantidade();
    
    bool vazia();
    
    bool cheia();

    bool verificarDuplicatas();
    
    void imprimir();

    float fatorDeCarga();

    void aumentar();

    void diminuir();

    void redimensionar(const std::size_t&);
};


#endif /* TabelaHash_h */

