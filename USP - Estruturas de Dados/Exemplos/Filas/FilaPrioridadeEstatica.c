#include <stdio.h>
#include <stdlib.h>
//Arquivo FilaPrioridade.h
#define MAX 100

typedef struct fila_prioridade FilaPrio;

FilaPrio* cria_FilaPrio();
void libera_FilaPrio(FilaPrio* fp);
int consulta_FilaPrio(FilaPrio* fp, char* nome);
int insere_FilaPrio(FilaPrio* fp, char *nome, int  prioridade);
int remove_FilaPrio(FilaPrio* fp);
int tamanho_FilaPrio(FilaPrio* fp);
int estaCheia_FilaPrio(FilaPrio* fp);
int estaVazia_FilaPrio(FilaPrio* fp);
void imprime_FilaPrio(FilaPrio* fp);

struct paciente{
    char nome[30];
    int prio;
};

struct fila_prioridade{
    int qtd;
    struct paciente dados[MAX];
};

FilaPrio* cria_FilaPrio(){
    FilaPrio *fp;
    fp = (FilaPrio*) malloc(sizeof(struct fila_prioridade));
    if(fp != NULL)
        fp->qtd = 0;
    return fp;
}

void libera_FilaPrio(FilaPrio* fp){
    free(fp);
}

int consulta_FilaPrio(FilaPrio* fp, char* nome){
    if(fp == NULL || fp->qtd == 0)
        return 0;
    strcpy(nome,fp->dados[fp->qtd-1].nome);
    return 1;
}

int insere_FilaPrio(FilaPrio* fp, char *nome, int prioridade){
    if(fp == NULL)
        return 0;
    if(fp->qtd == MAX)//fila cheia
        return 0;

    int i = fp->qtd-1;
    while(i >= 0 && fp->dados[i].prio >= prioridade){
        fp->dados[i+1] = fp->dados[i];
        i--;
    }

    strcpy(fp->dados[i+1].nome,nome);
    fp->dados[i+1].prio = prioridade;
    fp->qtd++;
    return 1;
}

int remove_FilaPrio(FilaPrio* fp){
    if(fp == NULL)
        return 0;
    if(fp->qtd == 0)
        return 0;
    fp->qtd--;
    return 1;
}

int tamanho_FilaPrio(FilaPrio* fp){
    if(fp == NULL)
        return -1;
    else
        return fp->qtd;
}

int estaCheia_FilaPrio(FilaPrio* fp){
    if(fp == NULL)
        return -1;
    return (fp->qtd == MAX);
}

int estaVazia_FilaPrio(FilaPrio* fp){
    if(fp == NULL)
        return -1;
    return (fp->qtd == 0);
}

void imprime_FilaPrio(FilaPrio* fp){
    if(fp == NULL)
        return;
    int i;
    for(i=fp->qtd-1; i >=0 ; i--){
        printf("Prio: %d \tNome: %s\n",fp->dados[i].prio,fp->dados[i].nome);
    }
}

int main(){
    struct paciente itens[6] = {{"Andre",1},
                                {"Bianca",2},
                                {"Carlos",5},
                                {"Nilza",10},
                                {"Inacio",9},
                                {"Edu",2}};

    FilaPrio* fp;
    fp = cria_FilaPrio();

    int i;
    for (i=0; i< 6; i++){
        printf("%d) %d %s\n",i,itens[i].prio, itens[i].nome);
        insere_FilaPrio(fp, itens[i].nome,itens[i].prio);
    }

    printf("=================================\n");

    imprime_FilaPrio(fp);

    printf("=================================\n");
    for (i=0; i< 6; i++){
        remove_FilaPrio(fp);
        imprime_FilaPrio(fp);
        printf("=================================\n");
    }

    libera_FilaPrio(fp);

    system("pause");
    return 0;
}

