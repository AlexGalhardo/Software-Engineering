#include <stdio.h>
#include "AVL.h"

//função para criar/inicializar a AVL
void criar(AVL *A) {
     A->raiz=NULL;
}

//função para finalizar a AVL; deve começar com p=raiz
void finalizar(no **p) {
     if (*p!=NULL) {
        finalizar(&(*p)->esq);
        finalizar(&(*p)->dir);
        free(*p);
     }     
}

//imprime os elementos da árvore
void imprimir(no **p) {
     if (*p!=NULL) {
        printf("%d/%d(",(*p)->info,(*p)->fb);
        imprimir(&(*p)->esq);
        printf(",");
        imprimir(&(*p)->dir);
        printf(")");
     }
     else printf("=");
}

//função de busca de um elemento na AVL; deve começar com p=raiz
int buscar(no **p, int *x) {
    if (*p==NULL)
       return 0;
    else if (*x<(*p)->info)
         return(buscar(&(*p)->esq,x));
    else if (*x>(*p)->info)
         return(buscar(&(*p)->dir,x));
    else return 1;
}

//funções para inserção de um elemento na AVL
//a variável "cresceu" indica se a árvore cresceu após a inserção
void EE(no **r) {
     no *pai=*r;
     no *filho=pai->esq;
     pai->esq=filho->dir;
     filho->dir=pai;
     pai->fb=0;
     filho->fb=0;
     *r=filho;
}

void DD(no **r) {
     no *pai=*r;
     no *filho=pai->dir;
     pai->dir=filho->esq;
     filho->esq=pai;
     pai->fb=0;
     filho->fb=0;
     *r=filho;
}

void ED(no **r) {
     no *pai=*r;
     no *filho=pai->esq;
     no *neto=filho->dir;
     pai->esq=neto->dir;
     filho->dir=neto->esq;
     neto->esq=filho;
     neto->dir=pai;
     switch (neto->fb) {
            case -1:
                 pai->fb=1;
                 filho->fb=0;
                 break;
            case 0:
                 pai->fb=0;
                 filho->fb=0;
                 break;
            case 1:
                 pai->fb=0;
                 filho->fb=-1;
                 break;
     }
     neto->fb=0;
     *r=neto;
}

void DE(no **r) {
     no *pai=*r;
     no *filho=pai->dir;
     no *neto=filho->esq;
     filho->esq=neto->dir;
     pai->dir=neto->esq;
     neto->esq=pai;
     neto->dir=filho;
     switch (neto->fb) {
            case -1:
                 pai->fb=0;
                 filho->fb=1;
                 break;
            case 0:
                 pai->fb=0;
                 filho->fb=0;
                 break;
            case 1:
                 pai->fb=-1;
                 filho->fb=0;
                 break;
     }
     neto->fb=0;
     *r=neto;
}

int aux_insere(no **p, int *x, int *cresceu) {
    if (*p==NULL) {
       *p=(no*) malloc(sizeof(no));
       (*p)->info=*x;
       (*p)->fb=0;
       (*p)->esq=NULL;
       (*p)->dir=NULL;
       *cresceu=1;
       return 1;
    }
    else if (*x==(*p)->info)
         return 0;
    else if (*x<(*p)->info) {
         if (aux_insere(&(*p)->esq,x,cresceu)) {
            if (*cresceu) {
	           switch ((*p)->fb) {
	                  case -1:
	                       if ((*p)->esq->fb==-1)
	                          EE(p);
                           else ED(p);
	                       *cresceu=0;
	                       break;
	                  case 0:
	                       (*p)->fb=-1;
	                       *cresceu=1;
	                       break;
                      case 1:
	                       (*p)->fb=0;
	                       *cresceu=0;
	                       break;
               }
            }
            return 1;
         }
         else return 0;
    }
    else {
         if (aux_insere(&(*p)->dir,x,cresceu)) {
            if (*cresceu) {
	           switch ((*p)->fb) {
	                  case -1:
	                       (*p)->fb=0;
                           *cresceu=0;
	                       break;
                      case 0:
	                       (*p)->fb=1;
	                       *cresceu=1;
	                       break;
                      case 1:
	                       if ((*p)->dir->fb==1)
	                          DD(p);
                           else DE(p);
	                       *cresceu=0;
	                       break;
               }
            }
            return 1;
         }
         else return 0;
    }
}

int inserir(no **p, int *x) {
  int cresceu;
  return aux_insere(p, x, &cresceu);
}
