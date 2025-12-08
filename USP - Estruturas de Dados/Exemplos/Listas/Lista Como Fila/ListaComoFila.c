#include "ListaComoFila.h"

void Cria(Fila *F){
	F->inicio = NULL;
	F->fim = NULL;
}

void Entra(Fila *F, elem *X, int *erro){
	
	no *p;
	
	p = (no*)malloc(sizeof(no));
	if(p==NULL)
		*erro = 1;
		else {
			*erro = 0;
			p->info = *X;
			p->prox = NULL;
			if(F->inicio == NULL)
				F->inicio = p;
				else F->fim->prox = p;
			F->fim = p;	
		}
}

void Sai(Fila *F, elem *X, int *erro){
	
	no *p;
	
	if(EstaVazia(F))
		*erro = 1;
		else {
			*erro = 0;
			*X = F->inicio->info;
			p = F->inicio;
			F->inicio = F->inicio->prox;
			if(F->inicio == NULL)
				F->fim=NULL;
			free(p);
		}	
}

int EstaVazia(Fila *F){
	if(F->inicio == NULL)
		return 1;
		else return 0;
}

int EstaCheia(Fila *F){
	
	no *p;
	
	p=(no*)malloc(sizeof(no));
	
	if(p==NULL)
		return 1;
		else {
			free(p);
			return 0;
		}
}




