/*
		Alex Galhardo Vieira
		ICMC USP - São Carlos
		2018

		aleexgvieira@gmail.com
		github.com/AlexGalhardo

		Class JavaBankAccount
*/


import java.util.Random;
import java.util.Scanner;

public class JavaBankAccount {

	Scanner entradaUsuario = new Scanner(System.in);

	/* ---- atributos do cliente dentro da conta  --- */
	//private Object Cliente = new Pessoa();
	private String nomeCliente;
	private int idadeCliente;
	private char sexoCliente;
	private double RGCliente;
	private double CPFCliente;
	private String nacionalidadeCliente;
	private String cidadeCliente;
	/* ---------------------------------------------*/


	/* ------ atributos da conta  ------------------*/
	private int Agencia = 42;

	private double SaldoAtualContaCorrente = 0;
	private double SaldoAtualContaPoupança = 0;

	/* total de saques realizados na conta */
	private int totalSaquesContaCorrente = 0;
	private int totalSaquesContaPoupança = 0;
	private int totalSaquesGeral = 0;

	/* total em dinheiro sacado da conta */
	private double totalSacadoContaCorrente = 0;
	private double totalSacadoContaPoupança = 0;
	private double totalSacadoGeral = 0;

	/* total em dinheiro depositado na conta */
	private double totalDepositadoContaCorrente = 0;
	private double totalDepositadoContaPoupança = 0;
	private double totalDepositadoGeral = 0;

	/* total de depositos realizados na conta */
	private int totalDepositosContaCorrente = 0;
	private int totalDepositosContaPoupança = 0;
	private int totalDepositosGeral = 0;
	/* ---------------------------------------------*/


	/* --------- metodos da classe -----------------*/

	/* construtor da classe JavaBankAccount */
	public JavaBankAccount(String nomeCliente, 
					int idadeCliente, 
					char sexoCliente,
					double RGCliente,
					double CPFCliente,
					String nacionalidadeCliente,
					String cidadeCliente,
					double saldoInicialContaCorrente,
					double saldoInicialContaPoupança ){

		this.nomeCliente = nomeCliente;
		this.idadeCliente = idadeCliente;
		this.sexoCliente = sexoCliente;
		this.RGCliente = RGCliente;
		this.CPFCliente = CPFCliente;
		this.nacionalidadeCliente = nacionalidadeCliente;
		this.cidadeCliente = cidadeCliente;
		this.SaldoAtualContaCorrente += saldoInicialContaCorrente;
		this.SaldoAtualContaPoupança += saldoInicialContaPoupança;
	}



	public void start(){

		System.out.println("\n\t ...Bem vindo ao Java Bank, " + this.getNomeCliente() + "!");

		do{

			System.out.println("\n\n\t Operações:");
			System.out.println("\t Digite [1] --> Ver extrato.");
			System.out.println("\t Digite [2] --> Mudar algum dado da conta.");
			System.out.println("\t Digite [3] --> Operacoes de Depositos.");
			System.out.println("\t Digite [4] --> Operacoes de Saques.");
			System.out.println("\t Digite [0] --> Encerrar sessão no JavaBank.");
			System.out.print("\t Opcão: ");
			
			int operacaoJavaBank = entradaUsuario.nextInt();

			if ( operacaoJavaBank == 1 ){
				this.getExtrato();
			}
			else if ( operacaoJavaBank == 2 ){
				this.MudarDados();
			}
			else if ( operacaoJavaBank == 3 ){
				this.Depositos();
			}
			else if ( operacaoJavaBank == 4 ){
				this.Saques();
			}
			else if ( operacaoJavaBank == 0 ){
				break;
			}
			else{
				System.out.println("\t Digite uma operação válida!");
			}

		}while( true );
	}


