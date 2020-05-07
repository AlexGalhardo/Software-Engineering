#include <stdlib.h>

typedef char elem;

struct bloco{
	elem info;
	struct bloco *prox;
};

typedef struct bloco no;

struct pilha {
	no* topo;
};

typedef struct pilha Pilha;

void Create(Pilha *P);
void Push(Pilha *P, elem *X, int *erro);
void Pop(Pilha *P, elem *X, int *erro);
int IsEmpty(Pilha *P);


