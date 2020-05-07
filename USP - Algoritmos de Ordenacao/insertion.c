#include <stdio.h>

void insertionSort(int *vetor, int n){

	int i, j, aux;
	for(i= 1; i < n; i++){
		aux = vetor[i];
		for(j=i; (j>0) && (aux < vetor[j-1]); j--){
			vetor[j] = vetor[j-1];
		}
		vetor[j] = aux;
	}
}

int main(){

	int vetor[5] = {5, 4, 3, 2, 1};

	printf("Ordenando o vetor...\n\n");

	insertionSort(vetor, 5);

	int k;
	for(k=0; k < 5; k++){
		printf("[%d] ", vetor[k]);
	}

	return 0;
}