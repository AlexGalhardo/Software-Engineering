import java.io.FileReader;
import java.io.BufferedReader;
import java.io.IOException;
import java.util.Scanner;
import java.util.Locale;

public class ScanSum {

	public static void main(String[] args) throws IOException {

		/*
		Serialização
		● Para ler a gravar objetos, o Java utiliza um recurso
		chamado de serialização de objetos
		● Um objeto serializado é representado como uma
		sequência de bytes
		● Após serializado, o objeto pode ser gravado utilizando
		o stream
		● Um objeto serializado também pode ser lido e
		desserializado, voltando a ser um objeto na memória
		*/

		/*
		Serialização
		● Para que um objeto possa ser serializado e
		desserializado, sua classe precisa implementar a
		interface Serializable
		● Esta interface não tem métodos
		● Interface de marcação
		● Em classes do tipo Serializable, todas as variáveis de
		instância também precisam ser Serializable
		● Ou declaradas como transient
		● Variáveis do tipo TRANSIENT são ignoradas durante o
		processo de serialização
		● Todos os tipos primitivos são serializáveis
		*/

		/*
		Vantagem
		● Facilidade para gravar e ler informações
		● Não é preciso salvar cada informação dos objetos
		separadamente
		● Desvantagem
		● Mais restrito
		● Se a estrutura da classe for alterada, objetos salvos não
		poderão ser lidos
		*/

		ObjectOutputStream out = null;

		try {
			out = new ObjectOutputStream(new FileOutputStream(“out.dat”));
			BigDecimal num1 = new BigDecimal(1000);
			BigDecimal num2 = new BigDecimal(20000);
			out.writeObject(num1);
			out.writeObject(num2);
		} finally {
			out.close();
		}

		ObjectInputStream in = null;

		try {
			in = new ObjectInputStream(new FileInputStream(“out.data”));
			BigDecimal num3 = (BigDecimal) in.readObject();
			BigDecimal num4 = (BigDecimal) in.readObject();
			System.out.format("Num1 = %d. Num2 = %d",
			num3.intValue(), num4.intValue());
		} finally {
			in.close();
		}
	}
}