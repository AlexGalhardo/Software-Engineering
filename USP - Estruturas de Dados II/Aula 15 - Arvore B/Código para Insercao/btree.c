#include <stdio.h>
#include <stdlib.h>
#include "btree.h"


/*
	Imprime as chaves da arvore B, recursivamente.. semelhante a in-ordem... 

*/
void imprimeArvore(No *raiz){
	// se a raiz da arvore não for NULO
	if (raiz != NULL){
		imprimeArvore(raiz->filhos[0]);
		for (int i = 1; i <= raiz->cont; i++)
		{
			printf("%c ", raiz->chaves[i]);
			imprimeArvore(raiz->filhos[i]);
		}
	}
}


/*
	faz uma busca SEQUENCIAL em no para encontrar a chave
	O no tem as chaves ordenadas.. comecamos do fim e vamos ate chave[2]
	returna verdadeiro se encontrar, retorna falso, caso contrario..
*/

int buscaChave(chave ch, No *no, int *pos){
	if (ch < no->chaves[1]){
		*pos = 0;       // busca nos filhos[0]
		return 0;       // nao encontrou neste no...
	}

	// percorre o vetor inteiro e veja se encontra
	for (*pos = no->cont; ch < no->chaves[*pos] && *pos > 1; (*pos)--);
	
	return (ch == no->chaves[*pos]);
}


/*
	Percorre a arvore B procurando pela chave.
	Se encontrou, retorna um ponteiro para o nó onde
	se encontra a chave. posicao conterá o indice em que se encontra a chave neste no.
	Caso contrario, retorna NULL
*/
No *buscaArvore(chave ch, No *raiz, int *posicao){
	if (!raiz) // nao existe árvore
		return NULL;
	// pesquisa a chave no vetor chave do nó corrente.
	if (buscaChave(ch, raiz, posicao))  // se encontrou a chave neste no, retorna este no (root)
		return raiz;    

	return buscaArvore(ch, raiz->filhos[*posicao], posicao);
}




/*
	Insere uma chave na árvore em uma arvore apontada para raiz (pode ser NULL) e retorna
	a raiz da arvore... VAmos assumir que a chave a ser inserida NAO está na arvore (portanto, ja fizemos uma 
	busca nela..)
*/

No *insereArvore(chave ch, No *raiz){
	
	char novaChaveRaiz; // se ocorrer overflow no nó corrente, esta sera a chave que "subirá" para ser a nova raiz !!
	No *direita; // o novo nó à direita !!!
	No *novaRaiz;

	//Insere o nó em raiz... se ocorreu overflow no no raiz,
	// cria o novo no à direita e devolve tambem a nova raiz da árvore
	if (overflow(ch, raiz, &novaChaveRaiz, &direita)){
		novaRaiz = (No *)malloc(sizeof(No));
		novaRaiz->cont = 1;
		novaRaiz->chaves[1] = novaChaveRaiz;
		novaRaiz->filhos[0] = raiz;
		novaRaiz->filhos[1] = direita;
		return novaRaiz;     // a nova raiz da árvore é novaRaiz
	}
	return raiz;   // nao houve overflow, retorna a propria raiz..
}

/*
	Percorre a árvore top down procurando o nó correto para inserir ch no nó raiz.
	retorna TRUE se a altura da árvore crescer, caso em que a chaveMeio deve ser
	inserida mais acima na árvore, tendo dir o nó à sua direita.
*/
int overflow(chave ch, No *raiz, chave *chaveMeio, No **dir){

	// nao tem como inserir nada em uma arvore vazia, entao a árvore cresce..
	if (raiz == NULL){
		*chaveMeio = ch;
		*dir = NULL; 
		return 1;        // a árvore cresceu !!!
	}

	int pos;
	// procura pela chave no no corrente, nao deve existir, mas precisamos saber em que posicao continuar a busca !!
	if (buscaChave(ch, raiz, &pos)){
		printf("Opa.. a chave %c ja está na árvore.. nao deveria...", ch);
	}
	// chama recursivo para continuar a busca e inserçao até a 
	if (overflow(ch, raiz->filhos[pos], chaveMeio, dir)){
		if (raiz->cont < MAX) { // tem espaco no nó raiz para mais uma chave.
			insereNo(*chaveMeio, *dir, raiz, pos);
			return 0;    // a arvore nao cresceu.
		}
		else { // Agora sim, aconteceu o overflow e devemos dividir o no 
			printf("Opa... deu split para a chave %c = no nó cujo primeiro elemento eh = %c \n", *chaveMeio, raiz->chaves[1]);
			split(*chaveMeio, *dir, raiz, pos, chaveMeio, dir);
			return 1;
		}
	}
	return 0;
}

