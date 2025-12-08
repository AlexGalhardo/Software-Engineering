/*
RESUMO

Compondo a maratona de algoritmos de ordenação, o couting sort será abordado neste post. Mostraremos o conceito, o custo (em comparações) de uso e um algoritmo em C de implementação.
Em uma definição básica o Counting Sort é um algoritmo de ordenação estável (pode ver o que é isso aqui) ótimo para ordenar sequências que contenham repetição.

Para realizar o uso desta modalidade vamos precisar de:

Um vetor A indexado a partir da posição 1 e que possui tamanho N (= número de elementos a serem ordenados);
Um vetor B que é usado para guardar a sequência ordenada;
Um vetor C, de tamanho K (= tamanho do intervalo de valores do vetor A), que é usado como memória temporária;
Passo 1
Nessa etapa será feita a contagem do número de cada elemento do intervalo. Tipo, se o um aparece duas vezes, dentro da casa 1 será feito o incremento duas vezes.

Passo 2
Agora será feito o complemento de casas de cada valor. Ou seja, se na casa 1 existe um três (o número um se repete três vezes), os número da casa dois só poderão ser guardados a partir da casa 4, então soma-se aos números da casa atual, os números da casa anterior.

Passo 3
Agora será feito a alocação dos valores no vetor ordenado. A regra é a seguinte: faz-se a varredura do vetor inicial do final para o começo, o valor de A identifica o índice do vetor complementar C e o valor do deste é o índice do vetor B, dentro do vetor B no índice apontado, será alocado o valor do índice A. Difícil essa parte hein?!

Passo 4
Essa é mamão com açúcar. Basta passar o conteúdo do vetor final para o vetor original.

https://www.youtube.com/watch?v=7zuGmKfUt7s

*/

/*

Counting sort
Faça uma implementação do algoritmo de ordenação "counting sort". O algoritmo deverá ler um número N que indica a quantidade de valores a serem ordenados. Em uma outra linha, o algoritmo deverá ler os N valores a serem ordenados, separados par a par por um único espaço. A saída do método deverá ser os valores ordenados ascendentemente e separados par a par por um único espaço.

É garantido que todos valores a serem ordenados são inteiros positivos, possíveis de serem armazenados em uma variável do tipo "int" da linguagem C. Além disso, é garantido que não há repetição de valores.

Exemplo de Entrada e Saída
Entrada:

10
5 3 2 7 6 8 9 1 0 4
Saída:

0 1 2 3 4 5 6 7 8 9

*/


// VISUALIZAR -> https://www.cs.usfca.edu/~galles/visualization/CountingSort.html

#include <stdio.h>
#include <stdlib.h>

int encontrarK(int *a, int n){
	int max = a[0];
	int i;
	for(i=1; i<n; i++){
		if(max < a[i]){
			max = a[i];
		}
	}
	return max;
}

void countingSort(int *a, int n){
	int k = encontrarK(a, n);
	int b[n];
	int c[k+1];
	
	int i, j;
	
	for(i=0; i<=k; i++){
		c[i] = 0;
	}
	
	for(j=0; j<n; j++){
		c[a[j]] = c[a[j]] +1;
	}
	
	for(i=1; i<= k; i++){
		c[i] = c[i] + c[i-1];
	}
	
	for(j=n-1; j>=0; j--){
		b[c[a[j]]-1] = a[j];
		c[a[j]] = c[a[j]]-1;
	}
	
	for(i=0; i<n; i++){
		printf("%d ", b[i]);
	}
}

int main(){
	
	int i, qtd;
	scanf("%d", &qtd);
	int a[qtd];
	for(i=0; i<qtd; i++){
		scanf("%d", &a[i]);
	}
	
	countingSort(a, qtd);
	
	return 0;
}
