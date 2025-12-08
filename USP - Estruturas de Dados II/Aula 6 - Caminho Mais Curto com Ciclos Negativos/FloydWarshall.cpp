#include <vector>
#include <queue>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#define VISITED 1
#define UNVISITED 0
#define INF 100
#define TRUE 1
#define FALSE 0

using namespace std;


/*
Vamos fazer uma estrutura de dados usando a classe STL vector..
Esta estrutura considera que o grafo é ponderado, ou seja, tem
um peso.....
*/

#define Vertex int

typedef pair<Vertex,Vertex> ii; // primeiro elemento = vertice w; segundo elem= peso
typedef vector<ii> vii;   // um vetor de pares <w,peso> ...
typedef vector<Vertex> vi;

// o grafo consiste de vértices, numerados de 0, v-1
// vamos assumir que são designados por valores inteiros.



// Para manter a compatibilidade com o que vimos fazendo, podemos definir uma estrutura
// Graph.
typedef struct graph{
	int nVert;
	int nEdge;
	int peso;
    Vertex **matAdj;
}Graph;


// Inicia o grafo com valores infinitos...
Graph initGraph(int nVert){
	Graph g;
	g.nVert = nVert;
	g.matAdj = (Vertex **) malloc(g.nVert * sizeof(Vertex *));
	for (int i = 0; i < g.nVert; ++i)
		g.matAdj[i] = (Vertex *) malloc(g.nVert * sizeof(Vertex));
	for (int i = 0; i < g.nVert; ++i)
		for (int j = 0; j < g.nVert; ++j)
			g.matAdj[i][j] = INF;
	   
	return g;
}

// insere um arco (aresta) v, w em g ao final da lista...
void addArc(Graph &g, Vertex v, Vertex w, int peso){
	g.matAdj[v][w] = peso;
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

int min(int a, int b){
	return a < b ? a : b;
}

/*
	Algoritmo de Floyd-Warshall é um classico exemplo de programação
	dinamica. É muito simples a codificacao.

	Para melhor entendimento, consulte o slide da aula... 

*/


void FloydWarshall(Graph &g){
	for (int k = 0; k < g.nVert; ++k)
		for (int i = 0; i < g.nVert; ++i)
			for (int j = 0; j < g.nVert; ++j)
			{
				g.matAdj[i][j] = min(g.matAdj[i][j], g.matAdj[i][k] + g.matAdj[k][j]);
			}

}

void printPath(vi &p, Vertex s, Vertex t){
	// chegou no inicio... imprime s...
	if (t == s) { 
		printf("%d ", s);
		return;
	}
	printPath(p, s, p[t]);
	printf("%d ", t);
}



int main(int argc, char const *argv[])
{
	/* code */
	int nVert;
	Vertex v1,v2;
	int peso;

	scanf("%d\n", &nVert);
	Graph g = initGraph(nVert);
	


	while (scanf("%d %d %d\n", &v1, &v2, &peso)  != EOF){
	  addArc(g,v1,v2,peso);
	  // para utilizar esta estrutura para grafo, basta chamar..
	  //addArc(&g,v2,v1,peso);
	}

	printGraph(g);

	// os valores da diagonal principal devem ser zerados
	// antes de começar.. lembre-se de que os vertices não
	// diretamente conectados estao com peso INF..
	for (int i = 0; i < g.nVert; ++i)
		for (int j = 0; j < g.nVert; ++j)
			if (i == j)
				g.matAdj[i][j] = 0;

	printf("\n");
	printGraph(g);

	FloydWarshall(g);

	printf("\n");
	printGraph(g);

	return 0;
}
