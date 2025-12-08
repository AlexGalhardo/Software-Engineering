#include <stdlib.h>
#include <string.h>

typedef struct bloco {
	char nome[20];
	struct bloco *ant, *prox;
} no;

typedef struct {
	
	no *ini, *fim;
	
}Lista;



