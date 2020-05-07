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

void cria(FILA *f){
	f->inicio = NULL;
	f->fim = NULL;
}

int vazio(FILA *f){
	if(f->inicio == NULL)
		return 1;
	else return 0;
}

void push(FILA *f, int *dado, int *erro){
	
	NO *aux;
	aux = (NO*)malloc(sizeof(NO));
	
	if(aux == NULL){
		*erro = 1;
		exit(1);
	}
	
	*erro = 0;
	aux->info = *dado;
	aux->prox = NULL;
	
	if(f->inicio==NULL){
		f->inicio = aux;
	}
	else{
		f->fim->prox = aux;
	}
	f->fim = aux;
}

void pop(FILA *f, int *dado, int *erro){
	
	NO *aux;
	aux = (NO*)malloc(sizeof(NO));
	
	if(vazio(f)){
		*erro = 1;
	}
	else {
		*erro = 0;
		*dado = f->inicio->info;
		aux = f->inicio;
		f->inicio = f->inicio->prox;
		if(f->inicio == NULL){
			f->fim = NULL;
		}
		free(aux);
	}
}


int qtdFila(FILA *f){
	
	NO *aux;
	aux = (NO*)malloc(sizeof(NO));
	if(aux == NULL){
		exit(1);
	}
	aux = f->inicio;
	
	int cont=0;
	
	while(aux != NULL){
		cont++;
		aux = aux->prox;
	}
	
	free(aux);
	return cont;
}

int ultimo(FILA *f, int *dado){
	return *dado = f->fim->info;
}

void addPosition(FILA *f, int indice, int *item){
	
	NO *aux;
	aux = (NO*)malloc(sizeof(NO));
	if(aux == NULL){
		exit(1);
	}
	aux = f->inicio;
	
	NO *next;
	next = (NO*)malloc(sizeof(NO));
	if(next == NULL){
		exit(1);
	}
	next = f->inicio;
	
	
	NO *dado;
	dado = (NO*)malloc(sizeof(NO));
	if(dado == NULL){
		exit(1);
	}
	dado->info = *item;
	dado->prox = NULL;
	
	
	if(f->inicio == NULL){
		exit(1);
	}
	
	int posicao =0;
	while(aux != NULL && posicao < indice){
		posicao++;
		aux = aux->prox;
	}
	
	int index=0;
	while(next != NULL && index <= indice){
		index++;
		next = next->prox;
	}
	
	aux->prox = dado;
	dado->prox = next->prox;
	
	free(aux);
	free(next);
	
}

int main(){
	
	printf("...Criando uma fila simples\n\n");
	FILA f;
	cria(&f);
	
	int i, entra, sai, erro, qtd, last, tamFila;
	
	printf("\n Digite quantos elementos voce gostaria de adicionar na fila: ");
	scanf("%d", &tamFila);
	
	for(i=0; i<tamFila; i++){
		printf(" Digite o %d elemento da fila: ", i+1);
		scanf("%d", &entra);
		push(&f, &entra, &erro);
	}
	
	qtd = qtdFila(&f);
	printf("\n A quantidade de elementos na fila eh: [%d]\n", qtd);
	
	ultimo(&f, &last);
	printf("\n O ultimo elemento da fila eh: [%d]\n\n", last);
	
	int opcao=0, indice, item;
	printf(" Gostaria de adicinar algum elemento em determinada posição da lista?\n");
	while(1){
		printf(" Digite [1] --> SIM\n");
		printf(" Digite [2] --> NAO\n");
		scanf("%d", &opcao);
		if(opcao == 1){
			printf(" Qual indice da lista voce quer adicionar: ");
			scanf("%d", &indice);
			indice=indice-2;
			printf(" Qual numero voce gostaria de adicionar: ");
			scanf("%d", &item);
			addPosition(&f, indice, &item);
			break;
		}else if(opcao == 2){
			break;
		}
	}
	
	printf("\n ...Printando os dados da fila...\n\n");
	int k;
	for(k=0; k<tamFila; k++){
		pop(&f, &sai, &erro);
		printf("%d->", sai);
	}
	return 0;
}
