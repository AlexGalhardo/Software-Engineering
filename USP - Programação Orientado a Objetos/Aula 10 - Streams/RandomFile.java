import java.io.FileReader;
import java.io.BufferedReader;
import java.io.IOException;
import java.util.Scanner;
import java.util.Locale;

public class ScanSum {

	public static void main(String[] args) throws IOException {

		// ACESSO ALEATÓRIO EM ARQUIVOS

		// O uso de streams permite apenas o acesso sequencial (fluxo) de dados

		/*
		Do contrário, precisamos usar classes que permitam a
		leitura e escrita de forma aleatória
		● RandomAccessFile
		● Neste caso, trabalhamos com um ponteiro que indica
		a posição atual de acesso no arquivo
		● Método seek(pos) da classe RandomAccessFile
		posiciona o ponteiro do arquivo para a posição “pos”
		no arquivo.
		*/	

		File fRand = new File("random.txt");

		RandomAccessFile raf = new RandomAccessFile(sRand,"rw");

		String books[] = new String[5];
		books[0] = "Professional JPP\n";
		books[1] = "The Java API\n";
		books[2] = "Java Security\n";
		books[3] = "Java Security Handbook\n";
		books[4] = "Hacking Exposed J2EE\n";
		
		// Escreve a partir do início
		for (int i = 0; i < books.length; i++) {
			raf.writeUTF(books[i]);
		}

		raf.seek(0); //volta ao início // aponta para a primeira linha escrita no arquivo
		raf.writeUTF("Professional JSP\n"); //sobreescreve
		raf.seek(raf.length()); //vai para o final
		raf.writeUTF("Servlet Programming\n"); //escreve (append) // acrescenta mais uma linha de output no final do arquivo
		raf.seek(0); //início de novo
	}
}