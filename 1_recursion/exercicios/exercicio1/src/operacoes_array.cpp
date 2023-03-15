#include "../include/operacoes_array.h"

int soma(int array[], int tamanho){
    if(tamanho==1){
        return array[0];
    }
    else
        return array[array,tamanho-1] + soma(array, tamanho-1);
}

int min(int array[], int tamanho){
    if(tamanho==1){
        return array[0];
    }
    else{
        return array[tamanho-1] < min(array,tamanho-1) ? array[tamanho-1]:min(array,tamanho-1);
    }
}