/*
	A chave ch deve ser inserida no nó raiz, ordenadamente. 
	MAs para isso pode ser preciso deslocar chaves e filhos para a direita
	ch será colocada em chave[pos+1]
	O vetor é percorrido da maior para a menor chave....
*/
void insereNo(chave ch, No *dir, No *raiz, int pos){
	// desloca para a direita....
	for (int i = raiz->cont; i > pos; i--)
	{
		raiz->chaves[i+1] = raiz->chaves[i];
		raiz->filhos[i+1] = raiz->filhos[i];
	}

	// agora insere a chave na posicao pos+1, nao se esquecendo de atualizar o seu nó a direita !!!
	raiz->chaves[pos+1] = ch;
	raiz->filhos[pos+1] = dir;
	raiz->cont++;    // nao se esqueca de incrementar cont, como eu esqueci e fiquei meia hora debugando...
}


/*
	Separa um nó que está cheio;;;;
	a chave a ser inserida é chaveMeio. dir é o no a direita da chaveMeio.
	o novo nó a direita é novoDir e a nova chave do meio que será novaChaveMeio..
*/

void split(chave chaveMeio, No *dir, No *raiz, int pos, chave *novaChaveMeio, No **novoDir){

	int corte; 
	if (pos <= MIN) // determina o ponto de corte do no raiz, ou seja, quantos elementos deveremos transferir para o novo nó 
		corte = MIN;
	else corte = MIN+1;

	*novoDir = (No *)malloc(sizeof(No));  // aloca o novo nó a direita
	// copia de corte+1 os elementos de raiz->chaves para o novo no
	for (int i = corte+1; i <= raiz->cont; ++i)
	{
	     (*novoDir)->chaves[i-corte] = raiz->chaves[i];
	     (*novoDir)->filhos[i-corte] = raiz->filhos[i];
	}
	// atualiza o tamanho de raiz e do novo nó a direita
	(*novoDir)->cont = raiz->cont - corte;
	raiz->cont = corte;
	
	// agora temos que inserir a chaveMeio ... ela por ir no no raiz ou no novo nó
	// depende que tipo de chave é... isso nós podemos fazer vendo o valor de pos com relacao a MIN
	if (pos <= MIN) // a chave é pequena e deve ser colocada no nó raiz...
		insereNo(chaveMeio, dir, raiz, pos);
	else     // a chave é maior e deve ir no NOVO no a direita
	   insereNo(chaveMeio, dir, *novoDir, pos-corte);

	 // neste ponto algo interessantissimo. ONDE está a novaChaveMeio, que deve ser passada para
	 // cima para ser inserida em algum nó acima (pode ser inclusive a nova raiz)???
	 // RESPOSTA: está no ultimo slot de raiz !!!!!

	 *novaChaveMeio = raiz->chaves[raiz->cont];

	 // O comando abaixo só pode ser entendido se vc atingiu o NIRVANA com árvores B...
	 (*novoDir)->filhos[0] = raiz->filhos[raiz->cont];

	 // finalmente, decrementa o contador de raiz, pois afinal de contas a chave que vai subir
	 // foi tirada de la...
	 raiz->cont--;
}


/************************************************************************************************
                          FUNCOES PARA DELECAO 
************************************************************************************************/

/*
	Funcao principal, recursiva, de remocao na arvore B
*/

