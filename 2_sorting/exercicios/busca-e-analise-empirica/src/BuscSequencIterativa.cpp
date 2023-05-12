int busca_sequencial(int chave, int entrada[], int tamanho){
    for(int i =0;i<tamanho;i++){
        if(entrada[i]==chave){
            return i;
        }
    }
    return -1;

}

int busca_sequencial_melhorada(int chave, int entrada[], int tamanho){
    //supõe que o algoritmo está ORDENADO
    for(int i =0;i<tamanho;i++){
        if(entrada[i]==chave){
            return i;
        }
        else if(chave<entrada[i]){
            return -1;
        }
        else if(chave>entrada[tamanho-1]){
            return -1;
        }
    }
    return -1;

}