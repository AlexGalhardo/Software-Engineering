/*

	Alex Galhardo Vieira
	ICMC USP - 2018

	github.com/AlexGalhardo
	aleexgvieira@gmail.com

*/

import java.lang.*;
import java.util.*;

class Date {

	private int dia;
	private int mes;
	protected int ano;

	enum Anos {
		ATUAL(2018), AC(0);
		// AC = antes de cristo
		private int codigo;

	    Anos(int codigo){
	    	this.codigo = codigo;
	    }

	   	public int getCodigo(){ 
	   		return this.codigo;
	   	}
	}

	enum Meses {

		JANEIRO(1), FEVEREIRO(2), MARÇO(3), ABRIL(4), MAIO(5), JUNHO(6),
		JULHO(7), AGOSTO(8), SETEMBRO(9), OUTUBRO(10), NOVEMBRO(11), DEZEMBRO(12);

		private final int codigo;

	    Meses(int codigo){
	    	this.codigo = codigo;
	    }

	    public int getCodigo(){ 
	    	return this.codigo; 
	    }
	}


	Date(int dia, int mes, int ano){
		this.dia = dia;
		this.mes = mes;
		this.ano = ano;
	}

	public void setDia(int dia){
		this.dia = dia;
	}
	public int getDia(){
		return this.dia;
	}

	public void setMes(int mes){
		this.mes = mes;
	}
	public int getMes(){
		return this.mes;
	}

	public void setAno(int ano){
		this.ano = ano;
	}
	public int getAno(){
		return this.ano;
	}

	//Considere os meses de janeiro, março, maio, julho, agosto, outubro e dezembro, como tendo 31
        //dias, fevereiro com 28 e o restante como 30.
	public void displayDate(){
		// ano maior que 2018 ou ano menor que 0
		if(this.getAno() > Anos.ATUAL.getCodigo() || this.getAno() < Anos.AC.getCodigo()){
			System.out.println("DATA INVALIDA");
		}
		// fevereiro possui mais que 28 dias?
		else if(this.getMes() == Meses.FEVEREIRO.getCodigo()){
			if(this.getDia() > 28){
				System.out.println("DATA INVALIDA");
			}
			else{
				System.out.println(this.getDia()+"/"+this.getMes()+"/"+this.getAno());
			}
		}
		// março, julho, agosto, outubro, dezembro possui mais que 31 dias?
		else if(this.getMes() == Meses.MARÇO.getCodigo()
				|| this.getMes() == Meses.MAIO.getCodigo()
				|| this.getMes() == Meses.JULHO.getCodigo()
				|| this.getMes() == Meses.AGOSTO.getCodigo()
				|| this.getMes() == Meses.OUTUBRO.getCodigo()
				|| this.getMes() == Meses.DEZEMBRO.getCodigo()){ 
			if(this.getDia() > 31){
				System.out.println("DATA INVALIDA");
			}
			else{
				System.out.println(this.getDia()+"/"+this.getMes()+"/"+this.getAno());
			}
		}
		else if(this.getMes() == Meses.ABRIL.getCodigo()
				|| this.getMes() == Meses.JUNHO.getCodigo()
				|| this.getMes() == Meses.SETEMBRO.getCodigo()
				|| this.getMes() == Meses.NOVEMBRO.getCodigo()){
			if(this.getDia() > 30){
				System.out.println("DATA INVALIDA");
			}
			else{
				System.out.println(this.getDia()+"/"+this.getMes()+"/"+this.getAno());
			}
		}
		// data valida
		else{
			System.out.println(this.getDia()+"/"+this.getMes()+"/"+this.getAno());
		}
	}


	public static void main(String[] args){

		Scanner userInput = new Scanner(System.in);

		int qtd = userInput.nextInt();

		// vetor de objetos Date
		List<Date> datas = new ArrayList<Date>();

		for(int i = 0; i < qtd; i++){

			int dia = userInput.nextInt();
			int mes = userInput.nextInt();
			int ano = userInput.nextInt();

			// crie objetos dates com construtor
			Date newDate = new Date(dia, mes, ano);

			datas.add(newDate);
		}

		for(Date date : datas){
			date.displayDate();
		}
	}
}
