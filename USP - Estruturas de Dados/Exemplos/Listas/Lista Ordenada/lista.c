// TAD lista ordenada
#include "lista.h"

struct bloco {
        elem info;
        struct bloco *prox;
};


void cria(ListaOrd *L) {
     L->inicio=NULL;
}

void finaliza(ListaOrd *L) {
     no *p;
     p=L->inicio;
     while (p!=NULL) {
           L->inicio=L->inicio->prox;
           free(p);
           p=L->inicio;
     }
}

void inserir(ListaOrd *L, elem *x, int *erro) {
     no *atual, *ant, *p;
     
     p=(no*) malloc(sizeof(no));
     if (p==NULL)
        *erro=1;
     else {
          *erro=0;
          p->info=*x;
          if ((L->inicio==NULL) || (*x<L->inicio->info)) {
             p->prox=L->inicio;
             L->inicio=p;
          }
          else {
               ant=NULL;
               atual=L->inicio;
               while ((atual!=NULL) && (atual->info<=*x)) {
                     ant=atual;
                     atual=atual->prox;
               }
               p->prox=atual;
               ant->prox=p;
          }
     }
             
     return;
}

void remover(ListaOrd *L, elem *x, int *erro) {
     no *p, *ant;     
     if ((L->inicio==NULL) || (*x<L->inicio->info))
        *erro=1;
     else if (*x==L->inicio->info) {
          *erro=0;
          p=L->inicio;
          L->inicio=L->inicio->prox;
          free(p);
     }
     else {
          ant=NULL;
          p=L->inicio;
          while ((p!=NULL) && (p->info<*x)) {
                ant=p;
                p=p->prox;
          }
          if ((p!=NULL) && (p->info==*x)) {
             *erro=0;
             ant->prox=p->prox;
             free(p);
          }
          else *erro=1;
     }     
     return;
}

int esta_na_lista(ListaOrd *L, elem *x) {
    no *p;
     
    p=L->inicio;
    while ((p!=NULL) && (p->info<*x)) {
          p=p->prox;
    }
    
    if ((p!=NULL) && (p->info==*x)) return 1;
    else return 0;
}

void imprimir(ListaOrd *L) {
     no *p;
     
     p=L->inicio;
     while (p!=NULL) {
           printf("%d ",p->info);
           p=p->prox;
     }
     
     return;
}
