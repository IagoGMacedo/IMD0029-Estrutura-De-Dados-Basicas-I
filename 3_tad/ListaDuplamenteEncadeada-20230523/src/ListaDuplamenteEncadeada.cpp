//
//  ListaDuplamenteEncadeada.cpp
//
//  Criado por Eiji Adachi Medeiros Barbosa
//

#include "../include/ListaDuplamenteEncadeada.h"

ListaDuplamenteEncadeada::ListaDuplamenteEncadeada()
{
    this->cabeca = new No<std::string>("CABECA_NAO_DEVE_SER_ACESSADA");
    this->cauda = new No<std::string>("CAUDA_NAO_DEVE_SER_ACESSADA");
    
    this->cabeca->setProximo(this->cauda);
    this->cabeca->setAnterior(nullptr);

    this->cauda->setProximo(nullptr);
    this->cauda->setAnterior(this->cabeca);

    this->quantidade = 0;
}

ListaDuplamenteEncadeada::~ListaDuplamenteEncadeada()
{
	No<std::string>* noRemover = this->cabeca->getProximo();
	while(noRemover->getProximo() != this->cauda){
		//não apaga cabeca nem cauda, incluir eles depois
		delete []noRemover;
		noRemover = noRemover->getProximo();
	}
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
	No<std::string>* noAtual = this->cabeca->getProximo();
	//noAtual = this->cabeca->getProximo();
	int contador = 1;
	while(noAtual->getProximo() != this->getCauda()){
		if(contador==i){
			return noAtual->getValor();
		}
		contador++;
		noAtual = noAtual->getProximo();
	}
	return "";
}

int ListaDuplamenteEncadeada::buscar(std::string s)
{
	No<std::string>* noAtual = new No<std::string>();
	noAtual = this->cabeca->getProximo();
	int contador = 1;
	while(noAtual->getProximo() != this->getCauda()){
		if(noAtual->getValor()==s){
			return contador;
		}
		contador++;
		noAtual = noAtual->getProximo();
	}
	return -1;
}

int ListaDuplamenteEncadeada::buscarMF(std::string s)
{
	//dont know what to do
	return -1;
}

bool ListaDuplamenteEncadeada::inserirNaCabeca(std::string s)
{   
    No<std::string>* novo = new No<std::string>(s);

    novo->setAnterior( this->getCabeca() );
    novo->setProximo( this->getCabeca()->getProximo() );

    // COMO NÃO FAZER
    // this->getCabeca()->getProximo()->setAnterior(novo);
    // this->getCabeca()->setProximo( novo );

    // COMO RECOMENDO FAZER
    novo->getAnterior()->setProximo( novo );
    novo->getProximo()->setAnterior( novo );

    ++this->quantidade;

    return true;
}

bool ListaDuplamenteEncadeada::inserirNaCauda(std::string s)
{    
	//criando o novo no com a string passada
	No<std::string>* novo = new No<std::string>(s);

	//primeiro vamos encadear ele
	novo->setProximo(this->cauda);
	novo->setAnterior(this->cauda->getAnterior());

	//agora vamos corrigir os demais
	novo->getProximo()->setAnterior(novo);
	novo->getAnterior()->setProximo(novo);
	this->quantidade++;
    return true;
}

bool ListaDuplamenteEncadeada::inserir(int i, std::string s)
{    
	if(!this->buscar(s)){
		No<std::string>* novo = new No<std::string>(s);
		No<std::string>* noPercorrendo = this->cabeca->getProximo();
		int contador = 1;
		while(noPercorrendo->getProximo() != this->cauda){
			if(contador==i){
				novo->setAnterior(noPercorrendo);
				novo->setProximo(noPercorrendo->getProximo());

				novo->getAnterior()->setProximo(novo);
				novo->getProximo()->setAnterior(novo);
				this->quantidade++;
				return true;

			}
		}
	}
	
	return false;
}

bool ListaDuplamenteEncadeada::inserirOrdenado(std::string s)
{
	return true;
}

std::string ListaDuplamenteEncadeada::removerDaCabeca(void)
{   
	if(this->quantidade>1){
		//ponteiro de no
		No<std::string>* noRemover = this->cabeca->getProximo();
		std::string stringRemover = noRemover->getValor();
		this->cabeca->setProximo(this->cabeca->getProximo()->getProximo());
		this->cabeca->getProximo()->setAnterior(this->cabeca);
		delete []noRemover;
		this->quantidade--;
		return stringRemover;
	}
	return "";
}

std::string ListaDuplamenteEncadeada::removerDaCauda(void)
{    
	if(this->quantidade>1){
		//ponteiro de no
		No<std::string>* noRemover = this->cauda->getAnterior();
		std::string stringRemover = noRemover->getValor();
		this->cauda->setAnterior(this->cauda->getAnterior()->getAnterior());
		this->cauda->getAnterior()->setProximo(this->cauda);
		delete []noRemover;
		this->quantidade--;
		return stringRemover;
	}
	return "";
}

std::string ListaDuplamenteEncadeada::remover(int i)
{    
	if(i<this->quantidade){
		No<std::string>* noRemover = this->cabeca->getProximo();
		int contador = 1;
		while(noRemover->getProximo() != this->cauda){
			if(contador==i){
				noRemover->getProximo()->setAnterior(noRemover->getAnterior());
				noRemover->getAnterior()->setProximo(noRemover->getProximo());
				this->quantidade--;
				std::string stringRemover = noRemover->getValor();
				delete []noRemover;
				return stringRemover;
			}
			contador++;
			noRemover = noRemover->getProximo();
		}
	}
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
