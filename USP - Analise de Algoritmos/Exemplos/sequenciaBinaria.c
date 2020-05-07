#include <limits.h>
#include <stdlib.h>
#include <sys/time.h>
#include <stdio.h>

#define MAXN 10

typedef long TipoChave;

typedef struct TipoRegistro {
  TipoChave Chave;
  /* outros componentes */
} TipoRegistro;

typedef int TipoIndice;

typedef struct TipoTabela {
  TipoRegistro Item[MAXN + 1];
  TipoIndice n;
} TipoTabela;

void Inicializa(TipoTabela *T)
{ T->n = 0; }

TipoIndice Pesquisa(TipoChave x, TipoTabela *T)
{ int i;
  T->Item[0].Chave = x;  i = T->n + 1;
  do {i--;}  while (T->Item[i].Chave != x);
  return i;
} 

void Insere(TipoRegistro Reg, TipoTabela *T)
{ if (T->n == MAXN) 
  printf("Erro : tabela cheia\n");
  else { T->n++; T->Item[T->n] = Reg; }
}

TipoIndice Binaria(TipoChave x, TipoTabela *T)
{ TipoIndice i, Esq, Dir;
  if (T->n == 0) 
  return 0;
  else 
  { Esq = 1;
    Dir = T->n;
    do 
      { i = (Esq + Dir) / 2;
        if (x > T->Item[i].Chave) 
        Esq = i + 1;
        else Dir = i - 1;
      } while (x != T->Item[i].Chave && Esq <= Dir);
    if (x == T->Item[i].Chave) return i; else return 0;
  }
} 

double rand0a1() { double resultado = (double) rand() / INT_MAX; /* Dividir pelo maior inteiro */
  if(resultado > 1.0) resultado = 1.0;
  return resultado;
}

void Permut( TipoChave *A, int n) { int i,j;
  TipoChave b;
  for(i = n; i > 0; i --) {
    j = (i * rand0a1()) + 1; b = A[i];
    A[i] = A[j]; A[j] = b;
  }
}

int main(int argc, char *argv[]) { struct timeval t;
  TipoTabela T;
  TipoRegistro reg;
  TipoChave vetor[MAXN+1];
  TipoIndice pos;
  int  i;
  Inicializa(&T);
  /* Pesquisa na TipoTabela Vazia */
  printf("Pesquisa Binaria na tabela vazia\n");
  pos = Binaria(1, &T);
  if (pos != 0) 
  { printf("Pesquisa Falhou\n");
    return 0;
  }
  printf("Pesquisa Sequencial na tabela vazia\n");
  pos = Pesquisa(1, &T);
  if (pos != 0) 
  { printf("Pesquisa Falhou\n");
    return 0;
  }
  /* Insere as chaves ordenas tabela */
  for (i = 1; i <= MAXN; i++) 
    { vetor[i] = i; reg.Chave = vetor[i];
      Insere(reg, &T);
      printf("Inseriu: %ld\n", vetor[i]);
    }
  /* Pesquisa Binaria em cada chave */
  printf("Pesquisa Binaria (chaves ordenadas)\n");
  for (i = 1; i <= MAXN; i++) {
    pos = Binaria(i, &T);
    if (pos == 0) 
    { printf("Pesquisa Falhou\n");
      return 0;
    }
    printf("TipoRegistro %d na posicao: %d\n", i, pos);
  }
  /* Permuta as chaves */
  gettimeofday(&t,NULL);
  srand((unsigned int)t.tv_usec);
  Permut (vetor,MAXN);
  /* Insere as chaves na tabela */
  Inicializa(&T);
  for (i = 1; i < MAXN + 1; i++) 
    { reg.Chave = vetor[i]; Insere(reg, &T);
      printf("Inseriu: %ld\n",vetor[i]);
    }
  /* Pesquisa Sequencial em cada chave */
  printf("Pesquisa Sequencial (chaves desordenadas)\n");
  for (i = 1; i <= MAXN; i++) 
    { reg.Chave = i; pos = Pesquisa(reg.Chave, &T);
      if (pos == 0) 
      { printf("Pesquisa Falhou\n");
        return 0;
      }
      printf("Registro %d na posicao: %d\n", i, pos);
    }
  return 0;
} 