	public void MudarDados(){
		int operacaoMudarDados = 1;
		do{
			System.out.println("\t Mudar dados da conta:");
			System.out.println("\t Digite [1] --> Mudar nome do cliente.");
			System.out.println("\t Digite [2] --> Mudar idade do cliente.");
			System.out.println("\t Digite [3] --> Mudar RG do cliente.");
			System.out.println("\t Digite [4] --> Mudar CPF do cliente.");
			System.out.println("\t Digite [5] --> Mudar nacionalidade do cliente.");
			System.out.println("\t Digite [6] --> Mudar cidade do cliente.");
			System.out.println("\t Digite [0] --> Voltar menu Principal.");
			System.out.print("\t Opcão: ");
		
			operacaoMudarDados = entradaUsuario.nextInt();

			if ( operacaoMudarDados == 1 ){
				this.mudarNomeCliente();
			}
			else if ( operacaoMudarDados == 2 ){
				this.mudarIdadeCliente();
			}
			else if ( operacaoMudarDados == 3 ){
				this.mudarRGCliente();
			}
			else if ( operacaoMudarDados == 4 ){
				this.mudarCPFCliente();
			}
			else if ( operacaoMudarDados == 5 ){
				this.mudarNacionalidadeCliente();
			}
			else if ( operacaoMudarDados == 6 ){
				this.mudarCidadeCliente();
			}
			else{
				System.out.println("\n\t Digite uma operação de mudança de dados válida!");
			}
		}while( operacaoMudarDados != 0 );
	}

	public void setNomeCliente( String novoNomeCliente ){
		this.nomeCliente = novoNomeCliente;
	}

	public void mudarNomeCliente(){
		System.out.println("\n\t Digite o novo nome do cliente: ");
		String novoNomeCliente = entradaUsuario.nextLine();
		this.setNomeCliente( novoNomeCliente );
	}


	public void setIdadeCliente( int novaIdadeCliente ){
		this.idadeCliente = novaIdadeCliente;
	}

	public void mudarIdadeCliente(){
		System.out.println("\n\t Digite a nova idade do cliente: ");
		int novaIdadeCliente = entradaUsuario.nextInt();
		this.setIdadeCliente( novaIdadeCliente );
	}

	public void setRGCliente( double novoRGCliente ){
		this.RGCliente = novoRGCliente;
	}
	
	public void mudarRGCliente(){
		System.out.println("\n\t Digite a nova idade do cliente: ");
		int novoRGCliente = entradaUsuario.nextInt();
		this.setIdadeCliente( novoRGCliente );
	}

	public void setCPFCliente( double novoCPFCliente ){
		this.CPFCliente = novoCPFCliente;
	}
	
	public void mudarCPFCliente(){
		System.out.println("\n\t Digite a nova idade do cliente: ");
		int novoCPFCliente = entradaUsuario.nextInt();
		this.setIdadeCliente( novoCPFCliente );
	}

	public void setNacionalidadeCliente( String novaNacionalidadeCliente ){
		this.nacionalidadeCliente = novaNacionalidadeCliente;
	}
	
	public void mudarNacionalidadeCliente(){
		System.out.println("\n\t Digite a nova idade do cliente: ");
		int novaNacionalidadeCliente = entradaUsuario.nextInt();
		this.setIdadeCliente( novaNacionalidadeCliente );
	}

	public void setCidadeCliente( String novaCidadeCliente ){
		this.cidadeCliente = novaCidadeCliente;
	}
	
	public void mudarCidadeCliente(){
		System.out.println("\n\t Digite a nova cidade do cliente: ");
		int novaCidadeCliente = entradaUsuario.nextInt();
		this.setIdadeCliente( novaCidadeCliente );
	}



	public void Depositos(){

		do{
			System.out.println("\n\t Operacoes de Depositos:");
			System.out.println("\t Digite [1] --> Depositar dinheiro na conta corrente.");
			System.out.println("\t Digite [2] --> Depositar dinheiro na conta poupança.");
			System.out.println("\t Digite [0] --> Voltar menu principal.");
			System.out.print("\t Opcão: ");
		
			int operacaoDeposito = entradaUsuario.nextInt();

			if ( operacaoDeposito == 1 ){
				this.depositarContaCorrente();
			}
			else if ( operacaoDeposito == 2 ){
				this.depositarContaPoupança();
			}
			else if( operacaoDeposito == 0 ){
				break;
			}
			else{
				System.out.println("\n\t Digite uma operação de saque válida!");
			}
		
		}while( true );
	}



