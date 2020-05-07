'''
	Alex Galhardo Vieira
	10408344

	Trabalho Estrutura de Dados II - Arquivos

	ICMC USP - 2018
	São Carlos - Brazil
'''

# Adicionar os dados originais toda vez que inicializar o programa.
file = open('dados.txt', 'w')
lista = []
lista.append('nro de registros = 9\n')
lista.append(' _____________________________________________________________________\n')
lista.append('|010    |Jose da Silva                           |fusca               |\n')
lista.append('|005    |Maria                                   |chevete             |\n')
lista.append('|007    |Maria                                   |fusca               |\n')
lista.append('|123    |Sebastiao                               |brasilia            |\n')
lista.append('|150    |Jose                                    |variant             |\n')
lista.append('|001    |Elisete                                 |vemaguete           |\n')
lista.append('|035    |Sebastiao                               |landau              |\n')
lista.append('|040    |Doralice                                |opala               |\n')
lista.append('|200    |Clotilde                                |maverick            |\n')
lista.append(' ---------------------------------------------------------------------\n')
file.writelines(lista)
file.close()

# adicionar indices iniciais no arquivo de indices primario.ndx
ndx = open('primario.ndx', 'w')
file = open('dados.txt', 'r')

conteudo = file.readlines()

listaIndices = []

for linha in conteudo:

	if "|" in linha:

		linha = ''.join(linha.split())
		listaPalavrasLinha = linha.split("|")

		# print(listaPalavrasLinha)
		RRN = (len(listaPalavrasLinha[2]) * len(listaPalavrasLinha[3])) * 1000
		# print(RRN)
		novoRegistroIndice = "{} {}".format(listaPalavrasLinha[1], RRN)
		# print(novoRegistroIndice)
		# ndx.write(novoRegistroIndice + "\n")
		listaIndices.append(novoRegistroIndice + "\n")

# organize em ordem crescente os dados de indice
listaIndices.sort()
# adicione os dados no arquivo de indices
ndx.writelines(listaIndices)
ndx.close()

#print(listaIndices)

# inserir dados dentro do arquivo
def inserir():

	# abre o arquivo e salve seu conteudo
	file = open('dados.txt', 'r')
	# transforma cada linha do arquivo em um item de uma lista, dentro da variavel conteudo
	conteudo = file.readlines()

	print("\n\t ...Iniciando funcao inserir...\n")

	nro = str(input('\t Digite o numero da residencia: '))
	# verifica se nro já não esta cadastrado no arquivo

	nroValido = True
	while nroValido:

		for linha in conteudo:
			if nro in linha:
				print('\n\t Nro já registrado no arquivo!')
				nroValido = False
				break

		if nroValido:
		
			nome = str(input('\t Digite o nome do residente: '))
			veiculo = str(input('\t Digite o nome do veiculo do residente: '))

			# remove ultimos traços do arquivo
			ultimo = len(conteudo) - 1
			conteudo.remove(conteudo[ultimo])

			tamanhoEspacosNome = 40 - len(nome)
			tamanhoEspacosVeiculo = 20 - len(veiculo)
			espacos = " "

			# pegue total de espaços entre os nomes e os veiculos, que é variável
			totalEspacosNome = espacos * tamanhoEspacosNome
			totalEspacosVeiculo = espacos * tamanhoEspacosVeiculo

			conteudo.append('|{}    |{}{}|{}{}|\n'.format(nro, nome, totalEspacosNome, veiculo, totalEspacosVeiculo))
			conteudo.append(' ---------------------------------------------------------------------\n')

			# atualize o nro de registros do arquivo
			novoRegistro = "nro de registros: {}\n".format(len(conteudo)-3)
			conteudo.pop(0)
			conteudo.insert(0, novoRegistro)

			# mostrando linhas do novo conteudo
			print('\n')
			for linha in conteudo:
				print(linha)
			file.close()
			
			# adicione novo dado também no arquivo de indices
			# organize os dados

			# pegue os dados do arquivo de indices
			ndx = open('primario.ndx', 'r')
			conteudoNDX = ndx.readlines()
			ndx.close()

			# crie o novo RNN
			RRN = (len(nome) * len(veiculo)) * 1000
			novoIndice = "{} {}".format(nro, RRN)
			# adicione no conteudo de indices e organize
			conteudoNDX.append(novoIndice + "\n")
			conteudoNDX.sort()

			# adicione os novos dados ordenados no arquivo de indices
			ndx = open('primario.ndx', 'w')
			ndx.writelines(conteudoNDX)
			ndx.close()

			# abra o arquivo de dados e adicione os dados inseridos pelo usuario
			file = open('dados.txt', 'w')
			file.writelines(conteudo)
			file.close()
			break