No  *removeArvore(chave ch, No *raiz){
	int pos;   // armazena a posicao da chave na pagina....
	if (raiz == NULL){
		printf("Opa... a chave %d = nao está na arvore..... \n", ch);
		return raiz;
	}

	// se encontrou a chave na raiz
	if (buscaChave(ch, raiz, &pos)){
		// Se o nó NAO for folha......
		if (raiz->filhos[pos] != NULL) {
			// localiza sucessor (que está na folha) e o coloca no lugar de chave no no raiz: raiz->chaves[pos]
			sobeSucessor(raiz, pos);
			// chama recursivamente para remover o sucessor lá no nó folha !!!!
			removeArvore(raiz->chaves[pos], raiz->filhos[pos]);
		}
		else // opa... Nó é folha... simplesmente remove a chave da posicao pos em raiz
			 removeChave(raiz, pos);

	} else   
	   removeArvore(ch, raiz->filhos[pos]);  // se nao encontrou, desce recursivamente...

	// removeChave remove uma chave na posicao pos do no raiz..
	// Observe, no entanto, que nao verificamos se este no violou a regra do numeto minimo de
	// chaves na pagina!...VEJA O SLIDE 42 (remocao da chave R),.... devemos neste caso fazer uma
	// restauracao... Mas QUANDO identificaremos este caso???
	// R: na volta da recursao, ao "voltarmos" ao nó pai, de onde removemos a chave !!!!
	// Incrível, não é??????
	if (raiz->filhos[pos])
	   if (raiz->filhos[pos]->cont < MIN){
			restauraArvore(raiz, pos);
			// tem um erro no livro.. ele nao verifica o caso em que 
			// a raiz se esvaziou e existe um filho (raiz->filhos[0]) com o que sobrou
			// da ultima combinacao possivel (pense na remocao em que a raiz tem apenas uma chave
			// e seus dois filhos nao tem o minimo suficiente de chaves...)
			// ao final deste processo, a raiz ficará vazia.. e todos as chaves restantes
			// estarao no filho à esquerda !!!!
			// entao é preciso fazer com que, neste caso, a raiz nova seja o filho[0] !!!
			if (raiz->cont == 0)
				return (raiz->filhos[0]);
	   }

	return raiz;
}


/*
	raiz é o no em que se contrar a chave a ser removida na posicao pos.
	O sucessor é facil de achar.. vai para raiz->filhos[pos] (que é um nó a direita de raiz)
	e de lá vai descendo o mais a esquerda possivel no->filhos[0] até o último nivel.
	A chave que procuramos estará no no folha->chaves[0]... certo ???????
	pega esta chave e armazena em raiz->chaves[pos]  !!!!
*/

void sobeSucessor(No *raiz, int pos){
	No *folha;

    // faz o caminho descrito no comentario (uma à direita e desce tudo pela esquerda )
	for (folha = raiz->filhos[pos]; folha->filhos[0] != NULL; folha = folha->filhos[0]);

	// chegando lá, copia a chave encontrada na raiz, na posicao pos....
	raiz->chaves[pos] = folha->chaves[1];
}

/*
	remove a chave localizada na posicao pos do nó raiz...
	basta deslocar todo munda à direita de pos uma posicao para tras..
*/

void removeChave(No *raiz, int pos){
	for (int i = pos+1; i <= raiz->cont; i++)
	{
		raiz->chaves[i-1] = raiz->chaves[i];
		raiz->filhos[i-1] = raiz->filhos[i];
	}
	//opa.. nao esqueca de diminuir cont...
	raiz->cont--;
}


/*
	O nó apontado por pos em raiz (raiz->filhos[pos]) TEM UNDERFLOW nele
	Devemos tratar este caso....As vezes devemos apenas "emprestar" de um "irmao"
	Outras vezes, teremos que COMBINAR todo mundo, lembra-se?? 
	veja os slides da aula......
*/

void restauraArvore(No *raiz, int pos){

	// o no com UNDERFLOW é o mais à esquerda.. ou seja... o único que
	// pode "emprestar" chave é o seu irmao à direita, certo????
	if (pos == 0){
		// Se for possivel emprestar do nó à direita
		if (raiz->filhos[1]->cont > MIN)
			moveParaEsquerda(raiz, 1);    //move do irmao 1 para o irmao 0
		else combinaIrmaos(raiz, 1);  // nao tem para emprestar, combina irmaos 0 e 1 com a raiz..
	} else  // eh algum outro irmao que nao o pos == 0....
	    // então verifica se o no com UNDERFLOW é o mais à direita (ultimo)
	    if (pos == raiz->cont) {
	    	// tem como emprestar do irmao imediatamente à esquerda ?
	    	if (raiz->filhos[pos-1]->cont > MIN)
	    		moveParaDireita(raiz, pos); // move do irmao pos-1 para o irmao pos !!!!
	    	else combinaIrmaos(raiz, pos);

	    } else   // agora o caso mais geral: pos é um irmao que tem candidatos á doacao tanto à esq quanto à dir.
	    	// verifica o irmao à esquerda primeiro
	        if (raiz->filhos[pos-1]->cont > MIN)
	        	moveParaDireita(raiz, pos);
	        else if (raiz->filhos[pos+1]->cont > MIN)
	        			moveParaEsquerda(raiz, pos+1);
	        	 else // nenhum dos irmãos tem como emprestar... combina todo mundo...
	        	 	combinaIrmaos(raiz,pos);
}


