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
      
      fp=fopen("testefixo.dat","w+b");
      
      for (a=0; a<2; a++) {
	    printf("Titulo e codigo da disciplina %d: ", a+1);
	    scanf("%s %d", (d1).titulo, &d1.codigo);
	    fwrite(&d1, sizeof(DISC), 1, fp);
      }
      
      printf("Leitura do arquivo:\n");
      fclose(fp);
      fp=fopen("testefixo.dat","rb");
      
      for (a=0; a<2; a++) {
	    fread(&d2, sizeof(DISC), 1, fp);
	    printf("Disciplina %d: %s %d\n", a+1, d2.titulo, d2.codigo);
      }
	    
      fclose(fp);
      return 0;
}
