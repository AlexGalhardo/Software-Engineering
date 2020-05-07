#include <vector>
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

void dfs(Graph &g, vi &visited, int v){
	// marca este nó como visitado e imprime...
	visited[v] = VISITED;
	ii w;
	// para todo w adjacente a v, verifica se nao esta visitado,
	// se nao estiver, chama recursivo,.. isso garante busca em profundidade.. 
	for (int i = 0; i < g.adjList[v].size(); ++i)
	{
		w = g.adjList[v][i]; // lembre-se de que w  = (w,peso)
		if (visited[w.first] == UNVISITED)
			dfs(g,visited,w.first);
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
	  addArc(&g,v2,v1);
	}

	printGraph(g);

	// cria um vetor de tamanho nVert com todos os valores 0.
	vi visited(g.nVert, UNVISITED);

	int qtd = 0; // quantidade de componentes conexas
	// percorre em profundidade o grafo g, a partir do vertice v, com vetor visited falso 
	for (int i = 0; i < visited.size(); ++i)
		if (visited[i] == UNVISITED){
			dfs(g,visited,i);
			qtd++;
		}

	printf("Este grafo contem %d componentes conexas\n", qtd);
	


	return 0;
		
}
