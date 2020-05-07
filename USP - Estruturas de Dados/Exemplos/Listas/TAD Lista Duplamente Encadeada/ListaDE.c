#include "ListaDE.h"

void Criar(Lista *L){
	
	L->ini = NULL;
	L->fim = NULL;
	
}

void inserir(Lista *L, char *X, int *pos, int *erro){

	no *aux, *aux2;	
	no *p;
	
	p=(no*)malloc(sizeof(no));
	if(p==NULL)
		*erro = 1;
		else {
			*erro = 0;
			strcpy(p->nome, X);
			
			if(L->ini == NULL){
				
				p->ant = NULL;
				p->prox = NULL;
				L->ini = p;
				L->fim = p;
				
			}else {
			
			aux=L->ini;
						
			while((aux != NULL) &&(*pos - 1 >0)){
				aux = aux->prox;
				(*pos)--;
			}
			
			//Inserir no começo
			if(aux == L->ini){
				p->ant = NULL;
				p->prox = aux;
				L->ini = p;
				aux->ant = p;
			} 
			//Inserir no fim
			else if(aux == NULL){
				
				p->prox = NULL;
				p->ant = L->fim;
				L->fim->prox = p;
				L->fim = p;
								
			}
			//Inserir no meio
			else {
			
				aux2 = aux->ant;
				aux->ant = p;
				p->prox = aux;
				aux2->prox = p;
				p->ant = aux2;
			}
		}
	}
}





