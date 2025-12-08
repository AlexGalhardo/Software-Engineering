/* Fabiano: 18/mai/2010 */
/*-- Verifica se grafo e' aciclico e Atribuig usando 8 bits por entrada de g--*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define MAXNUMVERTICES 100000 /*--No. maximo de vertices--*/
#define MAXNUMARESTAS  100000 /*--No. maximo de arestas--*/
#define MAXR           5
#define MAXTAMPROX     MAXR*MAXNUMARESTAS
#define MAXTAM         1000   /*--Usado Fila--*/
#define MAXTAMCHAVE    6      /*--No. maximo de caracteres da chave--*/
#define MAXNUMCHAVES   100000 /*--No. maximo de chaves lidas--*/
#define INDEFINIDO     -1

typedef int TipoValorVertice;
typedef int TipoValorAresta;
typedef int Tipor;
typedef int TipoMaxTamProx;
typedef int TipoPesoAresta;
typedef TipoValorVertice TipoArranjoVertices[MAXR];

typedef struct TipoAresta {
   TipoArranjoVertices Vertices;
   TipoPesoAresta Peso;
} TipoAresta;

typedef TipoAresta TipoArranjoArestas[MAXNUMARESTAS];

typedef struct TipoGrafo {
  TipoArranjoArestas Arestas;
  TipoValorVertice Prim[MAXNUMVERTICES];
  TipoMaxTamProx Prox[MAXTAMPROX];
  TipoMaxTamProx ProxDisponivel;
  TipoValorVertice NumVertices;
  TipoValorAresta NumArestas;
  Tipor r;
} TipoGrafo;

/*-- Tipos usados em Fila do Programa 3.17 --*/
typedef int TipoApontador;

typedef struct {
  TipoValorVertice Chave;
  /* outros componentes */
} TipoItem;

typedef struct {
  TipoItem Item[MAXTAM + 1];
  TipoApontador Frente, Tras;
} TipoFila;


typedef int TipoPesos[MAXTAMCHAVE];
typedef TipoPesos TipoTodosPesos[MAXR];
typedef char Tipog[MAXNUMVERTICES];
typedef char TipoChave[MAXTAMCHAVE];
typedef TipoChave TipoConjChaves[MAXNUMCHAVES];
typedef TipoValorVertice TipoIndice;

static TipoValorVertice M;
static TipoValorAresta N;

/*-- Entram aqui os operadores do Programa 3.18 --*/
void FFVazia(TipoFila *Fila)
{ Fila->Frente = 1;
  Fila->Tras = Fila->Frente;
}  /* FFVazia */

/* Nivio: aqui deveria ser TipoFila * ao inves de TipoFila.
 *        estou mantendo, mas fica estranho ja que fila eh
 *        um tipo abstrato.  */
int Vazia(TipoFila Fila)
{ return (Fila.Frente == Fila.Tras);
}  /* Vazia */

void Enfileira(TipoItem x, TipoFila *Fila)
{ if (Fila->Tras % MAXTAM + 1 == Fila->Frente)
  printf(" Erro   fila est  a  cheia\n");
  else
  { Fila->Item[Fila->Tras - 1] = x;
    Fila->Tras = Fila->Tras % MAXTAM + 1;
  }
}  /* Enfileira */


void Desenfileira(TipoFila *Fila, TipoItem *Item)
{ if (Vazia(*Fila))
  printf(" Erro   fila est  a  vazia\n");
  else 
  { *Item = Fila->Item[Fila->Frente - 1];
    Fila->Frente = Fila->Frente % MAXTAM + 1;
  }
}  /* Desenfileira */


/*-- Entram aqui os operadores do Programa 7.26 --*/
/* Nivio: nao faz sentido NumArestas ser um apontador. Estou transformando em uma variavel.
          Sugiro fazer o mesmo para o o programa C correspondente ao programa 7.26 para tornar
          o codigo mais claro.
*/
short ArestasIguais(TipoArranjoVertices V1, TipoValorAresta NumAresta, TipoGrafo *Grafo)
{ Tipor i, j;
  short Aux = TRUE;
  i = 0;
  while (i < Grafo->r && Aux)
  { j = 0;
    while ((V1[i] != Grafo->Arestas[NumAresta].Vertices[j]) && (j < Grafo->r)) j++; 
    if (j == Grafo->r) Aux = FALSE; 
    i++;
  }
  return Aux;
}

void FGVazio(TipoGrafo *Grafo)
{ int i;
  Grafo->ProxDisponivel = 0;
  for (i = 0; i < Grafo->NumVertices; i++) Grafo->Prim[i] = INDEFINIDO;
}

