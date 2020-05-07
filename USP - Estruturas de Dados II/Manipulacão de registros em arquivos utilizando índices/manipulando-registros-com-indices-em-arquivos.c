#include <stdio.h>
#include <string.h>
#include <malloc.h>


/*
Constantes usadas pela aplicaÃ§Ã£o
*/
char LIMPAR[] = "clear";
char IMPORTACAO[] = "arqdad.txt";
char DADOS[] = "dados.dat";
char HEADER[] = "header.dat";
char IDXNOME[] = "idxnome";
char IDXRED[] = "idxred";


/*
Estrutura bÃ¡sica para armazenamento/tratamento de registros.
Esta estrutura apresenta campos de tamanho fixo baseados
nos tamanhos mÃ¡ximos apresentados nos campos dos registros.
*/
typedef struct cand {
    char inscricao[8];
    char nome[33];
    char nascimento[7];
    char red[4];
    char geo[5];
    char his[5];
    char bio[5];
    char mat[5];
    char port[5];
    char le[6];
    char fis[5];
    char qui[5];
    char final[7];
    char clas[4];
    char obs[4];
} cand;


/*
Estrutura de armazenamento/tratamento de chaves primÃ¡rias composta por:
 - Valor da chave primÃ¡ria (key);
 - RRN do registro (rrn);
 - Marcador de item de Ã­ndice ativo (ativo);
 - Ponteiro para prÃ³ximo elemento da lista ligada.
*/
typedef struct nodePk {
    char key[8];
    int rrn;
    char ativo;
    struct nodePk *prox;
    } nodePk;


/*
Estrutura para armazenamento/tratamento das listas invertidas;
Uma lista invertida Ã© criada para cada nÃ³ da lista de chaves secundÃ¡rias
e mantÃ©m ponteiros para os nÃ³s da lista de chave primÃ¡ria (acesso 
late binding);
Composta por:
 - Ponteiro para a chave primÃ¡ria correspondente;
 - Ponteiro para prÃ³ximo elemento da lista ligada.
*/
typedef struct nodeInvertida {
    struct nodePk *pk;
    struct nodeInvertida *prox;
    } nodeInvertida;


/*
Estrutura para armazenamento/tratamento de chaves secundÃ¡rios.
Cada nÃ³ do tipo "nodeSk" cria uma lista invertida. Para isso, mantÃ©m:
 - Valor da chave secundÃ¡ria (key);
 - Ponteiros de inÃ­cio e fim da lista invertida correspondente ao nÃ³ (first e last);
 - Ponteiro para prÃ³ximo elemento da lista ligada.
*/
typedef struct nodeSk {
    char key[33];
    struct nodeInvertida *first;
    struct nodeInvertida *last;
    struct nodeSk *prox;
    } nodeSk;


//Node inicial e final do Ã­ndice primÃ¡rio
nodePk *pkFirst, *pkLast;


//Nodes iniciais e finais dos Ã­ndices secundÃ¡rios
nodeSk *skNomeFirst, *skNomeLast, *skRedFirst, *skRedLast;


//Ponteiros para criaÃ§Ã£o de vetores em tempo de execuÃ§Ã£o para busca binÃ¡ria
nodeSk **vetorSkNome, **vetorSkRed;
nodePk **vetorPk;


//Tamanho dos vetores gerados
int tamanhoVetor, tamSkNome, tamSkRed, tamPk;


/*
VariÃ¡vel de FLAG: quando valorada em:
 - 0 : Executa rotina de busca sem dar opÃ§Ã£o de exclusÃ£o;
 - 1 : Executa rotina de busca dando opÃ§Ã£o de exclusÃ£o. 
*/
char excluirBusca = 0;


/*
Realiza a criaÃ§Ã£o dos arquivos de dados e cabeÃ§alho
quando os mesmos ainda nÃ£o existem.
*/
void criarArquivos() {
    FILE *file;
    file = fopen(DADOS, "rb");
    if (!file) {
        file = fopen(DADOS, "wb");
        fclose(file);
    }
    file = fopen(HEADER, "rb");
    if (!file) {
        file = fopen(HEADER, "wb");
        fprintf(file, "i=n");
        fclose(file);
    }
}