	public void Saques(){
		
		do{
			System.out.println("\n\t Operacoes de Saques:");
			System.out.println("\t Digite [1] --> Sacar dinheiro da conta corrente.");
			System.out.println("\t Digite [2] --> Sacar dinheiro da conta poupança.");
			System.out.println("\t Digite [0] --> Voltar menu principal.");
			System.out.print("\t Opcão: ");
		
			int operacaoSaque = entradaUsuario.nextInt();

			if ( operacaoSaque == 1 ){
				this.sacarContaCorrente();
			}
			else if ( operacaoSaque == 2 ){
				this.sacarContaPoupança();
			}
			else if ( operacaoSaque == 0 ){
				break;
			}
			else{
				System.out.println("\n\t Digite uma operação de saque válida!");
			}
		
		}while( true );
	}



	/* metodo imprime extrado dos dados da conta */
	public void getExtrato(){
		System.out.print("\n\t Ola, " + this.getNomeCliente() + "!");
		System.out.print("\n\t ...Extrado Atual da Conta...");
		System.out.print("\n\t Agencia: " + this.getAgencia());
		System.out.print("\n\t Saldo Conta Corrente: " + this.getSaldoAtualContaCorrente());
		System.out.print("\n\t Saldo Conta Poupança: " + this.getSaldoAtualContaPoupança());
		System.out.print("\n\t Total Saques da Conta Corrente: " + this.getTotalSaquesContaCorrente());
		System.out.print("\n\t Total Saques da Conta Poupança: " + this.getTotalSaquesContaPoupança());
		System.out.print("\n\t Total de Saques Geral: " + this.getTotalSaquesGeral());
		System.out.print("\n\t Total Sacado Geral: R$ " + this.getTotalSacadoGeral());
		System.out.print("\n\t Total Sacado Conta Corrente: R$ " + this.getTotalSacadoContaCorrente());
		System.out.print("\n\t Total Sacado Conta Poupança: R$ " + this.getTotalSacadoContaPoupança());
		System.out.print("\n\t Total Depositos na Conta Corrente: " + this.getTotalDepositosContaCorrente());
		System.out.print("\n\t Total Depositos na Conta Poupança: " + this.getTotalDepositosContaPoupança());
		System.out.print("\n\t Total Depositos Geral: " + this.getTotalDepositosGeral());
		System.out.print("\n\t Total Depositado na Conta Corrente: R$ " + this.getTotalDepositadoContaCorrente());
		System.out.print("\n\t Total Depositado Conta Poupança: R$ " +this.getTotalDepositadoContaPoupança());
		System.out.print("\n\t Total Depositado Geral: R$ " + this.getTotalDepositadoGeral());
	}


	/* metodo get nome cliente */
	public String getNomeCliente(){
		return this.nomeCliente;
	}

	/* metodo get agencia */
	public int getAgencia(){
		return this.Agencia;
	}


	/* -------- CONTA CORRENTE ---------------*/
	public double getSaldoAtualContaCorrente(){
		return this.SaldoAtualContaCorrente;
	}

	public double getTotalSacadoContaCorrente(){
		return this.totalSacadoContaCorrente;
	}

	public int getTotalSaquesContaCorrente(){
		return this.totalSaquesContaCorrente;
	}

	public int getTotalDepositosContaCorrente(){
		return this.totalDepositosContaCorrente;
	}

	public double getTotalDepositadoContaCorrente(){
		return this.totalDepositadoContaCorrente;
	}

	/* metodo depositar conta corrente */
	public void depositarContaCorrente(){
		System.out.print("\t Quanto depositar na conta corrente: R$ ");
		double depositaContaCorrente = entradaUsuario.nextDouble();
		System.out.println("\t ...Depositando R$ " + depositaContaCorrente + " na Conta Corrente...");
		this.SaldoAtualContaCorrente += depositaContaCorrente;
		this.totalDepositosGeral++;
		this.totalDepositosContaCorrente++;
		this.totalDepositadoContaCorrente += depositaContaCorrente;
		this.totalDepositadoGeral += depositaContaCorrente;
		System.out.println("\t Saldo atual conta corrente: R$ " +  this.getSaldoAtualContaCorrente());
	}

