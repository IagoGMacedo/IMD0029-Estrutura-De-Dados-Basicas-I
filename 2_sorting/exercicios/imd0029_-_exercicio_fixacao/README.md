# IMD0029 - Estruturas de Dados Básicas I, Prof. Eiji Adachi
## Atividade de Fixação - Estrutura de diretórios, Compilação pelo terminal e Recursão

### Objetivos
- Exercitar a compilação pelo terminal em um projeto que segue uma estrutura de diretórios.
- Exercitar a implementação de algoritmos recursivos que manipulam arrays.

### Descrição da Atividade
Esta tarefa apresenta um projeto C++ que segue uma estrutura de diretórios para organizar os arquivos do projeto. A seguinte estrutura é adotada:
- ``src`` - Os arquivos .cpp devem ser armazenados neste diretório.
- ``include`` - Os arquivos .h devem ser armazenados neste diretório.
- ``bin`` - Os arquivos binários devem ser gerados neste diretório.

O projeto desta tarefa já possui um arquivo ``main.cpp``, que está localizado no diretório ``src``, e um arquivo ``operacoes_array.h``, que está no diretório ``include``. 
- O arquivo de cabeçalho ``operacoes_array.h`` apenas define a assinatura de duas funções que operam sobre arrays de inteiros: ``soma``, que soma todos os elementos do array e ``min``, que encontra o menor valor do array. 
- O arquivo ``main.cpp`` apenas declara variáveis que serão repassadas como parâmetros para as funções ``soma`` e ``min`` e imprime os resultados dessas funções na tela do terminal.

Nesta atividade, você deverá:
- Criar um arquivo ``operacoes_array.cpp`` no diretório apropriado, incluir no arquivo ``.cpp`` a diretiva ``include`` do respectivo arquivo ``.h``, e implementar as funções ``soma`` e ``min`` de modo recursivo. 
- Pela linha de comando do terminal, compilar os arquivos objeto dos arquivos ``main.cpp`` e ``operacoes_array.cpp`` e, num passo seguinte, gerar um arquivo executável. Os arquivos objeto e o executável devem ser criados no diretório apropriado.

Se você conseguir resolver com extrema facilidade as duas tarefas acima, tente fazer o seguinte:
- Usar o git para controlar as versões dos seus arquivos durante o processo de desenvolvimento da solução. Você pode usar o ChatGPT para pedir ajuda, ou mesmo um tutorial, de como usar os comandos básicos do git.
- Implementar as funções ``soma`` e ``min`` adotando uma estratégia recursiva chamda `Dividir para Conquistar'. Tipicamente, esta estratégia divide o problema ao meio faz duas chamadas recursivas para resolver cada metade do problema; em seguida, combina os resultados parciais para encontrar o resultado do problema maior. No caso específico das funções acima, a solução poderá ter uma estrutura similar ao seguinte trecho de código:
```c++
int funcao_recursiva(int array[], int primeiro, int ultimo)
{
    if( caso base )
    {
        // resolve trivialmente
    }
    else
    {
        int meio = (primeiro + ultimo)/2;
        // resolvo o sub-problema da metade inicial do array
        int resultado1 = funcao_recursiva(array, primeiro, meio-1);
        // resolvo o sub-problema da metade final do array
        int resultado2 = funcao_recursiva(array, meio, ultimo);
        // combino resultado1 e resultado2 para resolver o problema maior
        // retorno o resultado combinado
    }
}

int main()
{
    // chamada inicial para a função recursiva
    funcao_recursiva(array, 0, tamanho-1);
}
```
Perceba que a soma dos elementos de um array de tamanho N nada mais é do que a soma dos elementos da primeira metade do array adicionada a soma dos elementos da segunda metade do array. Similarmente, o menor elemento de um array de tamanho N é o menor entre o menor elemento da primeira metade do array e o menor elemento da segunda metade do array.