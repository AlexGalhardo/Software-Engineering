#include <stdio.h>
#include <stdlib.h>

#define N_Nos 5

typedef struct no{
	int origem;
	int destino;
	int peso;
	struct no *prox;
}NO;

typedef struct lista{
	NO *inicio;
	int tam;
}LISTA;

typedef struct grafo{
	LISTA *lista;
}GRAFO;

NO *criar_no(int id, int destino, int peso);
LISTA *criar_lista();
GRAFO *criar_grafo();
void inserir_aresta(LISTA *l, int id, int destino, int peso);
int vazia(LISTA *l);
void imprimir_lista(LISTA *l);
void imprimir_grafo(GRAFO *g, int i);
void liberar_grafo(GRAFO *g);
int get_id_menor_peso(LISTA *l, int *custo);

int main(){
	GRAFO *g = criar_grafo();
	inserir_aresta(g[0].lista, 0, 1, 35);
	inserir_aresta(g[0].lista, 0, 2, 40);
	inserir_aresta(g[1].lista, 1, 2, 25);
	inserir_aresta(g[1].lista, 1, 3, 10);
	inserir_aresta(g[2].lista, 2, 4, 15);
	inserir_aresta(g[3].lista, 3, 2, 20);
	inserir_aresta(g[3].lista, 3, 4, 30);

	printf("Grafo\n");
	for(int i = 0; i < N_Nos; i++){
		imprimir_grafo(g, i);
	}

	int origem = 0;
	int destino = 4;
	int custo = 0;

	printf("Caminho: \n");
	printf("%d ", origem+1);
	while(origem != destino){
		origem = get_id_menor_peso(g[origem].lista, &custo);
		printf("%d ", origem+1);
	}
	printf("\n");
	printf("Custo: %d\n", custo);

	liberar_grafo(g);
	return 0;
}

NO *criar_no(int id, int destino, int peso){
	NO *n = (NO *)malloc(sizeof(NO));
	if(n != NULL){
		n->origem = id;
		n->destino = destino;
		n->peso = peso;
		n->prox = NULL;
	}
	return n;
}

LISTA *criar_lista(){
	LISTA *l = (LISTA *)malloc(sizeof(LISTA));
	if(l != NULL){
		l->inicio = NULL;
		l->tam = 0;
	}
	return l;
}

GRAFO *criar_grafo(){
	GRAFO *g = (GRAFO *)malloc(sizeof(GRAFO) * N_Nos);
	for(int i = 0; i < N_Nos; i++){
		g[i].lista = criar_lista();
	}
	return g;
}

void inserir_aresta(LISTA *l, int id, int destino, int peso){
	NO *n = criar_no(id, destino, peso);
	if(n != NULL){
		if(vazia(l)){
			l->inicio = n;
		}else{
			n->prox = l->inicio;
			l->inicio = n;
		}
		l->tam++;
	}
}

int vazia(LISTA *l){
	return(l->inicio == NULL);
}

void imprimir_lista(LISTA *l){
	if(!vazia(l)){
		NO *p = l->inicio;
		while(p != NULL){
			printf("%d(%d) ", p->destino+1, p->peso);
			p = p->prox;
		}
	}
}

void imprimir_grafo(GRAFO *g, int i){
	printf("[%d] -> ", i+1);
	imprimir_lista(g[i].lista);
	printf("\n");
}

void liberar_grafo(GRAFO *g){
	int i;
	for(i = 0; i < N_Nos; i++){
		free(g[i].lista);
	}
	free(g);
}

int get_id_menor_peso(LISTA *l, int *custo){
	if(!vazia(l)){
		int menor_peso = l->inicio->peso;
		NO *p = l->inicio;
		int destino = p->destino;
		while(p != NULL){
			if(l->tam == 1){
				*custo += p->peso;
				return p->destino;
			}
			if(menor_peso > p->peso){
				menor_peso = p->peso;
				destino = p->destino;
			}
			p = p->prox;
		}
		*custo += menor_peso;
		return destino;
	}
	return -1;
}
