/*

REFERÊNCIA: https://pt.wikipedia.org/wiki/Radix_sort

https://www.youtube.com/watch?v=xuU-DS_5Z4g

Radix sort
Faça uma implementação do algoritmo de ordenação "radix sort". O algoritmo deverá ler um número N que indica a quantidade de valores a serem ordenados. Em uma outra linha, o algoritmo deverá ler os N valores a serem ordenados, separados par a par por um único espaço. A saída do método deverá ser os valores ordenados ascendentemente e separados par a par por um único espaço.

É garantido que todos valores a serem ordenados são inteiros positivos, possíveis de serem armazenados em uma variável do tipo "int" da linguagem C. Além disso, é garantido que não há repetição de valores.

Exemplo de Entrada e Saída
Entrada:

10
5 3 2 7 6 8 9 1 0 4
Saída:

0 1 2 3 4 5 6 7 8 9

*/

#include <stdio.h>
#include <stdlib.h>

void radixSort(int vetor[], int tamanho) {
    int i;
    int *b;
    int maior = vetor[0];
    int exp = 1;

    b = (int *)calloc(tamanho, sizeof(int));

    for (i = 0; i < tamanho; i++) {
        if (vetor[i] > maior)
    	    maior = vetor[i];
    }
 
    while (maior/exp > 0) {
        int bucket[10] = { 0 };
    	for (i = 0; i < tamanho; i++)
    	    bucket[(vetor[i] / exp) % 10]++; 
    	for (i = 1; i < 10; i++)
    	    bucket[i] += bucket[i - 1];
    	for (i = tamanho - 1; i >= 0; i--)
    	    b[--bucket[(vetor[i] / exp) % 10]] = vetor[i];
    	for (i = 0; i < tamanho; i++)
    	    vetor[i] = b[i];
    	exp *= 10;
    }
    free(b);
}

int main(){

    int tamanho, i;
    scanf("%d", &tamanho);

    int entrada[tamanho];
    for(i=0; i<tamanho; i++){
        scanf("%d", &entrada[i]);
    }
    /*
    for(i=0; i<tamanho; i++){
        printf("%d->", entrada[i]);
    }
    */
    //printf("\n\nOrdenando...\n\n");
    radixSort(entrada, tamanho);
    for(i=0; i<tamanho; i++){
        printf("%d ", entrada[i]);
    }
    

    return 0;
}
