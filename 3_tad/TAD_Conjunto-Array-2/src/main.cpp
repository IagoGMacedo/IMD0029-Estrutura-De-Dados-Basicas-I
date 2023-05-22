#include <iostream>
#include "../include/Conjunto.h"

int main() 
{
  int num;

  Conjunto c(10);
  while (true) 
  {
    std::cout << "Digite um número inteiro positivo para adicionar ao conjunto, ou um número negativo para terminar o programa." << std::endl;
    std::cin >> num;
    if (num < 0) 
    {
      std::cout << "Terminando o programa." << std::endl;
      break;
    }
    c.inserir(num);
    std::cout << "Adicionando " << num << " ao conjunto. Tamanho do conjunto: " << c.tamanho() << std::endl;
    c.imprimir();
  }
  c.inserir(10);
  std::cout << "novo tamanho: "<< c.tamanho()<< std::endl;
  c.imprimir();
  std::cout << "buscando: "<<c.buscar(10)<< std::endl;
  c.remover(10);
  c.imprimir();
  std::cout << "buscando: "<<c.buscar(10)<< std::endl;
  std::cout << "novo tamanho: "<< c.tamanho()<< std::endl;
  c.remover(2);
  std::cout << "novo tamanho: "<< c.tamanho()<< std::endl;
  c.imprimir();
  std::cout << "buscando: "<<c.buscar(2)<< std::endl;
  return 0;
}
