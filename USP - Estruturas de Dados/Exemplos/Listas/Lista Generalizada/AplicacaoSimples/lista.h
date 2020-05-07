typedef char elem;

typedef struct bloco {
        union {
              elem atomo;
              struct bloco *sublista;
        } info;
        int tipo;
        struct bloco *prox;
}no;

typedef struct {
        no *ini;
}LISTA;


int esta_na_lista_principal(LISTA *L, elem *x);
int esta_em_qualquer_parte_da_lista(no *p, elem *x);
int iguais(no *L1, no *L2);
int iguais_estruturalmente(no *L1, no *L2);
int profundidade(no *p);
int vazia(LISTA *lista);


void percorreLista(no *aux);
LISTA *cria(int *erro);
void push(LISTA *lista, int valor, int *erro, int tipo, int adicionarOnde);
void pop(LISTA *lista, int *saida, int *erro);
int tamanho(LISTA *lista);
