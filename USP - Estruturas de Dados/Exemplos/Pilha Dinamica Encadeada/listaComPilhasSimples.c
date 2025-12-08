#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct no{
	int info;
	struct no *prox;
}NO;

typedef struct{
	NO *topo;
}PILHA;

void cria(PILHA *p){
	p->topo = NULL;
}

int vazio(PILHA *p){
	if(p->topo == NULL)
		return 1;
	else return 0;
}

void push(PILHA *p, int *dado, int *erro){
	
	NO *aux;
	aux = (NO*)malloc(sizeof(NO));
	
	if(aux == NULL){
		*erro = 1;
		exit(1);
	}
	else{
		*erro = 0;
		aux->info = *dado;
		aux->prox = p->topo;
		p->topo = aux;			
	}
}

void pop(PILHA *p, int *dado, int *erro){
	
	NO *aux;
	
	if(vazio(p)){
		*erro = 1;
	}
	else {
		*erro = 0;
		*dado = p->topo->info;
		aux = p->topo;
		p->topo = p->topo->prox;
		free(aux);
	}
}


int main(){
	
	PILHA entrada;
	PILHA saida;
	
	cria(&entrada);
	cria(&saida);
	
	printf(" Vamos fazer uma fila com pilhas! \n\nEntra na pilha de entrada e sai na pilha de saida!\n\n\n");
	int entra, sai, i, erro;
	
	for(i=0; i<5; i++){
		printf("Digite o %d elemento da fila: ", i+1);
		scanf("%d", &entra);
		push(&entrada, &entra, &erro);
	}
	
	printf("\n\n...Tirando TODOS os dados da pilha de entrada para a pilha de saida...\n\n");
	int k;
	for(k=0; k < 5; k++){
		pop(&entrada, &sai, &erro);
		push(&saida, &sai, &erro);
	}
	
	printf("\n...Mostrando os dados em forma de fila...\n\n");
	int j;
	for(j=0; j < 5; j++){
		pop(&saida, &sai, &erro);
		printf("%d->", sai);
	}
	return 0;
}
