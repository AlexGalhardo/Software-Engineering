#include <stdio.h>
#include <stdlib.h>

/* este programa le um arquivo txt argv[1], linha a linha,
cria um outro arquivo texto arg[2] copiando o conteudo...
ou seja,,, fazemos uma copia arquivo..
*/


int main(int argc, char const *argv[])
{

	FILE *fpr, *fpw;
	char linha[1010];

	// cria o arquivo teste.txt para escrita. VEja.. se nao especificamos 'b', entao
	// o arquivo eh texto...



	fpr = fopen(argv[1],"r");
	fpw = fopen(argv[2],"w");

	if (fpr == NULL){
		printf("Opa... nao foi possivel abrir o arquivo de leitura...\n");
		exit(0);
	}

	if (fpw == NULL){
		printf("Opa... nao foi possivel criar o arquivo de saida...\n");
		exit(0);
	}

	while (fgets(linha, 1000, fpr) != NULL ) {
		fputs(linha, fpw);
	}

	// nao se esqueca de fechar o arquivo, para ESVAZIAR o buffer...
	fclose(fpr);
	fclose(fpw);

	/* code */
	return 0;
}