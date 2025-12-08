#include <vector>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>

#include "UnionFind.h"

using namespace std;


// estruturas uteis para representacao de grafos...
typedef pair<int, int> ii;
typedef vector<int> vi;

vector< pair<int, ii> > EdgeList;    // uma tripla: w, <u,v>

int main(){

	int A;  // nro de Arestas
	int V; // nro de Vertices


	int u,v,w;
 
	scanf("%d", &A);
	scanf("%d", &V);

	for (int i=0; i<A; i++) {
		scanf("%d %d %d", &u, &v, &w);
		EdgeList.push_back(make_pair(w, ii(u,v)));
	}
	sort(EdgeList.begin(), EdgeList.end());

	int mst_cost = 0;

	UnionFind uf(V); // inicialmente todas as arestas sao conjuntos disjuntos...

	// percorra todas as arestas...
	for(int i=0; i<A; i++){
		pair<int, ii> front = EdgeList[i]; // pega a aresta de menor peso!
		// se os vertices que compoem a aresta estao em conjuntos separados
		// nao ha ciclo, junta os dois !
		if (!uf.isSameSet(front.second.first, front.second.second)) {
			mst_cost += front.first;  // atualiza o custo
			// coloca ambos no mesmo set...
			uf.unionSet(front.second.first, front.second.second);
		}
	}

	printf("MST cost = %d (Kruskal's)\n", mst_cost);

	return 0;
}