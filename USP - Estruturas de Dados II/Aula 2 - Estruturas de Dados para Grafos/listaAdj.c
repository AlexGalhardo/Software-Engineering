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


int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}

