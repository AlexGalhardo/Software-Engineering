#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>

typedef struct no{
    int info;
    struct no *prox;
}NO;

typedef struct{
    NO *topo;
}PILHA;

void criaPilha(PILHA *p){
    p->topo = NULL;
}

int vazia(PILHA *p){
    if(p->topo == NULL){
        return 1;
    }else return 0;
}

void push(PILHA *p, int *dado, int *erro){
    
    NO *aux;
    aux = (NO*)malloc(sizeof(NO));
    if(aux==NULL){
        *erro = 1;
        return;
    }
    else{
		*erro = 0;
		aux->info = *dado;
		aux->prox = p->topo;
		p->topo = aux;			
	}
}

void pop(PILHA *p, int *saida, int *erro){
    
    NO *aux;
    aux = (NO*)malloc(sizeof(NO));
    if(aux== NULL){
        *erro = 1;
        return;
    }
    
    if(vazia(p)){
        *erro = 1;
    }
    else{
        *erro = 0;
        *saida = p->topo->info;
        aux = p->topo;
        p->topo = p->topo->prox;
        free(aux);
    }
}

int main(){
    
    PILHA pilha;
    criaPilha(&pilha);
    PILHA aux;
    criaPilha(&aux);
    
    int i, dado, erro, novo, saida;
    for(i=0; i<5; i++){
        printf("Digite o %d dado da pilha: ", i+1);
        scanf("%d", &dado);
        push(&pilha, &dado, &erro);
    }
    
    printf("Digite um novo dado que sera adicionado ordenadamente: ");
    scanf("%d", &novo);
    
    while(!vazia(&pilha)){
        pop(&pilha, &saida, &erro);
        if(saida <= novo){
            push(&pilha, &saida, &erro);
            break;
        }else{
            push(&aux, &saida, &erro);
        }
    }
    
    push(&pilha, &novo, &erro);
    
    while(!vazia(&aux)){
        pop(&aux, &dado, &erro);
        push(&pilha, &dado, &erro);
    }
    
    printf("...Printando os dados da pilha ordenanda em ordem decrescente...\n\n");
    int k;
    for(k=0; k<6; k++){
        pop(&pilha, &dado, &erro);
        printf("%d->", dado);
    }
    
    return 0;
}
