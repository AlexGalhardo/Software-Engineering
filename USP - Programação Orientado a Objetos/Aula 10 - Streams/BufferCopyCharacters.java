import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class BufferCopyCharacters {

	public static void main(String[] args) throws IOException {

		FileReader in = null;
		BufferedReader buffIn = null;
		FileWriter out = null;
		BufferedWriter buffOut = null;

		/*
		Durante processos de escrita, podemos descarregar o
		buffer, sem que ele tenha atingido seu limite
		● Flushing
		● Quando o método flush() de um stream é invocado, o
		buffer de escrita é descarregado
		● Só terá efeito prático em um stream do tipo buffered
		*/

		try {
			in = new FileReader("xanadu.txt");
			buffIn = new BufferedReader(in);
			out = new FileWriter("charoutput.txt");
			buffOut = new BufferedWriter(out);
			int c;
			while ((c = buffIn.readLine()) != null) {
				buffOut.write(c);
				buffOut.newLine();
			}
		} finally {
			if (buffIn != null)
				buffIn.close();
			if (buffOut != null)
				buffOut.close();
			}
		}