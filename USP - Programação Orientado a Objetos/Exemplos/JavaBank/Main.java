/*
		Alex Galhardo Vieira
		ICMC USP - São Carlos
		2018

		aleexgvieira@gmail.com
		github.com/AlexGalhardo

		Função Main 
*/

import java.util.Scanner;
import java.util.Random;

public class Main {

	public static void main(String[] args){

		System.out.println("\n\n\t Bem vindo ao Java Bank!\n");
		Scanner entradaUsuario = new Scanner(System.in);
		int continuarPrograma;

		do{	
			System.out.println("\n\t Digite [1] --> Começar um exemplo.");
			System.out.println("\t Digite [0] --> Encerrar o programa.");
			System.out.print("\t Opção: ");
			
			continuarPrograma = entradaUsuario.nextInt();

			if ( continuarPrograma == 1 ){
				
				Pessoa NovoCliente = new Pessoa();
				NovoCliente.start();

				String nomeCliente = NovoCliente.getNomePessoa();
				int idadeCliente = NovoCliente.getIdadePessoa();
				char sexoCliente = NovoCliente.getSexoPessoa();
				double RGCliente = NovoCliente.getRGPessoa();
				double CPFCliente = NovoCliente.getCPFPessoa();
				String nacionalidadeCliente = NovoCliente.getNacionalidadePessoa();
				String cidadeCliente = NovoCliente.getCidadePessoa();

				System.out.print("\t Deposito inicial da conta corrente: ");
				double saldoInicialContaCorrente = entradaUsuario.nextDouble();

				System.out.print("\t Deposito inicial da conta poupança: ");
				double saldoInicialContaPoupança = entradaUsuario.nextDouble();

				JavaBankAccount NewJavaBankAccount = new JavaBankAccount(nomeCliente, 
											idadeCliente, 
											sexoCliente,
											RGCliente,
											CPFCliente,
											nacionalidadeCliente,
											cidadeCliente,
											saldoInicialContaCorrente,
											saldoInicialContaPoupança);

				NewJavaBankAccount.start();
			}
			else if( continuarPrograma == 0 ){
				System.out.println("\t ...Encerrando Java Bank... \n\n");
				break; 
			}


		}while( true );
	}

}
