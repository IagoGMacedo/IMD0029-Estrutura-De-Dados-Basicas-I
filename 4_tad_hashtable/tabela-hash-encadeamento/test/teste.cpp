#include "../lib/catch2/catch_amalgamated.hpp"
#include "../include/TabelaHash.h"
#include <iostream>

TEST_CASE("Tabela Hash - Teste do Construtor") 
{
    std::size_t tamanhoInicial = 23;
    
    TabelaHash tabela(tamanhoInicial);

    CHECK(tabela.getTamanho() == tamanhoInicial);

    CHECK(tabela.getQuantidade() == 0);

    CHECK(tabela.verificarDuplicatas());
}

TEST_CASE("Tabela Hash - Teste de Inserir Simples") 
{
    std::size_t tamanhoInicial = 23;
    
    TabelaHash tabela(tamanhoInicial);

    std::string chave = std::string("CHAVE");
    std::string valor = std::string("VALOR");

    auto quantidadeAntes = tabela.getQuantidade();
    bool inseriu = tabela.inserir(chave, &valor);
    auto quantidadeDepois = tabela.getQuantidade();

    CHECK(inseriu);
    CHECK(quantidadeAntes+1 == quantidadeDepois);
    CHECK(tabela.verificarDuplicatas());
}

TEST_CASE("Tabela Hash - Teste de Inserir Vários Seguidos") 
{
    std::size_t tamanhoInicial = 1379;
    
    TabelaHash tabela(tamanhoInicial);

    for(std::size_t i = 0; i < tamanhoInicial; ++i)
    {
        auto chave = std::string("CHAVE-" + std::to_string(i));
        auto valor = std::string("VALOR-" + std::to_string(i));
        tabela.inserir(chave, &valor);
    }

    CHECK(tabela.verificarDuplicatas());
}

TEST_CASE("Tabela Hash - Teste de Inserir e Buscar Simples") 
{
    std::size_t tamanhoInicial = 23;
    
    TabelaHash tabela(tamanhoInicial);

    auto chave = std::string("CHAVE");
    auto valorInserido = std::string("VALOR");

    tabela.inserir(chave, &valorInserido);    
    
    auto valorRetornado = tabela.buscar(chave);
    
    CHECK(valorInserido == *valorRetornado);
    CHECK(tabela.verificarDuplicatas());
}

TEST_CASE("Tabela Hash - Teste de Inserir com Colisões (Requer Busca)") 
{
    std::size_t tamanhoInicial = 23;
    
    TabelaHash tabela(tamanhoInicial);

    auto chave1 = std::string("CHAVE");
    auto valor1 = std::string("VALOR1");

    auto chave2 = std::string("AVECH");
    auto valor2 = std::string("VALOR2");

    bool inseriu1 = tabela.inserir(chave1, &valor1);
    bool inseriu2 = tabela.inserir(chave2, &valor2);
    
    CHECK(inseriu1);
    CHECK(inseriu2);

    CHECK(valor1 == *tabela.buscar(chave1));
    CHECK(valor2 == *tabela.buscar(chave2));    

    CHECK(tabela.verificarDuplicatas());
}

TEST_CASE("Tabela Hash - Teste de Inserir, Buscar e Remover Simples") 
{
    std::size_t tamanhoInicial = 23;
    
    TabelaHash tabela(tamanhoInicial);

    auto chave = std::string("CHAVE");
    auto valorInserido = std::string("VALOR");

    tabela.inserir(chave, &valorInserido); 

    CHECK(nullptr == tabela.buscar("CHAVE QUE NAO EXISTE"));   

    auto valorRetornado = tabela.buscar(chave);
    
    CHECK(valorInserido == *valorRetornado);

    auto quantidadeAntes = tabela.getQuantidade();
    
    auto removeu = tabela.remover(chave);
    
    auto quantidadeDepois = tabela.getQuantidade();

    CHECK(removeu);
    CHECK(quantidadeAntes == quantidadeDepois+1);

    valorRetornado = tabela.buscar(chave);

    CHECK(nullptr == valorRetornado);

    CHECK(tabela.verificarDuplicatas());
}

TEST_CASE("Tabela Hash - Teste de Inserir com Colisões, Remoções e Busca") 
{
    std::size_t tamanhoInicial = 23;
    
    TabelaHash tabela(tamanhoInicial);

    auto chave1 = std::string("CHAVE");
    auto valor1 = std::string("VALOR1");

    auto chave2 = std::string("ECHAV");
    auto valor2 = std::string("VALOR2");

    auto chave3 = std::string("VECHA");
    auto valor3 = std::string("VALOR3");

    auto chave4 = std::string("AVECH");
    auto valor4 = std::string("VALOR4");

    CHECK( tabela.inserir(chave1, &valor1) );
    CHECK( tabela.inserir(chave2, &valor2) );    
    CHECK( tabela.inserir(chave3, &valor3) );
    CHECK( tabela.inserir(chave4, &valor4) ); 

    CHECK( tabela.remover(chave1) );
    CHECK( tabela.remover(chave2) );

    CHECK( *tabela.buscar(chave4) == valor4 );

    CHECK(tabela.verificarDuplicatas());
}

