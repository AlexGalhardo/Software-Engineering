#include <stdio.h>
#include <stdlib.h>

typedef struct NO* ArvBin;

ArvBin* cria_ArvBin();
void libera_ArvBin(ArvBin *raiz);
int insere_ArvBin(ArvBin* raiz, int valor);
int remove_ArvBin(ArvBin *raiz, int valor);
int estaVazia_ArvBin(ArvBin *raiz);
int altura_ArvBin(ArvBin *raiz);
int totalNO_ArvBin(ArvBin *raiz);
int consulta_ArvBin(ArvBin *raiz, int valor);
void preOrdem_ArvBin(ArvBin *raiz);
void emOrdem_ArvBin(ArvBin *raiz);
void posOrdem_ArvBin(ArvBin *raiz);

void adicionarDado(ArvBin *raiz);
void menus(ArvBin *raiz, int op);
void alturaArvore(ArvBin *raiz);
void adicionarDado(ArvBin *raiz);
void removerDado(ArvBin *raiz);
void printarOrdens(ArvBin *raiz);
void verificaVazia(ArvBin *raiz);
void verificaDado(ArvBin *raiz);
void quantidadeNos(ArvBin *raiz);
void menu();

struct NO{
    int info;
    struct NO *esq;
    struct NO *dir;
};

ArvBin* cria_ArvBin(){
    ArvBin* raiz = (ArvBin*) malloc(sizeof(ArvBin));
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

void libera_ArvBin(ArvBin* raiz){
    if(raiz == NULL)
        return;
    libera_NO(*raiz);//libera cada nó
    free(raiz);//libera a raiz
}

int insere_ArvBin(ArvBin* raiz, int valor){
    if(raiz == NULL)
        return 0;
    struct NO* novo;
    novo = (struct NO*) malloc(sizeof(struct NO));
    if(novo == NULL)
        return 0;
    novo->info = valor;
    novo->dir = NULL;
    novo->esq = NULL;

    if(*raiz == NULL)
        *raiz = novo;
    else{
        struct NO* atual = *raiz;
        struct NO* ant = NULL;
        while(atual != NULL){
            ant = atual;
            /*
            if(valor == atual->info){
                free(novo);
                return 0;//elemento já existe
            }
			*/
			
            if(valor >= atual->info)
                atual = atual->dir;
            else
                atual = atual->esq;
        }
        if(valor > ant->info)
            ant->dir = novo;
        else
            ant->esq = novo;
    }
    return 1;
}

struct NO* remove_atual(struct NO* atual) {
    struct NO *no1, *no2;
    if(atual->esq == NULL){
        no2 = atual->dir;
        free(atual);
        return no2;
    }
    no1 = atual;
    no2 = atual->esq;
    while(no2->dir != NULL){
        no1 = no2;
        no2 = no2->dir;
    }
    // no2 é o nó anterior a r na ordem e-r-d
    // no1 é o pai de no2
    if(no1 != atual){
        no1->dir = no2->esq;
        no2->esq = atual->esq;
    }
    no2->dir = atual->dir;
    free(atual);
    return no2;
}
// http://www.ime.usp.br/~pf/algoritmos/aulas/binst.html
int remove_ArvBin(ArvBin *raiz, int valor){
    if(raiz == NULL)
        return 0;
    struct NO* ant = NULL;
    struct NO* atual = *raiz;
    while(atual != NULL){
        if(valor == atual->info){
            if(atual == *raiz)
                *raiz = remove_atual(atual);
            else{
                if(ant->dir == atual)
                    ant->dir = remove_atual(atual);
                else
                    ant->esq = remove_atual(atual);
            }
            return 1;
        }
        ant = atual;
        if(valor > atual->info)
            atual = atual->dir;
        else
            atual = atual->esq;
    }
    return 0;
}

int estaVazia_ArvBin(ArvBin *raiz){
    if(raiz == NULL)
        return 1;
    if(*raiz == NULL)
        return 1;
    return 0;
}

int totalNO_ArvBin(ArvBin *raiz){
    if (raiz == NULL)
        return 0;
    if (*raiz == NULL)
        return 0;
    int alt_esq = totalNO_ArvBin(&((*raiz)->esq));
    int alt_dir = totalNO_ArvBin(&((*raiz)->dir));
    return(alt_esq + alt_dir + 1);
}

int altura_ArvBin(ArvBin *raiz){
    if (raiz == NULL)
        return 0;
    if (*raiz == NULL)
        return 0;
    int alt_esq = altura_ArvBin(&((*raiz)->esq));
    int alt_dir = altura_ArvBin(&((*raiz)->dir));
    if (alt_esq > alt_dir)
        return (alt_esq + 1);
    else
        return(alt_dir + 1);
}

int consulta_ArvBin(ArvBin *raiz, int valor){
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

void preOrdem_ArvBin(ArvBin *raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
    	printf("    ");
        printf("%d ",(*raiz)->info);
        preOrdem_ArvBin(&((*raiz)->esq));
        preOrdem_ArvBin(&((*raiz)->dir));
    }
}

void emOrdem_ArvBin(ArvBin *raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        emOrdem_ArvBin(&((*raiz)->esq));
        printf("    ");
        printf("%d ",(*raiz)->info);
        emOrdem_ArvBin(&((*raiz)->dir));
    }
}

