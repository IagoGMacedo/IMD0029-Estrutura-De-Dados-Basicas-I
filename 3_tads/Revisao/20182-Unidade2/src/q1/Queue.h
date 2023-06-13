//
//  Queue.hpp
//  Queue
//
//  Created by Eiji Adachi Medeiros Barbosa 
//

#ifndef Queue_hpp
#define Queue_hpp

#include <iostream>
#include <stack>

using namespace std;

template<typename T>
class Queue
{
public:
    Queue();
    Queue(int);
    void enqueue(T);
    void dequeue();
    T peek();
    int getQuantity();
    
private:
    int quantity;
    stack<T> pilha1, pilha2;
};

template<typename T>
Queue<T>::Queue():quantity(0)
{

}

template<typename T>
int Queue<T>::getQuantity()
{
	return this->quantity;
}

template<typename T>
T Queue<T>::peek(){
    return this->pilha1.top();
}

template<typename T>
void Queue<T>::enqueue(T element){
    //mover todos os elementos da pilha 1 para a pilha 2

    while(!this->pilha1.empty()){
        //enquanto NÃO estiver vazia
        this->pilha2.push(this->pilha1.top());
        this->pilha1.pop();
    }

    //adiciona o elemento na pilha 1
    this->pilha1.push(element);
    this->quantity++;

    //coloca tudo de volta na pilha 1
        while(!this->pilha2.empty()){
        //enquanto NÃO estiver vazia
        this->pilha1.push(this->pilha2.top());
        this->pilha2.pop();
    }
}

template<typename T>
void Queue<T>::dequeue(){
    if(!this->pilha1.empty()){
        this->pilha1.pop();
        this->quantity--;
    }
}

#endif /* Queue_hpp */
