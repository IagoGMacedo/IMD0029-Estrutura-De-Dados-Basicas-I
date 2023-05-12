# IMD0029 - Estruturas de Dados Básicas I, Prof. Eiji Adachi
## Atividade: Buscas e Análise Empírica


### Objetivos
- Implementar buscas sequencial e binária
- Exercitar análise empírica de algoritmos 

### Descrição da Atividade
Nesta tarefa, você deve implementar os algoritmos de busca sequencial e binária em suas versões recursivas e iterativas. Para isso, no diretório ``/src``, crie um arquivo ``.cpp`` para cada combinação de algoritmo de busca (sequencial e binária) e estratégia de implementação (recursiva e iterativa). 

Gere um arquivo executável para cada busca e execute-a, lembrando de redirecionar a saída do programa para um arquivo ``.csv`` no diretório ``/data``. Por exemplo: 

```./bin/bbi_main > ./data/saida_bbi_main.csv```

É importante lembrar que o arquivo main depende do arquivo ``/data/input.txt``. Como este arquivo é muito grande, não pude compartilhá-lo aqui, via SIGAA. Baixe-o no seguinte link (lembre de descompactar e colocar o arquivo ``input.txt`` dentro do diretório ``/data``): https://drive.google.com/file/d/136UWQlQXPBxAYSLcXCcfDfQpYSqmnL8S/view?usp=sharing 

Após gerar os arquivos ``.csv``, execute o script Python ``gerador_grafico.py``, que está no diretório ``/src``, para gerar os gráficos. Lembre-se que este script Python precisa receber pela linha de comando um argumento indicando qual arquivo ``.csv`` deverá ser processado. Por exemplo:

```python ./src/gerador_grafico.py ./data/saida_bbi_main.csv```

Observação: é possível que você se depare com erros ao executar o script Python pela primeira vez, provavelmente porque ainda não tem as bibliotecas usadas instaladas no seu ambiente. Use o Chat-GPT para solucionar esses problemas.