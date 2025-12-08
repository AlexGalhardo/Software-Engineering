#include <stdlib.h>

typedef char elem;

struct bloco{
	elem info;
	struct bloco *prox;
};

typedef struct bloco no;

struct fila {
	no* inicio, *fim;
};

typedef struct fila Fila;

void Cria(Fila *F);
void Entra(Fila *F, elem *X, int *erro);
void Sai(Fila *F, elem *X, int *erro);
int EstaVazia(Fila *F);
int EstaCheia(Fila *F);
