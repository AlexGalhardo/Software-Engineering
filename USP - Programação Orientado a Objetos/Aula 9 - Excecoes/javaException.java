/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package exercicio9;

/**
 *
 * @author ICMC
 * Calculator, que contém os
métodos
* referencias: https://www.caelum.com.br/apostila-java-orientacao-objetos/excecoes-e-controle-de-erros/#motivao
* https://pt.stackoverflow.com/questions/17025/usando-as-palavras-chave-throws-e-throw
● double div(double, double)
● double log10(double)

 */
import java.util.Scanner;

class CalculatorError extends Exception {
    /**
     * 
     */
    public CalculatorError(){}
    /**
     * 
     * @param msg 
     */
    public CalculatorError(String msg){
        super(msg);
    }
}

class Calculator {
    
    /**
     * 
     * @param x
     * @param y
     * @return
     * @throws InvalidOperationException 
     */
    private double divX;
    private double divY;
    private double resultado; 
    
    public double setDiv(double x, double y) throws InvalidOperationException {
        
        if(y <= 0){
            throw new InvalidOperationException("O divisor não pode ser 0");
        }
        else if(x == 0){
            throw new InvalidOperationException("O divindo não pode ser 0");
        }
        else {
            this.x = x;
            this.y = y;
            this.resultado = x/y;
            System.out.println("Os valores inseridos são válidos");
        }
    }
    
    /**
     * 
     * @param x
     * @param y
     * @return 
     */
    public double setLog10(double x, double y){
        if(y <= 0){
            throw new InvalidOperationException("A segunda entrada não pode ser 0");
        }
        else (x == 0){
            throw new InvalidOperationException("o dividendo não pode ser 0");
        }
    }    
}


class Exercicio9 {
    
    public static void main(String[] args) {
        /**
         * 
         */
        Scanner userInput = new Scanner(System.in);
        
        /**
         * 
         */
        System.out.println("Fazendo divisão na calculadora");
        try {
            double userX = userInput.nextDouble();
            double userY = userInput.nextDouble();
            Calculator calculadora = new Calculator();
            calculadora.setDiv(userX, userY);
            System.out.println("Os valores inseridos são validos!");
        } catch (InvalidOperationException e){
            System.out.println(e.getMessage());
            e.printStackTrace();
        } catch (Exception e){
            System.out.println(e.getMessage());
            e.printStackTrace();
        } finally {
            System.out.println("Programa executado com sucesso");
        }
        
        System.out.println("Fazendo log da calculadora");
        try {
            double x = userInput.nextDouble();
            double y = userInput.nextDouble();
            Calculator calculadora2 = new Calculator();
            calculadora2.setLog10(x, y);
        }
    }
}
