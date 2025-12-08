/*
	Alex Galhardo Vieira
	10408344
	ICMC USP - São Carlos 
	2018

Exercício 2
Pense em uma classe Stack (pilha) de inteiros. Implemente a classe e suas três principais
operações (push, pop e top).
Push é um método que deve lançar uma exceção do tipo “FullStackException” sempre que não
couber elementos na pilha (considere uma pilha de tamanho máximo fixo igual a 5).

Pop e Top devem lançar uma exceção “EmptyStackException” caso a pilha não tenha mais
elementos para serem retirados ou impressos respectivamente. Ambas exceções são herdeiras da
exceção "StackException". 

Implemente todas as 3 classes de exceção e os métodos que as lançam.
Implemente também uma classe Teste que mostra como criar a pilha e invocar os métodos push, pop
e top com os respectivos tratamentos de exceções seguindo o padrão abaixo.

O input será dado da forma: Na primeira linha, um inteiro N indicando o número de operações
feitas na pilha. Nas N linhas seguintes terão instruções do seguinte formato:

• I x - Insere o inteiro x no topo da pilha.
• R - Remove o elemento que está no topo da pilha.
• P - Imprime, em uma nova linha, o elemento que está no topo da pilha.

Caso alguma das exceções ocorra, imprima Erro! na mensagem da classe "StackException"e uma
mensagem adicional caracterizando o tipo da exceção ocorrida:
• Caso seja do tipo uma remoção inválida, imprima Remocao Invalida!
• Caso seja do tipo a pilha esteja cheia imprima Pilha cheia!
• Caso a pilha esteja vazia e peça para imprimir um elemento, imprima Operacao Invalida!

E, no caso de Remoção ou Inserção inválidas, finalize a execução do programa logo após as mensagens
de erro, ignorando instruções seguintes.

Obs: Para facilitar a leitura da entrada é aconselhável que se utilize o código disponibilizado no
Exercício 2 da Lista 2 como base, com alterações necessárias, porém isso não é obrigatório.
1

*** Input 1

8
P
I 10
P
I 4
I 5
R
P
I 12

Output 1

E r r o !
O pe raca o I n v a l i d a !
10
4

*** Input 2

6
I 3
P
R
R
I 5
P

Output 2

3
E r r o !
Remocao i n v a l i d a !


Explicação dos casos de teste:
No primeiro caso, tinhamos a pilha vazia na primeira instrução de impressão, então lançamos
uma exceção com a mensagem "Operacao Invalida", que não interrompe a execução do programa.
Logo, colocamos 10 na pilha e imprimimos o 10. Então, colocamos 4 e 5, porém retiramos o
elemento do topo dela (que seria o 5), obtendo então 4 como o novo topo. Em seguida, colocamos
12 na pilha e finalizamos a execução do programa.
No segundo caso, inserimos 3 na pilha, o imprimimos e depois o removemos. Então, na
quarta instrução tenta-se remover o topo da pilha, que não existe, lançando uma exceção do tipo
EmptyStackException, imprimindo a mensagem de erro e finalizando a execução do programa.
*/

import java.util.Scanner;
import java.util.*;

/*
Push é um método que deve lançar uma exceção do tipo “FullStackException” sempre que não
couber elementos na pilha (considere uma pilha de tamanho máximo fixo igual a 5).
*/
class FullStackException extends Exception {
	public FullStackException(){}

	public FullStackException(String msg){
		super(msg);
	}
}

class StackException extends Exception {
	public StackException(){}
	
	public StackException(String msg){
		super(msg);
	}	
}

/*
Pop e Top devem lançar uma exceção “EmptyStackException” caso a pilha não tenha mais
elementos para serem retirados ou impressos respectivamente. Ambas exceções são herdeiras da
exceção "StackException".
*/
class EmptyStackException extends StackException {
	
	public EmptyStackException(){}

	public EmptyStackException(String msg){
		super(msg);
	}
}

class Pilha {

	// private List pilha = new ArrayList(5);
	// private List pilha = new LinkedList();
	private int[] pilha;
	private int posicaoPilha;

	// constructor
	public Pilha(){
		// iniciando a posicao da pilha para -1
		this.posicaoPilha = -1;
		// criando um vetor com tamanho 5
		this.pilha = new int[5];
	}

	// push method
    public void push(int valor) throws FullStackException{
        
        // se a posicao da pilha for igual o tamanho do vetor, está cheio
        if (this.posicaoPilha == this.pilha.length - 1) {
            throw new FullStackException("Erro!\nPilha Cheia!");
        }
        
        this.pilha[++posicaoPilha] = valor;
    }

	public int pop() throws EmptyStackException {

        if(this.posicaoPilha == -1){
        	throw new EmptyStackException("Erro!\nRemocao Invalida!");
        }

        return this.pilha[this.posicaoPilha--];
    }

    public void top() throws EmptyStackException {

    	if(this.posicaoPilha == -1){
			throw new EmptyStackException("Erro!\nOperacao Invalida!");
		}

    	System.out.println(this.pilha[this.posicaoPilha]);
    }
}


class Main {

	public static void main(String[] args){

		Scanner userInput = new Scanner(System.in);
		
		int qtdAcoes = userInput.nextInt();

		Pilha newStack = new Pilha();
		// newStack.push2(1);
		// newStack.push2(3);
		// newStack.top2(); // 3
		// newStack.pop2(); // 3 
		// newStack.top2(); // 1

		/*
		• I x - Insere o inteiro x no topo da pilha.
		• R - Remove o elemento que está no topo da pilha.
		• P - Imprime, em uma nova linha, o elemento que está no topo da pilha.
		*/
		
		while(qtdAcoes != 0){

			char act = userInput.next().charAt(0);
			char action = Character.toUpperCase(act);

			// I
			if(action == 'I'){
				try{
					int number = userInput.nextInt();
					newStack.push(number);
					//System.out.println("elemento adicionado com sucesso!");
				}
				catch(FullStackException e){
					System.out.println(e.getMessage());
					// e.printStackTrace();
				}
			}
			// R
			else if(action == 'R'){
				try{
					newStack.pop();
				}
				catch(EmptyStackException e){
					System.out.println(e.getMessage());
					// e.printStackTrace();
				}
			}
			// P
			else{
				try{
					newStack.top();
				}
				catch(EmptyStackException e){
					System.out.println(e.getMessage());
					// e.printStackTrace();
				}
			}

			qtdAcoes--;
		}
	}
}