void posOrdem_ArvBin(ArvBin *raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        posOrdem_ArvBin(&((*raiz)->esq));
        posOrdem_ArvBin(&((*raiz)->dir));
        printf("    ");
        printf("%d ",(*raiz)->info);
    }
}


int main(){
	
	printf("    --- WELCOME TO BINARY ARVORES RANCH ---\n\n");

    ArvBin* raiz = cria_ArvBin();
	
	int op;
    
	do{
		menu();
		scanf("%d", &op);
		menus(raiz, op);
	}while(op!=0);
    
    return 0;
}

void menus(ArvBin *raiz, int op){
	
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
			libera_ArvBin(raiz);
			break;
			
		// comando invalido
		default:
			printf("    Digite um comando valido!\n");
	}	
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

void adicionarDado(ArvBin *raiz){
	
	int tamanho, valor, res, i;
	printf("    Quantos dados gostaria de adicionar: ");
	scanf("%d", &tamanho);

	printf("    Digite os dados que serao adicionados na arvore: ");
    for(i = 0; i < tamanho; i++){
		scanf("%d", &valor);
        res = insere_ArvBin(raiz, valor);
        if(res == 0){
        	printf("   [Valor Duplicado] Esse dado --> [%d] ja esta na lista!\n", valor);
		}
    } 
}

void removerDado(ArvBin *raiz){
	
	int qtd, dado, i, res;
	printf("    Digite quantos dados voce quer remover: ");
	scanf("%d", &qtd);
	
	printf("    Digite os dados que serao removidos da arvore: ");
    for(i = 0; i < qtd; i++){
    	scanf("%d", &dado);
        res = remove_ArvBin(raiz, dado);
    }
}

void printarOrdens(ArvBin *raiz){
	
	printf("\n\n    ---- BINARIA EM PRE ORDEM: ----\n");
    preOrdem_ArvBin(raiz);
    
    printf("\n\n    ---- BINARIA EM ORDEM: ----\n");
    emOrdem_ArvBin(raiz);
    
    printf("\n\n    ---- BINARIA EM POS ORDEM: ----\n");
    posOrdem_ArvBin(raiz);
    printf("\n\n");
}

void verificaVazia(ArvBin *raiz){
	
	printf("\n    ... Verificando se arvore esta vazia ...\n");
	
	int vazia = estaVazia_ArvBin(raiz);
	
	if(vazia == 1){
		printf("\n    A ARVORE ESTA VAZIA!\n\n");
	} else printf("\n    A ARVORE NAO ESTA VAZIA!\n\n");
}

void verificaDado(ArvBin *raiz){
	
	int procurar;
	printf("    Qual dado vc quer procurar? ");
	scanf("%d", &procurar);
	int estaNaArvore = consulta_ArvBin(raiz, procurar);
	if(estaNaArvore == 1){
		printf("\n    O DADO --> [%d] ESTA NA ARVORE!\n\n", procurar);
	}else printf("\n    O DADO --> [%d] NAO ESTA NA ARVORE!\n\n", procurar);
}

void quantidadeNos(ArvBin *raiz){
	int totalNo = totalNO_ArvBin(raiz);
	printf("\n\n    A arvore tem no total --> [%d] nos!\n\n", totalNo);
}

void alturaArvore(ArvBin *raiz){
	int altura = altura_ArvBin(raiz);
	printf("\n\n    A altura da arvore eh --> [%d]!\n\n", altura);
}