/*
Realiza o trabalho de inserÃ§Ã£o das chaves primÃ¡rias nos Ã­ndices;
Efetua a inserÃ§Ã£o das chaves jÃ¡ na forma ORDENADA;
Caso jÃ¡ houver o valor de chave primÃ¡ria que se pretende inserir, a funÃ§Ã£o
retornarÃ¡ o endereÃ§o do nÃ³ em que estÃ¡ alocada a respectiva chave;
Recebe como parÃ¢metro:
 - o valor da chave a ser inserida (key);
 - o rrn (deslocamento) no arquivo de dados (rrn);
 - ponteiro para o inÃ­cio da lista (first);
 - ponteiro para o final do Ã­ndice (last);

Devolve:
 - EndereÃ§o do nÃ³ em que estÃ¡ a chave que foi inserida;
*/
nodePk* inserirPk(char *key, int rrn, nodePk **first, nodePk **last) {
    nodePk *node, *iterador, *ante; //Ponteiros para realizaÃ§Ã£o de percurso
    node = (nodePk *) malloc(sizeof(nodePk));
    strcpy(node->key, key);
    node->rrn = rrn;
    node->ativo = 1;
    node->prox = NULL;

    // VerificaÃ§Ã£o de lista vazia.
    if (!*first) {
       *first = node;
        *last = node;
    }
    else {

       iterador = *first;
       ante = *first;

       while (iterador) {
      if (strcmp(iterador->key, key)==0) {
            return iterador;
      }
      if (strcmp(iterador->key, key)>=0) {
           break;
      }
      ante = iterador;
      iterador = iterador->prox;
       }

       if (iterador==NULL) {
      (*last)->prox = node;
      *last = node;
       }
       else if (iterador==ante) {
      node->prox = iterador;
      *first = node;
       }
       else {
      ante->prox = node;
      node->prox = iterador;

       }
 }
  return node;
}


/*
Realiza o trabalho de inserÃ§Ã£o dos elementos da lista invertida;
Efetua a inserÃ§Ã£o das chaves jÃ¡ na forma ORDENADA;
Recebe como parÃ¢metro:
 - o valor ponteiro para o nÃ³ que contÃ©m a chave primÃ¡ria correspondente;
 - ponteiro para o inÃ­cio da lista (first);
 - ponteiro para o final do Ã­ndice (last);
*/
void inserirInvertida(nodePk *pk, nodeInvertida **first, nodeInvertida **last) {
    nodeInvertida *node, *iterador, *ante;
    node = (nodeInvertida *) malloc(sizeof(nodeInvertida));
    node->pk = pk;
    node->prox = NULL;


    //VerificaÃ§Ã£o de lista vazia/inserÃ§Ã£o
    if (!*first) {
       *first = node;
        *last = node;
    }
    else {

    iterador = *first;
    ante = *first;

    while (iterador) {
        if (strcmp(iterador->pk->key, pk->key)>=0) {
             break;
        }
        ante = iterador;
        iterador = iterador->prox;
    }

    if (iterador==NULL) {
        (*last)->prox = node;
        *last = node;
    }
    else if (iterador==ante) {
        node->prox = iterador;
        *first = node;
    }
    else {
        ante->prox = node;
        node->prox = iterador;

    }
 }
}


/*
Realiza o trabalho de inserÃ§Ã£o das chaves secundÃ¡rias nos Ã­ndices;
Efetua a inserÃ§Ã£o das chaves jÃ¡ na forma ORDENADA;
Recebe como parÃ¢metro:
 - o valor da chave a ser inserida (key);
 - ponteiro para o nÃ³ que contÃ©m a chave primÃ¡ria correspondente;
 - ponteiro para o inÃ­cio da lista (first);
 - ponteiro para o final do Ã­ndice (last);
*/
void inserirSk(char *key, nodePk *pk, nodeSk **first, nodeSk **last) {
    nodeSk *node, *iterador, *ante;
    node = (nodeSk *) malloc(sizeof(nodeSk));
    strcpy(node->key, key);
    node->prox = NULL;

    node->first = NULL;
    node->last = NULL;

    //VerificaÃ§Ã£o de Ã­ndice vazio/inserÃ§Ã£o
    if (!*first) {
       *first = node;
        *last = node;

        //inserÃ§Ã£o de itens na lista invertida
        inserirInvertida(pk, &((*first)->first), &((*first)->last));
        return;
    }

    else {

    iterador = *first;
    ante = *first;

    while (iterador) {
        if (strcmp(iterador->key, key)==0) {
              free(node);

              //inserÃ§Ã£o de itens na lista invertida
              inserirInvertida(pk, &(iterador->first), &(iterador->last));
              return;
        }
        if (strcmp(iterador->key, key)>0) {
             break;
        }
        ante = iterador;
        iterador = iterador->prox;
    }

    if (iterador==NULL) {
        (*last)->prox = node;
        *last = node;
    }
    else if (iterador==ante) {
        node->prox = iterador;
        *first = node;
    }
    else {
        ante->prox = node;
        node->prox = iterador;

    }
   //inserÃ§Ã£o de itens na lista invertida
    inserirInvertida(pk, &(node->first), &(node->last));
 }
}


/*
Percorre a lista de Ã­ndice secundÃ¡rio e retorna seu tamanho
Recebe como parÃ¢metro:
 - ponteiro para o inÃ­cio da lista de Ã­ndice secundÃ¡rio
*/
int tamIndiceSk(nodeSk *first) {
    int i = 0;
    nodeSk *iter = first;
    while (iter) {
        i++;
        iter = iter->prox;
   }

    return i;
}


/*
Cria um vetor a partir de uma lista ligada, percorrendo a lista ligada.
Recebe como parÃ¢metro o ponteiro para o inÃ­cio da lista.
*/
nodeSk** listaParaVetor(nodeSk *first) {
    int i, n;
    nodeSk **elementos;
    n = tamIndiceSk(first);
    elementos = (nodeSk **) malloc(sizeof(nodeSk *)*n);

    for (i=0; i<n; i++) {
        elementos[i] = first;
        first = first->prox;
    }
    tamanhoVetor = n;
    return elementos;
}


