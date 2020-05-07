#include <stdio.h>
#include <stdlib.h>

struct aluno{
    int matricula;
    char nome[30];
    float n1,n2,n3;
};
typedef struct descritor Lista;

Lista* cria_lista();
void libera_lista(Lista* li);
int insere_lista_final(Lista* li, struct aluno al);
int insere_lista_inicio(Lista* li, struct aluno al);
int remove_lista_inicio(Lista* li);
int remove_lista_final(Lista* li);
int tamanho_lista(Lista* li);
int lista_vazia(Lista* li);
int lista_cheia(Lista* li);
int consulta_lista_mat(Lista* li, int mat, struct aluno *al);
int consulta_lista_pos(Lista* li, int pos, struct aluno *al);
void imprime_lista(Lista* li);

//Definição do tipo lista
struct elemento{
    struct aluno dados;
    struct elemento *prox;
};
typedef struct elemento Elem;

//Definição do Nó Descritor
struct descritor{
    struct elemento *inicio;
    struct elemento *final;
    int qtd;
};


Lista* cria_lista(){
    Lista* li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL){
        li->inicio = NULL;
        li->final = NULL;
        li->qtd = 0;
    }
    return li;
}

void libera_lista(Lista* li){
    if(li != NULL){
        Elem* no;
        while((li->inicio) != NULL){
            no = li->inicio;
            li->inicio = li->inicio->prox;
            free(no);
        }
        free(li);
    }
}

int tamanho_lista(Lista* li){
    if(li == NULL)
        return 0;
    return li->qtd;
}

int lista_cheia(Lista* li){
    return 0;
}

int lista_vazia(Lista* li){
    if(li == NULL)
        return 1;
    if(li->inicio == NULL)
        return 1;
    return 0;
}

int insere_lista_inicio(Lista* li, struct aluno al){
    if(li == NULL)
        return 0;
    Elem* no;
    no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados = al;
    no->prox = li->inicio;
    if(li->inicio == NULL)
        li->final = no;
    li->inicio = no;
    li->qtd++;
    return 1;
}

int insere_lista_final(Lista* li, struct aluno al){
    if(li == NULL)
        return 0;
    Elem *no;
    no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados = al;
    no->prox = NULL;
    if(li->inicio == NULL)//lista vazia: insere início
        li->inicio = no;
    else
        li->final->prox = no;

    li->final = no;
    li->qtd++;
    return 1;
}


int remove_lista_inicio(Lista* li){
    if(li == NULL)
        return 0;
    if(li->inicio == NULL)//lista vazia
        return 0;

    Elem *no = li->inicio;
    li->inicio = no->prox;
    free(no);
    if(li->inicio == NULL)
        li->final = NULL;
    li->qtd--;
    return 1;
}

int remove_lista_final(Lista* li){
    if(li == NULL)
        return 0;
    if(li->inicio == NULL)//lista vazia
        return 0;

    Elem *ant, *no = li->inicio;
    while(no->prox != NULL){
        ant = no;
        no = no->prox;
    }
    if(no == li->inicio){//remover o primeiro?
        li->inicio = NULL;
        li->final = NULL;
    }else{
        ant->prox = no->prox;
        li->final = ant;
    }
    free(no);
    li->qtd--;
    return 1;
}
//=================================================
int consulta_lista_pos(Lista* li, int pos, struct aluno *al){
    if(li == NULL || li->inicio == NULL || pos <= 0)
        return 0;
    Elem *no = li->inicio;//primeiro elemento
    int i = 1;
    while(no != NULL && i < pos){
        no = no->prox;
        i++;
    }
    if(no == NULL)
        return 0;
    else{
        *al = no->dados;
        return 1;
    }
}

int consulta_lista_mat(Lista* li, int mat, struct aluno *al){
    if(li == NULL || li->inicio == NULL)
        return 0;
    Elem *no = li->inicio;
    while(no != NULL && no->dados.matricula != mat)
        no = no->prox;
    if(no->dados.matricula != mat)
        return 0;
    else{
        *al = no->dados;
        return 1;
    }
}

void imprime_lista(Lista* li){
    if(li == NULL || li->inicio == NULL)
        return;
    Elem* no = li->inicio;
    while(no != NULL){
        printf("Matricula: %d\n",no->dados.matricula);
        printf("Nome: %s\n",no->dados.nome);
        printf("Notas: %f %f %f\n",no->dados.n1,
                                   no->dados.n2,
                                   no->dados.n3);
        printf("-------------------------------\n");
        no = no->prox;
    }
}


int main(){
    struct aluno a1,a[4] = {{2,"Andre",9.5,7.8,8.5},
                         {4,"Ricardo",7.5,8.7,6.8},
                         {1,"Bianca",9.7,6.7,8.4},
                         {3,"Ana",5.7,6.1,7.4}};
    Lista* li = cria_lista();
    printf("Tamanho: %d\n\n\n\n",tamanho_lista(li));

    int i;
    for(i=0; i < 4; i++)
        insere_lista_final(li,a[i]);

    imprime_lista(li);
    printf("\n\n\n\n Tamanho: %d\n",tamanho_lista(li));


    for(i=0; i < 4; i++){
        if (consulta_lista_pos(li, i+1, &a1))
            printf("ok: %s\n",a1.nome);
        else
            printf("erro: %s\n",a1.nome);

    }

//    imprime_lista(li);
//    printf("\n\n\n\n Tamanho: %d\n",tamanho_lista(li));
//
    for(i=1; i <= 6; i++){
        //remove_lista(li,i+1);
        if(!remove_lista_final(li))
            printf("Erro!!!!!!!!!\n");
        imprime_lista(li);
        printf("\n\n======================\n\n");
    }
//    for(i=0; i < 4; i++)
//        insere_lista_ordenada(li,a[i]);
//
//    imprime_lista(li);

    for(i=0; i < 2; i++)
        insere_lista_final(li,a[i]);

    imprime_lista(li);

    libera_lista(li);
    system("pause");
    return 0;
}
