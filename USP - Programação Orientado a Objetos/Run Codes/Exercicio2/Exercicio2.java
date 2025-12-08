/*

	Alex Galhardo Vieira
	ICMC USP - 2018

	github.com/AlexGalhardo
	aleexgvieira@gmail.com

*/


import java.util.*;
import java.lang.*;


interface INTERFACE {
	public void setAceleracao(double aceleracaoBase);
	public void setVelocidadeAtual(double velocidadeAtual);
	public void addDistanciaPercorrida(double distanciaPercorrida);
	public double getAceleraoBase();
	public double getVelocidadeAtual();
	public double getDistanciaPercorrida();
	public void addAction(char Action, int t);
	public void actionAcelerar(int t);
	public void actionFreiar(int t);
	public void actionVelocidadeConstante(int t);
	public void showDistanciaPercorrida();
}


abstract class Veiculo implements INTERFACE  {

	protected double velocidadeAtual;
	protected double aceleracaoBase;
	protected double distanciaPercorrida;

	// constructor classe mãe
	Veiculo(double aceleracaoBase){
		this.aceleracaoBase = aceleracaoBase;
		this.velocidadeAtual = 0;
		this.distanciaPercorrida = 0;
	}

	public void setAceleracao(double aceleracaoBase){
		this.aceleracaoBase = aceleracaoBase;
	}

	public void setVelocidadeAtual(double velocidadeAtual){
		this.velocidadeAtual = velocidadeAtual;
	}

	public void addDistanciaPercorrida(double distanciaPercorrida){
		this.distanciaPercorrida += distanciaPercorrida;
	}

	public double getAceleraoBase(){
		return this.aceleracaoBase;
	}

	public double getVelocidadeAtual(){
		return this.velocidadeAtual;
	}

	public double getDistanciaPercorrida(){
		return this.distanciaPercorrida;
	}

	public void addAction(char Action, int t){
		
		if(Action == 'A'){
			this.actionAcelerar(t);
		}
		else if(Action == 'F'){
			this.actionFreiar(t);
		}
		else{ // 'C'
			this.actionVelocidadeConstante(t);
		}
	}

	public void actionAcelerar(int t){
		double doubleT = t * t;
		double velocidadeAtual = this.getVelocidadeAtual() + this.getAceleraoBase() * t;
		this.setVelocidadeAtual(velocidadeAtual);
		double distanciaAcelerando = (0 * t) + ((this.getAceleraoBase() * doubleT) / 2);
		this.addDistanciaPercorrida(distanciaAcelerando);
	}

	public void actionFreiar(int t){
		double doubleT = t * t;
		double distanciaFrenagem = (this.getVelocidadeAtual() * t) - (this.getAceleraoBase() * doubleT / 2);
		this.addDistanciaPercorrida(distanciaFrenagem);
	}

	public void actionVelocidadeConstante(int t){
		double distanciaPercorrida = this.getVelocidadeAtual() * t;
		this.addDistanciaPercorrida(distanciaPercorrida);
	}

	public void showDistanciaPercorrida(){
		System.out.print(this.getDistanciaPercorrida()+ " ");
	}
}




class Bicicleta extends Veiculo {

	Bicicleta(int aceleracaoBase){
		// construtor classe veiculo
		super(aceleracaoBase);
	}
}

class Moto extends Veiculo {


	Moto(int aceleracaoBase){
		// construtor classe veiculo
		super(aceleracaoBase);
		this.setAceleracao(aceleracaoBase);
	}

	@Override
	public void setAceleracao(double aceleracaoBase){
		this.aceleracaoBase = aceleracaoBase * 4.5;
	}
	
}

class Carro extends Veiculo {

	Carro(int aceleracaoBase){
		// construtor classe veiculo
		super(aceleracaoBase);
		this.setAceleracao(aceleracaoBase);
	}

	@Override
	public void setAceleracao(double aceleracaoBase){
		this.aceleracaoBase = aceleracaoBase * 3;
	}
}




class Exercicio2 {

	public static void main(String[] args){

		Scanner userInput = new Scanner(System.in);

		int aceleracaoBase = userInput.nextInt();
		int acoesTomadas = userInput.nextInt();

		Bicicleta newBike = new Bicicleta(aceleracaoBase);
		Moto newMoto = new Moto(aceleracaoBase);
		Carro newCar = new Carro(aceleracaoBase);

		for(int numVeiculo = 0; numVeiculo < 3; numVeiculo++){

			for(int i=0; i < acoesTomadas; i++){

				/*
				A -> ACELERAR
				F -> FREAR
				C -> MANTER VELOCIDADE CONSTANTE
				*/ 
				char acao = userInput.next().charAt(0);
				/*
				t -> tempo em segundos 
				*/
				int t = userInput.nextInt();


				if(numVeiculo==0){
					newCar.addAction(acao, t);
				}
				else if(numVeiculo==1){
					newMoto.addAction(acao, t);
				}
				else{
					newBike.addAction(acao, t);
				}
			}
		}

		newCar.showDistanciaPercorrida();
		newMoto.showDistanciaPercorrida();
		newBike.showDistanciaPercorrida();
	}	
}