/*
	VAmos pegar uma chave do irmao à esquerda (pos-1) e levar para o irmao com UNDERFLOW em pos
	Entao, o irmao que tem menos chaves é o pos... (diferentemente do moveParaEsquerda)
*/

void moveParaDireita(No *raiz, int pos){
  No *direita = raiz->filhos[pos];

  // move todo mundo do no direita, uma posicao para frente
  for (int i = direita->cont; i > 0; i--)
  {
  	direita->chaves[i+1] = direita->chaves[i];
  	direita->filhos[i+1] = direita->filhos[i];
  }
  direita->cont++;  //  o no direita tem mais uma chave, claro.
  
  // o loop acima desloca os filhos à direita, mas temos que tratar a excecao da posicao 0
  direita->filhos[1] = direita->filhos[0];

  // ok.. agora copia a chave do pai raiz na posicao pos para a nova posicao vazia (1) no nó direita !!
  direita->chaves[1] = raiz->chaves[pos];

  // agora copia para a posicao pos em raiz ou ultimo elemento do filho em pos-1
  raiz->chaves[pos] = raiz->filhos[pos-1]->chaves[raiz->filhos[pos-1]->cont];

  // por fim, nao se esquecao de decrementar o contador do filho de raiz em pos-1
  raiz->filhos[pos-1]->cont--;

}

/*
	VAmos pegar uma chave do irmao à direita (pos) e levar para o irmao com UNDERFLOW em pos-1
	Entao, o irmao que tem menos chaves é o pos-1... (diferentemente do moveParaEsquerda)
*/
void moveParaEsquerda(No *raiz, int pos){

	No *esquerda = raiz->filhos[pos-1];
	esquerda->cont++;   // ja podemos incrementar o contador de esquerda e colocar o novo elemento lá

	//Este novo elemento em esquerda é a chave da raiz em pos...
	esquerda->chaves[esquerda->cont] = raiz->chaves[pos];

	// claro que temos que atribuir o que vai em esquerda->filhos[esquerda->cont]. QUEM É ?????
	// aha... é a filhos[0] do nó seu irmao na posicao pos !!!1 Incrivel.....
	// para facilitar, vamos criar um ponteiro para o irmão em po
	No *irmaoempos = raiz->filhos[pos];
	esquerda->filhos[esquerda->cont] = irmaoempos->filhos[0];

	// agora copia a primeira chave do irmao em pos para a raiz na posicao pos...
	raiz->chaves[pos] = irmaoempos->chaves[1];

	// temos sempre que tratar a excecao da posicao zero.. 
	irmaoempos->filhos[0] = irmaoempos->filhos[1];
	irmaoempos->cont--;  // lembre-se de que o irmao na posicao pos perdeu uma chave..

	// agora basta deslocar todo mundo do irmao em pos uma posicao para tras
	for (int i = 1; i <= irmaoempos->cont; i++)
	{
		irmaoempos->chaves[i] = irmaoempos->chaves[i+1];
		irmaoempos->filhos[i] = irmaoempos->filhos[i+1];
	}
}


/*
	Combina os irmaos pos e pos-1 com a raiz, juntando tudo... ambos irmao em pos e pos-1 
	nao tem chaves suficientes...na verdade o irmao em pos tem menos chaves que o irmao em pos-1	
*/

void combinaIrmaos(No *raiz, int pos){
	No *direita = raiz->filhos[pos];
	No *esquerda = raiz->filhos[pos-1];

	// primeiro vamos colocar a chave da posicao pos do pai (raiz) no final do nó esquerdo ...
	esquerda->cont++; 
	esquerda->chaves[esquerda->cont] = raiz->chaves[pos];
	// sempre tem que atulizar filhos junto com chaves...
	esquerda->filhos[esquerda->cont] = direita->filhos[0];

	// agora copia as chaves e filhos do no à direita para o no à esquerda..
	for (int i = 1; i <= direita->cont; i++)
	{
		esquerda->cont++;
		esquerda->chaves[esquerda->cont] = direita->chaves[i];
		esquerda->filhos[esquerda->cont] = direita->filhos[i];
	}

	// por fim, nao se esqueca de deslocar as chaves e filhos do no raiz uma posicao para esquerda
	for (int i = pos; i < raiz->cont; i++)
	{
		raiz->chaves[i] = raiz->chaves[i+1];
		raiz->filhos[i] = raiz->filhos[i+1];
	}
	// a folha perdeu uma chave...
	raiz->cont--;

	// Claro, o nó direita nao existe mais
	free(direita);
	// UFA.. terminou.....

}
