//
//  ListaDuplamenteEncadeada.cpp
//
//  Criado por Eiji Adachi Medeiros Barbosa
//

#include "ListaDuplamenteEncadeada.h"

ListaDuplamenteEncadeada::ListaDuplamenteEncadeada()
{
    this->cabeca = new No<std::string>("ESSE_E_O_CONTEUDO_DA_CABECA_--NAO_DEVE_SER_ACESSADA");
    this->cauda = new No<std::string>("ESSE_E_O_CONTEUDO_DA_CAUDA_--CAUDA_NAO_DEVE_SER_ACESSADA");
    
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

No<std::string>* ListaDuplamenteEncadeada::getCabeca(void)
{
    return this->cabeca;
}

No<std::string>* ListaDuplamenteEncadeada::getCauda(void)
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

std::string ListaDuplamenteEncadeada::recuperar(int i)
{
   return "";
}

int ListaDuplamenteEncadeada::buscar(std::string s)
{
	return -1;
}

bool ListaDuplamenteEncadeada::inserirNaCabeca(std::string s)
{   
    auto novo = new No<std::string>(s);
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

bool ListaDuplamenteEncadeada::inserirNaCauda(std::string s)
{    
    auto novo = new No<std::string>(s);
	novo->setAnterior(this->cauda->getAnterior());
	novo->setProximo(this->cauda);

	novo->getAnterior()->setProximo(novo); //estou setando o novo nó como o próximo em relação ao antigo que estava mais próximo da cauda
	novo->getProximo()->setAnterior(novo); //estou setando o novo nó como o anterior em relação à cauda

	++quantidade;
	
	return true;
}

bool ListaDuplamenteEncadeada::inserir(int i, std::string s)
{    
	/*if(i == 1 && quantidade == 0)
	{
		return inserirNaCabeca(s);
	}*/
	//verifica se a posição i é válida
	if(i < 0 || i > quantidade)
	{
		return false;
	}

	//Note que se i igual a zero, estamos inserindo na verdade inserindo na posição adjacente a cabeça
	if(i == 0)
	{
		return inserirNaCabeca(s);
	}

	//Note que se i é igual a quantidade, então estamos inserido na posição adjacente a cauda
	if(i == quantidade)
	{
		return inserirNaCauda(s);
	}

	auto novo = new No<std::string>(s);

	No<std::string>* atual = this->cabeca->getProximo(); //Começa do proximo da cabeça pois cabeça não conta por ser uma sentinela

	//estamos buscando o elemento localizado na posição i-1, que é o antecessor a posição que queremos inserir o
	//novo nó
	for(int pos = 0; pos < i-1; pos++)
	{
		atual = atual->getProximo();
	}

	novo->setAnterior(atual);
	novo->setProximo(atual->getProximo());
	atual->setProximo(novo);
	(novo->getProximo())->setAnterior(novo);

	++quantidade;

	return true;

}

std::string ListaDuplamenteEncadeada::removerDaCabeca(void)
{   
    return "";
}

std::string ListaDuplamenteEncadeada::removerDaCauda(void)
{    
    return "";
}

std::string ListaDuplamenteEncadeada::remover(int i)
{    
    return "";
}

void ListaDuplamenteEncadeada::imprimir(void)
{
	for(auto n = this->cabeca->getProximo(); n != this->cauda; n = n->getProximo())
	{
		std::cout << n->getValor() << " ";
	}
	std::cout << std::endl;
}

StatusDaLista ListaDuplamenteEncadeada::checarConsistencia()
{
	if( this->cabeca == nullptr )
	{
		return CABECA_NULA;
	}
	else if( this->cabeca->getProximo() == nullptr )
	{
		return CABECA_PROXIMO_NULO;
	}
	else if( this->cabeca->getProximo()->getAnterior() != this->cabeca )
	{
		return ENCADEAMENTO_INCORRETO;
	}
	else if( this->cabeca->getAnterior() != nullptr )
	{
		return CABECA_ANTERIOR;
	}
	
	if( this->cauda == nullptr )
	{
		return CAUDA_NULA;
	}
	else if( this->cauda->getAnterior() == nullptr )
	{
		return CAUDA_ANTERIOR_NULO;
	}
	else if( this->cauda->getAnterior()->getProximo() != this->cauda )
	{
		return ENCADEAMENTO_INCORRETO;
	}
	else if( this->cauda->getProximo() != nullptr )
	{
		return CAUDA_PROXIMO;
	}
	
	if(this->vazia())
	{
		if( this->cabeca->getProximo() != this->cauda )
		{
			return CABECA_CAUDA;
		}
		
		if( this->cabeca != this->cauda->getAnterior() )
		{
			return CABECA_CAUDA;
		}
	}
	else
	{
		// Verifica encadeamento dos elementos
		for(No<std::string>* i = this->cabeca->getProximo(); i != this->cauda; i=i->getProximo())
		{
			if( i->getProximo()->getAnterior() != i )
			{
				return ENCADEAMENTO_INCORRETO;
			}
			if( i->getAnterior()->getProximo() != i )
			{
				return ENCADEAMENTO_INCORRETO;
			}
		}
	}
	
	return OK;
}
