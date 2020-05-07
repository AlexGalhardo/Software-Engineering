// import classes filereader
// import classes filewriter
// import IOException
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class CopyCharacters {

	public static void main(String[] args) throws IOException {

		// em java, 1 char possui 16 bits = 2 bytes
		// em java, 1 int possui 32 bits = 4 bytes

		// a variável armazena um caracter nos últimos 16 bits

		// Todos os caracteres da tabela ASCII são representados por 1 byte

		// Stream de caracteres converte o dado lido para caracteres

		// Todos os streams vistos até aqui são do tipo que não 
		// usam buffers de memória
        // ● Isso é, todo chamada de leitura/escrita é repassada diretamente para o SO

        /*
		Buffered Streams
		● Para tornar esse processo mais eficiente, o Java
		fornece streams que usam buffers de memória
		● Leitura
		● Sempre que uma leitura é requisitada, dados são lidos
		do buffer (memória)
		● Quando o buffer estiver vazio, novos dados são
		carregados do arquivo para o buffer
		● Escrita
		● Sempre que uma escrita é requisitada, dados são
		escritos no buffer (memória)
		● Quando o buffer estiver cheio, os dados são
		descarregados para o arquivo
        */

        /*
		Existem quatro tipos de buffered streams no Java
		● BufferedInputStream (byte)
		● BufferedOutputStream (byte)
		● BufferedReader (caracteres)
		● BufferedWriter (caracteres)
        */

		FileReader inputStream = null; // sempre crio um objeto e aponto para null
		FileWriter outputStream = null; // sempre crio um objeto e aponto para null
		
		// em java, toda vez que eu não iniciar um objeto, eu preciso apontar para null

		try {
			// objeto do tipo inputStream é um objeto filerReader de xanadu.txt
			inputStream = new FileReader("xanadu.txt");
			// objeto output stream é um objeto fileWriter de charoutput
			outputStream = new FileWriter("charoutput.txt");
			int c;

			// enquanto tiver dados em input, continue lendo
			while ((c = inputStream.read()) != -1) {
				// pegue os dados da stream de entrada e coloque na stream de saída
				outputStream.write(c);
			}
		} finally {
			if (inputStream != null)
				inputStream.close();
			if (outputStream != null)
				outputStream.close();
			}
		}
	}