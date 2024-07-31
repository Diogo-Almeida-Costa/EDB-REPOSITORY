//
//  No.h
//
//  Criado por Eiji Adachi Medeiros Barbosa 
//

#ifndef NO_H
#define NO_H

#include <string>

//O valor é o contéudo que cada nó deve armazenar, enquanto o ponteiro proximo aponta para o próximo
//nó dessa lista
class No
{
public:
    ~No(){};
    
    No( int val ){valor = val;}
    
    int getValor(){return valor;}
    
    void setValor(int val){valor = val;}

    No* getProximo(){return proximo;}

    void setProximo(No* p){proximo = p;} 

private:
    int valor;

    No* proximo;
};
#endif
