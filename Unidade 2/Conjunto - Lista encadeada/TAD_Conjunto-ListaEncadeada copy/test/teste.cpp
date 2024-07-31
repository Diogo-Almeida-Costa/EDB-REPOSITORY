#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Conjunto.h"

TEST_CASE("Inserir elementos no conjunto") {
    Conjunto conjunto;

    CHECK(conjunto.tamanho() == 0);

    CHECK(conjunto.inserir(10) == true);
    CHECK(conjunto.tamanho() == 1);

    CHECK(conjunto.inserir(20) == true);
    CHECK(conjunto.tamanho() == 2);

    CHECK(conjunto.inserir(30) == true);
    CHECK(conjunto.tamanho() == 3);

    CHECK(conjunto.inserir(40) == true);
    CHECK(conjunto.tamanho() == 4);

    CHECK(conjunto.inserir(50) == true);
    CHECK(conjunto.tamanho() == 5);
}

TEST_CASE("Buscar elementos no conjunto") {
    Conjunto conjunto;

    CHECK(conjunto.buscar(5) == false);

    CHECK(conjunto.inserir(5) == true);
    CHECK(conjunto.buscar(5) == true);

    CHECK(conjunto.inserir(6) == true);
    CHECK(conjunto.buscar(6) == true);

    CHECK(conjunto.inserir(7) == true);
    CHECK(conjunto.buscar(7) == true);

    CHECK(conjunto.buscar(8) == false);
    CHECK(conjunto.buscar(9) == false);
}

TEST_CASE("Remover elementos do conjunto") {
    Conjunto conjunto;

    CHECK(conjunto.remover(5) == false);

    CHECK(conjunto.inserir(5) == true);
    CHECK(conjunto.tamanho() == 1);
    CHECK(conjunto.buscar(5) == true);
    CHECK(conjunto.remover(5) == true);
    CHECK(conjunto.buscar(5) == false);
    CHECK(conjunto.tamanho() == 0);

    CHECK(conjunto.inserir(6) == true);
    CHECK(conjunto.inserir(7) == true);
    CHECK(conjunto.inserir(8) == true);
    CHECK(conjunto.inserir(9) == true);

    CHECK(conjunto.tamanho() == 4);

    CHECK(conjunto.buscar(8) == true);
    CHECK(conjunto.remover(8) == true);
    CHECK(conjunto.buscar(8) == false);
    CHECK(conjunto.tamanho() == 3);

    CHECK(conjunto.buscar(6) == true);
    CHECK(conjunto.remover(6) == true);
    CHECK(conjunto.buscar(6) == false);
    CHECK(conjunto.tamanho() == 2);

    CHECK(conjunto.buscar(9) == true);
    CHECK(conjunto.remover(9) == true);
    CHECK(conjunto.buscar(9) == false);
    CHECK(conjunto.tamanho() == 1);

    CHECK(conjunto.buscar(7) == true);
    CHECK(conjunto.remover(7) == true);
    CHECK(conjunto.buscar(7) == false);
    CHECK(conjunto.tamanho() == 0);
}

TEST_CASE("Contar par") 
{
    Conjunto conjunto;

    CHECK(conjunto.inserir(5) == true);

    CHECK(conjunto.inserir(6) == true);
    
    CHECK(conjunto.contarPar() == 1);

    CHECK(conjunto.inserir(7) == true);
    CHECK(conjunto.inserir(8) == true);
    CHECK(conjunto.inserir(9) == true);
    CHECK(conjunto.inserir(10) == true);
    CHECK(conjunto.inserir(18) == true);
    
    CHECK(conjunto.contarPar() == 4);
}

TEST_CASE("Contar nós") 
{
    Conjunto conjunto;

    CHECK(conjunto.inserir(5) == true);

    CHECK(conjunto.inserir(6) == true);
    
    CHECK(conjunto.contarNo() == 2);

    CHECK(conjunto.inserir(7) == true);
    CHECK(conjunto.inserir(8) == true);
    CHECK(conjunto.inserir(9) == true);
    CHECK(conjunto.inserir(10) == true);
    CHECK(conjunto.inserir(18) == true);
    
    CHECK(conjunto.contarNo() == 7);
}