/*
Percorre a lista de Ã­ndice primÃ¡rio e retorna seu tamanho
Recebe como parÃ¢metro:
 - ponteiro para o inÃ­cio da lista de Ã­ndice primÃ¡rio
*/
int tamIndicePk(nodePk *first) {
    int i = 0;
    nodePk *iter = first;
    while (iter) {
        if (iter->ativo) {
        i++;
        }
        iter = iter->prox;
   }
    return i;
}


/*
Cria um vetor a partir de uma lista ligada, percorrendo a lista ligada.
Recebe como parÃ¢metro o ponteiro para o inÃ­cio da lista.
*/
nodePk** listaParaVetorPk(nodePk *first) {
    int i, n;
    nodePk **elementos;
    n = tamIndicePk(first);
    elementos = (nodePk **) malloc(sizeof(nodePk *)*n);

    for (i=0; i<n; i++) {
        while (!(first->ativo)) {
        first = first->prox;
        }
        elementos[i] = first;
        first = first->prox;
    }
    tamanhoVetor = n;
    return elementos;


}


/*
Atualiza tamanhos dos Ã­ndices e recria os vetores.
*/
void atualizaVetores() {
   free(vetorSkNome);
   free(vetorSkRed);
   free(vetorPk);
   vetorPk = listaParaVetorPk(pkFirst);
   tamPk = tamanhoVetor;
   vetorSkNome = listaParaVetor(skNomeFirst);
   tamSkNome = tamanhoVetor;
   vetorSkRed = listaParaVetor(skRedFirst);
   tamSkRed = tamanhoVetor;
}


/*
Recebe uma string e um tamanho.
Atribui, atÃ© o limite dado como parÃ¢metro, espaÃ§os, encerrando com o caracter {FONTE}.
*/
void completaEspacos(char *str, int tamanho) {
     int i=0, x=0;
     if (str[i]==0) return;
     for (i=0; i<tamanho; i++) {
          x = i;
          if (str[i]==0) break;
     }
     for (i=x; i<tamanho; i++) {
         str[i] = ' ';
     }
     str[tamanho-1] = 0;
}


/*
Permite ao usuÃ¡rio adicionar um novo item ao arquivo de dados;
Os registros adicionados sÃ£o incluÃ­dos tambÃ©m nos Ã­ndices primÃ¡rio e secundÃ¡rio;
*/
void inserir() {
    cand c;
    int rrn, tamCampo;
    system(LIMPAR);
    getchar();
    printf("INSERIR INFORMAÃ‡Ã•ES DE NOVO CANDIDATO\n");

    do {
    printf("\nNÃºmero de inscriÃ§Ã£o  (mÃ¡x:7): ");
    gets(c.inscricao);
    tamCampo = strlen(c.inscricao);
    } while (tamCampo>7);
    completaEspacos(c.inscricao, 8);

    do {
    printf("\nNome (mÃ¡x:32): ");
    gets(c.nome);
    tamCampo = strlen(c.nome);
    } while (tamCampo>32);

    do {
    printf("\nNascimento  (mÃ¡x:6): ");
    gets(c.nascimento);
    tamCampo = strlen(c.nascimento);
    } while (tamCampo>6);
    completaEspacos(c.nascimento, 7);

    do {
    printf("\nRedaÃ§Ã£o (mÃ¡x:3): ");
    gets(c.red);
    tamCampo = strlen(c.red);
    } while (tamCampo>3);
    completaEspacos(c.red, 4);

    do {
    printf("\nGeografia (mÃ¡x:4): ");
    gets(c.geo);
    tamCampo = strlen(c.geo);
    } while (tamCampo>4);
    completaEspacos(c.geo, 5);

    do {
    printf("\nHistÃ³ria (mÃ¡x:4): ");
    gets(c.his);
    tamCampo = strlen(c.his);
    } while (tamCampo>4);
    completaEspacos(c.his, 5);

    do {
    printf("\nBiologia (mÃ¡x:4): ");
    gets(c.bio);
    tamCampo = strlen(c.bio);
    } while (tamCampo>4);
    completaEspacos(c.bio, 5);

    do {
    printf("\nMatemÃ¡tica (mÃ¡x:4): ");
    gets(c.mat);
    tamCampo = strlen(c.mat);
    } while (tamCampo>4);
    completaEspacos(c.mat, 5);

    do {
    printf("\nPortuguÃªs (mÃ¡x:4): ");
    gets(c.port);
    tamCampo = strlen(c.port);
    } while (tamCampo>4);
    completaEspacos(c.port, 5);

    do {
    printf("\nLÃ­ngua Estrangeira (mÃ¡x:5): ");
    gets(c.le);
    tamCampo = strlen(c.le);
    } while (tamCampo>5);
    completaEspacos(c.le, 6);

    do {
    printf("\nFÃ­sica (mÃ¡x:4): ");
    gets(c.fis);
    tamCampo = strlen(c.fis);
    } while (tamCampo>4);
    completaEspacos(c.fis, 5);

    do {
    printf("\nQuÃ­mica (mÃ¡x:4): ");
    gets(c.qui);
    tamCampo = strlen(c.qui);
    } while (tamCampo>4);
    completaEspacos(c.qui, 5);

    do {
    printf("\nEscore Final (mÃ¡x:6): ");
    gets(c.final);
    tamCampo = strlen(c.final);
    } while (tamCampo>6);
    completaEspacos(c.final, 7);

    do {
    printf("\nClassificaÃ§Ã£o (mÃ¡x:3): ");
    gets(c.clas);
    tamCampo = strlen(c.clas);
    } while (tamCampo>3);
    completaEspacos(c.clas, 4);

    do {
    printf("\nObservaÃ§Ã£o (mÃ¡x:3): ");
    gets(c.obs);
    tamCampo = strlen(c.obs);
    } while (tamCampo>3);
    completaEspacos(c.obs, 4);

    FILE *fd;
    fd = fopen(DADOS, "a");

    rrn = ftell(fd);


    fprintf(fd, "|%s|%s|%s|%s|%s|%s|%s|%s|%s|%s|%s|%s|%s|%s|%s|#",
    c.inscricao, c.nome, c.nascimento, c.red, c.geo, c.his, c.bio, c.mat, c.port, c.le, c.fis, c.qui, c.final, c.clas, c.obs);

    //InclusÃ£o de registros nos Ã­ndices primÃ¡rio e secundÃ¡rio.
    nodePk *p;
    p = inserirPk(c.inscricao, rrn, &pkFirst, &pkLast);
    inserirSk(c.nome, p, &skNomeFirst, &skNomeLast);
    inserirSk(c.red, p, &skRedFirst, &skRedLast);

    fclose(fd);

}


