#include "iostream"
int busca_binaria(int chave, int entrada[], int tamanho){
    int inicio = 0, fim = tamanho -1, meio;
    while(inicio<=fim){
        meio=inicio+fim/2;
        if(chave<entrada[meio]){
            fim = meio -1;
        } else if(chave>entrada[meio]){
            inicio=meio+1;
        } else{
            return meio;
        }
    }
    return -1;
}

int busca_binaria_desord(int chave, int entrada[], int tamanho){
    int inicio = 0, fim = tamanho -1, meio;
    while(inicio<=fim){
        meio=inicio+fim/2;
        if(chave<entrada[meio]){
            inicio=meio+1;
        } else if(chave>entrada[meio]){
            fim = meio -1;
        } else{
            return meio;
        }
    }
    return -1;
}

int main(){
    std::cout << "oi som oi";
    return 0;
}