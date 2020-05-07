#include <vector>
#include <queue>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#define VISITED 1
#define UNVISITED 0

using namespace std;


/*
VAmos fazer uma estrutura de dados usando a classe STL vector..
Esta estrutura considera que o grafo é ponderado, ou seja, tem
um peso.....
*/

typedef pair<int,int> ii; // primeiro elemento = vertice w; segundo elem= peso
typedef vector<ii> vii;   // um vetor de pares <w,peso> ...
typedef vector<int> vi;

// o grafo consiste de vértices, numerados de 0, v-1
// vamos assumir que são designados por valores inteiros.
#define Vertex int


// Para manter a compatibilidade com o que vimos fazendo, podemos definir uma estrutura
// Graph.
typedef struct graph{
	int nVert;
	int nEdge;
    vector<vii> adjList;
}Graph;

Graph initGraph(int nVert){
	Graph g;
	g.nVert = nVert;
	// redefine o vector com nVert elementos...
	g.adjList.resize(nVert);

	return g;
}

// insere um arco (aresta) v, w em g ao final da lista...
void addArc(Graph *g, Vertex v, Vertex w){
	g->adjList[v].push_back(make_pair(w,0));
}

void printGraph(Graph g){
	// para todos os vertices...
	for (int i = 0; i < g.nVert; ++i)
	{	
		printf("%d ->> ", i);
		for(int j = 0; j<g.adjList[i].size(); j++){
			printf("%d ", g.adjList[i][j].first);
		}
		printf("\n");
	}
}

/*
	Busca em profundidade: dado um vertice v qq do grafo, um vetor de vertices
	inicialmente marcado como não visitado, percorra o grafo a partir de v.
	marque v como visitado e 
	Para cada vertice w adjacente a v, ainda nao visitado, chame recursivamente
	a funcao. Isso garante a visitacao em profundidade.
*/

void bfsOrdTopol(Graph &g, vi &vetOrdTop){
	// precisamos de uma fila
	queue<Vertex> q; // define uma fila q
	int indice = -1;
	// vetor de quantidade de vertices predecessores de v
	vi predecessorCount(g.nVert, 0);
	
	// preenche o vetor de predecessor...
	for (int i = 0; i < g.nVert; ++i)
		for(int j = 0; j<g.adjList[i].size(); j++)
			predecessorCount[g.adjList[i][j].first]++;
	
		for (int i = 0; i < g.nVert; ++i)
		{
			printf("%d ", predecessorCount[i]);
		}
		printf("\n");


	// neste ponto, os vertices que nao tem nenhum predecessor, estao zerados..
	// coloque-os na fila...
	for (int i = 0; i < g.nVert; ++i)
		if (predecessorCount[i] == 0)
			q.push(i);	// coloca vertice i na fila...

	Vertex v,succ;
	while (!q.empty()){
		v = q.front(); q.pop(); // retira o primeiro da fila e coloque-o no inicio do vetor
		indice++;
		vetOrdTop[indice] = v;
		// percorra a lista de seus sucessores...
		for(int j = 0; j<g.adjList[v].size(); j++) {
			succ = g.adjList[v][j].first;
			predecessorCount[succ]--;
			// ja nao tem mais sucessores, entao precesse-o, colocando-o na fila !!!
			if (predecessorCount[succ] == 0)
				q.push(succ);
		}
	}
}




int main(int argc, char const *argv[])
{
	/* code */
	int nVert;
	Vertex v1,v2;

	scanf("%d\n", &nVert);
	Graph g = initGraph(nVert);
	//cout << g.adjList.size();


	//addArc(g,0,1);
	while (scanf("%d %d\n", &v1, &v2)  != EOF){
	  addArc(&g,v1,v2);
	  // para utilizar esta estrutura para grafo, basta chamar..
	  //addArc(&g,v2,v1);
	}

	printGraph(g);

	// cria um vetor de tamanho nVert com todos os valores 0.
	vi vetOrdTop(g.nVert);

	bfsOrdTopol(g,vetOrdTop);

	// imprime a ordenacao topologica
	for (int i = 0; i < vetOrdTop.size(); ++i){
		printf("%d ", vetOrdTop[i]);
	}
	printf("\n");

	return 0;
		
}
