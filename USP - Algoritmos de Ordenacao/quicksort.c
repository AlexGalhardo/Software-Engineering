/*

REFERÊNCIAS

https://www.youtube.com/watch?v=SLauY6PpjW4

*/
#include <stdio.h>
#include <stdlib.h>

int particiona(int *vetor, int inicio, int fim){

	int esq, dir, pivo, aux;
	esq = inicio;
	dir = fim;
	pivo = vetor[inicio];

	while(esq < dir){
		while(vetor[esq] <= pivo){
			esq++;
		}
		while(vetor[dir] > pivo){
			dir--;
		}
		if(esq < dir){
			aux = vetor[esq];
			vetor[esq] = vetor[dir];
			vetor[dir] = aux;
		}
	}
	vetor[inicio] = vetor[dir];
	vetor[dir] = pivo;
	return dir;
}


void quickSort(int *vetor, int inicio, int fim){

	int pivo;
	if(fim > inicio){
		pivo = particiona(vetor, inicio, fim);
		quickSort(vetor, inicio, pivo-1);
		quickSort(vetor, pivo+1, fim);
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

	quickSort(vetor, 0, 10);

	int k;
	for(k=0; k < 10; k++){
		printf("[%d] ", vetor[k]);
	}
	return 0;
}
