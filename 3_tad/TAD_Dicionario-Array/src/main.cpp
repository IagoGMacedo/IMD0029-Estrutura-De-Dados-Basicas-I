#include <iostream>
#include "../include/Dicionario.h"

int main() 
{
  int num;
  std::string str;

  Dicionario d(10);
  while (true) 
  {
    std::cout << "Digite uma string e número inteiro positivo para adicionar ao dicionario, ou um número negativo para terminar o programa." << std::endl;
    std::cin >> str >> num;
    if (num < 0) 
    {
      std::cout << "Terminando o programa." << std::endl;
      break;
    }
    if( d.buscar(str) )
    {
      d.atualizar(str, num);
      std::cout << "Atualizando (" << str << ", " << num << ") no dicionario. Tamanho do dicionario: " << d.tamanho() << std::endl;  
    }
    else
    {
      d.inserir(str, num);
      std::cout << "Adicionando (" << str << ", " << num << ") ao dicionario. Tamanho do dicionario: " << d.tamanho() << std::endl;
    }
    
    d.imprimir();
  }
  d.remover("a");
  std::cout << "quantidade final: " << d.tamanho() << std::endl;
  std::cout << "retorno final: " << *d.buscar("b") << std::endl;
  d.remover("b");
  std::cout << "retorno do removido: " << d.buscar("b") << std::endl;
  d.imprimir();

  return 0;
}
