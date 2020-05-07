#include <vector>
#include <queue>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#define VISITED 1
#define UNVISITED 0
#define INF 100000

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
	Buscar em largura(breadth-first search): percorre o grafo em "camadas". Seja um 
	vertice v (primeira camada). Selecione todos vertice w adjacente a v e visite-os.
	repita o processo sucessivamente, "cortando" grafo em "camadas de adjacencia" 

	PAra fazer isso, precisamos de uma fila. Antes de chamar a funcao, coloque o vertice 
	v na fila. Enquanto a fila nao for vazia, faca: 
		- retire o vertice v da fila q. (e imprima...)
		- para todos os seus adjacentes, se ainda nao visitados, coloque-os na
			fila.
*/


void bfs(Graph &g, vi &dist, queue<Vertex> &q, vi &pai){
	Vertex v;
	ii w;

	// enquanto tiver vertices na fila...
	while (!q.empty()) {
		v = q.front(); q.pop();
		// para todos os adjacentes de v ..
		for (int i = 0; i < g.adjList[v].size(); ++i)
		{
			w = g.adjList[v][i]; // pega w adjacente w = (w, peso)
			// se ele for nao visitado ( a distancia ainda eh infinita)
			if (dist[w.first] == INF){
				dist[w.first] = dist[v] + 1; // incrementa a distancia de seu pai (v) ate ele
				pai[w.first] = v;  // o pai de w é o vertice v, eh claro !!
				q.push(w.first);
			}
		}
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

	// cria um vetor de tamanho nVert de distancia inicialmente infinito.
	vi dist(g.nVert, INF);
	//qq um vetor que guarda o pai do vertice i p[i]. Assim podemos
	// tracar a rota de r até qq outro vertice do grafo...
	vi pai(g.nVert);

	// percorre em largura o grafo g, a partir do vertice v, com vetor visited falso 


	queue<Vertex> q; // define uma fila q
	q.push(0);	// coloca vertice 0 nela...
	dist[0] = 0; // a distancia do vertice 0 para ele mesmo eh zero  !!

	bfs(g, dist, q, pai);

	// por curiosidade, imprima o caminho de 0 ate 3.....
	printPath(pai, 0, 3);
	printf("\n");


	return 0;
}
