/*

https://www.youtube.com/watch?v=p7k9ncsB5Cs

https://pt.wikipedia.org/wiki/Pesquisa_bin%C3%A1ria
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Implementação Iterativa:

int PesquisaBinaria (int vet[], int chave, int Tam){
     int inf = 0;     // limite inferior (o primeiro índice de vetor em C é zero          )
     int sup = Tam-1; // limite superior (termina em um número a menos. 0 a 9 são 10 números)
     int meio;
     while (inf <= sup)
     {
          meio = (inf + sup)/2;
          if (chave == vet[meio])
               return 1;
          if (chave < vet[meio])
               sup = meio-1;
          else
               inf = meio+1;
     }
     return 0;   // não encontrado
}

//Implementação Recursiva:

// x => chave | v[] => vetor ordenado | e => limite inferior (esquerda) | d => limite superior (direita)
int PesquisaBinariaRecursiva(int x, int v[], int e, int d){
 int meio = (e + d)/2;
 if (v[meio] == x)
    return meio;
 if (e >= d)
    return -1; // não encontrado
 else
     if (v[meio] < x)
        return PesquisaBinariaRecursiva(x, v, meio+1,      d);
     else
        return PesquisaBinariaRecursiva(x, v,      e, meio-1);
}

int main(){
	
	int vetor[10];
	int i;
	
	for(i=0; i<10; i++){
		scanf("%d", &vetor[i]);
	}
	
	int valor;
	printf("Procurar qual valor: ");
	scanf("%d", &valor);
	
	int achado;
	achado = PesquisaBinaria(vetor, valor, 10);
	//achado = PesquisaBinariaRecursiva(vetor, valor, 11);
	if(achado){
		printf("VALOR ENCONTRADO!\n");
	}
	else{
		printf("VALOR NAO ENCONTRADO!\n");
	}
	
	return 0;
}
