/* Fabiano: 18/mai/2010 */
/* Testa funcao hash perfeita usando 4 bytes por entrada de g */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define MAXNUMVERTICES 100000 /*--No. maximo de vertices--*/
#define MAXNUMARESTAS  100000 /*--No. maximo de arestas--*/
#define MAXR           5
#define MAXTAMCHAVE    6      /*--No. maximo de caracteres da chave--*/
#define MAXNUMCHAVES   100000 /*--No. maximo de chaves lidas--*/

typedef int TipoValorVertice;
typedef int TipoValorAresta;
typedef int Tipor;
typedef int TipoPesos[MAXTAMCHAVE];
typedef TipoPesos TipoTodosPesos[MAXR];
typedef char Tipog[MAXNUMVERTICES];
typedef char TipoChave[MAXTAMCHAVE];
typedef TipoChave TipoConjChaves[MAXNUMCHAVES];
typedef TipoValorVertice TipoArranjoVertices[MAXR];
typedef TipoValorVertice TipoIndice;

static TipoValorVertice M;
static TipoValorAresta N;

/*--Funcao hash universal apresentada no Programa 4.22--*/
TipoIndice h(TipoChave Chave, TipoPesos p)
{ int i; unsigned int Soma = 0; int comp = strlen(Chave);
  for (i = 0; i < comp; i++)
    Soma += (unsigned int)Chave[i] * p[i];
  return (Soma % M);
}

TipoIndice hp (TipoChave Chave, 
               Tipor r,
               TipoTodosPesos Pesos,
               Tipog g)
{ int i, v = 0; TipoArranjoVertices a;
  for (i = 0; i < r; i++) 
  { a[i] = h(Chave, Pesos[i]);
    v += g[a[i]];
  }
  v = v % r;  
  return a[v];
} 

static void Ignore(FILE *Arq, char Delim) 
{ int c = fgetc(Arq);
  while(c != Delim && c != EOF) 
    c = fgetc(Arq);
}

int main()
{ Tipor r; Tipog g; TipoTodosPesos Pesos;
  int i, j; TipoConjChaves ConjChaves;  
  FILE *ArqChaves; FILE *ArqFHP;
  char NomeArq[100]; TipoChave Chave;
 
  inline short VerificaFHP()
  { short TabelaHash[MAXNUMVERTICES];
    int   i, indiceFHP;
    for (i = 0; i < M; i++) TabelaHash[i] = FALSE;
    for (i = 0; i < N; i++) 
      { indiceFHP = hp (ConjChaves[i], r, Pesos, g);
        if (TabelaHash[indiceFHP]) return FALSE;
        TabelaHash[indiceFHP] = TRUE; 
      }
    return TRUE;
  }

  printf ("Nome do arquivo com chaves a serem lidas: ");
  scanf("%s*[^\n]", NomeArq);
  printf("NomeArq = %s\n", NomeArq);
  ArqChaves = fopen(NomeArq, "r");


  fscanf(ArqChaves, "%d %d %d*[^\n]", &N, &M, &r); 
  Ignore(ArqChaves, '\n');
  printf("N=%d, M=%d, r=%d\n", N, M, r);

  i = 0;
  while ((i < N) && (!feof(ArqChaves))) 
    { fscanf(ArqChaves,"%s*[^\n]", ConjChaves[i]); Ignore(ArqChaves, '\n');
      printf("Chave[%d]=%s\n", i, ConjChaves[i]);
      i++;  
    }
  if (i !=  N) 
  { printf("Erro: entrada com menos do que ', N, ' elementos.\n");
    exit(-1);
  }

  printf ("Nome do arquivo com a funcao hash perfeita: ");
  scanf("%s*[^\n]", NomeArq);
  printf("NomeArq = %s\n", NomeArq);
  ArqFHP = fopen(NomeArq, "rb");

  fscanf(ArqFHP, "%d*[^\n]", &N); Ignore(ArqFHP, '\n'); 
  fscanf(ArqFHP, "%d*[^\n]", &M); Ignore(ArqFHP, '\n'); 
  fscanf(ArqFHP, "%d*[^\n]", &r); Ignore(ArqFHP, '\n'); 
  printf("N=%d, M=%d, r=%d\n", N, M, r);

  for (j = 0; j < r; j++) 
    { for (i = 0; i < MAXTAMCHAVE; i++) fscanf(ArqFHP, "%d*[^%d\n]", &Pesos[j][i]);
      Ignore(ArqFHP, '\n');
      printf("\n");
      for (i = 0; i < MAXTAMCHAVE; i++) printf("%d ", Pesos[j][i]); 
      printf("  (p%d)\n", j);
    } 
  for (i = 0; i < M; i++) fscanf(ArqFHP, "%d*[%d\n]", &g[i]); 
  Ignore(ArqFHP, '\n');
  for (i = 0; i < M; i++) printf("%d ", g[i]); 
  printf("  (g)\n"); 

  if (VerificaFHP()) printf ("FHP foi gerada com sucesso\n");
  else printf ("FHP nao foi gerada corretamente\n");

  printf("Chave: "); scanf("%s*[^\n]", Chave); 
  while (strcmp(Chave, "aaaaaa") != 0) 
    { printf ("FHP: %d\n", hp(Chave, r, Pesos, g));
      printf("Chave: ");  
      scanf("%s*[^\n]", Chave); 
    }
  fclose (ArqChaves);
  fclose (ArqFHP);
  return 0;
}