/*
Percorre o arquivo de dados com base no rrn e adiciona
uma marca de exclusÃ£o (*), alÃ©m de desativar o respectivo nÃ³;
Recebe como parÃ¢metro:
 - o ponteiro para o nÃ³ do registro a ser excluÃ­do;
*/
void excluir(nodePk *node) {
    node->ativo = 0;
    FILE *file;
    file = fopen(DADOS, "r+b");
    fseek(file, node->rrn, SEEK_SET);
    fputc('*', file);
    fclose(file);
}


/*
Exibe na tela o registro contido no arquivo de dados, indicado pelo RRN;
*/
void imprimirRegistro(int rrn) {
    char registro[150], c;
    int x = 0;
    FILE *file;
    file = fopen(DADOS, "rb");
    fseek(file, rrn+1, SEEK_SET);
    while ((c=fgetc(file))!='#') {
       registro[x] = c;
       x++;
    }
    registro[x] = 0;

    printf("\n\nNÃºmero de InscriÃ§Ã£o: %s", strtok(registro, "|*"));
    printf("\nNome: %s", strtok(NULL, "|*"));
    printf("\nData de nascimento: %s", strtok(NULL, "|*"));
    printf("\n:::::::::::::::::::::::::::NOTAS::::::::::::::\
:::::::::::::\nRedaÃ§Ã£o: %s; ", strtok(NULL, "|*"));
    printf("Geografia: %s; ", strtok(NULL, "|*"));
    printf("HistÃ³ria: %s; ", strtok(NULL, "|*"));
    printf("\nBiologia: %s; ", strtok(NULL, "|*"));
    printf("MatemÃ¡tica: %s; ", strtok(NULL, "|*"));
    printf("PortuguÃªs: %s; ", strtok(NULL, "|*"));
    printf("\nLÃ­ngua Estrangeira: %s; ", strtok(NULL, "|*"));
    printf("FÃ­sica: %s; ", strtok(NULL, "|*"));
    printf("QuÃ­mica: %s; ", strtok(NULL, "|*"));
    printf("\n:::::::::::::::::::::::::RESULTADOS:::::::::::\
:::::::::::::\nEscore Final: %s; ", strtok(NULL, "|*"));
    printf("ClassificaÃ§Ã£o: %s; ", strtok(NULL, "|*"));
    printf("ObservaÃ§Ã£o: %s; \n", strtok(NULL, "|*"));
    printf("-----------------------------------------------------------\n");

    fclose(file);
}


/*
Exibe para o usuÃ¡rio todos os itens dos Ã­ndices secundÃ¡rios
*/
void mostrarSk(nodeSk *first) {
    getchar();
    nodeInvertida *inv;
    while (first) {

        inv = first->first;
        while(inv) {
            if (inv->pk->ativo) {
            imprimirRegistro(inv->pk->rrn);


            printf("Pressione ENTER para prÃ³ximo registro (ESC + ENTER para voltar)...");
            if (getchar()==27) return;
            }
            inv = inv->prox;
        }

        first = first->prox;

        }

}


