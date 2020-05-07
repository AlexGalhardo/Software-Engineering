#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* este programa le o nome e a idade de pessoas e vai
colocando cada um destes registros, espaçados por um space
bar, um em cada linha....
quando o nome tiver dois caracteres ou menos, o programa para de inserir
e mostra na tela todos os registros que foram armazenados nestes arquivo.
Ou seja, o programa tem que voltar para o inicio do arquivo e ler todos
os registros...
*/


int main(int argc, char const *argv[])
{

	FILE *fp;
	char nome[20];
	int idade;

	fp = fopen(argv[1],"w+");

	if (fp == NULL){
		printf("Opa... nao foi possivel abrir o arquivo...\n");
		exit(0);
	}

	while (1){
		printf("Entre com o nome e a idade: ");
		scanf ("%s %d" , nome, &idade);
		if (strlen(nome) <= 2)
			break;
		fprintf(fp, "%s\t%d\n", nome, idade);
	}

	// volta o ponteiro de arquivo para inicio..
	rewind(fp);

	printf("Nomes\t\t\tIdades\n");
	while(fscanf(fp, "%s\t%d", nome, &idade) != EOF){
		printf("%s\t\t\t%d\n", nome, idade);
	}

	// nao se esqueca de fechar o arquivo, para ESVAZIAR o buffer...
	fclose(fp);

	/* code */
	return 0;
}