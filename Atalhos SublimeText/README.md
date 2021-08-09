-Command Palette
   - O Command Palette, nos permite pesquisar todos os comandos disponíveis no Sublime Text. O atalho para o Command Palette é Ctrl+Shift+P. Irá ser exibida uma caixa que permite a entrada de texto. Através de um algoritmo de Fuzzy Matching, o Sublime Text irá exibir as ações disponíveis. O interessante é que esse algoritmo faz uma busca por palavras que comecem com as letras informadas. Por exemplo, se você digitar “ssjs” irá escolher a opção Set Sintax: JavaScript. Além disso a Command Palette exibe o atalho para o comando pesquisado o que ajuda a decorar os atalhos.

- Abas
   - Ctrl+N  Cria uma nova aba
   - Ctrl+W  Fecha a aba atual
   - Ctrl+Shift+T    Reabre a última aba fechada

- Navegando entre Abas
   - Alt+1   Vai para a primeira aba. Podem ser usado os algarismos até 9 para ir para a aba correspondente
   - Ctrl+PageDown   Navega para a aba da esquerda
   - Ctrl+PageUp Navega para a aba da direita
   - Ctrl+Tab    Navega para a última aba visitada

- Edição de Texto
   - Crtl+Enter  Insere uma nova linha abaixo da atual e posiciona o cursor em seu início
   - Ctrl+Shift+Enter    Insere uma nova linha acima da atual e posiciona o cursor em seu início
   - Ctrl+K + Ctrl+Backspace Apaga o conteúdo da linha a esquerda do cursor
   - Ctrl+K + Ctrl+K Apaga o conteúdo da linha a direita do cursor
   - Ctrl+Delete Apaga a próxima palavra a direita
   - Ctrl+Backspace  Apaga a próxima palavra a esquerda
   - Ctrl+K, Ctrl+U  Converte o texto selecionado para upper case
   - Ctrl+K, Ctrl+L  Converte o texto selecionado para lower case
   - Ctrl+J  Concatena a linha atual com a linha anterior
   - Ctrl+Shift+Up   Move a linha ou texto selecionado para cima
   - Ctrl+Shift+Down Move a linha ou texto selecionado para baixo
   - Ctrl+Shift+K    Deleta a linha selecionada
   - Ctrl+Shift+D    Duplica a linha ou texto selecionado


- Seleção de Texto
   - Ctrl+Click do mouse Seleciona vários pontos para edição múltipla
   - Ctrl+Shift+L    Coloca um cursor de edição no final de cada linha selecionada
   - Ctrl+D  Adiciona um cursor de edição no final da próxima ocorrência da palavra selecionada
   - Ctrl+L  Seleciona a linha inteira. Se pressionado novamente, seleciona a linha abaixo
   - Ctrl+Shift+M    Seleciona todo texto entre um conjunto de chaves
   - Ctrl+Shift+A    Seleciona todo texto entre um conjunto de tags
   - Ctrl+Shift+Space    Seleciona uma parte de um contexto. Expande o contexto se pressionado múltiplas vezes
   - Menu Selection -> Invert Selection  Inverte a seleção atual, selecionando tudo que não estava selecionado


Criando seu primeiro Projeto
Cada projeto tem seu próprio arquivo de configuração, então antes de começar precisamos de um lugar para salvar os arquivos. Comece criando uma pasta, do jeito que você está acostumado a fazer, de nome sublime-projects (por exemplo).

Após, inicie um novo projeto, como de costume, criando um novo arquivo ou pasta no Sublime. Agora, vá até a opção do menu Project > Save Project As... aponte a pasta que criamos, no caso a pasta sublime-projects, de ao seu projeto um nome e salve.

Solicitar lista de projetos salvos
Para acessar uma lista com todos os projetos anteriores utilize o atalho CMD-CTRL-P. Escreva no campo de busca para filtrar a lista, de acordo com o nome do projeto, pressione enter na opção do projeto e imediatamente a pasta do projeto com arquivos é apresentada na sidebar do Sublime.

Você vai se deparar com seu projeto aberto, com as abas e os arquivos que você estava editando na ultima vez que atuou no projeto.

Atuar em diferentes projetos fica mais fácil dessa maneira.

Procurando arquivos dentro de projetos
Creio que esse recurso seja o que mais salva tempo no Sublime. Escrever é melhor que clicar quando se trata de procurar arquivos, então, com o projeto aberto, pressione CMD-P e comece a escrever!


Manipulando Tabs
As Tabs são uma maneira bem interessante de ter uma visão do estado do projeto. Muitas das vezes você vai utilizar uma tab para arquivos HTML, outra para CSS e as vezes uma para JavaScript. Com esse atalho é possível criar tabs mais rápido:

CMD-2 - adiciona duas tabs
CMD-3 - adiciona três tabs
CMD-4 - adiciona quatro tabs

