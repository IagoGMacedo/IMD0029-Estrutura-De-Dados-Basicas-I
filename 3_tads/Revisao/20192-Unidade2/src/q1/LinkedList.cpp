//
//  LinkedList.cpp
//
//  Created by Eiji Adachi Medeiros Barbosa
//

#include "LinkedList.h"

using namespace std;

LinkedList::LinkedList(): first(nullptr)
{
}

LinkedList::~LinkedList()
{
    // TO-DO
}

void LinkedList::setFirst(Node<int>* n)
{
    this->first = n;
}

Node<int>* LinkedList::getFirst(void)
{
    return this->first;
}

bool LinkedList::insertBegin(int x)
{
	Node<int>* novo = new Node<int>(x);

    novo->setNext( this->getFirst() );

    this->setFirst( novo );

    return true;
}

void LinkedList::print(void)
{
	std::cout << "{ ";
    for(auto n = this->getFirst(); n != nullptr; n = n->getNext())
	{
		std::cout << n->getValue() << " ";
	}
	std::cout << "}";
}

int LinkedList::max()
{
    //setar o proximo como first
    //comparar o atual com o retorno da chamada da proxima função
    if(this->getFirst()==nullptr){
        return 0;
    }
    Node<int> *noAtual = this->getFirst();
    this->setFirst(this->getFirst()->getNext());
    int valorMax = max();
	return ((noAtual->getValue()>valorMax)?noAtual->getValue():valorMax);
    
}