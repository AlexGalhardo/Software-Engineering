#include <stdio.h>
#include <stdlib.h>

/* 

P2
# feep.pgm
24 7
15
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  3  3  3  3  0  0  7  7  7  7  0  0 11 11 11 11  0  0 15 15 15 15  0
0  3  0  0  0  0  0  7  0  0  0  0  0 11  0  0  0  0  0 15  0  0 15  0
0  3  3  3  0  0  0  7  7  7  0  0  0 11 11 11  0  0  0 15 15 15 15  0
0  3  0  0  0  0  0  7  0  0  0  0  0 11  0  0  0  0  0 15  0  0  0  0
0  3  0  0  0  0  0  7  7  7  7  0  0 11 11 11 11  0  0 15  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0


veja a imagem acima. Sim.. é uma imagem... se vc copiar o conteudo acima
e gravar como uma imagem feep.pgm, será capaz de abri-la com qq programa
de imagens que quiser..
a primeira linha é o magic number (p2 -> texto; p5 -> binario)
a segunda linha: um mero comentario.. pode ser qq coisa
terceira linha: dimensoes x e y da imagem (colunas, linhas)
quarta linha: o valor maximo que o pixel pode receber.

Note que os pixels da imagem acima sao gravados em texto (ou plain, em ingles)
O mais interessante com este formato é que vc pode gravar a imagem no formato
BINARIO, o que economizaria bastante espaco...

basta trocar o magic number "P2" por "P5". Escreva um programa que crie uma 
imagem binaria de tamanho 255x255, em formato binario que seja branco no fundo
e que tenha um quadrado de tamanho aproximado de 50x50 no centro de cor preta...

para ver se o seu programa funciona, abra a imagem com um programa externo..

OBS: imagens nivel de cinza, o branco = 255 e o preto = 0; (unsigned char)

*/

#define lin 256
#define col 256

int main(int argc, char const *argv[])
{

	FILE *fp;
	unsigned char img[lin*col];


	
	// cria o arquivo teste.txt para escrita. VEja.. se nao especificamos 'b', entao
	// o arquivo eh texto...



	fp = fopen(argv[1],"wb");

	if (fp == NULL){
		printf("Opa... nao foi possivel abrir o arquivo...\n");
		exit(0);
	}

	// crie o header da imagem
	fprintf(fp, "P5\n");
	fprintf(fp, "# Imagem Criada por Joao\n");
	fprintf(fp, "%d %d\n", col, lin);
	fprintf(fp, "%d\n", 255); // a imagem eh nivel de cinza, cujo maior valor eh 255 -> branco


	for (int i = 0; i < lin; ++i)
		for (int j = 0; j < col; ++j)
			img[i*col+j] = 255;

	for (int i = 0+103; i < lin-103; ++i)
		for (int j = 0+103; j < col-103; ++j)
			img[i*col+j] = 0;

	// escreve com um unico comando todo o stream de dados..
	fwrite(img, sizeof(unsigned char), lin*col, fp);

	// nao se esqueca de fechar o arquivo, para ESVAZIAR o buffer...
	fclose(fp);

	/* code */
	return 0;
}