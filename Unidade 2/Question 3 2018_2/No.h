
#ifndef __No__
#define __No__

#include <iostream>
template <typename T>
class No
{
private:
    T valor;
    No* proximo;
    No* anterior;
    int cont = 0;
    
public:
    No();
    
    No( T );
    
    No( T, No*, No* );
    
    T getValor();
    
    void setValor(T val);
    
    No* getProximo();
    
    void setProximo(No*);
	
	No* getAnterior();
	
	void setAnterior(No*);

    void setCont(int);

    int getCont();

};

template<typename T>
No<T>::No(void):
proximo(NULL) {}

template<typename T>
No<T>::No(T val):
valor(val), proximo(NULL), anterior(NULL) {}
 
template<typename T>
No<T>::No(T val, No* n, No* p):
valor(val), proximo(n), anterior(p) {}

template<typename T>
T No<T>::getValor(void)
{
    return this->valor;
}

template<typename T>
void No<T>::setValor(T t)
{
    this->valor = t;
}

template<typename T>
No<T>* No<T>::getProximo(void)
{
    return this->proximo;
}

template<typename T>
void No<T>::setProximo(No<T>* n)
{
    this->proximo = n;
}

template<typename T>
No<T>* No<T>::getAnterior(void)
{
	return this->anterior;
}

template<typename T>
void No<T>::setAnterior(No<T>* p)
{
	this->anterior = p;
}

template<typename T>
int No<T>::getCont()
{
    return this->cont;
}

template<typename T>
void No<T>::setCont(int k)
{
    this->cont = k;
}


#endif 
