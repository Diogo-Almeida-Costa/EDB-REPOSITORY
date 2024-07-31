
#include "ListaDuplamenteEncadeada.h"

ListaDuplamenteEncadeada::ListaDuplamenteEncadeada()
{
    this->cabeca = new No<int>(0);
    this->cauda = new No<int>(0);
    
    this->cabeca->setProximo(this->cauda);
    this->cabeca->setAnterior(nullptr);

    this->cauda->setProximo(nullptr);
    this->cauda->setAnterior(this->cabeca);

    this->quantidade = 0;
}

ListaDuplamenteEncadeada::~ListaDuplamenteEncadeada()
{
    // TO-DO
}

No<int>* ListaDuplamenteEncadeada::getCabeca(void)
{
    return this->cabeca;
}

No<int>* ListaDuplamenteEncadeada::getCauda(void)
{
    return this->cauda;
}

int ListaDuplamenteEncadeada::tamanho(void)
{
    return this->quantidade;
}

bool ListaDuplamenteEncadeada::vazia(void)
{
    return this->tamanho() == 0;
}


bool ListaDuplamenteEncadeada::inserirNaCabeca(int s)
{   
    auto novo = new No<int>(s);
	novo->setAnterior(this->cabeca);
	novo->setProximo(this->cabeca->getProximo());

	//novo->getProximo() esse trecho do código é um ponteiro em si, o antigo ponteiro que estava do lado
	//da cabeça 
	//->setAnterior(novo); seta como o anterior desse nó o novo nó criado 
	novo->getProximo()->setAnterior(novo);
	novo->getAnterior()->setProximo(novo); //coloca como o próximo da cabeça o novo nó criado

	++quantidade;
	
	return true;
}

No<int>* ListaDuplamenteEncadeada::buscaCont(int k)
{
    auto aux = this->cabeca->getProximo();
    while(aux != this->cauda)
    {
        if(aux->getValor() == k)
        {
            aux->setCont(aux->getCont()+1);
            auto ant = aux->getAnterior();
            while(ant->getCont() < aux->getCont() && ant != this->cabeca)
            {
                ant = ant->getAnterior();
            }
            aux->getProximo()->setAnterior(aux->getAnterior());
            aux->getAnterior()->setProximo(aux->getProximo());
            aux->setAnterior(ant->getAnterior());
            ant->getAnterior()->setProximo(aux);
            ant->setAnterior(aux);
            aux->setProximo(ant);
            return aux;
        }
        else
        {
            aux = aux->getProximo();
        }
    }
    return this->cauda;
}

void ListaDuplamenteEncadeada::imprimir(void)
{
	for(auto n = this->cabeca->getProximo(); n != this->cauda; n = n->getProximo())
	{
		std::cout << n->getValor() << " ";
	}
	std::cout << std::endl;
}