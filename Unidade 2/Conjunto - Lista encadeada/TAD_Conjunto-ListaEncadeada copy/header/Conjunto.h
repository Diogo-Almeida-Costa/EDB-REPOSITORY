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
        int contarPar();
        int auxcontarPar(No* node);
        int contarNo();
        int auxcontarNo(No* node);
        //Essa parte é o que podemos manipular a partir de outros trechos
   
    private:
        No* inicio;
        int quantidade;
        //Isso aqui é restrito a quem está implementando
};

#endif