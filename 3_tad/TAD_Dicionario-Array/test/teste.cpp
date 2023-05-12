#define CATCH_CONFIG_MAIN
#include "../lib/catch2/catch.hpp"
#include "../include/Dicionario.h"

TEST_CASE("Inserir elementos no dic") {
    Dicionario dic(5);

    CHECK(dic.tamanho() == 0);

    CHECK(dic.inserir("A", 10) == true);
    CHECK(dic.tamanho() == 1);

    CHECK(dic.inserir("B", 20) == true);
    CHECK(dic.tamanho() == 2);

    CHECK(dic.inserir("C", 30) == true);
    CHECK(dic.tamanho() == 3);

    CHECK(dic.inserir("D", 40) == true);
    CHECK(dic.tamanho() == 4);

    CHECK(dic.inserir("E", 50) == true);
    CHECK(dic.tamanho() == 5);

    CHECK(dic.inserir("F", 60) == false);
    CHECK(dic.tamanho() == 5);

    CHECK(dic.inserir("G", 70) == false);
    CHECK(dic.tamanho() == 5);

    CHECK(dic.inserir("H", 80) == false);
    CHECK(dic.tamanho() == 5);

    CHECK(dic.inserir("I", 90) == false);
    CHECK(dic.tamanho() == 5);

    CHECK(dic.inserir("J", 100) == false);
    CHECK(dic.tamanho() == 5);
}

TEST_CASE("Buscar elementos no dic") {
    Dicionario dic(5);

    CHECK(dic.buscar("A") == nullptr);

    int x = 5;
    CHECK(dic.inserir("A", x) == true);
    CHECK(*dic.buscar("A") == x);

    int y = 6;
    CHECK(dic.inserir("B", y) == true);
    CHECK(*dic.buscar("B") == y);

    int z = 7;
    CHECK(dic.inserir("C", z) == true);
    CHECK(*dic.buscar("C") == z);

    CHECK(dic.buscar("D") == nullptr);
    CHECK(dic.buscar("E") == nullptr);
}

TEST_CASE("Remover elementos do dic") {
    Dicionario dic(5);

    CHECK(dic.remover("A") == false);

    CHECK(dic.inserir("A", 5) == true);
    CHECK(dic.tamanho() == 1);
    CHECK(dic.remover("A") == true);
    CHECK(dic.buscar("A") == nullptr);
    CHECK(dic.tamanho() == 0);

    CHECK(dic.inserir("B", 6) == true);
    CHECK(dic.inserir("C", 7) == true);
    CHECK(dic.inserir("D", 8) == true);
    CHECK(dic.inserir("E", 9) == true);

    CHECK(dic.tamanho() == 4);

    CHECK(*dic.buscar("D") == 8);
    CHECK(dic.remover("D") == true);
    CHECK(dic.buscar("D") == nullptr);
    CHECK(dic.tamanho() == 3);

    CHECK(*dic.buscar("B") == 6);
    CHECK(dic.remover("B") == true);
    CHECK(dic.buscar("B") == nullptr);
    CHECK(dic.tamanho() == 2);

    CHECK(*dic.buscar("E") == 9);
    CHECK(dic.remover("E") == true);
    CHECK(dic.buscar("E") == nullptr);
    CHECK(dic.tamanho() == 1);

    CHECK(*dic.buscar("C") == 7);
    CHECK(dic.remover("C") == true);
    CHECK(dic.buscar("C") == nullptr);
    CHECK(dic.tamanho() == 0);
}