void InsereAresta(TipoAresta *Aresta, TipoGrafo *Grafo)
{ int i, Ind;
  if (Grafo->ProxDisponivel == MAXTAMPROX) 
  printf ("Nao ha espaco disponivel para a aresta\n");
  else 
  { Grafo->Arestas[Grafo->ProxDisponivel] = *Aresta;
    for (i = 0; i < Grafo->r; i++)
      { Ind = Grafo->ProxDisponivel + i * Grafo->NumArestas;
        Grafo->Prox[Ind] = Grafo->Prim[Grafo->Arestas[Grafo->ProxDisponivel].Vertices[i]];
        Grafo->Prim[Grafo->Arestas[Grafo->ProxDisponivel].Vertices[i]] = Ind;
      }
  }
  Grafo->ProxDisponivel++;
}

short ExisteAresta(TipoAresta *Aresta, TipoGrafo *Grafo)
{ Tipor v;
  TipoValorAresta A1;
  int Aux;
  short EncontrouAresta;
  EncontrouAresta = FALSE;
  for(v = 0; v < Grafo->r; v++)
    { Aux = Grafo->Prim[Aresta->Vertices[v]];
      while (Aux != INDEFINIDO && !EncontrouAresta)
        { A1 = Aux % Grafo->NumArestas;
          if (ArestasIguais(Aresta->Vertices, A1, Grafo)) EncontrouAresta = TRUE;
          Aux = Grafo->Prox[Aux];
        }
    }
  return EncontrouAresta;
}

TipoAresta RetiraAresta(TipoAresta *Aresta, TipoGrafo *Grafo)
{ int Aux, Prev, i;
  TipoValorAresta A1;
  Tipor v;
  for (v = 0; v < Grafo->r; v++)
    { Prev = INDEFINIDO;
      Aux = Grafo->Prim[Aresta->Vertices[v]];
      A1 = Aux % Grafo->NumArestas;
      while (Aux >= 0 && !ArestasIguais(Aresta->Vertices, A1, Grafo))
        { Prev = Aux;  
          Aux = Grafo->Prox[Aux];
          A1 = Aux % Grafo->NumArestas;
        }
      if (Aux >= 0)
      { if (Prev == INDEFINIDO)
        Grafo->Prim[Aresta->Vertices[v]] = Grafo->Prox[Aux];
        else Grafo->Prox[Prev] = Grafo->Prox[Aux];
      }
    }
  TipoAresta Resultado = Grafo->Arestas[A1];
  for (i = 0; i < Grafo->r; i++) Grafo->Arestas[A1].Vertices[i] = INDEFINIDO;
  Grafo->Arestas[A1].Peso = INDEFINIDO;
  return Resultado;
}

void ImprimeGrafo(TipoGrafo *Grafo)
{ int i, j;
  printf(" Arestas: Num Aresta, Vertices, Peso \n");
  for (i = 0; i < Grafo->NumArestas; i++)
    { printf ("%2d", i);
      for (j = 0; j < Grafo->r; j++) printf ("%3d", Grafo->Arestas[i].Vertices[j]);
      printf ("%3d\n", Grafo->Arestas[i].Peso);
    }
  printf ("Lista arestas incidentes a cada vertice:\n");
  for (i = 0 ; i < Grafo->NumVertices; i++)
    { printf ("%2d", i);  
      j = Grafo->Prim[i];
      while (j != INDEFINIDO)
        { printf ("%3d", j % Grafo->NumArestas);  
          j = Grafo->Prox[j];
        }
      printf("\n");
    }
}

short VerticeGrauUm (TipoValorVertice V, TipoGrafo * Grafo)
{ return ((Grafo->Prim[V] >= 0) && 
          (Grafo->Prox[Grafo->Prim[V]] == INDEFINIDO)); 
}

void GrafoAciclico (TipoGrafo * Grafo,
                    TipoArranjoArestas L,
                    short * GAciclico)
{ TipoValorVertice j; 
  TipoValorAresta A1;  
  TipoItem x;  
  TipoFila Fila; 
  TipoValorAresta NArestas;
  TipoAresta Aresta;

  NArestas = Grafo->NumArestas; 
  FFVazia (&Fila);  j = 0;
  while (j < Grafo->NumVertices)
  { if (VerticeGrauUm (j, Grafo)) 
    { x.Chave = j;  Enfileira (x, &Fila); 
    }
    j = j + 1;
  }
  while (!Vazia (Fila) && (NArestas > 0)) 
    { Desenfileira (&Fila, &x);
      if (Grafo->Prim[x.Chave] >= 0) 
      { A1 = Grafo->Prim[x.Chave] % Grafo->NumArestas;
        Aresta = RetiraAresta (&Grafo->Arestas[A1], Grafo);
        L[Grafo->NumArestas - NArestas] = Aresta;
        NArestas = NArestas - 1;
        if (NArestas > 0) 
        { for (j = 0; j < Grafo->r; j++) 
            { if (VerticeGrauUm (Aresta.Vertices[j], Grafo)) 
              { x.Chave = Aresta.Vertices[j]; 
                Enfileira (x, &Fila); 
              }
            }
        }
      }
    }
  *GAciclico = (NArestas == 0);
} /* GrafoAciclico */