/*
Exibe para o usuÃ¡rio todos os itens dos Ã­ndices primÃ¡rios
*/
void mostrarPk(nodePk *first) {
    getchar();

    while (first) {
        if (first->ativo) {
        imprimirRegistro(first->rrn);
        printf("Pressione ENTER para prÃ³ximo registro (ESC + ENTER para voltar)...");
        if (getchar()==27) return;
        }
        first = first->prox;
        }

}


/*
Busca no vetor construÃ­do a partir do Ã­ndice primÃ¡rio o valor informado;
Usa o mÃ©todo de busca binÃ¡ria;
Recebe como parÃ¢metro:
 - a chave a ser pesquisada;
 - vetor onde deve ser pesquisado;
 - o tamanho do vetor onde deve ser pesquisado;
*/
void buscaPk(char *elemento, nodePk **vetor, int tamVetor) {
   int inf = 0, sup = tamVetor-1, x, encontrado = 0;

   while (inf <= sup) {
      x = (inf+sup)/2;
      if (strcmp((vetor[x])->key, elemento)==0) {
          encontrado = 1;
          break;
      }
      else if (strcmp((vetor[x])->key, elemento)<0) {
          inf = x + 1;
      }

      else {
           sup = x - 1;
      }

   }
  system(LIMPAR);
  printf("RESULTADOS DA BUSCA POR: \"%s\"\n\n", elemento);
  if (encontrado) {
      char opcao;
      char *op = &opcao;
      getchar();
      if ((vetor[x])->ativo) {

            opcao = 'N';
            imprimirRegistro((vetor[x])->rrn);

            if (excluirBusca) {
            printf("\nDESEJA EXCLUIR ESSE REGISTRO? (S/N)\n");
            gets(op);
            if (opcao == 'S' || opcao == 's') {
                excluir((vetor[x]));
                atualizaVetores();
            }
            }
}
  }

  else {
     printf("NÃ£o foi encontrado o item");
    }

}


/*
Busca no vetor construÃ­do a partir de um dos Ã­ndices
secundÃ¡rios o valor informado;
Usa o mÃ©todo de busca binÃ¡ria;
Recebe como parÃ¢metro:
 - a chave a ser pesquisada;
 - vetor onde deve ser pesquisado;
 - o tamanho do vetor onde deve ser pesquisado;
*/
void buscaBinaria(char *elemento, nodeSk **vetor, int tamVetor) {
   int inf = 0, sup = tamVetor-1, x, encontrado = 0;

   while (inf <= sup) {
      x = (inf+sup)/2;
      if (strcmp((vetor[x])->key, elemento)==0) {
          encontrado = 1;
          break;
      }
      else if (strcmp((vetor[x])->key, elemento)<0) {
          inf = x + 1;
      }

      else {
          sup = x - 1;
      }

   }

  system(LIMPAR);
  printf("RESULTADOS DA BUSCA POR: \"%s\"\n", elemento);
  if (encontrado) {
     nodeInvertida *inv;
     inv = (vetor[x])->first;
        char opcao;
        char *op = &opcao;

        // Percurso da lista e opÃ§Ã£o para exclusÃ£o de registro
        while(inv) {
            opcao = 'N';
            if (inv->pk->ativo) {
            imprimirRegistro(inv->pk->rrn);
            if (excluirBusca) {
            printf("\nDESEJA EXCLUIR ESSE REGISTRO? (S/N)\n");
            gets(op);
            if (opcao == 'S' || opcao == 's') {
                excluir(inv->pk);
                atualizaVetores();
            }
            }

            printf("Pressione ENTER para prÃ³ximo registro (ESC + ENTER para voltar)...");
            if (getchar()==27) return;

            }
            inv = inv->prox;
        }

}

  else {
     printf("NÃ£o foi encontrado o item");
   }

}


/*
MENU DE PESQUISA
*/
void menuPesquisar() {
    char opcao = ' ';
    char valor[33];
    while (opcao!='4') {
    getchar();
    system(LIMPAR);
    if (excluirBusca) {
    printf("EXCLUSÃƒO DE REGISTROS\n");
    }
    printf("PESQUISAR REGISTROS POR: \n\n");
    printf("1. NÃºmero de InscriÃ§Ã£o\n");
    printf("2. Nome\n");
    printf("3. Nota da RedaÃ§Ã£o\n");
    printf("4. Voltar\n");
    printf("\nEscolha uma opÃ§Ã£o: ");

    opcao = getchar();

    if (opcao=='1') {
        printf("\nEntre com a chave primÃ¡ria: ");
        scanf("%s", valor);
        completaEspacos(valor, 8);
        buscaPk(valor, vetorPk, tamPk);
        printf("\nFim de busca, pressione ENTER para continuar...\n");
    }
    if (opcao=='2') {
        getchar();
        printf("\nEntre com o nome: ");
        gets(valor);
        buscaBinaria(valor, vetorSkNome, tamSkNome);
        printf("\nFim de busca, pressione ENTER para continuar...\n");
    }
    if (opcao=='3') {
        printf("\nEntre com a nota de redaÃ§Ã£o: ");
        scanf("%s", valor);
        completaEspacos(valor, 4);
        getchar();
        buscaBinaria(valor, vetorSkRed, tamSkRed);
        printf("\nFim de busca, pressione ENTER para continuar...\n");

    }

    }
}


