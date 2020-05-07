import java.util.Scanner;

/**
 *
 * @author Alex Galhardo 
 * @where ICMC USP 2018
 */

public class Projeto {
    public static void main(String[] args){
        
        Scanner scanner = new Scanner(System.in);  
        String meuNome = scanner.nextLine();
        System.out.println(meuNome);
        System.out.println("Hello World");
        
        Scanner input = new Scanner(System.in);
    
        // tamanho da primeira matriz
        System.out.println("Diga o tamanho da primeira matriz: ");
        int linhasPrimeiraMatriz = input.nextInt();
        int colunasPrimeiraMatriz = input.nextInt();

        // tamanho da segunda matriz
        System.out.println("Agora diga o tamanho da segunda matriz: ");
        int linhasSegundaMatriz = input.nextInt();
        int colunasSegundaMatriz = input.nextInt();

        // define as matrizes
        int novaMatriz[][];
        int primeiraMatriz[][];
        int segundaMatriz[][];
        
        primeiraMatriz = new int[linhasPrimeiraMatriz][colunasPrimeiraMatriz];
        segundaMatriz = new int[linhasSegundaMatriz][colunasSegundaMatriz];
        novaMatriz = new int[colunasPrimeiraMatriz][linhasSegundaMatriz];
        
       
  
        // pega os elementos da primeira matriz
        System.out.println("Digite os elementos da primeira matriz");
        for(int i =0; i < linhasPrimeiraMatriz; i++){
            for(int k = 0; k < colunasPrimeiraMatriz; k++){
                int numero = input.nextInt();
                primeiraMatriz[i][k] = numero;
            }
        }

        // pega os elementos da segunda matriz
        System.out.println("Digite os elementos da segunda matriz");
        for(int i = 0; i < colunasPrimeiraMatriz; i++){
            for(int k = 0; k< linhasPrimeiraMatriz; k++){
                int numero = input.nextInt();
                segundaMatriz[i][k] = numero;
            }
        }
        
        int soma = 0;
        // multiple as duas matrizes
        System.out.println("Multiplicado as duas matrizes...");
        for(int i = 0; i<colunasPrimeiraMatriz; i++){
            for(int k=0; k<linhasSegundaMatriz; k++){
                soma += primeiraMatriz[i][k] * segundaMatriz[k][i];
                //novaMatriz[i][k] = primeiraMatriz[i][k] * segundaMatriz[k][i];
                if(k == linhasSegundaMatriz){
                    novaMatriz[i][k] = soma;
                    soma = 0;
                }
            }
        }
        
        // printando a nova matriz
        for(int i= 0; i< colunasSegundaMatriz; i++){
            for(int k=0; k<linhasPrimeiraMatriz; k++){
                System.out.println(soma);
            }
        }
    }
}
