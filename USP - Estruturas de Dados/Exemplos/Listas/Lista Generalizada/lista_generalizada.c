#include <stdio.h>
#include "lista_generalizada.h"

int esta_na_lista_principal(ListaGen *L, elem *x) {
    no *p;
    p=L->ini;
    while (p!=NULL) {
          if ((p->tipo==0) && (p->info.atomo==*x))
             return(1);
          else p=p->prox;
    }
    return(0);
}

int esta_em_qualquer_parte_da_lista(no *p, elem *x) {
    if (p==NULL)
       return 0;
    else if (p->tipo==0) {
         if (p->info.atomo==*x)
            return 1;
         else return(esta_em_qualquer_parte_da_lista(p->prox,x));
    }
    else if (p->tipo==1) {
         if (esta_em_qualquer_parte_da_lista(p->info.sublista,x))
            return 1;
         else return(esta_em_qualquer_parte_da_lista(p->prox,x));
    }
}

int iguais(no *L1, no *L2) {
    if ((L1==NULL) && (L2==NULL))
       return 1;
    else if ((L1==NULL) || (L2==NULL))
         return 0;
    else if ((L1->tipo==L2->tipo==0) && (L1->info.atomo==L2->info.atomo))
         return(iguais(L1->prox,L2->prox));
    else if ((L1->tipo==L2->tipo==1) && (iguais(L1->info.sublista,L2->info.sublista)))
         return(iguais(L1->prox,L2->prox));
    else return 0;
}

int iguais_estruturalmente(no *L1, no *L2) {
    if ((L1==NULL) && (L2==NULL))
       return 1;
    else if ((L1==NULL) || (L2==NULL))
         return 0;
    else if (L1->tipo==L2->tipo==0)
         return(iguais_estruturalmente(L1->prox,L2->prox));
    else if ((L1->tipo==L2->tipo==1) && (iguais_estruturalmente(L1->info.sublista,L2->info.sublista)))
         return(iguais_estruturalmente(L1->prox,L2->prox));
    else return 0;
}

int profundidade(no *p) {
    int prof, aux;
        
    if (p==NULL)
       prof=0;
    else if (p->tipo==0) {
         prof=1;
         aux=profundidade(p->prox);
         if (aux>prof)
            prof=aux;
    }
    else if (p->tipo==1) {
         prof=1+profundidade(p->info.sublista);
         aux=profundidade(p->prox);
         if (aux>prof)
            prof=aux;
    }    
    return(prof);
}
