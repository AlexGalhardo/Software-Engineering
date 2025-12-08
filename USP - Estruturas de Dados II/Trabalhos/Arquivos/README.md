Especificação do Projeto 2


Fazer um programa que controle a entrada de veículos em um determinado lugar.
Por controle, entenda-se permitir a: 

a) inserção; b) alteração; c) remoção; d) pesquisa

Cada registro é composto por 3 campos, como apresentados na tabela
TabelaInicial.txt

Os campos são: 	
		- Nro da residência (tamanho fixo, de 3 dígitos - sempre)
		- Nome do residente ou visitante (tamanho variável, mas no máximo 40 caracteres)
		- Modelo do veículo (tamanho variável, mas no máximo 20 caracteres)

IMPORTANTÍSSIMO: 
	- tudo que você tem NO INÍCIO, é a tabela TabelaInicial.txt. 
		O FORMATO DELA É EXATAMENTE COMO ESPECIFICADO no modelo que você vê aqui.

		Portanto, NÃO altere-o. Você DEVERÁ utilizar EXATAMENTE este modelo para iniciar o seu programa.

	- a TabelaInicial.txt NAO DEVE SER PASSADA COMO ARGUMENTO, ja que seu nome 
	é imutável. PORTANTO, não use argv e argc no seu programa.

A partir da TabelaInicial.txt, você deve (UMA ÚNICA vez):
		a) construir um arquivo principal de dados, cujo nome DEVE ser: dados.txt 
		(letras minúsculas, exatamente como está)
		
		b) construir um arquivo de índice primário, cujo nome DEVE ser: primario.ndx
		(também em minúsculas)

O arquivo de dados (dados.txt) tem as seguintes características:

		- Ele deve ser GRAVADO NO FORMATO ASCII. Isso vai facilitar a depuração
		e com isso será mais fácil verificar se seu programa está funcionando  corretamente

		- Ele pode armazenar os dados pode meio de registros de TAMANHO FIXO ou 
		TAMANHO VARIÁVEL.   
			
			* Se for tamanho fixo, observe o tamanho máximo das strings para cada 
		  	 um dos campos estabelecido acima (3, 40 e 20). 

		  	* Se for tamanho variável, utilize separadores, para distiguir um campo 
  		     do outro. (vc pode utilizar, por exemplo o caracter '*', '$', '#', etc)

O arquivo de índices (primario.ndx), por sua vez, tem as seguintes características:

		- Também armazenado em formato ASCII. 
		
		- Contém DOIS CAMPOS: a chave primária (o nro da residência) e o RRN do registro.

		- ATENÇÃO SOBRE O RRN:
			
			- se você optou por usar registros de tamanho fixo, então o seu RRN 
			  é de fato um valor relativo. Voce pode optar por colocar cada registro
			  em uma linha diferente no arquivo e o RRN seria então um valor que 
			  permitisse apontar para o início da linha em que está o referido registro
			  (simples assim).

			- se você optou por utilizar registros de tamanho variado, então o RRN é de
			  fato o valor absoluto do byte inicial ocupado pelo registro no arquivo.
			  Neste caso, o seu arquivo ficaria mais "feio" de se ver, mas seria mais 
			  compacto! Gastaria menos espaço em disco.
			  
		
		- o arquivo de índices deve armazenar as chaves em ordem crescente de valores
		
		- o campo chave, como já dito, será armazenado como uma string numérica de tamanho 3, sempre.
		
		- o campo RRN deverá ser armazenado como um string numérica de tamanho 5, sempre.

		- Portanto, o registro do arquivo "primario.ndx" é de tamanho fixo e deve possuir o seguinte formato:
				001 00000
				004 00056
				010	00NNN
				101 NNNNN
                       
		ou seja, o primeiro registro de chave 001 tem RRN = 00000, o  segundo registro de chave 004 tem RRN = 00056, e assim por diante.


IMPORTANTE: 

- o arquivo de dados principal (dados.txt) é sempre mantido em disco. Nunca vai para memória. 
	    
- o arquivo de indice primário é SEMPRE manipulado na memória PRIMÁRIA. 
	Portanto, defina QUALQUER estrutura que queira para manipular este arquivo em RAM. 
	No início do programa você deverá ler o arquivo de índices e armazenar todos 
	os registros em memória primária. Ao terminar o programa, não se esqueça de
	sobrescever o arquivo para manter a integridade dos dados.  
		*** A estrutura em RAM DEVE ESTAR ORDENADA PELA CHAVE, de forma que qualquer
		 consulta a este arquivo seja feita por BUSCA BINARIA.



 ************************  AS OPERAÇÕES BÁSICAS  *****************************



INSERÇÃO: 	

- sempre inserir um novo registro ao FINAL do arquivo dados.txt.  

REMOÇÃO: 	

- ao remover, faça o MÍNIMO de alterações possíveis no arquivo de dados. Apenas 
marque um caracter do registro para indicar remoção. Exemplo: suponha que vc 
quer remover o registro

-->>>>  |010    |Jose da Silva   |fusca   |

Removê-lo significa mofificar este registro para:

-->>>>  |$10    |Jose da Silva   |fusca   |

apenas trocamos o primeiro dígito do NRO, por '$'



ALTERAÇÃO: 

- pode-se alterar QUALQUER UM dos TRÊS campos do registro. Claro que chaves primárias 
não podem ser DUPLICADAS. Portanto, faça as devidas verificações antes de aceitar 
a operação.

COMPACTAÇÃO:

- Eliminar todos os registros "removidos", ou seja, aqueles registros que foram 
marcados com o caracter especial, serão definitivamente eliminados do arquivo, 
diminuindo o seu tamanho efetivamente.


>>>>>>>>>> IMPORTANTE
>>>>>>>>>> 
>>>>>>>>>> O SEU PROGRAMA DEVE TER UM MENU com as seguintes opções:
		1) inserir
		2) remover
		3) alterar
		4) procurar
		5) compactar
		6) sair
 
Dados de entrada:

INSERÇÃO:  nro, nome e veículo;

REMOÇÃO: nro 

ALTERAÇÃO: nro
 		se o registro existir, qq um dos três campos poderão ser solicitados e modificados.

COMPACTAÇÃO: não possui. Apenas realiza a operação

FINALMENTE:  Todas as operações acima devem vir acompanhadas das respectivas mensagens 
de sucesso ou erro.
	Exemplo: se na inserção já houver veículo com aquela chave, mostre uma msg de 
	erro do tipo "chave duplicada". Caso contrário, mostre mensagem tal como: 
	"veículo inserido com sucesso"


A PERGUNTA QUE NÃO QUER CALAR.

***  Os índices são manipulados em memória principal e só serão atualizados 
quando o programa terminar. Suponha que o programa está rodando e foram feitas 
várias operações (inserções, remoções, modificações, etc). Certamente os índices 
que estão em RAM são diferentes dos que estão no disco - o programa ainda não 
terminou e, portanto, ainda não foi atualizado em disco!  Mas neste ponto, acaba 
a energia ou o computador pifa !!!

Você concorda que o seu arquivo de índices NÃO está CONSISTENTE com o arquivo de 
dados, e que quando o programa "voltar", este arquivo de índices não poderá ser 
usado? 

Você tem então que "recuperar" o arquivo de índices !!!

Como???

Dica: pense num "flag" mantido em disco (um arquivo pequeno, separado). 

Seu programa DEVE ser capaz de se recuperar deste crash...



Boa diversão.


