#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct no{
	int info;
	struct no *prox;
}NO;

typedef struct{
	NO *inicio, *fim;
}FILA;


int vazia(FILA *f){
	if(f->inicio==NULL){
		return 1;
	}else{
		return 0;
	}
}

FILA* cria(int *erro){
	FILA *f;
	f = (FILA*)malloc(sizeof(FILA));
	if(f==NULL){
		*erro = 1;
		return;
	}
	*erro = 0;
	f->inicio = NULL;
	f->fim = NULL;
	return f;
}

void push(FILA *f, int *dado, int *erro){
	
	NO *aux;
	aux = (NO*)malloc(sizeof(NO));
	if(aux==NULL){
		*erro = 1;
		return;
	}
	*erro = 0;
	
	aux->info = *dado;
	aux->prox = NULL;
	if(f->inicio == NULL)
		f->inicio = aux;
		else f->fim->prox = aux;
	f->fim = aux;
}

void pop(FILA *f, int *saida, int *erro){
	
	if(vazia(f)){
		*erro = 1;
		return;
	}
	
	NO *aux;
	aux = (NO*)malloc(sizeof(NO));
	if(aux == NULL){
		*erro = 1;
		return;
	}
	*erro = 0;
	
	aux = f->inicio;
	*saida = aux->info; 
	f->inicio = aux->prox;
	free(aux);
}

int tamanho(FILA *f){
	
	NO *aux;
	aux = (NO*)malloc(sizeof(NO));
	if(aux == NULL){
		exit(1);
	}
	
	int cont;
	aux = f->inicio;
	while(aux != NULL){
		cont++;
	}
	return cont;
}

int main(){
	
	int erro;
	
	FILA *f;
	f = cria(&erro);
	
	int i, dado;
	for(i=0; i<5; i++){
		printf("Digite o %d dado da fila: ", i+1);
		scanf("%d", &dado);
		push(f, &dado, &erro);
	}
	
	
	printf("Printando os dados da fila...\n");
	int k, saida;
	for(k=0; k<5; k++){
		pop(f, &saida, &erro);
		printf("%d->", saida);
	}
	
	return 0;
}
