#include <stdio.h>
#include <stdlib.h>

// o grafo consiste de vértices, numerados de 0, v-1
// vamos assumir que são designados por valores inteiros.

#define Vertex int

// agora vamos definir uma estrutura Arc
// v1 é a ponta inicial; v2 é a ponta final...
typedef struct arc{
	Vertex v;
	Vertex w;
}Arc;

Arc criaArc(Vertex v, Vertex w){
	Arc a;
	a.v = v;
	a.w = w;
	return a;
}


typedef struct graph{
	int nVert;
	Arc *list;
}Graph;

Graph initGraph(int nvert, int nro){
	Graph g;

	g.nVert = nvert;
	g.list = (Arc *) malloc(nro * sizeof(Arc));

	return g;
}

int main(int argc, char const *argv[])
{
	Arc a;

	Graph g = initGraph(5, 10000)
	return 0;
}