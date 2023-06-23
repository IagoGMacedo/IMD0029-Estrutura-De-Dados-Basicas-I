/**
 * @file Dicionario.h
 * @brief Declaração da classe Dicionario e struct Par.
 */
#pragma once

#include <string>

/**
 * @brief Classe que representa um dicionário.
 */
class Dicionario {
    public:
        /**
         * @brief Construtor da classe Dicionario.
         * @param capacidade A capacidade máxima do dicionário.
         */
        Dicionario(const int capacidade);

        /**
         * @brief Destrutor da classe Dicionario.
         */
        ~Dicionario();

        /**
         * @brief Insere um par chave-valor no dicionário.
         * @param chave A chave do par.
         * @param valor O valor do par.
         * @return true se a inserção foi bem-sucedida, false caso contrário.
         */
        bool inserir(const std::string& chave, const int& valor);

        /**
         * @brief Atualiza o valor de uma chave no dicionário.
         * @param chave A chave a ser atualizada.
         * @param valor O novo valor da chave.
         * @return true se a atualização foi bem-sucedida, false caso contrário.
         */
        bool atualizar(const std::string& chave, const int& valor);

        /**
         * @brief Remove um par chave-valor do dicionário.
         * @param chave A chave do par a ser removido.
         * @return true se a remoção foi bem-sucedida, false caso contrário.
         */
        bool remover(const std::string& chave);

        /**
         * @brief Busca o valor associado a uma chave no dicionário.
         * @param chave A chave a ser buscada.
         * @return Um ponteiro para o valor associado à chave, ou nullptr se a chave não for encontrada.
         */
        int* buscar(const std::string& chave) const;

        /**
         * @brief Retorna a quantidade de pares chave-valor no dicionário.
         * @return A quantidade de pares chave-valor no dicionário.
         */
        int tamanho() const;

        /**
         * @brief Imprime o dicionário.
         */
        void imprimir() const;

 private:
    /**
     * @brief Struct que representa um par de chave-valor.
     */
    struct Par 
    {
        std::string chave; /**< A chave do par. */
        int valor;         /**< O valor do par. */
    };
    Par* elementos;   /**< Um array de pares chave-valor. */
    int capacidade;   /**< A capacidade máxima do dicionário. */
    int quantidade;   /**< A quantidade atual de pares chave-valor no dicionário. */
};
