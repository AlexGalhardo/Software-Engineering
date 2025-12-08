/* STREAMS */
// entrada e saida de dados unidirecional
// 

import java.io.FileInputStream; // import biblioteca fileinput stream
import java.io.FileOutputStream; // import biblioea fileoutput stream
import java.io.IOException; // import biblioteca IOException

public class CopyBytes {

	public static void main(String[] args) throws IOException {

		//  a variável do tipo inteiro armazena um byte nos seus últimos 8 bits

		// Stream de bytes faz a leitura

		FileInputStream in = null; 
		FileOutputStream out = null;

		try {
			in = new FileInputStream("xanadu.txt");
			out = new FileOutputStream("byteoutput.txt");
			int c;
			// enquanto tiver dados entrado em c
			// pegue os dados e lance para o arquivo byteoutput
			while ((c = in.read()) != -1) {
				out.write(c);
			}
		} finally {
			// se leu os dados e objeto in não for null, feche ele
			if (in != null)
				in.close();
			// faça mesma coisa com o arquivo de output
			if (out != null)
				out.close();
			}
		}
	}
