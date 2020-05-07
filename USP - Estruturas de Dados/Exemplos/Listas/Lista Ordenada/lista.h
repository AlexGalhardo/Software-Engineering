// TAD lista ordenada
#include <stdio.h>

typedef int elem;

typedef struct bloco no;

typedef struct {
        no *inicio;
} ListaOrd;

void cria(ListaOrd*);
void finaliza(ListaOrd*);
void inserir(ListaOrd*,elem*,int*);
void remover(ListaOrd*,elem*,int*);
int esta_na_lista(ListaOrd*,elem*);
void imprimir(ListaOrd*);
