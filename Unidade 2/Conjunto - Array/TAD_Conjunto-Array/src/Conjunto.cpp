#include "Conjunto.h"
#include <iostream>

Conjunto::Conjunto(int capacidade)
{
    //TO-DO
}

Conjunto::~Conjunto()
{
    //TO-DO
}

bool Conjunto::buscar(int elemento) const
{
   //TO-DO
    return elemento != 0;
}

bool Conjunto::inserir(int elemento)
{
    //TO-DO
    return elemento != 0;
}

bool Conjunto::remover(int elemento)
{
    //TO-DO
    return elemento != 0;
}

int Conjunto::tamanho() const
{
    //TO-DO
    return 0;
}

void Conjunto::imprimir() const
{
    std::cout << "{ ";
    for(int i = 0; i < quantidade; ++i)
    {
        std::cout << this->elementos[i] << " ";
    }
    std::cout << "}" << std::endl;
}