	/* metodo sacar conta corrente */
	public void sacarContaCorrente(){

		System.out.println("\t Saldo atual conta corrente: R$ " + this.getSaldoAtualContaCorrente());
		System.out.print("\t Quanto sacar da conta corrente: R$ ");

		double retiraContaCorrente = entradaUsuario.nextDouble();
		if ( retiraContaCorrente <= this.getSaldoAtualContaCorrente()){
			System.out.println("\n\t ...Sacando R$ " + retiraContaCorrente + " da Conta Corrente...");
			this.SaldoAtualContaCorrente -= retiraContaCorrente;
			this.totalSaquesGeral++;
			this.totalSaquesContaCorrente++;
			this.totalSacadoContaCorrente += retiraContaCorrente;
			this.totalSacadoGeral += retiraContaCorrente;
			System.out.println("\t Saldo atual conta corrente: R$ " +  this.getSaldoAtualContaCorrente());
		}
		else{
			System.out.println("\t Você não possui saldo suficiente para sacar essa quantidade no momento!");
			System.out.println("\t Seu saldo atual é: R$ " + this.getSaldoAtualContaCorrente());
		}
	}
	/*---------------------------------------*/




	/* -------- CONTA POUPANÇA ---------------*/
	public double getSaldoAtualContaPoupança(){
		return this.SaldoAtualContaPoupança;
	}

	public double getTotalSacadoContaPoupança(){
		return this.totalSacadoContaPoupança;
	}

	public int getTotalSaquesContaPoupança(){
		return this.totalSaquesContaPoupança;
	}

	public int getTotalDepositosContaPoupança(){
		return this.totalDepositosContaPoupança;
	}

	public double getTotalDepositadoContaPoupança(){
		return this.totalDepositadoContaPoupança;
	}

	/* metodo depositar conta poupança */
	public void depositarContaPoupança(){
		System.out.println("\n\t Quanto depositar na conta poupança: R$ ");
		double depositaContaPoupança = entradaUsuario.nextDouble();
		
		if ( depositaContaPoupança <= 0 ){
			System.out.println("\n\t Por favor, digite um valor válido positivo.");
		}
		else{
			System.out.println("\n\t ...Depositando Conta Poupança...");
			this.SaldoAtualContaCorrente += depositaContaPoupança;
			this.totalDepositosGeral++;
			this.totalDepositosContaPoupança++;
			this.totalDepositadoContaPoupança += depositaContaPoupança;
			this.totalDepositadoGeral += depositaContaPoupança;
			System.out.println("\n\t Saldo atual conta poupança: R$ " +  this.getSaldoAtualContaCorrente());
		}
	}

	/* metodo sacar conta poupança */
	public void sacarContaPoupança(){

		System.out.println("\n\t Saldo atual da conta poupança: R$" + this.getSaldoAtualContaPoupança());
		System.out.println("\n\t Quanto sacar da conta poupança: R$ ");
		double retiraContaPoupança = entradaUsuario.nextDouble();

		if ( retiraContaPoupança < this.getSaldoAtualContaPoupança()){
			System.out.println("\n\t ...Sacando Conta Corrente...");
			this.SaldoAtualContaPoupança -= retiraContaPoupança;
			this.totalSaquesGeral++;
			this.totalSaquesContaPoupança++;
			this.totalSacadoContaPoupança += retiraContaPoupança;
			this.totalSacadoGeral += retiraContaPoupança;
			System.out.println("\n\t Saldo atual conta poupança: R$ " +  this.getSaldoAtualContaCorrente());
		}
		else{
			System.out.println("\n\t Você não possui esse saldo para saque na conta poupança no momento!");
		}
	
	}
	/*---------------------------------------*/


	/* ------- GERAL -------------------------*/
	public int getTotalSaquesGeral(){
		return this.totalSaquesGeral;
	}

	public double getTotalSacadoGeral(){
		return this.totalSacadoGeral;
	}

	public int getTotalDepositosGeral(){
		return this.totalDepositosGeral;
	}

	public double getTotalDepositadoGeral(){
		return this.totalDepositadoGeral;
	}


}
