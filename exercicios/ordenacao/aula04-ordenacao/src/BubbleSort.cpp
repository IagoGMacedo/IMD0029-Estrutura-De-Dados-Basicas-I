#include "ordenar.h"

void ordenar(int entrada[], int tamanho){
    for(int i  =0;i<tamanho;i++){
        for(int j =0;j<tamanho-i-1;j++){
            if(entrada[j]>entrada[j+1]){
                int aux = entrada[j];
                entrada[j] = entrada[j+1];
                entrada[j+1] = aux;
                //swap
            }
        }
    }
}

void ordenar_otimizado(int entrada[], int tamanho){
    bool fez_swap = 1;
    int fim = tamanho-1;
    while(fez_swap){
        fez_swap = 0;
        for(int j =0;j<fim;j++){
            if(entrada[j]>entrada[j+1]){
                fez_swap = 1;
                //swap
                int aux = entrada[j];
                entrada[j] = entrada[j+1];
                entrada[j+1] = aux;
            }
            fim = fim -1;
        }
    }
}