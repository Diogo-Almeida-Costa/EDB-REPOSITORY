#ifndef CONJUNTO_H
#define CONJUNTO_H

#include <string>
#include "No.h"

class Conjunto 
{
    public:
        Conjunto();
        ~Conjunto();
        bool inserir(int elemento);
        bool remover(int elemento);
        bool buscar(int elemento) const;
        int tamanho() const;
        void imprimir() const;
   
    private:
        No* inicio;
        int quantidade;
};

#endif