# função que adiciona '$' nas linhas que serão deletadas do arquivo
def remover():

	print('\n\t ...Iniciando função remover...\n')

	file = open('dados.txt', 'r')
	
	while True:
		# peça o numero da residencia que se deseja alterar
		nro = str(input('\n\t Digite o nro da residencia que deseja remover: '))
		# A função readlines() retorna cada linha do arquivo como um elemento de uma lista. 
		conteudo = file.readlines()
		# inicia uma variavel para armazenar numero da residencia
		numeroResidencia = ''
		# cria uma variavel para verificar se o numero digitado está contido no arquivo
		encontrou = False

		# para cada linha dentro do arquivo
		print('\n')
		for linha in conteudo:

			# se a linha possuir o numero digitado pelo usuario
			if nro in linha:

				# marque com um '$' na frente do dado que será deletado no arquivo de indices
				ndx = open('primario.ndx', 'r')
				conteudoNDX = ndx.readlines()
				ndx.close()
				# para cada linha dentro do arquivo de indices
				for linhaNDX in conteudoNDX:
					# se tiver o nro no arquivo de indices
					if nro in linhaNDX:
						# atualize o indice com o simbolo '$' na frente
						indiceParaDeletar = linhaNDX[:1] + '$' + linhaNDX[1:]
						print(linhaNDX)
						# adicione a linha para deletar no index da linha antiga
						conteudoNDX.insert(conteudoNDX.index(linhaNDX), indiceParaDeletar)
						# retire o dado sem a marcação para delete
						conteudoNDX.remove(linhaNDX)
						# atualize o arquivo de indices com a linha que será deletada na função compactar
						ndx = open('primario.ndx', 'w')
						ndx.writelines(conteudoNDX)
						ndx.close()


				# marque com um '$' na frente do dado que será deletado do arquivo de dados
				dadoParaDeletar = linha[:1] + '$' + linha[1:]
				print(dadoParaDeletar)
				index = conteudo.index(linha)
				conteudo.insert(index, dadoParaDeletar)
				conteudo.remove(linha)
				file.close()
				file = open('dados.txt', 'w')
				file.writelines(conteudo)
				file.close()
				encontrou = True
				break
		
		if encontrou:
			print('\n\t Numero de residencia marcado para delete com sucesso!\n\n')
			file.close()
			break
		else:
			print('\n\t Numero de residencia nao encontrado!\n')
			break

def procurar():

	# procura pela chave e print os dados
	nro = str(input('\n\t Digite o nro da casa para ver os dados: '))

	file = open('dados.txt', 'r')
	conteudo = file.readlines()

	nroEncontrado = False

	for linha in conteudo:
		if nro in linha:
			# print('\n\t O numero {} existe no arquivo!'.format(nro))
			# print(linha)
			linha = ''.join(linha.split())
			listaPalavrasLinha = linha.split("|")
			print('\n\t O nro é {}, o nome é {} e o carro é {}\n'.format(listaPalavrasLinha[1], listaPalavrasLinha[2], listaPalavrasLinha[3]))
			file.close()
			nroEncontrado = True
			break

	if not nroEncontrado:
		print('\n\t Nro não encontrado!\n')

# Verifique cada linha do arquivo, se tiver '$' na frente do NRO, delete essa linha
def compactar():
	
	print('\n\t ...Iniciando função Compactar...\n')

	file = open('dados.txt', 'r')
	
	while True:
		# A função readlines() retorna cada linha do arquivo como um elemento de uma lista. 
		conteudo = file.readlines()
		# cria uma variavel para verificar se alguma linha foi deletada do arquivo
		arquivoCompactado = False

		# para cada linha dentro do arquivo
		for linha in conteudo:

			deletar = '$'

			# se a linha possuir o '$' na frente do nro, delete essa linha do arquivo
			if deletar in linha:

				# delete registro do arquivo de indices
				ndx = open('primario.ndx', 'r')
				indices = ndx.readlines()
				ndx.close()
				for indice in indices:
					if deletar in indice:
						indices.pop(indices.index(indice))
						break

				# atualize o arquivo de indices
				ndx = open('primario.ndx', 'w')
				indices.sort()
				ndx.writelines(indices)
				ndx.close()

				print(linha)
				conteudo.remove(linha)
				file.close()
				file = open('dados.txt', 'w')
				file.writelines(conteudo)
				file.close()

				nRegistros = conteudo[0]
				nRegistros = ''.join(nRegistros.split())
			
				arquivoCompactado = True

		novoRegistro = "nro de registros: {}\n".format(len(conteudo)-3)

		conteudo.pop(0)
		conteudo.insert(0, novoRegistro)

		# abra o arquivo e adicione o dado nro de registros decrementado atualizado
		file = open('dados.txt', 'w')
		file.writelines(conteudo)
		file.close()

		if arquivoCompactado:
			print('\n\t Arquivo compactado com sucesso!\n\n')
			file.close()
			break
		else:
			print('\t Nenhum item foi deletado do arquivo!')
			break


