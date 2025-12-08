#include <stdio.h>
#include <stdlib.h>

// o grafo consiste de vértices, numerados de 0, v-1
// vamos assumir que são designados por valores inteiros.
#define Vertex int


// o (Di)Grafo armazena o nro de vertices, o nro de arestas (opcional) e claro
// um ponteiro para a lista de adjacencia...
typedef struct graph{
	int nVert;
	int nEdge;
    Vertex **matAdj;
}Graph;


// voce agora pode completar o seu TAD com várias funções.
// seria interessante separa implementacao da especificação
// .h e .c

Graph initGraph(int nVert){
	Graph g;
	g.nVert = nVert;
	g.matAdj = (Vertex **) malloc(g.nVert * sizeof(Vertex *));
	for (int i = 0; i < g.nVert; ++i)
		g.matAdj[i] = (Vertex *) malloc(g.nVert * sizeof(Vertex));
	for (int i = 0; i < g.nVert; ++i)
		for (int j = 0; j < g.nVert; ++j)
			g.matAdj[i][j] = 0;
	   
	return g;
}

// insere um arco (aresta) v, w em g ao final da lista...
void addArc(Graph *g, Vertex v, Vertex w){
	struct node *pv;

	if (v<0 || v>=g->nVert || w<0 || w>=g->nVert){
		printf("v e/ou w nao tem valores validos...\n");
		return;
	}
	g->matAdj[v][w] = 1;
}

void printGraph(Graph g){
	struct node *p;
	// para todos os vertices...
	for (int i = 0; i < g.nVert; ++i) {
		for (int j = 0; j < g.nVert; ++j)
		    printf("%5d", g.matAdj[i][j]);	
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
	  //addArc(g,v2,v1);
	}

	printGraph(g);


	return 0;
}