/*
Desaloca todos os dados utilizados pelos Ã­ndices mantidos em memÃ³ria
*/
void limparIndices() {

    nodeInvertida *inv, *anteInv;
    nodeSk *sk, *anteSk;

    sk = skNomeFirst;

    while (sk) {
        inv = sk->first;
        anteInv = NULL;
        while (inv) {
            anteInv = inv;
            inv = inv->prox;
            free(anteInv->pk);
            free(anteInv);
        }
        anteSk = sk;
        sk = sk->prox;
        free(anteSk);
    }

    sk = skRedFirst;

    while (sk) {
        inv = sk->first;
        anteInv = NULL;
        while (inv) {
            anteInv = inv;
            inv = inv->prox;
            free(anteInv);
        }
        anteSk = sk;
        sk = sk->prox;
        free(anteSk);
    }

    pkFirst = NULL;
    skNomeFirst = NULL;
    skRedFirst = NULL;

}


/*
Efetua a gravaÃ§Ã£o das listas de Ã­ndices primÃ¡rio e secundÃ¡rio em arquivos
*/
void salvarIndices() {

    nodeInvertida *inv;
    nodePk *pk;
    nodeSk *skn, *skr;
    FILE *fn, *fr;
    fn = fopen(IDXNOME, "wb");
    fr = fopen(IDXRED, "wb");

    skn = skNomeFirst;


    while (skn) {
        inv = skn->first;
        while (inv) {
            if (inv->pk->ativo) {
            fprintf(fn, "%s|%s|%d|\n", inv->pk->key, skn->key, inv->pk->rrn);
            }
            inv = inv->prox;
        }
        skn = skn->prox;
    }

    skr = skRedFirst;

    while (skr) {
        inv = skr->first;
        while (inv) {
            if (inv->pk->ativo) {
            fprintf(fr, "%s|%s|%d|\n", inv->pk->key, skr->key, inv->pk->rrn);
            }
            inv = inv->prox;
        }
        skr = skr->prox;
    }

    fclose(fn);
    fclose(fr);
}


/*
Caso os Ã­ndices sejam apagados, reconstroi os mesmos;
O parÃ¢metro "recupera" pode ser valorado como:
 - 0 : efetua reconstruÃ§Ã£o sem recuperar registro excluÃ­dos
 - 1 : efetua reconstruÃ§Ã£o recuperando registro excluÃ­dos
*/
void reconstruirIndices(int recupera) {
    limparIndices();
    nodePk *p;
    char registro[150], c, *pk, *nome, *red;
    int x, rrn = 0;
    FILE *file;
    file = fopen(DADOS, "rb");
    if (!file) {
        printf("\nNÃ£o foi possÃ­vel abrir o arquivo de dados...");
        return;
    }

    while (1) {
        x = 0;
    while (((c=fgetc(file))!='#')) {
        if (feof(file)) {
            fclose(file);
            salvarIndices();
            printf("\nOs Ã­ndices foram reconstruÃ­dos com sucesso...");
            getchar();
            return;
            }
       registro[x] = c;
       x++;
    }
    registro[x] = 0;
    if (recupera==1||(recupera==0 && registro[0]!='*')) {
    pk = strtok(registro, "|*");
    nome = strtok(NULL, "|*");
    strtok(NULL, "|*");
    red = strtok(NULL, "|*");

    completaEspacos(red, 4);
    p = inserirPk(pk, rrn, &pkFirst, &pkLast);
    inserirSk(nome, p, &skNomeFirst, &skNomeLast);
    inserirSk(red, p, &skRedFirst, &skRedLast);
}
    rrn = ftell(file);
    
       }
}


/*
Carrega para memÃ³ria todos os Ã­ndices gravados em arquivo;
*/
void carregarIndices() {
    limparIndices();
    FILE *nome, *red;
    nome = fopen(IDXNOME, "rb");
    red = fopen(IDXRED, "rb");
    if (nome&&red) {
    char linha[100], *key, *pk, *rrn;
    nodePk *p;

    while (fgets(linha, 100, nome)) {
        pk = strtok(linha, "|*");
        key = strtok(NULL, "|*");
        rrn = strtok(NULL, "|*");
        p = inserirPk(pk, atoi(rrn), &pkFirst, &pkLast);
        inserirSk(key, p, &skNomeFirst, &skNomeLast);

    }

    while (fgets(linha, 100, red)) {
        pk = strtok(linha, "|*");
        key = strtok(NULL, "|*");
        rrn = strtok(NULL, "|*");
        p = inserirPk(pk, atoi(rrn), &pkFirst, &pkLast);
        inserirSk(key, p, &skRedFirst, &skRedLast);
    }

    }

    else {
        printf("\nNÃ£o foi possÃ­vel carregar os Ã­ndices, pressione ENTER\
 para iniciar a reconstruÃ§Ã£o dos Ã­ndices...");
        getchar();
        reconstruirIndices(0);
    }

}


