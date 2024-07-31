#ifndef __ListaDuplamenteEncadeada__
#define __ListaDuplamenteEncadeada__

#include "No.h"

class ListaDuplamenteEncadeada {
private:
    No<int>* cabeca;
    No<int>* cauda;
    int quantidade;
    
public:
    ListaDuplamenteEncadeada(void);
    ~ListaDuplamenteEncadeada(void);

    No<int>* buscaCont(int);

    bool inserirNaCabeca(int);


    No<int>* getCabeca(void);
    No<int>* getCauda(void);
    
    void imprimir(void);
    
    bool vazia(void);
    int tamanho(void);
};

#endif 
