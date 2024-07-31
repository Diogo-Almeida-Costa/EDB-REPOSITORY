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
    if(this->quantidade == 0)
    {
        return false;
    }
    else
    {
        No* aux = this->inicio;
        while(aux != nullptr)
        {
            if(elemento == aux->getValor())
            {
                return true;
            }       
            else
            {
                aux = aux->getProximo();
            }
        }
        return false;
    }
}

bool Conjunto::inserir(int elemento)
{
   //No* aux = this->inicio;

   No* novoNo = new No(elemento);
 
   novoNo->setProximo(this->inicio);
   this->inicio = novoNo;
   ++this->quantidade;
   return true;
   //Esse novo elemento é adicionado no inicio da lista, como o primeiro elemento
   //Adicionar como último elemento traria complicação pois precisariamos de uma referência para o anterior
}

bool Conjunto::remover(int elemento)
{
    if(this->quantidade == 0)
    {
        return false;
    }
    else
    {
        No* aux = this->inicio;
        No* ant = nullptr;
        while(aux != nullptr)
        {
            if(aux->getValor() == elemento)
            {
                //Achamos o valor dentro do vetor e precisamos remover ele
                if(aux == this->inicio)
                {
                    //coloco como o inicio o próximo em relação ao auxiliar
                    this->inicio = aux->getProximo();
                }
                else
                {
                    //como é um elemento diferente do inicio, seguimos a lógica de usar o anterior para 
                    //apagarmos o auxiliar
                    ant->setProximo(aux->getProximo());
                }
                delete aux;
                --this->quantidade;
                return true;
            }
            else
            {
                ant = aux; // garantimos que o anterior é sempre o valor antes de auxiliar
                aux = aux->getProximo();
            }
        }
        //Percorri a lista toda e não achei o elemento, portanto não tem o que remover
        return false;
    }
}

int Conjunto::contarPar()
{
    auto aux = this->inicio;
    return auxcontarPar(aux);
}

int Conjunto::auxcontarPar(No* node)
{
    int cont;
    if(node == nullptr)
    {
        return 0;
    }
    else if(node->getValor()%2 == 0)
    {
        cont = 1;
    }
    else
    {
        cont = 0;
    }
    return cont+auxcontarPar(node->getProximo());
}

int Conjunto::contarNo()
{
    auto aux = this->inicio;
    return auxcontarNo(aux);
}

int Conjunto::auxcontarNo(No* node)
{
    int cont;
    if(node == nullptr)
    {
        return 0;
    }
    else
    {
        cont = 1;
        node = node->getProximo();
    }
    return cont+auxcontarNo(node);
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
