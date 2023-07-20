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
    if(this->getFirst()!=nullptr)
    {
        delete this->first;
    }
}

void LinkedList::setFirst(Node<string>* n)
{
    this->first = n;
}

Node<string>* LinkedList::getFirst(void)
{
    return this->first;
}

bool LinkedList::insertBegin(string s)
{
	Node<string>* node = new Node<string>(s);

	if( this->getFirst() != nullptr )
	{
		node->setNext( this->getFirst() );
	}

	this->setFirst( node );

	return true;
}

void LinkedList::print(void)
{
	for(auto n = this->getFirst(); n != nullptr; n = n->getNext())
	{
		std::cout << n->getValue() << " ";
	}
	std::cout << std::endl;
}

Node<string>* recInvert(Node<string>* curr, Node<string>* prev )
{
    if( curr == nullptr )
    {
        return prev;
    }
    else
    {
        auto newFirst = recInvert( curr->getNext(), curr );
        curr->setNext(prev);
        return newFirst;
    }
}

void LinkedList::invert()
{
	auto n = recInvert(this->getFirst(), nullptr);
    this->setFirst( n );
}
