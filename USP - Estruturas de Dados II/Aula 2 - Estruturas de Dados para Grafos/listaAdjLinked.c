#include <stdio.h>
#include <stdlib.h>

// o grafo consiste de vértices, numerados de 0, v-1
// vamos assumir que são designados por valores inteiros.
#define Vertex int

// um nó da lista de adjacencia.. veja figura..
// para fins de visualizacao, vamos nos referir a este vértice como w (v -> w)
typedef struct node{
	Vertex w;
	struct node *prox;
} Node;

typedef struct adj{
	Vertex v;
	Node *pnode;
	struct adj *prox;
} Adj;

// o (Di)Grafo armazena o nro de vertices, o nro de arestas (opcional) e claro
// um ponteiro para a lista de adjacencia...
typedef struct graph{
	int nVert;
	int nEdge;
    Adj *adj;
}Graph;


// voce agora pode completar o seu TAD com várias funções.
// seria interessante separa implementacao da especificação
// .h e .c

Graph initGraph(int nVert){
	Graph g;
	g.nVert = nVert;
	Adj *p, *pant;
	// cria a lista ligada de adjacencia....
	for (int i = 0; i < g.nVert; ++i)
	{
		pant = p;
		p = (Adj *)malloc(sizeof(Adj));
		p->v = i;
		p->pnode = NULL;
		p->prox = NULL;
		if (i == 0) 
			g.adj = p;
		else {
			pant->prox = p;
		}
	}


	return g;
}

// insere um arco (aresta) v, w em g ao final da lista...
void addArc(Graph *g, Vertex v, Vertex w){
	Adj *pv;
	Node *pw;

	if (v<0 || v>=g->nVert || w<0 || w>=g->nVert){
		printf("v e/ou w nao tem valores validos...\n");
		return;
	}
	// encontra o vertice v em adj...
	pv = g->adj;
	for (int i = 0; i < v; ++i)
		pv = pv->prox;
	pw = pv->pnode;

	if (pw == NULL){ //é a primeira aresta partindo de v
		pw = (Node *)malloc(sizeof(Node));
		pw->prox = NULL;
		pw->w = w;
		pv->pnode = pw;
	} else {   // encontra o ultimo elemento da lista
		while (pw->prox != NULL) 
			pw = pw->prox;
		pw->prox = (Node *)malloc(sizeof(Node));
		pw->prox->w = w;
		pw->prox->prox = NULL;
	}
	

}

void printGraph(Graph g){
	Adj *pv = g.adj;
	Node *pw;
	// para todos os vertices...
	while(pv != NULL)
	{	
		printf("%d ->> ", pv->v);
		pw = pv->pnode;
		while(pw != NULL){
			printf("%d ", pw->w);
			pw = pw->prox;
		}
		pv = pv->prox;
		printf("\n");
	}
}

int main(int argc, char const *argv[])
{
	/* code */
	int nVert;
	Vertex v1,v2;

	scanf("%d\n", &nVert);
	Graph g = initGraph(nVert);


	//addArc(g,0,1);
	while (scanf("%d %d\n", &v1, &v2)  != EOF){
	  addArc(&g,v1,v2);
	  // para utilizar esta estrutura para grafo, basta chamar..
	  addArc(&g,v2,v1);
	}

	printGraph(g);


	return 0;
}

