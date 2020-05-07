/* Fabiano: 18/mai/2010 */
/* Testa funcao hash perfeita usando 4 bytes por entrada de g */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define MAXK 4 /*-- No. maximo de vertices --*/
#define MAXNUMVERTICES 100000 /*--No. maximo de vertices--*/
const static int MAXTAMG = (MAXNUMVERTICES + 3)/4; /* Cada byte armazena 4 vertices */
const static int MAXTAMTABRANK = (MAXNUMVERTICES + MAXK - 1)/MAXK; /* Teto de MAXNUMVERTICES/MAXK */
#define MAXTRVALUE 255
#define MAXNUMARESTAS  100000 /*--No. maximo de arestas--*/
#define MAXR           5
#define MAXTAMCHAVE    6      /*--No. maximo de caracteres da chave--*/
#define MAXNUMCHAVES   100000 /*--No. maximo de chaves lidas--*/
#define NAOATRIBUIDO    3

typedef int TipoValorVertice;
typedef int TipoValorAresta;
typedef int Tipor;
typedef int TipoPesos[MAXTAMCHAVE];
typedef TipoPesos TipoTodosPesos[MAXR];
typedef unsigned char Tipog;
typedef unsigned char TipoTr[MAXTRVALUE + 1];
typedef int TipoTabRank;
typedef unsigned short TipoK;
typedef char TipoChave[MAXTAMCHAVE];
typedef TipoChave TipoConjChaves[MAXNUMCHAVES];
typedef TipoValorVertice TipoArranjoVertices[MAXR];
typedef TipoValorVertice TipoIndice;

static TipoValorVertice M;
static TipoValorAresta N;

void GeraTr (TipoTr Tr) 
{ int i, j, v, Soma = 0;
  for (i = 0; i <= MAXTRVALUE; i++) 
    { Soma = 0;  v = i;
      for (j = 1; j <= 4; j++) 
        { if ((v & 3) != NAOATRIBUIDO) Soma = Soma + 1;
          v = v >> 2; 
        }
      Tr[i] = Soma;
    }
} /* GeraTr */

void ImprimeTr (TipoTr Tr) 
{ int i;
  printf ("Tr = {");
  for (i = 0; i <= MAXTRVALUE; i++) 
  { if (i % 16 == 0) printf("\n");
    printf("%d ", Tr[i]);
  }
  printf("\n}\n");
} /* ImprimeTr */

void ImprimeTabRank (TipoTabRank *TabRank, int TamTabRank)
{ int i;
  printf ("TabRank = {");
  for (i = 0; i < TamTabRank; i++) 
    { if (i % 16 == 0) printf("\n");
      printf("%d ", TabRank[i]);
    }
  printf("\n}\n");
} /* ImprimeTabRank */

/*--Funcao hash universal apresentada no Programa 4.22--*/
TipoIndice h(TipoChave Chave, TipoPesos p)
{ int i; unsigned int Soma = 0; int comp = strlen(Chave);
  for (i = 0; i < comp; i++)
    Soma += (unsigned int)Chave[i] * p[i];
  return (Soma % M);
}

/* Assume que todas as entradas de 2 bits do vetor */
/* g foram inicializadas com o valor 3             */
void AtribuiValor2Bits (Tipog *g, int Indice, char Valor)
{ int i, Pos;
  i   = Indice / 4;
  Pos = (Indice % 4);
  Pos = Pos * 2;          /* Cada valor ocupa 2 bits */
  g[i] &=  ~(3 << Pos);   /* zera os dois bits a atribuir */
  g[i] |= (Valor << Pos); /* realiza a atribuicao */ 
} /* AtribuiValor2Bits */

char ObtemValor2Bits (Tipog *g, int Indice)
{ int i, Pos;
  i = Indice / 4;
  Pos = (Indice % 4);
  Pos = Pos * 2; /* Cada valor ocupa 2 bits */
  return (g[i] >> Pos) & 3;  
} /* ObtemValor2Bits */

TipoIndice hp (TipoChave Chave, Tipor r,
               TipoTodosPesos Pesos, Tipog *g)
{ int i, v = 0;
  TipoArranjoVertices a;
  for (i = 0; i < r; i++) 
    { a[i] = h(Chave, Pesos[i]);
      v += ObtemValor2Bits(g, a[i]);
    }
  v = v % r;  
  return a[v];
} /* hp */

