#include <stdio.h>
#include <stdlib.h>

typedef struct NO* ArvAVL;

ArvAVL* cria_ArvAVL();
void libera_ArvAVL(ArvAVL *raiz);
int insere_ArvAVL(ArvAVL *raiz, int data);
int remove_ArvAVL(ArvAVL *raiz, int valor);
int estaVazia_ArvAVL(ArvAVL *raiz);
int altura_ArvAVL(ArvAVL *raiz);
int totalNO_ArvAVL(ArvAVL *raiz);
int consulta_ArvAVL(ArvAVL *raiz, int valor);
void preOrdem_ArvAVL(ArvAVL *raiz);
void emOrdem_ArvAVL(ArvAVL *raiz);
void posOrdem_ArvAVL(ArvAVL *raiz);

void adicionarDado(ArvAVL *raiz);
void menus(ArvAVL *raiz, int op);
void alturaArvore(ArvAVL *raiz);
void adicionarDado(ArvAVL *raiz);
void removerDado(ArvAVL *raiz);
void printarOrdens(ArvAVL *raiz);
void verificaVazia(ArvAVL *raiz);
void verificaDado(ArvAVL *raiz);
void menu();

struct NO{
    int info;
    int altura;
    struct NO *esq;
    struct NO *dir;
};

ArvAVL* cria_ArvAVL(){
    ArvAVL* raiz = (ArvAVL*) malloc(sizeof(ArvAVL));
    if(raiz != NULL)
        *raiz = NULL;
    return raiz;
}

void libera_NO(struct NO* no){
    if(no == NULL)
        return;
    libera_NO(no->esq);
    libera_NO(no->dir);
    free(no);
    no = NULL;
}

void libera_ArvAVL(ArvAVL* raiz){
    if(raiz == NULL)
        return;
    libera_NO(*raiz);//libera cada nó
    free(raiz);//libera a raiz
}

int altura_NO(struct NO* no){
    if(no == NULL)
        return -1;
    else
    return no->altura;
}

int fatorBalanceamento_NO(struct NO* no){
    return labs(altura_NO(no->esq) - altura_NO(no->dir));
}

int maior(int x, int y){
    if(x > y)
        return x;
    else
        return y;
}

int estaVazia_ArvAVL(ArvAVL *raiz){
    if(raiz == NULL)
        return 1;
    if(*raiz == NULL)
        return 1;
    return 0;
}

int totalNO_ArvAVL(ArvAVL *raiz){
    if (raiz == NULL)
        return 0;
    if (*raiz == NULL)
        return 0;
    int alt_esq = totalNO_ArvAVL(&((*raiz)->esq));
    int alt_dir = totalNO_ArvAVL(&((*raiz)->dir));
    return(alt_esq + alt_dir + 1);
}

int altura_ArvAVL(ArvAVL *raiz){
    if (raiz == NULL)
        return 0;
    if (*raiz == NULL)
        return 0;
    int alt_esq = altura_ArvAVL(&((*raiz)->esq));
    int alt_dir = altura_ArvAVL(&((*raiz)->dir));
    if (alt_esq > alt_dir)
        return (alt_esq + 1);
    else
        return(alt_dir + 1);
}

void preOrdem_ArvAVL(ArvAVL *raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
    	printf("    ");
        printf("%d ",(*raiz)->info);
        preOrdem_ArvAVL(&((*raiz)->esq));
        preOrdem_ArvAVL(&((*raiz)->dir));
    }
}

void emOrdem_ArvAVL(ArvAVL *raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        emOrdem_ArvAVL(&((*raiz)->esq));
        printf("    ");
        printf("%d ", (*raiz)->info);
        emOrdem_ArvAVL(&((*raiz)->dir));
    }
}

void posOrdem_ArvAVL(ArvAVL *raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        posOrdem_ArvAVL(&((*raiz)->esq));
        posOrdem_ArvAVL(&((*raiz)->dir));
        printf("    ");
        printf("%d ",(*raiz)->info);
    }
}

int consulta_ArvAVL(ArvAVL *raiz, int valor){
    if(raiz == NULL)
        return 0;
    struct NO* atual = *raiz;
    while(atual != NULL){
        if(valor == atual->info){
            return 1;
        }
        if(valor > atual->info)
            atual = atual->dir;
        else
            atual = atual->esq;
    }
    return 0;
}

void RotacaoLL(ArvAVL *A){
    struct NO *B;
    B = (*A)->esq;
    (*A)->esq = B->dir;
    B->dir = *A;
    (*A)->altura = maior(altura_NO((*A)->esq),altura_NO((*A)->dir)) + 1;
    B->altura = maior(altura_NO(B->esq),(*A)->altura) + 1;
    *A = B;
}

