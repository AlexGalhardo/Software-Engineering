lista = {} // string csv

for(let linha of lista){
	const colunas = linha.split(';')
	const id = colunas[i].replace('BOF-', '')
	const nome = colunas[6]
	const nomeComercial = colunas[7]
	const logo = colunas[12]

	lista[id] = {
		name: nomeComercial,
		logo: logo !== '0' && logo !== '#N/A' ? logo : 'https://google.com'
	}
}

console.log(JSON.stringify(lista))
