#include <stdio.h>
#include <stdlib.h>
#include "btree.h"


int main(int argc, char const *argv[]){
	
	No *raiz = NULL;
	int pos;

	// chave = char
	chave ch = 'A';

	if (buscaArvore(ch, raiz, &pos)){
		printf("Encontrou a chave %c na posicao = %d\n", ch, pos);
	} else {
		printf("Chave nao encontrada...\n");
	}

	// raiz = insereArvore('M', raiz);
	// raiz = insereArvore('D', raiz);
	// raiz = insereArvore('H', raiz);
	// raiz = insereArvore('Q', raiz);
	// raiz = insereArvore('U', raiz);
	// raiz = insereArvore('A', raiz);
	// raiz = insereArvore('C', raiz);
	// raiz = insereArvore('E', raiz);
	// raiz = insereArvore('F', raiz);
	// raiz = insereArvore('I', raiz);
	// raiz = insereArvore('J', raiz);
	// raiz = insereArvore('K', raiz);
	// raiz = insereArvore('N', raiz);
	// raiz = insereArvore('O', raiz);
	// raiz = insereArvore('P', raiz);
	// raiz = insereArvore('R', raiz);
	// raiz = insereArvore('S', raiz);
	// raiz = insereArvore('V', raiz);
	// raiz = insereArvore('W', raiz);
	// raiz = insereArvore('X', raiz);
	// raiz = insereArvore('Y', raiz);
	// raiz = insereArvore('Z', raiz);


	// ./arvoreb < 2.in
	// le cada character dentro do arquivo 2.in
	// enquanto não chegar no 'END OF FILE'
	while ((ch = fgetc(stdin)) != EOF){
		printf("Chave lida = >%c<\n", ch);
		// insere na arvore
		raiz = insereArvore(ch, raiz);
		// consome o '\n' em cada linha
		ch = getc(stdin);
	}


	imprimeArvore(raiz);
	printf("\n");

	raiz = removeArvore('J', raiz);
	
	imprimeArvore(raiz);
	printf("\n");

	raiz = removeArvore('S', raiz);
	imprimeArvore(raiz);
	printf("\n");

	raiz = removeArvore('Q', raiz);
	imprimeArvore(raiz);
	printf("\n");

	raiz = removeArvore('A', raiz);
	imprimeArvore(raiz);
	printf("\n");

	raiz = removeArvore('C', raiz);
	imprimeArvore(raiz);
	printf("\n");

	raiz = removeArvore('D', raiz);
	imprimeArvore(raiz);
	printf("\n");

	raiz = removeArvore('E', raiz);
	imprimeArvore(raiz);
	printf("\n");

	raiz = removeArvore('F', raiz);
	imprimeArvore(raiz);
	printf("\n");

	raiz = removeArvore('H', raiz);
	imprimeArvore(raiz);
	printf("\n");

	raiz = removeArvore('I', raiz);
	imprimeArvore(raiz);
	printf("\n");

	raiz = removeArvore('K', raiz);
	imprimeArvore(raiz);
	printf("\n");

	raiz = removeArvore('M', raiz);
	imprimeArvore(raiz);
	printf("\n");

	raiz = removeArvore('N', raiz);
	imprimeArvore(raiz);
	printf("\n");

	raiz = removeArvore('O', raiz);
	imprimeArvore(raiz);
	printf("\n");

	raiz = removeArvore('P', raiz);
	imprimeArvore(raiz);
	printf("\n");

	raiz = removeArvore('R', raiz);
	imprimeArvore(raiz);
	printf("\n");

	raiz = removeArvore('U', raiz);
	imprimeArvore(raiz);
	printf("\n");

	raiz = removeArvore('V', raiz);
	imprimeArvore(raiz);
	printf("\n");

	raiz = removeArvore('W', raiz);
	imprimeArvore(raiz);
	printf("\n");

	raiz = removeArvore('X', raiz);
	imprimeArvore(raiz);
	printf("\n");

	raiz = removeArvore('Y', raiz);
	imprimeArvore(raiz);
	printf("\n");

	raiz = removeArvore('Z', raiz);

	imprimeArvore(raiz);
	printf("\n");

	// neste ponto a arvore ficou completamente vazia...se tentar retirar algo
	raiz = removeArvore('*', raiz);

	return 0;
}
