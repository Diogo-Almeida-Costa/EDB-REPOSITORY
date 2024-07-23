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
        /*void setInicio(No* i){inicio=i;}*/ //Não seria legal porque permitiria que alguém de fora tivesse acesso
        int tamanho() const;
        void imprimir() const;
        //Essa parte é o que podemos manipular a partir de outros trechos
   
    private:
        No* inicio;
        int quantidade;
        //Isso aqui é restrito a quem está implementando
};

#endif