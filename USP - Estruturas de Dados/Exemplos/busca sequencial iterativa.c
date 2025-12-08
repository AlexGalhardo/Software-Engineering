#include <stdio.h>

int busca_sequencial_iterativa(int vet[], int key, int size){
	
	int i = 0;
	while((i<size) && (vet[i]!=key)){
		i++;
	}
	if ( i>= size){
		return -1;
	}
	else if(vet[i] == key){
		return i+1;
	}
	return -1;
}

int main(){

	int vetor[10]= {1,2 ,3 ,4 , 5, 6, 7, 8, 9, 10};

	int complexidade = busca_sequencial_iterativa(vetor, 7, 10);

	printf("\t A complexidade da busca sequencial iterativa é %d", complexidade);

	return 0;
}