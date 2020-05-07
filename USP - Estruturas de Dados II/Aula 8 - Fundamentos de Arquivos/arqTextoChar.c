#include <stdio.h>
#include <stdlib.h>

/* este programa le caracteres do teclado e vai colocando-os
no arquivo, um por um até que seja digitado enter...
*/


int main(int argc, char const *argv[])
{

	FILE *fp;
	char ch;

	// cria o arquivo teste.txt para escrita. VEja.. se nao especificamos 'b', entao
	// o arquivo eh texto...



	fp = fopen(argv[1],"w");

	if (fp == NULL){
		printf("Opa... nao foi possivel abrir o arquivo...\n");
		exit(0);
	}

	while ((ch = getchar()) != '\n' ) {
		fputc(ch, fp);
	}

	// nao se esqueca de fechar o arquivo, para ESVAZIAR o buffer...
	fclose(fp);

	/* code */
	return 0;
}