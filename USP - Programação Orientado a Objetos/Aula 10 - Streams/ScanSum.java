import java.io.FileReader;
import java.io.BufferedReader;
import java.io.IOException;
import java.util.Scanner;
import java.util.Locale;

public class ScanSum {

	public static void main(String[] args) throws IOException {

		Scanner s = null;
		double sum = 0;

		try {
			// faça s ser do instancia Scanner
			// aponte s para null, pq ela não foi instanciada ainda
			// faça uma nota instancia para s, do tipo Scanner, que vai receber uma stream de entrada
			// do tipo BufferedReader
			// que recebe os dados de entrada e armazena no Buffer
			// que recebe os dados de stream de entrada do tipo FileReader 
			s = new Scanner(new BufferedReader(new FileReader("numbers.txt")));
			
			s.useLocale(Locale.US); // Decimal separator
			
			// enquanto ouver proximo numero
			while (s.hasNext()) {
				// se for double number
				if (s.hasNextDouble()) {
					// some
					sum += s.nextDouble();
				} else {
					s.next();
				}
			}
		} finally {
			s.close();
		}
		System.out.println(sum);
	}
}
