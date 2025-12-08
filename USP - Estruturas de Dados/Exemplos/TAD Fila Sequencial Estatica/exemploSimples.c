#include <stdio.h>
#include <stdlib.h>

#define tamFila 10

typedef struct{
	int inicio, fim, total;
	int dados[tamFila];
}FILA;

void cria(FILA *f){
	f->inicio =0;
	f->fim=0;
	f->total=0;
}

int cheia(FILA *f){
	if(f->total == tamFila-1){
		return 1;
	}else return 0;
}

void push(FILA *f, int *dado, int *erro){
	if(!cheia(f)){
		*erro = 0;
		f->total++;
		f->dados[f->fim] = *dado;
		f->fim++;
	}else *erro =1;
	return;
}

int vazia(FILA *f){
	if(f->total == 0){
		return 1;
	}else return 0;
}

void pop(FILA *f, int *saida, int *erro){
	if(!vazia(f)){
		*erro =0;
		*saida = f->dados[f->inicio];
		f->inicio++;
		f->total--;
	}else *erro =1;
	return;
}

void primeiro(FILA *f, int *saida, int *erro){
	if(!vazia(f)){
		*erro = 0;
		*saida = f->dados[f->inicio];
	}else *erro = 1;
	return;
}


int main(){
	
	FILA f;
	cria(&f);
	
	printf("Criando uma fila estatica!\n\n");
	
	int qtd, i, entrada, saida, erro;
	printf("Digite quantos elementos voce quer adicionar na lista: ");
	scanf("%d", &qtd);
	
	for(i=0; i<qtd; i++){
		printf("\nDigite o elemento %d da fila: ", i+1);
		scanf("%d", &entrada);
		push(&f, &entrada, &erro);
	}
	
	printf("\nPrintando os dados adicionados dentro da fila...\n\n");
	int k;
	for(k=0; k < qtd; k++){
		pop(&f, &saida, &erro);
		printf("%d->", saida);
	}
	
	return 0;
}
