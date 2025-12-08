#include <stdio.h>

int busca_sequencial_recursiva(int vet[], int key, int size, int i){
	if(i>=size){
		return -1;
	}
	else if(vet[i] == key){
		return i+1;
	}
	else{
		return busca_sequencial_recursiva(vet, key, size, i+1);
	}
}


int main(){

	int vetor[10] = {1,2 ,3 , 4, 5, 6, 7, 8, 9, 10};

	int complexidade = busca_sequencial_recursiva(vetor, 9, 10, 0);

	printf("A complexidade é %d", complexidade);

	return 0;
}