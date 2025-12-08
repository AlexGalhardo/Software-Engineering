#include <stdio.h> 
#include <stdlib.h>
#include "Pilha.h"

// Cria uma pilha P
void Create(Pilha *p){
	p->topo = -1;
	return;
}

// Esvazia uma pilha P
void Empty(Pilha *p){
	p->topo = -1;
	return;
}

//Retorn a 1 se a pilha estiver vazia, 0 se a pilha tiver conteudo
int IsEmpty(Pilha *P){
	if(P->topo == -1)
		return 1;
	else return 0;	
}

//Retorn a 1 se a pilha estiver cheia, 0 se a pilha tiver conteudo ou vazia
int IsFull(Pilha *P){
	if(P->topo == TamPilha-1)
		return 1;
	else return 0;	
}

//Insere o elemento X na pilha P. Retorna 0 se não houver erro, Retorna 1 se algum erro acontecer
int Push(Pilha *P, elem *X){
	
	if(!IsFull(P)){
		P->topo++;
		P->itens[P->topo] = *X;
		return 0;
	} else return 1;	
	
}

//Remove o elemento X da pilha P. Retorna 0 se não houver erro, Retorna 1 se algum erro acontecer
int Pop(Pilha *P, elem *X){
	if(!IsEmpty(P)){
		*X = P->itens[P->topo];
		P->topo--;
		return 0;
	} else return 1;	
}