/*
Realiza a abertura e importaÃ§Ã£o do arquivo "arqdad.txt"
*/
void importar() {
    FILE *file;
    file = fopen(HEADER, "rb");
    char l[4];
    fscanf(file, "%s", l);
    fclose(file);
    if (l[2] == 's') {
        printf("\n\nO arquivo arqdad.txt jÃ¡ foi importado.");
        getchar();
        return;
    }
    cand candidato;
    char linha[150];
    int rrn, i, x=0;
    FILE *saida, *fd;
    fd = fopen(IMPORTACAO, "rb");
    saida = fopen(DADOS, "ab");

    if (!fd) {
        printf("ARQUIVO DE IMPORTAÃ‡ÃƒO NÃƒO ENCONTRADO...");
        getchar();
        return;
    }
    for (i=0; i<7; i++) {
        fgets(linha, 150, fd);
        }
    rrn = 0;
    while (fgets(linha, 150, fd)) {

        fseek(saida, 0, SEEK_END);
        rrn = ftell(saida);

        for (i=1; i<8; i++) {
            candidato.inscricao[x]=linha[i];
            x++;
            }
        candidato.inscricao[x] = 0;
        x = 0;
        fprintf(saida, "|%s|", candidato.inscricao);

        for (i=10; i<43; i++) {
            if ((linha[i]==' ')&&(linha[i+1]==' ')) break;
            candidato.nome[x]=linha[i];
            x++;
            }
        candidato.nome[x] = 0;
        x = 0;
        fprintf(saida, "%s|", candidato.nome);

        for (i=43; i<49; i++) {
            candidato.nascimento[x]=linha[i];
            x++;
            }
        candidato.nascimento[x] = 0;
        x = 0;
        fprintf(saida, "%s|", candidato.nascimento);

        for (i=52; i<56; i++) {
            candidato.red[x]=linha[i];
            x++;
            }
        candidato.red[x] = 0;
        x = 0;
        fprintf(saida, "%s|", candidato.red);

        for (i=57; i<61; i++) {
            candidato.geo[x]=linha[i];
            x++;
            }
        candidato.geo[x] = 0;
        x = 0;
        fprintf(saida, "%s|", candidato.geo);

        for (i=62; i<67; i++) {
            candidato.his[x]=linha[i];
            x++;
            }
        candidato.his[x] = 0;
        x = 0;
        fprintf(saida, "%s|", candidato.his);

        for (i=68; i<73; i++) {
            candidato.bio[x]=linha[i];
            x++;
            }
        candidato.bio[x] = 0;
        x = 0;
        fprintf(saida, "%s|", candidato.bio);

        for (i=73; i<78; i++) {
            candidato.mat[x]=linha[i];
            x++;
            }
        candidato.mat[x] = 0;
        x = 0;
        fprintf(saida, "%s|", candidato.mat);

        for (i=80; i<85; i++) {
            candidato.port[x]=linha[i];
            x++;
            }
        candidato.port[x] = 0;
        x = 0;
        fprintf(saida, "%s|", candidato.port);

        for (i=85; i<91; i++) {
            candidato.le[x]=linha[i];
            x++;
            }
        candidato.le[x] = 0;
        x = 0;
        fprintf(saida, "%s|", candidato.le);

        for (i=92; i<97; i++) {
            candidato.fis[x]=linha[i];
            x++;
            }
        candidato.fis[x] = 0;
        x = 0;
        fprintf(saida, "%s|", candidato.fis);

        for (i=97; i<102; i++) {
            candidato.qui[x]=linha[i];
            x++;
            }
        candidato.qui[x] = 0;
        x = 0;
        fprintf(saida, "%s|", candidato.qui);

        for (i=103; i<109; i++) {
            candidato.final[x]=linha[i];
            x++;
            }
        candidato.final[x] = 0;
        x = 0;
        fprintf(saida, "%s|", candidato.final);

        for (i=112; i<116; i++) {
            candidato.clas[x]=linha[i];
            x++;
            }
        candidato.clas[x] = 0;
        x = 0;
        fprintf(saida, "%s|", candidato.clas);

        for (i=117; i<120; i++) {
            candidato.obs[x]=linha[i];
            x++;
            }
        candidato.obs[x] = 0;
        x = 0;
        fprintf(saida, "%s|#", candidato.obs);

    candidato.inscricao[7] = 0;
    candidato.nome[32] = 0;
    candidato.red[3] = 0;

    nodePk *p;
    p = inserirPk(candidato.inscricao, rrn, &pkFirst, &pkLast);
    inserirSk(candidato.nome, p, &skNomeFirst, &skNomeLast);
    inserirSk(candidato.red, p, &skRedFirst, &skRedLast);


      }
    file = fopen(HEADER, "wb");
    l[2] = 's';
    fprintf(file, "%s", l);
    fclose(file);
}


