import java.io.*;
import java.util.Scanner;


public class ScanXan {

	public static void main(String[] args) throws IOException {

		/*
		A classe Scanner não é um stream propriamente dito
		● Porém, ela facilita a leitura de dados por tokens
		● Por padrão, os tokens são identificados por
		separadores em branco (blank)
		□ Espaços em branco, tabulações, final de linha...
		● Com ela, podemos especificar o tipo primitivo a ser
		lido em cada chamada
		*/

		Scanner s = null;

		try {
			s = new Scanner(new BufferedReader(new FileReader("xanadu.txt")));
			// enquanto tiver espaços em branco ou proxima linha no arquivo
			// imprima palavra
			while (s.hasNext())
				System.out.println(s.next());
		} finally {
			if (s != null)
				s.close();
			}
		}
	}