#include "ordenar.h"

void intercalar(int entrada[], int inicio1, int inicio2, int fim2){
    //pressupõe dois vetores já ordenados
    int fim1 = inicio2-1;
    int i = inicio1;
    int j = inicio2;
    int k = 0;
    int tmp[fim2];
    while(i < fim1 && j < fim2){
        if(entrada[i]<=entrada[j]){
            tmp[k] = entrada[i];
            i++;
        } else {
            tmp[k] = entrada[j];
            j++;
        }
        k++;
    }
    //um dos vetores acabou
    while(i<fim1){
        tmp[k] = entrada[i];
        i++;
    }
    while(j<fim2){
        tmp[k] = entrada[j];
        j++;
    }     
    entrada = tmp;
}

void ordenar(int entrada[], int tamanho){
    //Já sei como intercalar mas como conseguir dois vetores ordenados?
}