/*--Operadores para obter a lista de arestas incidentes a um vertice--*/
/* Nivio: novamente um apontador esta sendo usado desnecessariamente para Vertice */
short ListaIncVazia(TipoValorVertice *Vertice, TipoGrafo *Grafo)
{ return Grafo->Prim[*Vertice] == INDEFINIDO;
}

/* Nivio: novamente um apontador esta sendo usado desnecessariamente para Vertice */
TipoApontador PrimeiroListaInc(TipoValorVertice *Vertice, TipoGrafo *Grafo)
{ return Grafo->Prim[*Vertice];
}

/* Nivio: novamente um apontador esta sendo usado desnecessariamente para Vertice e ele nao 
          eh nem usado na funcao. Isso eh para manter compatibilidade? 
*/
void ProxArestaInc(TipoValorVertice *Vertice, TipoGrafo *Grafo, 
                   TipoValorAresta *Inc, TipoPesoAresta *Peso, 
                   TipoApontador *Prox, short *FimListaInc)
{ *Inc = *Prox % Grafo->NumArestas;
  *Peso = Grafo->Arestas[*Inc].Peso;
  if (Grafo->Prox[*Prox] == INDEFINIDO) 
  *FimListaInc = TRUE;
  else *Prox = Grafo->Prox[*Prox];
}

/*---- Fim dos operadores do Programa 7.? ----*/

/*--Funcao hash universal apresentada no Programa 4.22--*/
TipoIndice h(TipoChave Chave, TipoPesos p)
{ int i; unsigned int Soma = 0; int comp = strlen(Chave);
    for (i = 0; i < comp; i++)
      Soma += (unsigned int)Chave[i] * p[i];
    return (Soma % M);
}


/*--Gera pesos para funcao h apresentado no Programa 6.X --*/
void GeraPesos(TipoPesos p)
{ int i;
  struct timeval semente;
  gettimeofday(&semente,NULL); 
  srand((int)(semente.tv_usec + 1000000*semente.tv_sec)); /* Nivio: tinha um erro aqui. Compare com o original */
  for (i = 0; i < MAXTAMCHAVE; i++)
    p[i] =  rand(); /* nivio: funcao nao funciona bem em em c e por isso tive que altera-la para funcionar com os exemplos. */
} 

void Atribuig (TipoGrafo *Grafo,
               TipoArranjoArestas L,
               Tipog g)
{ int i, j, u, Soma;
  TipoValorVertice v; 
  TipoAresta a;
  unsigned char Visitado[MAXNUMVERTICES];
  for (i = Grafo->NumVertices - 1; i >= 0; i--)  
    { g[i] = Grafo->r; Visitado[i] = FALSE; }
  for (i = Grafo->NumArestas - 1; i >= 0; i--) 
    { a = L[i];  Soma = 0;
      for (v = Grafo->r - 1; v >= 0; v--) 
        { if (!Visitado[a.Vertices[v]]) 
          { Visitado[a.Vertices[v]] = TRUE;
            u = a.Vertices[v]; j = v;
          } 
          else Soma += g[a.Vertices[v]];
        }
      g[u] = (j - Soma) % Grafo->r;
      while (g[u] < 0) g[u] += Grafo->r;
    } 
}

