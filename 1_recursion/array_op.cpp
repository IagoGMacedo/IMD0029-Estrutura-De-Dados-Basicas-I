//
// Created by iagog on 09/03/2023.
//
#include <iostream>

int bigger(int a, int b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}

int max( int array[], int tam){
    if(tam==1){
        return array[0];
    }
    else{
        return bigger(array[tam-1], max(array,tam-1));
    }
    return 0;
}

int min(int array[], int tam){
    if(tam==1){
        return array[0];
    }
    else{
        return array[tam-1] < min(array,tam-1) ? array[tam-1]:min(array,tam-1);
    }
    return 0;
}

int sum(int array[], int tam){
    if(tam==1){
        return array[0];
    }
    else
        return array[array,tam-1] + sum(array, tam-1);
}

int main(){
    int array[] = {1,8,0,4,7};
    int tam = 5;
    std::cout << "metodo soma:"<< sum(array,tam) << std::endl;
    std::cout << "maior:"<< max(array,tam) << std::endl;
    std::cout << "menor:"<< min(array,tam) << std::endl;

    return 0;
}
