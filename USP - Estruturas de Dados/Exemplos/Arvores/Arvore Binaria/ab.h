typedef int elem;

typedef struct bloco {
        elem info;
        struct bloco *esq, *dir;
} no;

typedef struct {
        no *raiz;
} Arvore;

void cria(Arvore*);
int IsEmpty(Arvore*);
no* busca(no*,elem*);
no* busca_pai(no*,elem*);
void inserir_esq(Arvore*,elem*,elem*,int*);
void inserir_dir(Arvore*,elem*,elem*,int*);
void imprimir(no*);
int altura(no*);
void finaliza(no*);
void remover(Arvore*,elem*,int*);
void percurso_pre_ordem(no*);
void percurso_em_ordem(no*);
void percurso_pos_ordem(no*);
int espelho_similares(no*,no*);
