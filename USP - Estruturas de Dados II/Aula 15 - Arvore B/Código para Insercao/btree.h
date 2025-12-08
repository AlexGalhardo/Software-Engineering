#ifndef BTREE
#define BTREE

#include <stdio.h>
#include <stdlib.h>

#define MAX 5    // numero maximo de chaves no no MAX = m - 1
#define MIN 2    // lembre-se de que nro minimo: MIN = |"m/2"| -1 

typedef char chave;

typedef struct no{
	int cont;
	chave chaves[MAX+1];       // atencao, nesta implementacao nao usaremos a posicao 0, a primeira chave 
	 							// sera armazenada em chaves[1]. As chaves menores que ela estarão
								// em filhos[0].....
	struct no *filhos[MAX+1];
	int folha;   
}No;

// prototipos das funcoes...
No *buscaArvore(chave , No *, int *);
int buscaChave(chave, No *, int *);
No *insereArvore(chave, No *);
int overflow(chave , No *, chave *, No **);
void insereNo(chave, No *, No *, int);
void split(chave , No *, No *, int , chave *, No **);
void imprimeArvore(No *);
No  *removeArvore(chave, No *);
void sobeSucessor(No *, int);
void removeChave(No *, int );
void restauraArvore(No *, int);
void moveParaDireita(No *, int);
void moveParaEsquerda(No *, int);
void combinaIrmaos(No *, int);

#endif