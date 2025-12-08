import java.io.*;
import java.util.*;

class Graph {

    private int V;   // No. of vertices
    private LinkedList<Integer> adj[]; //Adjacency Lists

    Graph(int v){
        V = v;
        adj = new LinkedList[v];
        for (int i=0; i < v; ++i)
            adj[i] = new LinkedList();
    }

    void addEdge(int v,int w) {
        adj[v].add(w);
    }

    void BFS(int s){
        
        boolean visited[] = new boolean[V];

        LinkedList<Integer> queue = new LinkedList<Integer>();

        visited[s]=true;
        queue.add(s);

        while (queue.size() != 0) {

        	Collections.sort(queue);
            s = queue.poll();
            System.out.print(s+" ");

            Iterator<Integer> i = adj[s].listIterator();

            while (i.hasNext())
            {
                int n = i.next();
                if (!visited[n])
                {
                    visited[n] = true;
                    queue.add(n);
                }
            }

            if(queue.size() == 0){
                for(int j=0; j<adj.length; j++){
                    Iterator<Integer> index = adj[j].listIterator();
                    if(index.hasNext()){
                        int novo = index.next();
                        if(!visited[j]){
                        	visited[j] = true;
                        	queue.add(j);
                        	s = queue.poll();
            				System.out.print(s+" ");
                        }
                        if(!visited[novo]){
                            visited[novo] = true;
                            queue.add(novo);
                        }
                    }      
                }
            }
        }
    }

    public static void main(String args[]){
		
		Scanner userInput = new Scanner(System.in);
		
		int option = userInput.nextInt();

		if(option == 1){

			int numVertices = userInput.nextInt();
			int numArestas = userInput.nextInt();

			Graph g = new Graph(numVertices+1);

			int contador = 0, u, v;

			while(contador < numArestas){
				u = userInput.nextInt();
				v = userInput.nextInt();

				g.addEdge(u, v);
				contador++;
			}
			g.BFS(1);
		}
    }
}
