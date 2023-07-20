//
//  LinkedList.cpp
//
//  Created by Eiji Adachi Medeiros Barbosa
//

#include "LinkedList.h"

using namespace std;

LinkedList::LinkedList()
{
    this->head = new Node<string>();
    this->tail = new Node<string>();
    
    this->head->setNext(this->tail);
    this->head->setPrevious(NULL);

    this->tail->setNext(NULL);
    this->tail->setPrevious(this->head);

    this->quantity = 0;
}

LinkedList::~LinkedList()
{
    Node<string>* n = this->head;
    
    while(n != this->tail)
    {
        Node<string>* toDestroy = n;
        
        n = n->getNext();
        
        delete toDestroy;
    }
    
    delete this->tail;
}

Node<string>* LinkedList::getHead(void)
{
    return this->head;
}

Node<string>* LinkedList::getTail(void)
{
    return this->tail;
}

int LinkedList::getQuantity(void)
{
    return this->quantity;
}

bool LinkedList::isEmpty(void)
{
    return this->quantity == 0;
}

void LinkedList::print(void)
{
    std::cout << "{ ";
    for(Node<string>* n = this->head->getNext(); n != this->tail; n = n->getNext())
    {
        std::cout << n->getValue() << ":" << n->getCount() << " ";
    }
    std::cout << "}" << std::endl;
}

ListStatus LinkedList::checkConsistency()
{
    if( this->head == NULL )
    {
        return HeadNull;
    }
    else if( this->head->getNext() == NULL )
    {
        return HeadNextNull;
    }
    else if( this->head->getNext()->getPrevious() != this->head )
    {
        return IncorrectLink;
    }
    else if( this->head->getPrevious() != NULL )
    {
        return HeadPrevious;
    }
    
    if( this->tail == NULL )
    {
        return TailNull;
    }
    else if( this->tail->getPrevious() == NULL )
    {
        return TailPreviousNull;
    }
    else if( this->tail->getPrevious()->getNext() != this->tail )
    {
        return IncorrectLink;
    }
    else if( this->tail->getNext() != NULL )
    {
        return TailNext;
    }
    
    if(this->isEmpty())
    {
        if( this->head->getNext() != this->tail )
        {
            return HeadTail;
        }
        
        if( this->head != this->tail->getPrevious() )
        {
            return HeadTail;
        }
    }
    else
    {
        // Verifica encadeamento dos elementos
        for(Node<string>* i = this->head->getNext(); i != this->tail; i=i->getNext())
        {
            if( i->getNext()->getPrevious() != i )
            {
                return IncorrectLink;
            }
            if( i->getPrevious()->getNext() != i )
            {
                return IncorrectLink;
            }
        }
    }
    
    return OK;
}

bool LinkedList::insertEnd(string s)
{
    Node<string>* n = new Node<string>(s);

    n->setNext( this->getTail() );
    n->setPrevious( this->getTail()->getPrevious() );

    n->getPrevious()->setNext(n);
    n->getNext()->setPrevious(n);

    ++quantity;

    return true;
}

Node<string>* LinkedList::searchCF(string key)
{
	// std::cout << "\tERRO: LinkedList::searchCF - not yet implemented.\n";
 //    std::abort();
    for( Node<string>* n = this->getHead()->getNext(); n != this->getTail(); n = n->getNext() )
    {
        if( n->getValue() == key )
        {
            n->setCount( n->getCount()+1 );

            if(n->getPrevious() == this->getHead() || n->getPrevious()->getCount() >= n->getCount())
            {
                return n;
            }

            // unlink
            n->getNext()->setPrevious( n->getPrevious() );
            n->getPrevious()->setNext( n->getNext() );

            Node<string>* aux = n->getPrevious();

            while( aux != this->getHead() && aux->getCount() < n->getCount() )
            {
                aux = aux->getPrevious();
            }

            if(aux == this->getHead() )
            {
                n->setPrevious( this->getHead() );
                n->setNext( this->getHead()->getNext() );
            }
            else
            {
                n->setPrevious( aux );
                n->setNext( aux->getNext() );    
            }

            n->getPrevious()->setNext( n );
            n->getNext()->setPrevious( n );

            return n;
        }
    }

    return nullptr;
}