/*
Cria um novo arquivo de dados, excluindo definitivamente os
registros outrora somente removidos logicamente.
*/
void removerDefinitivo() {
    int x;
    char c, registro[150];
    FILE *file, *tmp;
    file = fopen(DADOS, "rb");
    tmp = fopen("tmp", "wb");
    if (!file) {
        printf("\nNÃ£o foi possÃ­vel abrir o arquivo de dados...");
        return;
    }

    while (1) {
        x = 0;
    while (((c=fgetc(file))!='#')) {
        if (feof(file)) {
            fclose(file);
            fclose(tmp);
            remove(DADOS);
            rename("tmp", DADOS);
            reconstruirIndices(1);
            printf("\nTodos os registros removidos logicamente foram definitivamente removidos...");
            return;
            }
       registro[x] = c;
       x++;
    }
    registro[x] = '#';
    registro[x+1] = 0;

    if (registro[0]!='*') {
     fprintf(tmp, "%s", registro);
   }

       }   

}


/*
MENU DE LISTAGEM DE REGISTROS
*/
void menuListar() {
   char opcao = ' ';
    char valor[33];
    getchar();
    while (opcao!='4') {
    system(LIMPAR);

    printf("LISTAR REGISTROS POR: \n\n");
    printf("1. NÃºmero de InscriÃ§Ã£o\n");
    printf("2. Nome\n");
    printf("3. Nota da RedaÃ§Ã£o\n");
    printf("4. Voltar\n");
    printf("\nEscolha uma opÃ§Ã£o: ");

    scanf("%c", &opcao);

    if (opcao=='1') {
        mostrarPk(pkFirst);
    }
    if (opcao=='2') {
        mostrarSk(skNomeFirst);

    }
    if (opcao=='3') {
        mostrarSk(skRedFirst);

    }


    }
}


/*
MENU DE INSERCAO DE REGISTROS
*/
void menuInserir() {

    char opcao = ' ';
    getchar();
    while (opcao!='2') {
    system(LIMPAR);

    printf("INSERIR NOVO REGISTRO\n");
    printf("1. Iniciar inserÃ§Ã£o de dados\n");
    printf("2. Voltar\n");
    printf("\nEscolha uma opÃ§Ã£o: ");

    scanf("%c", &opcao);

    if (opcao=='1') {
        inserir();
    }
    }
}


/*
MENU PRINCIPAL
*/
int menuPrincipal() {
    char opcao[] = "  ";
    system(LIMPAR);
    printf("Pressione ENTER...");
    while (opcao[0] != '1' && (opcao[1] != '1' || opcao[1] != '0')) {
        getchar();
        system(LIMPAR);

        printf("MANIPULAÃ‡ÃƒO DE ARQUIVOS DE DADOS COM USO DE ÃNDICES");
        printf("\n\n1. Inserir");
        printf("\n2. Excluir");
        printf("\n3. Listar");
        printf("\n4. Buscar");
        printf("\n5. Importar arquivo \"arqdad.txt\"");
        printf("\n6. Restaurar registros removidos logicamente");
        printf("\n7. Reconstruir Ã­ndices");
        printf("\n8. Remover registros definitivamente");
        printf("\n9. Salvar alteraÃ§Ãµes");
        printf("\n10. Cancelar alteraÃ§Ãµes e sair");
        printf("\n11. Salvar alteraÃ§Ãµes e sair");
        printf("\n\nEscolha uma opÃ§Ã£o vÃ¡lida: ");

        scanf("%s", opcao);

        if (opcao[0] == '1' && opcao[1] == '0') {
            return 0;
        }

        if (opcao[0] == '1' && opcao[1] == '1') {
            return 1;
        }

        if (opcao[0] == '1') {
            menuInserir();
        }

        if (opcao[0] == '2') {
            atualizaVetores();
            excluirBusca = 1;
            menuPesquisar();
        }

        if (opcao[0] == '3') {
            excluirBusca = 0;
            menuListar();
        }

        if (opcao[0] == '4') {
            atualizaVetores();
       excluirBusca = 0;
            menuPesquisar();
        }

        if (opcao[0] == '5') {
            importar();
        }

        if (opcao[0] == '6') {
            limparIndices();
            reconstruirIndices(1);
            salvarIndices();
            printf("\n\nOs registros excluÃ­dos foram restaurados!");

        }

        if (opcao[0] == '7') {
            reconstruirIndices(0);
        }

        if (opcao[0] == '8') {
            removerDefinitivo();
        }

        if (opcao[0] == '9') {
            salvarIndices();
            printf("\n\nAs alteraÃ§Ãµes foram gravadas nos arquivos de Ã­ndices...");
            getchar();
        }
    }
}


/*
Programa principal
*/
int main() {

//Verifica se os arquivos jÃ¡ existem e os cria, caso negativo;
criarArquivos();

//Carrega os Ã­ndices do arquivo para a memÃ³ria;
carregarIndices();

//Salva Ã­ndices se for a opÃ§Ã£o escolhida pelo usuÃ¡rio;
if (menuPrincipal()) {
    salvarIndices();
   }
}