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
   if(quantidade == 0)
   {
	return "";
   }
   else
   {
		No<std::string>* busca = this->cabeca->getProximo();
		if(i == 1)
		{
			return busca->getValor();
		}
		else
		{
			for(int b = 2; b <= quantidade; b++)
			{
				busca = busca->getProximo();
				if(i == b)
				{
					return busca->getValor();
				}
			}
		}
		return "";
   }
}

int ListaDuplamenteEncadeada::buscar(std::string s)
{
	if(quantidade == 0)
	{
		return -1;
	}
	else
	{
		No<std::string>* busca = this->cabeca->getProximo();
		for(int b = 1; b <= quantidade; b++)
		{
			if(busca->getValor() == s)
			{
				return b;
			}
			else
			{
				busca = busca->getProximo();
			}
		}
		return -1;
	}
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
	if(quantidade == 0)
	{
		return inserirNaCabeca(s);
	}
	if(i == 1)
	{
		return inserirNaCabeca(s);
	}
	if(i == quantidade)
	{
		return inserirNaCauda(s);
	}

	auto novo = new No<std::string>(s);

	No<std::string>* ant = this->cabeca->getProximo();

	for(int b = 2; b <= i-1; b++)
	{
		ant = ant->getProximo();
	}
	auto prox = ant->getProximo();
	novo->setAnterior(ant);
	novo->setProximo(prox);
	prox->setAnterior(novo);
	ant->setProximo(novo);
	++quantidade;
	return true;
}

std::string ListaDuplamenteEncadeada::removerDaCabeca(void)
{   
	if(quantidade == 0)
	{
		return "";
	}
	else
	{
		No<std::string>* elemento = this->cabeca->getProximo();
		this->cabeca->setProximo(elemento->getProximo());
		elemento->getProximo()->setAnterior(this->cabeca);
		std::string v = elemento->getValor();
		delete elemento;
		--quantidade;
		return v;
	}
}

std::string ListaDuplamenteEncadeada::removerDaCauda(void)
{    
    if(quantidade == 0)
	{
		return "";
	}
	else
	{
		No<std::string>* elemento = this->cauda->getAnterior();
		std::string v = elemento->getValor();
		this->cauda->setAnterior(elemento->getAnterior());
		elemento->getAnterior()->setProximo(this->cauda);
		delete elemento;
		--quantidade;
		return v;
	}
}

std::string ListaDuplamenteEncadeada::remover(int i)
{    
    if(quantidade == 0)
	{
		return "";
	}
	else
	{
		if(i == 1)
		{
			return removerDaCabeca();
		}
		else if (i == quantidade)
		{
			return removerDaCauda();
		}
		else
		{
			No<std::string>* elemento = this->cabeca->getProximo();
			for(int b = 1; b < quantidade; b++)
			{
				if(i == b)
				{
					auto ant = elemento->getAnterior();
					auto prox = elemento->getProximo();
					auto v = elemento->getValor();
					ant->setProximo(prox);
					prox->setAnterior(ant);
					delete elemento;
					--quantidade;
					return v;
				}
				else
				{
					elemento = elemento->getProximo();
				}
			}
			return "";
		}
		
	}
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
