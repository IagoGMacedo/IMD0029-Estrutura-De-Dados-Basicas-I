#include "ordenar.h"

void ordenar(string array[], int tamanho){
    int min = 0;
    for(int i =0;i<tamanho;i++){
        for(int j =i+1;j<tamanho;j++){
            if(array[j]<array[i]){
                min = j;
            }
        }
        if(min!=i){
            //SWAP
            string aux = array[i];
            array[i] = array[min];
            array[min]= aux;
        }
    }
}