#include <stdio.h>

int busca_ternaria_recursiva(int vet[], int key, int start, int end){

	int middle1 = start + (end-start)/3;
	int middle2 = start + 2*((end-start)/3);
	if(start>end){
		return -1;
	}
	else if( vet[middle1] == key ){
		return middle1+1;
	}
	else if( vet[middle2] == key ){
		return middle2+1;
	}
	else if( vet[middle1] > key ){
		return busca_ternaria_recursiva(vet, key, start, middle1 - 1 );
	}
	else{
		return busca_ternaria_recursiva(vet, key, middle1+1, middle2 - 1);
	}
}

int main(){

	int vetor[1000];

	int i, count = 1;
	for(i=0; i<1000; i++){
		vetor[i] = count;
		count++;
	}
	for(i=0; i<1000; i++){
		printf("%d\n", vetor[i]);
	}

	int complexidade = busca_ternaria_recursiva(vetor, 500, 0, 999);

	printf("A complexidade ternaria é --> %d\n", complexidade);

	return 0;
}