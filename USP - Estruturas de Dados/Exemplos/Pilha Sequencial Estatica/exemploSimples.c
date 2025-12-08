#include <stdio.h>
#include <stdlib.h>
#define tamPilha 5

typedef struct{
	int topo;
	int dados[tamPilha];
}PILHA;

void cria(PILHA *p){
	p->topo = -1;
}

int cheio(PILHA *p){
	if(p->topo == tamPilha-1)
		return 1;
	else return 0;
}

int vazio(PILHA *p){
	if(p->topo==-1)
		return 1;
	else return 0;
}

int push(PILHA *p, int *dado){
	if(!cheio(p)){
		p->topo++;
		p->dados[p->topo] = *dado;
		return 0;
	}
	return 1;
}

int pop(PILHA *p, int *dado){
	if(!vazio(p)){
		*dado = p->dados[p->topo];
		p->topo--;
		return 0;
	} else return 1;
}


int main(){
	
	PILHA p;
	cria(&p);
	
	int i, dado;
	for(i=0; i<7; i++){
		printf("Digite o %d dado: ", i+1);
		scanf("%d", &dado);
		push(&p, &dado);
	}
	
	
	printf("...Tirando os dados da pilha...\n");
	int k, saida;
	for(k=0; k<5; k++){
		pop(&p, &saida);
		printf("%d->", saida);
	}
	
	return 0;
}
