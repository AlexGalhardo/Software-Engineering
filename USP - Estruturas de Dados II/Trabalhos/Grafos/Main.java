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
}

class Objeto {
	public int volumeObjeto;
	Objeto(int volumeObjeto){
		this.volumeObjeto = volumeObjeto;
	}
}

class Pilha {

  	private LinkedList<Objeto> objetos = new LinkedList<Objeto>();

  	public void insere(Objeto objeto) {
    	this.objetos.add(objeto);
  	}

  	public Objeto remove() {
    	return this.objetos.remove(this.objetos.size() - 1);
  	}

  	public boolean vazia() {
   		return this.objetos.size() == 0;
 	}
}

class Caixas {

	private int inicioVetor = 0;
	public int totalCaixas;
	public int caixas[] = new int[10];
	public static int custoTotal = 0;

	public Caixas(int totalCaixas, int volumeCadaCaixa){
		this.totalCaixas = totalCaixas;
		for(int i=0; i < this.totalCaixas; i++){
			caixas[i] = volumeCadaCaixa;
		}
	}

	public void adicionaObjetosNasCaixas(Pilha newPilha){

		while(!newPilha.vazia()){

			Objeto objetoNoTopo = newPilha.remove();

			int indiceMaiorCusto = 0;
			int maiorCusto = 0;

			// percorra todas as caixas no vetor
			for(int i = this.inicioVetor; i < this.totalCaixas; i++){

				// se a caixa possuir volume maior ou igual ao objeto no topo da pilha, verifique se ela possui maior custo
				if(caixas[i] >= objetoNoTopo.volumeObjeto){

					// o custo do objeto para essa caixa se dá:
					// volume da caixa - volume do objeto
					int custo = caixas[i] - objetoNoTopo.volumeObjeto;

					// quanto maior a diferença entre volume da caixa e do objeto, menor será o custo
					if(custo > maiorCusto){
						maiorCusto = custo;
						indiceMaiorCusto = i;
					}
					else{
						continue;
					}
				}
				// se caixa possuir volume menor para ocupar o objeto, pule essa caixa da verificação
				else{
					this.inicioVetor++;
				}
			}

			// se a caixa no indice 5, tem o maior volume disponivel, essa será a com menor custo
			// pegue o custo disponivel desta caixa, e diminua com o volume do objeto
			caixas[indiceMaiorCusto] -= objetoNoTopo.volumeObjeto;
		}

		for(int i= 0; i < this.totalCaixas; i++){
			Caixas.custoTotal += this.caixas[i] * this.caixas[i];
		}
	}
}

class Main {

	public static int custoTotal=0;

	public static void main(String[] args){

		Scanner userInput = new Scanner(System.in);

		Pilha newPilha = new Pilha();

		//Caixas newCaixas = new Caixas();

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

		if(option == 2){

			int numObjetos = userInput.nextInt();
			int numCaixas = userInput.nextInt();
			int volCaixas = userInput.nextInt();

			// crie um vetor de caixas e adicione o volume inserido pelo usuário para cada uma delas
			Caixas newCaixas = new Caixas(numCaixas, volCaixas);

			// pegue o volume de cada objeto do usuário, crie um objeto e insira na pilha de objetos
			for(int i=0; i<numObjetos; i++){

				int volumeObjeto = userInput.nextInt();

				Objeto newObjeto = new Objeto(volumeObjeto);

				newPilha.insere(newObjeto);
			}

			// retire o objeto no topo da pilha
			// verifique cada volume das caixas e verifique qual possui maior volume disponivel
			// se a caixa possuir o maior volume disponivel, ela será o com menor custo 
			newCaixas.adicionaObjetosNasCaixas(newPilha);
			System.out.println(Caixas.custoTotal);
		}
	}
}