Agora vamos navegar entre essas tabs:

CMD-ALT-ESQUERDA - avança uma tab
CMD-ALT-DIREITA - volta uma tab

Seleção
Não sou um fã de seleção com mouse - é muito complicado e lento. Por exemplo, comece do inicio de uma palavra, agora segure a tecla do mouse e solte após selecionar toda a palavra. A maioria das vezes você não tem a seleção que deseja. Utilize os seguintes atalhos e não se fruste!

Encontre todas as palavras declarada na seleção
Uma por uma:
Selecione qualquer palavra, e encontre palavras iguais pressionando CMD-D.

Todas de uma só vez:
Denovo, selecione uma palavra, e agora pressione CMD-CTRL-G para encontrar todas as palavras iguais no texto.

Selecionar linha por linha
Aqui selecionamos uma linha inteira, e podemos selecionar as próximas linhas, completas, pressionando o comando CMD-L.


Selecionar todos os derivados/filhos
Clique em um elemento que tenha derivados. Depois, pressione CMD-SHIFT-J e todos os elementos derivados são selecionados.


Outros formas de ganhar tempo
Mais atalhos que eu utilizo para otimizar o meu trabalho.

Ir direto a uma função
Para pesquisar uma função no arquivo em questão pressione o comando CMD-R e entre com o termo referente a função no campo de pesquisa para encontra-la no documento.

Copiar toda linha
Clique na linha que você deseja copiar e pressione o comando CMD-SHIFT-D. Agora você tem uma linha duplicada, idêntica, logo em seguida.

Trocar linhas
Pressione CMD-CTRL-↓ ou CMD-CTRL-↑ para trocar a posição de uma linha, para cima ou para baixo.


Fechando tags
Digamos que você declarou uma tag <span> e não quer fecha-la manualmente, então basta pressionar o comando CMD-ALT-.. Outro método é escrever o nome da tag, sem abrir nem fechar a tag, e pressionar a tecla TAB.


Ativar ou desativar a Sidebar/barra lateral
O Sublime Text também tem um atalho para ativar ou desativar a sidebar. Pressione os comandos CMD-K-B para alternar entre os controles.


Multiplos cliques de ação
Cria vários cliques
Você precisa de mais de um clique na tela para executar a mesma ação? Então segure a tecla CMD e clique no outro local que você precisa selecionar. Você pode repetir o processo e gerar quantas seleções desejar.


Arraste para criar vários cliques na tela
Para a primeira técnica você precisa clicar em todos lugar onde você deseja selecionar. Então identificamos a necessidade de selecionar outro elemento alinhado verticalmente. Não clique em cada um separadamente, ao invés disso pressione ALT e então, com o botão direito do mouse pressionador, selecione movendo o cursor para cima ou para baixo.

Plugin para escritores: Markdown Preview
Pessoalmente, eu utilizo Markdown no Sublime Text, mas para começar não temos nem um preview do documento. Eis que surge uma solução, chamada Markdown Preview.

Para instalar, vá até seu editor, o Sublime Text no caso, pressione as teclas CMD-SHIFT-P para abrir o gerenciador de pacotes Package Control: Install Package, e então procure por Markdown Preview e pressione enter para instalar.

Agora, abra seu arquivo Markdown, execute o comando CMD-SHIFT-P novamente e procure por Markdown - Você deve encontrar um item chamado Markdown Preview: Preview in Browser. Clique nesta opção e seu principal navegador vai abrir uma janela com o preview do arquivo markdown.


Plugins indispensáveis: Hayaku
Esse plugin te ajuda a escrever CSS mais rápido e adiciona alguns recursos de auxílio. O Hayaku pode ser comparado ao Emmet, com mais recursos especialmente para propriedades CSS.

Abreviação de valores CSS
Aqui temos alguns exemplos de abreviação de valores e propriedades criados com o Hayaku (pressione TAB para executar cada um):

por position: relative;
mt10 margin-top: 10px;
cF color: #FFF;
brr background-repeat: repeat;
tdn text-decoration: none;
Aumente & diminua os valores com o teclado
É impossível utilizar o teclado para aumentar ou diminuir valores numéricos. Para tal, coloque o cursor do mouse em um número e utilize os seguintes atalhos.

Aumente ou diminua os valores entre 0.1: ALT-CTRL-↑ ou ALT-CTRL-↓
Aumente ou diminua os valores entre 1: ALT-↑ ou ALT-↓
Aumente ou diminua os valores entre 10: ALT-SHIFT-↑ ou ALT-SHIFT-↓




- Suas preferências
Uma das primeiras coisas que você precisa saber é que o Sublime guarda suas preferências em um arquivo em formato JSon, por isso é bem fácil de entender.

Os dois arquivos que você precisa saber: Um para seus atalhos de teclado, que fica aqui Sublime Text 2 > Preferences > Key Bindings – User e outro para as definições gerais, Sublime Text 2 > Preferences > Settings – User ou CMD + ,.

