#define CATCH_CONFIG_MAIN
#include "../lib/catch2/catch.hpp"
#include "../include/ListaDuplamenteEncadeada.h"

TEST_CASE("Inserir na cabeça da lista") 
{
    ListaDuplamenteEncadeada lista;
    
    std::string v[] = {"alpha","bravo","charlie","delta","echo","fox","golf","hotel","india","juliet"};
    
    for(int i = 0; i < 10; i++)
    {
        int tamanhoAntes = lista.tamanho();
        
        auto valorInserido = v[i];

        CHECK(lista.checarConsistencia() == OK);
                
        bool inseriu = lista.inserirNaCabeca( valorInserido );

        CHECK(inseriu);

        CHECK(lista.checarConsistencia() == OK);
        
        auto primeiroElemento = lista.getCabeca()->getProximo();

        CHECK(primeiroElemento != nullptr);
        
        auto primeiroValor = primeiroElemento->getValor();

        CHECK(primeiroValor == valorInserido);
        
        int tamanhoDepois = lista.tamanho();

        CHECK(tamanhoDepois == tamanhoAntes+1);
    }
}

TEST_CASE("Inserir na cauda da lista") 
{
    ListaDuplamenteEncadeada lista;
    
    std::string v[] = {"alpha","bravo","charlie","delta","echo","fox","golf","hotel","india","juliet"};
    
    for(int i = 0; i < 10; i++)
    {
        int tamanhoAntes = lista.tamanho();
        
        auto valorInserido = v[i];

        CHECK(lista.checarConsistencia() == OK);
                
        bool inseriu = lista.inserirNaCauda( valorInserido );

        CHECK(inseriu);

        CHECK(lista.checarConsistencia() == OK);
        
        auto ultimoElemento = lista.getCauda()->getAnterior();

        CHECK(ultimoElemento != nullptr);
        
        auto ultimoValor = ultimoElemento->getValor();

        CHECK(ultimoValor == valorInserido);
        
        int tamanhoDepois = lista.tamanho();

        CHECK(tamanhoDepois == tamanhoAntes+1);
    }
}

TEST_CASE("Recuperar elemento da i-ésima posição da lista") 
{
    ListaDuplamenteEncadeada lista;
    
    std::string v[] = {"alpha","bravo","charlie","delta","echo","fox","golf","hotel","india","juliet"};
    
    for(int i = 0; i < 10; i++)
    {
        CHECK( lista.inserirNaCauda( v[i] ) );
    }

    for(int i = 0; i < 10; i++)
    {
        CHECK( lista.recuperar(i+1) == v[i] );
    }
}

TEST_CASE("Inserir na i-ésima posição da lista") 
{
    ListaDuplamenteEncadeada lista;
    
    std::string v[] = {"alpha","bravo","charlie","delta","echo","fox","golf","hotel","india","juliet"};
    
    int tamanhoAntes = lista.tamanho();
    bool inseriu = lista.inserir( 1, v[0] );
    
    CHECK(inseriu);
    
    int tamanhoDepois = lista.tamanho();
    
    CHECK(tamanhoAntes+1 == tamanhoDepois);

    auto verificada = lista.checarConsistencia();

    CHECK(verificada == OK);
    
    for(int i = 1; i < 10; i++)
    {
        int tamanhoAntes = lista.tamanho();
        
        std::string valorInserido = v[i];
        
        int indice = i % 2 == 0 ? 2 : 1;
        
        verificada = lista.checarConsistencia();
        CHECK(verificada == OK);
        
        inseriu = lista.inserir(indice, valorInserido);
        CHECK(inseriu);
        
        auto valorRetornado = lista.recuperar(indice);

        CHECK(valorRetornado == valorInserido);
        
        int tamanhoDepois = lista.tamanho();
        CHECK(tamanhoAntes+1 == tamanhoDepois);
    }
}

TEST_CASE("Remover elemento da cabeça da lista")
{
    ListaDuplamenteEncadeada lista;
    
    std::string v[] = {"alpha","bravo","charlie","delta","echo","fox","golf","hotel","india","juliet"};
    
    for(int i = 0; i < 10; i++)
    {
        auto valorInserido = v[i];
        lista.inserirNaCabeca( valorInserido );
    }
    
    for(int i = 0; i < 10; i++)
    {
        auto verificada = lista.checarConsistencia();
        CHECK( verificada == OK );
        
        int tamanhoAntes = lista.tamanho();
        auto valorRemovido = lista.removerDaCabeca();
        int tamanhoDepois = lista.tamanho();
        
        CHECK( tamanhoDepois == tamanhoAntes-1 );
        
        auto valorEsperado = v[9-i];

        CHECK( valorRemovido == valorEsperado );
    }
}

TEST_CASE("Remover elemento da cauda da lista")
{
    ListaDuplamenteEncadeada lista;
    
    std::string v[] = {"alpha","bravo","charlie","delta","echo","fox","golf","hotel","india","juliet"};
    
    for(int i = 0; i < 10; i++)
    {
        auto valorInserido = v[i];
        lista.inserirNaCauda( valorInserido );
    }
    
    for(int i = 0; i < 10; i++)
    {
        auto verificada = lista.checarConsistencia();
        CHECK( verificada == OK );
        
        int tamanhoAntes = lista.tamanho();
        auto valorRemovido = lista.removerDaCauda();
        int tamanhoDepois = lista.tamanho();
        
        CHECK( tamanhoDepois == tamanhoAntes-1 );
        
        auto valorEsperado = v[9-i];

        CHECK( valorRemovido == valorEsperado );
    }
}

TEST_CASE("Remover elemento da i-ésima posição da lista")
{
    ListaDuplamenteEncadeada lista;
    
    std::string v[] = {"alpha","bravo","charlie","delta","echo","fox","golf","hotel","india","juliet"};
    
    for(int i = 0; i < 10; i++)
    {
        auto valorInserido = v[i];
        lista.inserirNaCabeca( valorInserido );
    }
    
    for(int i = 0; i < 10; i++)
    {
        auto verificada = lista.checarConsistencia();
        CHECK( verificada == OK );
        
        int tamanhoAntes = lista.tamanho();
        auto valorRemovido = lista.remover(1);
        int tamanhoDepois = lista.tamanho();
        
        CHECK( tamanhoDepois == tamanhoAntes-1 );
        
        auto valorEsperado = v[9-i];

        CHECK( valorRemovido == valorEsperado );
    }
}

TEST_CASE("Buscar elemento na lista")
{
    ListaDuplamenteEncadeada lista;
    
    std::string v[] = {"alpha","bravo","charlie","delta","echo","fox","golf","hotel","india","juliet"};
    
    for(int i = 0; i < 10; i++)
    {
        auto valorInserido = v[i];
        lista.inserirNaCauda(valorInserido);
    }
    
    for(int i = 0; i < 10; i++)
    {
        auto valorBuscado = v[i];
        int indiceRetornado = lista.buscar(valorBuscado);

        CHECK(indiceRetornado == i+1);
        
        auto verificada = lista.checarConsistencia();

        CHECK( verificada == OK );
    }
    
    std::string inexistentes[] = {"0", "50", "100", "200"};
    
    for(int i = 0; i < 4; i++)
    {
        int indiceRetornado = lista.buscar(inexistentes[i]);
        CHECK( indiceRetornado == -1 );
        
        auto verificada = lista.checarConsistencia();
        CHECK( verificada == OK );
    }
}