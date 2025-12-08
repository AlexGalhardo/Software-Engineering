#include <stdio.h>

void selectionSort(int *vetor, int tamanho){

	int i, j, menor, troca;
	for(i=0; i< tamanho-1; i++){
		menor = i;
		for(j=i+1; j<tamanho; j++){
			if(vetor[j] < vetor[menor]){
				menor = j;
			}
		}
		if(i != menor){
			troca = vetor[i];
			vetor[i] = vetor[menor];
			vetor[menor] = troca;
		}
	}

}

int main(){

	int vetor[5] = {5, 4, 3, 2, 1};

	printf("Ordenando o vetor...\n\n");

	selectionSort(vetor, 5);

	int k;
	for(k=0; k < 5; k++){
		printf("[%d] ", vetor[k]);
	}

	return 0;
}