void RotacaoRR(ArvAVL *A){
    struct NO *B;
    B = (*A)->dir;
    (*A)->dir = B->esq;
    B->esq = (*A);
    (*A)->altura = maior(altura_NO((*A)->esq),altura_NO((*A)->dir)) + 1;
    B->altura = maior(altura_NO(B->dir),(*A)->altura) + 1;
    (*A) = B;
}

void RotacaoLR(ArvAVL *A){
    RotacaoRR(&(*A)->esq);
    RotacaoLL(A);
}

void RotacaoRL(ArvAVL *A){
    RotacaoLL(&(*A)->dir);
    RotacaoRR(A);
}

int insere_ArvAVL(ArvAVL *raiz, int valor){
    int res;
    if(*raiz == NULL){//árvore vazia ou nó folha
        struct NO *novo;
        novo = (struct NO*)malloc(sizeof(struct NO));
        if(novo == NULL)
            return 0;

        novo->info = valor;
        novo->altura = 0;
        novo->esq = NULL;
        novo->dir = NULL;
        *raiz = novo;
        return 1;
    }

    struct NO *atual = *raiz;
    if(valor < atual->info){
        if((res = insere_ArvAVL(&(atual->esq), valor)) == 1){
            if(fatorBalanceamento_NO(atual) >= 2){
                if(valor < (*raiz)->esq->info ){
                    RotacaoLL(raiz);
                }else{
                    RotacaoLR(raiz);
                }
            }
        }
    }else{
        if(valor > atual->info){
            if((res = insere_ArvAVL(&(atual->dir), valor)) == 1){
                if(fatorBalanceamento_NO(atual) >= 2){
                    if((*raiz)->dir->info < valor){
                        RotacaoRR(raiz);
                    }else{
                        RotacaoRL(raiz);
                    }
                }
            }
        }else{
            //printf("\n    Valor duplicado!!\n\n");
            return 0;
        }
    }

    atual->altura = maior(altura_NO(atual->esq),altura_NO(atual->dir)) + 1;

    return res;
}

struct NO* procuraMenor(struct NO* atual){
    struct NO *no1 = atual;
    struct NO *no2 = atual->esq;
    while(no2 != NULL){
        no1 = no2;
        no2 = no2->esq;
    }
    return no1;
}

int remove_ArvAVL(ArvAVL *raiz, int valor){
	if(*raiz == NULL){
	    printf("\n\n    Dado[s] inexistente na arvore!\n");
	    return 0;
	}

    int res;
	if(valor < (*raiz)->info){
	    if((res = remove_ArvAVL(&(*raiz)->esq,valor)) == 1){
            if(fatorBalanceamento_NO(*raiz) >= 2){
                if(altura_NO((*raiz)->dir->esq) <= altura_NO((*raiz)->dir->dir))
                    RotacaoRR(raiz);
                else
                    RotacaoRL(raiz);
            }
	    }
	}

	if((*raiz)->info < valor){
	    if((res = remove_ArvAVL(&(*raiz)->dir, valor)) == 1){
            if(fatorBalanceamento_NO(*raiz) >= 2){
                if(altura_NO((*raiz)->esq->dir) <= altura_NO((*raiz)->esq->esq) )
                    RotacaoLL(raiz);
                else
                    RotacaoLR(raiz);
            }
	    }
	}

	if((*raiz)->info == valor){
	    if(((*raiz)->esq == NULL || (*raiz)->dir == NULL)){// nó tem 1 filho ou nenhum
			struct NO *oldNode = (*raiz);
			if((*raiz)->esq != NULL)
                *raiz = (*raiz)->esq;
            else
                *raiz = (*raiz)->dir;
			free(oldNode);
		}else { // nó tem 2 filhos
			struct NO* temp = procuraMenor((*raiz)->dir);
			(*raiz)->info = temp->info;
			remove_ArvAVL(&(*raiz)->dir, (*raiz)->info);
            if(fatorBalanceamento_NO(*raiz) >= 2){
				if(altura_NO((*raiz)->esq->dir) <= altura_NO((*raiz)->esq->esq))
					RotacaoLL(raiz);
				else
					RotacaoLR(raiz);
			}
		}
		if (*raiz != NULL)
            (*raiz)->altura = maior(altura_NO((*raiz)->esq),altura_NO((*raiz)->dir)) + 1;
		return 1;
	}

	(*raiz)->altura = maior(altura_NO((*raiz)->esq),altura_NO((*raiz)->dir)) + 1;

	return res;
}

