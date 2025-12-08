/*
REFERÊNCIAS:

https://www.youtube.com/watch?v=MtQL_ll5KhQ

https://www.ime.usp.br/~pf/analise_de_algoritmos/aulas/heap.html

https://www.ime.usp.br/~pf/analise_de_algoritmos/aulas/dicionario.html#floor

https://docente.ifrn.edu.br/robinsonalves/disciplinas/estruturas-de-dados-2013/08Heap.pdf

*/
#include <stdio.h>

void criaHeap(int *vetor, int i, int f){

	int aux = vetor[i];
	int j = i * 2 +1;

	while(j <= f){
		if(j < f){
			if(vetor[j] < vetor[j+1]){
				j = j +1;
			}
		}
		if(aux < vetor[j]){
			vetor[i] = vetor[j];
			i = j;
			j = 2 * i + 1;
		}
		else{
			j = f +1;
		}
	}
	vetor[i] = aux;
}


void heapSort(int *vetor, int tamanho){

	int i, aux;
	for(i=(tamanho-1)/2; i >= 0; i--){
		criaHeap(vetor, i, tamanho -1);
	}

	for(i=tamanho-1; i>=1; i--){
		aux = vetor[0];
		vetor[0] = vetor[i];
		vetor[i] = aux;
		criaHeap(vetor, 0, i-1);
	}
}


int main(){

	int vetor[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	printf("    O vetor desordenada eh: \n\n");
	
	int i;
	for(i=0; i<10; i++){
		printf("[%d] ", vetor[i]);
	}
	printf("\n\n");

	printf("Ordenando o vetor...\n\n");

	heapSort(vetor, 10);

	int k;
	for(k=0; k < 10; k++){
		printf("[%d] ", vetor[k]);
	}
	return 0;
}
