#include <stdio.h>
#include <stdlib.h>

//https://www.youtube.com/watch?v=rcDF8IqTnyI

typedef struct NO* ArvLLRB;

ArvLLRB* cria_ArvLLRB();
void libera_ArvLLRB(ArvLLRB* raiz);
int insere_ArvLLRB(ArvLLRB* raiz,int valor);
int remove_ArvLLRB(ArvLLRB *raiz, int valor);
int estaVazia_ArvLLRB(ArvLLRB *raiz);
int totalNO_ArvLLRB(ArvLLRB *raiz);
int altura_ArvLLRB(ArvLLRB *raiz);
int consulta_ArvLLRB(ArvLLRB *raiz, int valor);
void preOrdem_ArvLLRB(ArvLLRB *raiz, int H);
void emOrdem_ArvLLRB(ArvLLRB *raiz, int H);
void posOrdem_ArvLLRB(ArvLLRB *raiz, int H);

void menu();
void menus(ArvLLRB *raiz, int op);
void adicionarDados(ArvLLRB *raiz);
void verificarVazia(ArvLLRB *raiz);
void removerDados(ArvLLRB *raiz);
void verificarAltura(ArvLLRB *raiz);
void quantidadeNos(ArvLLRB *raiz);
void verificarDado(ArvLLRB *raiz);
void printarOrdens(ArvLLRB *raiz);

#define RED 1
#define BLACK 0

struct NO{
    int info;
    struct NO *esq;
    struct NO *dir;
    int cor;
};

