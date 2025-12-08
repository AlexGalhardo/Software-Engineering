#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <sys/time.h>

#define MAX  10

typedef long TipoChave;
typedef struct TipoRegistro {
  TipoChave Chave;
  /* outros componentes */
} TipoRegistro;
typedef struct TipoNo * TipoApontador;
typedef struct TipoNo {
  TipoRegistro Reg;
  TipoApontador Esq, Dir;
} TipoNo;
typedef TipoApontador TipoDicionario;

void Pesquisa(TipoRegistro *x, TipoApontador *p)
{ if (*p == NULL) 
  { printf("Erro: Registro nao esta presente na arvore\n");
    return;
  }
  if (x->Chave < (*p)->Reg.Chave) 
  { Pesquisa(x, &(*p)->Esq);
    return;
  }
  if (x->Chave > (*p)->Reg.Chave)
  Pesquisa(x, &(*p)->Dir);
  else *x = (*p)->Reg;
} 

void Insere(TipoRegistro x, TipoApontador *p)
{ if (*p == NULL) 
  { *p = (TipoApontador)malloc(sizeof(TipoNo));
    (*p)->Reg = x; 
    (*p)->Esq = NULL; 
    (*p)->Dir = NULL;
    return;
  }
  if (x.Chave < (*p)->Reg.Chave) 
  { Insere(x, &(*p)->Esq); 
    return; 
  }
  if (x.Chave > (*p)->Reg.Chave)
  Insere(x, &(*p)->Dir);
  else printf("Erro : Registro ja existe na arvore\n");
} 

void Inicializa(TipoApontador *Dicionario)
{ *Dicionario = NULL; }

void Antecessor(TipoApontador q, TipoApontador *r)
{ if ((*r)->Dir != NULL) 
  { Antecessor(q, &(*r)->Dir);
    return;
  }
  q->Reg = (*r)->Reg;
  q = *r; 
  *r = (*r)->Esq;
  free(q);
} 

void Retira(TipoRegistro x, TipoApontador *p)
{  TipoApontador Aux;
  if (*p == NULL) 
  { printf("Erro : Registro nao esta na arvore\n");
    return;
  }
  if (x.Chave < (*p)->Reg.Chave) { Retira(x, &(*p)->Esq); return; }
  if (x.Chave > (*p)->Reg.Chave) { Retira(x, &(*p)->Dir); return; }
  if ((*p)->Dir == NULL) 
  { Aux = *p;  *p = (*p)->Esq;
    free(Aux);
    return;
  }
  if ((*p)->Esq != NULL) 
  { Antecessor(*p, &(*p)->Esq);
    return;
  }
  Aux = *p;  *p = (*p)->Dir;
  free(Aux);
}  

void Central(TipoApontador p)
{ if (p == NULL) return;
  Central(p->Esq);
  printf("%ld\n", p->Reg.Chave);
  Central(p->Dir);
} 

void TestaI(TipoNo *p, int pai)
{ if (p == NULL) return;
  if (p->Esq != NULL) 
  { if (p->Reg.Chave < p->Esq->Reg.Chave) 
    { printf("Erro: Pai %ld menor que filho a esquerda %ld\n", p->Reg.Chave, 
             p->Esq->Reg.Chave);
      exit(1);
    }
  }
  if (p->Dir != NULL) 
  { if (p->Reg.Chave > p->Dir->Reg.Chave) 
    { printf("Erro: Pai %ld maior que filho a direita %ld\n",  p->Reg.Chave, 
             p->Dir->Reg.Chave);
    exit(1);
    }
  }
  TestaI(p->Esq, p->Reg.Chave);
  TestaI(p->Dir, p->Reg.Chave);
}


void Testa(TipoNo *p)
{ if (p != NULL)
  TestaI(p, p->Reg.Chave);
}

double rand0a1() {
  double resultado=  (double) rand()/ RAND_MAX; /* Dividir pelo maior inteiro */
  if(resultado>1.0) resultado = 1.0;
  return resultado;
}

void Permut( TipoChave A[], int n) {
  int i,j; TipoChave b;
  for(i = n; i>0; i --) 
    { j = (i * rand0a1());
      b = A[i];
      A[i] = A[j];
      A[j] = b;
    }
}

int main(int argc, char *argv[])
{
  struct timeval t; TipoNo *Dicionario;
  TipoRegistro x; TipoChave vetor[MAX];
  int i, j, k, n;

  Inicializa(&Dicionario);
  /* Gera uma permutação aleatoria de chaves entre 1 e MAX */
  for (i = 0; i < MAX; i++) vetor[i] = i+1;
  gettimeofday(&t,NULL);
  srand((unsigned int)t.tv_usec);
  Permut(vetor,MAX-1);
  
  /* Insere cada chave na arvore e testa sua integridade apos cada insercao */
  for (i = 0; i < MAX; i++) 
    { x.Chave = vetor[i];
      Insere(x, &Dicionario);
      printf("Inseriu chave: %d\n", x.Chave);
     Testa(Dicionario);
    }

  /* Retira uma chave aleatoriamente e realiza varias pesquisas */
  for (i = 0; i <= MAX; i++) 
    { k = (int) (10.0*rand()/(RAND_MAX+1.0));
      n = vetor[k];
      x.Chave = n;
      Retira(x, &Dicionario);
      Testa(Dicionario);
      printf("Retirou chave: %ld\n", x.Chave);
      for (j = 0; j < MAX; j++) 
        { x.Chave = vetor[(int) (10.0*rand()/(RAND_MAX+1.0))];
          if (x.Chave != n) 
          { printf("Pesquisando chave: %ld\n", x.Chave);
            Pesquisa(&x, &Dicionario);
          }
        }
      x.Chave = n;
      Insere(x, &Dicionario);
      printf("Inseriu chave: %ld\n", x.Chave);
      Testa(Dicionario);
    }

  /* Retira a raiz da arvore ate que ela fique vazia */
  for (i = 0; i < MAX; i++) 
    { x.Chave = Dicionario->Reg.Chave;
      Retira(x, &Dicionario);
      Testa(Dicionario);
      printf("Retirou chave: %ld\n", x.Chave);
    }
  return 0;
} 