TipoIndice hpm (TipoChave Chave, 
                Tipor r, 
		TipoTodosPesos Pesos,
                Tipog * g, 
		TipoTr Tr, 
		TipoK k,
                TipoTabRank *TabRank)
{ TipoIndice i, j, u, Rank, Byteg;
  u = hp (Chave, r, Pesos, g);
  j = u / k;      Rank = TabRank[j]; 
  i = j * k;      j  = i;
  Byteg = j / 4;  j = j + 4;
  while (j < u) 
  { Rank = Rank + Tr[g[Byteg]];
    j = j + 4;  Byteg = Byteg + 1;
  }
  j = j - 4;
  while (j < u) 
  { if (ObtemValor2Bits (g,j) != NAOATRIBUIDO) Rank = Rank+1;
    j = j + 1;
  }
  return Rank;
} /* hpm */

static void Ignore(FILE *Arq, char Delim) 
{ int c = fgetc(Arq);
  while(c != Delim && c != EOF) c = fgetc(Arq);
}

int main()
{ Tipor r; Tipog g[MAXTAMG]; TipoTr Tr;
  TipoTabRank TabRank[MAXTAMTABRANK];
  int TamTabRank; TipoK k; char Valorg;
  TipoTodosPesos Pesos; int i, j;
  TipoConjChaves ConjChaves;
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

  inline short VerificaFHPM()
  { short TabelaHash[MAXNUMVERTICES];
    int   i, indiceFHPM;
    for (i = 0; i < M; i++) TabelaHash[i] = FALSE;
    for (i = 0; i < N; i++) 
      { indiceFHPM = hpm (ConjChaves[i], r, Pesos, g, Tr, k, TabRank);
        if (TabelaHash[indiceFHPM] || indiceFHPM >= N) return FALSE;
        TabelaHash[indiceFHPM] = TRUE; 
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
  fscanf(ArqFHP, "%d*[^\n]", &k); Ignore(ArqFHP, '\n'); 
  printf("N=%d, M=%d, r=%d, k=%d\n", N, M, r, k);
  GeraTr(Tr); ImprimeTr(Tr);
  TamTabRank = (M + k -1)/k;

  for (j = 0; j < r; j++) 
    { for (i = 0; i < MAXTAMCHAVE; i++) 
        fscanf(ArqFHP, "%d*[^%d\n]", &Pesos[j][i]);
      Ignore(ArqFHP, '\n');
      printf("\n");
      for (i = 0; i < MAXTAMCHAVE; i++) 
        printf("%d ", Pesos[j][i]); 
      printf("  (p%d)\n", j);
    } 

  for (i = 0; i < M; i++) 
    { fscanf(ArqFHP, "%d*[%d\n]", &Valorg);
      AtribuiValor2Bits(g, i, Valorg); 
    }
  Ignore(ArqFHP, '\n');
  for (i = 0; i < M; i++) printf("%d ", ObtemValor2Bits(g, i)); 
  printf("  (g)\n"); 

  for (i = 0; i < TamTabRank; i++) 
    fscanf(ArqFHP, "%d*[%d\n]", &TabRank[i]);
  Ignore(ArqFHP, '\n');
  for (i = 0; i < TamTabRank; i++) 
    printf("%d ", TabRank[i]); 
  printf("  (TabRank)\n"); 

  if (VerificaFHP()) printf ("FHP foi gerada com sucesso\n");
  else printf ("FHP nao foi gerada corretamente\n");

  if (VerificaFHPM()) printf ("FHPM foi gerada com sucesso\n");
  else printf ("FHPM nao foi gerada corretamente\n");

  printf("Chave: ");  
  scanf("%s*[^\n]", Chave); 
  while (strcmp(Chave, "aaaaaa") != 0) 
    { printf ("FHP: %d\n", hp(Chave, r, Pesos, g));
      printf ("FHPM: %d\n", hpm(Chave, r, Pesos, g, Tr, k, TabRank));
      printf("Chave: ");  
      scanf("%s*[^\n]", Chave); 
    }
  fclose (ArqChaves);
  fclose (ArqFHP);
  return 0;
}