#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int vazia(LISTA *lista){
	if(lista->ini==NULL){
		return 1;
	}else{
		return 0;
	}
}

LISTA* cria(int *erro){
	LISTA *lista;
	lista = (LISTA*)malloc(sizeof(LISTA));
	if(lista==NULL){
		*erro = 1;
	}
	*erro = 0;
	lista->ini = NULL;
	return lista;
}

/* adicionar dados na lista generalizada */
void push(LISTA *lista, int valor, int *erro, int tipo, int adicionarOnde){

  /* cria um novo ponteiro tipo no */
	no *aux;
	aux = (no*)malloc(sizeof(no));
	if(aux==NULL){
		*erro = 1;
	}
	*erro = 0;

  if( tipo == 1 ){
    aux->tipo = 1;
    aux->info.atomo = valor;
    aux->prox = NULL;
  }
  else{
    aux->tipo = 2; /* a partir deste nó tem 1 lista */
		//aux->info.atomo = valor;
		aux->info.sublista = NULL;
    aux->prox = NULL;
  }

	//aux->info = *dado;
	//aux->prox = NULL;
	if( adicionarOnde == 1 ){
		if(lista->ini == NULL){
			lista->ini = aux;
	  }
	  else{
	    aux->prox = lista->ini;
		   lista->ini = aux;
	   }
	}
	else {
		no *procuraSub;
		procuraSub = lista->ini;
		while ( procuraSub->tipo != 2 ){
			procuraSub = procuraSub->prox;
		}
		procuraSub = procuraSub->info.sublista;
		while( procuraSub != NULL ){
			procuraSub = procuraSub->prox;
		}
		procuraSub = aux;
	}
}

void pop(LISTA *lista, int *saida, int *erro){

	if(vazia(lista)){
		*erro = 1;
		return;
	}

	no *aux;
	aux = (no*)malloc(sizeof(no));
	if(aux == NULL){
		*erro = 1;
		return;
	}
	*erro = 0;

	aux = lista->ini;
	*saida = aux->info.atomo;
	lista->ini = aux->prox;
	free(aux);
}

int tamanho(LISTA *lista){

	no *aux;
	aux = (no*)malloc(sizeof(no));
	if(aux == NULL){
		exit(1);
	}

	int cont;
	aux = lista->ini;
	while(aux != NULL){
		cont++;
		aux = aux->prox;
	}
	return cont;
}

int esta_na_lista_principal(LISTA *L, elem *x) {

    no *p;
    p=L->ini;
    while (p!=NULL) {
          if ((p->tipo==0) && (p->info.atomo==*x))
             return(1);
          else p=p->prox;
    }
    return(0);
}
/*
void printarListaPrincipal(lista, int *dado){

  no *aux;
  aux = lista->ini;
  while ( aux != NULL ){

      if(aux->tipo==1){
        *dado = aux.info.atomo;
      }
  }
}*/

void percorreLista(no *aux){

	while ( aux != NULL){
		printf("%d ->", aux->info.atomo);
		aux = aux->prox;
	}
}

int esta_em_qualquer_parte_da_lista(no *p, elem *x) {
    if (p==NULL)
       return 0;
    else if (p->tipo==0) {
         if (p->info.atomo==*x)
            return 1;
         else return(esta_em_qualquer_parte_da_lista(p->prox,x));
    }
    else if (p->tipo==1) {
         if (esta_em_qualquer_parte_da_lista(p->info.sublista,x))
            return 1;
         else return(esta_em_qualquer_parte_da_lista(p->prox,x));
    }
}

/*
void printarLista(no *aux){

  if(aux== NULL){
    return 0;
  }
  else if( aux->tipo == 1){
    if(p->info.atomo){
      printf("%d ->", p->info.atomo);
    }
    else return*printarLista
  }

}
*/
int iguais(no *L1, no *L2) {
    if ((L1==NULL) && (L2==NULL))
       return 1;
    else if ((L1==NULL) || (L2==NULL))
         return 0;
    else if ((L1->tipo==L2->tipo==0) && (L1->info.atomo==L2->info.atomo))
         return(iguais(L1->prox,L2->prox));
    else if ((L1->tipo==L2->tipo==1) && (iguais(L1->info.sublista,L2->info.sublista)))
         return(iguais(L1->prox,L2->prox));
    else return 0;
}

int iguais_estruturalmente(no *L1, no *L2) {
    if ((L1==NULL) && (L2==NULL))
       return 1;
    else if ((L1==NULL) || (L2==NULL))
         return 0;
    else if (L1->tipo==L2->tipo==0)
         return(iguais_estruturalmente(L1->prox,L2->prox));
    else if ((L1->tipo==L2->tipo==1) && (iguais_estruturalmente(L1->info.sublista,L2->info.sublista)))
         return(iguais_estruturalmente(L1->prox,L2->prox));
    else return 0;
}

int profundidade(no *p) {

    int prof, aux;

    if (p==NULL)
       prof=0;
    else if (p->tipo==0) {
         prof=1;
         aux=profundidade(p->prox);
         if (aux>prof)
            prof=aux;
    }
    else if (p->tipo==1) {
         prof=1+profundidade(p->info.sublista);
         aux=profundidade(p->prox);
         if (aux>prof)
            prof=aux;
    }
    return(prof);
}
