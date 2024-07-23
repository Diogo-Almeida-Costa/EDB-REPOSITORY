#include "Conjunto.h"
#include <iostream>

Conjunto::Conjunto(int _capacidade)
{
    this->capacidade = _capacidade;
    this->elementos = new int[this->capacidade];
    this->quantidade = 0;
}

Conjunto::~Conjunto()
{
    delete[] elementos;
}

//repare que é uma busca sequencial, portanto é de complexidade linear também
//Se mantivermos ordenação podemos usar busca binária e ter custo log(n)
bool Conjunto::buscar(int elemento) const
{
   for(int i = 0; i < this->quantidade; i++)
   {
        if(this->elementos[i] == elemento)
        {
            return true;
        }
   }
   return false;
}

//Pior caso é linear, precisa percorrer todo mundo
//Se mantivermos ordenação vamos ter um custo maior, visto que uma vez que inserirmos um elemento iremos
//ter que mover todos os elementos maiores que ele.
bool Conjunto::inserir(int elemento)
{
    if(this->quantidade == this->capacidade)
    {
        return false;
    }
    for(int i = 0; i < quantidade; i++)
    {
        if(this->elementos[i] == elemento)
        {
            return false;
        }
    }
    this->elementos[this->quantidade] = elemento;

    ++this->quantidade;
    return true;
}

//Os piores casos são: tentar remover um elemento que não esta ou tentar remover o 
//primeiro(vai ter que deslocar quase todo os elementos), que é de complexidade linear também
//Mesmo se deixarmos o array ordenado vamos ter o caso linear quando formos remover o primeiro elemento
bool Conjunto::remover(int elemento)
{
    for(int i = 0; i < this->quantidade; i++)
    {
        if(this->elementos[i] == elemento)
        {
            for(int j = i; j < this->quantidade-1; j++)
            {
                this->elementos[j] = this->elementos[j+1];
            }
            --this->quantidade;
            return true;
        }
    }

    return false;
}

int Conjunto::tamanho() const
{
    return quantidade;
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
