#include "banco de memoria.h"

void cria(Banco *B) {
     int i;
     for (i=0;i<TAM-1;i++)
         B->itens[i].prox=i+1;
     B->itens[TAM-1].prox=-1;
     B->primeiro_vazio=0;
     B->ini=-1;
     B->fim=-1;
}

void getnode(Banco *B, int *pos) {
    if (B->primeiro_vazio!=-1) {
       *pos=B->primeiro_vazio;
       B->primeiro_vazio=B->itens[B->primeiro_vazio].prox;
       B->itens[*pos].prox=-1;
    }
    else *pos=-1;
}

void freenode(Banco *B, int *pos) {
    B->itens[*pos].prox=B->primeiro_vazio;
    B->primeiro_vazio=*pos;
}

int EstaVazio(Banco *B) {
    if (B->ini==-1)
       return(1);
    else return(0);
}

int EstaCheio(Banco *B) {
    if (B->primeiro_vazio==-1)
       return(1);
    else return(0);
}

void inserir_no_comeco(Banco *B, elem *x, int *erro) {
     int pos;
     if (EstaCheio(B))
        *erro=1;
     else {
          *erro=0;
          getnode(B,&pos);
          B->itens[pos].info=*x;
          B->itens[pos].prox=B->ini;
          B->ini=pos;
          if (B->fim==-1)
             B->fim=pos;
     }
}

void retirar_do_comeco(Banco *B, elem *x, int *erro) {
     int pos;
     if (EstaVazio(B))
        *erro=1;
     else {
          *erro=0;
          *x=B->itens[B->ini].info;
          pos=B->ini;
          B->ini=B->itens[B->ini].prox;
          if (B->ini==-1)
             B->fim=-1;
          freenode(B,&pos);
     }
}

void inserir_no_fim(Banco *B, elem *x, int *erro) {
     int pos;
     if (EstaCheio(B))
        *erro=1;
     else {
          *erro=0;
          getnode(B,&pos);
          B->itens[pos].info=*x;
          B->itens[pos].prox=-1;
          if (B->fim!=-1)
             B->itens[B->fim].prox=pos;
          B->fim=pos;
          if (B->ini==-1)
             B->ini=pos;
     }
}
