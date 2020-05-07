#include <stdio.h>

//declaração do nó da árvore
typedef int elem;

typedef struct bloco {
        elem info;
        struct bloco *esq, *dir;
} no;

typedef struct {
        no *raiz;
} ABB;


//protótipos das funções
void criar(ABB*);
void finalizar(no**);
void imprimir(no**);
int inserir(no*,elem*);
int remover(no**,elem*);
int buscar(no**,elem*);

//função para criar/inicializar a árvore de busca binária
void criar(ABB *A) {
     A->raiz=NULL;
}

//função para finalizar árvore de busca binária; deve começar com p=raiz
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
        printf("%d(",(*p)->info);
        imprimir(&(*p)->esq);
        printf(",");
        imprimir(&(*p)->dir);
        printf(")");
     }
     else printf("null");
}

//função de busca de um elemento na árvore binária de busca; deve começar com p=raiz
int buscar(no **p, elem *x) {
    if (*p==NULL)
       return 0;
    else if (*x<(*p)->info)
         return(buscar(&(*p)->esq,x));
    else if (*x>(*p)->info)
         return(buscar(&(*p)->dir,x));
    else return 1;
}

//função de inserção de um elemento na árvore binária de busca; deve começar com p=raiz
int inserir(no **p, elem *x) {
     if (*p==NULL) {
        *p=(no*) malloc(sizeof(no));
        (*p)->info=*x;
        (*p)->esq=NULL;
        (*p)->dir=NULL;
        return 1;
     }
     else if (*x<(*p)->info)
          return(inserir(&(*p)->esq,x));
     else if (*x>(*p)->info)
          return(inserir(&(*p)->dir,x));
     else return 0;
}

//função que retorna o maior elemento de uma subarvore com raiz em p
elem busca_maior(no **p) {
     no *aux;
     aux=*p;
     while (aux->dir!=NULL)
           aux=aux->dir;
     return(aux->info);
}

//função que remove um elemento de uma árvore
int remover(no **p, elem *x) {
    no *aux;
    if (*p==NULL)
       return 0;
    else if (*x<(*p)->info)
         return(remover(&(*p)->esq,x));
    else if (*x>(*p)->info)
         return(remover(&(*p)->dir,x));
    else {
         //caso 1: o nó não tem filhos
         if (((*p)->esq==NULL) && ((*p)->dir==NULL)) {
            free(*p);
            *p=NULL;
            return 1;
         }
         //caso 2a: só há o filho direito
         else if ((*p)->esq==NULL) {
              aux=*p;
              *p=(*p)->dir;
              free(aux);
              return 1;
         }
         //caso 2b: só há o filho esquerdo
         else if ((*p)->dir==NULL) {
              aux=*p;
              *p=(*p)->esq;
              free(aux);
              return 1;
         }
         //caso 3: há os dois filhos
         else {
              (*p)->info=busca_maior(&(*p)->esq);
              return(remover(&(*p)->esq,&(*p)->info));
         }
    }
}


int main(void) {       
    ABB A;
    int opcao, k, res;
    
    criar(&A);
    
    printf("Entre com a acao desejada: 0 - sair, 1 - inserir, 2 - remover, 3 - buscar\n");
    printf("Sua opcao: ");
    scanf("%d",&opcao);
    while (opcao!=0) {          
          if (opcao==1) {
             printf("Digite a chave para inserir: ");
             scanf("%d",&k);
             res=inserir(A.raiz,&k);
             if (!res)
                printf("(erro ao inserir)\n");
             imprimir(&A.raiz);
             printf("\n");
          }
          else if (opcao==2) {
             printf("Digite a chave para remover: ");
             scanf("%d",&k);
             res=remover(&A.raiz,&k);
             if (!res)
                printf("(erro ao remover)\n");
             imprimir(&A.raiz);
             printf("\n");
          }
          else if (opcao==3) {
             printf("Digite a chave para buscar: ");
             scanf("%d",&k);
             res=buscar(&A.raiz,&k);
             if (!res)
                printf("(erro ao buscar)\n");
             imprimir(&A.raiz);
             printf("\n");
          }
          else printf("\nOpcao invalida\n");
          
          printf("\nEntre com a acao desejada: 0 - sair, 1 - inserir, 2 - remover, 3 - buscar\n");
          printf("Sua opcao: ");
          scanf("%d",&opcao);
    }

    imprimir(&A.raiz);
    printf("\n");
    finalizar(&A.raiz);
    system("pause");
    return 0;
}
