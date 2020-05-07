/* PROGRAMA SIMPLES SOBRE LISTAS GENERALIZADAS */

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(void) {

    LISTA *lista;
    int erro;

    lista = cria(&erro);

    int qtd;
    printf("\n\n\t Digite a quantidade de elementos que vao ser inseridos: ");
    scanf("%d", &qtd);

    int i, valor = 0, tipo, adicionado, tipoUm=0, tipoDois=0, adicionarOnde;

    printf("\n\n\t DIGITE [1] para adicionar no na lista principal\n");
    printf("\t DIGITE [2] para adicionar no modo SUBLISTA\n");
    printf("\t DIGITE [3] para adicionar na SUBLISTA\n");

    for(i=0; i<qtd; i++){
      printf("\n\t Digite o valor e o onde vai ser inserido: ");
      scanf("%d %d %d", &valor, &tipo, &adicionarOnde);
      while( tipo < 1 || tipo > 2){
        printf("\t Digite onde vai ser inserido: ");
        scanf("%d", &tipo);
      }
      /* verifica quantidade de tipos dentro da lista generalizada */
      if ( tipo == 1 ){
        tipoUm++;
      }
      if ( tipo == 2 ){
        tipoDois++;
      }

      push(lista, valor, &erro, tipo, adicionarOnde);
    }

    printf("\n\t Digite [1] --> Printar dados da lista principal\n");
    printf("\t Digite [2] --> Printar dados das sublistas\n");
    printf("\t Digite [3] --> Printar todos os dados da lista generalizada\n");
    printf("\t Opcao: ");
    int opcao;
    scanf("%d", &opcao);
    /*
    while ( opcao != 1 || opcao != 2  || opcao != 3){
      printf("\t Digite [1] --> Printar dados da lista principal\n");
      printf("\t Digite [2] --> Printar dados das sublistas\n");
      printf("\t Digite [3] --> Printar todos os dados da lista generalizada\n");
      int opcao;
      printf("\t OPCAO: ");
      scanf("%d", &opcao);
    }
    */
    int dado;
    if( opcao == 1 ){ // printar dados lista principal
      printf("\n\t LISTA PRINCIPAL\n\n");
      no *aux;
      aux = lista->ini;
      printf("\t ");
      while ( aux != NULL ){

          if(aux->tipo==1){
            printf("%d ->", aux->info.atomo);
          }
          aux = aux->prox;
      }
      printf("\n\n");
      aux = NULL;
      free(aux);
      printf("\t Quantidade tipo 1 --> [%d]\n\n", tipoUm);
    }
    else if( opcao == 2){ // printar dados sublista
      printf("\n\t SUBLISTA\n");
      no *aux;
      aux = lista->ini;
      printf("\t ");
      while ( aux != NULL ){

          if(aux->tipo == 2){
            no *opa;
            opa = aux;
            opa->info.sublista;
            percorreLista(opa);
            //printf("%d ->", aux->info.atomo);
          }
          aux = aux->prox;
      }
      aux = NULL;
      free(aux);
      printf("\n\n\t Quantidade tipo 2 --> [%d]\n\n", tipoDois);
    }
    else{ // printar todos os dados da lista generalizada
      printf("\t LISTA GENERALIZADA\n");
    }

    return 0;
}

//void menu(op){