int main(){
	
	printf("    --- WELCOME TO ARVORES RANCH ---\n\n");
	
    ArvAVL* avl;
    avl = cria_ArvAVL();
    
    int op;
    
	do{
		menu();
		scanf("%d", &op);
		menus(avl, op);
	}while(op!=0);
	
    return 0;
}

void menu(){
	
	printf("    --- Escolha uma opcao ---\n");
	printf("    Digite [1] --> Adicionar dado na arvore\n");
	printf("    Digite [2] --> Remover dado da arvore\n");
	printf("    Digite [3] --> Verificar se arvore esta vazia\n");
	printf("    Digite [4] --> Verificar se algum dado esta na arvore\n");
	printf("    Digite [5] --> Verificar quantidade de nos da arvore\n");
	printf("    Digite [6] --> Verificar altura da arvore\n");
	printf("    Digite [7] --> Imprimir todas as ordens da arvore\n\n");
	
	printf("    Digite [0] --> SAIR\n");
	
	printf("    Opcao: ");
}

void adicionarDado(ArvAVL *raiz){
	
	int tamanho, valor, res, i;
	printf("    Quantos dados gostaria de adicionar: ");
	scanf("%d", &tamanho);

	printf("    Digite os dados que serao adicinados na arvore: ");
    for(i = 0; i < tamanho; i++){
		scanf("%d", &valor);
        res = insere_ArvAVL(raiz, valor);
        if(res == 0){
        	printf("   [Valor Duplicado] Esse dado --> [%d] ja esta na lista!\n", valor);
		}
    } 
}

void removerDado(ArvAVL *raiz){
	
	int qtd, dado, i, res;
	printf("    Digite quantos dados voce quer remover: ");
	scanf("%d", &qtd);
	
	printf("    Digite os dados que serao removidos da arvore: ");
    for(i = 0; i < qtd; i++){
    	scanf("%d", &dado);
        res = remove_ArvAVL(raiz, dado);
    }
}

void printarOrdens(ArvAVL *raiz){
	
	printf("\n\n    ---- AVL EM PRE ORDEM: ----\n");
    preOrdem_ArvAVL(raiz);
    
    printf("\n\n    ---- AVL EM ORDEM: ----\n");
    emOrdem_ArvAVL(raiz);
    
    printf("\n\n    ---- AVL EM POS ORDEM: ----\n");
    posOrdem_ArvAVL(raiz);
    printf("\n\n");
}

void verificaVazia(ArvAVL *raiz){
	
	printf("\n    ... Verificando se arvore esta vazia ...\n");
	
	int vazia = estaVazia_ArvAVL(raiz);
	
	if(vazia == 1){
		printf("\n    A ARVORE ESTA VAZIA!\n\n");
	} else printf("\n    A ARVORE NAO ESTA VAZIA!\n\n");
}

void verificaDado(ArvAVL *raiz){
	
	int procurar;
	printf("    Qual dado vc quer procurar? ");
	scanf("%d", &procurar);
	int estaNaArvore = consulta_ArvAVL(raiz, procurar);
	if(estaNaArvore == 1){
		printf("\n    O DADO --> [%d] ESTA NA ARVORE!\n\n", procurar);
	}else printf("\n    O DADO --> [%d] NAO ESTA NA ARVORE!\n\n", procurar);
}

void quantidadeNos(ArvAVL *raiz){
	int totalNo = totalNO_ArvAVL(raiz);
	printf("\n\n    A arvore tem no total --> [%d] nos!\n\n", totalNo);
}

void alturaArvore(ArvAVL *raiz){
	int altura = altura_ArvAVL(raiz);
	printf("\n\n    A altura da arvore eh --> [%d]!\n\n", altura);
}

void menus(ArvAVL *raiz, int op){
	
	switch(op){
		
		// adicionar dado na arvore
		case 1:
			adicionarDado(raiz);
			printf("    ");
			printarOrdens(raiz);
			break;
			
		// remover dado da arvore
		case 2:
			removerDado(raiz);
			printf("    ");
			printarOrdens(raiz);
			break;
			
		// verifica se esta vazia
		case 3:
			verificaVazia(raiz);
			break;
		
		// verificar se algum dado esta na arvore
		case 4:
			verificaDado(raiz);
			break;
			
		// quantidade de nos na arvore
		case 5:
			quantidadeNos(raiz);
			break;
		
		// dizer qual é a altura da arvore
		case 6:
			alturaArvore(raiz);
			break;
		
		// printar as ordens da arvore
		case 7:
			printarOrdens(raiz);
			break;
			
		// sair do programa
		case 0:
			printf("\n\n    ... ADIOS AMUIGO...\n\n");
			libera_ArvAVL(raiz);
			break;
			
		// comando invalido
		default:
			printf("    Digite um comando valido!\n");
	}	
}



