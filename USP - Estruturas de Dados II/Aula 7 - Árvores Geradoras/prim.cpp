#include <vector>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;


// estruturas uteis para representacao de grafos...
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;



vector<vii> adjList(100);    // uma lista de adjacencia: para cada vertice v, tem-se um conjunto de tuplas (u,w)
vi taken;     // vetor de vertices ja visitados....
priority_queue<ii> pq;    // fila de prioridade.... de pares de vertices (u,v)

void process(int vtx){
	taken[vtx] = 1; 
	for (int i=0; i < adjList[vtx].size(); i++){
		ii v = adjList[vtx][i];  // pega a primeira adjacencia de vtx....
		if (!taken[v.first])
			// Atencao: C++ STL priority queue is MAX HEAP...
			// usaremos sinal (-) para reverter ordenacao...
			// primeiro o peso, depois o valor do vertice!!!
			pq.push(ii(-v.second, -v.first));
	}

}

void print_queue(priority_queue<ii> q) {
	cout << " Fila Prioridade: ";
	ii data;
    while(!q.empty()) {
    	data = pq.top(); pq.pop(); 
        std::cout << "(" << data.first << "," << data.second <<")" << " ** ";
    }
    std::cout << '\n';
}


int main(){

	int A;  // nro de Arestas
	int V; // nro de Vertices
	int u,v,w;
 
	scanf("%d", &A);
	scanf("%d", &V);

	// lembre-se, o grafo nao eh direcionado!
	for (int i=0; i<A; i++) {
		scanf("%d %d %d", &u, &v, &w);
		adjList[u].push_back(make_pair(v,w));
		adjList[v].push_back(make_pair(u,w));
	}

	taken.assign(V,0);  // nenhum vertice foi visitado ainda..
	process(0); // comeca pelo vertice V=0. ISso é arbitrario....

	int mst_cost = 0;

	while(!pq.empty()){  // enquanto houver elementos na fila...
		//print_queue(pq);
		ii front = pq.top(); pq.pop(); // pega primeiro valor da fila: tem o menor peso dentre os adjs...
		// lembre-se de que o vertice u foi armazenado como segundo, pra priorizar a busca pelo peso..
		//std::cout << "(" << front.first << "," << front.second <<")" << " ** ";
		u = -front.second;   
		w = -front.first;
		//std::cout << "(" << u << "," << front.second <<")" << " ** ";
		if (!taken[u]) { // este vertice nao foi conectado ainda na MST ...
			mst_cost += w; 
			process(u);   // popula a fila com os adjacentes de u....
		}
	}

	printf("MST cost = %d (Prim's)\n", mst_cost);

	return 0;
}