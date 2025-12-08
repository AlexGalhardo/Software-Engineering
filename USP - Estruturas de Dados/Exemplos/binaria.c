#include <stdio.h>

int busca_binaria_recursiva(int vet[], int key, int start, int end){

	int middle = (start+end)/2;

	if (start > end){
		return -1;
	}
	else if(vet[middle] == key){
		return middle+1;
	}
	else if(vet[middle]> key){
		return busca_binaria_recursiva(vet, key, start, middle-1);
	}
	else{
		return busca_binaria_recursiva(vet, key, middle+1, end);
	}

}

int main(){

	int vet[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	int complexidade = busca_binaria_recursiva(vet, 10, 0, 9);

	printf("A complexidade da busca binaria recursiva é --> [%d]", complexidade);

	return 0;
}