#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void merge(int *vetor, int inicio, int meio, int fim){
	int *temp, p1, p2, tamanho, i, j, k;
	int fim1 = 0, fim2 =0;
	tamanho = fim-inicio+1;

	p1 = inicio;
	p2 = meio+1;

	temp = (int *)malloc(tamanho*sizeof(int));

	if(temp != NULL){
		for(i=0; i<tamanho; i++){
			if(!fim1 && !fim2){
				if(vetor[p1] < vetor[p2]){
					temp[i] = vetor[p1++];
				}
				else{
					temp[i] = vetor[p2++];
				}

				if(p1>meio) fim1=1;
				if(p2>fim) fim2=1;
			}
			else{
				if(!fim1){
					temp[i]=vetor[p1++];
				}
				else{
					temp[i] = vetor[p2++];
				}
			}
		}
		for(j=0, k=inicio; j < tamanho; j++, k++){
			vetor[k] = temp[j];
		}
	}
	free(temp);
}


void mergeSort(int *vetor, int inicio, int fim){

	int meio;
	if(inicio < fim){
		meio = floor((inicio+fim)/2);
		mergeSort(vetor, inicio, meio);
		mergeSort(vetor, meio+1, fim);
		merge(vetor, inicio, meio, fim);
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

	mergeSort(vetor, 0, 10);

	int k;
	for(k=0; k < 10; k++){
		printf("[%d] ", vetor[k]);
	}

	return 0;
}