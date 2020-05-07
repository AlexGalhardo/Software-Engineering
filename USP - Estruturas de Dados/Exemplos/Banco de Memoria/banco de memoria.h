#define TAM 10

typedef int elem;

typedef struct {
        elem info;
        int prox;
} no;

typedef struct {
        int ini, fim, primeiro_vazio;
        no itens[TAM];
} Banco;

void cria(Banco*);
void getnode(Banco*,int*);
void freenode(Banco*,int*);
int EstaVazio(Banco*);
int EstaCheio(Banco*);
void inserir_no_comeco(Banco*,elem*,int*);
void retirar_do_comeco(Banco*,elem*,int*);
void inserir_no_fim(Banco*,elem*,int*);
