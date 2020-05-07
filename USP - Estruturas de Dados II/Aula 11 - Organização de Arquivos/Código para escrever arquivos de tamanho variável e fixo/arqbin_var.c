#include <stdio.h>
#include <string.h>

typedef struct disciplina {
      char titulo[50];
      int codigo;
} DISC;

int main(void) {
      FILE *fp;
      DISC d1, d2;
      int a;
      unsigned char ts2;
      
      fp=fopen("testevar.dat","w+b");

      /* 
	    Usa campo titulo de tamanho variavel
	    indicando nos primeiro byte o tamanho do campo
      */
      for (a=0; a<3; a++) {
	    printf("Titulo e codigo da disciplina %d: ", a+1);
	    scanf("%s %d", (d1).titulo, &d1.codigo);
      
	    ts2 = (unsigned char)strlen(d1.titulo);
	    printf("Escreve string de tamanho %u\n", ts2 );
	    fwrite(&ts2, sizeof(unsigned char), 1, fp);
	    fwrite(&d1.titulo, ts2, 1, fp);
	    fwrite(&d1.codigo, sizeof(int), 1, fp);
      }
      
      printf("Leitura do arquivo:\n");
      fclose(fp);
      fp=fopen("testevar.dat","rb");
      
      for (a=0; a<3; a++) {
	    fread(&ts2, sizeof(unsigned char), 1, fp);
	    fread(&d2.titulo, ts2, 1, fp);
	    fread(&d2.codigo, sizeof(int), 1, fp);
	    printf("Disciplina %d: %s (%u) %d\n", a+1, d2.titulo, ts2, d2.codigo);
      }
      fclose(fp);
      return 0;
}
