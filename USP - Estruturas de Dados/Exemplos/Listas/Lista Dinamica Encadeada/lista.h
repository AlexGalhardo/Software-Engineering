#include <stdlib.h>

typedef char elem;

typedef struct bloco {
        elem info;
        struct bloco *prox;
} no;

typedef struct {
        no *inicio, *fim;
} Lista;

void cria(Lista *L);
void inserir(Lista *L, elem *X, int *erro);
void finaliza(Lista *L);
int tamanho_rec(no *p);
int tamanho_rec_lista(Lista *L);
int tamanho(Lista *L);
int esta_na_lista(Lista *L, elem *X);
int esta_na_lista_rec(no *p, elem *X);
void eliminar_rec(Lista *L, no* anterior, no* atual, elem *X, int *erro);

