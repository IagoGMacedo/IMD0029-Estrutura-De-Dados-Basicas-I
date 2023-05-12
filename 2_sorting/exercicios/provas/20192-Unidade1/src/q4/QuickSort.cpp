#include "Sort.h"
#include <iostream>

inline void swap(int& a, int& b)
{
	int aux = a;
	a = b;
	b = aux;
}

int acharMediana(int v[], int esquerda, int meio, int direita){
	int inicio = v[esquerda];
	int midle = v[meio];
	int fim  = v[direita];
	if(inicio<meio){
		if(midle<fim){
			return meio;
		}
		if(inicio<fim){
			return direita;
		}
		else{
			return esquerda;
		}
	} else{
		//verdade: inicio > meio
		if(fim<midle){
			return meio;
		}
		if(fim<inicio){
			return direita;
		}
		else{
			return esquerda;
		}
		
	}
	return direita;
}

int particionarNormal(int *v, int esquerda, int direita){
	//estrategia: tornar pivo o ultimo elemento
	int pivo  = v[direita];
	int i =esquerda-1;
	for(int j = esquerda; j<=direita-1;j++){
		if(v[j] < pivo){
			i++;
			swap(v[i],v[j]);
		}
		
	}
	swap(v[i+1],v[direita]);
	//retornando indice do pivo com ele ordenado parcialmente
	return i+1; 
}

int particionar_mediana3(int *v, int esquerda, int direita){
	int meio = (esquerda+direita)/2;
	int i_mediana = acharMediana(v, esquerda, meio, direita);
	swap(v[i_mediana], v[direita]);
	int pivo  = v[direita];
	int i =esquerda-1;
	for(int j = esquerda; j<=direita-1;j++){
		if(v[j] <= pivo){
			i++;
			swap(v[i],v[j]);
		}
		
	}
	swap(v[i+1],v[direita]);
	//retornando indice do pivo com ele ordenado parcialmente
	return i+1; 

}

void ordenarParticao(int *v, int esquerda, int direita){
	if(esquerda<direita){
		//aqui inserimos a estrategia de particionamento
		int i_pivo  = particionar_mediana3(v, esquerda, direita);
		ordenarParticao(v, esquerda, i_pivo-1);
		ordenarParticao(v, i_pivo+1, direita);
	}
}

void sort(int v[], int size)
{
	//assinatura perfeita
	ordenarParticao(v,0, size-1);
	
}
