/*
Heapsort
Faça uma implementação do algoritmo de ordenação "heapsort". O algoritmo deverá ler um número N que indica a quantidade de valores a serem ordenados. Em seguida, numa outra linha, o algoritmo deverá ler um número binário (0 ou 1) que indica se a ordenação deve ser feita em ordem crescente (valor 0) ou decrescente (valor 1). Em uma outra linha, por fim, o algoritmo deverá ler os N valores a serem ordenados, separados par a par por um único espaço. A saída do método deverá ser os valores ordenados e separados par a par por um único espaço.

Exemplo de Entrada e Saída
Entrada:

10
0
5 3 2 7 6 8 9 1 0 4
Saída:

0 1 2 3 4 5 6 7 8 9
*/

/*
Heapsort
Faça uma implementação do algoritmo de ordenação "heapsort". O algoritmo deverá ler um número N que indica a quantidade de valores a serem ordenados. Em seguida, numa outra linha, o algoritmo deverá ler um número binário (0 ou 1) que indica se a ordenação deve ser feita em ordem crescente (valor 0) ou decrescente (valor 1). Em uma outra linha, por fim, o algoritmo deverá ler os N valores a serem ordenados, separados par a par por um único espaço. A saída do método deverá ser os valores ordenados e separados par a par por um único espaço.

Exemplo de Entrada e Saída
Entrada:

10
0
5 3 2 7 6 8 9 1 0 4
Saída:

0 1 2 3 4 5 6 7 8 9
*/

#include <stdio.h>

void criaHeapDec(int *vetor, int i, int f){

	int aux = vetor[i];
	int j = i * 2 +1;

	while(j <= f){
		if(j < f){
			if(vetor[j] > vetor[j+1]){
				j = j +1;
			}
		}
		if(aux > vetor[j]){
			vetor[i] = vetor[j];
			i = j;
			j = 2 * i + 1;
		}
		else{
			j = f + 1;
		}
	}
	vetor[i] = aux;
}


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

void heapSortDec(int *vetor, int tamanho){

	int i, aux;
	for(i=(tamanho-1)/2; i >= 0; i--){
		criaHeapDec(vetor, i, tamanho -1);
	}

	for(i=tamanho-1; i>=1; i--){
		aux = vetor[0];
		vetor[0] = vetor[i];
		vetor[i] = aux;
		criaHeapDec(vetor, 0, i-1);
	}
}


int main(){

	int tamanho, op, i;
	scanf("%d", &tamanho);
	scanf("%d", &op);
	int vetor[tamanho];

	if(op == 0){
		for(i=0; i<tamanho; i++){
			scanf("%d", &vetor[i]);
		}
    
		heapSort(vetor, tamanho);
    
		for(i=0; i<tamanho; i++){
			printf("%d ", vetor[i]);
		}
	}
	else{
		for(i=0; i<tamanho; i++){
			scanf("%d", &vetor[i]);
		}
    
		heapSortDec(vetor, tamanho);
    
		for(i=0; i<tamanho; i++){
			printf("%d ", vetor[i]);
		}
	}
	return 0;
}
