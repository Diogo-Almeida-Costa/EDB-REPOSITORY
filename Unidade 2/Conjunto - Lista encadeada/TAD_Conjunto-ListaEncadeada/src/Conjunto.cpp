#include "Conjunto.h"
#include <iostream>

Conjunto::Conjunto()
{
    this->inicio = nullptr;
    this->quantidade = 0;
}

Conjunto::~Conjunto()
{
    // TO-DO
}

bool Conjunto::buscar(int elemento) const
{
    return false;
}

bool Conjunto::inserir(int elemento)
{
    return false;
}

bool Conjunto::remover(int elemento)
{
    return false;
}

int Conjunto::tamanho() const
{
    return quantidade;
}

void Conjunto::imprimir() const
{
    if(quantidade != 0)
    {
        No* aux = this->inicio;
        std::cout << "{ ";
        while(aux != nullptr)
        {
            std::cout << aux->getValor() << " ";
            aux = aux->getProximo();
        }
        std::cout << "}" << std::endl;
    }
}
