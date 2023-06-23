#include <cassert>
#include <iostream>

using namespace std;

int acharMenorOuIgual(int array[], int esquerda, int direita, int chave)
{
	if(direita<esquerda){
		return -1;
	}
	int meio  = (esquerda+direita)/2;
	if(array[meio]==chave){
		return meio;
	}
	if(array[meio]<chave){     
		//tinha uma versão mais correta aqui, mas é realmente bem simples!
		if(array[meio+1]>chave){
			return meio;
		}
		return acharMenorOuIgual(array, meio+1,direita,chave);
	}
	if(array[meio]>chave){
		return acharMenorOuIgual(array, esquerda,meio-1,chave);

	}
	return meio;
	
}

int main(void)
{
	// Vamos assumir que não há elementos repetidos
	int array[] = {0, 2, 4, 6, 8, 10, 12};
	int tamanho = sizeof(array) /sizeof(int);

	std::cout << "Q1 - Testes 1: buscando elementos que existem no array." << std::endl;
	// Aqui são buscados apenas elementos que existem no array de entrada
	assert( acharMenorOuIgual(array, 0, tamanho-1, 0) == 0);
	assert( acharMenorOuIgual(array, 0, tamanho-1, 2) == 1);
	assert( acharMenorOuIgual(array, 0, tamanho-1, 4) == 2);
	assert( acharMenorOuIgual(array, 0, tamanho-1, 6) == 3);
	assert( acharMenorOuIgual(array, 0, tamanho-1, 8) == 4);
	assert( acharMenorOuIgual(array, 0, tamanho-1, 10) == 5);
	assert( acharMenorOuIgual(array, 0, tamanho-1, 12) == 6);
	std::cout << "Q1 - Testes 1: OK!" << std::endl;

	std::cout << "\nQ1 - Testes 2: buscando elementos que não existem no array, mas que existe no array um menor do que o buscado." << std::endl;
	// Aqui são buscados elementos que não estão no array de entrada,
	// mas que existe no array um elemento menor do que os buscados
	int result = acharMenorOuIgual(array, 0, tamanho-1, 1);
	std::cout << "valor printando" << result << std::endl;
	assert( acharMenorOuIgual(array, 0, tamanho-1, 1) == 0);
	assert( acharMenorOuIgual(array, 0, tamanho-1, 3) == 1);
	result = acharMenorOuIgual(array, 0, tamanho-1, 5);
	std::cout << "valor printando" << result << std::endl;
	assert( result == 2);
	assert( acharMenorOuIgual(array, 0, tamanho-1, 7) == 3);
	assert( acharMenorOuIgual(array, 0, tamanho-1, 9) == 4);
	assert( acharMenorOuIgual(array, 0, tamanho-1, 11) == 5);
	assert( acharMenorOuIgual(array, 0, tamanho-1, 13) == 6);
	std::cout << "Q1 - Testes 2: OK!" << std::endl;

	std::cout << "\nQ1 - Testes 3: buscando elemento que não existe no array, e que não existe no array um menor do que o buscado." << std::endl;
	// Aqui são buscados elementos que não estão no array,
	// mas que não existem no array elementos menores do que os buscados,
	// logo, deve-se retornar -1
	assert( acharMenorOuIgual(array, 0, tamanho-1, -2) == -1);
	std::cout << "Q1 - Testes 3: OK!" << std::endl;
	
	std::cout << "\n!!!! Q1 - Passou em todos os testes !!!! " << std::endl;
	return 0;
}
