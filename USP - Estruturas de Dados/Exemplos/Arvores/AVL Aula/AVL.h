//declaração do nó da árvore
typedef int elem;

typedef struct bloco {
        elem info;
        int fb;
        struct bloco *esq, *dir;
} no;

typedef struct {
        no *raiz;
} AVL;


//protótipos das funções
void criar(AVL*);
void finalizar(no**);
void imprimir(no**);
int inserir(no**,int*);
int buscar(no**,int*);
