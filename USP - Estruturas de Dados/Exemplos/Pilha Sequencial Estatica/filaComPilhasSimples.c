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
	
	PILHA entrada;
	PILHA saida;
	
	cria(&entrada);
	cria(&saida);
	
	printf(" Vamos fazer uma fila com pilhas! \n\nEntra na pilha de entrada e sai na pilha de saida!\n\n\n");
	int entra, sai, i;
	
	for(i=0; i<5; i++){
		printf("Digite o %d elemento da fila: ", i+1);
		scanf("%d", &entra);
		push(&entrada, &entra);
	}
	
	printf("\n\n...Tirando TODOS os dados da pilha de entrada para a pilha de saida...\n\n");
	int k;
	for(k=0; k < 5; k++){
		pop(&entrada, &sai);
		push(&saida, &sai);
	}
	
	printf("\n...Mostrando os dados em forma de fila...\n\n");
	int j;
	for(j=0; j < 5; j++){
		pop(&saida, &sai);
		printf("%d->", sai);
	}
	
	return 0;
}
