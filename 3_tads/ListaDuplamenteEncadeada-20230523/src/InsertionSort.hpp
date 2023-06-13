#include "iostream"

class InsertionSort{
public:

void ordenar(int entrada[], int tamanho){
    for(int i = 1; i<tamanho;i++){
        int j = i -1; //fim da parte ordenada
        int novo = entrada[i];
        while(j>=0 && novo<entrada[j]){ //while tambem é uma verificação, por isso melhor caso é só n
            entrada[j+1] = entrada[j]; //desloca elementos
            j = j -1;
        }
        entrada[j+1] = novo; //quando corrige o primeiro elemento ele fica negativo
    }
};
void ordenarTeste(int entrada[], int tamanho){
    for(int i = 2; i<tamanho;i++){
            int j = i -1; //fim da parte ordenada
            int novo = entrada[i];
            while(j>=0 && novo<entrada[j]){ //while tambem é uma verificação, por isso melhor caso é só n
                entrada[j+1] = entrada[j]; //desloca elementos
                j = j -1;
            }
            entrada[j+1] = novo; //quando corrige o primeiro elemento ele fica negativo
    }
    for(int i =0;i<tamanho;i++){
        std::cout << entrada[i] <<", " << std::endl;
    }
};
};

