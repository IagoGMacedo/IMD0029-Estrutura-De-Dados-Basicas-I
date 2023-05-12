#include <iostream>
#include "../include/operacoes_array.h"

using namespace std;

void imprima(int array[], int tamanho)
{
    cout << "Entrada := ";
    cout << array[0];
    for( int i = 1; i < tamanho; ++i )
    {
        cout << ", " << array[i];
    }
    cout << endl;
}

int main(int argc, char* argv[])
{
    int entrada[] = {1, 2, 3, 10, 11, 12, 13, 0, 4};
    int tamanho = sizeof(entrada) / sizeof(int);
    
    imprima(entrada, tamanho); 
    
    cout << "Soma := " << soma(entrada, tamanho) << endl;
    cout << "Min := " <<  min(entrada, tamanho) << endl;

    return 0;
}