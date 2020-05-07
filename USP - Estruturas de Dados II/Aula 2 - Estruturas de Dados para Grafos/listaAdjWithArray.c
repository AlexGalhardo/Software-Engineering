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

// o (Di)Grafo armazena o nro de vertices, o nro de arestas (opcional) e claro
// um ponteiro para a lista de adjacencia...
typedef struct graph{
	int nVert;
	int nEdge;
    struct node **adj;
}Graph;


// voce agora pode completar o seu TAD com várias funções.
// seria interessante separa implementacao da especificação
// .h e .c

Graph initGraph(int nVert){
	Graph g;
	g.nVert = nVert;
	g.adj = (struct node **)malloc(sizeof(struct node *)*nVert);
	for (int i = 0; i < g.nVert; ++i)
	{
		g.adj[i] = NULL;
	}

	return g;
}

// insere um arco (aresta) v, w em g ao final da lista...
void addArc(Graph *g, Vertex v, Vertex w){
	struct node *pv;

	if (v<0 || v>=g->nVert || w<0 || w>=g->nVert){
		printf("v e/ou w nao tem valores validos...\n");
		return;
	}
	pv = g->adj[v];
	if (pv == NULL){ //é a primeira aresta partindo de v
		g->adj[v] = (struct node *)malloc(sizeof(struct node));
		g->adj[v]->prox = NULL;
		g->adj[v]->w = w;
	} else {   // encontra o ultimo elemento da lista
		while (pv->prox != NULL) 
			pv = pv->prox;
		pv->prox = (struct node *)malloc(sizeof(struct node));
		pv->prox->w = w;
		pv->prox->prox = NULL;
	}
	

}

void printGraph(Graph g){
	struct node *p;
	// para todos os vertices...
	for (int i = 0; i < g.nVert; ++i)
	{	
		p = g.adj[i];
		printf("%d ->> ", i);
		while(p != NULL){
			printf("%d ", p->w);
			p = p->prox;
		}
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