Nestes dois arquivos você muda o que quiser. Coisa linda. Se você tiver que mudar qualquer coisa, lembre-se de mudar sempre no arquivo de USER, que é o seu arquivo. Assim você mantém as definições default intactas.

Uma sacada é colocar estes arquivos dentro da sua pasta de Dropbox, no GIT ou qualquer outro lugar de forma que você consiga recuperá-los quando formatar a máquina ou quando quiser configurar o Sublime em outro computador. Eu fiz coloquei os meus dentro de uma pasta no Dropbox e fiz um link simbólico para o Sublime.

Se você quiser descobrir o nome de um determinado atalho referente a um comando de teclado, basta abrir o console do Sublime com o atalho CMD+ e a cada comando de teclado que você executar, você verá o nome do comando referente a este atalho.


Lista de comandos
Sublime tem muitos comandos escondidos que podem não estar listados nos menus. Você pode acioná-los pelo teclado acionando os comandos pelo controle de acesso CMD+SHIFT+P. Lindo, não?

Package Control
Como qualquer outro editor o Sublime tem uma série de plugins que salvam a sua vida e turbinam sua produtividade. Acontece que é muito, mas muito chato você instalar todos estes plugins, é por isso que antes de qualquer outro plugin, instale o Sublime Packaget Control.

O Sublime Package Control é um plugin que gerencia outros plugins. Você consegue procurar, instalar e desinstalar plugins do seu Sublime de uma maneira simples. Para acioná-lo use o atalho CMD+SHIFT+P. Com esse atalho você consegue executar uma série de comandos do Sublime, para usar o Package Control, inicie escrevendo “Package Control:”. Aparecerá uma lista de comandos que você poderá utilizar.

A opção INSTALL PACKAGE mostra uma lista de pacotes que você poderá instalar. Se quiser ver uma lista do site deles, vá direto nesse link.

Uma lista completa de comandos pode ser vista aqui.

Configurando um atalho de linha de comando
Esse link dispensa explicações. Ele ensina a instalar o comando subl no seu terminal para facilitar a abertura de projetos no Sublime via terminal.

Múltiplas seleções
Quer selecionar vários lugares ao mesmo tempo? Fácil, segure o CMD ou o CTRL e use o mouse para selecionar diversas partes do seu código.

Selecionar pedaços iguais de código
Imagine que você tem o código abaixo:

<ul>
    <li>Opção 1</li>
    <li>Opção 2</li>
    <li>Opção 3</li>
    <li>Opção 4</li>
    <li>Opção 5</li>
</ul>
Você quer colocar agora a mesma classe em todos os li desse bloco. Selecione a primeira tag

e em seguida aperte CMD+D para selecionar outros blocos de código iguais a este que você selecionou inicialmente, nesse caso os LIs.
Procurar arquivos
Quer encontrar arquivos no seu projeto sem ter que ficar perdendo tempo nas pastas? Use o atalho CMD+T e pronto, digite o nome do seu arquivos e edite-o.

Goto Anything
Quer encontrar funções, classes ou IDs dentro do seus arquivos? Use o atalho CMD+P. Esse comando abre o search geral do Sublime. Nesse search você pode procurar arquivos, como no exemplo anterior ou se você iniciar a busca com um @, vai possibilitar a procura de funções, classes, IDs e etc no arquivo aberto.

Se você quiser ir para uma linha específica, você pode começar a busca com : (dois pontos) e aí você coloca o número da linha ou use o atalho    - CTRL+G e número da linha.

Esconder a Sidebar
Se você trabalha em um notebook com tela pequena você vai querer isso. Basta apertar CMD+K e seguidamente CMD+B. Isso faz com que a Sidebar apareça ou desapareça.

Apagar linha inteira
Para apagar a linha inteira: CMD+K+K.

Clonar a linha
Para copiar uma linha inteira e duplicá-la: CMD+SHIFT+D.

Seleção em bloco
Segure CTLR+SHIFT aperte a seta do teclado para baixo. Você verá o cursor selecionando as linhas. Depois segure o SHIFT e aperte a tecla para direita. Pronto… Seleção bloco.

Atalhos de seleção
A tecla SUPER é CMD no Mac e a tecla WINDOWS no Windows.

Ação	Atalho
Selecionar conteúdo entre tags	SUPER + SHIFT + A
Expadir seleção para linha	SUPER + L
Expandir seleção para ocorrência idêntica	SUPER + D
Expandir seleção para escopo	SUPER + SHIFT + SPACE
Expandir seleção para colchetes	CTRL + SHIFT + M
Mover a linha para cima	CTRL + SUPER + UP
Mover a liha para baixo	CTRL + SUPER + DOWN
Duplicar linha	SUPER + SHIFT + D
Juntar linhas	SUPER + J