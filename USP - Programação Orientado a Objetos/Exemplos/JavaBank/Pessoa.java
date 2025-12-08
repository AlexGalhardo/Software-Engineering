/*
		Alex Galhardo Vieira
		ICMC USP - São Carlos
		2018

		aleexgvieira@gmail.com
		github.com/AlexGalhardo

		Class Pessoa
*/

import java.util.Scanner;

public class Pessoa {

	Scanner entradaUsuario = new Scanner(System.in);

	private String nomePessoa;
	private int idadePessoa;
	private char sexoPessoa;
	private double RGPessoa;
	private double CPFPessoa;
	private String nacionalidadePessoa;
	private String cidadePessoa;

	public void start(){

		System.out.println("\n\n\t Cadastro de Pessoa Física");

		System.out.print("\t Digite seu nome: ");
		String nomePessoa = entradaUsuario.nextLine();
		this.setNomePessoa( nomePessoa );

		System.out.print("\t Digite sua idade: ");
		int idadePessoa = entradaUsuario.nextInt();
		this.setIdadePessoa( idadePessoa );

		System.out.print("\t Digite seu sexo: ");
		char sexoPessoa = entradaUsuario.next().charAt(0);
		this.setSexoPessoa( sexoPessoa );

		System.out.print("\t Digite seu RG: ");
		double RGPessoa = entradaUsuario.nextDouble();
		this.setRGPessoa( RGPessoa );

		System.out.println("\t Digite sua Nacionalidade: ");
		String nacionalidadePessoa = entradaUsuario.nextLine();
		this.setNacionalidadePessoa( nacionalidadePessoa );

		System.out.print("\t Digite seu CPF: ");
		double CPFPessoa = entradaUsuario.nextDouble();
		this.setRGPessoa( CPFPessoa );

		System.out.println("\t Digite sua Cidade de Origem: ");
		String cidadePessoa = entradaUsuario.nextLine();
		this.setCidadePessoa( cidadePessoa );
	}

	// NOME
	public void setNomePessoa( String nomePessoa ){
		this.nomePessoa = nomePessoa;
	}
	public String getNomePessoa(){
		return this.nomePessoa;
	}


	// IDADE
	public void setIdadePessoa( int idadePessoa ){
		this.idadePessoa = idadePessoa;
	}
	public int getIdadePessoa(){
		return this.idadePessoa;
	}


	// SEXO
	public void setSexoPessoa( char sexoPessoa ){
		this.sexoPessoa = sexoPessoa;
	}
	public char getSexoPessoa(){
		return this.sexoPessoa;
	}


	// RG
	public void setRGPessoa( double RGPessoa ){
		this.RGPessoa = RGPessoa;
	}
	public double getRGPessoa(){
		return this.RGPessoa;
	}


	// CPF
	public void setCPFPessoa( double CPFPessoa ){
		this.CPFPessoa = CPFPessoa;
	}
	public double getCPFPessoa(){
		return this.CPFPessoa;
	}


	// NACIONALIDADE
	public void setNacionalidadePessoa( String nacionalidadePessoa ){
		this.nacionalidadePessoa = nacionalidadePessoa;
	}
	public String getNacionalidadePessoa(){
		return this.nacionalidadePessoa;
	}


	// CIDADE
	public void setCidadePessoa( String cidadePessoa ){
		this.cidadePessoa = cidadePessoa;
	}
	public String getCidadePessoa(){
		return this.cidadePessoa;
	}
}