TEST_CASE("Tabela Hash - Teste de Inserções sucessivas de mesma chave devem atualizar o valor") 
{
    TabelaHash tabela;

    auto chave1 = std::string("CHAVE");
    auto valor1 = std::string("VALOR1");

    tabela.inserir(chave1, &valor1);

    CHECK(*tabela.buscar(chave1) == valor1);

    auto novoValor = std::string("NOVO-VALOR");

    auto quantidadeAntes = tabela.getQuantidade();
    tabela.inserir(chave1, &novoValor);
    auto quantidadeApos = tabela.getQuantidade();

    CHECK(*tabela.buscar(chave1) == novoValor);
    CHECK(quantidadeAntes == quantidadeApos);

    CHECK(tabela.verificarDuplicatas());
}

TEST_CASE("Tabela Hash - Teste de Inserir-Atualizar com remoções no meio") 
{
    TabelaHash tabela;

    auto chave1 = std::string("CHAVE");
    auto valor1 = std::string("VALOR1");

    auto chave2 = std::string("ECHAV");
    auto valor2 = std::string("VALOR2");

    auto chave3 = std::string("VECHA");
    auto valor3 = std::string("VALOR3");

    auto chave4 = std::string("AVECH");
    auto valor4 = std::string("VALOR4");
    
    auto chave5 = std::string("HAVEC");
    auto valor5 = std::string("VALOR5");
    
    tabela.inserir(chave1, &valor1);
    tabela.inserir(chave2, &valor2);
    tabela.inserir(chave3, &valor3);
    tabela.inserir(chave4, &valor4);
    tabela.inserir(chave5, &valor5);
    tabela.remover(chave1);
    tabela.remover(chave2);    
    
    auto novoValor = std::string("NOVO");

    CHECK(tabela.inserir(chave5, &novoValor));
    CHECK(*tabela.buscar(chave5) == novoValor);
    CHECK(tabela.inserir(chave2, &valor2));

    CHECK(tabela.verificarDuplicatas());
}

TEST_CASE("Tabela Hash - Teste de Aumentar dinamicamente a tabela") 
{
    std::size_t tamanhoInicial = 1779;
    
    TabelaHash tabela(tamanhoInicial);

    auto chaveBase = "CHAVE--";
    auto valorBase = "VALOR--";

    for(std::size_t i = 0; i < 2*tamanhoInicial; i++)
    {
        auto chaveInserida = std::string( chaveBase + std::to_string(i) );

        tabela.inserir(chaveInserida, new std::string( valorBase + std::to_string(i) ));
    }

    // Esperado que a tabela cresça
    CHECK( tamanhoInicial < tabela.getTamanho() );

    for(std::size_t i = 0; i < tamanhoInicial; i++)
    {
        auto chaveInserida = std::string( chaveBase + std::to_string(i) );
        auto valorInserido = std::string( valorBase + std::to_string(i) );

        // É esperado encontrar todos elementos que estavam antes sejam encontrados após o aumento
        REQUIRE( valorInserido == *tabela.buscar(chaveInserida) );        
    }

    CHECK( tabela.fatorDeCarga() < CARGA_LIMITE_SUPERIOR );
}

TEST_CASE("Tabela Hash - Teste de Diminuir dinamicamente a tabela") 
{
    std::size_t tamanhoInicial = 1779;
    
    TabelaHash tabela(tamanhoInicial);

    auto chaveBase = "CHAVE--";
    auto valorBase = "VALOR--";

    for(std::size_t i = 0; i < 2*tamanhoInicial; i++)
    {
        auto chaveInserida = std::string(chaveBase + std::to_string(i));

        tabela.inserir(chaveInserida, new std::string(valorBase + std::to_string(i)));
    }

    for(std::size_t i = 0; i < tamanhoInicial; i++)
    {
        auto chaveInserida = chaveBase + std::to_string(i);
        auto valorInserido = valorBase + std::to_string(i);

        // É esperado encontrar todos elementos que estavam antes sejam encontrados após o aumento
        REQUIRE( valorInserido == *tabela.buscar(chaveInserida) );        
    }

    auto tamanhoAntesDasRemocoes = tabela.getTamanho();
    
    // Série de remoções para forçar a diminuição
    for(std::size_t i = 0; i < 2*tamanhoInicial; i++)
    {
        auto chaveRemovida = chaveBase + std::to_string(i);

        auto foiRemovido = tabela.remover(chaveRemovida);
        REQUIRE( foiRemovido );
    }  

    CHECK( tamanhoAntesDasRemocoes > tabela.getTamanho());
    CHECK( tabela.getQuantidade() == 0);

    CHECK( tabela.fatorDeCarga() < CARGA_LIMITE_SUPERIOR );
}