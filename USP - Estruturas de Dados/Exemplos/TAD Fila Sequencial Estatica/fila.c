#include "fila.h"

void Cria(Fila *F) {
     F->inicio=0;
     F->fim=0;
     F->total=0;
     return;
}

void Esvazia(Fila *F) {
     F->inicio=0;
     F->fim=0;
     F->total=0;
     return;
}

int EstaVazia(Fila *F) {
    if (F->total==0)
       return 1;
    else return 0;
}

int EstaCheia(Fila *F) {
    if (F->total==TamFila)
       return 1;
    else return 0;
}

void Entra(Fila *F, elem *X, int *erro) {
     if (!EstaCheia(F)) {
          *erro=0;
          F->total++;
          F->itens[F->fim]=*X;
          if (F->fim==TamFila-1) F->fim=0;
          else F->fim++;
     }
     else *erro=1;
     return;
}

void Sai(Fila *F, elem *X, int *erro) {
     if (!EstaVazia(F)) {
          *erro=0;
          F->total--;
          *X=F->itens[F->inicio];
          if (F->inicio==TamFila-1) F->inicio=0;
          else F->inicio++;
     }
     else *erro=1;
     return;
}

//função que verifica se os elementos de uma pilha estão em ordem crescente
int Crescente(Fila *F) {
    elem primeiro, seguinte;
    int i, erro, teste_crescente;

    teste_crescente=1;

    if (!EstaVazia(F)) {
        i=F->total-1;

        Sai(F,&primeiro,&erro);
        Entra(F,&primeiro,&erro);
        while (i>0) {
            Sai(F,&seguinte,&erro);
            Entra(F,&seguinte,&erro);
            i--;
            if (primeiro>seguinte)
                teste_crescente=0;
            primeiro=seguinte;
        }
    }

    return(teste_crescente);
}

//função que retorna o primeiro da fila, sem retira-lo da fila
elem Primeiro(Fila *F, int *erro) {
     if (!EstaVazia(F)) {
        *erro=0;
        return(F->itens[F->inicio]);
     }
     else *erro=1;
     return;
}

//função que une duas filas ordenadas em uma terceira
void Unir(Fila *F1, Fila *F2, Fila *F3, int *erro) {
     elem x, y;
     int erro_local;
     int total_f1, total_f2;

     if (F1->total+F2->total>TamFila)
        *erro=1;

     else {
        *erro=0;
        total_f1=F1->total;
        total_f2=F2->total;

        while ((total_f1>0) && (total_f2>0)) {
              x=Primeiro(F1,&erro_local);
              y=Primeiro(F2,&erro_local);
              if (x<y) {
                 Entra(F3,&x,&erro_local);
                 Sai(F1,&x,&erro_local);
                 Entra(F1,&x,&erro_local);
                 total_f1--;
              }
              else {
                 Entra(F3,&y,&erro_local);
                 Sai(F2,&y,&erro_local);
                 Entra(F2,&y,&erro_local);
                 total_f2--;
              }
        }

        if (total_f1>0)
           while (total_f1>0) {
                 Sai(F1,&x,&erro_local);
                 Entra(F1,&x,&erro_local);
                 Entra(F3,&x,&erro_local);
                 total_f1--;
           }
        if (total_f2>0)
           while (total_f2>0) {
                 Sai(F2,&y,&erro_local);
                 Entra(F2,&y,&erro_local);
                 Entra(F3,&y,&erro_local);
                 total_f2--;
           }

     }

}
