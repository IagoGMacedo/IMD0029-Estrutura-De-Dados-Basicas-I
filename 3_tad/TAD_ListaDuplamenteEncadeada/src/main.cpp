#include "../include/ListaDuplamenteEncadeada.h"
#include "iostream"
int main(void){
    ListaDuplamenteEncadeada lista;
    
    std::string v[] = {"alpha","bravo","charlie","delta","echo","fox","golf","hotel","india","juliet"};
    
    for(int i = 0; i < 10; i++)
    {
        int tamanhoAntes = lista.tamanho();
        std::cout <<"tamanho antes:"<<tamanhoAntes << std::endl;
        
        auto valorInserido = v[i];

                
        bool inseriu = lista.inserirNaCauda( valorInserido );
        std::cout <<" inseriu na cauda:"<<inseriu << std::endl;
        
        auto ultimoElemento = lista.getCauda()->getAnterior();
        std::cout <<" valor da cauda:"<<ultimoElemento->getValor() << std::endl;
        std::cout <<"tamanho depois:"<<lista.tamanho() << std::endl;

        
        auto ultimoValor = ultimoElemento->getValor();

        
        int tamanhoDepois = lista.tamanho();
    }
    return 0;
}