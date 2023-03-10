//
// Created by iagog on 09/03/2023.
//
#include <iostream>

int sum(int a, int b){
    if(b==0){
        return a;
    }
    else
        return 1 + sum(a,b-1);
}

int multiplication(int a, int b){
    if(b==0){
        return 0;
    }
    else
        return a + multiplication(a, b-1);
}


int main(){
    std::cout << "metodo soma: " << sum(3,0) << std::endl;
    std::cout << "metodo multiplicacao: " << multiplication(5,4) << std::endl;
    return 0;
}
