#include <stdio.h>
#include <stdlib.h>

/* este programa le um arquivo texto, caracter por caracter..
*/


int main(int argc, char const *argv[])
{

	FILE *fp;
	char ch;

	// cria o arquivo teste.txt para escrita. VEja.. se nao especificamos 'b', entao
	// o arquivo eh texto...



	fp = fopen(argv[1],"r");

	if (fp == NULL){
		printf("Opa... nao foi possivel abrir o arquivo...\n");
		exit(0);
	}

	while ((ch = fgetc(fp)) != EOF ) {
		printf("%c", ch);
	}

	// nao se esqueca de fechar o arquivo, para ESVAZIAR o buffer...
	fclose(fp);
	printf("\n");

	/* code */
	return 0;
}