def alterar():

	print('\n\t ...Iniciando função alterar...\n')

	# procura pela chave e print os dados
	nro = str(input('\n\t Digite o nro da casa que deseja alterar: '))

	nroEncontrado = False

	file = open('dados.txt', 'r')
	conteudo = file.readlines()
	file.close()

	# para cada linha dentro do arquivo
	# CONTEUDO --> LISTA DE LINHAS
	# LINHA -> cada linha do arquivo
	for linha in conteudo:

		# se existir o nro digitado pelo usuário na linha
		if nro in linha:
			
			linha = ''.join(linha.split())

			nroEncontrado = True

			# listaPalavrasLinha --> ('', nro, nome, veiculo, '')
			# [1] -> nro
			# [2] -> nome
			# [3] -> veiculo
			listaPalavrasLinha = linha.split("|")

			nro = listaPalavrasLinha[1]
			nome = listaPalavrasLinha[2]
			veiculo = listaPalavrasLinha[3]

			tamanhoEspacosNome = 40 - len(nome)
			tamanhoEspacosVeiculo = 20 - len(veiculo)
			espacos = " "

			# pegue total de espaços entre os nomes e os veiculos, que é variável
			totalEspacosNome = espacos * tamanhoEspacosNome
			totalEspacosVeiculo = espacos * tamanhoEspacosVeiculo
			
			print('\t O nro é {}, o nome é {} e o carro é {}\n\n'.format(listaPalavrasLinha[1], listaPalavrasLinha[2], listaPalavrasLinha[3]))
			
			# enquanto usuário não digitar 0
			while True:

				print('\n\t O que voce gostaria de alterar?')
				print('\t Digite [1] --> Nro')
				print('\t Digite [2] --> Nome do residente')
				print('\t Digite [3] --> Nome do veiculo')
				print('\t Digite [0] --> Cancelar alteração')
				
				opcao = int(input('\t Opcao: '))
				
				# opcao invalida
				if opcao < 0 or opcao > 3:
					print('\t Opcao Invalida!')

				# cancelar alteração
				elif opcao == 0:
					break

				# mudar nro
				elif opcao == 1:

					novoNRO = str(input('\n\t Digite novo nro: '))
					
					file = open('dados.txt', 'r')
					conteudo = file.readlines()
					file.close()

					# verifique se já não existe esse mesmo nro registrado no arquivo
					nroValido = True
					
					while nroValido:

						for linha in conteudo:
							if novoNRO in linha:
								print('\n\t Nro já registrado no arquivo!')
								nroValido = False
								break

						novoRegistroNRO = '|{}    |{}{}|{}{}|\n'.format(novoNRO, listaPalavrasLinha[2], totalEspacosNome, listaPalavrasLinha[3], totalEspacosVeiculo)
						# retire a linha toda do index da linha
						indexLinha = conteudo.index(linha)-1
						conteudo.pop(indexLinha)
						# adicione o novoRegistroNRO nesse mesmo index da linha retirada
						conteudo.insert(indexLinha, novoRegistroNRO)
						file = open("dados.txt", 'w')
						file.writelines(conteudo)
						file.close()
						print('\n\t Nro atualizado com sucesso!')
						break

				# mudar nome do residente
				elif opcao == 2:
					
					novoNomeResidente = str(input('\n\t Digite o novo nome do residente: '))

					file = open('dados.txt', 'r')
					conteudo = file.readlines()
					file.close()

					nomeAtualizado = '|{}    |{}{}|{}{}|\n'.format(nro, novoNomeResidente, totalEspacosNome, veiculo, totalEspacosVeiculo)
					# retire a linha toda do index da linha
					indexLinha = conteudo.index(linha)-1
					conteudo.pop(indexLinha)
					
					# adicione nova linha com nome atualizado dentro do arquivo
					conteudo.insert(indexLinha, nomeAtualizado)
					file = open("dados.txt", 'w')
					file.writelines(conteudo)
					file.close()

					print('\t Nome atualizado com sucesso!')

				# mudar nome do veiculo
				else:

					novoNomeVeiculo = str(input('\n\t Digite o novo nome do veiculo: '))
					
					file = open('dados.txt', 'r')
					conteudo = file.readlines()
					file.close()

					veiculoAtualizado = '|{}    |{}{}|{}{}|\n'.format(nro, nome, totalEspacosNome, novoNomeVeiculo, totalEspacosVeiculo)
					# retire a linha desatualizada do antigo veiculo
					indexLinha = conteudo.index(linha)-1
					conteudo.pop(indexLinha)
					
					# adicione nova linha com nome atualizado dentro do arquivo
					conteudo.insert(indexLinha, veiculoAtualizado)
					file = open("dados.txt", 'w')
					file.writelines(conteudo)
					file.close()

					print('\n\t Veiculo atualizado com sucesso!')

			
			break

	if not nroEncontrado:
		print("\n\t Nro não encontrado!")

def start():

	while True:

		while True:

			print('\n\t Digite [1] --> Inserir')
			print('\t Digite [2] --> Remover')
			print('\t Digite [3] --> Alterar')
			print('\t Digite [4] --> Procurar')
			print('\t Digite [5] --> Compactar')
			print('\t Digite [6] --> Sair')
			opcao = int(input('\t Opcao: '))

			if (opcao < 1 or opcao > 6):
				print('\n\t Digite um comando válido!\n')
				continue
			else: 
				break

		if opcao == 1:
			inserir()
		elif opcao == 2: 
			remover()
		elif opcao == 3:
			alterar()
		elif opcao == 4:
			procurar()
		elif opcao == 5:
			compactar()
		else:
			break


# comece o programa
start()