ArvLLRB* cria_ArvLLRB(){
    ArvLLRB* raiz = (ArvLLRB*) malloc(sizeof(ArvLLRB));
    if(raiz != NULL){
        *raiz = NULL;
    }
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

void libera_ArvLLRB(ArvLLRB* raiz){
    if(raiz == NULL)
        return;
    libera_NO(*raiz);//libera cada nó
    free(raiz);//libera a raiz
}

int consulta_ArvLLRB(ArvLLRB *raiz, int valor){
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

struct NO* rotacionaEsquerda(struct NO* A){
    struct NO* B = A->dir;
    A->dir = B->esq;
    B->esq = A;
    B->cor = A->cor;
    A->cor = RED;
    return B;
}

struct NO* rotacionaDireita(struct NO* A){
    struct NO* B = A->esq;
    A->esq = B->dir;
    B->dir = A;
    B->cor = A->cor;
    A->cor = RED;
    return B;
}

int cor(struct NO* H){
    if(H == NULL)
        return BLACK;
    else
        return H->cor;
}

void trocaCor(struct NO* H){
    H->cor = !H->cor;
    if(H->esq != NULL)
        H->esq->cor = !H->esq->cor;
    if(H->dir != NULL)
        H->dir->cor = !H->dir->cor;
}

struct NO* insereNO(struct NO* H, int valor, int *resp){
    if(H == NULL){
        struct NO *novo;
        novo = (struct NO*)malloc(sizeof(struct NO));
        if(novo == NULL){
            *resp = 0;
            return NULL;
        }

        novo->info = valor;
        novo->cor = RED;
        novo->dir = NULL;
        novo->esq = NULL;
        *resp = 1;
        return novo;
    }

    if(valor == H->info)
        *resp = 0;// Valor duplicado
    else{
        if(valor < H->info)
            H->esq = insereNO(H->esq,valor,resp);
        else
            H->dir = insereNO(H->dir,valor,resp);
    }

    //nó Vermelho é sempre filho à esquerda
    if(cor(H->dir) == RED && cor(H->esq) == BLACK)
        H = rotacionaEsquerda(H);

    //Filho e Neto são vermelhos
    //Filho vira pai de 2 nós vermelhos
    if(cor(H->esq) == RED && cor(H->esq->esq) == RED)
        H = rotacionaDireita(H);

    //2 filhos Vermelhos: troca cor!
    if(cor(H->esq) == RED && cor(H->dir) == RED)
        trocaCor(H);

    return H;
}

int insere_ArvLLRB(ArvLLRB* raiz, int valor){
    int resp;

    *raiz = insereNO(*raiz,valor,&resp);
    if((*raiz) != NULL)
        (*raiz)->cor = BLACK;

    return resp;
}

struct NO* balancear(struct NO* H){
    //nó Vermelho é sempre filho à esquerda
    if(cor(H->dir) == RED)
        H = rotacionaEsquerda(H);

    //Filho da direita e neto da esquerda são vermelhos
    if(H->esq != NULL && cor(H->dir) == RED && cor(H->esq->esq) == RED)
        H = rotacionaDireita(H);

    //2 filhos Vermelhos: troca cor!
    if(cor(H->esq) == RED && cor(H->dir) == RED)
        trocaCor(H);

    return H;
}

struct NO* move2EsqRED(struct NO* H){
    trocaCor(H);
    if(cor(H->dir->esq) == RED){
        H->dir = rotacionaDireita(H->dir);
        H = rotacionaEsquerda(H);
        trocaCor(H);
    }
    return H;
}

struct NO* move2DirRED(struct NO* H){
    trocaCor(H);
    if(cor(H->esq->esq) == RED){
        H = rotacionaDireita(H);
        trocaCor(H);
    }
    return H;
}

struct NO* removerMenor(struct NO* H){
    if(H->esq == NULL){
        free(H);
        return NULL;
    }
    if(cor(H->esq) == BLACK && cor(H->esq->esq) == BLACK)
        H = move2EsqRED(H);

    H->esq = removerMenor(H->esq);
    return balancear(H);
}

// tirei a recursão, assim fica igual a usada na AVL
struct NO* procuraMenor(struct NO* atual){
    struct NO *no1 = atual;
    struct NO *no2 = atual->esq;
    while(no2 != NULL){
        no1 = no2;
        no2 = no2->esq;
    }
    return no1;
}

struct NO* remove_NO(struct NO* H, int valor){
    if(valor < H->info){
        if(cor(H->esq) == BLACK && cor(H->esq->esq) == BLACK)
            H = move2EsqRED(H);

        H->esq = remove_NO(H->esq, valor);
    }else{
        if(cor(H->esq) == RED)
            H = rotacionaDireita(H);

        if(valor == H->info && (H->dir == NULL)){
            free(H);
            return NULL;
        }

        if(cor(H->dir) == BLACK && cor(H->dir->esq) == BLACK)
            H = move2DirRED(H);

        if(valor == H->info){
            struct NO* x = procuraMenor(H->dir);
            H->info = x->info;
            H->dir = removerMenor(H->dir);
        }else
            H->dir = remove_NO(H->dir, valor);
    }
    return balancear(H);
}

int remove_ArvLLRB(ArvLLRB *raiz, int valor){
    if(consulta_ArvLLRB(raiz,valor)){
        struct NO* h = *raiz;
        *raiz = remove_NO(h,valor);
        if(*raiz != NULL)
            (*raiz)->cor = BLACK;
        return 1;
    }else
        return 0;
}

int estaVazia_ArvLLRB(ArvLLRB *raiz){
    if(raiz == NULL)
        return 1;
    if(*raiz == NULL)
        return 1;
    return 0;
}

int totalNO_ArvLLRB(ArvLLRB *raiz){
    if (raiz == NULL)
        return 0;
    if (*raiz == NULL)
        return 0;

    int alt_esq = totalNO_ArvLLRB(&((*raiz)->esq));
    int alt_dir = totalNO_ArvLLRB(&((*raiz)->dir));
    return (alt_esq + alt_dir + 1);
}

int altura_ArvLLRB(ArvLLRB *raiz){
    if (raiz == NULL)
        return 0;
    if (*raiz == NULL)
        return 0;
    int alt_esq = altura_ArvLLRB(&((*raiz)->esq));
    int alt_dir = altura_ArvLLRB(&((*raiz)->dir));
    if (alt_esq > alt_dir)
        return (alt_esq + 1);
    else
        return(alt_dir + 1);
}

void  posOrdem_ArvLLRB(ArvLLRB *raiz, int H){
    if(raiz == NULL)
        return;

    if(*raiz != NULL){
        posOrdem_ArvLLRB(&((*raiz)->esq),H+1);
        posOrdem_ArvLLRB(&((*raiz)->dir),H+1);

        if((*raiz)->cor == RED)
            printf("    %d --> Cor: Vermelho --> Altura: [%d] \n",(*raiz)->info,H);
        else
            printf("    %d --> Cor: Vermelho --> Altura: [%d] \n",(*raiz)->info,H);

    }
}

void emOrdem_ArvLLRB(ArvLLRB *raiz, int H){
    if(raiz == NULL)
        return;

    if(*raiz != NULL){
        emOrdem_ArvLLRB(&((*raiz)->esq),H+1);

        if((*raiz)->cor == RED)
            printf("    %d --> Cor: Vermelho --> Altura: [%d] \n",(*raiz)->info,H);
        else
            printf("    %d --> Cor: Vermelho --> Altura: [%d] \n",(*raiz)->info,H);

        emOrdem_ArvLLRB(&((*raiz)->dir),H+1);
    }
}

void preOrdem_ArvLLRB(ArvLLRB *raiz, int H){
    if(raiz == NULL)
        return;

    if(*raiz != NULL){
        if((*raiz)->cor == RED)
            printf("    %d --> Cor: Vermelho --> Altura: [%d] \n",(*raiz)->info,H);
        else
            printf("    %d --> Cor: Vermelho --> Altura: [%d] \n",(*raiz)->info,H);

        preOrdem_ArvLLRB(&((*raiz)->esq),H+1);
        preOrdem_ArvLLRB(&((*raiz)->dir),H+1);
    }
}

int main(){
	
    ArvLLRB * raiz = cria_ArvLLRB();
    //https://www.youtube.com/watch?v=rcDF8IqTnyI
    
    printf("    --- Welcome to The Rubro Negro Ranch :) ---\n\n");
    
	int op;
	
    do{
    	menu();
    	scanf("%d", &op);
    	menus(raiz, op);
	}while(op != 0);

    return 0;
}

void adicionarDados(ArvLLRB *raiz){
	
	int qtd, valor, i;
	printf("    Digite quantidade de dados que vao ser adicionados: ");
	scanf("%d", &qtd);
	
	printf("    Digite os dados que vao ser adicionados: ");
	for(i=0; i< qtd; i++){
		scanf("%d", &valor);
        insere_ArvLLRB(raiz, valor);
    }
}

void removerDados(ArvLLRB *raiz){
	
	int qtd, valor, i;
	printf("    Digite quantidade de dados que vao ser removidos: ");
	scanf("%d", &qtd);
	
	printf("    Digite os dados que vao ser removidos: ");
	for(i=0; i< qtd; i++){
		scanf("%d", &valor);
        remove_ArvLLRB(raiz, valor);
    }
}

void printarOrdens(ArvLLRB *raiz){

    int altura = altura_ArvLLRB(raiz);

    printf("\n\n    	--- ARVORE EM PRE-ORDEM ---\n\n");
    preOrdem_ArvLLRB(raiz, altura);
    printf("\n\n    	--- ARVORE EM ORDEM ---\n\n");
    emOrdem_ArvLLRB(raiz, altura);
    printf("\n\n    	--- ARVORE EM POS-ORDEM ---\n\n");
    posOrdem_ArvLLRB(raiz, altura);
    printf("\n\n");
}

void verificarDado(ArvLLRB *raiz){
	
	int res, valor;
	printf("     Digite qual dado voce quer verificar: ");
	scanf("%d", &valor);
	
	res = consulta_ArvLLRB(raiz,valor);
	if(res == 1){
		printf("\n\n    O dado --> [%d] esta na arvore!\n\n", valor);
	}
	else{
		printf("\n\n    O dado --> [%d] NAO esta na arvore!\n\n", valor);
	}
}

void verificarAltura(ArvLLRB *raiz){
	
	int altura = altura_ArvLLRB(raiz);
	printf("\n\n    A altura da arvore eh --> [%d]\n\n", altura);
}

void quantidadeNos(ArvLLRB *raiz){
	
	int qtd = totalNO_ArvLLRB(raiz);
	printf("\n\n    A arvore tem no total --> [%d] nos!\n\n", qtd);
}

void verificarVazia(ArvLLRB *raiz){
	
	int vazia = estaVazia_ArvLLRB(raiz);
	if(vazia){
		printf("\n    A ARVORE ESTA VAZIA!\n\n");
	}
	else{
		printf("\n    A ARVORE NAO ESTA VAZIA!\n\n");
	}
}

void menu(){
	printf("    Digite [1] --> Para adicionar dado na arvore\n");
	printf("    Digite [2] --> Para remover dado na arvore\n");
	printf("    Digite [3] --> Para verificar dado na arvore\n");
	printf("    Digite [4] --> Para verificar altura da arvore\n");
	printf("    Digite [5] --> Para verificar quantidade de nos da arvore\n");
	printf("    Digite [6] --> Para verificar se arvore esta vazia\n");
	printf("    Digite [7] --> Para printar ordens da arvore\n");
	printf("\n    Digite [0] --> SAIR\n");
	printf("    Opcao:");
}

void menus(ArvLLRB *raiz, int op){

	switch(op){
		
		case 1:
			adicionarDados(raiz);
			printarOrdens(raiz);
			break;
		
		case 2:
			removerDados(raiz);
			printarOrdens(raiz);
			break;
		
		case 3:
			verificarDado(raiz);
			break;
		
		case 4:
			verificarAltura(raiz);
			break;
		
		case 5:
			quantidadeNos(raiz);
			break;
		
		case 6:
			verificarVazia(raiz);
			break;
		
		case 7:
			printarOrdens(raiz);
			break;
		
		case 0:
			printf("    ADIOS AMUIGO!\n");
			break;
			
		default:
			printf("    Digite um comando válido!\n");
			break;			
	}
}