void GeraGrafo (TipoConjChaves  ConjChaves,
                TipoValorAresta  N,
                TipoValorVertice M,
                Tipor            r,
                TipoTodosPesos   Pesos,
                int *NGrafosGerados,
                TipoGrafo       *Grafo) 
{ /*--GeraGrafo--*/
    /* Gera um grafo sem arestas repetidas e sem self-loops */
    int i, j;
    TipoAresta  Aresta;
    int  GrafoValido;
    inline int  VerticesIguais (TipoAresta *Aresta) 
    { int i, j;
      for (i = 0; i < Grafo->r - 1; i++) 
      {
        for (j = i + 1; j < Grafo->r; j++) {
              if (Aresta->Vertices[i] == Aresta->Vertices[j])
                  return TRUE;
          }
      }
      return FALSE;
    }
    do { 
        GrafoValido = TRUE;
        Grafo->NumVertices = M;
        Grafo->NumArestas = N;  
        Grafo->r = r;
        FGVazio (Grafo);         
        *NGrafosGerados = 0;
        for (j = 0; j < Grafo->r; j++) GeraPesos (Pesos[j]); 
        for (i = 0; i < Grafo->NumArestas; i++) 
          { Aresta.Peso = i;
            for (j = 0; j < Grafo->r; j++) 
              Aresta.Vertices[j] = h (ConjChaves[i], Pesos[j]);
            if (VerticesIguais (&Aresta) || ExisteAresta (&Aresta, Grafo)) 
            { GrafoValido = FALSE;
              break;  
            }
            else InsereAresta (&Aresta, Grafo);
          }
        ++(*NGrafosGerados);
    } while(!GrafoValido);
} /* Fim GeraGrafo */

static void Ignore(FILE *Arq, char Delim) 
{ int c = fgetc(Arq);
  while(c != Delim && c != EOF) c = fgetc(Arq);
}

int main()
{ Tipor r; TipoGrafo Grafo;
  TipoArranjoArestas L; short GAciclico;
  Tipog g; TipoTodosPesos Pesos;
  int i, j; int NGrafosGerados;
  TipoConjChaves ConjChaves;  
  FILE *ArqEntrada; FILE *ArqSaida;
  char NomeArq[100];

  printf ("Nome do arquivo com chaves a serem lidas: ");
  scanf("%s*[^\n]", NomeArq);
  printf("NomeArq = %s\n", NomeArq);
  ArqEntrada = fopen(NomeArq, "r");

  printf ("Nome do arquivo para gravar experimento: ");
  scanf("%s*[^\n]", NomeArq);
  printf("NomeArq = %s\n", NomeArq);
  ArqSaida = fopen(NomeArq, "w");

  NGrafosGerados = 0;  
  i = 0;

  fscanf(ArqEntrada, "%d %d %d*[^\n]", &N, &M, &r); Ignore(ArqEntrada, '\n'); 
  printf("N=%d, M=%d, r=%d\n", N, M, r);

  while ((i < N) && (!feof(ArqEntrada))) 
    { fscanf(ArqEntrada,"%s*[^\n]", ConjChaves[i]); Ignore(ArqEntrada, '\n');
      printf("Chave[%d]=%s\n", i, ConjChaves[i]);
      i++;  
    }
  if (i !=  N) 
  { printf("Erro: entrada com menos do que ', N, ' elementos.\n");
    exit(-1);
  }
  do 
    { GeraGrafo (ConjChaves, N, M, r, Pesos, &NGrafosGerados, &Grafo); 
      ImprimeGrafo (&Grafo);
      /*--Imprime estrutura de dados--*/
      printf ("prim: "); 
      for (i = 0; i < Grafo.NumVertices; i++)  
          printf("%3d ", Grafo.Prim[i]); 
      printf("\n");
  
      printf ("prox: "); 
      for (i = 0; i < Grafo.NumArestas * Grafo.r; i++)  
          printf("%3d ", Grafo.Prox[i]); 
      printf("\n");
  
      GrafoAciclico (&Grafo, L, &GAciclico);
    } while (!GAciclico);

  printf ("Grafo aciclico com arestas retiradas:");
  for(i = 0; i < Grafo.NumArestas; i++) printf("%3d ", L[i].Peso);
  printf("\n");

  Atribuig (&Grafo, L, g); 
  fprintf(ArqSaida, "%d  (N)\n", N);
  fprintf(ArqSaida, "%d  (M)\n", M);
  fprintf(ArqSaida, "%d  (r)\n", r);

  for (j = 0; j < Grafo.r; j++) 
  { for (i = 0; i < MAXTAMCHAVE; i++) fprintf(ArqSaida, "%d ", Pesos[j][i]); 
    for (i = 0; i < MAXTAMCHAVE; i++) printf("%d ", Pesos[j][i]); 
    fprintf(ArqSaida, "  (p%d)\n", j); 
    printf("  (p%d)\n", j);
  } 
  for (i = 0; i < M; i++) fprintf(ArqSaida, "%d ", g[i]); 
  for (i = 0; i < M; i++) printf("%d ", g[i]); 
  fprintf(ArqSaida, "  (g)\n");  
  printf("  (g)\n");  
  fprintf(ArqSaida, "No. grafos gerados por GeraGrafo:%d\n", NGrafosGerados);
  printf("No. grafos gerados por GeraGrafo:%d\n", NGrafosGerados);
  fclose (ArqSaida);
  fclose (ArqEntrada);
  return 0;
}
