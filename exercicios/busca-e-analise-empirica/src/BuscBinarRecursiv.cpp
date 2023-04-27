int busca_binaria(int chave , int entrada[], int inicio, int fim){
    //supõe que os valores estão ORDENADOS
    if(inicio>fim){
        return -1;
    }
    int meio = inicio+fim/2;
    //desloca as posições de meio, não só repete
    if(chave<entrada[meio]){
        return busca_binaria(chave, entrada, inicio, meio-1);
    } else if(chave>entrada[meio]){
        return busca_binaria(chave, entrada, meio+1, fim);
    } else{
        return meio;
    }

}