#include <vector>
#include <queue>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#define VISITED 1
#define UNVISITED 0
#define INF 100000
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
void addArc(Graph *g, Vertex v, Vertex w, int peso){
	g->adjList[v].push_back(make_pair(w,peso));
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


void printVetor(vi &v){
	for (int i = 0; i < v.size(); ++i)
		printf("%d ", v[i]);
	printf("\n");

}

/*
	Algoritmo de Bellman Ford. A ideia eh bem simples.
	Seja um vertice s (source) do grafo. VAmos computar a distancia minima
	deles para os demais.. 
	- sabemos que dist[s]=0.
	- Ao relaxarmos uma aresta s -> u, entao dist[u] contem o valor correto
	- Ao relaxarmos uma aresta u -> v, entao dist[v] tb contem o valor correto

	- Se relaxarmos TODOS as arestas E, V-1 vezes, entao o menor caminho de s
	até o vértice mais distante de s (que nao por concidência é um caminho de
	comprimento V-1, certo?), entao teremos o valor computado corretamente... 

*/


void BellmanFord(Graph &g, vi &dist, vi &pai){
	Vertex v;
	ii w;
	int min; 

    // faca V-1 vezes, como explicado acima... Complexidade O(V)
	for (int i = 0; i < g.nVert-1; ++i) {
		// Relaxe TODAS as arestas do grafo, percorrendo a lista de adjacencia..
		// para cada vertice da lista de adjacencia. A complexidade disso 
		// eh O(E). Portanto a complexidade deste algoritmo é O(V*E)...
		for (int j = 0; j < g.nVert; ++j)
			// percorra todas as arestas adjacentes..
			for (int k = 0; k < g.adjList[j].size(); ++k) {
				w = g.adjList[j][k]; // pega todo j -> w  
				if (dist[j] + w.second < dist[w.first]){
					dist[w.first] = dist[j] + w.second;
					pai[w.first] = j;
				}
				
			}

		// ao final de cada iteracao, imprime o vetor de distancia
		printVetor(dist);
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

/*
	PAra verificar ciclos negativos, basta percorrer a lista
	de adjacencia mais uma vez (DEPOIS de rodar BELLMANFORD).
	se for encontrado um valor mais baixo que o já existente,
	entao tem...
*/
bool TemCicloNegativo(Graph &g, vi &dist){
	ii w;
	// percorre a lista
	for (int j = 0; j < g.nVert; ++j)
		// percorra todas as arestas adjacentes..
		for (int k = 0; k < g.adjList[j].size(); ++k) {
			w = g.adjList[j][k]; // pega todo j -> w  
			if (dist[j] + w.second < dist[w.first]){
				return true;
			}
			
		}

	return false;
}


int main(int argc, char const *argv[])
{
	/* code */
	int nVert;
	Vertex v1,v2;
	int peso;

	scanf("%d\n", &nVert);
	Graph g = initGraph(nVert);
	//cout << g.adjList.size();


	//addArc(g,0,1);
	while (scanf("%d %d %d\n", &v1, &v2, &peso)  != EOF){
	  addArc(&g,v1,v2,peso);
	  // para utilizar esta estrutura para grafo, basta chamar..
	  //addArc(&g,v2,v1,peso);
	}

	printGraph(g);

	// cria um vetor de tamanho nVert de distancia inicialmente infinito.
	vi dist(g.nVert, INF);
	//qq um vetor que guarda o pai do vertice i p[i]. Assim podemos
	// tracar a rota de r até qq outro vertice do grafo...
	vi pai(g.nVert);

	// percorre em largura o grafo g, a partir do vertice v, com vetor visited falso 

	Vertex s = 0;
	dist[s] = 0; // a distancia do vertice 0 para ele mesmo eh zero  !!

	printVetor(dist);

	BellmanFord(g, dist, pai);

	// por curiosidade, imprima o caminho de s ate um vertice qq...
	// cuidado com o uso desta funcao agora.. se tem ciclo negativo,
	// tem sentido imprimir o menor caminho com uma versao recursiva ??????
	// só tem sentido chamar printPath se o grafo nao tem ciclo negativo...
	// Mas isso pode ser verificado.... 
	if (! TemCicloNegativo(g, dist)) {
		printf("Imprimindo vetor pai = ");  printVetor(pai);
		printPath(pai, s, 3);
		printf("\n");
	} else printf("O grafo tem ciclo negativo. Chamar a funcao recursiva vai gerar stack overflow..\n");


	return 0;
}
