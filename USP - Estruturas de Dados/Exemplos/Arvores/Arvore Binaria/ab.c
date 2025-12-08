#include <stdlib.h>
#include <stdio.h>
#include "ab.h"

//inicializa a árvore, fazendo a raiz igual a NULL
void cria(Arvore *A) {
     A->raiz=NULL;
}

//verifica se a árvore está vazia
int IsEmpty(Arvore *A) {
    if (A->raiz==NULL)
       return 1;
    else return 0;
}

//busca x na árvore, devendo iniciar com p=raiz ou outro ponto da árvore
no* busca(no *p, elem *x) {
    no *aux;
    
    if (p==NULL)
       return(NULL);
    else if (p->info==*x)
         return(p);
    else {
         aux=busca(p->esq,x);
         if (aux==NULL)
            aux=busca(p->dir,x);
         return(aux);
    }    
}

//busca pai de x na árvore, devendo iniciar com p=raiz ou outro ponto da árvore
no* busca_pai(no *p, elem *x) {
    no *aux;
    
    if (p==NULL)
       return(NULL);
    else if ((p->esq!=NULL) && (p->esq->info==*x))
         return(p);
    else if ((p->dir!=NULL) && (p->dir->info==*x))
         return(p);
    else {
         aux=busca_pai(p->esq,x);
         if (aux==NULL)
            aux=busca_pai(p->dir,x);
         return(aux);
    }
}

//se possível, insere x à esquerda de pai na árvore
//se pai=-1, insere na raiz
void inserir_esq(Arvore *A, elem *x, elem *pai, int *erro) {
     no *aux, *p;

     if (*pai!=-1) {
        aux=busca(A->raiz,pai);
        if ((aux!=NULL) && (aux->esq==NULL)) {
           p=(no*) malloc(sizeof(no));
           p->info=*x;
           p->esq=NULL;
           p->dir=NULL;
           aux->esq=p;
           *erro=0;
        }
        else *erro=1;
     }
     else if (A->raiz==NULL) {
          p=(no*) malloc(sizeof(no));
          p->info=*x;
          p->esq=NULL;
          p->dir=NULL;
          A->raiz=p;
          *erro=0;
     }
     else *erro=1;
}

//se possível, insere x à direita de pai na árvore
//se pai=-1, insere na raiz
void inserir_dir(Arvore *A, elem *x, elem *pai, int *erro) {
     no *aux, *p;
          
     if (*pai!=-1) {
        aux=busca(A->raiz,pai);
        if ((aux!=NULL) && (aux->dir==NULL)) {
           p=(no*) malloc(sizeof(no));
           p->info=*x;
           p->esq=NULL;
           p->dir=NULL;
           aux->dir=p;
           *erro=0;
        }
        else *erro=1;
     }
     else if (A->raiz==NULL) {
          p=(no*) malloc(sizeof(no));
          p->info=*x;
          p->esq=NULL;
          p->dir=NULL;
          A->raiz=p;
          *erro=0;
     }
     else *erro=1;
}

//imprime os elementos da árvore
void imprimir(no *p) {
     if (p!=NULL) {
        printf("%d(",p->info);
        imprimir(p->esq);
        printf(",");
        imprimir(p->dir);
        printf(")");
     }
     else printf("null");
}

//função para computar a altura de uma árvore binária; devo começar com p
//apontando para a raiz
int altura(no *p) {
    int alt_esq, alt_dir;

    if (p==NULL)
       return(0);
    else {
         alt_esq=1+altura(p->esq);
         alt_dir=1+altura(p->dir);
         if (alt_esq>alt_dir)
            return(alt_esq);
         else return(alt_dir);
    }
}

//libera toda a memória usada na árvore
void finaliza(no *p) {
     if (p!=NULL) {
        finaliza(p->esq);
        finaliza(p->dir);
        free(p);
     }
}

//função que remove um elemento da árvore, caso ele esteja nela
void remover(Arvore *A, elem *x, int *erro) {
     no *filho, *pai;
     int eh_filho_esq;
     
     //localizando o nó e o pai dele
     if ((A->raiz!=NULL) && (A->raiz->info==*x)) {
        pai=NULL;
        filho=A->raiz;
     }
     else {
          pai=busca_pai(A->raiz,x);
          if (pai!=NULL) {
             if ((pai->esq!=NULL) && (pai->esq->info==*x)) {
                filho=pai->esq;
                eh_filho_esq=1;
             }
             else {
                  filho=pai->dir;
                  eh_filho_esq=0;
             }
          }
          else filho=NULL;
     }
     
     if (filho==NULL)
        *erro=1;
     else {
          //primeiro caso: o nó não tem filhos
          if ((filho->esq==NULL) && (filho->dir==NULL)) {
             if (pai!=NULL) {
                if (eh_filho_esq)
                   pai->esq=NULL;
                else pai->dir=NULL;
             }
             else A->raiz=NULL;
             free(filho);
             *erro=0;
          }
          //segundo caso: o nó tem um ou dois filhos
          else {
               if (filho->esq!=NULL) {
                  filho->info=filho->esq->info;
                  filho->esq->info=*x;
               }
               else {
                    filho->info=filho->dir->info;
                    filho->dir->info=*x;
               }
               remover(A,x,erro);
          }
     }
}

//função de percurso de pre-ordem na árvore = busca em profundidade
void percurso_pre_ordem(no *p) {
     if (p!=NULL) {
        printf("%d\n",p->info);
        percurso_pre_ordem(p->esq);
        percurso_pre_ordem(p->dir);
     }
}

//função de percurso de em-ordem na árvore
void percurso_em_ordem(no *p) {
     if (p!=NULL) {
        percurso_em_ordem(p->esq);
        printf("%d\n",p->info);        
        percurso_em_ordem(p->dir);
     }
}

//função de percurso de pos-ordem na árvore
void percurso_pos_ordem(no *p) {
     if (p!=NULL) {
        percurso_pos_ordem(p->esq);
        percurso_pos_ordem(p->dir);
        printf("%d\n",p->info);        
     }
}

//função que verifica se duas árvores são espelho-similares
int espelho_similares(no *p1, no *p2) {
    if ((p1==NULL) && (p2==NULL))
         return(1);
    else if ((p1==NULL) || (p2==NULL))
         return(0);
    else if ((espelho_similares(p1->esq,p2->dir)) && (espelho_similares(p1->dir,p2->esq)))
         return(1);
    else return(0);
}











