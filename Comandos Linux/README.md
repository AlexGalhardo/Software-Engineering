```
Lista bem completa de comandos Linux
15 DE MAIO DE 2013 ATILA AUGUSTO2 COMENTÁRIOS
—————————————————————————–
—————————————————————————–
Super Manual de comandos do GNU/Linux
————————————-

AUTOR : Eder S. G. (Jordam)
E-M@IL PRINCIPAL : ederjordam@yahoo.com.br
SITE : http://geocities.yahoo.com.br/ederjordam
REGISTERED LINUX USER : 179086
Este manual de comandos é baseado na distribuição Debian GNU/Linux

versão 4.0.15, 22 de julho, 2005

—————————————————————————–
—————————————————————————–

Resumo
——
Este documento contém informações diversas dos vários comandos do Linux.
Nota de Copyright
—————–
Este documento pode ser distribuído ou modificado sobre os termos da
GNU General Public Licence.
(C) 1996-2001 Eder S. G.

Este manual é software livre; você pode redistribui-lo e/ou
modifica-lo de acordo com os termos da GNU General Public Licence como
publicada pela Free Software Foundation; versão 2 da licença ou (a
critério do autor) qualquer versão posterior.

Este documento é distribuído com a itenção de ser útil ao seu
utilizador, no entanto _NÃO TEM NENHUMA GARANTIA, EXPLÍCITAS OU
IMPLÍCITAS , COMERCIAIS OU DE ATENDIMENTO A UMA DETERMINADA
FINALIDADE_. Consulte a Licença Pública Geral GNU para maiores
detalhes.

Uma cópia da GNU General Public Licence esta disponível no website
da GNU (http://www.gnu.org/copyleft/gpl.html) na World Wide
Web. Voce também pode obter uma cópia escrevendo para a Free Software
Foundation, Inc., 59 Temple Place – Suite 330, Boston, MA 02111-1307,
USA.

Eu, Eder S. G., gostaria que você atribua qualquer material derivado
deste documento para mim. Se você modificar e melhorar este documento,
peço que o autor seja notificado pelo e-mail ederjordam@yahoo.com.br
Observação
———-
NÃO ME RESPONSABILIZO POR EVENTUAIS DANOS EM SEU EQUIPAMENTO PELO MAL USO
DAS INFORMAÇÕES NESTE DOCUMENTO. É DE SUA INTEIRA RESPONSABILIDADE QUERER
OU NAO UTILIZAR OS COMANDOS DESCRITOS NESTE DOCUMENTO.

Linux é uma marca registrada e concedida por Linus Torvalds, seu criador e
cedente.

Todas as marcas registradas neste documento são de propriedades de
seus respectivos donos.
Do autor do documento
———————
Dúvidas, sugestões me contate através do e-m@il ederjordam@yahoo.com.br
—————————————————————————-

– INDICE
01 – COMANDOS DE MANIPULAÇÃO DE ARQUIVOS E DIRETÓRIOS
02 – COMANDOS INFORMATIVOS
03 – COMANDOS DE INICIALIZACAO E ENCERRAMENTO DO LINUX
04 – COMANDOS DE CONTROLE DE ACESSO E USUARIOS/GRUPOS
05 – COMANDOS DE PROCESSOS DO LINUX
06 – COMANDOS DE CONFIGURACAO DO LINUX
07 – COMANDOS DE IMPRESSAO
08 – COMANDOS DE REDE
09 – EDITORES DE TEXTO
10 – CAMINHOS DE ARQUIVOS IMPORTANTES NO LINUX
11 – AGRADECIMENTOS
12 – COMANDOS PARA MODULOS (DRIVERS)
13 – COMANDOS DE REDIRECIONAMENTO E PIPE
14 – TECLAS DE ATALHO DO KDE 3.X
15 – METACARACTERES
16 – COMANDOS PARA GRAVAÇÃO DE CD’S
17 – COMANDOS DA DISTRIBUIÇÃO DEBIAN

—————————————————————————-

1 – COMANDOS DE MANIPULAÇÃO DE ARQUIVOS E DIRETÓRIOS

1.1 – comando ls = lista arquivos e o conteúdo de diretórios

– Exibe apenas diretórios
ls -l | grep ‘^d’
ou
ls -d */

– Exibe apenas diretórios sem exibir seus respectivos tamanhos
ls -l | grep ‘^d’ | awk {‘print $8’}

– Exibe arquivos ocultos, ou seja, iniciados com “.”
ls -a

– Exibe arquivos ocultos, exceto o “.” e “..”
ls -A

– Para listar arquivos e diretórios como o comando ‘dir /p’:
ls | less
* ou *
ls | most

– Exibe os arquivos em colunas, ordenados verticalmente
ls -C

– Exibe somente diretórios:
ls -l | grep ^d
ou
ls -la | grep ^d

– Exibe os arquivos em seus tamanhos em KB, MB e GB
ls -h

– Exibe primeiramente os arquivos criados/alterados recentemente
ls -t

– Exibe informações referentes a arquivos e diretorios em colunas
ls -l

– Exibe apenas arquivos executáveis, ou seja, marcados por um asterisco
no final do seu nome
ls -F

– Exibe arquivos de acordo com o tempo do ultimo acesso ao inves
do tempo de modificacao do mesmo
ls -u

– Exibe os arquivos na ordem inversa (de z para a)
ls -r

– Exibe um diretorio e seus respectivos subdiretorios
ls -R

– Exibe o conteudo do diretorio pelo tamanho do arquivo, no lugar
de ordem alfabetica, com os maiores arquivos sendo exibidos primeiro
ls -S

– Exibe o número do inode de cada arquivo/diretorio
ls -i

– Exibe os arquivos horizontalmente cada um separado por virgula
ls -m

– Exibe o UID e o GID ao inves do nome/grupo do arquivo
ls -nl

– Exibe arquivos/diretorios nao exibindo o grupo, apenas o dono
ls -o

– Exibe os arquivos em colunas, ordenados horizontalmente
ls -x

– Exibe e ordena o conteudo do diretorio alfabeticamente pela extensao
(caracteres depois do ultimo “.”) do arquivo. Arquivos sem extensao são
ordenados primeiramente
ls -X

– Exibe o nome de cada diretorio com “/” e cada nome de arquivos executaveis
com “*” em seu final
ls -F

– Exibe o status do tempo de alteração ao invés do tempo de modificação para
ordenar (com -t) ou listar (com -l)
ls -c

– Exibe todos os arquivos com a inicial minuscula contidos dentro da faixa
entre os caracteres ‘a’ e ‘d’
ls [a-d]*

– Exibe os arquivos com a inicial entre P e Q, e depois outra entre 1 e 3
ls [P-Q1-3]*

– Envia o conteudo do comando ls no console atual para o console tty2
ls > /dev/tty2

– Exibe uma lista de arquivos/diretorios ordenados pela data de criação
ls -Fltr

– Exibe os arquivos ordenados do menor para o maior
ls -la | sort +4 -n

– Exibe os arquivos ordenados do maior para o menor
ls -la | sort +4 -nr

– Exibe os arquivos com suas propriedades no estilo do S. O. Windows
ls -al –full-time

– Exibe todos os arquivos com extensão ‘txt’
ls -l *.txt

– Exibe todos os arquivos ‘txt’ que contenham a palavra ‘jordam’
ls -l *.txt | grep jordam

– Exibe um número de quantos arquivos existem em um diretório
ls -A | wc -l

– Exibe um número de quantos arquivos existem em um diretório
ls -A -p | sed -e ‘/\//d’ | wc -l

– Exibe um número de quantos diretórios existem em um diretório
ls -A -p | grep “/” | wc -l

– Para listar em um diretório os arquivos mais velhos
ls -lt | tail -30

– Para listar os arquivos maiores
ls -l | sort -n -k 5 | tail -30

– Para procurar os diretórios com a maior quantidade de arquivos
du -k . | sort -n -k 1 | tail -30


1.2 – comando rm = remove arquivos e diretorios

– Remove o arquivo file1.txt
rm file1.txt

– Remove os arquivos file1.txt, file2.txt e file3.txt
rm file1.txt file2.txt file3.txt

– Pergunta ao usuário se ele deseja realmente remover o arquivo teste1.txt
rm -i teste1.txt

– Remove os diretorios com seus arquivos e subdiretorios (-r) não exibindo
perguntas de confirmacao de exclusao (-f)
rm -rf /trabalhos/exposicao50

– Remove os diretorios com seus arquivos e subdiretorios (-r) não exibindo
perguntas de confirmacao de exclusao (-f) exibindo o nome de cada arquivo
antes de apagá-lo (-v)
rm -rfv /trabalhos/exposicao50

– Para remover o arquivo ‘file1.txt’ de todos os diretórios home de todos
os usuários cadastrados no sistema
rm -rfv /home/*/file1.txt

– Para remover todos os arquivos de todos os diretórios home de todos
os usuários cadastrados no sistema que possuam arquivos dentro de seus
respectivos diretórios ‘trash’
rm -rf /home/*/trash/*

– Para remover o arquivo ‘–verify’
rm -f — –verify
* ou *
rm ./–verify

O 1º ‘–‘ significa que acabou a lista de argumentos, o que vier na frente
é nome de arquivo. O 2º ‘–‘ faz parte do nome do arquivo.

– Para remover o arquivo ‘–exclude-from=excluir’
rm — “–exclude-from=excluir”
* ou *
rm — –exclude-from=excluir
1.3 – comando cp = copia arquivos ou diretorios

– Mais utilizado:
cp -aRdiv
ou
cp -a -R -d -i -v

– Quando o primeiro diretório tem vários diretórios dentro, o “cp” precisa
saber que você quer copiar tudo. Para isso adicione a opção “-a”. E ele
fará uma copia recursiva, isto é: copiara tudo o que encontrar dentro
do primeiro diretório para o segundo, e preservara sua estrutura e atributos,
mesmo que “-dpr”
cp -a diretorio diretorio

– Se já existir um arquivo de mesmo nome dentro do diretório, ele pergunta
se você quer substituí-lo. Se a resposta à pergunta for “y”, ele o fará
cp -i arquivo diretorio

– Se já existir um arquivo de mesmo nome dentro do diretório, ele gravará
em cima dele sem perguntar nada
cp -f arquivo diretorio

– Copia o arquivo file1.txt para o diretorio citado
cp file1.txt /home/edjordam

– Copia o arquivo file1.txt para o diretorio citado com um novo nome:
filenovo.txt
cp file1.txt /home/edjordam/filenovo.txt
– Faz uma copia do arquivo1 para o arquivo2
cp arquivo1.txt arquivo2.txt

– Copia o arquivo file1.txt checando se existe um arquivo de mesmo nome
no diretorio /home/ederjordam, se estiver esta opção irá fazer uma
pergunta se deseja sobrescrever o arquivo de destino
cp -i file1.txt /home/ederjordam

– Copia o arquivo file1.txt preservando suas propriedades, como o pro-
prietario do arquivo, data de criação, permissões de acesso, última
modificacao e último acesso
cp -p file1.txt /home/ederjordam

– Copia os arquivos/diretórios/sub-diretórios do diretório textos para o
diretório atual
cp -R /files/textos/* .

– Copia os arquivos, diretórios, sub-diretórios do diretório textos para
o diretório /usr/backup
cp -R /files/textos/* /usr/backup

– Copia todos os arquivos .txt do diretório /chicago para o diretório atual
cp /chicago/*.txt .

– Copia o arquivo file9.txt mantendo seu link simbolico, ou seja, o vínculo
original do arquivo
cp -d file9.txt /home/ederjordam

– Copia o arquivo file4.txt da maneira mais fiel possivel, o ‘-a’ é a união
das flags ‘-pdR’ juntas e o ‘-i’ apresenta um prompt antes de sobescrever
arquivos de destinos existentes
cp -ai file4.txt /home/ederjordam

– Copia o arquivo file7.txt e cria uma cópia de segurança do arquivo citado.
Repare que existe um arquivo de mesmo nome no diretório
/home/ederjordam porem com um “~” no final
cp -b file7.txt /home/ederjordam

– Copia o arquivo file3.txt para o diretório /home/ederjordam e se existir
um arquivo de mesmo nome será atomaticamente deletado
cp -f file3.txt /home/ederjordam

– Copia o arquivo file5.txt para o diretorio /home/ederjordam e substitui
o arquivo caso tenha a hora de modificação mais antiga do que o arquivo de
origem correspondente
cp -u file5.txt /home/ederjordam

Copia o conteúdo dos 3 arquivos para o arquivo agenda.txt
cp file1.txt file2.txt file3.txt > agenda.txt
– Acrescenta o conteúdo do arquivo file4.txt no arquivo agenda.txt
cp file4.txt >> agenda.txt
– Copia TODOS os arquivos (inclusive os ocultos) exibindo o resultado final
do comando ‘-v’
cp -av teste/* /home/ederjordam
ou
cp -av teste/.??* /home/ederjordam
ou
cp * .[a-zA-Z0-9#~]* /home/ederjordam

Note que se você tiver arquivos ocultos com menos que três letras após o ‘.’
no nome estes não serão copiados. Para copiá-los, digite seus respectivos
nomes. Isso se deve ao fato da expressão “.??*” ser usada para eliminar os
diretórios “.” e “..”.

– Copiará, a partir do diretório corrente, 100 arquivos que atendam à condição
“INPUT*:*”, ou seja que comecem por “INPUT”, e que são seguidos por zero ou
mais caracteres. Podemos colocar como origem em um comando cp, mv, ou qualquer
outro semelhante uma expressão regular que me permita selecionar com precisão
quais arquivos eu quero copiar ou mover para um diretório de destino. As
aspas invertidas sinalizam exatamente isto, que o comando entre aspas
invertidas serão executados e seu resultado será passado para o comando sendo
executado
cp `ls INPUT* | head -n 100` destino
1.4 – comando cat = exibe o conteúdo de um arquivo

– Exibe o conteudo do arquivo file1.txt
cat file1.txt

– Exibe o conteúdo do arquivo file1.txt com suas linhas numeradas
cat -n file1.txt

– Exibe o conteúdo do arquifo file1.txt apresentando no finaL de cada linha
o caracter $
cat -A file1.txt

– Enumera os arquivos de um diretório
cat -n <(ls)

– Exibe uma lista apenas com os logins dos usuários cadastrados no sistema
cat /etc/passwd | cut -d : -f 1
ou
cat /etc/passwd | awk -F “:” ‘{print $1}’

– Procura o nome Edi Jordam no arquivo agenda.txt
cat agenda.txt | grep “Edi Jordam”

– Recebe por email o conteudo do arquivo /etc/services
cat /etc/services | sendmail user@dominio.com.br
– Retira o ^M dos arquivos formatados com padrão MS Windows (quebra de linha)
cat arquivo | tr -s “\r” “\n” > novo_arquivo_sem_m

– Onde arquivo.dat é o arquivo que voce deseja exibir, com a opção ‘-n’ ele
numera todas as linhas e o ‘grep N’ sendo a enésima linha que você desejar
cat -n arquivo.dat | grep N

– Exibi a enésima linha de todos os arquivos de um diretório
cat -n /caminho/arquivo | grep -e ^[\ ]*NUMERO_LINHA[^0-9]

– Copia o conteudo destes 3 arquivos para o arquivo agenda.txt
cat file1.txt file2.txt file3.txt > agenda.txt
– Acrescenta o conteúdo do file4.txt no arquivo agenda.txt sem apagar os
dados já nele armazenados
cat file4.txt >> agenda.txt
– Remove as três primeiras linhas do arquivo options.skel e cria o arquivo
options com as modificacoes
cat ~/.gnupg/options.skel | sed “0,3d” > ~/.gnupg/options

– Envia um em@ail a todos os usuarios do sistema
cat /etc/passwd | cut -d: -f 1 | while read x;
do
echo “Desliguem seus computadores no final do expediente!” | mail ${x} -s “Aviso do administrador.”;
done

– Exibe o conteúdo do primeiro console
cat /dev/vcs1

– Exibe o conteúdo do primeiro console com cores
cat /dev/vcsa1

– Exibe a 95º linha do arquivo file1.txt
cat -n file1.txt | awk ‘$1 == 95 {print $2}’

– Exibe a 95º linha do arquivo passwd
cat -n passwd | awk ‘$1 == 95 {print $0}’ | cut -f 2-

– Direciona a saída do comando cat para a impressora
cat file1.txt > /dev/lp0
ou
cat < file1.txt > /dev/lp0

– Direciona a saída do comando cat para a impressora numerando suas linhas
cat -n file1.txt > /dev/lp0

– Exibe o conteudo do cat no monitor envia também para a impressora
cat file1.txt | tee /dev/lp0

– Direciona a saida do comando cat para o programa de spool lpr
cat file1.txt | lpr

– Exibe todas as mensagens do daemon ‘kernel’ da estação de trabalho ‘wrk1’
eliminando os campos ‘wrk1’ e ‘kernel’. Os parâmetros ‘$1’, ‘$2’ do comando
‘awk’ indica que campos serão listados, (omitimos $4 e $5 que são respecti-
vamente ‘wrk1’ e ‘kernel’)
cat /var/log/* | grep ‘wrk1’ | grep ‘kernel’ | awk ‘{print $1 $2 $3 $6 $7 $8 $9 $10 $11 $12}’

– Exibe as 10 linhas restantes depois da 1º ocorrência da palavra ‘palavra1’
que fica sempre no início de alguma linha
cat file1.txt | grep palavra1 -B 10

– Exibe todas as linhas exeto as que tenham joao e maria
cat arquivo | grep -v joao | grep -v maria

– Converte um arquivo criado no DOS para o Unix
cat file | sed “s/^M\{1,\}$//” | sed “$ s/^Z//” > file-new.txt
– Converte um arquivo criado no Unix para o DOS
cat file | sed “s/$/^M/” | sed “$ s/$/^Z/” > file-new.txt
– Exibe a primeira coluna do arquivo /etc/passwd.
cat /etc/passwd | cut -d: -f1 | sort > arq

Explicação:
cat /etc/passwd = obtem o conteudo do /etc/passwd
cut -d: -f1 = corta a primeira ocorrencia de 2 pontos “:” do arquivo
sort = ordena em ordem alfabetica
> arq = direciona o resultado ou saida para o arquivo “arq”

– Gera o arquivo mails.txt contendo todos os usuarios do computador
cat /etc/passwd | cut -f1 -d: >> /etc/mail/mails.txt
– Se houver um erro de arquivo não encontrado use este comando para ler
arquivos texto com a extensão gz
zcat /usr/man/man1/lsmod.1.gz

– Possuo um arquivo com vários usernames e necessito criar um shell para
consultar este arquivo e remover do passwd todos esses usernames
cat ArqPWs | xargs grep -v /etc/passwd > /tmp/passwdnew
mv -f /tmp/passwdnew /etc/passwd

– Como faco pra tirar as linhas que contem uma certa expressão em um
arquivo? EX:
aaaaa.string_que_eu_quero_tirar.bbbbbbb
aaaaa.string_normal.bbbbbbbbbbbb
aaa.string_que_eu_quero_tirar.bbbbbbbbbbbbbbbbbb
cat arquivo | grep -v “string_que_eu_quero_tirar”

– Preciso alterar uma string que vem entre ‘ ‘. A string que vem é algo
assim: seila seila seila seil ‘seila2’
cat arquivo | cut -d “‘” -f 2 > arquivo_2

– Como fazer para trocar todas as letras maiusculas de um arquivo
por minusculas?
cat arquivo.txt | tr ‘[A-Z]’ ‘[a-z]’

– Mantenho um livro de endereço para envio de e-mail em um arquivo txt com
os e-mail de meus clientes. Pensei em um script que capturasse o username
do /etc/passwd (levando-se em conta o grupo) e concatenasse com
@meudominio.com.br; resolveria esta questão

Você cria um arquivo chamado emails.txt, com todos os usuarios que possuem UID
maior que 500, menos o nobody
cat /etc/passwd | sed -e ‘/^\([^:]*:\)\{2\}[5-9][0-9]\{2,\}:/!d;/nobody/d;s/:.*/@meudominio.com.br/’ > emails.txt
Cria o email.txt, mas apenas dos usuarios que pertencem ao grupo de GID=500
e GID=502
cat /etc/passwd |sed -e ‘/^\([^:]*:\)\{3\}\(500\)\|\(502\):/!d;s/:.*/@meudominio.com.br/’ > emails.txt
– Em uma migracao de scripts do MS-DOS para o Unix, ganhamos alguns ^M no
final de cada linha. Existem linhas com 1 ^M outras com 2 ^M e outras sem
nenhum. Como posso retirar todos os ^M sem danificar os scripts?
cat arquivo.in | tr -d “\r” > arquivo.out
– Concatenar os arquivos em um único arquivo, que chamaremos de total.zip
cat file1.zip > total.zip
cat file2.zip >> total.zip
cat file.zip >> total.zip
ou você pode abreviar esse passo para
cat file1.zip file2.zip file3.zip > total.zip
ou ainda
cat file?.zip > total.zip
cat file[1-3].zip > total.zip
– Exibe o modelo do HD configurado como master na ide primária
cat /proc/ide/ide0/hda/model

– Exibe o modelo do CD-ROM configurado como master na ide secundária
cat /proc/ide/ide1/hdc/model

– Seleciona a linha 30 em um arquivo texto
cat arquivo-com-frases.txt | sed ’30!d’

– Exibir apenas uma determinada linha no arquivo
cat arquivo | awk -e ‘{if(NR == <numero linha>) { print $0; }’
1.5 – comando less = exibe o conteudo de um arquivo pausadamente

– Exibe o conteudo do arquivo file1.txt pausadamente
less file1.txt

– Exibe linhas em banco consecutivas em uma unica linha em branco
less -s file1.txt

– Corta as linhas mais largas do que a tela
less -S file1.txt

– Força os caracretes de controle serem exibidos usando a notação de
acento circunflexo (CTRL + A é ^A)
less -r file1.txt

– Ações com o comando less:
Para pular diretamente para uma linha, coloque o número da linha seguido
da letra ‘g’

Para pular diretamente para o início ou final do arquivo, se digitar ‘g’
você pula para a primeira linha do texto. Com o ‘G’ sozinho você pula para
a última linha do texto

Para retroceder em um arquivo, a seta para cima faz mover para cima uma linha
de texto por vez e a seta para baixo faz mover uma linha de texto para baixo

Para pesquisar retroativamente em um arquivo, uma barra normal(/) seguida de
uma palavra ou frase pesquisará para frente do texto e um ponto de
interrogação
1.6 – comando zless = permite visualizar arquivos TXT que estejam compactados
em um arquivo .gz
zless file1.gz
1.7 – comando zmore = permite visualizar arquivos TXT que estejam compactados
em um arquivo .gz
zmore file.gz
1.8 – comando more = exibe o conteúdo de um arquivo pausadamente

– Exibe pausadamente o conteudo do arquivo file1.txt
more file1.txt

– Exibe pausadamente o conteudo do arquivo file2.txt e a cada pausa,
exibe um prompt de opcoes
more -d file2.txt
1.9 – comando od = exibe a saída octal de um arquivo binário
od nome-do-arquivo
1.10 – comando pwd = exibe o diretório atual que você se encontra
pwd
1.11 – comando mkdir = cria um diretório

– Para criar o diretório ‘trabalhos’ na raiz do sistema
mkdir /trabalhos

– Para criar uma estrutura de sub-diretórios
mkdir -p diretorio1/diretorio2/diretorio3

– Para criar um diretório com espaços em seu nome
mkdir “Diretorio com espacos”

– Para criar diversos diretórios com apenas um comando
mkdir /home/{joao,maria,jose,raimundo,antonio}
1.12 – comando rmdir = deleta um diretorio vazio

– Deleta o diretório, se estiver vazio
rmdir /nome-do-diretorio

– Deleta todos os diretórios no caminho
rmdir -p /nome-do-diretorio

– Apaga o diretorio se estiver vazio
rmdir “Diretorio com espacos”
1.13 – comando clear = limpa o conteúdo atual na tela
clear
ou
CTRL + L
1.14 – comando df = exibe o espaço usado em partições do HD

– Exibe os sistemas de arquivos
df

– Exibe também o tipo de cada sistema de arquivo analizado
df -T

– Exibe informações de todos os sistemas de arquivos
df -a

– Exibe o espaço livre, o espaço ocupado em MB, KB, GB e exibe o uso
e tamanho de todas as partições montadas no sistema
df -h

– Exibe o espaco usado em particoes em MB
df -m
1.15 – comando free = exibe a memória livre, usada e mais

– Exibe informações sobre a memória
free

– Exibe informações sobre a memória em MB
free -m

– Exibe informações sobre a memória atualizando suas informações de 6 em
6 segundos
free -s 6
1.16 – comando du = determina o espaço ocupado pelos arquivos e diretórios

– Exibe o espaço em disco usado pelo diretório atual
du

– Exibe o tamanho total em MB do diretorio /usr
du -h /usr

– Exibe o tamanho em MB do diretório Mail/
du -h -s Mail/
ou
du -hs Mail/

– Exibe o espaço usado para o atual diretório e não para seus sub-diretórios
du -s /dir2

– Exibe o tamanho em MB do diretório httpd
du -s -m httpd

– Exibe a contagem para todos os arquivos encontrados, não somente
diretórios
du -a

– Exibe o tamanho dos arquivos ou diretórios em bytes
du -b

– Exibe o tamanho dos arquivos ou diretórios em KB
du -k

– Exibe o tamanho dos arquivos ou diretórios em MB
du -m

– Exibe o total geral para todo argumento depois que todos os argumentos
tenham sido processados. Pode ser usado para descobrir o total do disco
usado de um conjunto de arquivos ou diretórios
du -c

– Procura todos os arquivos com extensão *.txt no diretório atual
du -a | grep *.txt

– Realiza uma busca mais eficiente do arquivo file1.txt
du -a | grep file1.txt

– Exibe uma listagem de diretorios ordenados do maior para o menor
du -S | sort -nr | more

– Vai percorrer todo o HD atrás de todos os arquivos e vai mostrar o
total em kbytes por pasta e no final o total geral
du -sc /* | sort -n

Uma vez que voce descobriu a pasta vilã (ex: o prob. é o /home), digite:
du -sc /home/* | sort -n

– Exibe o tamanho de todos os arquivos no diretório
du *

– Exibe o tamanho de todos os arquivos (aos quais você tem permissão)
no computador
du /*

– Exibe os diretórios que possuem mais de 300MB
du -m | awk ‘($1 > 300) {print $0 }’

– Exibe o tamanho do diretório em MB
du -s -h /home/edersg/fotos

– Como descobrir a maior pasta/arquivo?
Normalmente utilizo o du -m -h para fazer isto mas não é bem isto que
preciso, pois não necessito saber arquivo por arquivo de cada pasta mas
sim o total de cada pasta. Por exemplo, a partir do /var, executando o
du -m -h
tenho o resultado abaixo:
0 ./cache/man/cat1
0 ./cache/man/cat2
0 ./cache/man/cat3
0 ./cache/man/cat4
0 ./cache/man/cat5
0 ./cache/man/cat6
0 ./cache/man/cat7
0 ./cache/man/cat8
0 ./cache/man/cat9
0 ./cache/man/oldlocal/cat1
0 ./cache/man/oldlocal/cat3
0 ./cache/man/oldlocal/cat5
0 ./cache/man/oldlocal/cat7
0 ./cache/man/oldlocal/cat8
24K ./cache/man/oldlocal
0 ./cache/man/local/cat1
0 ./cache/man/local/cat3
0 ./cache/man/local/cat5
0 ./cache/man/local/cat7
0 ./cache/man/local/cat8
24K ./cache/man/local
0 ./cache/man/X11R6/cat7
0 ./cache/man/X11R6/cat1
20K ./cache/man/X11R6
0 ./cache/man/opt
692K ./cache/man

Porém gostaria que o resultado fosse somente, isto:
692K ./cache/man

Atualmente meu /var(veja o df, acima) tem as seguintes pastas:
alias attach bin boot control doc man queue rc supervise users

O que eu gostaria era se saber quanto MB cada uma destas pastas estão
ocupando em meu disco. Algo do tipo:
200MB alias/
500MB attach/
e assim por diante.
Tente:
du -h –max-depth=1
Opa! Corrigindo a msg anterior:
cd diretório_que_vc_deseja_saber_tamanho_dos_subdiretórios
ls -1p|fgrep /|cut -d\ -f10|xargs du -hs

Obs: Há DOIS espaços após o “cut -d\”, ok?
Ah, eu ia me esquecendo: note que é “ls -1p” (é hífen “NÚMERO UM”
“LETRA P MINÚSCULA”)
Tente ai:
cd /var
du -h –max-depth=1 | more
Tente:
du -s /var/*

Isto irá mostrar o tamanho de cada diretório. Você ainda pode listar me KB e
fazer um sort no final para listar os maiores primeiro:
du -sk /var/* |sort -n
Ooops… faltou o parâmetro -r no sort para mostrar os maiores primeiro
du -sk /var/* |sort -nr
Essa era mais ou menos o que eu ia sugerir:
du -sc /var/* | sort -n

O maior problema dessa solução é que ela não inclui diretório escondidos
(aqueles que começam com ponto). Tipo, se vc fizer isso no seu home,
fatalmente não vai descobrir que o cache do firefox ocupa 50MB… Ai a
solução é usar um comando um poquinho maior:
du -k –max-depth=1 /var/ | sort -n
Tente:
du -s /var/* | sort -n | tail –lines=1

limitação: não dá para deixar a saída do du mais bonitinha, com -h, pois
senão o sort pira.
1.17 – comando tree = exibe o conteudo de um diretorio(arquivos/subdiretorios)

– Exibe somente os sub-diretórios
tree -d

– Exibe todos os arquivos, inclusive os ocultos
tree -a

– Exibe o caminho completo dos arquivos
tree -f

– Exibe as permissões dos arquivos
tree -p
1.18 – comando mv = move ou renomeia arquivos e diretórios

– Renomeia os arquivo file2.txt
mv file2.txt file55.txt

– Move o arquivo file1.txt para o diretorio /home
mv file1.txt /home

– Move todos os arquivos do diretorio padrao com a extensão txt,
doc e jpg para o diretorio /home
mv *.txt *.doc *.jpg /home

– Move o diretorio mp3 para o diretorio /home/musicas
mv mp3/ /home/musicas

– Renomeia o diretorio fotos para fotos-novas
mv fotos/ /fotos-novas

Opções:

-f = remove arquivos do diretorio de destino com o mesmo nome,
ou seja, remove os arquivos existentes que vao ser sobrescritos
pela movimentacao, sem avisar ao usuario

-i = exbe um prompt caso exista arquivos com o mesmo nome, ou
seja, avisa antes de sobescrever qualquer arquivo

-v = exibe o nome de cada arquivo antes de move-lo

-b = faz um backup dos arquivos que estao sendo movidos

-u = não sobescreve um arquivo existente se ele possuir a mesma
hora de modificação ou for mais recente
1.19 – comando ln = cria links simbolicos para arquivos e diretorios.

– Existem 2 tipos de links:

1º links simbólicos (soft links) = cria um arquivo especial no disco (do
tipo link) que tem como conteúdo o caminho para chegar até o arquivo alvo
(isto pode ser verificado pelo tamanho do arquivo do link). Use a opção
‘-s’ para criar links simbólicos. Os links simbólicos tem uma função pare-
cida com os atalhos do Windows, eles apontam para um arquivo, mas se o
arquivo for movido para outro diretório, o link ficará quebrado.

2º links diretos (hard link) = faz referência ao mesmo inodo do arquivo
original, desta forma ele será perfeitamente idêntico, inclusive nas
permissões de acesso, ao arquivo original. Ao contrário dos links
simbólicos, não é possível fazer um hardlink para um diretório ou
fazer referência a arquivos que estejam em partições diferentes. Os hard
links por sua vez são semelhantes aos atalhos do OS/2 da IBM, eles são
mais intimamente ligados ao arquivo e são alterados junto com ele. Se
o arquivo mudar de lugar, o link é automaticamente atualizado.

– Cria um hard link chamado ‘video-mj’ apontando para o arquivo ‘video1.avi’
ln /home/jordan/video1.avi video-mj

– Cria um link simbólico chamado ‘importante.txt’ na raiz do sistema apontando
para o arquivo ‘/usr/doc/file1.txt’
ln -s /usr/doc/file1.txt /importante.txt
– Cria um link simbólico chamado ‘/dev/mouse’ apontando para o arquivo
‘/dev/ttyS0’ que representa a porta COM1/ttyS0
ln -s /dev/ttyS0 /dev/mouse

– Força a criação de um link simbólico chamado ‘/dev/mouse’ apontando para o
arquivo ‘/dev/ttyS0’ que representa a porta COM1/ttyS0
ln -sf /dev/ttyS0 /dev/mouse

– Cria um link simbólico chamado ‘/dev/mouse’ apontando para o arquivo
‘/dev/psaux’ que representa o dispositivo PS2 (minidim)
ln -sf /dev/psaux /dev/mouse

– Exibe os resultados de cada arquivo antes de terminar o link
ln -v

– Cria hard links
ln -d = cria hardlinks para diretórios

– OBS:
Se for usado o comando ‘rm’ com um link, somente o link será removido.

Se for usado o comando ‘cp’ com um link, o arquivo original será
copiado ao invés do link.

Se for usado o comando ‘mv’ com um link, a modificação será feita
no link.

Se for usado um comando de visualização (como o ‘cat’), o arquivo
original será visualizado.
1.20 – comando find = procura arquivos/diretorios. O comando find
pode procurar arquivos/diretorios através de sua data de modificacao
tamanho etc. O comando find é extremamente poderoso e flexível para
descobrir arquivos que atendem a determinadas especificações.

– Procura o arquivo ‘file1.txt’ em todo o sistema
find / -name file1.txt -print

– Procura e deleta arquivos ‘core’ em todo o sistema
find / -name core -exec rm {} \;

– Procura e deleta arquivos (sem confirmação) ‘core’ em todo o sistema
find / -name core -exec rm -f {} \;

– Procura e deleta todos os arquivos chamados ‘textos.txt’ dentro dos
diretórios pessoais de todos os usuários
find /home -name textos.txt -exec rf -f {} \;

– Procura pelo arquivo ‘file1.txt’ que pertença ao grupo ‘trabalho’ em
todo o sisetma
find / -group trabalho -name file1.txt -print

– Procura por todos os arquivos que tenham permissão de execução pelo
proprietário no diretório home
find ~ -perm -100 -print

– Procura no diretório home do usuário ‘joao’ todos os arquivos que não
tenham a extensão ‘.gif’
find ~/joao ! -name “*.gif” -print

– Procura no diretório atual todos os arquivos que foram modificados há no
máximo 2 dias
find . -mtime 2 -print

– Exclui arquivos criados a mais de 2 dias (obs: -ctime +1 = 24 horas,
-ctime +2 = 48 horas)
find * -ctime +2 -exec rm {} \

– Procura por todos os arquivos que sejam do usuário ‘joao’ ou do grupo ‘casa’
em todo o sistema
find / ( -group casa -o -user joao ) -print

– Procura por arquivos cujo o dono seja o ‘user1’ em todo o sistema
find / -user user1 -print

– Procura por arquivos que pertençam ao grupo ‘gerentes’ em todo o sistema
find /home -group gerentes -print

– Procura arquivos com a extenção DOC e CONF em todo o sistema
find / -name ‘*.doc’ -o -name’*.conf’ -print

– Procura no diretorio atual e sub-diretórios arquivos com tamanho maior
que 1024KB (1MB)
find . -size +1024K -print

– Procura em todo o sistema arquivos com tamanho maior que 1024KB (1MB)
find / -size +1024K -print

– Procura arquivos que contém uma determinada frase em todo o sistema
find / -name “*.txt” -exec grep -i “escreva sua frase” {} \;

– Procura no diretório atual e sub-diretórios por arquivos que contenham
mais de 1MB (1024KB)
find . -size +1024 -print

– Realiza backup de todos os arquivos fontes C no diretório atual e seus
sub-diretórios
find . -name “*.[ch]” -print | zip source -@

– Procura por arquivos que não foram acessados nos últimos 20 dias no
diretório ‘/home/mjordan’
find /home/mjordan -atime +20 -print

– Apaga todos os arquivos TRASH de cada sub-diretório sem ter que entrar
em cada um deles
find . -name TRASH -exec rm {} \;

– Exclui todos os arquivos com a extensão ‘mm2’
find / -name “*.mm2” -exec rm {} \;

– Faz uma busca por todos os arquivos SETUID/SETGID e salva o resultado do
comando find no arquivo log1.txt
find / -type f -perm +6000 -ls >> /log1.txt

– Faz uma busca por todos os arquivos que possuem permissão de gravação
configurada para todos os usuários e salva o resultado do comando find
no arquivo log2.txt
find / -perm -2 ! -type l -ls >> /log2.txt

– Faz uma busca por todos os arquivos que não possuem um dono ou grupo e
salva o resultado do comando find no arquivo log3.txt
find / -nouser -o -nogroup >> /log3.txt

– Para descobrir links simbólicos que apontam para arquivos que não
existem mais no sistema
find . -type l -follow 2>/dev/stdout | cut – d: -f 2 | xargs rm -f

Repare q o ‘2>/dev/stdout’ pode ser substituido por 2>&1, mas eu acho o
primeiro mais legivel! Isso se faz necessario pois o find, ao seguir um link
quebrado escreve a mensagem da saida padrão de erro (stderr), por isso temos
que redirecionar, para que o cut consiga pegar e passar pra frente.

– A opção -ctime indica “creation time”, ou seja, a quantos dias o inode do
arquivo foi alterado. O termo “creation time” gera um pouco de dúvida,
pois não se refere exatamente à data de criação do arquivo mas sim à data
de alteração de algum atributo do seu inode. Comando como chmod, chown,
chgrp alteram essa data pois alteram os atributos do inode.

A opção -mtime indica “modification time”, ou seja, a quantos dias o
conteúdo de um arquivo foi alterado.

Existe tambem a opção -atime, indicando “access time”. Serve para
verificar a quanto tempo um arquivo não foi acessado (lido, modificado
alterado permissão, etc).

– Exibe os arquivos que foram criados ou modificados durante os ultimos 4 dias
find /usr -mtime 4

– Exibe os arquivos que foram criados ou modificados durante os ultimos 5 dias
find /trabalho -ctime 5

– Para procurar quais arquivos foram criados ou modificados nos últimos 7
dias, deve usar a opção -mtime junto com a opção -ctime
find /trabalho -ctime 4 -a -mtime 4

– É feita uma busca para encontrar todos os arquivos terminados em .mm2 e
o comando tar receberá esta lista por meio do pipe (caractere “|”), indicada
pela flag “-T”. O sinal “-” significa “standard output”, ou o que veio pelo
pipe, que criará o arquivo backup.mm2.tar.gz irá conter apenas arquivos
terminados em .mm2
find . -name \*.mm2 | tar cvzf backup.mm2.tar.gz -T –

– Uso do find para achar todos os arquivos criados/modificados dia tal no
caso 18 de dezembro. O find tem 3 opções referentes a datas. São elas:
atime – Data do último acesso;
ctime – Data da última alteração no status do arquivo;
mtime – Data da última alteração nos dados do arquivo.
Estas 3 opções opções são usadas estipulando-se o número de dias desejado.
Assim usando -atime dd, serão listados todos os arquivos cujo útimo acesso
foi a dd dias. Se voce fizer -atime -dd, vc terá os arquivos cujo último
acesso foi há menos de dd dias, e de forma analoga, +dd significa há mais
de dd dias.

– Deleta arquivos core em todo o sistema
find / -name core -exec rm -f {} \;

– Cria um relatório com o tamanho de todos os diretórios do sistema
find . -type d -maxdepth 1 -exec du -s {} \;

– Cria um relatório com o tamanho de todos os diretórios do sistema
de forma ordenada:
find . -type d -maxdepth 1 -exec du -s {} \; |sort -n

– Cria um relatório com o tamanho de todos os diretórios do sistema
de forma ordenada e ainda caso queira que apareça primeiro os nomes
de diretórios seguido pelos respectivos tamanhos
find . -type d -maxdepth 1 -exec du -s {} \; |sort -n | sed -e “s/\([0-9]\+\)[[:space:]]*\(\.\/\)\?\(.*\)/\3 \1/”

– Para listar os arquivos modificados mais recentemente para o mais antigo
find / -mtime -1 | ls -t

– Para procurar em /home/user/fotos todas as imagens jpg e mostrar
com o software qiv
find /home/user/fotos -iname “*.jpg” -exec qiv -fm {} \;

– Para saber quantas fotos no diretório ‘/home/user/fotos’
find /home/user/fotos -iname “*.jpg” | wc -l

– Procura arquivos que não possuem dono em nosso sistema. Esta situação
é extremamente comum, visto que usuários são criados e apagados diaria-
mente e ficam vagando pelo sistema e podem eventualmente vir a comprometer
a segurança. Então será gerado uma listagem com todos os arquivos do
sistema que não pertencem a nenhum usuário cadastrado no sistema
find / -nouser -print

– Procura arquivos que não possuem dono em nosso sistema. Esta situação
é extremamente comum, visto que usuários são criados e apagados diaria-
mente e ficam vagando pelo sistema e podem eventualmente vir a comprometer
a segurança. Então será gerado uma listagem com todos os arquivos do
sistema que não pertencem a nenhum usuário cadastrado no sistema e logo
após serão apagados do sistema
find / -nouser -print | xargs rm

– Quero criar um script shell que aceite um parâmetro qualquer e busque este
parâmetro inserido pelo usuário dentro de páginas HTML em diretórios diversos.
Ou seja, quando o usuário rodar o comando, passando um argumento que pode ser
uma palavra, o script deverá procurar em todos os arquivos e subdiretórios
por aquela string específica.
find “$1” -type f -exec grep -l “$2” {} \;

isso é um grep recursivo que procura a string $2 a partir do diretorio $1.
A opcao -l lista todos os arquivos que contem a string. Sem esta opção, voce
vera todas as linhas onde ocorrem a string.

– Tenho um diretório raiz com vários arquivos e sub-diretórios. Estou mudado
alguns direitos para os grupos dos arquivos e diretórios com esse comando:
chmod g=rw -R *
Eu gostaria de alterar recursivamente, agora, somente os direitos dos
diretórios, sem alterar os dos arquivos. Isso é possível?

Costumo usar o find para isso
find /home/fabio/diretorio -type d -exec chmod g=rw {} \;

No caso, o “-type d” diz ao find para localizar apenas os diretórios e o
“-exec” manda executar o comando “chmod g=rw” sobre cada diretório que
ele encontrar, representado na sintaxe com comando com o “{}”. Repare
que existe um espaço antes do “\;” que fecha a linha de comando. No meu
exemplo o find vai atuar na árvore abaixo do diretório
“/home/fabio/diretorio”. Se quiser fazer isso apenas com arquivos, no
lugar de diretórios, bastaria usar “-type f”.
1.21 – comando locate = localiza arquivos, sendo que antes de executá-lo
pela primeira vez deve-se usar o comando “updatedb” para criar o banco
de dados e deve-se executá-lo freqüentemente (sempre que se instalar/remover)
programas no computador.

– Procura em todos os arquivos pela palavra text1
locate text1
1.22 – comando cd = acessa e sai de um diretório

– Alterna para o último diretório visitado:
cd –

– Acessa o diretorio /home
cd /home

– Sobe um diretório
cd ..

– Retorna ao diretorio raiz
cd /

– Acessa o diretorio home do usuario corrente: EX: /home/ederjordam
cd ~

– Acessa o diretório home do usuario ederjordam
cd ~ederjordam

– Sobe um diretório e entra imediatamente no próximo (por exemplo, quando
você está em ‘/usr/sbin’, você digita ‘cd ../bin’, o comando ‘cd’ retorna
um diretório (‘/usr’) e entra imediatamente no diretório ‘bin’ (‘/usr/bin’)
cd ../diretorio1 –
1.23 – comando alias = cria atalhos para comandos

– Acrescente os comandos abaixo no arquivo ‘/etc/bashrc’ para que seja
inicializado sempre que o sistema for reinicializado

alias cd.on=”mount /mnt/cdrom”
alias cd.off=”umount /mnt/cdrom”
alias desligar=”shutdown -h now”
alias floppy.on=”mount /mnt/floppy”
alias floppy.off=”umount /mnt/floppy&quot”
alias olhar-logs=”tail -f /var/log/messages”
1.24 – comando e2fsck – checa e corrige erros no sistema de arquivos. Deve-se
apenas usar o e2fsck para dar manutenção em particoes Linux Native. Pode-se
usar também o comando equivalente “fsck.ext2”

– Checa e corrige erros na partição hda1
e2fsck -y /dev/hda1

– Checa e corrige erros na partição hda2
e2fsck -y /dev/hda2

– Checa e corrige erros na partição hda3 executando também o comando
badblocks
e2fsck -y -c /dev/hda3

– Checa e corrige erros na partição hda4 forçando a verificação de sistemas
de arquivos que aparentam estar em bom estado
e2fsck -y -f /dev/hda4

– Checa e corrige erros na partição hda5 forçando o reparo automático sem
prompts
e2fsck -y -p /dev/hda5

– Faz uma checagem usando o modo “somente leitura” na particao hda1. Com a
opção ‘-n’ é possível checar o sistema de arquivos montado sem perda de dados
e2fsck -n /dev/hda1

– Faz uma checagem usando o modo “somente leitura” na partição hda1. Com esta
opção ‘-n’ é possível checar o sistema de arquivos montado sem perda de dados.
Com a opção ‘-c’ o sistema de arquivos será checado e permitirá atualizações
somente dos setores danificados, não alterando qualquer outra área
e2fsck -c -n /dev/hda1

– Para revisar uma partição use:
e2fsck -pycvf /dev/hda1

Opções:
-p: repara os erros automaticamente
-y: em questõs críticas irá assumir resposta afirmativa
-c: procura pro blocos defeituosos
-v: mostar todas as mensagens na terla (verboso)
-f: força checagem do sistema de arquivos estiver marcado como limpo
/dev/hda1 : é o dispositivo da partição, você não irá por a partição em si
mas sim o dispositivo de sua partição, assim se sua partição for a /dev/hda3
você irá por ela

-c faz o fsck.ext2 verificar se existem agrupamentos danificados na unidade
de disco

-d aciona o debug. Mostra todos os detalhes de processamento

-f força a checagem mesmo se o sistema aparenta estar em bom estado. Por
padrão, um sistema de arquivos que parece em bom estado não é verificado

-F grava os dados do cache no disco antes de iniciar o teste

-l:[arquivo] inclui os blocos listados no (arquivo) como blocos defeituosos
no sistema de arquivos. O formato deste arquivo é o mesmo gerado pelo programa
badblocks (veja mais adiante)

-L [arquivo] faz o mesmo que a opção -l, só que a lista de blocos defeituosos
do dispositivo é completamente limpa e depois a lista do (arquivo) é
adicionada ao teste

-n faz somente uma verificação de leitura no sistema de arquivos. Com esta
opção o sistema é verificado com o dispositivo montado. Nenhuma modificação
é feita no sistema. Apenas o teste de leitura é realizado

-p corrige automaticamente o sistema de arquivos sem perguntar nada. É re-
comendável fazer isto manualmente pra entender o que aconteceu, em caso de
problemas com o sistema de arquivos

-v ativa o modo verbose. Todas as mensagens de aviso são mostradas durante
a execução do programa

-y assume sim para todas as questões feitas durante o texto. O seu uso é
altamente não recomendável

– Caso a opção -c seja usada junto com -n, -l ou -L, o sistema de arquivos
será verificado e permitirá somente a atualizações setores danificados, não
alterando qualquer outra área do dispositivo. Se forem encontrados arquivos
com problemas e estes não puderem ser recuperados, o fsck perguntará se deseja
salvá-los no diretório lost+found. Após sua execução é mostrado detalhes sobre
o sistema de arquivos verificado como quantidade de blocos livres, ocupados e
taxa de fragmentação.
1.25 – comando type = exibe a localização de um arquivo no sistema. OBS:
Similar ao comando ‘whereis comando’.

– Exibe a localização do comando ‘bash’ no sistema
type bash

– Exibe a localização do comando ‘ls’ no sistema
type ls

– Exibe a localização do comando ‘cd’ no sistema
type cd
1.26 – comando diff = compara dois arquivos e exibe as diferencas entre
eles. O comando diff apenas faz comparacoes com arquivos no formato texto
O diff apresenta uma listagem das diferenças encontradas entre os 2 arquivos
passados como parâmetro, incluindo os comandos necessários para que um
editor (o ed, se não me engano) possa, a partir de um dos arquivos, igualar
o conteúdo do segundo. Se você quiser apenas verificar se 2 arquivos possuem
o mesmo conteúdo ou não, é mais eficiente usar o ‘cmp’, e testar o $? Ou
$status, dependendo do shell que esteja utilizando.

– Checa linha a linha para verificar se há ou não diferenças entre os arquivos
diff file1.txt file1.txt.old
– Compara os arquivos e exibe suas diferencas na tela
diff file1.txt file2.txt

– Compara os arquivos e enviapara o arquivo newfile.txt as diferencas dos
arquivos
diff file1.txt file2.txt > newfile.txt
– Faz a comparacao nos arquivos ignorando diferencas entre maiusculas e
minusculas
diff -i file1.txt file2.txt

– Exibe somente se os 2 arquivos possuem diferenças. Não exibe as dife-
renças entre eles
diff -q file1.txt file2.txt

– Aumenta a tabulação das diferenças encontradas nos arquivos comparados
diff -t file1.txt file2.txt

– Compara os arquivos ignorando linhas em branco diferentes entre os 2
arquivos e usando o formato unificado
diff -B -u file1.txt file2.txt

– Compara o diretório e subdiretorios ‘/usr/dir1/’ e ‘/usr/dir2/’ armazenando
as diferencas entre os diretórios no arquivo ‘comparacao.txt’
diff -r /usr/dir1/ /usr/dir2/ > comparacao.txt
– Obtem cada linha do primeiro arquivo, verifique se ela existe no segundo
(que também possue um nome por linha) e caso não exista, jogua essa linha
para um terceiro arquivo
diff arquivo1.txt arquivo2.txt | grep “<” > arquivo3.txt

– Ler cada linha do segundo arquivo e verificar se ela existe no primeiro
arquivo e se não existir, jogar essa linha para um determinado arquivo
diff arquivo2.txt arquivo1.txt | grep “<” > arquivo4.txt

– Verifica o que há de diferente nos diretórios e exibirá as diferenças
diretamente na tela o monitor
diff -uNr diretorio.original diretorio

– Verifica o que há de diferente nos diretórios e redirecionará a saída do
comando para o arquivo resultado.txt
diff -uNr diretorio.original diretorio > resultado.txt
1.27 – comando comm = compara dois arquivos ordenados linha a linha. Este sem
opções produz uma saída de três colunas. A Coluna 1 contém linhas que são
exclusivas do arquivo file1.txt, a coluna 2 contém linhas que são exclusivas
do arquivo file2.txt e a coluna 3 contém linhas comuns aos dois arquivos.
As opções -1, -2, e -3 impedem a exibição das colunas correspondentes
comm -123 file1.txt file2.txt
1.28 – comando wc = lista o número de bytes, palavras e linhas nos arquivos

– Exibe o numero de linhas, palavras separadas por espaços em branco e o
tamanho em bytes do arquivo file1.txt
wc file1.txt

– Exibe o tamanho em bytes do arquifo file2.txt
wc –bytes file2.txt

– Exibe o tamanho em bytes do arquifo file3.txt
wc –chars file3.txt

– Exibe as palavras separadas por expaços em branco no arquivo file4.txt
wc –words file4.txt

– Exibe o numero de linhas do arquivo file5.txt
wc –lines file5.txt
1.29 – comando grep = procura strings (frases) ou palavras em um arquivo

^ acento circunflexo
.. ponto
\ barra invertida
{ chave
\ outra barra invertida
} outra chave
$ cifrao
1,4 de 1 a 4 caracteres

– Para procurar no hd por uma determinada string
grep -rin string *

– Para procurar no diretório /etc por uma determinada string
grep -R padrao /etc/

– Procura em todos os arquivos de texto e exibe todas as linhas em que
a palavra GNULINUX aparece
grep -n GNULINUX *.txt

– Procura a string ‘:0:’ no arquivo /etc/passwd
grep :0: /etc/passwd

– Procura a palavra ‘jordam’ no arquivo texto1.txt
grep jordam /home/texto1.txt

– Procura a string ‘Eder Jordam’ no arquivo file1.txt
grep “Eder Jordam” file1.txt

– Procura a frase Eder Jordam no arquivo file1.txt exibindo o
número de cada linha encontrada
grep “Eder Jordam” -n file1.txt

– Procura a palavra “jordam” em todos os arquivos TXT do diretorio atual
grep jordam *.txt

– Procura em todos os arquivos a frase Chicago Bulls is the best
grep “Chicago Bulls is the best” *

– Exibe os arquivos do diretorio atual com a data de modificação do dia
28 de março
ls -lha | grep “Mar 28”

– Faz uma busca pela expressão ‘servidor’ dentro de todos os arquivos do
diretório /etc
grep -s servidor /etc/*

– Exclui as linhas do arquivo file1.txt que tenham o conteúdo ‘basquete’
grep -v basquete file1.txt > novo-arquivo.txt
– Procura pela ‘palavra1’ nos arquivos do diretorio especificado
grep palavra1 /diretorio/*

– Procura pela “frase qualquer” com maiusculas ou minúsculas, no diretório
atual
grep -i ‘frase qualquer’ ./*

– Procura por qualquer palavra que comece com um número de 0 a 9 nos arquivos
dos diretório /home/docs/
grep ‘[0-9]palavra’ /home/docs/*

– Procura por qualquer palavra que comece com as letras a, b ou c nos arquivos
do diretório especificado
grep ‘[abc]palavra’ ../*

– Procura pela palavra que comece com qualquer caractere EXCETO as letras a,
b ou c no arquivo file1.txt
grep ‘[^abc]palavra’ file1.txt

– Visualiza de forma rápida os serviços habilitados habilitados para
iniciliazação do inetd
grep -v ^# /etc/inetd.conf | sed -e ‘/^S/d’

– Retira do arquivo file1.txt todas as linhas que possuem nenhum, 1, 2, 3,
ou 4 caracteres entre aspas existe na sequencia
grep -v ‘^.\{1,4\}$’ file1.txt > arquivo_final

– A opção -v do grep indica para listar somente as linhas que não são reconhe-
cidas pelos padrões (que nesse caso está em um arquivo). A opção -f indica
que os padrões a serem procurados não são especificados na linha de comando
e sim em um arquivo, cujo nome deve ser fornecido após a opção -f. A opção
-x representa que o padrão será procurado em toda a linha (você disse que era
um nome por linha.
grep -x -v -f arq1 arq2 > arq_diff_1_2
grep -x -v -f arq2 arq1 > arq_diff_2_1

– O comando grep possui algumas formas de funcionamento bem interessantes.
Recentemente eu precisei localizar alguns arquivos e tratá-los de forma
a remover algumas formatações erradas. Veja os exemplos:
grep CODE *.src
a.src:CODE
c.src:CODE
f.src:CODE

Para que eu tenha apenas o nome dos arquivos onde se encontra a palavra
“CODE”, eu posso usar o comando grep da seguinte forma:
grep -l CODE *.src
a.src
c.src
f.src

A opção “-l” me indica apenas o arquivo onde a palavra CODE se encontra
porém não exibe as linhas do arquivo, o que é o padrão do comando grep.
Uma vez de posse desta lista, eu precisava mover estes arquivos para
um outro diretório, onde então seriam editados

#!/bin/bash
for file in `grep -l CODE *.src`
do
mv $file repair
done

Na estrutura acima, “repair” é o nome de um diretório para onde os arquivos,
retornados pelo comando grep, serão movidos.

– Retorna o numero da linha de um arquivo que tem a sequencia de strings
que eu queira
grep -n “string-a-ser-encontrada” file1.txt

– Exibe todas as linhas exeto as que tenham joao e maria
egrep -v ‘(joao.*maria|maria.*joao)’

– Se fosse pra tirar tanto as que tivessem joao quanto as que tivessem maria,
grep -v ‘(joao|maria)’ file1.txt

– Procura por uma linha com o comando ‘setterm -blank’ nos arquivos dentro
do diretório /etc/rc.d/
grep -r “setterm -blank” /etc/rc.d/

– Tenho varios arquivos direrentes e gostaria de selecionar apenas os arquivos
que contem uma determinada palavra(dentro do arquivo).
grep -lF palavra arq1 arq2 arq3
se voce quiser todos os arquivos do diretório, tambem pode fazer:
grep -lF palavra *
ou
grep -lF palavra * 2> /dev/null
mostra somente os nomes de arquivos que contêm a ocorrência e ‘joga fora’
os nomes dos subdiretórios porventura existentes

– Do que se trata a porta 161 UDP?
grep ‘\<161/udp\>’ /etc/services
esta porta é para o protocolo SNMP que é usado para dar informações sobre o
sistema. Se você não usa, desligue o serviço.

– Estou usando o comando grep para pesquisar uma coincidencia em um arquivo
só que esta pesquisa retorna muitas linhas, como eu faria para pegar
determinada linha, a primeira ou somente a terceira?
A primeira linha:
grep “o que vc está procurando” nome_do_arquivo | sed ‘1!d’

A terceira linha:
grep “o que vc está procurando” nome_do_arquivo | sed ‘3!d’

– Contagem de Acertos: para determinar o número de arquivos que obedecem a
determinado critério de busca use o comando grep -c:
ls
a ba c d e f

– Exibe quantos arquivos possum a letra a em seu nome
ls | grep -c a
2
a resposta é dois: os arquivos chamados a e ba.

– Exibe quantos arquivos começam com a letra a
ls | grep -c “^a”
1
apenas o arquivo chamado a atende a esta busca.

Arquivos que terminem em a:
ls | grep -c “a$”
2
neste caso a resposta também é dois: os arquivos a e ba.
1.30 – comando file = determina o tipo de um arquivo

– Exibe que tipo de arquivo é, ou seja, um texto, uma imagem etc
file arquivo1

– Exibe o tipo do arquivo seguindo os links simbolicos
file -L arquivo2

– Tenta exibir o tipo dos arquivos dentro de um arquivo compactado
file -z arquivo3

– Exibe a versão do programa file
file -v
1.31 – Descompactando arquivos

– Para descompactar arquivos no formato ‘bz2’
bunzip2 -d nome-do-arquivo.bz2
– Para descompactar arquivos no formato ‘tar’
tar -xvf nome-do-arquivo.tar
– Para descompactar arquivos no formato ‘tar.gz’
tar -zxvf nome-do-arquivo.tar.gz
– Para descompactar arquivos no formato ‘tgz’
gunzip nome-do-arquivo.tgz
– Para descompactar arquivos no formato ‘gz’
gunzip nome-do-arquivo.gz
ou
gzip -d nome-do-arquivo.gz
– Para descompactar arquivos no formato ‘zip’
unzip nome-do-arquivo.zip
– Para descompactar arquivos no formato ‘rar’
unrar e nome_do_arquivo.rar
– Para descompactar arquivos no formato ‘Z’
uncompress nome-do-arquivo.Z

– Exibe uma descrição contendo os nome dos arquivos que estão compactados
no arquivo ‘files.zip’ testando a integridade do mesmo
unzip -t files.zip
– Exibe uma descrição contendo os nome dos arquivos, data, hora e tamanho
que estão compactados no arquivo ‘files.zip’
unzip -l files.zip
– Exibe uma descrição contendo os nome dos arquivos e seus conteúdos
(formato TXT) que estão compactados no arquivo ‘files.zip’
unzip -c files.zip
– Descompacta o arquivo ‘files.zip’ no diretorio ‘/usr’ (opção ‘-d’)
unzip files.zip -d /usr/

– Descompacta apenas os arquivos que são mais recentes no diretório /usr
unzip -f files.zip -d /usr

– Descompacta o arquivo ‘files.zip’ mas nunca substituindo arquivos já
existentes
unzip -n files.zip
– Descompacta o arquivo ‘files.zip’ substituindo arquivos existentes sem
perguntar. Tem a função contrária a opção ‘-n’
unzip -o files.zip
– Permite descompactar arquivos ZIP protegidos por senha
unzip filez.zip -P senha

– Descompacta arquivos que são mais recentes do que as versões já
existentes dos mesmos, bem como arquivos que ainda não existem
unzip -u files.zip
– Exibe o comentário de um arquivo compactado
unzip -z files.zip
– Descompacta o arquivo ‘files.tar.gz’ no diretorio ‘/usr’ (opção ‘-C’)
tar -zxvf files.tar.gz -C /usr

– Copia para vários disquetes o arquivo musica1.mp3 solicitando disquetes
até o termino da cópia
tar -cvMf /dev/fd0 musica1.mp3

– Restaura o arquivo musica1.mp3 para o diretorio atual
tar -xvMf /dev/fd0 musica1.mp3

– Exibe o conteúdo do arquivo ‘tar.gz’
tar -tz file.txt.tar.gz
– Exibe o conteudo do arquivo ‘texto.txt.bz2’
bzip2 -c texto.txt.bz2
– Exibe o conteúdo do arquivo ‘file7.gz’
gzip -l file7.gz

– Verifica a integridade do arquivo ‘texto.txt.bz2’
bzip2 -t texto.txt.bz2
1.32 – Compactando arquivos

– O comando tar = não é um compactador e sim um ‘arquivador’ (ele junta
vários arquivos em um só), mas pode ser usado em conjunto com um
compactador (como o “gzip” ou “zip”) para armazena-los compactados.

tar -c = cria um novo arquivo tar
tar -t = lista o conteudo do arquivo tar
tar -x = extrai arquivos de arquivo tar
tar -v = exibe uma lista com cada arquivo sendo processado
tar -u = atualiza arquivos compactados no arquivo tar
tar -f = arquivo de origem/destino
tar -T = indica quais arquivos irão compor o arquivo criado
tar -X arquivo = tenta apagar o arquivo dentro de um arquivo compactado

tar -z = filtra o arquivo com gzip (.tar.gz) ou (.tgz)
tar -j = usa o programa bzip2 para processar os arquivos do tar (.tar.bz2)
tar -Z = usa o programa compress para processar os arquivos do tar
(.tar.Z) ou (.tgZ’

tar -W = tenta verificar o arquivo gerado pelo tar após grava-lo
tar -M = cria/lista/extrai arquivos multi-volumes
tar -u = inclui em um arquivamento existente apenas arquivos que sejam
mais recentes do que a copia do arquivamento

– Para criar um arquivo chamado ‘backup1.tgz’ contendo os arquivos
‘agora1.txt’, ‘agora2.txt’ e ‘agora3.txt’
tar -cvzf backup1.tgz agora1.txt agora2.txt agora3.txt

– Para cria um arquivo chamado ‘backup_diario.19-Jul-2002.tar’ contendo os
arquivos ‘agora1.txt’, ‘agora2.txt’ e ‘agora3.txt’
tar -cvf backup_diario.`date +%d-%b-%Y`.tar agora1.txt agora2.txt agora3.txt

– Para criar um arquivo chamado ‘backup2.tgz’ contendo os arquivos
do diretório ‘trabalhos’
tar -cvzf backup2.tgz trabalhos/

– Para criar um arquivo chamado ‘backup3.tar.gz’ contendo todos os arquivos
que tem como proprietário/dono o usuário ederjordam
tar -cvzf backup3.tar.gz `find . -user ederjordam -print`

– Para criar um arquivo chamado ‘backup4.tar’ contendo todos os arquivos
exceto o diretório ‘/var/spool/squid’
tar -f backup4.tar -exclude /var/spool/squid

– Para criar um arquivo chamado ‘backup5.tar’ contendo os diretórios
‘dir1’, ‘dir2’ e ‘dir3’
tar -cvf backup5.tar dir1 dir2 dir3

– Para criar um arquivo chamado ‘backup6.tar.gz’ contendo apenas arquivos que
atendam a determinado critério de seleção, como o exemplo contendo apenas
arquivos com a extensão TXT, encontrados a partir do diretório atual e
identificados pelo comando ‘find’
tar cvzf backup6.tar.gz -T `find . -name \*.txt`

– Para criar um arquivo chamado ‘backup7-date-dia-mes-ano.tar.gz’ contendo
todos os arquivos do diretório ‘/home/usuario1/work5’
tar -zcvf backup7-`date +%d%m%y`.tar.gz /home/usuario1/work5

– Para compactar um diretório mas ignorando um subdiretório dentro deste
diretório:
tar –exclude=”diretorio_a_excluir” -cf container.tar dir1 file1

Você pode excluir um ou mais diretorios/arquivos, é so sair adicionando
varios ‘–exclude’ na linha de comando ou se preferir pode gerar um lista
em um arquivo txt e passar o arquivo como parametro. Veja os argumentos
abaixo:
–exclude=PATTERN exclude files, given as a PATTERN
-X, –exclude-from=FILE exclude patterns listed in FILE

– Para realizar um backup de todo HD
tar clf – / | tar -C “/ponto-de-montagem” -xvf –

‘/’ : estarias fazendo o backup a partir do barra do teu hd
‘/ponto-de-montagem’ : ponto onde esta montado o seu backup

– Para criar um arquivo chamado ‘teste.txt.gz’ utilizando compactação máxima
gzip -9 tese.txt
– Força a compactação mesmo quando um arquivo de mesmo nome já existe e será
sobrescrito pelo arquivo compactado
gzip -f tese.txt
– Testa a integridade do arquivo compactado ‘backup10.gz’
gzip -t backup10.gz

– Para criar um arquivo chamado ‘backup1.zip’ contendo os arquivos
‘tese1.txt’, ‘tese2.txt’ e ‘tese3.txt’
zip backup1.zip tese1.txt tese2.txt tese3.txt

– Para criar um arquivo chamado ‘backup2.zip’ contendo todos os arquivos
com extensão TXT
zip backup2.zip *.txt

– Para criar um arquivo chamado ‘backup3.zip’ contendo todos os arquivos
com extensão TXT do diretório /usr e sub-diretórios
zip -r backup3.zip /usr/*.txt

– Parar criar um arquivo chamado ‘backup4.zip’ contendo todos os arquivos
do diretório atual utilizando compatação máxima
zip -9 backup4.zip *

– Verifica se o arquivo ‘backup4.zip’ contém erros
zip -T backup4.zip

– Caso o arquivo ‘backup4.zip’ esteja danificado, o comando abaixo tentará
arrumá-lo
zip -F backup4.zip

– Para criar um arquivo chamado ‘backup5.zip’ contendo todos os arquivos
e sub-diretórios do diretório ‘/home/user’. A opção ‘-r’ é recursivo, ou
seja, utilize-o caso queira copiar todos os arquivos e sub-diretórios dentro
do diretório ‘/home/user’
zip -r backup5.zip /home/user/*
1.33 – comando rpm

– Para reconstruir a base de dados RPM que está corrompida
rpm –rebuildb

– Gera um arquivo RPM no diretório ‘/usr/src/redhat/RPMS/i386’
rpm –rebuild pacore.src.rpm
– Verifica a assinatura do pacote
rpm -checksig nome-do-pacote

– Atualiza e instala um pacote no sistema
rpm -Uhv nome-do-pacote.rpm
– Instala um pacote no sistema
rpm -ivh nome-do-pacote.rpm
– Força a atualização de um pacote (não é recomendável utilizar este
comando)
rpm -Uhv nome-do-pacote.rpm
– Força a instalacao de um pacote de versão anterior à já instalada
no sistema
rpm -Uhv nome-do-pacote.rpm –oldpackage

– Checa a integridade dos pacotes instalados (desde que o banco de dados
rpm não esteja corrompido)
rpm –verify -a

– Faz uma pesquisa para encontrar o pacote RPM instalado no sistema que
possui o arquivo ‘libncurses.so.5’
rpm -q –whatprovides libncurses.so.5
– Exibe os pacotes dos quais este depende
rpm -qR nome-do-pacote

– Exibe informacoes sobre o pacote
rpm -qpi nome-do-pacote.rpm
– Exibe informações do pacote, tais como nome, descrição, release,
tamanho, data de criação, data de instalação
rpm -qi nome-do-pacote

– Exibe todos os pacotes instalados no sistema
rpm -qa

– Verifica se o pacote referente ao software livre apache está instalado
no sistema
rpm -qa | grep apache

– Verifica se um determinado pacote está instalado no sistema
rpm -q nome-do-pacote

– Exibe o nome do pacote instalado no sistema que contem o
nome-do-programa
rpm -qf /usr/bin/Eterm

– Exibe todos os arquivos relacionados ao programa (EX: /usr/bin/awk)
sem saber o pacote
rpm -qdf nome-do-programa

– Exibe a lista de todos os arquivos que o pacote possui
rpm -qpl nome-do-pacote.rpm
– Exibe os arquivos contidos no pacote. (EX: rpm -ql squid)
rpm -ql nome-do-programa

– Exibe os pré-requisitos para a instalação do pacote
rpm -qpR nome-do-pacote.rpm
– Remove um pacote do sistema
rpm -e nome-do-pacote.rpm
– Força a remocao do pacote
rpm -e nome-do-pacote.rpm –nodeps –force

– Verifica a integridade do pacote
rpm -K –nopgp nome-do-pacote.rpm
– Exibe o changelog de um pacote instalado no sistema
rpm -qf –changelog nome-do-pacote

– Procura se o arquivo ‘file1.txt’ existe nos pacotes que estão
instalados no sistema
rpm -qpl *.rpm | grep file1.txt

– Procura nos pacotes RPM que estão no CD-ROM pelo arquivo ‘lib-so.1.0’
rpm -qp –filesbypkg /mnt/cdrom/distro/RPMS/* | grep lib-so.1.0

– Procura nos pacotes RPM do diretório atual pelo arquivo ‘libjpeg.so.6’
rpm -qp –filesbypkg * | grep libjpeg.so.6
– Visualiza os arquivos dentro do pacote
rpm -qpi –filesbypkg pacote1.rpm

– Exibe os pacotes que dependem do pacote glib
rpm -q –whatrequires glib

– A libXm pertence ao pacote lesstif
rpm -qf /usr/X11R6/lib/libXm.so.2.0.1
– Exibe os pacotes RPM que o pacote glib necessita para ser instalado
rpm -q –requires glib

– É possível utilizar um pacote fonte para construir um pacote RPM
contendo os arquivos binários adequados à arquitetura da máquina em
que ele será utilizado. Se você possui o arquivo fonte e deseja cons-
truir um pacote contendo os binários para que o programa possa efeti-
vamente ser instalado. O pacote será construído e colocado no diretório
‘/usr/src/rpm/RPMS/arquitetura’ onde arquitetura é o processador para
o qual o pacote foi compilado normalmente i386. Proceda então a instalação
como faria normalmente
rpm –rebuild pacote.src.rpm
– A libraw1394 é a única interface suportada pela parte raw1394 no
sub-sistema IEEE 1394 no kernel Linux que fornece acesso direto aos
barramentos 1394 conectados para aplicações fora do kernel
rpm -q –qf “%{description}\n” libraw1394

– Extrai o conteudo do pacote RPM no diretorio atual
rpm2cpio pacote.rpm | cpio -ivd

– Exibe qual pacote RPM possui o arquivo gnomeconf sem instalar o
pacote RPM
rpm -qpi *.rpm | grep -i gnomeconf

– Instala o pacote RPM mesmo possuindo um arquivo de mesmo nome já
instalados no sistema
rpm -Uhv pacote.rpm -replacefiles

– Exibe informações sobre as mudanças (alteracoes) neste pacote
rpm -q –changelog nome-do-pacote

– Verificação de um pacote provoca a comparação dos arquivos instalados
de um pacote com as informações localizadas nas bases de dados do RPM.
Entre outras coisas a verificação compara o tamanho, MD5 sum, permissões,
tipo, dono e grupo de cada arquivo
rpm -V nome-do-pacote

– Verifica um pacote que contenha o arquivo ‘/bin/ls’. Outra função do
comando seria quando alguns problemas estão ocorrendo com o arquivo
‘/usr/bin/paste’. Inicialmente pode-se verificar a qual pacote o arquivo
pertence e se ele está íntegro
rpm -Vf /bin/ls

– Verifica todos os pacotes instalados. Tambem útil quando alguns arquivos
foram apagados acidentalmente, mas não se tem certeza de quais arquivos o
foram. Se alguns arquivos não forem localizados ou aparentem estar corrom-
pidos, pode-se reinstalar o pacote imediatamente
rpm -Va
– Verifica um pacote instalado e o arquivo do pacote RPM
rpm -Vp Eterm-0.9-4cl.rpm

Esta função pode ser útil caso haja alguma suspeita de que a base de dados
RPM esteja corrompida. Se não houver nenhuma discrepância não haverá resposta
do sistema, caso contrário será apresentada na forma de um string com 8
caracteres, com um c significando arquivo de configuração e após o nome do
arquivo. Cada um dos 8 caracteres significa um dos atributos do arquivo
comparado com aqueles definidos no pacote RPM onde um ponto significa que
o atributo está ok. Os atributos são mostrados abaixo:
Código Significado
5 MD5 checksum
S Tamanho do arquivo
L Link simbólico
T Modificação do arquivo
D Device
U Usuário
G Grupo
M Modo (inclui permissões e tipo de arquivo)
Caso algum código seja apresentado, é necessário avaliar a necessidade
de remoção do pacote, ou de sua reinstalação

– Exibe informações sobre as ultimas alterações no pacote RPM
rpm -qp –changelog pacote.src.rpm | head

– Exibe informações sobre as últimas alteracoes no pacote RPM
rpm -q –changelog rp-pppoe

– Força a reinstalacao do pacote
rpm -Uvh nome_do_pacote.rpm –force –allfiles

– Força a reinstalacao do pacote substiuindo possíveis arquivos existentes
rpm -Uhv nome_do_pacote.rpm –force –replacefiles

– Verifica se o pacote não está corrompido. Além do md5 ele checa a assinatura
digital(se estiver presente).
rpm -vK nome_do_pacote.rpm
– Exibe o nome do pacote RPM que armazena o comando ping
rpm -qf /bin/ping

– Sempre que der pela falta de um programa, depois de tê-lo procurado
com os comandos:
whereis programa
find / -name programa
rpm -qa | grep programa

Você pode inserir o CD de instalação, mudar para o diretório dos RPMS
‘/mnt/cdrom/distribuicao/RPMS’ e procurá-lo
rpm -qp -filesbypkg *.rpm | grep programa
1.34 – comando hdparm = define parametros de acesso para discos rígidos.

– Exibe informações sobre o HD
hdparm /dev/hda

– Exibe mais informações sobre o HD
hdparm -i /dev/hda

– Testando o acesso do dispositivo ‘/dev/hda’
htparm -t /dev/hda

– Testa a velocidade de leitura do buffer-cache e do disco ‘/dev/hda’
hdparm -tT /dev/hda

– Modo básico de configuração do hdparm
hdparm -c1 -d1 /dev/hda
ou
hdparm -c 1 -d 1 /dev/hda

– Configura o parâmetro “MaxMultSect” para 16
hdparm -m 16 /dev/hda

– Habilita o acesso a 32bits e UDMA/100
hdparm -d1 -c1 -X 69 /dev/hda
ou
hdparm -d 1 -c 1 -X 69 /dev/hda
1.35 – comando echo = acrescenta palavras, frases a um arquivo

– Operações diversas 1
touch arquivo1.txt
echo “Enviando uma frase” > arquivo1.txt
echo “Enviando mais uma frase” >> arquivo1.txt

– Operações diversas 2
echo “Olá mundo!” >> /home/file1.txt
echo “/sbin/ismod cim.o” >> /etc/rc.d/rc.local
– Para exibir o PATH atual
echo $PATH

– Para ouvir um beep do speaker do computador
echo -e “\a”

– Para efetuar uma soma
echo $[1 + 3]

– Para efetuar uma subtração
echo $[23 – 2]

– Para efetuar uma multiplicação
echo $[45 * 4]

– Para efetuar uma divisão
echo $[80 / 40]

– Para modificar a senha do usuário ‘user1’
echo ‘senha’ | passwd –stdin user1

– Se você não sabe se o make (ou outro script) foi executado com sucesso
ou nao, execute este comando. O $? é uma variavel especial do shell que
contem o resultado do ultimo comando. Se ela contiver o valor 0, significa
que o ultimo comando (no caso make bzImage) foi executado corretamente.
Caso contrario, algum erro aconteceu.
echo $?
1.36 – comando nice = altera as propriedades de execução de um processo.

– Para configurar uma menor prioridade ao processo
nice -n 19 nome-do-programa

– Para configurar uma maior prioridade ao processo
nice -n -19 nome-do-programa
1.37 – comando bc = uma calculadora que funciona no console

– Para somar números
8 + 2 e tecle ENTER

– Para diminuir números
8 – 2 e tecle ENTER

– Para multiplicar números
8 * 2 e tecle ENTER

– Para dividir números
8 / 2 e tecle ENTER

– Para sair do bc digite
quit
1.38 – comando tail = exibe o final do conteúdo de um arquivo

– Para exibir as 10 últimas linhas do arquivo ‘/var/log/messages’
tail /var/log/messages

– Para exibir as 50 últimas linhas do arquivo ‘/var/log/messages’
tail -50 /var/log/messages

– Para exibir as últimas 23 linhas do arquivo ‘/var/log/messages’
tail -n 23 /var/log/messages

– Para exibir o conteúdo do arquivo ‘/var/log/messages’ em tempo real
tail -f /var/log/messages

– Para exibir o conteúdo do comando ‘tail’ no terminal ‘/dev/tty7’
tail -f /var/log/messages > /dev/tty7 &

– Para exibir as 100 últimas linhas do comando ‘tail’ no terminal ‘/dev/tty7’
tail -100 /var/log/messages > dev/tty7
1.39 – comando watch = executa um programa periodicamente, exibindo sua
saída no terminal.

– Para monitorar o tráfego online de FTP, WWW e outros
watch -n 1 netstat -a

– Para monitorar o conteúdo do diretório padrão, ou seja, se você alterar
um nome de um arquivo, o mesmo será exibido depois da alteração automa-
ticamente
watch -d ls -l

– Para monitorar apenas os arquivos e diretórios em que seu proprietário/dono
é o usuário ‘edersg23’
watch -d ‘ls -l | fgrep edersg23’

– Atualiza de 1 em 1 segundo os resultados na tela do comando sensors
watch -n 1 “sensors”
1.40 – comando mknod = cria arquivos especiais de blobo ou caracteres

– Para criar o arquivo especial referente ao CD-ROM sob /dev/hdb
mknod /dev/hdb b 3 64
1.41 – comando basename = retira o diretório e sufixo de arquivos
1.42 – comando chfn = é usado para alterar as informações do usuário
apresentadas pelo comando finger. Esta informação é armazenada no
arquivo /etc/passwd, e é apresentada pelo programa finger. O comando
finger apresentará as informações em quatro partes que podem ser
alteradas por chfn: nome verdadeiro, nome da empresa e telefone e
telefone residencial.

OPCOES:
-f nome = altera o nome verdadeiro ou completo do usuário
-r nome = altera o número da sala do usuário
-o nome-empresa = nome da empresa.
-p telefone-escritorio = telefone comercial
-h telefone-residencial = alterao telefone residencial do usuário
1.43 – comando chsh = altera o interpretador de comandos do usuário
(login shell)

– Para alterar o shell do usuário ‘user1’ para ‘/bin/tcsh’
chsh -s /bin/tcsh user1

– Para exibir a lista de interpretadores de comandos presentes no
arquivo ‘/etc/shells’
chsh -l
1.44 – comando uuencode = converte um arquivo binário em um arquivo de
texto ASCII totalmente codificado para que possa ser enviado via e-m@il.

– Envia um email:
uuencode arquivo2.txt arquivo2.txt | mail -s Titulo-do-email user@dominio.com
E quando receber, salve a mensagem em disco e utilize o comando uudecode.
Se o arquivo da mensagem chama-se ‘file5’, digite:
uudecode file5

– Envia uma imagem por email:
uuencode foto.png new-name.png | mail -s “$assunto” $email`;
1.45 – comando uudecode = converte o arquivo codificado para o seu formato
original depois da recepção pelo destinatário.
uudecode arquivo-temporario
1.46 – comando convert = converte uma imagem de um certo padrão (jpg) para
um outro padrão (png). O comando convert faz parte do pacote ImageMagick.

– Para converter uma imagem no formato JPG para o formato PNG
convert arquivo.jpg arquivo-convertido.png
1.47 – comando import = importa a tela atual do desktop. O comando import
faz parte do pacote ImageMagick.

– Para obter um screenshot da tela:
import -window root shot23.jpg
import -window root shot33.png
import -geometry 800×600 file1.jpg
import -geometry 800×600 file2.png
import -geometry 104×768 file3.jpg
import -geometry 104×768 file3.png
sleep 30; import -window root shot.jpg -quality 80

pode-se usar o programa ksnapshot ou colar a IMG no programa GIMP
1.48 – comando xwd = importa a tela atual do desktop.

– Para salvar o conteúdo da tela no arquivo ‘shot1.xwd’
xwd -display :0.0 -root -out shot1.xwd
1.49 – comando tac = exibe o conteúdo do arquivo do final para o inicio,
ou seja, começa exibindo a última linha até a primeira linha do arquivo
tac arquivo1.txt
1.50 – comando cryptdir = criptografa todos os arquivos em um diretório.

– Para criptografar todos os arquivos no diretório ‘/home/secreto’
cryptdir /home/secreto

Ao criptografar arquivos, uma senha será solicitada a voce 2 vezes. Essa
senha é necessária para descriptografar arquivos. Estes arquivos terão
a extensão .crypt incluídas em seus nomes
1.51 – comando decryptdir = descriptografa todos os arquivos em um diretório.
Os arquivos devem ter sido criptografados com o comando cryptdir.

– Para descriptografa todos os arquivos do diretório ‘/home/secreto’
decryptdir /home/secreto
1.52 – comando gzexe = cria um arquivo compactado executável. Se você
compactar um arquivo binário ou um script com o comando gzexe, então
poderá executá-lo como se ele estivesse descompactado. Quando compactar
um arquivo chamado arquivo1, o original descompactado será copiado em
arquivo1~ e o arquivo compactado manterá o nome arquivo1.

– Descompacta o arquivo especificado em vez de compactá-lo
gzexe -d nome-do-arquivo
1.53 – comando alien = converte pacotes

– Para converter um pacote RPM para um pacote DEB
alien -d nome-do-pacote.rpm
– Para converter um pacote DEB em RPM
alien -r nome-do-pacote.deb
1.54 – comando sed = stream editor

– Preciso preencher espacos com o caractere + Assim:
echo “Informe seu nome:”
read nome
echo $nome
Resultado: Pedro Afonso Segundo
Preciso: Pedro+Afonso+Segundo

echo “Informe seu nome:”
read nome
echo $nome | sed -e ‘s/ /+/g’

– sed -n NUMERODA_LINAp /usr/ed1.txt = exibe um numero da linha do arquivo
ed1.txt

– Como fazer para reconhecer um padrão em várias linhas?
Como separar esse trecho de um arquivo texto e mandar para saida padrão?
#<inicio>
….
…
…
..
#</fim>

Digite o comando :
sed -n -e “/#<inicio>/, /<\/fim>/p” nome_do_arquivo

– Como fazer a remoção do espaço em branco ao final das linhas:
Primeira maneira:
sed ‘s/ *$//’ arquivo in > arquivo.out
note: nem precisa do g,
Outra forma:
sed ‘s/ *$//g’ arquivo.in > arquivo.out && mv arquivo.out arquivo.in
– Todo mundo já teve que formatar um texto, quebras linhas, juntar parágrafos
e, ao final, percebe que existem espaços brancos nos finais das linhas. Para
remover os espaços, utilizando ‘sed’, façamos o seguinte:
cat arquivo.in | sed ‘s/ *$//g’ > arquivo.out
– Preciso exibir a enésima linha de todos os arquivos de um diretório.
sed -n 7p arquivo

“sed -n 7p *” nao funcionou, entao:
for x in *; do sed -n 7p $x; done

ou se quiser fazer do jeito unix
cat arquivo | head -7 | tail -1
7 é a linha que se quer mostrar.

sed ‘/bola/d’ file1.txt > arq_new = exclui as linhas do arquivo file1.txt
que tenham o conteudo igual a palavra bola

sed ‘s/bulls/chicago/g’ file1.txt > basq23.txt = faz uma procura no arquivo
file1.txt em busca de palavra bulls que sera trocada pela palavra chicago, e
sera enviada estas alteracoes para um novo arquivo, o basq23.txt
1.55 – comando dos2unix = converte a formatacao de arquivos no formato
DOS/MAC para formatacao UNIX

– Para retirar os caracteres ‘^M’ (quebra de linha) do arquivo ‘file1.txt’
dos2unix file1.txt

Sistemas operacionais diferentes gravam arquivos-texto de forma diferente.
O Unix grava arquivos-texto separando as linhas com um Linefeed (código
ascii 0x0A, ou 10). O Windows, mais perdulário, grava arquivos-texto
separando as linhas com um carriage return e um linefeed (0x0D 0x0A) em
seqüência. O carriage return, ao ser mostrado na tela por alguns programas
(vi, por exemplo), aparece como ^M — que quer dizer Control-M. Solução:

1 – No vi, usar o seguinte comando de substituição:
:%s/^M// <enter>

lembrando q o ^M é Ctrl+V + Ctrl+M

OBS.: Não digite ^ e M; deixe Ctrl apertado, aperte V, deixe Ctrl apertado
aperte M. O Ctrl-V indica que o próximo caractere teclado deve ser
interpretado literalmente. Assim, Ctrl-V Ctrl-M faz aparecer ^M.
Isso retirará todos os ^M do seu texto.

Mas se você tiver vários arquivos, você pode colocá-los todos em
um diretório e, nesse diretório, rodar o seguinte scriptzinho:
for arq in *
do
tr -d ‘\r’ < “$arq” > “${arq}.novo”
mv “${arq}.novo” “$arq”
done

OBS: Coloque cópias dos arquivos, pois os originais serão apagados por
esse script
1.56 – comando awk = é uma linguagem para processamento de padrões.

– Para contar quantas linhas um determinado arquivo tem:
awk ‘END {print NR}’ arquivo.txt
– Para ler apenas uma determinada linha do arquivo (lerá apenas 30a. linha):
awk ‘NR == 30’ arquivo.txt
awk -F: ‘{print $1 ” -> ” $5}’ /etc/passwd = exibe os usuarios locais
do sistema e seus respectivos nomes completos.

awk -F: ‘{print $1 ” -> ” $5 ” -> ” $6}’ /etc/passwd = exibe os usuarios
locais do sistema, seus nomes completos e o shell aonde o usuario irá
se logar (ou o caminho de um programa que irá ser executado assim que
o usuário fizer o login na maquina).

– Precido fazer o segunte:
awk -F: ‘$3 igual 100 { print $1 }’ /home/nomes
Qual seria o comando que eu colocaria no lugar da palavra IGUAL.

Tente:
awk -F: ‘$3 == 100 { print $1 }’ /home/nomes

– Dentro do awk da pra pegar a linha de baixo?
Sim, vc pode usar o next, exemplo:
awk ‘{if($0 ~ /exec_args/)next;c=1;if(c == 1)print;exit}’ arquivo.txt
1.57 – comando tee = envia o resultado do programa para a saída padrão
(tela) e para um arquivo ao mesmo tempo.

– Exibe a saida do comando ls em uma coluna (-C1) e ao mesmo tempo
grava no arquivo ‘file1.txt’
ls -C1 * | tee file1.txt

– A saida do comando será mostrada normalmente na tela e ao mesmo
tempo gravada no arquivo ‘file1.txt’
ls -la | tee file1.txt
1.58 – comando nl = exibe o número de linhas juntamente com o conteúdo
do arquivo.

– Exibe o número de linhas e o conteúdo do arquivo ‘file1.txt’
nl file1.txt

– Para salvar o resultado em um outro arquivo
nl /file1.txt > /tmp/teste1.txt
1.59 – comando sort = organiza e ordena as linhas de um arquivo texto

– Organiza o conteúdo do arquivo ‘file1.txt’ em ordem crescente
sort file1.txt

– Organiza o conteúdo do arquivo ‘file1.txt’ em ordem decrescente
sort -r file1.txt

– Ignora diferencas entre letras maiusculas e minusculas durante a
organização
sort -f file1.txt

– Ignora linhas em branco
sort -b file1.txt

– Somente usa letras, digitos e espaços durante a organização
sort -d file1.txt

– Para remover linhas duplicadas em um arquivo:
sort aquivo1.txt | uniq >arquivo_novo.txt
– Caso estiver organizando um campo que contém números que serão
organizados na ordem aritmética. Por exemplo, se você tiver um
arquivo com os números
100
10
50
Usando a opção `-n’, o arquivo será organizado desta maneira:
10
50
100
Caso esta opção _não_ for usada com o `sort’, ele organizará como
uma listagem alfabética (que começam de `a’ até `z’ e do `0′ até `9′)
10
100
50
O comando é
sort -n file2.txt
1.60 – comando cut = remove para exibição seções de cada linha em arquivos.
É utilizado usado quando se deseja extrair campos ou pedaços de dados de
arquivos. Sintaxe:
cut -ccaracteres [arquivo]

Onde ‘caracteres’ é a porção que se deseja cortar de cada registro de
arquivo, podendo ser um simples numero ou uma faixa.

– Retira da saída do comando who até o nono caractere
who | cut -c-9

– Retira da saída do who do décimo ao vigésimo caractere
who | cut -c10-20

– Retira da saída do who a partir do trigésimo segundo caractere
who | cut -c32-

– Para obter a primeira e a tarceira letra de cada linha do arquivo
‘/etc/passwd’
cut -b 1,3 /etc/passwd

– Para obter a primeira letra e terceira a decima letra de cada linha
do arquivo ‘/etc/passwd’
cut -b 1,3-10 /etc/passwd

– Para captura o primeiro caracter e terceiro ao decimo caracter de cada
linha do arquivo ‘/etc/passwd’
cut -c 1,3-10 /etc/passwd

– Existem duas opções do cut que servem para especificar o(s) campos
dos registros que desejamos extrair. A opção ‘-f’ (field) pode ser
utilizada para especificar os campos (fields) que desejamos extrair. Obedece
as mesmas regras da opção ‘-c’. EX: Temos um arquivo chamado telefones e
dentro deste arquivo há o conteúdo:

Diego Rodrigo <TAB> (011) 9999-8888
Cristiane de Freitas <TAB> (012)9885-8555

Para extrair somente os nomes deste arquivo, usaríamos o seguinte comando:
cat telefones | cut -f1

O resultado seria:
Diego Rodrigo
Cristiane de Freitas

OBS: Note que não especifiquei nenhum delimitador, o delimitador padrão é
o <TAB>. Repare que entre o nome e o número do telefone tem um <TAB>

A opção ‘-d’ (delimitador) descreve para o cut qual será o separador de
campos do arquivo. Exemplo: Para indicar ao cut que o delimitador será
um espaço em branco
cat telefones | cut -f1 -d

O resultado seria:
Diego
Cristiane

Caso quiséssemos extrair somente o DDD do arquivo telefones, usaríamos a
seguinte linha:
cat telefones | cut -f2 -d ( | cut -f1 -d )

O resultado seria:
011
012

– Digamos que temos um arquivo com o seguinte conteúdo:
C – o assembler do passado
Java – ainda vai ser boa um dia
Perl – existe mais de um jeito de fazer isso
PHP – Pre processador HTML

Digite então:
cut -c1-5 arquivo.txt
A saída será:
C – o
Java
Perl
PHP –

Digite outro comando:
cut -d ‘-‘ -f 1 arquivo.txt
A saída será:
C
Java
Perl
PHP

Digite outro comando:
cut -d ‘-‘ -f 2 teste.txt
A saída será:
o assembler do passado
ainda vai ser boa um dia
existe mais de um jeito de fazer isso
Pre processador HTML
1.61 – comando cpm = compara dois arquivos de qualquer tipo (binario
ou texto). Os dois arquivos especificados serao comparados e caso
exista diferenca entre eles, é mostrado o numero da linha e byte onde
ocorreu a primeira diferenca na saida padrao(tela) e o programa
retorna o codigo de saida 1.

– Para comparar do ‘arquivo1.txt’ e do ‘arquivo4.txt’
cpm arquivo1.txt arquivo4.txt
1.62 – comando patch = atualiza arquivos texto atraves das diferenças
geradas pelo comando diff.

– Para aplicar as diferenças contidas no arquivo ‘file1.txt’ nos arquivos
originais
patch -p0 < file1.txt

– Para aplicar as diferenças contidas no arquivo ‘file2.diff’ nos arquivos
originais
patch -p0 file1.txt file2.diff
1.63 – comando cdrecord = software para gravação de CD’s

– Para exibir informações sobre o gravador de CD
cdrecord -scanbus

– Para gravar dados a partir do arquivo de imagem ‘img.iso’
cdrecord -v speed=4 dev=0,6,0 -data img.iso
– Para gravar as trilhas 1 e 2 de um CD de áudio
cdrecord -v speed=4 dev=0,6,0 -audio trilha1.wav trilha2.wav

– Para gravar as trilhas 1 a 3 sendo o CD multisessão
cdrecord -v speed=4 dev=0,6,0 -data img_do_cd.iso -audio trilha1.wav trilha2.wav trilha3.wav

– Para gravar o arquivo ‘cd1.iso’ na velocidade de 8x
cdrecord -v -speed=8 -dev=0,0,0 -eject -fs=8M cd1.iso
1.64 – comando md5sum = checa se um arquivo possui o mesmo checksum
do arquivo original
md5sum nome-da-imagem.iso
1.65 – comando fmt = faz a formatação de linhas. Ele não faz o alinhamento
do texto, faz apenas a quebra das linhas próximo ao desejado.

– Faz com que as linhas do arquivo ‘texto1.txt’ tenham em média 60
caracteres por linha
fmt -w 60 texto1.txt

– Faz o espaçamento uniforme, reduzindo espaços consecutivos entre 2
palavras para apenas um e fazendo o mesmo com as linhas, deixando apenas
uma linha em branco entre parágrafos
fmt -w 60 -u texto2.txt
1.66 – comando gpg = ferramenta para criptografia e assinatura de
arquivos

– Cria uma chave
gpg –gen-key

– Lista chaves públicas
gpg –list-keys

– Lista chaves particulares
gpg –list-secret-keys

– Carrega uma chave particular
gpg –import –allow-secret-key-import arquivo-da-chave

– Carrega uma chave pública
gpg –import arquivo-chave

– Imprimi uma chave particular em um arquivo ASCII
gpg –export-secret-key -a -o secret.key
– Imprimi uma chave pública em um arquivo ASCII
gpg –export -a -o public.key
– Apaga uma chave pública
gpg –delete-key email

– Apaga uma chave particular
gpg –delete-secret-key email

– Criptografa um arquivo
gpg -e -r email arquivo-a-criptografar

– Assina um arquivo
gpg -s -r email arquivo-a-assinar

– Criptografa e assina um arquivo
gpg -es -r email arquivo

– Descriptografa um arquivo
gpg -o arq-descriptografado -d -r email arq-criptografado

– Criptografa e envia por email um arquivo
gpg -e -a -r email-a-receber arquivo-a-ser-criptografado
1.67 – comando konqueror = browser web e file manager do KDE

Atalhos de navegação do konqueror:
atlantik:/
audiocd:/
bzip:/
bzip2:/
cgi:/
camera:/
devices:/
file:/
finger:/
fish:/
floppy:/
ftp:/
gzip:/
help:/
http:/
https:/
imap4:/
imaps:/
info:/
kdeapi:/
kmailservice:/
knewsservice:/
lan:/
mac:/
man:/
media:/
metainfo:/
nfs:/
nntp:/
perldoc:/
pop3:/
pop3s:/
print:/
pydoc:/
rlan:/
rlogin:/
rtsp:/
sftp:/
smb:/
smtp:/
smtps:/
tar:/
telnet:/
thumbnail:/
vnc:/
webdav:/
webdavs:/
zip:/
1.68 – comando ispel = corretor ortográfico

– Para iniciar o processo de correção ortográfica em pt_BR no arquivo
‘file1.txt’
ispel -d pt_br file1.txt

#######################################################################

2 – COMANDOS INFORMATIVOS

2.1 – comando arch = exibe a arquitetura de hardware do pc atual
i686 = computador pentium II e pentium III
i586 = pentium I, k5
i486 = 486
i386 = 386
2.1 – comando whoami = exibe o usuário atual, ou seja, exibe o nome
do usuário logado no computador
whoami
2.2 – comando who = exibe os usuários que estão logados no computador

– Exibe os logins e a quantidade total de usuários logados no sistema
who -q

– Exibe após o login o tempo que o usuário esta logado no sistema
who -i

– Exibe se o usuario pode receber msg’s via talk
who -w
ou
who -T

+ = o usuario pode receber msg’s via talk
– = o usuario nao pode receber msg’s via talk
? = nao e possivel determinar em que terminal o usuario esta conectado
2.3 – comando whois = exibe informações sobre usuarios e dominios remotos

whois 200.251.142.9@nic.br
whois 200.251.148.x@internic.com
whois -h registro.br dominio_a_ser_pesquisado

whois <IP>@registro.br
2.4 – comando man = exibe páginas de manual dos comandos do sistema

– Para exibir a página de manual do comando ‘ls’
man ls

– Para exibir a página de manual do comando ‘rm’
man rm

– Para exibir a página de manual do comando ‘find’
man find

– Para converter o conteúdo da man-page do comando ‘hdparm’ para um
arquivo *.ps, no caso ‘hdparm.ps’
man hdparm -t > hdparm.ps
– Para converter o arquivo ‘hdparm.ps’ para ‘hdparm.pdf’
ps2pdf hdparm.ps hdparm.pdf
– Para copiar no arquivo ‘hdparm.txt’ uma cópia da man-page do comando
escolhido ‘hdparm’
man hdparm | col -b > hdparm.txt
– Para converter o conteúdo da man-page do comando ‘fdisk’ para um
arquivo no formato TXT, no caso, ‘fdisk.txt’
man fdisk | colcrt > fdisk.txt
– Para copiar páginas de manual para um arquivo no formato TXT
info man > man.txt
ou
man ls | groff -Tlatin1 > arquivo
2.5 – comando xman = exibe paginas de manual no modo gráfico
xman
2.6 – comando cal = exibe um calendário

– Exibe o calendário do mês atual
cal

– Exibe o calendário do ano de 2005
cal 2005

– Exibe um calendário anual, ou seja, de todos os meses:
cal -y

– Exibe o calendário do mês de janeiro de 2001
cal 1 2001

– Exibe o calendário do mes de maio de 2001
cal 5 2001

– Exibe o calendário do mês atual com a segunda-feira como sendo o
primeiro dia da semana
cal -m

– Exibe o calendário do mês passado, atual e do próximo mês:
cal -3

– Exibe o calendário completo do ano de 2002
cal 2002 ou cal -y

– Exibe o calendário do mês de dezembro, porém do dia 335 até o 365
cal -j 12 2002

– Exibe quantos são os dias úteis (basta retirar o sábado e domingo)
de um determinado mes
cal $mes $ano | sed -n -e ‘s/ / # /g’ -e ‘s/ / #/g’ -e ‘s/^ /#/’ -e ‘3,$p’ | cut -d ‘ ‘ -f 2-6 | tr ‘#’ ‘ ‘ | wc -w

– Excluiu as duas primeiras linhas (cabeçalho) e também os 3 primeiros e
os 3 últimos caracteres de cada linha (domingo e sábado)
cal 12 2001 | sed ‘1,2d;s/^…//;s/\(.*\)…$/\1/’ | wc -w

mais visual:

# cal 12 2001
dezembro 2001
Do Se Te Qu Qu Se Sá
1
2 3 4 5 6 7 8
9 10 11 12 13 14 15
16 17 18 19 20 21 22
23 24 25 26 27 28 29
30 31

# cal 12 2001 | sed ‘1,2d;s/^…//;s/\(.*\)…$/\1/’
3 4 5 6 7
10 11 12 13 14
17 18 19 20 21
24 25 26 27 28
31
2.7 – comando date = exibe a data e a hora atual

– Exibe a data atual
date

– Para ajustar a hora do sistema
date 051909522004

onde o 05 corresponde ao mês, o 19 ao dia, o 09 as horas, o 52 aos minutos,
o 20 às duas primeiras casas do ano e o 04 às duas segundas casas do ano,
logo estou selecionando para o meu sistema a data 19/05/2004 e a hora
09h52min.

– Para salvar a data e a hora na CMOS, digite:
clock -w

– Para obter o dia da semana por extenso (com 3 letras)
edersg@jordan:~$ date +%a
Sun

– Para obter o dia da semana por extenso (completo)
edersg@jordan:~$ date +%A
Sunday

– Para o mês atual (com 3 letras)
jordan:~# date +%b
Aug

– Para o mês atual (com 3 letras)
jordan:~# date +%h
Aug

– Para obter o mês atual (completo)
jordan:~# date +%B
August

– Para obter o locale com data(dia, mes ano) e hora, minuto e segundo
jordan:~# date +%c
Sun Aug 7 09:38:05 2005

– Para exibir o dia atual (de 01 a 31)
jordan:~# date +%d
07

– Para exibir o dia atual (de 1 a 31)
jordan:~# date +%e
7

– Para obter a data no formato (mm/dd/yy)
jordan:~# date +%D
08/07/05

– Para obter a data no formato (yyyy-mm-dd)
jordan:~# date +%F
– Para obter o ano atual com 2 dígidos (yy)
jordan:~# date +%g
05

– Para obter o ano atual com 4 dígidos (yy)
jordan:~# date +%G
2005

– Para obter a hora atual (00 a 23)
jordan:~# date +%H
09

– Para obter a hora atual (01 a 12)
jordan:~# date +%I
09

– Para obter o dia do ano atual (de 001 até 366)
jordan:~# date +%j
219

– Para obter a hora atual (0 a 23)
jordan:~# date +%k
9

– Para obter a hora atual (1 a 12)
jordan:~# date +%l
9

– Para o mês atual (com 2 dígitos)
jordan:~# date +%m
08

– Para obter o minuto da hora atual
jordan:~# date +%M
50

– Para obter o locale em letras maísculas: AM ou PM
jordan:~# date +%p
AM

– Para obter o locale em letras minúsculas: am ou pm
jordan:~# date +%P
am

– Para obter a hora (formato 12 em hh:mm:ss) e o locale em maísculo (AM ou PM)
jordan:~# date +%r
09:52:17 AM

– Para obter a hora (formato 24 em hh:mm)
jordan:~# date +%R
09:53

– Para obter os segundos da hora atual no formato “00:00:00 1970-01-01 UTC”
jordan:~# date +%s
1123419275

– Para obter os segundos (00 a 60) da hora atual
jordan:~# date +%S
45

– Para obter a hora (atual) no formato 24 horas (hh:mm:ss)
jordan:~# date +%T
09:57:38

– Para obter o dia da semana (1 representa segunda, 2 representa terça,
3 representa quarta, 4 representa quinta, 5 representa sexta,
6 representa sábado e 7 representa domingo)
jordan:~# date +%u
7

– Para obter o número da semana desde o inicio do ano (00 a 53)
sendo que domingo é considerado o primeiro dia da semana
jordan:~# date +%U
32

– Para obter o número da semana desde o inicio do ano (01 a 53)
sendo que segunda é considerado o primeiro dia da semana
jordan:~# date +%V
31

– Para obter o dia da semana (de 0 a 6) sendo que domingo é representado
como 0, segunda como 1, terça como 2, quarta como 3, quinta como 4,
sexta como 5 e sábado como 6
jordan:~# date +%w
0

– Para obter o número da semana do ano sendo segunda-feira o primeiro dia
da semana (00 a 53)
jordan:~# date +%W
31

– Para obter o locale com a data no formato “mm/dd/yy”
jordan:~# date +%x
08/07/05

– Para obter o locale com a hora no formato “hh:mm:ss”
jordan:~# date +%X
10:10:37

– Para obter os últimos dois dígidos do ano atual
jordan:~# date +%y
05

– Para obter o ano atual (desde 1970)
jordan:~# date +%Y
2005

– Para obter o timezone (de acordo com a RFC-2822)
jordan:~# date +%z
-0300

– Para obter o timezone no formato EDT
jordan:~# date +%Z
BRT

– Exibe a data de ontem com a formatação do sistema. A opção ‘–date’ pode
ser substituída por ‘-d’ e ‘yesterday’ pode ser substituído por ‘today’,
‘tomorrow’ dentre outras opções)
date –date yesterday

– Exibe o ano corrente
date +%Y

– Exibe a data corrente na formatação dd/mm/aaaa)
date +%d/%m/%Y

– Exibe a data do dia anterior na formatação dd/mm/aaaa)
date -d yesterday +%d/%m/%Y

– Exibe a data do dia de ontem
date –date ‘1 day ago’

– Exibe a data do dia de antes de ontem
date –date ´2 days ago´

– Exibe a data depois de amanhã
date –date ‘2 days’

– Exibe a data do dia três meses e um dia atrás
date –date ´3 months 1 day´

– Exibe a data daqui a um ano e três semanas
date –date ‘1 year 3 weeks’

– Exibe dia no ano do natal no ano atual
date –date´25 Dec´ + %j

– Exibe a data 5 dias atras
date –date ‘5 days ago’

– Exibe a data 2 meses atras:
date –date ‘2 months ago’

– Exibe a data 3 dias a frente
date –date ‘3 days’

– Exibe a data de 2 meses e 15 dias
date –date ‘2 months 15 days’

– Exibe a data atual em um formato, incluindo o nome da lua cheia e o
dia do mês
date ´+%B%d´

Mas isto pode não ser o que você quer pois para os primeiros nove dias do
mês, o ´%d´ se expande para um campo de dois dígitos completados com zero
´date -d 1-may´+%B%d´´

exibirá: ´May 01´

– Para exibir a mesma data, mas, sem o zero inicial para dias do mês de um
dígito, você pode utilizar o modificador não padrão ´-´ para suprimi-lo.
date -d 1-may´+%B %-d

resumo
——
day dia
week semana
month mês
year ano
ago atrás (passados)
2.8 – comando finger = exibe informações sobre um usuário

– Exibe todos os usuários logados no sistema
finger

– Exibe informações de todos os usuários logados no sistema
finger -l

– Exibe informações do usuário ‘ederjordam’ que está cadastrado
no sistema
finger ederjordam
2.9 – comando netstat = exibe tabelas de roteamento, conexões de rede,
estatísticas de interface, informacoes sobre portas TCP e UDP abertas e
conexões mascaradas. Exibe informações sobre as portas TCP e UDP abertas
que estao em uso. Este comando sem argumentos mostratrá uma lista de
portas abertas, as que estão ocupadas ou ouvindo o tipo de conexao, host
etc.

– Exibe o endereçamento IP em suas respectivas portas
netstat -n

– Exibe os detalhes das conexoes atuais
netstat

– Exibe informacoes sobre a tabela de roteamento
netstat -r

– Exibe uma tabela de todas as interfaces de rede
netstat -i

– Verificar informações sobre a rede
netstat -a

– Exibe todas as portas TCP abertas, aguardando pedido de conexão
netstat -at

– Exibe todas as portas UDP abertas, aguardando pedido de conexão
netstat -au

– Visualiza a tabela de rota dos IP inválidos em uma rede
netstat -rn

– Monitora as conexões
netstat -m

– Verifica se já não esta no ar a porta 23 do serviço/protocolo telnet
netstat -nta | grep :23

– Indentifica o processo
netstat -anp

– Exibe informações selecionadas a cada segundo
netstat -c

– Exibe as portas abertas no PC atual
netstat -pan –inet

– Exibe uma lista de todas as sessões mascaradas também pode ser vista.
O suporte a mascaramento é usado para esconder máquinas em endereços de
rede não oficiais do resto do mundo
netstat -M

– Exibe estatísticas sobre o sub-sistema de rede do kernel linux que são
lidas a partir de ‘/proc/net/snmp’
netstat -s

– Faz uma busca por serviços abertos (programas que têm 0.0.0.0 na coluna
‘Local Address’) que são visíveis para toda à Internet
netstat -pan –inet

– Verifica se a porta 25 (padrao SMTP) está funcionando
netstat -tan | grep 25

– Verifica se a porta 6000 (padrao X11 está funcionando)
netstat -tan | grep 6000

– Para descobrir o endereço IP do gateway padrão
netstat -r

– Lista todas as portas que estão no estado LISTEN
netstat -an –inet

– Para encontrar o processo que está mantendo uma porta aberta no seu
computador (netstat -a para ver isso), utilize o seguinte comando
netstat -nap –inet | grep <porta que voce quer>

– Para descobrir qual programa esta abrindo uma determinada porta
netstat -na (exibe todas as conexões e portas abertas)

então digite:
fuser -n PROTOCOLO PORTA (exibe o pid do processo respondendo pela porta)
2.10 – comando mail = envia/visuliza emails no terminal

Sintaxe:
mail [-s subject] [-c cc-addr] [-b bcc-addr] to-addr

-s subject : especifica a linha de assunto das mensagens enviadas

-c cc-addr : especifica uma lista de endereços que devem receber
copias das mensagens

-b bcc-addr : especifica uma lista de endereços que devem receber
cópias escondidas cegas das mensagens

to-addr : endereço de email do remetente

– Para visualizar os emails que estão no arquivo inbox
mail

– Le a correspondencia da caixa de entrada do usuário ‘jordam’
mail -f /var/spool/mail/jordam

– Le a correspondencia da caixa de entrada do usuario ‘user1’
mail -f /var/spool/mail/user1

– Comando básico para se enviar um email via texto. Deve-se digitar
o ‘subjetc’, o ‘corpo da mensagem’ e apertando ‘CTRL + D’ será
pedido o ‘cc’
mail user@dominio.com
– Envia um email para o usuario ‘user@dominio.com’ com o arquivo
‘file1.txt’ anexado
mail -s assunto-do-email usuario@dominio.com < file1.txt

– Para enviar um email com uma mensagem pesonalizada:
echo “Opa Eder
Tudo bem contigo?
Gostaria que voce me enviasse a apostila. Obrigado
Pedro” | mail -s ‘assunto-do-email’ usuario@dominio.com.br
– Envia um email com o arquivo ‘bem-vindo.htm’ em anexo
cat bem-vindo.htm | mail $1 -s ‘Bem Vindo’ user@dominio.com
– Envia um email a todos os usuarios do sistema:
cat /etc/passwd | cut -d: -f 1 | while read x ; do echo “Desliguem seus computadores no final do expediente!” |mail ${x} -s “Aviso do administrador.”; done

– Se voce quiser colocar um texto no corpo da mensagem:
cat texto.txt | mail usuario@dominio.com
– Se quiser enviar um arquivo anexo:
cat arquivo_anexo.zip | uuencode arquivo_anexo.zip | mail usuario@dominio.com
– Para enviar um email para vários destinatários:
mail -s “subject” -c “mail CC” -b “mail BCC” mail1 mail2 … mailn < arquivo-a-ser-enviado.txt
– Para enviar um único email para vários usuários
1) Crie um arquivo com todos emails das pessoas que irãoreceber o email.
Um endereço de email por linha. Escolha um nome de arquivo: “lista.txt”

2) Tenha em maos tbm o arquivo com o body do email ex. “corpo.txt”

3) Para enviar, digite:
mail -s assunto ‘cat lista.txt’ < corpo.txt
2.11 – comando uptime = exibe o tempo que seu sistema está ativo (rodando)

– Para visualizar o carregamento de sua máquina. Se estiver acima de 2.0,
voce está com muito processamento (e talvez pouca memória).
uptime

12:45pm up 2 days, 20:21, 15 users, load average: 0.37, 0.33, 0.17
^^^^ ^^^^ ^^^^

se sua máquina estiver carregada, veja o processo voraz que está comendo
mais memória (“ps auxwww | sed ‘1d’ | sort +5 -nr”). Normalmente alguns
processos como netscape, gnome, etc, começam a crescer indefinidadmente
ocupando toda a memória e todo o tempo de cpu.
2.12 – comando last = exibe o histórico de logins e logouts dos usuários
baseado no conteúdo do arquivo ‘/var/log/wtmp’. São exibidos os seguintes
campos na listagem: nome do usuário, terminal onde ocorreu a conexão e
desconexão, hostname, data do login/logout, hora do login/down e o tempo
em horas:minutos que esteve conectado ao sistema.

– Exibe os últimos registros dos 15 últimos logins
last | head -15

-Exibe os últimos 5 usuários que acessaram o computador
last -5

– Exibe o nome de host a ser apresentado na última coluna
last -a

– Usa o DNS para resolver o IP de sistemas remotos para nomes DNS,
logins remotos, exibem todos os enderecos IP como nomes de host
last -d

– Exibe as entradas de desligamento do sistema e alterações do
nível de execução do sistema
last -x

– Exibe somente as atividades referentes ao usuario user1
last user1

– Exibe todas as atividades do tty1
last tty1

– Exibe os últimos 4 acessos que o usuário ‘ederjordam’ efetuou no sistema
last -R4 ederjordam
2.14 – comando dmesg = exibe o buffer de anel do kernel, exibe as mensagens
de inicializacao do sistema.

– Exibe as mensagens da inicialização do sistema
dmesg

– Limpa o buffer após ser exibido
dmesg -c

– Procura o modelo do drive de CD-ROM do computador
dmesg | grep -i cd-rom
2.15 – comando setterm = altera as propriedades de um terminal

– Altera a cor de fundo (opção -background) do terminal para branco
e suas letras (opção -foreground) para a cor vermelha
setterm -store -background white -foreground red

– Altera a cor de fundo (opção -background) do terminal para branco
e suas letras (opção -foreground) para a cor azul
setterm -store -background white -foreground blue
2.16 – comando users = informa os usuários conectados atualmente no sistema.
Os nomes de usuários são obtidos no arquivo ‘/var/log/wtmp’
users
2.17 – comando id = exibe os UIDs e GIDs efetivos e reais

– Exibe os grupos em que o usuario atual esta cadastrado
id

– Exibe o id do usuário ‘jordam’
id jordam

– Exibe somente o ID do grupo ‘programadores’
id -g programadores
2.18 – comando w = exibe quem está logado no sistema. Além de determinar
o que está sendo feito, o tempo de uso do processador, etc:
w
2.19 – comando whereis = localiza o arquivo executável, fonte e páginas de
manual de um determinado comando do sistema

– Para localizar o arquivo executável do comando ‘ls’
whereis ls

– Realiza uma pesquisa apenas nos arquivos binarios
whereis -b cat

– Realiza uma pesquisa apenas nas páginas de manual
whereis -m cat

– Realiza uma pesquisa apenas o codigo fonte
whereis -s cat
2.20 – comando which = exibe o caminho completo de um programa, buscando
por executáveis nos PATH’s exportados

– Exibe o caminho do programa cat
which cat

– Exibe TODOS os caminhos do programa cat
which -a cat
2.21 – comando env = exibe as variáveis que o seu shell possui
env
2.22 – comando lynx = navegador web (browser) que funciona no terminal

– Exibe informações do servidor web do site ‘http://www.dominio.com.br&#8217;
lynx -dump -head http://www.dominio.com.br

– Converte o arquivo ‘file1.html’ para um arquivo no formato TXT, ou seja,
texto puro
lynx -dump -nolist file1.html
2.23 – comando xscreensaver = manipula as proteções de tela no console
2.24 – comando ldd = lista as depedências de bibliotecas compartilhadas
necessárias por cada programa ou por outras bibliotecas.

– Exibe uma lista de bibliotecas que o programa Eterm depende para ser
executado no computador
ldd /usr/bin/Eterm

– Exibe uma lista de bibliotecas que o programa Eterm depende para ser
executado no computador
ldd `which /usr/bin/Eterm`

– Exibe funções ausentes
ldd -d programa1

– Exibe objetos de dados e funções
ldd -r programa1

– Exibe as bibliotecas que o software amule necessita mas que não estão
instaladas no sistema
ldd /usr/bin/amule | grep not

libwx_gtk2_xrc-2.6.so.0 => not found
libwx_gtk2_qa-2.6.so.0 => not found
libwx_gtk2_html-2.6.so.0 => not found
libwx_gtk2_adv-2.6.so.0 => not found
libwx_gtk2_core-2.6.so.0 => not found
libwx_base_xml-2.6.so.0 => not found
libwx_base_net-2.6.so.0 => not found
libwx_base-2.6.so.0 => not found
2.25 – comando lspci = lista todos os dispositivos PCI do pc
lspci
lspci -vn | more
lspci -vv

00:00.0 Host bridge: Silicon Integrated Systems [SiS] 530 Host (rev 03)
00:00.1 IDE interface: Silicon Integrated Systems [SiS] 5513 [IDE] (rev d0)
00:01.0 ISA bridge: Silicon Integrated Systems [SiS] 85C503/5513 (rev b1)
00:01.1 Class ff00: Silicon Integrated Systems [SiS] ACPI
00:02.0 PCI bridge: Silicon Integrated Systems [SiS] 5591/5592 AGP
00:09.0 VGA compatible controller: Trident Microsystems TGUI 9660/968x/968x (rev d3)
00:0c.0 Multimedia audio controller: C-Media Electronics Inc CM8738 (rev 10)
00:0c.1 Communication controller: C-Media Electronics Inc CM8738 (rev 20)
00:0d.0 Ethernet controller: Silicon Integrated Systems [SiS] SiS900 10/100 Ethernet (rev 02)
01:00.0 VGA compatible controller: Silicon Integrated Systems [SiS] 6306 3D-AGP (rev a3)

* Esta é a descrição do chipset principal da placa-mãe SIS 530:
00:00.0 Host bridge: Silicon Integrated Systems [SiS] 530 Host (rev 03)

* Interface IDE SIS 513, chipset que controla a interface usada pelos CDs
e HDs por exemplo:
00:00.1 IDE interface: Silicon Integrated Systems [SiS] 5513 [IDE] (rev d0)

* Barramento ISA:
00:01.0 ISA bridge: Silicon Integrated Systems [SiS] 85C503/5513 (rev b1)

* ACPI é usado para controlar o consumo de energia de micros modernos:
00:01.1 Class ff00: Silicon Integrated Systems [SiS] ACPI

* A palavra mágica “AGP” no final da uma dica:
00:02.0 PCI bridge: Silicon Integrated Systems [SiS] 5591/5592 AGP

* O lspci encontrou minha placa de vídeo Trident, posso usar dois monitores ao
mesmo tempo:
00:09.0 VGA compatible controller: Trident Microsystems TGUI 9660/968x/968x (rev d3)

* Olha meu controlador de áudio ai. Aquele CM8738 no final é importante, é
o chipset:
00:0c.0 Multimedia audio controller: C-Media Electronics Inc CM8738 (rev 10)

* C-Media de novo, mas tem uma função diferente da anterior:
00:0c.1 Communication controller: C-Media Electronics Inc CM8738 (rev 20)

* Controlador de Rede, SIS900 é o chip:
00:0d.0 Ethernet controller: Silicon Integrated Systems [SiS] SiS900 10/100 Ethernet (rev 02)

* OK, meu controlador VGA, 3d-AGP ruim que dói, mas pelo menos o nome rima:
01:00.0 VGA compatible controller: Silicon Integrated Systems [SiS] 6306 3D-AGP (rev a3)
2.26 – comando head = exibe as primeiras linhas de um arquivo

– Exibe as primeiras 8 linhas do arquivo ‘file1.txt’. Caso nao for especi-
ficado, o comando head exibe as 10 primeiras linhas do arquivo
head -n 8 file1.txt

– Exibe as primeiras 3 linhas do arquivo file2.txt. Caso nao for especificado,
o comando head exibe as 10 primeiras linhas do arquivo
head -n 3 file2.txt

– Gera uma senha de 6 caracteres
head -c 6 /dev/random | mimencode

– Gera uma senha de 8 caracteres
head -c 8 /dev/random | mimencode

– Cria senhas randomicas
head -c 6 /dev/urandom | uuencode – | cat -n | grep 2 | cut -f2 | cut -c 2,3,4,5,6,7,8,9

– Exibe a enésima linha de todos os arquivos de um diretório
head -n N * | tail -n 1

– Exibe a enesima linha de todos os arquivos de um diretório
head -n arquivo | tail -1

– Imprime as 30 linhas iniciais do arquivo ‘file1.txt’
head -n 30 file1.txt > /dev/lp0
2.27 – comando fuser = permite identificar e fechar os processos que
estão utilizando arquivos e soquetes do sistema.

– Exibe quem está acessando o ponto de montagem ‘/dev/cdrom’
fuser -u /mnt/cdrom

– Exibe qual programa esta rodando na porta 23 TCP
fuser -v -n tcp 23

– Exibe qual programa esta rodando na porta 23 UDP
fuser -v -n udp 23

– Exibe informacoes sobre a porta 1353
fuser -v 1353/tcp

– Exibe qual programa esta usando o dispositivo ‘/dev/dsp’
fuser -v /dev/dsp

– Exibe qual programa esta utilizando a porta 631
lsof | grep 631

– Pergunta antes de destruir o processo 1121
fuser -i 1121
2.28 – comando time = mede o tempo que um programa ou comando leva para
ser executado.

– Mede o tempo em que o programa Star Office demora para ser carregado
time /usr/bin/soffice

– Mede o tempo em que o programa ls é executado
time ls

– Mede o tempo em que o programa find é executado
time find / -name *.txt – print
2.29 – comando fdisk = possui ferramentas para a manipulação de tabelas
de particao.

– Exibe a tabela de partições para os seguintes dispositivos /dev/hd[a-d],
/dev/sd[a-h] e /dev/ed[a-d]
fdisk -l

– Exibe o número da versão do fdisk
fdisk -v
2.30 – comando ksyms = exibe informações sobre simbolos do kernel exportados

– Exibe todos os simbolos, incluindo os do kernel atual
ksyms -a

– Exibe informacoes de modulo, incluindo endereco e tamanho do módulo
ksyms -m
2.31 – comando logname = exibe o username do usuário
logname
2.32 – comando lsmod = exibe os módulos atualmente carregados no kernel
lsmod
2.33 – comando mailto = envia um email para um ou mais destinatários
mailto -a character-set -c address -s subject recipient

-a character-set : especifica um conjunto de caracteres alternativo
como o ISO-8859-8. O padrão é US-ASCII

-c address : especifica uma lista de enderecos que devem receber
copias das mensagens

-s subject : especifica o assunto da mensagem. Se o assunto tiver mais
de uma palavra, coloque-o entre aspas.

recipient : outros enderecos de emails para que se devem enviar a mensagem

Para concluir a composicao de uma mensagem, use CTRL + D o digite um “.”
sozinho em uma linha em branco.
2.34 – comando pidof = localiza e exibe os ID’s de processos de um ou
mais programas

– Localiza o ID referente a execucao do programa xmms
pidof -s xmms

– Exibe os PIDs que estejam execudando sobre o xmms
pidof -x xmms

– Obtem o PID do numero do processo digitado
pidof NOME_DO_PROCESSO
EX:
pidof ntop
2.35 – comando quota = exibe informações de cota de utilização de disco
de um usuario. Sintaxe:

quota -F format-name -guv | q
quota -F format-name -uv | q user
quota -F format-name -gv | q group

– Exibe a cota dos grupos a que o usuário pertence
quota -g

– Exibe informaceos de cota do usuário
quota -u

– Exibe cotas para sistemas de arquivos onde nao está alocado armazenamento
quota -v
2.36 – comando quotacheck = percorre um sistema de arquivo para ver a
utilização de disco por um usuário ou grupo e produz os resultados nos
arquivos ‘quota.user’ e ‘quota.group’. Sintaxe:
quotacheck -guv -F quota-format -a | filesystem

– Verifica todos os sistemas de arquivos no arquivo ‘/etc/fstab’
quotacheck -a

– Verifica os arquivos e diretórios ussados por uma ID de grupo em particular
quotacheck -g

– Verifica os arquivos e diretórios usados por uma ID de usuário em particular
quotacheck -u

– Exibe cotas para sistemas de arquivos onde nao esta alocado armazenamento
quotacheck -v
2.37 – comando quotaoff = desativa cotas de utilizacao de disco de um
ou mais sistemas de arquivo.

sintaxe: quotaoff -g -u -a | filesystem

quotaoff -a = desativa cotas de todos os sistemas de arquivos
em /etc/fstab

quotaoff -g = desativa as cotas de grupo dos sistemas de arquivo
especificados

quotaoff -u = desativa as cotas de usuario dos sistemas de arquivo
especificados
2.38 – comando quotaon = ativa as contas de utilização de disco de um
ou mais sistemas de arquivos. Sintaxe:
quotaon -g -u -a | filesystem

– Ativa as cotas de todos os sistemas de arquivo em ‘/etc/fstab’
quotaon -a

– Ativa as cotas de grupo dos sistemas de arquivo especificados
quotaon -g

– Ativa as cotas de usuário dos sistemas de arquivo especificados
quotaon -u
2.39 – comando mesg = permite ou nao o recebimentos de requisições de talk
de outros usuários. Sintaxe:
mesg [_y/n_]

Onde: _y_ permite que você receba “talks” de outros usuários.

Digite `mesg’ para saber se você pode ou não receber “talks” de outros
usuários. Caso a resposta seja “n” você poderá enviar um talk para
alguém mas o seu sistema se recusará em receber talks de outras
pessoas.

É interessante colocar o comando `mesg y’ em seu arquivo de inicialização
.bash_profile para permitir o recebimento de “talks” toda vez que entrar
no sistema.
2.40 – comando groups = exibe os grupos em que o usuário atual está
cadatrado no arquivo ‘/etc/group’
groups
2.41 – comando dumpe2fs = exibe informações sobre uma partição

– Exibe informações sobre a partição ‘/dev/hda1’
dumpe2fs /dev/hda1

– Exibe apenas os blocos defeituosos da partição ‘/dev/hda1’
dumpe2fs -b /dev/hda1
2.42 – comando tload = exibe de forma gráfica a carga do sistema
tload

– Exibe uma escala vertical
tload -s 1 à 10

– Especifica o intervalo de atualizações em 4 segundos
tload -d 4
2.43 – comando ldconfig = cria as ligações e cache para os arquivos de
bibliotecas mais recentes.

– Carrega as novas bibliotecas
ldconfig

– Exibe as bibliotecas de sistema instaladas atualmente no seu sistema.
Você tambem pode visualizar o arquivo ‘/etc/ld.so.conf’ que contem os
diretórios onde se encontram os arquivos de bibliotecas
ldconfig -v | more
2.44 – comando set = visualiza as variáveis de ambiente disponíveis para o
usuario atual.
set

– Visualiza o conteudo da variavel $PATH
echo $PATH

– Exporta uma variável ‘$LINGUAGEM’ com o valor ‘portugues’
export LINGUAGEM=portugues

– Para vistualizar a variavel “$LINGUAGEM”
echo $LINGUAGEM

– Exporta a variável chamada ‘$http_proxy’ com o valor ‘10.0.1.5:8008’
export http_proxy=10.0.1.5:8008
2.45 – comando locale = exibe as variáveis de localização do sistema e seus
respectivos valores. As principais variáveis de localização são:

LANG = especifica o idioma e o país. A lingua portuguesa do brasil
é especificada com o valor “pt_BR” e a lingua inglesa com o valor “C”.
Para especificar mais de um idioma, use “:”. EX:
export LANG=pt_BR
export LANG=pt_BR:C

LC_MESSAGES = especifica o idioma que serao mostradas as mensagens dos
programas. O formato é o mesmo que a variável de localizacao LANG.
export LC_MESSAGES=pt_BR
export LC_MESSAGES=pt_BR:C

LC_ALL = especifica todas a variaveis de localizacao de uma só vez.
Seu formato é o mesmo da variável de localização ‘LANG’.

Nota: Os arquivos de localização estão armazenados no caminho:
/usr/share/locale/[Idioma]/LC_MESSAGES

Nota2: As variáveis de ambiente podem ser especificadas no arquivo
/etc/environment

Desta forma as variáveis serão carregadas toda a vez que seu sistema for
iniciado. Você também pode especificar as variáveis de localização em seu
arquivos de inicialização
.bash_profile
.bashrc
ou
.profile

assim toda vez que entrar no sistema, as variáveis de localização personali-
zadas serão carregadas.
2.46 – comando lsof = exibe todos os arquivos abertos. Ótimo para prevenir
algum tipo de ataque. Este programa vai dizer a você se alguma coisa
esta rodando um sniffer e ele vai logar tudo sobre o invasor em seus
arquivos de LOG. Este comando (list open files) exibe informações de todos
os arquivos abertos do sistema. O comando lsof é utilizado para mostrar os
arquivos que estão abertos no sistema. Sozinho o comando lsof mostra todos
os arquivos abertos, mas o mesmo possui muitos parâmetros.

– Para exibir uma lista de todos os arquivos abertos (inclusive arquivos
de rede como sockets, arquivos nfs etc
lsof | less

– Para exibir apenas o equivalente do comando ‘sockstat’
lsof -i

COMMAND PID USER FD TYPE DEVICE SIZE NODE NAME
sshd 1876 root 4u IPv6 14621287 TCP maq8:ssh->192.168.1.149:1138 (ESTABLISHED)
sshd 2555 user 4u IPv6 14621287 TCP maq8:ssh->192.168.1.149:1138 (ESTABLISHED)
portmap 3582 bin 3u IPv4 2926 UDP *:sunrpc
portmap 3582 bin 4u IPv4 2927 TCP *:sunrpc (LISTEN)
vi 3878 userY 3u IPv4 12867647 TCP maq8:45119->starway:6000 (ESTABLISHED)
kadmind 4285 root 6u IPv4 4263 TCP *:kerberos-adm (LISTEN)
kadmind 4285 root 9u IPv4 4264 UDP *:464
krb5kdc 4310 root 6u IPv4 4309 UDP mapi8.distro.conectiva:kerberos
krb5kdc 4310 root 9u IPv4 4310 UDP mapi8.distro.conectiva:kerberos-iv
krb5kdc 4310 root 10u IPv4 4311 UDP mapi8.gigabit:kerberos
krb5kdc 4310 root 11u IPv4 4312 UDP mapi8.gigabit:kerberos-iv
xinetd 4447 root 5u IPv4 4772 UDP *:amanda
xinetd 4447 root 6u IPv4 4773 TCP *:pop-3 (LISTEN)
xinetd 4447 root 8u IPv4 4774 TCP localhost.localdomain:32769 (LISTEN)

– Para visualizar os arquvos já removidos que continuam abertos
e sendo utilizados
lsof | grep DEL

gconfd-2 15606 user mem DEL 254,2 864953 /usr/lib/libgobject-2.0.so.0.400.0
gconfd-2 15606 user mem DEL 254,2 864955 /usr/lib/libgthread-2.0.so.0.400.0
gconfd-2 15606 user mem DEL 254,2 864951 /usr/lib/libgmodule-2.0.so.0.400.0
gconfd-2 15606 user mem DEL 254,2 864949 /usr/lib/libglib-2.0.so.0.400.0

Nesse caso o processo ‘gconfd-2’ continua usando bilbiotecas antigas que
já foram removidas do sistema (porque foram atualizadas para versões mais
novas). Apesar dos arquivos não aparecerem com o comando ‘ls’, eles ainda
estão no sistema de arquivos até que o processo os libere. Quando o gconfd-2
foi reiniciado ele usará as novas bibliotecas e o sistema então removerá
as antigas definitivamente. Esse comportamento permite que um sistema seja
atualizado completamente mesmo com diversos programas sendo excutados.

– Verifica que programa está associado às portas sob suspeição
lsof | less

– Verifica se a porta 6000 que pertence ao X Windows está aberta
lsof | less | grep 6000

– É possível obter uma lista de usuários e programas que estejam utilizando
um determinado arquivo (e possivelmente bloqueando-o)
lsof /var/log/secure

– Lista os programas que estão utilizando as portas TCP ou UDP do seu
computador
lsof -i

– Os arquivos antigos continuarão ocupando espaço em seu disco
lsof | grep \;

para ter uma idéia de quantos arquivos antigos ainda estão abertos por
processos e não podem ser deletados.

– Para exibir os arquivos abertos identificado pelo nome de usuário,
representado aqui pelo identificador usuário:
lsof -u usuário

– Para exibir os arquivos abertos por um determinado grupo, identificado
aqui numericamente pela variável n:
lsof -g n

– Para exibir os arquivos abertos por um determinado número de processo
(PID), representado aqui pela variável n:
lsof -p n

– Para exibir os arquivos que cada usuário logado está utilizando
atualmente:
lsof -u<login>

– Alguem utiliza o serv.Email Postfix + amavis + uvscan? Pois eu estou
tentando configurar o Amavis + o uvscan para funcionar com o meu postfix
e não consigo. Quando eu tento enviar uma mensagem o cliente de correio
me retorna porta 25 indisponível, verifiquei as portas abertas e constatei
que a porta 25 está fechada. Se alguem tiver alguma informação e/ou
configuração para me mandar eu agradeço.

Bem, veja quem está rodando na sua porta 25 com o comando:
lsof -i tcp:25

A seguir, veja em qual porta o Postfix está rodando atrarvés do comando:
lsof -i tcp:smtp

– Tenho um servidor com mysql, e consigo conectar a todas as databases se
estiver servidor, porem´m quando tento conectar através de um cliente
gráfico em outra maquina não consigo conectar, ponho o ip da maquina, o nome
da maquina e nada.

O mysql costuma fazer um arquivo <nomedamaquina>.err no mesmo diretorio onde
ficam os databases, mas varia de acordo com a distro e vc não falou qual é.
Este arquivo costuma ter algumas informações relevantes. Também tem um my.cnf
que costuma ter as configurações do mysql, mas vc também não postou ele aqui.
Tenta mostrar a saída do comando:
lsof -i:3306

Pra gente ver se mostra alguma coisa. Eu desconfio que o mysql não abriu a
conexão tcp/ip, só está ouvindo no soquete. Isto pra não falar se tem algum
iptables configurado, etc.
– Uma outra alternativa para descobrir o processo rodando em determinada
porta é usando o comando lsof
lsof -i tcp:25

COMMAND PID USER FD TYPE DEVICE SIZE NODE NAME
sendmail 816 root 4u IPv4 1131 TCP *:smtp (LISTEN)
sendmail 4799 root 4u IPv4 37493002 TCP acme.com:48087->200.221.4.73:smtpYN_SENT)
sendmail 5897 root 4u IPv4 37504728 TCP acme.com:48093->mc4.bay6.hotmail.com:smtpSTABLISHED)
sendmail 5897 root 6u IPv4 37504728 TCP acme.com:48093->mc4.bay6.hotmail.com:smtpSTABLISHED)
sendmail 5976 root 4u IPv4 37492525 TCP acme.com:48080->mc11.bay6.hotmail.com:smtpYN_SENT)
sendmail 6028 root 6u IPv4 37493546 TCP acme.com:48090->200-207-128-166.speedyterra.com.br:smtpYN_SENT)

Neste caso, foram listadas todas as conexões do sendmail, que usa a porta de
número 25 do protocolo tcp, juntamente com a identificação dos processos,
entre outras informações.

– A glibc (GNU C Library) é a biblioteca básica usada por praticamente
todos os programas em sistemas GNU/Linux. Riley Hassell da eEye Digital
Security publicou[2] um anúncio sobre uma vulnerabilidade[3][4] na
biblioteca XDR usada por diversos sistemas, inclusive pela glibc. A
função xdrmem_getbytes() (e outras funções da mesma família xdrmem_*)
possui uma vulnerabilidade de estouro de inteiro que pode ser explorada
por atacantes remotos para derrubar serviços que usam essas funções ou
mesmo executar código arbitrário. Solução: É recomendado que todos os
usuários façam a atualização. Todas as aplicações que estiverem rodando
no momento da atualização devem ser reiniciadas. Uma forma de verificar
que aplicações são essas é executando o comando
lsof | grep \;

A primeira coluna da saída do comando acima conterá o nome da aplicação
que deverá ser reiniciada. Se houver dúvidas quanto a esse procedimento,
recomendamos que a máquina seja reiniciada.

– Verifiquei via nmap que tenho a porta 32768 aberta em um de meus servidores
(RH7.3). Procurei no netstat e aparece ainda a 32769

Proto Recv-Q Send-Q Endereço Local Endereço Remoto Estado
tcp 0 0 *:32768 *:* OUÇA
tcp 0 0 localhost.localdo:32769 *:* OUÇA
udp 0 0 *:32768 *:*
udp 0 0 *:32769 *:*

– Como verifico qual programa está ouvindo nessa porta?
lsof -i
2.47 – comando SuperProbe = exibe informaçõess sobre a placa de
víideo, como mémoria, chipset etc.
SuperProbe

First video: Super-VGA
Chipset: ATI 264GT3 (3D Rage Pro) (Port Probed)
Memory: 8192 Kbytes
RAMDAC: ATI Mach64 integrated 15/16/24/32-bit DAC w/clock
(with 6-bit wide lookup tables (or in 6-bit mode))
(programmable for 6/8-bit wide lookup tables)
Attached graphics coprocessor:
Chipset: ATI Mach64
Memory: 8192 Kbytes
2.48 – comando fold = permite alterar a largura das linhas de um arquivo.
O comando fold faz parte do pacote textutils. Esta alteração pode ser feita
contando-se os bytes, palavras, ou através de um valor pré-definido para o
comprimento de linha que se desenha. O comportamento padrão do comando fold
é quebrar as linhas em 80 colunas.

– Com estas opções as linhas serão quebradas na 60ª coluna, após um espaço
em branco(-s), impedindo que palavras sejam partidas
fold -s -w 60 arquivo1.txt
2.49 – comando history = exibe o histórico dos últimos 1000 comandos de um
usuário

– Exibe os últimos 10 comandos digitados
history 10

– Limpa o histórico corrente
history -c
2.50 – O diretório /proc = o sistema de arquivos ‘/proc’ é um sistema de ar-
quivos virtual. Isto significa que ele não existe fisicamente no winchester
Um sistema e arquivos virtual pode ser entendido como aquele que não deixa
rastro em seu winchester, ou seja, este sistema de arquivos está na memória
primária. O ‘/proc’ é criado ‘on the fly’ durante o processo de incialização
do linux. Ele possui diferentes estruturas de dados e informações colhidas
do kernel linux.

– Obtem informações sobre placas PCI
lspci
lspci -v
lspci -vv
lspci -vvv

– Exibe a quantidade de memória RAM em MB
free -m

– Exibe estatisticas sobre a memória virtual
vmstat

– Exibe a versão do kernel atual
uname -a

– Exibe o tipo de máquina (hardware)
uname -m

– Exibe o nome de rede da máquina
uname -n

– Exibe a versão (release) do kernel
uname -r

– Exibe o nome do sistema operacional
uname -s

– Exibe a data da compilação do kernel
uname -v

– Informações sobre gerenciamento de energia
cat /proc/apm

– Linha de comando para inicializar o kernel
/proc/cmdline

– Informações sobre a CPU
/proc/cpuinfo

– Informações sobre dispositivos usados o sistema
/proc/devices

– Informações sobre os canais DMA usados por dispositivos
/proc/dma

– Informações sobre os filesystems em uso
/proc/filesystems

– Informações sobre as interrupções (IRQ)
/proc/iterrupts

– Informações sobre s endereços de entrada e saída (I/O)
/proc/ioports

– Corresponde a toda a memoria RAM do PC
/proc/kcore

– Informações sobre mensagens do kernel linux
/proc/kmsg

– Informações sobre média de carga do PC
/proc/loadavg

– Informações sobre o uso da memória no PC
/proc/meminfo

– Informações sobre outras configurações
/proc/misc

– Informações sobre módulos atualmente carregados no kernel linux
/proc/modules

– Informações sobre os filesystems atualmente montados
/proc/mounts

– Informações sobre sobre placas PCI
/proc/pci

– Informações sobre o relogio em tempo real do sistema
/proc/rtc

– Exibe o tempo em que o sistema está funcionando
/proc/uptime

– Informações sobre a versão atual do kernel linux
/proc/version

– Informações sobre como esta particionado cada HD
/proc/partitions

– Lista os dispositivos de rede. Observe que pode não haver uma correspon-
dência entre os dispositivos listados e dispositivos físicos como placas
de rede. O dispositivo lo representa a interface de loopbacke não uma placa
de rede
/proc/net/dev

– Informações sobre placas ISA plug and play
pnpdump –config

– Diretório que exibe informações sobre rede
/proc/net/

– Informações sobre dispositivos
/proc/net/dev

– Estatísticas da rede
/proc/net/snmp

– Informação sobre o socket BÁSICO (RAW)
/proc/net/raw

– Informação sobre o socket TCP
/proc/net/tcp

– Informação sobre o socket UDP
/proc/net/udp

– Informação sobre o socket de domínio Unix
/proc/net/unix

– Informação sobre o socket IPX
/proc/net/ipx

– Informação sobre o socket AX25
/proc/net/ax25

– Informação sobre o socket DDP (Appletalk)
/proc/net/appeltalk

– Informação sobre o socket NET/ROM
/proc/net/nr

– Informação sobre os roteamentos IP realizados pelo kernel
/proc/net/route

– Informação sobre os roteamentos AX25 realizados pelo kernel
/proc/net/ax25_route

– Informação sobre os roteamentos IPX realizados pelo kernel
/proc/net/ipx_route

– Lista de nós NET/ROM do kernel
/proc/net/nr_nodes

– Conexões mascaradas do kernel
/proc/net/ip_masquerade

– Número máximo de arquivos que podem ser abertos
/proc/sys/fs/file-max

– Para exibir todas as variáveis e seus valores separados pelo sinal de igual
do sistema de arquivos ‘/proc’ digite:
sysctl -a

– Para exibir o valor de uma variável digite:
sysctl net/ipv4/conf/all/rp_filter
ou
cat /proc/sys/net/ipv4/conf/all/rp_filter

– Para atribuir um novo valor para a variável digite:
sysctl -w net/ipv4/conf/all/rp_filter=1
ou
echo 1 > /proc/sys/net/ipv4/conf/all/rp_filter

– Conta ao kernel linux qual o tempo do live que será colocado nos pacotes
que deixarão o host. O valor default é 64
/proc/sys/net/ipv4/ip_default_ttl

– Fornece ao servidor o recurso de linux router server, ou seja, que encaminhe
IP entre as diversas interfaces de rede. O valor booleano e o default é 0
(desabilitado). Para habilitar, basta trocar o 0 por 1
/proc/sys/net/ipv4/ip_forward

– O pmtu (Path Maximum Transfer Unit) é um valor booleano que pode ser habi-
litado para descobrir o mtu entre este host e um end host. O pmtu e o mtu
são coisas diferentes. o mtu conta ao kernel sobre a máxima unidade de
transferencia para suas conexões, mas não sobre todas conexão até o end-host.
O pmtu tenta descobrir o mtu para um end host incluindo todos os hops no
caminho. O valor default é 1
/proc/sys/net/ipv4/ip_no_pmtu_disc

– Permite que processos locais façam o bind com um endereço IP não local.
Isto é útil em alguns casos de snnifers para um determinado host. O valor
default é 0
/proc/sys/net/ipv4/ip_nonlocal_bind

– Se o valor for 1, o kernel linux ignorará todas os ICMP ECHO REQUESTS
/proc/sys/net/ipv4/icmp_echo_ignore_all

– Funciona como a variável icmp_echo_ignore all exceto que irá ignorar
somente mensagens ICMP enviadas para o endereço de broadcast ou multicast.
O valoe default é 0
/proc/sys/net/ipv4/icmp_echo_ignore_broadcasts

– É a taxa máxima na qual o kernel linux gerará mensagens ICMP do tipo es-
pecificado na variável icmp_ratemask. O valor é o número de jiffies
(1 jiffy = 1/100 sc) entre o envio de 2 mensagens semelhantes. O valor
dafult é 100 o que significa que um pacote ICMP pode ser enviado em 100
jiffies. O valor 0 significa não limitado envio de ICMP’s
/proc/sys/net/ipv4/icmp_ratelimit
– Atribui a máscara do qual tipos de ICMP’s serão limitados através da variá-
vel icmp_ratelimit
/proc/sys/net/ipv4/icmp_ratemask

Este valor é a soma de 2 ^ n, onde o n é cada tipo especificado de ICMP
(como especificado no cabeçalho de arquivos do kernel linux). Alguns tipos:
0 echo reply
3 destination unreachable
4 source quench
5 redirect (change route)
8 echo request
11 time exceeded
12 parameter problem
13 timestamp request
14 timestamp reply
15 information request
16 information reply
17 address mask request
18 address mask reply

O valor default desta variável é 6168 que significa que ICMP Destination
Unreachable, ICMP Source Quench, ICMP Time Exceeded e ICMP Parameter Problem
é a mascara. Veja:
2 ^ 3 + 2 ^ 4 + 2 ^ 11 + 2 ^ 12

– Esta variável contará ao kernel linux quando ele deve aceitar ICMP Redirects
ou não. ICMP Redirects são usados para contar a um host que existe um caminho
melhor para enviar pacotes para um específico host ou rede. O valor default
é 1
/proc/sys/net/ipv4/conf/nome_da_interface/accept_redirects

– Conta ao kernel linux se ele tem permissão para rotear pacotes pela origem.
O valor default é 1
/proc/sys/net/ipv4/conf/nome_da_interface/accept_source_route

– Conta ao kernel linux se um endereço IP deve ser ligado com um endereço
ARP específico ou não. O kernel linux decide se responde para um pacote en-
trando numa interface de rede, se ele envia a respsota pelo mesmo endereço
da interface ou não. Se o valor desta variável for verdadeiro (1) isso é o
que acontece. O valor default é 0
/proc/sys/net/ipv4/conf/nome_da_interface/arp_filter

– Habilita o encaminhamento de IP para dispositivos específicos. Isto é útil
para habilitar o encaminhamento entre 2 interfaces e uma terceira deixar de-
sabilitada. O valor default é o mesmo que o valor de ipv4/ip_forward, assim
se o valor atribuído a ip_forward for 1, todas as variáveis forwarding serão
1 também
/proc/sys/net/ipv4/conf/nome_da_interface/forwarding

– Permite o log de todos os pacotes que contém endereço impossível/
inválido/marciano. O valor default é 0
/proc/sys/net/ipv4/conf/nome_da_interface/log_martians

– Permite o roteamento multicast para um dispositivo específico. O valor
default é 0
/proc/sys/net/ipv4/conf/nome_da_interface/mc_forwarding

– Atribui proxy arp para uma interface. Este recurso deve ser habilitado
nas interfaces que se deseja para responder a ARP queries. O valor default
é 0
/proc/sys/net/ipv4/conf/nome_da_interface/proxy_arp

– Atribui o filtro de caminho reverso para uma interface. O RP serve para
validar que o atual endereço de origem usadoa por alguns pacotes estejam
correlacionados com uma tabela de rotas e que pacotes com este IP de origem
são supostamente respondidos através da mesma interface
/proc/sys/net/ipv4/conf/nome_da_interface/rp_filter

– Permite o redirecionamento seguro. Se não estiver habilitado, o kernel linux
aceitará ICMP redirect de qualquer host. Se habilitado, todos os ICMP redi-
rects serão somente aceitos de gateways litados na lista de gateway default.
Com isto poderemos nos livrar de redirecionamentos ilegais que podem ser
maliciosos. O valor default é 1
/proc/sys/net/ipv4/conf/nome_da_interface/secure_redirects

– Permite informar ao kernel linux se a interface física conectada é compar-
tilhada ou não. Isto é se diversas e diferentes redes IP com diferentes
máscaras operarem sobre uma mesma mídia ou não. O objetivo principal dessa
variável é informar ao kernel se deve enviar ICMP redirects para uma rede
específica ou não. O valor default é 1
/proc/sys/net/ipv4/conf/nome_da_interface/share_media

—————————————————————————-

3 – COMANDOS DE INICIALIZACAO E ENCERRAMENTO DO GNU/LINUX

3.1 – comando sync = salva as informações em cache de disco. Isso força
todas as informações alteradas a serem salvas no disco. O comando faz o
sistema copiar buffers para o disco. Use o comando sync antes de desligar
o sistema, ou seja, antes do comando ‘shutdown’
sync
3.2 – comando reboot = reinicia o sistema imediatamente. Deve ser usado
com cuidado pois não faz chamada ao comando sync e isto pode gerar
inconsistências no sistema de arquivos que somente o fsck poderá
consertar
reboot
3.3 – comando shutdown = reinicia ou desliga o sistema de forma segura

– Reinicia o sistema neste exato momento
shutdown -r now

– Desliga o computador neste exato momento
shutdown -h now

– Reinicia o sistema daqui 8 minutos
shutdown -r +8

– O computador entra em modo mono-usuário as 19:00 horas
shutdown 19:00

– Desliga o computador as 19:00 horas
shutdown -h +19:00

– Desliga o computador as 06:00 horas da manhã
shutdown -h +06:00

– Reinicia o sistema daqui a 23 minutos
shutdown -r 23

– Cancela a execução do comando shutdown
shutdown -c

– Cancela a execucao do shutdown enviando uma mensagem aos usuários do sistema
shutdown -c mensagem

– Envia uma mensagem para os usuários do sistema sem reiniciar o PC
shutdown -k mensagem

– Sequência para desligamento do computador:
sync
sync
shutdown -h now
ou
sync; sync; shutdown -h now

Sequencia para reiniciar o computador:
sync
sync
shutdown -r now
ou
sync; sync; shutdown -r now
3.4 – comando exit = termina a sessão atual
3.5 – comando logout = termina a sessão atual
3.6 – comando sleep = causa um processo para torna-se inativo
3.7 – comando su = executa um interpretador de comandos com substituição
de usuário e grupo sem efetuar logout do usuario atual. su permite que
um usuário torne-se outro temporariamente.
su nome-do-usuario

Para retornar ao usuário anterior, tecla CTRL+D ou digite ‘exit’
3.8 – comando rlogin = inicia uma sessao de terminal remoto
rlogin -l username host

Opções:
-x = ativa a criptografia dos dados que forem transmitidos
3.9 – Servicos no gnu/linux

– Debian, Kurumin, Ubuntu
Iniciar servico = /etc/init.d/nome-do-servico start
Parar servico = /etc/init.d/nome-do-servico stop
Reiniciar servico = /etc/init.d/nome-do-servico restart

– RedHat, Fedora
Iniciar servico = /etc/rc.d/init.d/nome-do-servico start
Parar servico = /etc/rc.d/init.d/nome-do-servico stop
Reiniciar servico = /etc/rc.d/init.d/nome-do-servico restart
3.10 – comando crontab = apresenta ou altera a tabela cron (crontab) de um
usuário. A tabela cron especifica acoes programadas que sao executadas pelo
daemon cron.

– Edita o arquivo crontab do usuario que esta executando o comando
crontab -e

– Exibe o arquivo crontab do usuario que esta executando o comando
crontab -l

– Exclui o arquivo crontab do usuario que esta executando o comando
crontab -r
3.11 – comando halt = para o sistema.

– Desliga o sistema
halt

– Força o desligamento do sistema
halt -f

– Desliga as interfaces de rede antes do desligamento total do sistema
halt -i

– Ao paralisar o sistema, desliga o computador
halt -p

– Desliga o sistema mas não registra o desligamento no arquivo ‘/var/log/wtmp’
Por padrao é registrado o desligamento neste arquivo
halt -d
3.12 – comando login = estabelece login com o sistema.

– Pede o login e o password para o user1
login user1

– Usado para evitar uma segunda autenticação de acesso. Isso não funciona
para o o usuário root
login -f user2

– Usado por getty para dizer ao login não destruir o ambiente
login -p

– Usado por outros servidores (por exemplo telnetd) para passar o nome para
o servidor remoto para acessos que podem ser colocados em utmp e wtmp. Apenas
o usuário root pode usar esta opção
login -h nome-da-maquina
3.13 – comando chkconfig = faz com que serviços sejam inicializados/fiquem
parados nos modos de inicialização do RedHat ou Fedora GNU/Linux(init 1,
2, 3, 4, 5)

– Modo grafico = 5
– Modo texto = 3

– Habilita o serviço sshd no modo texto(3)
chkconfig –level 3 sshd on

– Habilita o serviço squid no modo grafico(5)
chkconfig –level 5 squid on

– Habilita o servico httpd nos modos de inicializacao 3, 4 e 5
chkconfig –level 345 httpd on
3.14 – comando startx = inicializa um gerenciador de janelas do X.

– Se você quiser iniciar mais de um X, você deverá adicionar alguns
parâmetros, a partir da segunda sessão X
startx — :1

– Executa o terceiro X11, silenciosamente e em segundo plano para não
bloquear o console
startx — :2 -quiet &

– Executa o quarto X11, com uma profundidade de cor de 24 bits
startx — :3 -bpp 24

#######################################################################

4 – COMANDOS DE CONTROLE DE ACESSO E USUARIOS/GRUPOS

4.1 – comando useradd ou adduser = adiciona um usuario no sistema. Por
padrão, quando um novo usuario é adicionado, é criado um grupo com o
mesmo nome do usuario. Sera criado um diretorio home com o nome do usuário
e este recebera uma identificacao.

– Para criar o usuário chamado ‘jordam’
useradd jordam

– Força a criação do diretório ‘home’ do usuário ‘jordam’
useradd -m jordam

– Cria o usuário ‘jordam’ com a ID ‘800’
useradd -u 800 jordam

– Cria o usuário ‘jordam’ com o nome do grupo chamado ‘admin’
useradd -g admin jordam

– Cria o usuário ‘jordam’ com o seu shell apontando para ‘/bin/false’
(ele não irá conseguir se logar no sistema)
useradd jordam -s /bin/false

– Cria o usuário ‘jordam’ especificando seu diretório home em ‘/home/users/’
ao invés de ‘/home/jordam’
useradd -d /home/users jordam

– Cria o usuário ‘jordam’ colocando-o no grupo ‘admin’ e também nos
‘users’ e ‘postgresql’
useradd -g admin -G users,postgresql jordam
– Adiciona o usuário ‘jordam’ no grupo ‘users’ com o diretório home em
‘/home/jordam’ e seu nome pessoal ‘Mister Jordam’. Se você não especi-
ficar qualquer parametro então serão utilizadas as configurações padrão
contidas no arquivo ‘/etc/default/useradd’. Além disso, o conteúdo do
diretório ‘/etc/skel’ será copiado para o diretório deste novo usuário
useradd -g users -d /home/jordam -c ‘Mister Jordam’ jordam
4.2 – comando passwd = cria/modifica a senha de um usuário

– Altera senha do usuário ‘jordam’
passwd jordam

– Bloqueia/travar login do usuário ‘jordam’
passwd -l jordam

– Desbloqueia/destrava login do usuario ‘jordam’
passwd -u jordam
4.3 – comando usermod = modifica a conta de um usuário

– Altera o diretório home do usuário ‘jordam’
usermod -d nome_do_diretorio jordam

– Define uma data de expiração para a conta do usuário ‘jordam’, após ela
será desativada. A data deve estar no formato YYYY-MM-DD
usermod -e YYYY-MM-DD jordam

– Fornece um novo ajuste para o número de dias depois que uma senha
expira, quando ela será permanentemente desativada
usermod -f numero_de_dias_inativos usuario1

– Altera o nome do login do usuário ‘jordam’ para ‘jordam23’
usermod -l jordam23 jordam

– Altera o shell padrão do usuário ‘jordam’
usermod -s nome_do_shell jordam

– Altera o número de identificação (UID) do usuário ‘jordam’
usermod -u UID jordam

– Configura a data de expiração da conta do usuário ‘jordam’ para 21
de Agosto de 2003
usermod -e 2003-8-21 jordam

– Faz com que o usuário ‘jordam’ passe a ser membro do grupo ‘users’
usermod -G users jordam
4.4 – comando userdel = remove um usuário do sistema

– Remove o usuário ‘jordam’
userdel jordam

– Remove o usuário ‘jordam’ e também seu diretório home (/home/jordam)
userdel -r jordam

– Procura e remove arquivos que pertenciam ao usuário ‘jordam’ cujo UID
é 800 (checar o arquivo ‘/etc/passwd) que se encontram em outros diretó-
rios no sistema
find / -type f -uid 800 -print -exec rm {} \;
4.5 – comando groupadd ou addgroup = adiciona um grupo ao sistema

– Cria um grupo chamado ‘reporteres’ no sistema
groupadd reporteres

– Cria um grupo chamado ‘artistas’ especificando o número de identificação
do grupo (GID) como 823
groupadd -g 823 artistas

OBS: Logo após a criação de um grupo, pode-se acrescentar uma senha
ao mesmo. Pra isso, basta digitar o comando
gpasswd nome_do_grupo
4.6 – comando groupmod = modifica informaçõe sobre um grupo
groupmod grupo1
4.7 – comando groupdel = exclui um grupo do sistema. Você nao pode remover
o grupo primario de um usuario. Remova o usuario primeiro.

– Exclui o grupo ‘artistas’ do sistema
groupdel artistas

– Procura todos os arquivos pertencentes ao grupo cuja ID é 960 e depois
usa o comando ‘chgrp’ para alterar a posse de grupo do arquivo para o
grupo chamado ‘novogrupo’
find / -type f -uid 960 -print -exec chgrp novogrupo {} \;
4.8 – comando chgrp = altera o GRUPO de arquivos/diretorios. O grupo de
um arquivo/diretorio só poderá ser alterado pelo seu respectivo dono.

– Altera o grupo atual do arquivo ‘teste1.txt’ para o grupo ‘projetos’
chgrp -c -v projetos teste1

– Altera o grupo atual do diretório ‘pesquisa’ para o grupo ‘projetos’
e também de todos os arquivos e subdiretorios presentes no diretório
‘pesquisa’
chgrp -R -c -v projetos pesquisa
4.9 – comando chown = altera o proprietário/dono e/ou o nome do grupo de
arquivos/diretórios

– Altera o dono do arquivo ‘teste1.txt’ para o usuário ‘jordam’ e grupo
‘admin’ exibindo o resultado do comando (opção -v)
chown -v jordam.admin teste1.txt

– Altera o dono do diretório ‘textos’ bem como seus sub-diretórios (opção -R)
para o usuário ‘jordam’ e grupo ‘admin’
chown -v -R jordam.admin textos

– Altera o dono do arquivo ‘teste5.txt’ para o usuário ‘jordam’
chown jordam teste5.txt
4.10 – comando chmod = altera as permissões de acesso de arquivos/diretórios

drw-r–r– 1 root root 361 Nov2000 07:23AM file1.txt

a b c d e f g h

a – permissões do arquivo
b – número
c – dono/proprietário do arquivo
d – grupo do arquivo
e – tamanho em bytes do arquivo
f – data de criacao do arquivo
g – hora de criacao do arrquivo
h – nome do arquivo

d rwx rwx rwx
| | | |
| | | |_ acesso aos demais usuarios que nao sao do grupo do dono do arquivo
| | |
| | |_ grupo do proprietario do arquivo
| |
| |_ proprietario do arquivo
|
|_ indica que é um diretorio
r – read (Leitura) – copiar, visualizar, imprimir:
* arquivo: significa que se pode ler o arquivo (através de um “cat” por
exemplo.

* diretório: significa que se pode ver o conteúdo do diretório (através de
ls por exemplo). Porém observe a explicação sobre a permissão de execução mais
abaixo.

w – write (escrita, gravação): mover, apagar, modificar
* arquivo: significa que se pode adicionar conteúdo e alterar um arquivo.

* diretório: significa que se pode criar e/ou apagar qualquer, repito QUALQUER
arquivo e/ou diretório que esteja dentro deste, mesmo que não se tenha
permissão
alguma para o arquivo/diretório a ser apagado. Observe a explicação sobre
permissão de execução abaixo e “sticky bit” em 2.2. NUNCA deixe o seu
diretório
home com esta permissão para outros (também conhecida como world-writable).

x – eXecute (execução)
* arquivo: pode-se executar o programa ou shell script (se um arquivo texto
não for um script e tiver esta permissão e você executar vai dar um monte de
“command not found”).

* diretório: significa que pode-se “entrar” no diretório. Esta permissão
é importante quando atribuída a um diretório. De nada adianta uma permissão
‘w’ se não tiver ‘x’. Já no caso do ‘r’ sem ‘x’ ainda podemos ver o conteúdo
do diretório, porém com algumas limitações. Mas na hora de executar um “find”
precisamos ter ‘r’ e ‘x’.

– = sem permissão

PERMISSÕES OCTAIS (modo octal)
0 = nenhuma permissao para o arquivo (—)
1 = permissao para executar o arquivo (–x)
2 = permissao para gravar(escrever) no arquivo (-w-)
3 = permissao para gravar(escrever) e executar o arquivo (-wx)
4 = permissao para leitura do arquivo (r–)
5 = permissao para leitura e execucao do arquivo (r-x)
6 = permissao para leitura e gravacao(escrever) no arquivo (rw-)
7 = permissao para leitura, gravacao(escrever) e execucao do arquivo (rwx)

,——-,———–,———,
| octal | permissão | cálculo |
|——-|———–|———|
| 0 | — | 0 |
| 1 | –x | 1 |
| 2 | -w- | 2 |
| 3 | -wx | 2+1 |
| 4 | r– | 4 |
| 5 | r-x | 4+1 |
| 6 | rw- | 4+2 |
| 7 | rwx | 4+2+1 |
‘——-‘———–‘———‘

Um modo fácil de entender como as permissões de acesso octais funcionam, é
através da seguinte tabela:
1 = executar
2 = gravar
4 = ler

Basta agora fazer o seguinte:
– somente permissão de execução, use 1
– somente a permissão de leitura, use 4
– somente permissão de gravação, use 2
– permissão de leitura/gravação, use 6 (equivale a 2+4/Gravar+Ler)
– permissão de leitura/execução, use 5 (equivale a 1+4/Executar+Ler)
– permissão de execução/gravação, use 3 (equivale a 1+2 /Executar+Gravar)
– permissão de leitura/gravação/execução, use 7 (equivale a
1+2+4/Executar+Gravar+Ler).

OBS: O caracter “d” no primeiro bit de algumas linhas geradas com
o comando ls, significa que é um diretorio. Veja abaixo a lista de
outras opções possiveis:

Caractere Significado
– arquivo normal
b dispositivo de blocos
c dispositivo de caracteres
d diretorio
l symbolic link
p FIFO
s socket, atribuído para arquivos de comunicação/memória
t sticky bit é um bit utilizado tanto para arquivos como
para diretórios

Em adição as três permissões básicas (rwx), existem permissões de
acesso especiais (stX) que afetam arquivos executáveis e diretórios:

– s = quando é usado na permissão de acesso do “dono” ajusta a identificação
efetiva do usuário do processo durante a execução de um programa, também
chamado de “bit setuid”. Não tem efeito em diretórios. Quando “s” é usado na
permissão de acesso do “Grupo” ajusta a identificação efetiva do grupo do
processo durante a execução de um programa, chamado de “bit setgid”. É
identificado pela letra “s” no lugar da permissão de execução do grupo do
arquivo/diretório. Em diretórios, força que os arquivos criados dentro dele
pertençam ao mesmo grupo do diretório, ao invés do grupo primário que o
usuário pertence. Ambos “setgid” e “setuid” podem aparecer ao mesmo tempo no
mesmo arquivo/diretório. A permissão de acesso especial “s” somente pode
aparecer no campo “dono” e “grupo”.

– t = salva a imagem do texto do programa no dispositivo swap, assim ele
será carregado mais rapidamente quando executado, também chamado de “stick
bit”.
Em diretórios, impede que outros usuários removam arquivos dos quais não são
donos. Isto é chamado de colocar o diretório em modo “append-only”. Um
exemplo de diretório que se encaixa perfeitamente nesta condição é o “/tmp”
todos os usuários devem ter acesso para que seus programas possam criar os
arquivos temporários lá, mas nenhum pode apagar arquivos dos outros. A
permissão especial “t” pode ser especificada somente no campo outros
usuários das permissões de acesso.

– X = se você usar “X” ao invés de “x” a permissão de execução somente é
afetada se o arquivo ja tiver permissões de execução. Em diretórios ela tem
o mesmo efeito que a permissão de execução “x”.

,—————————————————-,
| ATRIBUTOS ESPECIAIS |
|————-‘————————————–|
| VALOR OCTAL | SIGNIFICADO |
|————-‘————————————–|
| 0 | Nenhum atribudo especial ligado |
| 1 | Bit STICKY ligado |
| 2 | Bit SETGID ligado |
| 3 | Bits STICKY e SETGID ligados |
| 4 | Bit SETUID ligado |
| 5 | Bits STICKY e SETUID ligados |
| 6 | Bits SETUID e SETGID ligados |
| 7 | Bits STICKY, SETUID e SETGID ligados |
‘————-‘————————————–‘

,————————————————————–,
| BIT | SIGNIFICADO |
|——–‘—————————————————–‘
| SETUID | O arquivo é executado como se fosse invocado pelo |
| | proprietario; não faz sentido para diretórios. |
|——–‘—————————————————–‘
| SETGID | O arquivo é executado sob seu grupo, mesmo que o |
| | usuário que esteja querendo executar o arquivo não |
| | participe dele. Todo arquivo criado em um diretó- |
| | rio SETGID é criado com o mesmo grupo do diretório. |
|——–‘—————————————————–‘
| STICKY | Um arquivo criado sob um diretório com o bit STICKY |
| | ligado pode ser apagado apenas por seu proprietario.|
| | Um programa com o bit STICKY ligado terá seu texto |
| | mantido na area de swap do sistema. |
‘——–‘—————————————————–‘

– Altera a permissão do arquivo ‘texto2.txt’ para leitura, gravação
e execução (x) para o seu dono/proprietário, leitura e execução
para o grupo do dono/proprietário e para os demais usuários permissão
de leitura e execução
chmod -v 755 texto2.txt

– Semelhante a opção ‘-v’ mas somente exibe os arquivos que tiveram as
permissões alteradas
chmod -c 755 texto2.txt

– A opção ‘-R’ indica para mudar os acessos de forma recursiva, ou
seja, de todos os arquivos e sub-diretórios do diretório ‘textos’
chmod -v -R 411 textos

– Define a permissão de acesso dos outros usuarios(0) como nenhuma, e
define a permissão de acesso do grupo(4) como somente leitura. Utilizei
somente dois números e então a permissão de acesso do dono do arquivo
não é modificada pois o sistema le as permissões de acesso da direita
para a esquerda
chmod 40 texto2.txt

– Liga o bit STICKY do diretório projetos e da permissão de leitura,
escrita e execução a todos os usuários do sistema
chmod 1777 projetos

– Define a permissão de acesso dos outros usuários(2) para somente exe-
cução, acesso do grupo(4) como leitura e execução o acesso do dono(7)
como leitura, gravação e execução e ajusta o bit setgid(4) para o ar-
quivo ‘texto2.txt’
chmod 4752 texto2.txt
4.11 – comando umask = a umask (user mask) são 3 números que definem as
permissões iniciais do dono, grupo e outros usuarios que o arquivo/diretório
recebera quando for criado ou copiado. Digite umask sem parâmetros para
retornar o valor de sua umask atual. A umask tem efeitos diferentes caso
o arquivo que estiver sendo criado for binario(um programa executável) ou
texto. Veja a tabela a seguir para ver qual é a mais adequada a sua situação:

,——-,———————-,————,
| | ARQUIVO | |
| UMASK |———————-| DIRETÓRIO |
| | Binário | Texto | |
|——-|————|———|————|
| 0 | r-x | rw- | rwx |
| 1 | r– | rw- | rw- |
| 2 | r-x | r– | r-x |
| 3 | r– | r– | r– |
| 4 | –x | -w- | -wx |
| 5 | — | -w- | -w- |
| 6 | –x | — | –x |
| 7 | — | — | — |
‘——-‘————‘———‘————‘

– Um arquivo texto criado com o comando
umask 012
touch texto.txt
receberá as permissões “-rw-rw-r–” pois 0 (dono) terá permissões “rw-”
1 (grupo), terá permissões “rw-” e 2 (outros usuários) terão permissões
“r–”

– Um arquivo binário copiado com o comando
umask 012;cp /bin/ls /tmp/ls

receberá as permissões `-r-xr–r-x’ (confira com a tabela acima)

– Por este motivo é preciso um pouco de atenção antes de escolher a
umask, um valor mal escolhido poderia causar problemas de acesso a
arquivos, diretórios ou programas não sendo executados. O valor padrão
da umask na maioria das distribuições atuais é 022. A umask padrão no
Debian GNU/Linux é a 022. A umask é de grande utilidade para programas
que criam arquivos/diretórios temporários, desta forma pode-se bloquear
o acesso de outros usuários desde a criação do arquivo, evitando recor-
rer ao comando ‘chmod’. Quando um arquivo é criado ele recebe certos
valores de propriedade, como o UID do dono (normalmente o criador do
arquivo), o valor de propriedade do grupo GID (geralmente o grupo a que
o dono pertence quando o arquivo é criado) e outros valores de permissão
de acesso derivados dos valores associados ao valor umask do dono, no
momento da criação. Estes valores umask são definidos geralmente no arquivo
‘/etc/profile’ com os seguintes valores

Para o superusuário (root):
umask 002

Para os demais usuários do sistema:
umask 022

Algarismo 0 = nenhum tipo de acesso
Algarismo 2 = acesso somente leitura
Algarismo 6 = acesso completo (leitura e gravação)

– A umask funciona retirando permissões, ou seja, a permissão padrão do
sistema seria 666, mas com um valor de 002, no caso do superusuário,
teríamos 664 (666-002=664), o que significa que quando um arquivo for
criado pelo superusuário ele vai ter suas permissões inicias em
-rw-rw-r–, permitindo escrita e leitura para o dono do arquivo e ao
grupo ao qual ele pertence, porém somente leitura para os demais
usuários do sistema. Já no caso dos usuários comuns do sistema, todo
arquivo iniciará sua vida com permissões 644 (666-022=644), o que signi-
fica leitura e escrita para o dono (no formato absoluto será -rw-r–r–),
enquanto que para o grupo e aos outros usuários do sistema permite apenas
leitura. Além destas permissões, existe uma permissão especial que permite
que usuários possam executar arquivos de outros donos, com as permissões
destes últimos. É o chamado o suid bit.
chmod a+s script1.sh

Com esta linha de comando, o arquivo ‘script1.sh’ pode ser executado por
qualquer usuário (parâmetro a – all), utilizando as permissões do dono
do arquivo.
4.12 – comando chattr = altera atributos de um arquivo

– Altera os atributos dos diretórios e de seus conteúdos
chattr -R

– Exibe os detalhes das modificacoes efetuadas
chattr -V

– Remove todos os atributos do arquivo ‘teste1.txt’
chattr = teste1.txt

– Adiciona o atributo imutável no arquivo ‘teste1.txt’
chattr +i teste1.txt

– Remove o atributo imutável do arquivo ‘teste1.txt’
chattr -i ‘teste1.txt’

– Adiciona o atributo para não atualizar a data de acesso do arquivo
‘teste1.txt’
chattr +A teste1.txt

– Remove o atributo para nao atualizar a data de acesso do arquivo
‘teste1.txt’
chattr -A teste1.txt

– Adiciona o atributo para que o arquivo ‘teste1.txt’ não seja sobrescrito
chattr +a teste1.txt

– Remove o atributo para que o arquivo ‘teste1.txt’ seja sobrescrito
chattr -a teste1.txt

– Adiciona o atributo para presevar o conteúdo do arquivo ‘teste1.txt’
durante uma atualização
chattr +u teste1.txt

– Remove o atributo para presevar o conteudo do arquivo ‘teste1.txt’
durante uma atualização
chattr -u teste1.txt
4.13 – comando lsattr = visualiza os atribuidos criados com o comando
chattr em arquivos/diretórios

– Lista os atributos do arquivo ‘teste5.txt’
lsattr teste5.txt

– Lista os atribuidos do diretório ‘/home’
lsattr -d /home

– Lista os atributos de todos os sub-diretórios do diretório
‘/home/jordam/trabalho’
lsattr /home/jordam/trabalho

– Lista os atributos de todos os arquivos e diretórios dentro do
diretorio ‘/home’
lsattr -R /home

– Lista todos os arquivos, inclusive os oculdos ‘.’
lsattr -a
4.14 – comando stat = exibe informações sobre um arquivo

– Lista informações do arquivo ‘teste5.txt’
stat teste5.txt

File: `eita.txt’
Size: 50 Blocks: 8 IO Block: 4096 regular file
Device: 303h/771d Inode: 343223 Links: 1
Access: (0644/-rw-r–r–) Uid: ( 1000/ edersg) Gid: ( 1000/ edersg)
Access: 2005-07-09 09:07:34.000000000 -0300
Modify: 2005-07-09 09:07:24.000000000 -0300
Change: 2005-07-09 09:07:24.000000000 -0300
4.15 – comando mount = monta sistemas de arquivos

– Alguns tipos de de sistemas de arquivos
minix, ext2, ext3, hpfs, msdos, umsdos, vfat, proc, nfs, iso9660,
smbfs, ufs, sysv, xenix

– Monta o CD-ROM (de dados) no diretório ‘/mnt/cdrom’
mount /dev/cdrom /mnt/cdrom
ou
mount -t iso9660 /dev/cdrom /mnt/cdrom
ou
mount -t iso9660 /dev/hdx /mnt/cdrom

– Monta o disquete no diretório ‘/mnt/disquete’
mount /dev/fd0 /mnt/disquete

– Monta o disquete no diretório ‘/mnt/floppy’ com o sistema de arquivos
DOS, ou seja, FAT32
mount -t vfat /dev/fd0 /mnt/floppy

– Monta o disquete no diretório ‘/mnt/floppy’ com o sistema de arquivos
ext2
mount -t ext2 /dev/fd0 /mnt/floppy

– Monta na particao hdaX (X trocar pela partição correspondente do seu
win98) os arquivos do win98 no diretorio ‘/mnt/win98’
mount -t vfat /dev/hdaX /mnt/win98

– Monta o arquivo (imagem ISO) ‘debian1.iso’ dentro do diretório
‘/mnt/imagem’ tornando acessíveis todos os arquivos que estão em ‘debian1.iso’
como se estivesse acessando o CD nº 1 do Debian:
mount -t iso9660 -o ro,loop=/dev/loop0 /imagens/debian1.iso /mnt/imagem
ou
mount -o loop,unhide -t iso9660 -r debian1.iso /mnt/imagem

– Monta a unidade do WinNT no diretorio ‘/home/winnt’
mount -t smbfs -o username=USUARIO,password=SENHA,workgroup=GRUPO //192.168.0.1/share /home/winnt

– Como montar um DRIVE a partir da memória RAM disponível?
EX: Criar um /tmp/ram (32MB) para colocar arquivos temporários.
Use o tmpfs para isso:
mount -t tmpfs none /tmp/ram -o size=32M

Você pode mudar seu tamanho depois, fazendo:
mount /tmp/ram -o remount,size=64M

– Já configurei o NFS no servidor, só não sei como faço para acessar da
minha maquina cliente como montar, esse compartilhamento?
Sintaxe:
mount -t nfs ip-do-serv-nfs:/diretorip /ponto_de_montagem
EX:
mount -t nfs 10.0.0.1:/home /mnt/home

– Você vai ter que dar BOOT no PC, entrar com disquete ou CD de Rescue
e montar o / (raiz) na memória, fazer a alteração no fstab e depois
reiniciar… Nao precisa. Basta digitar:
mount -n -o remount,rw /

– Se você gravou o arquivo em si, deves montar o CD e depois montar o
arquivo com o seguinte comando:
mount -o loop arquivo.iso /ponto-de-montagem-a-ser-acessado
ou
mount -t iso9660 im_do_cd.iso /mnt/cdrom = poderá ser acessado os arquivos
da imagem do CD sem precisar gravá-la em uma mídia.

– Para montar uma pasta compartilhada do Windows no GNU/Linux:
mount -t smbfs //pc_win2000/pasta /mnt/maq_w2k -o username=Usuario,password=Senha

– Formatar disquete para acesso no DOS/Windows 9x, GNU/Linux
fdformat /dev/fd0H1440

– Cria o sistema de arquivos etx2 para acesso somente no GNU/Linux
checando blocos ruins:
mke2fs -c -L nome-do-volume /dev/fd0 = cria o sistema de arquivos ext2

no disquete checando blocos ruins e especificando o nome do volume ou
mkfs -t ext2 -c /dev/fd0H1440 = cria o sistema de arquivos ext2 no disquete

checando blocos ruins ou
mkfs.ext2 -c /dev/fd0H1440 = cria o sistema de arquivos ext2 no disquete

checando blocos ruins

– Cria o sistema de arquivos ext2 na particao ‘/dev/hda1’ checando blocos
ruins e especificando o nome do volume
mke2fs -c -L nome-do-volume /dev/hda1

– Cria o sistema de arquivos ext2 na partição ‘/dev/hda2’ checando blocos
ruins
mkfs -t ext2 -c /dev/hda2

– Cria o sistema de arquivos ext2 na partição ‘/dev/hda3’ checando blocos
ruins
mkfs.ext2 -c /dev/hda3

Opções:
-c = checa blocos ruins
-t = especifica o tipo de sistema de arquivos a ser gerado
-L = especifica o nome do volume da particao

– Cria(formata) o sistema de arquivos vfat para acesso no DOS/Win9*
checando blocos ruins: (cria o sistema de arquivos e verifica a
existencia de blocos defeituosos antes de formatar)
mkdosfs -c /dev/fd0

– Cria o sistema de arquivos e verifica a existencia de blocos
defeituosos antes de formatar
mkdosfs -c /dev/hda1

– Indica o tipo de alocacao de arquivo a ser criado. Pode ser FAT12,
FAT16
mkdosfs -F fatsize /dev/fd0

– Define o rotulo de volume com o nome de no maximo 11 caracteres
mkdosfs -n nome-do-volume /dev/fd0

– Cria o sistema de arquivos FAT e verifica a existencia de blocos
ruins na partição ‘/dev/hda1’
mkfs.msdos -c /dev/hda1

– Antes de retirar o disquete, desmonte-o
umount /dev/fd0

– Como formato disquetes para mais de 1.44MB?
Escolha o dispositivo correto. Ex: para formatar um disquete em 1.44
fdformat /dev/fd0h1440 ou simplesmente fdformat /dev/fd0

Para formatar em 1.66
fdformat /dev/fd0h1660
4.16 – copiando disquetes = para copiar disquetes, digite

dd if=/dev/fd0H1440 of=imagem # dd if=imagem of /dev/fd0H1440

o primeiro dd gera a imagem exata do disquete para o arquivo imagem,
o segundo dd grava a imagem para o disquete
4.17 – comando mkpasswd = quando invocado sem parâmetros, retorna uma senha
randômica qualquer. Uma shell script simples para criar quantas contas forem
necessárias e que atribui a cada usuário uma senha pode ser criada facilmente.

cd /usr/bin
mcedit senhas.sh
#!/bin/bash
for usuario in `cat $1`
do
useradd $usuario
mkpasswd $usuario > $usuario.senha
# Criação da carta ao usuario
cat > $usuario.carta << FIM

Conforme sua solicitação, foi criada uma conta em nossos computadores
centrais com as seguintes especificações:

computador: $HOSTNAME
login: $usuario
senha: `cat $usuario.senha`

Solicitamos a memorização das informações contidas neste documento e
sua destruição em seguida, devido ao caráter confidencial destas
informações.

Realize a troca de sua senha já em seu primeiro acesso para algo que
lhe seja mais fácil de lembrar.

Lembre-se, nunca divulgue a sua senha de acesso para ninguém. A segurança
de seus dados e do sistema como um todo dependem de você.

Atenciosamente,

Suporte Técnico
FIM

cat $usuario.carta
enscript -f Courier12 -F Courier-bold12 -b “Prezado Usuário(a),”
$usuario.carta
rm $usuario.*
done
4.18 – comando mkswap = configura e formata uma particao como area de troca

– Configura a partição ‘/dev/hda5’ como do tipo swap checando se existem
blocos defeituosos na partição ‘/dev/hda5’
mkswap -c /dev/hda5

depois, digite o comando abaixo para ativar a particao swap ‘/dev/hda5’
swapon /dev/hda5

e para desativar uma particao swap ‘/dev/hda5’ momentaneamente
swapoff /dev/hda5
4.19 – comando badblocks = é utilizado para pesquisar qualquer disco ou
partição na detecção de blocos defeituosos

– Cria o arquivo ‘resultados1.txt’ com a lista de blocos defeituosos
encontrados na partição ‘/dev/hda1’
badblocks -o /resultados1.txt /dev/hda1

– Exibe o número de blocos checados durante a execução do comando
badblocks ‘-s’ e exibe maiores detalhes sobre os resultados do comando
backblocks ‘-v’
badblocks -s -v /dev/hda1

– Checa se um disquete possui badblocks
badblocks /dev/fd0H1440 1440

Opções:
-b [tamanho] especifica o tamanho do bloco do dispositivo em bytes

-o [arquivo] gera uma lista de blocos defeituosos do disco no [arquivo].
Esta lista pode ser usada com o programa fsck junto com a opção -l

-s mostra números de blocos checados durante a execução dos badblocks

-v modo verbose que exibe todos os detalhes da execução

-w usa o modo leitura/gravação. Com esta opção o badblocks procura por
blocos defeituosos gravando alguns padrões (0xaa,0x55,0xff,0x00) em cada
bloco do dispositivo testado

Cuidado: Nunca use esta opção em um dispositivo que contenha arquivos, pois
eles serão apagados.
4.20 – comando dumpe2fs = exibe informações sobre o superbloco para o
sistema de arquivos presente, no caso, o ext2
dumpe2fs -b -V /dev/dispositivo
4.21 – comando chroot = permite que o diretório raiz / seja um diretório
diferente de / no sistema de arquivos. Um exemplo, um servidor Internet,
você poderá definir o diretório raiz como /usr/ftp. Quando alguem acessar
esse servidor usando FTP, o qual vai para o diretório raiz por padrão,
estará na verdade acessando o diretório /usr/ftp
chroot </ </usr/ftp>

– Executa o daemon do BIND ‘enjaulado’, como usuário ‘named’ e no modo de
depuração. A partir disso pode se constatar erros e realizar os acertos
necessários
chroot /var/named /usr/local/sbin/named -u named -g

– Digamos que a sua árvore de dir seja

/
|-root
|-etc
|-bin
|-home
|-outro usuario
|-user
|-bin
|-etc

chroot /home/user
agora para o usuario a arvore vai ser
/
|-bin
|-etc

perceba que voce tem que ter os diretorios de suporte no home do user, ja
que para ele nem vai existir o resto da arvore… mais ou menos como em
um FTP você tem de ter o /bin o /lib e etc e não /etc/
4.22 – comando dd = converte e copia um arquivo

– Copia o conteúdo do ‘hd_origem’ para um novo HD, no caso o ‘hd_destino’
dd if=/dev/hd_origem of=/dev/hd_destino

– Copia o conteúdo completo do CD-ROM (já montado no sistema) para o
arquivo ‘/usr/imagem1.iso’
dd if=/dev/cdrom of=/usr/imagem1.iso

Para testar a cópia, monte-a utilizando o comando
mount -o loop -t iso9660 -r /usr/imagem1.iso /mnt/imagem1

– Cria uma imagem do conteúdo do CD-ROM para o arquivo ‘/home/imagem.iso’
dd if=/dev/cdrom of=/home/imagem.iso
– Copia o ‘arquivo.img’ para um disquete de 1.44MB
dd if=arquivo.img of=/dev/fd0 bs=1440k

if=arquivo = le a partir do arquivo ao invés da entrada padrão

of=arquivo = escreve no arquivo ao invés da saída padrão. A menos que
‘conv=notrunc’ seja fornecido, dd trunca o arquivo para zero bytes
(ou para o tamanho especificado com seek=)
4.23 – comando newusers = le um arquivo contendo uma lista de novos
usuarios e cria estes usuarios no sistema. O formato do arquivo lido
pelo comando newusers é o mesmo do arquivo ‘/etc/passwd’
newusers arquivo-usuarios.txt
4.24 – comando lastlog = exibe o último login dos usuários cadastrados no
sistema. É exibido o nome usado no login, o terminal onde ocorreu a conexão
e a hora da ultima conexao. Estes dados sao obtidos atraves da pesquisa e
formatacao do arquivo “/var/log/lastlog”. Caso o usuario nao tenha feito
login é mostrada a mensagem “** Never logged in **”

– Exibe somente os usuarios que se conectaram ao sistema nos últimos DIAS
lastlog -t DIAS

– Exibe somente detalhes sobre o usuário NOME
lastlog -u NOME
4.25 – comando chage = altera uma senha que tenha um tempo de expiração.
Serve para dar permissões de login temporario para usuários, cancelar usuá-
rio entre outros

– Criei um usuario temporario, e quero que em primeiro plano, ele tenha
direito somente a 2 dias mais de uso do sistema. Como acabei de criar,
veja as permissões
chage -l temporario

Minimum: 0
Maximum: 99999
Warning: 7
Inactive: -1
Last Change: Apr 06, 2004
Password Expires: Never
Password Inactive: Never
Account Expires: Never

Para alterar estas informações:
chage -E 2004-04-08 temporario

Onde usuariamos ano-mes-dia que a senha irá expirar (apos isso o usuário não
loga mais na máquina. Digite:
chage -l temporario

Minimum: 0
Maximum: 0
Warning: 7
Inactive: -1
Last Change: Apr 06, 2004
Password Expires: Never
Password Inactive: Never
Account Expires: Apr 08, 2004

Veja que a conta expira em 8 de abril de 2004. Vamos bloquear agora um
usuario para ele nao logar mais:
chage -E 2004-04-05 temporario

Isso quer dizer, coloque uma data ja ultrapassada e veja o log no arquivo
‘/var/log/messages’ quando tento logar

Apr 6 02:03:12 queen sshd(pam_unix)[18539]: account temporario has expired (account expired)
Apr 6 02:03:12 queen sshd[18539]: PAM rejected by account configuration[13]: User account has expired
Apr 6 02:03:12 queen sshd[18539]: Failed password for temporario from XX.XX.XX.XX port 4239
– Informa (-m) o minimo de dias em que a senha deve permacer até uma nova
troca, (-E) a data de expiracao da senha, (-I) o número de dias antes do
bloqueio da conta em que esta ficara inativa, (-W) o número de dias antes
do bloqueio da conta em que o usuario receberá avisos e ‘jonas’ o nome do
usuário para aplicar estar configuracoes
chage -m 0 -E 2003-10-31 -I 7 -W 7 jonas

– Outro comando:
chage -m mindays -M maxdays -d lastday -I inactive -E expiredate -W warndays user

#######################################################################

5 – COMANDOS DE PROCESSOS DO GNU/LINUX

5.1 – comando top = exibe uma listagem das atividades de processamento em
tempo real. Ele lista as tarefas que usam mais intensamente a CPU e pode
disponibilizar uma interface interativa de manipulação de processos. Ele
pode ordenar os processos por usa de CPU, de memória e tempo de execução.
A listagem é atualizada, por padrão, a cada 5 segundos, mas isso pode ser
alterado através da opção -d na linha de comando ou -s para o comando
interativo.

– Especifica 2 segundos do tempo entre as atualizações das telas
top -d 2

– Atualiza a tela sem qualquer espera
top -q

– Indica que top deve ser executado em modo seguro, desabilitando
possíveis perigos do modo interativo. É elegante executar um top seguro
permanentemente em um terminal extra
top -s

– Inicia top ignorando qualquer processo inativo ou zumbi. Veja o
comando interativo i abaixo
top -i

– Altera o número de linhas que serao exibidas no monitor
top -n numero

– Semelhante ao comando kill, para terminar um processo
top -k numero-PID
5.2 – comando ps = exibe o status sobre os processos ativos

– Exibe informações sobre os processos de outros usuários
ps -a

– Exibe informações em um formato extenso
ps -l

– Exibe informações sobre o PID, tty dos comandos que estao rodando
ps -e

– Exibe informações se algum programa esta rodando
ps -ef | grep programa

– Exibe apenas os processos que estao em execução
ps -r

– Exibe os processos em execução no terminal 1
ps -t1

– Exibe os processos em execução no terminal 2
ps -t2

– Exibe um melhor metodo de visualização dos processos
ps -auxw

– Exibe o processo que está consumindo mais memória
ps -auxw | sort +4n

– Exibe o processo que está consumindo mais memória
ps -auxw | sort +5n

– Exibe os usuarios logados na maquina via FTP
ps -auxw | grep ftp

– Exibe uma lista de todos os processos
ps auxw | grep root

– Exibe o processo está usando mais CPU
ps -auxwww | sed ‘1d’ | sort -r +3 | head

– Checa se o serviço ‘apache2’ está rodando, se estiver, ele é reiniciado
ps ax | grep apache2 || /etc/init.d/apache2 restart

– Usando o parâmetro ‘-ef’ surgem oito colunas
1. Coluna UID: identifica a ID do dono do processo
2. Coluna PID: identifica o numero ID do processo
3. Coluna PPID: identifica o processo pai
4. Coluna C: indica a quantidade de utilização do processador para
escalamento
5. Coluna STIME: indica a hora que o processo foi iniciado
6. Coluna TTY: indica o terminal de controla associado ao processo
7. Coluna TIME: tempo total da execução que o processo acumulou
8. Coluna COMMAND: descreve o nome do processo indicando qual
comando esta sendo executado
5.3 – comando kill = finaliza um ou mais processos em execução

Opções:
-l = exibe os sinais (números e nomes) que podem ser enviados
-s = especifica o sinal a ser enviado. O sinal pode ser informado
como um dígito ou como um número

– Tenta finalizar o programa com o número do processo (PID)
kill numero_do_pid

– Finaliza o programa com o número do processo (PID)
kill -9 numero_do_pid

– Censura um determinado usuário
kill -9 `ps -aef | grep luser | awk `{ print $2 }’`

– Para desconectar um usuário:
pkill -u uid_do_usuario
5.4 – comando killall = envia um sinal a todos os processos que estão
compartilhando um nome de processo comum entre eles.

– Finaliza todos os processos envolvendo tal programa
killall -9 programa

– Exibe os sinais (numeros e nomes) que podem ser enviados
killall -l

– Força o programa a enviar o sinal apenas para as combinações exatas
de nomes de processo maiores do que 15 caracteres
killall -e processo

– Solicita configuração antes de enviar o sinal para cada processo
killall -i processo

– – Reinicia o serviço ‘httpd’
killall -HUP httpd

– Reinicia o servico ‘syslogd’
killall -HUP syslogd
5.5 – comando jobs = exibe a lista de processos em execução pelo shell
jobs

jobs -l
5.6 – comando pstree = exibe os processos em forma de uma árvore
pstree

– Exibe toda estrutura inclusive de sub-processos do processo pai
pstree -c

– Exibe caracteres graficos no desenho da árvore de processos
pstree -G

– Exibe e classifica pelo numero PID ao invés do nome
pstree -n

– Exibe o número PID entre parenteses após o nome do processo
pstree -p
5.7 – comando fg = permite que um programa rodando em segundo plano
(background) rode em primeiro plano (foreground). Você deve usar o
comando ‘jobs’ para pegar o número do processo rodando em segundo
plano ou interrompida, este número será passado ao comando ‘fg’
para ativa-lo em primeiro plano.

fg numero

Onde ‘numero’ é o número obtido através do comando ‘jobs’. Caso seja
usado sem parâmetros, o comando ‘fg’ utilizará o último programa
interrompido (o maior número obtido com o comando ‘jobs’). EX:
fg 1
5.8 – comando bg = permite que um programa rodando em primeiro plano
(foreground) rode em segundo plano (background). Você deve interromper
a execução do programa teclando CTRL+Z. Será mostrado o número da tarefa
interrompida. Utilize este número com o comando ‘bg’ para iniciar a
execução do programa em segundo plano (background).
bg numero

Onde ‘numero’ é o número do programa obtido com o pressionamento das
teclas CTRL+Z ou através do comando ‘jobs’
5.9 – comando nohup = executa um comando imune a interrupcoes de conexão
com a saída para um dispositivo nao tty, ou seja, deixa o programa em
background apos efetuar logoff.

– Deixa um programa rodando em background mesmo depois de ter efetuado
logoff
nohup ./programa &

– Evita que o comando caia se você for dar um logout, isso irá gerar
um arquivo ‘nohup.out’ com as saidas
nohup tar cvf /dev/st0 /arquivos/* &

#######################################################################

6 – COMANDOS DE CONFIGURACAO DO GNU/LINUX

– OBS: ALguns comandos funcionam apenas no Debian e seus derivados
(Ubuntu, Kurumin, Knoppix etc) e outros funcionam apenas no RedHat,
Fedora, Conectiva.

– Configura a interface gráfica:
wmchooser
* ou altere o arquivo ~/.wm_style e coloque o nome da interface gráfica
que voce quer inicializar. Ex: (windowmaker, gnome, kde)

– Configurar teclado:
kbdconfig

– Configurar mouse:
mouseconfig

– Configura placa de som
sndconfig
sndconfig –noprobe
sndconfig –noautoconfig

– Configurar uma placa de fax-modem
modemconf

– Configura placa de vídeo
Xconfigurator
Xconfigurator –expert
xf86config
XFree86setup
xf86cfg

– Configura rede
netconfig
ou
netconf

– Configuração do fuso horario
timeconfig

– Configura os serviços que inicializam automaticamente
ntsysv
chkconfig

– Para configurar o WindowMaker, digite:
wmakerconf &

– Para configurar um wallpaper (papel de parede) digite:
Esetroot /nome-da-imagem.jpg
ou
wmsetbg /nome-da-imagem.jpg
– Status da placa de dispositivos (eth0, eth1, ppp, lo)
ifconfig

– Desligar/parar a primeira placa de rede
ifdown eth0

– Ligar/iniciar a primeira placa de rede
ifup eth0

– Lista os módulos carregados no sistema
lsmod

– Carregando modulos / instalando modulos no kernel:
modprobe nome_do_modulo.o
ou
modprobe nome_do_modulo

– Exibe informações de configuração do módulo
modprobe -c nome_do_modulo

– Desativa o modulo1 do kernel
modprobe -r nome_do_modulo

– Exibe todos os módulos
modprobe -l

– Descarrega módulos carregados no kernel linux:
rmmod nome_do_modulo.o
ou
rmmod nome_do_modulo

– Remove todos os módulos não usados
rmmod -a nome_do_modulo

– Envia toda a saída para o log do sistema
rmmod -s nome_do_modulo
6.1 – comando linux_logo = configura o slogan(desenho) em texto do pinguim

– Exibe o desenho padrao em cores no terminal
linux_logo

– Exibe as diversas opções do linux_logo
linux_logo -h

– Configura o arquivo ‘/etc/issue’ para armazenar o desenho do linux_logo
em sua forma texto com cores
linux_logo -classic >> /etc/issue

– Configura o arquivo ‘/etc/issue’ para armazenar o desenho do linux_logo
em sua forma texto sem cores
linux_logo -ascii >> /etc/issue
6.2 – comando setserial = exibe e configura portas seriais

– Para exibir as configurações referentes ao modem na COM2:
setserial /dev/ttyS1

– Para exibir informacoes referetes a porta COM2:
setserial -a /dev/ttyS1

– Para configurar a porta COM2 para usar a IRQ 4:
setserial /dev/ttyS1 irq 4

– Para tentar uma configuração automática
setserial /dev/modem autoconfig

– Outras configurações
setserial /dev/ttyS1 irq 5 uart 16550a port 0x03e8
setserial /dev/ttyS1 irq 11 port 0x6200 autoconfig
setserial /dev/ttyS1 irq 10 port 0xdc00 uart 16550a
6.3 – comando statserial = exibe o status de uma porta serial, exibindo
os sinais nos pinos da porta e o status da linha de handshaking

– Exibe o status da porta como um numero decimal
statserial -d dispositivo

– Desativa o loop e xibe apenas um status
statserial -n dispositivo

– Exibe o status da porta como um número hexadecimal
statserial -x dispositivo
6.4 – comando ntpdate = sincroniza o horário do PC atual com um servidor
da Internet
ntpdate ntp.pop-df.rnp.br || ntpdate ntp.nml.csiro.au &
6.5 comando sysctl = configura parametros do kernel em tempo real, sem
a necessidade de reinicialização do computador

– Exibe todas opções em que o usuário pode alterar, modificar
sysctl -A

#######################################################################

7 – COMANDOS DE IMPRESSAO

7.1 – comando lpd = executa o daemon de spooler da impressora para
controlar a impressao nas impressoras locais e remotas.

– Registra os pedidos de de impressão em rede válidos
lpd -l porta
7.2 – comando lpr = é utilizado para enviar um arquivo para a impressora.

– Imprime o ‘teste1.txt’ na impressora padrão
lpr teste1.txt

– Envia o arquivo ‘teste1.txt’ para a impressão na impressora em que for
citada no comando
lpr -P nome-da-impressora teste1.txt

– Especifica o número de 3 copias do arquivo para a impressão
lpr -K 3 nome-do-arquivo

– Envia um email com o status que a impressão foi concluida com sucesso
lpr -m mjordan nome-do-arquivo

– Imprime o nome da tarefa especificada em vez do nome do arquivo na página
de cabeçalho
lpr -J nome-da-tarefa arquivo1.txt

– Permite que os caracteres de controle sejam impressos enquanto suprime
quebras de linha
lpr -l arquivo1.txt
7.3 – comando lpq = exibe o status corrente de uma fila de spool de impressora
lpq

– Exibe todas as informacoes sobre os arquivos que compoem a entrada
da tarefa, em vez de apenas o que caberá em uma linha
lpq -l

– Consulta a impressora especificada
lpq -P nome-da-impressora
7.4 – comando lprm = remove da fila de impressao arquivos que ainda não
foram impressos
lprm numero-do-arquivo-na-fila-de-impressao

lprm -P nome-da-impressora numero-do-arquivo-na-fila-de-impressao

– Remove todos os arquivos de spoll na fila de impressão
lprm -a all

– Remove os arquivos de spool na fila de impressão com do usuário com a
identificacao ‘user@maquina23’
lprm -Pt1 ‘user@maquina23*
7.5 – comando lpstat = exibe informações sobre o status do serviço
de impressão
lpstat -v
7.6 – comando pr = formata arquivos texto para serem impressos.

– Formata o arquivo ‘teste1.txt’ para impressão especificando o número
máximo de 50 linhas por página, o nome “Teste do comando pr” ao invés
do nome do arquivo sendo impresso no cabeçalho da página
pr -l 50 -h “Teste do comando pr” teste1.txt

#######################################################################

8 – COMANDOS DE REDE

CAMINHOS IMPORTANTES – DEBIAN
—————————–
– Configuração das interfaces de rede:
/etc/network/interfaces

– Configuração do host name, roda padrão e do gateway:
/etc/network/interfaces

– Configuração das rotas estáticas:
/etc/network/interfaces

CAMINHOS IMPORTANTES – REDHAT / FEDORA
————————————–
– Configuração das interfaces de rede:
/etc/sysconfig/network-scripts/ifcfg-*

– Configuração do host name, roda padrão e do gateway:
/etc/sysconfig/network

– Configuração das rotas estáticas:
/etc/sysconfig/static-routes

8.1 – comando ping = verifica se uma maquina da rede esta disponível na rede
enviando pacotes ICMP ECHO_REQUEST para as maquinas da rede. Este comando
envia requisições ICMP de ECHO REQUEST e fica escutando pelos pacotes ICMP
de ECHO REPLY.

O maior pacote ICMP que a especificação TCP/IP admite é de 65.535 bytes.
No Windows ele é limitado em 65.000 bytes pelo utilitário ping… já no
GNU/Linux o ping permite que esse pacote chegue a 65.467 bytes. Mesmo
assim se você fizer um programa que envie pacotes maiores que esses 64k
através do protocolo ICMP, esses pacotes não podem passar pela Internet
inteiros, assim, são fragmentados antes da transmissão. Quando o host
destino recebe os fragmentos, ele os re-agrupa no seu tamanho original.
Nos sistemas operacionais mais antigos isso era conhecido como Ping da
Morte, pois o sistema se perdia quando o buffer no qual o pacote foi
armazenado estourava. Atualmente, a maioria dos roteadores filtram esses
pacotes grandes. Utilização correta do parâmetro para definir um tamanho
de pacote com o ping.

Sua utilização correta no caso GNU/Linux
ping -s 65467 endereco_ip

Sua utilização correta no caso Windows
ping -l 65000 endereco_ip

Obs: O parâmetro -f tem sentido diferente nas duas plataformas. No GNU/Linux
é utilizado para inundação de pings. Envia pacotes rapidamente à medida que
eles voltam ou cem vezes por segundo, dependendo de qual é o mais rápido.
Para cada ECHO_REQUEST enviado um período um ponto ‘.’ é mostrado, enquanto
que para cada ECHO_REPLY recebido um backspace é mostrado. Isto proporciona
uma rápida visualização de quantos pacotes estão sendo enviados. Somente o
usuário root pode usar esta opção. Seu equivalente no Windows é o parâmetro
‘-t’. No Windows o parâmetro ‘-f’ é utilizado para definir um sinalizador de
‘Não fragmentar’ no pacote.

– Testa a interface local está funcionando
ping 127.0.0.1

– Testa se a máquina ‘www.ederjordam.com.br’ está funcionando
ping http://www.ederjordam.com.br

– Verifica se a maquina cujo o IP é 200.251.9.8 está conectada na rede
ping 200.251.9.8

– Envia 5 pacotes ICMP para a maquina cuja o numero IP é 127.0.0.1 (endereço
de loopback) e depois termina
ping -c 5 127.0.0.1

– Envia pacotes ICMP com a mesma rapidez com que eles voltam ou 100 vezes
por segundo
ping -d 127.0.0.1

– Especifica 3 segundos para se esperar entre o envio de cada pacote ICMP
ping -i 3 127.0.0.1

– – Registra a rota que os pacotes tomam e apresenta o buffer de rota de
pacotes que retornaram
ping -R 127.0.0.1

– Envia novos pacotes antes de receber a resposta do pacote anterior. Para
cada requisicao enviada, um ‘.’ é exibido na tela e para cada resposta
recebida, um backspace é exibido. Somente o usuário root pode utilizar esta
opção e pode auxiliar na detecção de erros de transmissão de pacotes em
interfaces das máquinas na sua rede
ping -f 192.168.0.1

– Especifica o tamanho do pacote que sera enviado à maquina (máximo de
65467) cujo endereco IP é 192.168.0.1
ping -s TAMANHO 192.168.0.1

– Exibe maiores detalhes sobre os pacotes enviados e recebidos do host
atual para o host cujo IP é 192.168.0.1
ping -v 192.168.0.1

– Para testar o ping da morte
ping -f -s 65467 endereco_ip
ou
ping -f -s 65467 dominio

– Infelizmente serve para ‘derrubar’ um host na rede. É necessário que
se usem várias máquinas ao mesmo tempo. Os nº 1000, 99999 podem ser
substituidos, no comando, estam na “forma maxima” e w0 significa que os
pacotes são enviados ininterruptamente
ping -c 1000 -s 99999 -w0 IP/dominio

– Efetua um ping na maquina cujo IP é 192.168.0.1 e diminui a taxa de
pings de 1 para 2 segundos
ping -i 2 192.168.0.1

– Resto da rede, é só você usar a interface de rede (ethernet – eth0,
eth1 etc)
ping -I eth0 nome_da_minha_maquina

– Exibe a rota que os pacotes ICMP fazem, tanto na ida quando na volta
(parâmetro ‘-R’) e pingando apenas uma vez (parâmetro ‘-c 1’):
ping -c 1 -R http://www.acessa.com.br

PING http://www.acessa.com (200.251.55.60) 56(124) bytes of data.
64 bytes from http://www.acessa.com (200.251.55.60): icmp_seq=0 ttl=249 time=37.8 ms
RR: 10.1.67.21
200-251-136-67.powerline.com.br (200.251.136.67)
192.168.174.2
cyclades.powerline.com.br (200.251.137.1)
200.251.218.149
rt01-jf.artnet.com.br (200.251.55.51)
http://www.acessa.com (200.251.55.60)
artnet-S4-0-2-acc02.bhe.embratel.net.br (200.251.142.254)
embratel-S0-1-0-acc02.bhe.embratel.net.br (200.251.254.173)

— http://www.acessa.com ping statistics —
1 packets transmitted, 1 received, 0% packet loss, time 0ms
rtt min/avg/max/mdev = 37.827/37.827/37.827/0.000 ms, pipe 2
8.2 – comando dnsquery = consulta os servidores DNS para pesquisar
informações sobre um host especifico.
dnsquery dominio.com.br
– Especifica o nome do servidor a ser usado para a consulta
dnsquery -n nome-do-servidor

– Procura as troca de correio do dominio
dnsquery -t MX nome-do-servidor

– Procura o inicio do registro de autoridade do host
dnsquery -t SOA nome-do-servidor
8.3 – comando nslookup = consulta o servidor de nomes DNS. Resolve o
endereçamento IP/nome atraves do DNS usado
nslookup 200.251.142.1

nslookup numero_ip

nslookup dominio.com.br
nslookup -silent numero_ip

– Exibe informacoes sobre o registro de autoridade do host
nslookup -type=SOA numero_ip

– Exibe informações sobre o servidor DNS do referido numero IP
nslookup -type=NS numero_ip
8.4 – comando dig = DNS lookup utility
dig

dig dominio.com.br
– Exibe a versão do DNS do dominio
dig @ns.dominio.co.br version.bind chaos txt

– Exibe se o servidor DNS acessível e se ele responde a consultas de nomes
dig @endereço_IP_de_um_dos_DNS http://www.dominio.com.br

– Informa o servidor POP e SMTP do dominio
dig MX dominio.com.br
– Exibe o domínio associado à este endereço IP
dig -x endereco_ip

– Estou com meu DNS instalado em um CL6 aparentemente ele funciona muito bem
mas infelizmente ele está falhando em resover alguns endereços, como por ex:
rufus.w3.org e sys.com.tw dentre outros.

Adianto a voce que as requisições para os 2 domínios acima citados não são
realmente “resolvidos” pelo seu DNS, pois ele não é autoritativo para os
respectivos domínios. Eles devem ser resolvidos por servidores de nomes que
possuem autoridade sobre o domínio e esta informação retornada para sua
máquina, por ex:
dig @rufusw3.org
;;Query time: 694 msec
;;SERVER: 18.29.1.67#53(rufus.w3.org)
;;WHEN: Tue MAy 14 12:44:21 2002
;;MSG SIZE rcvd: 292

Seria útil conhecer a saída do comando dig para seu próprio domínio,
como:
dig seudominio NS
8.5 – comando host = DNS lookup utility
host
host dominio.com.br
– Onde ‘dns1’ é o nome ou o IP dos servidores que você fornece no
cadastramento na Fapesp
host -t SOA dns1

– Onde ‘dns2’ é o nome ou o IP dos servidores que você fornece no
cadastramento na Fapesp
host -t SOA dns2

– Testa se o DNS consegue resolver nomes de dominio
host -v http://www.dominio.com.br

– Testa se o DNS consegue resolver nomes de dominio
host -v 223.5.6.7

host -t mx schwartzsolutions.eti.br
schwartzsolutions.eti.br mail is handled by 5 mail.
schwartzsolutions.eti.br mail is handled by 10 mx-sec.terraempresas.com.br.

Como não existe uma máquina ‘mail’ aqui, meu MTA também encaminharia para
mx-sec.terraempresas.com.br… Aí, o mx-sec.terraempresas.com.br receberia
a mensagem e ao enviar para você, ele veria que também não existe uma máquina
‘mail’ e enviaria para ele mesmo. Oops! Temos um loop!
8.6 – comando ifconfig = é usado para configurar e manter as interfaces
de rede. Sintaxe:
ifconfig interface options address
ifconfig interface opções endereço

interface = especifica o nome da interface
eth0 : primeira placa de rede no sistema
eth1 : segunda placa de rede no sistema
eth2 : terceira placa de rede no sistema

options = algumas opcoes do comando ifconfig
up : ativa a interface especificada
down : desativa a interface especificada
netmask address : define a mascara de rede da interface especificada
broadcast address : define o end. de broadcast da inteface especificada
pointtopoint address : ativa o modo ponto a ponto da interface especificada,
implicando um link direto entre 2 maquinas

address = especifica o nome da maquina e o endereco IP da interface

– Exibe as interfaces de rede ativas
ifconfig

– Se a interface ‘lo’ (loopback) não estiver ativa, digitando o comando
ela irá se ativar
ifconfig lo 127.0.0.1 up

– Exibe informações sobre a primeira placa de rede, a eth0
ifconfig eth0

– Exibe informações sobre a segunda placa de rede, a eth1
ifconfig eth1

– Ativa a interface eth0 (1º placa de rede)
ifconfig eth0 up

– Desativa a interface eth0 (1º placa de rede)
ifconfig eth0 down

– Configura o endereço IP 192.168.0.1 e a máscara de rede 255.255.255.0
para a interface eht0 e depois a ative com o parametro up
ifconfig eth0 192.168.0.1 netmask 255.255.255.0 up

– Configura a primeira placa de rede (eth0) com número IP 192.168.0.2,
mascara de rede 255.255.255.0 e o broadcast da rede como 192.168.0.255
ifconfig eth0 192.168.0.2 netmask 255.255.255.0 broadcast 192.168.0.255

– Configura a segunda placa de rede (eth1) com número IP 192.168.0.4,
mascara de rede 255.255.255.0 e o broadcast da rede como 192.168.0.255
ifconfig eth1 192.168.0.4 netmask 255.255.255.0 broadcast 192.168.0.255

– Exibe o endereço IP da interface ppp0
ifconfig | grep P-a-P | awk ‘{print $3}’
ou
ifconfig ppp0 | grep ‘inet end’ | awk ‘{print$3}’

– Exibe o endereço IP da interface eth0
ifconfig eth0 | awk ‘/inet addr/ { sub(/inet addr:/, “”); print $1}
ou
ifconfig eth0 | grep inet | cut -d : -f2 | cut -d ” ” -f2

– Para descobrir o endereço MAC da interface eth0
ifconfig eth0

eth0 Encapsulamento do Link: Ethernet Endereço de HW 48:54:E8:28:42:EA
inet end.: 192.168.1.200 Bcast:192.168.1.255 Masc:255.255.255.0
UP BROADCASTRUNNING MULTICAST MTU:1500 Métrica:1
Pacotes RX:26179 erros:0 descartados:0 sobreposições:0 frame:0
Pacotes TX:25316 erros:0 descartados:0 sobreposições:0 portadora:0
colisões:4 txqueuelen:100
IRQ:11 Endereço de E/S:0xdd80

Repare na primeira linha: HW 48:54:E8:28:42:EA

– Atribuindo vários IPs em uma única placa de rede para criar aliases para
a interface de rede:
ifconfig eth0:0 192.168.2.200 netmask 255.255.255 broadcast 192.168.2.255

– Para atribuir mais IPs só mude o número após o “:” (eth0:1,
eth0:2 e assim por diante) Agora você têm dois ou mais IP’s em uma
placa de rede. Muito útil pra quem deseja hospedar vários sites.

– Exibe as interfaces de redes que estão ativas
ifconfig -a

– Cria a interface de loopback caso a mesma não esteja aparecendo com
o comando ‘ifconfig -a’
ifconfig lo 127.0.0.1 netmask 255.0.0.0

– Para configurar o MTU de uma interface de rede
ifconfig eth0 mtu 1440

– Para configurar uma placa de rede com uma conexão ponto-a-ponto
ifconfig eth0 192.168.2.1 netmask 255.255.255.255 pointopoint 192.168.2.2

– Para colocar uma interface de rede em modo promíscuo (a interface aceitará
pacotes destinados a qualquer IP) inserguro!
ifconfig eth0 promisc

– Para retirar uma interface de rede em modo promíscuo (a interface aceitará
pacotes destinados a qualquer IP) seguro!
ifconfig eth0 -promisc

– Para alterar o endereço MAC de uma placa de rede (OBS: ela deverá estar
desabilitada. OBS2: Assim que voce reiniciar o PC, o endereço MAC original
será configurado novamente) digite os seguintes comandos
ifconfig eth0 down
ifconfig eth0 hw ether 00:11:22:33:44:55
ifconfig eth0 up
8.7 – comando ifup = inicia/ativa uma interface de rede

– Inicia/ativa a primeira placa de rede
ifup eth0

– Inicia/ativa o primeiro dispositivo PPP
ifup ppp0
8.8 – comando ifdown = paraliza/desativa uma interface especificada

– Paraliza/desativa a primeira placa de rede
ifdown eth0

– Paraliza/desativa o primeiro dispositivo PPP
ifdown ppp0
8.9 – comando ifport = define o tipo de transceptor para uma interface
de rede especificada. Sintaxe:
ifport interface type

interface = especifica o nome da interface
eth0 : primeira placa de rede no sistema
eth1 : segunda placa de rede no sistema
eth2 : terceira placa de rede no sistema

type = especifica o tipo de transceptor.
auto : selecao automatica
10baseT : par trancado ethernet
10base2 : cabo coaxial ethernet
aui : interface AUI ethernet
100baseT : par trancado fash ethernet
8.10 – comando traceroute = exibe a rota/caminho percorrido da máquina
local até o host de destino/endereço IP. Ao contrário do comando
‘ping -R endereco_ip’, o comando traceroute resolve os nomes (podendo-se
desabilitar esta opção com o parâmetro ‘-n’) e é capaz de traçar uma rota
mesmo que o host não exista ou esteja inacessível. Obviamente o comando
somente irá traçar a rota até que um roteador responda com um ‘unreacheable’
ou até o TTL expirar. Exibe a rota tomada pelos pacotes para uma maquina da
rede. Este comando mostra na tela o caminho percorrido entre os gateways da
rede e o tempo gasto de retransmissão. É é útil para encontrar computadores
defeituosos na rede caso o pacote não esteja chegando ao seu destino. A
Internet é uma grande e complexa aglomeração de máquinas de rede conectadas
por gateways. Traçar a rota que um pacote segue (ou achar o gateway que está
descartando os seus pacotes) pode ser difícil. O traceroute utiliza o campo
‘time to live’ do protocolo IP e tenta obter uma resposta ICMP TIME_EXCEEDED
de cada gateway no caminho para alguma máquina. O único parâmetro obrigatório
é o nome da máquina de destino ou o seu número IP. O tamanho pré-definido do
datagrama de procura é de 38 bytes, mas isto pode ser aumentado especificando
um tamanho de pacote(em bytes) depois do nome da máquina de destino.

– Traça a rota/caminho entre a sua conexão e a origem do host
traceroute numero_ip
ou
traceroute nome_da_maquina
ou
traceroute http://www.dominio.com.br

– Exibe o valor ttl dos pacotes retornados, ou seja, exibe o tempo de vida do
pacote (ttl). Isto é útil para verificar roteamento assimétrico
traceroute -l 192.168.0.1

– Ajusta a quantidade máximas de ttl dos pacotes. O padrão é 30
traceroute -m NUMERO 192.168.0.1

– Exibe os endereços dos pontos numericamente ao invés de usar resolucao DNS
(simbolicamente e numericamente, evita uma procura endereço-para-nome em um
servidor de nomes para cada gateway encontrado no caminho)
traceroute -n 192.168.0.1

– Ajusta a porta que sera usada para o teste. A porta padrão é 33434
traceroute -p PORTA 192.168.0.1

– Ignora as tabelas de roteamento normais e envia diretamente para uma máquina
em uma rede anexa. Se a máquina não estiver em uma rede diretamente anexa, um
erro é retornado
traceroute -r 192.168.0.1

– Utiliza o seguinte endereço IP (que deve ser dado como número, não como nome
de máquina) como o endereço de origem nos pacotes de procura
traceroute -s end_origem

– Exibe mais detalhes sobre o resultado do comando traceroute
traceroute -v 192.168.0.1

– Configura o tempo maximo que aguardará por uma resposta (padrão: 3 segundos)
traceroute -w NUMERO 192.168.0.1

– Define o campo type-of-service nos pacotes de procura para o valor seguinte
(pré-definido como zero). O valor deve ser um inteiro decimal no alcance de
0 a 255. Esta opção pode ser usada para descobrir se diferentes type-of-
service resultam em diferentes caminhos
traceroute -t serviço 192.168.0.1
8.11 – comando tracepath = similar ao comando traceroute, com a diferença de
exibir o PMTU do caminho.
tracepath http://www.acessa.com

1: 10.1.67.21 (10.1.67.21) 0.545ms pmtu 1500
1: 10.1.67.1 (10.1.67.1) 1.166ms
2: 10.201.0.1 (10.201.0.1) 19.960ms
3: 192.168.175.2 (192.168.175.2) 16.118ms
4: 192.168.174.1 (192.168.174.1) 35.672ms
5: embratel-S0-1-2-acc02.bhe.embratel.net.br (200.251.247.41) 65.802ms
6: 200.251.220.214 (200.251.220.214) 37.473ms
7: http://www.acessa.com (200.251.55.60) 39.746ms reached
Resume: pmtu 1500 hops 7 back 7
8.12 – comando route = exibe/manipula a tabela de roteamento IP

– Exibe a tabela de roteamento IP do kernel
route

– Exibe a tabela de roteamento IP do kernel (mas não resolve os possíveis nomes
de máquinas existentes na rede)
route -n

– Sintaxe para adicionar uma rota
route add [ -net | -host ] target [ netmask Nm ] [ gw Gw ] [[ dev ] If ]

– Adiciona a rota default(padrão)
route add default gw 192.168.1.200

– Adiciona a rota padrao para a interface ppp0
route add default ppp0

– Adiciona e indica que o destino é uma rede esta sendo adicionada
route add -net

– Adiciona e indica que o destino é um host esta sendo adicionada
route add -host

– Adiciona uma rota para uma rede
route add -net 192.168.5.0 netmask 255.255.255.0 gw 192.168.1.3

– Adiciona uma rota para um host utilizando uma interface ponto-a-ponto
route add -net 192.168.10.1 dev ppp0

– Adiciona uma rota para a rede 192.168.1 acessível através da interface eth0
route add -net 192.168.1.0 eth0

– Adiciona e diz que o host 127.0.0.1 (host local, máquina local) deve ser
acessado através do dispositivo lo
route add -host 127.0.0.1 lo

– Adiciona/configura o linux para enviar todas as informações da rede local
para a interface eth0 que está configurada com o IP 192.168.0.1 e máscara
de rede 255.255.255.0
route add -net 192.168.0.1 netmask 255.255.255.0 eth0

– Adiciona/configura o linux para especificar o gateway padrão que pode ser
usado para acessar redes remotas. O gateway padrão está no IP 192.168.0.0 e
pode ser acessado enviando-se informações destinadas a ele através da
interface eth0
route add default gw 192.168.0.0 eth0

– Adiciona uma rota para a rede 192.56.76.x atraves da interface eth0
route add -net 192.56.76.0 netmask 255.255.255.0 eth0

– Adiciona a rede 192.57.66.x para ser alcancada atraves da rota anterior
atraves da interface SLIP
route add -net 192.57.66.0 netmask 255.255.255.0 gw ipx4

– Adiciona/configura para que todas as rotas IP classe D (multicast) vão
atraves da interface eth0. Esta e a linha de configuracao normal a ser usada
com um kernel multicast
route add -net 224.0.0.0 netmask 240.0.0.0 dev eth0

– Adiciona/configura uma rota de rejeicao para a rede privada 10.x.x.x
route add 10.0.0.0 netmask 255.0.0.0 reject

– Para adicionar uma rota padrão a um endereço que não se encontre na tabela
de roteamento utiliza-se o “gateway padrão da rede”. Através do gateway padrão
é possível especificar um computador (normalmente outro gateway) que os
pacotes de rede serão enviados caso o endereço não confira com os da tabela
de roteamento. No comando, foi especificado o PC 192.168.1.1 como “gateway
padrão”
route add default gw 192.168.1.1 eth0

– Sintaxe para deletar uma rota:
route del [ -net | -host ] target [ netmask Nm ] [ gw Gw ] [[ dev ] If ]

– Deleta a rota padrão
route del default

– Indica que o destino é uma rede esta sendo excluida
route del -net

– Indica que o destino é um host esta sendo excluida
route del -host

– Deleta a rota para a rede 192.168.1.0 acessível através da interface eth0
route del -net 192.168.1.0 eth0

– Este comando diz que o host 127.0.0.1 (host local, máquina local) deve ser
excluida através do dispositivo lo
route del -host 127.0.0.1 lo
8.13 – comando ipfw = IP firewall administration padrao no kernel 2.0.x
8.14 – comando ipchains = IP firewall administration padrao no kernel 2.2.x
O ipchains fornece 3 built-in-chains. Todos os pacotes começam com uma dessas
chains e,dependendo das regras, pode terminar passando por todas as 3.

input = pacotes chegando através de um network device na sua máquina de uma
origem externa. Pacotes gerados localmente vêm sempre do loopback device ou
‘lo’.

forward = pacotes que apenas estão passando pela sua máquina ou redire-
cionados. Se tanto o destino quanto a origem do pacote são remotos o pacote
é enviado para o forwarding firewall.

output = pacotes deixando a sua máquina sob um network device para uma origem
externa. Ou, se enviado para o loopback device, o pacote reaparece na chain de
input.

– Criando e destruindo chains
Chain (ou corrente em português) especifica o nome da chain. Pode ter até 8
letras de comprimento e, para previnir conflitos com possíveis buit-in target
names futuros, deve conter pelo menos 1 letra minúscula.

-N Chain = cria uma nova chain definida pelo usuário.

-X [chain] = deleta uma chain vazia definida pelo usuário, ou todas as chains
definidas pelo usuário. Todas as regras referentes a uma chain definida pelo
usuário deve ser deletada antes da chain definida pelo usuário.

– Adicionando ou removendo regras
-v (verbose) = quando usado com o seguinte grupo de comandos, irá fazer com
que a regra seja ecoada para o stdout.

[Regra], como especificada na linha de comando, consiste em nenhum ou mais
predicados seguidos por nenhuma ou mais ações. Predicados e ações estao
listados a seguir.

[Indice] é usado para especificar uma regra de acordo com a sua posição na
chain. A primeira regra numa chain tem o índice 1.

-A [-v] [Regra] = adiciona uma regra a chain

-D [-v] [Indice] = deleta uma regra na chain pela posição [Indice].

-D [-v] [Regra] = deleta primeira regra na chain que contenha a [Regra].

-F [chain] = descarta todas as regras da chain (ou todas as chains).
Equivalente a deletar todas as regras uma a uma.

-I [-v] [Indice Regra] = insere [Regra] na chain precedendo a regra de índice
[Indice]. Portanto, se o índice e 1, a regra inserida fica sendo a primeira
regra na chain.

-R [-v] [Indice regra] = substitui (replace) a regra no índice [Indice] na
chain com a regra [Regra].

– Targets (Alvos)
Cada regra tem um alvo que determina o que fazer com um pacote quando
enquadrado. Se um pacote chega ao final de uma chain sem se enquadrar em
nenhuma das regras, a política de target padrão (default) da chain é usada.

– Políticas
ACCEPT = permite que o pacote passe atraves do firewall

REJECT = rejeita o pacote. Se não for um pacote ICMP, envia um reply ICMP
Host Unreachable para o remetente.

DENY = não aceitar o pacote, não responder (reply). Simplesmente ignora o
remetente.

MASQ = (para chain forward apenas). Deixa o pacote passar, porém mascara ele.
Substitui o remetente do pacote pelo endereço local e substitui a porta de
origem no cabecalho com o número temporário gerado localmente.

REDIRECT = (para chain input apenas. Envia o pacote a um soquete local ou
processa. Pode ser usado com pacotes TCP e UDP em chains de input ou chains
definidas pelo usuário.

RETURN = equivalente a ignorar as demais chains, podendo chamar uma política
de target built-in ou retornar a uma chain do usuário. Seria o equivalente ao
return dentro de uma função em C.

(no target especified) O byte da regra e o contador do pacote serão incre-
mentados, porém o pacote será passado para a proxima regra na chain mesmo
se for enquadrado nessa regra. Normalmente utilizado para contabilidade.
Se um target for usado incorretamente (MASQ de uma input chain por exemplo),
o pacote será descartado e uma mensagem será enviada ao log do sistema,
syslog.

– Comandos de Masquerading
-M L [-v] Lista as coneccoes de masquerading correntes.
-v ira fazer com que as informações relecionadas
aos números da sequencia delta sejam descartadas
tambem.

-M -S tcp Configura os valores de timeout de masquerading.
tcpfin udp Os parametros especificam o timeout em segundos
para sessoes TCP (tcp), sessoes apos recepcao do
pacote FIN (tcpfin), e pacotes UDP respectivamente.
Um timeout de 0 ira manter os timeouts anteriores.
Os Defaults sao 15,2 e 5 minutos.

– Informação
-h Imprime um sumário dos comandos

-h icmp Lista nomes ICMP conhecidos a ipchains

–version Informa a versão do ipchains.

– Utilitários Chain
-P chain Troca a política de uma chain built-in para [target].
target [target] precisa ser ACCEPT, DENY, REJECT ou MASQ para
chains forward. Nenhum outro tipo de target pode ser
usado como política built-in de uma chain.

-Z [-L] Zerar o byte do pacote e os contadores na chain (ou
todas as chains).-Z pode ser usado em combinação
com -L para leitura de contadores e depois apaga-los,
assegurando que nenhum pacote não prosseguirá como
não contabilizado. No entanto, ao fazer isso, você
deve zerar todas as suas chains. você não pode
zerar automaticamente e listar uma unica chain.

-L [-vxn] Lista as regras numa chain (ou todas as chains).
[chain] -v especifica modo verbose, -x expande os números
(mostra valores sem as abreviações K, M, e G),
-n faz o ipchains imprimir IPs numericos ao inves
de fazer lookups de nomes. Pode ser usado com -Z
acima.

-C [-v] Testa um pacote numa chain. pkt e formado como se fosse
chain pkt uma regra exceto pelo fato de conter pelo menos -s, -d, -p
(precisa ter um protocolo especificado, não pode ser
generico), e a flag -i (ao menos que -f seja usado para
criar um fragmento). -v faz com que um trace do caminho
do pacote seja impresso no stdout.

– Ações
-j target Pula para (jump-to), especifica o target a ser chamado
[port] quando a regra combinar.Target pode ser uma das listas
acima, ou o nome de uma chain definida pelo usuário.
você não pode pular para uma chain built-in.
para facilitar pense assim -j [política] ou
-j [target].

-l Faz com que os pacotes que combinarem com a regra
sejam logados no syslog.Muito cuidado com isso porque
pode fazer seu arquivo de log crescer alem da capacidade
do seu disco.

-m [valor] número a marcar no pacote. Usado em conjunto com a
implementacao do Servico de Qualidade nos kernels 2.1.
Se [valor] comecar com + ou -, entao o valor será somado
ou subtraido to valor marcado no pacote, e não substituindo-o.

-o [tam maximo] Copia o pacote para o device do espaco do usuário.
[tm maximo] limita o números de bytes a serem copiados.

-t and xor Muda o bit do tipo de servico do pacote
(TOS – Type Of Service). O TOS do pacote será ANDed com and e
depois XORed com xor. Os dois parametros sao valores de 8-bits
hexadecimais.A RFC1349 especifica que o LSB do campo TOS não
pode ser alterado, portanto ipchains ira recusar qualquer
regras que violem isso.a RFC1349 tambem especifica que apenas
1 bit no campo TOS pode ser alterado por vez.Regras que
alterarem mais de 1 bit por vez serão aceitas mas um aviso será
enviado para o stdout.

– Predicados

-p [!] Especifica um protocolo. Pode ser um nome do protocolo como
protocolo TCP, UDP, ICMP ou ALL (para todos) (não importa letras
maiusculas ou minusculas), ou o número IP do protocolo sendo
0 para todos. Exemplo, 22 ou ssh podem ser usados para ssh.
A lista dos protocolos podem ser encontradas no arquivo
/etc/services.O simbolo [!] significa NOT. Ou seja ! ssh.
Para, não a SSH.

-s [!] end O endereço de origem a ser combinado ou [!] para NOT esse
endereço. -s significa SOURCE (origem). Onde [end] e o
endereço ip (address). Por exemplo 192.168.0.10.

-d [!] end O endereço de destino a ser combinado ou [!] para NOT esse
endereço. -d significa DESTINATION (destino). Onde [end] e o
endereço ip (address). Por exemplo 192.168.0.10.

Obs. Tanto o endereço -s quanto -d podem ser especificados
pelo nome (por exemplo, localhost, http://www.conectiva.com.br) ou
o IP, por exemplo 192.168.0.10. Para um endereço IP, você
pode significar o quanto da rede ou endereço e significativa
especificando a netmask. EX:
As duas notações sao validas:
192.168.0.10/255.255.255.0 ou
192.168.0.10/24 (sendo 24 equivale a uma subnet de 24 bits,
ou seja 255.255.255.0). Nessa caso estamos falando de
todos os endereços entre 192.168.0.0 ate 192.168.0.255.
Ou seja, a subnet inteira.

[[!] porta] Quando usado com protocolos TCP ou UDP, por exemplo:
-p tcp ou -p udp, uma porta ou intervalo de portas
podem ser especificados.Simplesmente especifique o número
da porta ou o nome. Por exemplo 80 ou www. Um intervalo
pode ser determinado usando um : entre a porta menor
e a porta maior. Exemplo 0:65535.

[!] -y Quando utilizado com o protocolo TCP, especifica pacotes SYN
do TCP apanes.Ira combinar com pacotes TCP requisitando uma
coneccao TCP.

[!] -f Combina o segundo ate o ultimo fragmento de um pacote
fragmentado. Nenhuma porta pode ser especificada quando
o flag -f e utilizado.

-i [!] nome Especifica a interface de rede pelo nome (de acordo com o
nome listado no comando ifconfig).A interface de input
e’ a interface por onde entram os pacotes, a interface
de forward e output sao as interfaces por onde os pacotes
saem.Um nome de interface terminado com + ira combinar
com todas as interfaces daquele tipo. Por exemplo eth+
para : eth0, eth1, eth2 etc. ppp+ para ppp0, ppp1, etc.
Pode-se especificar um interface que não existe no seu sistema
ou não esta ativa, por exemplo ppp1. Nenhum pacote ira
combinar com a regra ate que a interface ppp1 esteja ativa.

-b Bidirecional, is vai fazer com que a regra funcione não importa
qual seja a direcao do pacote.E equivalente a repetir a regra
invertendo o endereço de origem (-s) e destino (-d). Na
verdade, seria como inserir duas regras em 1 so.
Talvez, para não confundir seja melhor declarar as duas regras
a declarar apenas 1.
obs. A exclamacao ! significa NOT. Por exemplo
“! -s 162.168.0.11” ira combinar com qualquer pacote menos
1 originado em 162.168.0.11. A mesma regra pode ser usada para
portas, protocolo, interface e demais predicados acima com essa
opcao descriminada.

– O que essa regra faz é mascarar todos os pacotes provenientes da rede
192.168.0.0 com o IP da eth0 encaminhando-os à Internet:
ipchains -A forward -j MASQ -i eth0 -s 192.168.0.0/24 -d 0.0.0.0

Opções:
-A forward = adiciona regra de encaminhamento;
-j MASQ = política de mascarar o IP com o IP do servidor;
-i eth0 = pela interface eth0;
-s 192.168.0.0/24 = que tenha origem na rede 192.168.0.0 de subnet 255.255.255.0;
-d 0.0.0.0 = destino a internet.
– O que essa regra faz é negar toda a entrada de pacotes originários da
Internet nas portas 0 a 7000.
ipchains -A input -s 0.0.0.0/32 0:7000 -j DENY

Opções:
-A input = adiciona regra de entrada
-s 0.0.0.0/32 origem (source) = determina a origem, nessa caso a internet com
subnet 255.255.255.255 ou /32 (32 bits).
0:7000 = especifica todas as portas entre 0 e 7000
-j DENY = política de DENY, ou seja negar.
– Esse exemplo é mais completo por especificar a interface eth1 e o protocolo
TCP. Nesse caso conexões provenientes da Internet na porta 80, protocolo TCP
para interface eth1 são aceitos. Além disso serão logados através do parametro
‘-l’
ipchains -A input -s 0.0.0.0/32 80 -p TCP -i eth1 -j ACCEPT -l

Opções:
-A input = adiciona regra de entrada
-s 0.0.0.0/32 origem (source) = determina a origem, nessa caso a internet com
subnet 255.255.255.255 ou /32 (32 bits).
80 = especifica porta 80, ou seja a porta que geralmente utiliza-se http.
-p TCP = apenas para o protocolo TCP.
-i eth1 = na interface especificada eth1.
-j ACCEPT = política de aceitação.
-l = logar atividade.

– Esse exemplo bloqueia toda a saída da sua rede para a Internet que esteja
usando a porta 4444. Este exemplo é util para quando não se quer que os
funcionários utilizem serviços como Napster, ICQ, jogos ou outros tipos
de jogos. É importante conhecer a porta do serviço e também conhecer seu
protocolo
ipchains -A output -d 0.0.0.0/32 4444 -j DENY -l

Opções:
-A output = adiciona regra de saída.
-d 0.0.0.0/32 = destino internet.
4444 = porta 4444.
-j DENY = política de DENY (negar).
-l = logar atividade.
8.15 – comando iptables = IP firewall administration padrao no kernel 2.4.x
e 2.6.x, também conhecido como NetFilter. Sintaxe:
iptables comandos regras extensoes

comandos:
——–
-P cadeia = define a política padrão para uma cadeia. As cadeias válidas são:
INPUT, OUTPUT e FORWARD.

-A cadeia = anexa regras ao final de uma cadeia. Se um nome de host é
fornecido, como fonte ou como destino, uma regra é adicionada para cada IP
relacionado a este host. A opção “cadeia” deve ser substituida por: INPUT,
OUTPUT e FORWARD

-D cadeia = apaga uma ou mais regras da cadeia especificada

-D cadeia regra_num = apaga a regra residente na posição indicada por
regra_num da cadeia especificada. A 1ª regra na cadeia é a de número 1

-R cadeia regra_num = substituí a regra regra_num da cadeia especificada pela
regra dada

-I cadeia regra_num = insere uma ou mais regras no começo da cadeia. Se um
nome de host é fornecido, como fonte ou como destino, uma regra é adicionada
para cada IP relacionado a este host

-L [cadeia] = lista todas as regras em uma cadeia. Caso não haja nenhuma
cadeia especificada, todas as regras em todas as cadeias são listadas

-F [cadeia] = remove todas as regras de uma cadeia. Se nenhuma cadeia for
especificada, remove as regras de todas as cadeias existentes, inclusive as do
usuário

-Z [cadeia] = restaura os contadores de datagramas e de bytes em todas as
regras das cadeias especificadas para zero, ou para todas as cadeias se
nenhuma for especificada

-N cadeia = cria uma cadeia definida pelo usuário com o nome especificado

-X [cadeia] = apaga a cadeia definida pelo usuário ou todas se não for
especificada uma

-C cadeia = verifica o datagrama descrito pela regra especificada contra a
cadeia especificada. Este comando retorna uma mensagem descrevendo como a
cadeia processou o datagrama. Isto é muito útil para testar a configuracão do
firewall, e para uma análise posterior.

regras:
——-
As seguintes regras podem ser usadas:

-p ! protocolo = define o protocolo ao qual a regra se aplica. O parâmetro
protocolo pode ser qualquer valor numérico do arquivo /etc/protocol ou uma
das palavras chave: tcp, udp ou icmp

-s ! addres[/mask] = define a origem do pacote ao qual a regra se aplica. O
parâmetro address pode ser um nome de host, um nome de rede ou um endereço IP
com uma máscara de rede opcional

-d ! address[/mask] = define o destino do pacote ao qual a regra se aplica.
O endereço e a porta são definidos usando-se as mesmas regras utilizadas para
definir esses valores para a origem do pacote

-j política = define um alvo para o pacote caso ele se encaixe nesta regra. As
políticas válidas: ACCEPT, DROP, QUEUE e RETURN.
ACCEPT = permite a passagem do datagrama;
DROP = recusa o datagrama;
DENY = nega o datagrama;
QUEUE = passa o datagrama para área do usuário para posterior processamento;
RETURN = força o código do firewall a retornar para a cadeia anterior e
continua o processamento na regra seguinte à que retornou.

-i ! interface_name = define o nome da interface DE ENTRADA DE PACOTES por
onde o datagrama foi recebido. Um nome de interface pode ser usado encer-
rando-o com um sinal de “+”; por exemplo, eth+ corresponderia a todas as
interfaces ethernet iniciadas com eth. Se o seu computador possuir uma
placa fax-modem, sua interface é a ppp0.

-o ! interface_name = define o nome da interface DE SAÍDA DE PACOTES por
onde o datagrama será transmitido. Um nome de interface pode ser usado
encerrando-o com um sinal de “+”; por exemplo, eth+ corresponderia a todas
as interfaces ethernet iniciadas com eth. Se o seu computador possuir uma
placa fax-modem, sua interface é a ppp0.

! -f = indica que a regra somente se refere ao segundo fragmento e aos
subseqüentes de pacotes fragamentados.

Observação: O símbolo “!” é usado na regras como uma negação da expressão.
Exemplo:
-s 192.168.0.10/32 equivale ao endereço de origem 192.168.0.10;
-s !192.168.0.10/32 equivale a todos os endereços exceto o 192.168.0.10

opções:
——-
-v = saída em modo verbose. Mais rico em termos de detalhes sobre o que está
acontecendo ou sendo feito

-n = saída em modo numérico e não por nome de host, rede ou porta

-x = exibe o valor exato do pacote e dos contadores de bytes em vez de
arrendondá-los para o milhar, milhão ou bilhão mais próximo

–line-numbers = quando lista as regras, adiciona um número de linha ao começo
de cada regra, correspondendo à posição da regra dentro da cadeia.

extensões:
———-
O IPtables é extensível através de uma biblioteca de módulo compartilhados
opcional. Para fazer uso das extensões é preciso especificar o seu nome usando
o parâmetro “-m argumento” para o que o IPtables carregue este módulo. Em
alguns casos é usuado o parâmetro “-p” para determinar o protocolo (em certos
casos não é necessário o parâmetro “-m” pois ele é carregado automaticamente,
por exemplo quando se usa tcp, udp ou icmp).

Extensão TCP: usada com -m tcp -p tcp
————————————-
–sport ! porta:porta = especifica a porta que a origem do datagrama usa.
Portas podem ser especificadas com um conjunto especificando-se o seu limite
superior e inferior separados por dois pontos “:”. EX: 20:25 descreve todas
as portas numeradas de 20 até 25 inclusive. Também é possível usar o caracter
“!” para inverter a expressão

–dport ! porta:porta = especifica a porta que o destino do datagrama usa.
ou
–destionation-port ! port:port = especifica a porta que o destino do
datagrama usa.

–tcp-flags ! mask comp = especifica que esta regra somente será validada
quando os flags do datagrama TCP coincidirem com o especificado em mask e
comp. Mask é uma lista separada por vírgulas dos flags que devem ser exa-
minados quando for feito o teste. Comp é uma lista separada por vírgulas dos
flas que devem ser configurados. Os flags válidos são: SYN, ACK, FIN, RST,
URG, PSH, ALL ou NONE.

–syn = especifica que a regra deve encontrar somente datagramas com o bit
SYN ligado e os bits ACK e FIN desligados. Datagramas com essas opções são
usados para requisitar início de conexão TCP.

Extensão UDP: usada com -m udp -p udp
————————————-
–sport ! port:port = este parâmetro tem funcionamento idênyico ao da
extensão TCP.

–dport ! port:port = este parâmetro tem funcionamento idêntico ao da
extensão TCP.
Extensão ICMP: usada com -m icmp -p icmp
—————————————-
–icmp-type ! typername = especifica o tipo de mensagem ICMP que a regra
deve satisfazer. O tipo pode ser determinado por um número ou nome. Alguns
nomes válidos são: echo-request, echo-reply, source-quench, time-exceeded,
destionation-unreachable, network-unreachable, host-unreanchable,
protocol-unreachable e port-unreachable.

Extensão MAC: usada com -m mac
——————————
–mac-source ! address = especifica o endereço Ethernet do host que
transmitiu o datagrama que esta regra deve encontrar.

Dispositivos de rede importantes no GNU/Linux
———————————————
ethX = utilizado para as placas padrão ethernet. Normalmente a primeira
placa conectada no host é eth0, a segunda eth1 e assim sucessivamente.

lo = dispositivo de loopback, utilizando para testes do TCP/IP. Normalmente
quando aparece somente este dispositivo, significa que a parte física da
rede não está ativa.

pppX = a interface ppp, normalmente é ativa no momento de uma conexão PPP
(point-to-point protocol) via modem no sistema recebe o dispositivo ppp0,
a segunda ppp1, e assim sucessivamente. Para verificar sua existência é
necessário que uma conexão PPP esteja estabelecida.

– Especifica o source, seja um endereço IP ou um nome DNS
iptables -s ip

– Especifica o tipo de protocolo. Ex: tcp, udp, icmp
iptables -p protocolo

– Especifica a porta de destino. EX 23=telnet, 22=SSH, 80=WWW
iptables –destionation-port porta
ou
iptables –dport porta

– Exibe uma mensgem de ajuda com os comandos do iptables
iptables -hor

– Especifica o que fazer com o pacote. EX: ACCEPT, DENY, DROP
iptables -j codigo

– Recusa SYN pedidos de conexao em todas as portas menos a porta 80
iptables -A INPUT -i ppp0 -p tcp –syn –destination-port ! 80 -j DROP

– Aceita (-j ACCEPT) todos os pacotes que entram (-A INPUT) com destino à
porta SSH (–destination-port ssh) vindos de todos os computadores que
pertencem à rede 192.168.0.0 (-s 192.168.0.0)
iptables -A INPUT -s 192.168.0.0 -p tcp –destination-port ssh -j ACCEPT

– Recusa (-j DROP) todos os pacotes que entram (-A INPUT) com destino à porta
SSH (–destination-port ssh) vindos de qualquer conexão externa à rede local
192.168.0.0 (-s ! 192.168.0.0)
iptables -A INPUT -s ! 192.168.0.0 -p tcp –destination-port ssh -j DROP
8.15 – comando arp = este comando poderá listar e modificar a tabela arp do
kernel linux. A tabela arp associa endereços IP à endereços de hardware (mais
conhecidos como endereço MAC ou MAC Address). Manipula o cache ARP do sistema.
Toda a comunicação entre computadores (usando TCP/IP) é feita atrávés do
endereço MAC dos dispositivos de rede, e não somente pelo endereço IP. O ARP
é um dos protocolos utilizados na pilha TCP/IP localizado na camada de rede,
ou Internet, como alguns chamam. Ele executa a resolução de endereços de
pacotes de saída, mapeando os endereços IP para endereços MAC. Os adaptadores
usam o endereço MAC para determinar se um pacote diz respeito a um computador
específico. Sem o endereço MAC, os adaptadores de rede não sabem se devem
passar os dados para uma camada superior para serem processados posterior-
mente. Como os pacotes estão saindo da camada IP estão sendo preparados para
transmissão na rede, os endereços MAC de destino e origem devem ser adicio-
nados. O ARP armazena uma tabela, chamada cache ARP, que contém os IP e
seus endereços MAC correspondentes (a qual voce lista com o comando “arp -a”).
O cache do ARP de um computador contém o mapeamento somente de computadores
e roteadores residentes no mesmo segmento. A resolução funciona da seguinte
maneira: O ARP compara o endereço IP destino de todos os pacotes de saída com
o cache do ARP para determinar o endereço MAC de envio do pacote. Se houver
uma entrada correspondente, o endereço MAC é recuperado do cache. Se não
houver, o ARP transmite uma solicitação ao computador que possui o endereço
IP em questão para que responda com seu endereço MAC. A seguir, o computador
com o endereço IP correspondente adiciona o endereço MAC inicial do compu-
tador ao seu cache e responde com seu próprio endereço MAC. Quando é recebida
uma resposta do ARP, o cache do ARP é atualizado com as novas informações e
o pacote pode ser enviado. Se o pacote for para outro segmento, o ARP resolve
o endereço MAC para o roteador responsável por esse segmento, em vez de
resolver o endereço para o computador de destino final. Assim, o roteador
passa a ser responsável por encontrar o endereço MAC do destino ou encaminhar
o pacote para outro roteador.

– Exibe a tabela arp
arp

Address HWtype HWaddress Flags Mask Iface
10.1.67.1 ether 00:04:E2:39:58:12 C eth0

– Exibe a tabela arp mas não resolve nomes das máquinas existente em uma rede
arp -n

Address HWtype HWaddress Flags Mask Iface
10.1.67.1 ether 00:04:E2:39:58:12 C eth0

– Para deletar uma entrada da tabela arp
arp -d nome_do_host
ou
arp -d ip_do_host

– Exibe ao usuário o que esta acontecendo, de modo detalhado
arp -v

– Exibe as entradas das máquinas especificadas. Se o parametro máquina não
for usado, todas as entradas serão exibidas
arp -a

– Como posso descobrir o MAC ADDRESS de um máquina?
arp -a

– Exibe endereços numéricos, ao invés de tentar determinar os nomes
simbólicos da máquina, porta e usuário
arp -n maquina/IP

– Remove todas as entradas para a máquina especificada
arp -d maquina/IP

– Configura a interface eth0 para responder a requisições de arp para o
endereço IP 192.168.0.3 utilizando o seu próprio endereço de hardware (MAC
Address). O parâmetro ‘pub’ faz com que a interface passe a divulgar esse
endereço e nao apenas aceitar pacotes para ele
arp -s 192.168.0.3 -i eth0 -D eth0 pub
8.16 – comando arping = serve para enviar requisições arp e/ou ICMP. Além de
aceitar nomes de hosts, endereços IP’s e endereços de hardware, pode usar
também como origem e/ou destino endereços de broadcast
8.17 – comando rarp = manipula a tabela RARP do sistema
rarp -v
8.18 – comando dnsdomainname = exibe o nome de dominio DNS do sistema,
com base em seu nome e dominio totalmente qualificado
dnsdomainname
dnsdomainname -v
8.19 – comando hostname = exibe o nome da máquina
hostname

– Exibe os alias (apelidos) da máquina
hostname -a

– Exibe o nome do domínio DNS. Não use o comando domainname para obter o
nome do domínio DNS porque ele mostrará o nome do domínio NIS e não o
nome do domínio DNS. Use o comando dnsdomainname
hostname -d

– Exibe o FQDN (Nome de Domínio Completamente Qualificado). Um FQDN consiste
de um nome curto de máquina e do nome do domínio DNS. A menos que você
esteja usando bind ou NIS para resolução de nomes você pode mudar o FQDN
e o nome do domínio DNS (que é parte do FQDN) no arquivo ‘/etc/hosts’
hostname -f

– Exibe o(s) endereço(s) IP da máquina
hostname -i

– Exibe o nome da máquina sem o nome do dominio
hostname -s

– Exibe o nome do domínio NIS no sistema
hostname -y

– Exibe uma saída detalhada do que está acontecendo
hostname -v
8.20 – comando domainname = exibe ou define o nome de dominio NIS do
sistema.
domainname
8.21 – comando nmap = ferramenta de exploração de rede e segurança

Opções:

-PT usa o ping para verificar que HOSTS que estão ativos

-PT21 igual ao primeiro só que usa a porta 21

-sT varre porta de conexão TCP

-sS varre portas TCP SYN (furtivo)

-f usa pacotes fragmentados

-P0 nao faz ping

-PI usa ping ICMP pra saber quais HOSTS estão ativos

-sU varre porta UDP

-sF varredura FIN furtiva

-PB faz varreduras TCP e ICMP (vc pode escolher a porta)

-O descobre que OS o HOST esta usando

-p varre um intervalo de portas vc digita isso seguido do intervalo
de portas

-D [alguma HOST ativa] essa função eu naum sei direito o que faz, mas
parece que lança algo que confunde a HOST e naum deixa ela te rastear,
se voce colocar varias HOSTS inativas da pra fazer uma inundação SYN

-F varredura rápida

-I obtém infos sobre os processos TCP na escuta

-R resolve todos os HOSTS (pelo menos tenta)

-o essa é boa p/ varreduras longas ele grava as saídas no arquivo texto
que voce escrever após o “o”

-g configura a porta fonte

-v saída detalhada

-vv saída mais detalhada ainda

-e [nome_dispositivo] envia pacotes na interface nome_dispositivo

nmap -sT -PO -O endereco_ip

– Exibe o serviço, a porta bem como tenta detectar o software que está
fornecendo a conexão:
nmap -A localhost -P0

Starting nmap 3.55 (http://www.insecure.org/nmap/) at 2004-09-17 19:54 UTC
Interesting ports on localhost.localdomain (127.0.0.1):
(The 1657 ports scanned but not shown below are in state: closed)
PORT STATE SERVICE VERSION
80/tcp open http Apache httpd 2.0.50 ((Fedora))
111/tcp open rpcbind 2 (rpc #100000)
443/tcp open ssl/http Apache httpd 2.0.50 ((Fedora))
Device type: general purpose
Running: Linux 2.4.X|2.5.X|2.6.X
OS details: Linux 2.5.25 – 2.6.3 or Gentoo 1.2 Linux 2.4.19 rc1-rc7)
Uptime 0.183 days (since Fri Sep 17 15:31:29 2004)

– Verifica se a máquina alvo está com a porta do XFree86 aberta, não
pingando o host, mas verificando o sistema operacional que está rodando
nmap -P0 -O -p5999-6005 endereco_ip

– Identifica se a maquina está rodando o serviço telnet e se também
exibe o sistema operacional do host
nmap -P0 -O -p23 endereco_ip

– Verifica se o host remoto está com a porta do LPD aberta
nmap -P0 -O -p515 endereco_ip

– Verifica se o host remoto está com a porta do http aberta
nmap -P0 -O -p80 endereco_ip

– Verifica se o host remoto está com a porta do ftp aberta
nmap -P0 -O -p21 endereco_ip

– Verifica se o host remoto está com a porta do ssh aberta
nmap -P0 -O -p22 endereco_ip

– Visualiza as portas que estão abertas no seu sistema
nmap localhost

– <$1> significa que é para mostrar somente a primeira coluna verá uma coluna
de número de serviços (porta/protocolo) abertas
nmap localhost | grep open | awk ‘{print $1}’

– Checa se o serviço de ftp está rodando
nmap localhost | grep ftp

– Faz uma varredura em todos os IP (“pingando”) que comeam com 172.30.
(deve ser o IP da sua rede) e desviar o resusultado para o arquivo ‘ipativo’
namp -sP 172.30.*.* > /var/log/ipativo

– Exibe todas as máquinas que estao ligadas neste endereçamento IP
nmap -sP 192.168.0.*

– Descobre o endereço do DHCP server da rede 192.168.0
nmap -sU -p 67 192.168.0.1-254

– Verifica se uma determinada porta esta ou não aberta no sistema
nmap -sS localhost

– Exibe as portas TCP abertas
nmap -sT 192.168.0.1

– Exibe as portas UDP abertas
nmap -sU 192.168.0.1

– Exibe se as portas 22 a 200 estão abertas
nmap 192.168.0.1 -p22-200

– Exibe quais máquinas que estao ativas na rede
nmap -sP 192.168.0/24

– Exibe do IP 1 a 254 e checa se a porta 25 esta aberta
nmap 192.168.0.1-254 -p25

nmap -p 25,53 -sX -P0 -D 1.2.3.4,5.6.7.8 192.168.0.2
8.22 – comando pppstats = imprime estatísticas PPP

– Exibe valores absolutos em vez de relativos. Com esta opção todos os
relatórios mostrarão estatísticas relativas ao momento em que a conexão
PPP foi iniciada. Sem esta opção, o segundo e os subseqüentes relatórios
mostrarão estatísticas relativas ao momento do término do relatório
anterior
pppstats -a ppp0

– Repete a tela 8 vezes. Se esta opção não for especificada, o número de
repetições padrão será 1
pppstats -c 8 ppp0

– Exibe estatísticas adicionais, relatando a taxa de compactação alcançada
pelo algoritmo de compactação de pacotes em uso
pppstats -r ppp0

– Exibe estatísticas adicionais, relatando o desempenho do algoritmo de
compactação de cabeçalho TCP
pppstats -v ppp0

– Pausa 8 segundos entre cada repetição da tela. O padrão será de 5 segundos
pppstats -w 8 ppp0

– Em vez de utilizar o formato padrão de exibição, exibe estatísticas indi-
cando o desempenho do algoritmo de compactação de pacotes utilizado
pppstats -z ppp0
8.23 – comando rup = exibe o status de um ou mais sistemas remotos.
Se nenhum host for especificado entao o status de todas as maquinas
na rede local será exibido. Sintaxe:
rup -dhlt nome-da-maquina

– Exibe a hora local em cada maquina
rup -d nome-da-maquina

– Exibe as entradas pelo nome de host
rup -h nome-da-maquina

– Exibe as entradas pela media de carga
rup -d nome-da-maquina

– Exibe as entradas pela hora
rup -t nome-da-maquina
8.24 – comando rusers = exibe quem esta conectado com um ou mai hosts
na rede local. Se nenhuma maquina for indicada, entao todos os usuários
conectados com todas as maquinas na rede local serao exibidos. Sintaxe:
rusers -l hostname

– Exibe os resultados no formato longo, incluindo nome do usuário, nome
da maquina, tty que está sendo usado pelo usuário e a hora do login,
entre outras informacoes
rusers -l nome-da-maquina
8.25 – comando rwho = exibe uma lista de usuarios conectados com todas
as maquinas na rede local
rwho
8.26 – comando rwhod = responde as solicitacoes que chegam do cliente rwho
rwhod
8.27 – comando wall = envia uma mensagem a todos os usuários conectados
do sistema. O comando wall faz a leitura de um arquivo ou entrada padrão
e escreve o resultado em todos os terminais onde existem usuários
conectados. Somente o usuario root pode utilizar este comando
wall mensagem

wall /tmp/mensagem1.txt

echo Teste de mensagem | wall
8.28 – comando telnet = permite acesso a um computador remoto. É
recomendado usar no lugar do serviço telnet, o servido ssh, pois
senhas e logins são enviados 100 qualquer tipo de criptografia nos
seviços telnet. Ja com o ssh as informações sao criptografadas antes
de serem enviadas/recebidas dando maior segurança para o usuario
telnet opcoes ip/dns porta

ip/dns = endereço IP do computador de destino ou o DNS
porta = porta onde será feita a tentativa de conexão. O padrão é a porta 23

Opcoes :
-8 : força uma conexão em modo binario de 8 bits para envio e recebimento.
-a tenta um login automatico, enviando o nome de usuario lido da
variável de ambiente USER.
-d : ativa o modo debug
-r : ativa a emulacao de rlogin
-l user1 : faz a conexao com o login user1

– Tenta uma conexão na porta 80 (httpd)
telnet http://www.dominio.com.br 80

– Tenta uma conexão na porta 25 (SMTP)
telnet http://www.dominio.com.br 25

– Faz uma consulta à um servidor whois
telnet rwhois.embratel.net.br 1234

– Faz uma consulta à um servidor whois
telnet whois.nic.br
– Verifica se a porta do Squid está aberta
telnet host 3128

– Verifica se a porta do POP3 está aberta
telnet host 110

– Verifica se a porta do SMTP está aberta
telnet host 25
8.29 – comando ftp = permite a transferencia de arquivos de um computador
local para um computador remoto e vice e versa. Ao entrar em algum endereço
de FTP e o mesmo pedir um user e uma senha, o usuário deve utilizar o login
‘anonymous’, e digitar qualquer senha, seguido do caracter ‘@’, pois ele
estará pedindo um e-mail como senha. EX: teste@teste.com
ftp ip
ou
ftp dns
ou
ftp ftp.dominio.com.br
Comandos FTP:
————
– Permite acesso na máquina especificada
open nome_maquina ou numero_ip

– Altera de diretório
cd diretorio

– Exibe em qual diretorio remoto você está
pwd

– Lista o conteúdo do diretório remoto atual
ls

– Exibe o diretório local, ou seja, do seu computador
lcd

– Acessa o diretório local ‘/home/jordam’
lcd /home/jordam

– Configura o modo de transferência binário
bin

– Quando estiver baixando um arquivo, exibirá caracteres ‘#’ enquanto
a transferência estiver sendo realizada
hash

– Habilita e desabilita o modo interativo de comandos
prompt

– Faz o download do arquivo ‘photos.zip’
get photos.zip
– Faz o download de todos os arquivos coma extensão TXT
mget *.txt

– Envia o arquivo ‘docs.zip’ para o servidor o qual voce tenha
permissão de gravação
put docs.zip
– Envia todos os arquivos JPG para o servidor
mput *.jpg

– Sai do programa ftp
bye

– Copia o arquivo ‘file1.txt’ do servidor ftp para o computador local.
O arquivo é gravado por padrão no diretório onde o programa ftp foi
executado/chamado
get file1.txt

– Por padrão esta opcao esta desligada. Quando ligada faz com que o
caractere ‘#’ seja exibido na tela indicando o progresso do download
hash on/off

– Semelhante ao comando get, o comando ‘mget’ possibilita copiar vários
arquivos e permite o uso de caracteres curinga “*”, “?”
mget file1.txt file2.txt file3.txt

– Envia o arquivo ‘file1.txt’ para o diretório atual do servidor FTP
send file1.txt

– Ativa ou desativa a pergunta para a copia de arquivo. Se estiver
desligada (off) assume sim para qualquer pergunta
prompt on/off

– Preciso enviar um arquivo de backup via FTP para um determinado host,
como fazer isso isso de forma automática?
ftp -i -n < /root/scripts/ftp_virusscan.txt
conteúdo do arquivo /root/scripts/ftp_virusscan.txt
open ftp.nai.com
user anonymous xx@xx.xxx
bin
cd virusdefs
cd 4.x
hash
mget *.zip
mget *.exe
bye
8.30 – comando talk = inicia um chat com outro usuário que, necessariamente,
deve estar logado no sistema UNIX
talk nome_do_usuario@dominio.com.br
Para sair, tecle CTRL+C

talk usuario tty

usuario : nome de login que deseja iniciar o chat. Pode-se encontrar
logins para chat digitando o comando who

tty : nome do terminal aonde o usuario esta conectado

– Se o usuario que voce deseja conversar estiver conectado em um
computador remoto
usuario@nome-do-host
8.31 – comando tcpdchk = é útil para verificar problemas nos arquivos
‘hosts.allow’ e ‘hosts.deny’. Quando executado ele verifica a sintaxe destes
arquivos e relata problemas, caso eles existam
tcpdchk
8.32 – comando tcpdmatch = permite que você simule a tentativa de conexões
ao seu sistema e observar ser ela será permitida ou bloqueada pelos arquivos
‘hosts.allow’ e ‘hosts.deny’. EX:

Conteúdo do arquivo ‘hosts.allow’
ALL: 127.0.0.1
in.talkd, in.ntalkd: ALL
in.fingerd: 192.168.1. EXCEPT 192.168.1.30

A primeira linha permite o loopback (127.0.0.1) acessar qualquer serviço
TCP/UDP em nosso computador, a segunda linha permite qualquer um acessar
os servidor TALK (nós desejamos que o sistema nos avise quando alguém
desejar conversar) e a terceira somente permite enviar dados do ‘finger’
para computadores dentro de nossa rede privada (exceto para 192.168.1.30).

Conteúdo do arquivo hosts.deny:
ALL: ALL

Qualquer outra conexão será explicitamente derrubada. Vamos aos testes.

Para verificar se o endereço 127.0.0.1 tem acesso ao finger digite
tcpdmatch in.fingerd 127.0.0.1

client: address 127.0.0.1
server: process in.fingerd
matched: /etc/hosts.allow line 1
access: granted

Ok, temos acesso garantido com especificado pela linha 1 do ‘hosts.allow’
(a primeira linha que confere é usada).

Digite:
tcpdmatch in.fingerd 192.168.1.29

client: address 192.168.1.29
server: process in.fingerd
matched: /etc/hosts.allow line 3
access: granted

O acesso foi permitido através da linha 3 do hosts.allow.

Digite:
tcpdmatch in.fingerd 192.168.1.30

client: address 192.168.1.30
server: process in.fingerd
matched: /etc/hosts.deny line 1
access: denied

O que aconteceu? como a linha 2 do `hosts.allow’ permite o acesso a todos os
computadores 192.168.1.* exceto 192.168.1.30, ela não bateu, então o proces-
samento partiu para o `hosts.deny’ que nega todos os serviços para qualquer
endereço.

Digite:
tcpdmatch in.talkd http://www.debian.org

client: address http://www.debian.org
server: process in.talkd
matched: /etc/hosts.allow line 2
access: granted

Ok, na linha 2 qualquer computador pode te chamar para conversar via talk na
rede, mas para o endereço DNS conferir com um IP especificado, o ‘GNU/Linux’
faz a resolução DNS, convertendo o endereço para IP e verificando se ele
possui acesso. No lugar do endereço também pode ser usado a forma
‘daemon@computador’ ou `cliente@computador’ para verificar respectivamente
o acesso de daemons e cliente de determinados computadores aos serviços da
rede.
8.33 – comando wget = software que faz o download de arquivos da WWW
Sintaxe:
wget URL:porta/path

– Comeca a fazer o download do arquivo ‘file1.avi’
wget http://www.site.com.br/file1.avi

– Caso a conexao termine e o download do arquivo ‘file1.avi’ não tenha
terminado, basta reiniciar do ponto onde caiu a conexão, usando o
parametro ‘-c’
wget -c http://www.site.com.br/file1.avi

– Copia todo o conteúdo do site referente à este dominio
wget -r http://www.dominio.com/

– Baixa apenas páginas html do site, deixando de lado as imagens e outros
arquivos. Neste caso você usa o parâmetro ‘-A’, seguido dos tipos de arquivos
a serem baixados. O wget automaticamente converte páginas php, asp e outras
extensões para html, de forma que esse comando funciona bem com a maioria
dos sites
wget -r -A “.html” http://www.uol.com.br

– Baixando um arquivo via FTP com com senha. EX:
wget ftp://login@senha@http://ftp.ibiblio.org/teste.iso
ou
wget ftp://user:password@host/path

– Faz o download do arquivo ‘file1.txt’ especificando o nome de usuário
sendo ‘user1’, a senha sendo ‘senha88’, e o caminho do arquivo no servidor
ftp
wget user1:senha88@ftp.ederjordam.com/home/ederjordam/file1.txt
– Copia um arquivo especifico, no exemplo seria index.html e grava no
diretorio ‘/tmp’ com o nome de ‘teste.html’
wget -O /tmp/teste.html http://www.site.com/files/index.html

– Copia todas as páginas HTML do site ‘http://www.uol.com.br/remedios&#8217;
wget -m -l 0 -A htm http://www.uol.com.br/remedios

– Copia a página web e suas imagens para o respectivo diretório que voce
se encontra
wget -r -np -k http://whatever/wherever

– Copia todo o site para o seu computador
wget -t0 -r -F http://www.dominio.com

– Faz o espelhamento (mirror) do site. OBS: Um espelhamento mal projetado
pode contribuir para encher seu disco rígido com material não desejado,
além de sobrecarregar a Internet e o servidor sendo espelhado
wget -m http://members.xoom.com/edersg/

– Uma aranha, no contexto da Internet é um programa que serve para verificar
se os links de uma página estão ativos, ou seja, verificando se cada vínculo
HREF está conectado (ativo), verificando se os links de uma determinada página
local, chamada de links.html, estão ativos
wget –spider –force-html -i links.html
– Faz o mesmo que a opção acima, porem o arquivo agora analizado se encontra
na Internet
wget –spider http://members.xoom.com/edersg/links.html

– Para fazer o download apenas de imagens nos formatos jpg, gif e png
wget -P /tmp/pastaespecifica -r -p http://www.unicamp.br –accept=JPG,jpg,GIF,gif,png,PNG

– Para fazer o download de todos os aquivos de um site
wget -c -r ftp://meu.servidor.com/

– Para fazer o download do arquivo ‘arquivo.txt’ de um ftp que exija
login e senha
wget ftp://login:senha@ftp.servidor.com/pasta/arquivo.txt
wget ftp://usuario:senha@servidor_ftp.com.br/arquivo.extensao
– Para limitar o download a no máximo 10Kbps
wget –limit-rate=10k –continue http://algumendereco/arquivo.zip

– O wget pode também retomar transferências interrompidas (opção ‘-c’)
quando se fornece o arquivo incompleto ao qual se acrescenta os
restantes dados. Esta operação precisa de ser suportada pelo servidor
wget -c http://o.url.do/arquivo/incompleto

Entretanto, lembre-se que nem todos os sites estão abertos para espelhamento,
o direito autoral deve ser respeitado. E também, existem sites que possuem
arquivos robots.txt que especificam quais partes do site podem ser copiadas
e quais não. Portanto, não se surpreenda se descobrir que determinado site
ou página não pode ser recuperado.

– Se tiver tantas interrupções na transferência de arquivo como eu tenho
no meu escritório, pode dizer ao wget para tentar o URL várias vezes
wget -t 5 http://coloque.o.seu.url/aqui

aqui desistimos ao fim de 5 tentativas. Use a opcao ‘-t inf’ para nunca
desistir.

– E quanto a proxy firewalls? Use a variável de ambiente “http_proxy” ou
o arquivo de configuração “.wgetrc” para especificar um proxy através
do qual irá fazer a transferência de arquivos. Um problema com ligações
via proxy com ligações interrompidas é que o retomar pode por vezes
falhar. Se uma transferência via proxy é interrompida o servidor proxy
irá colocar em cache somente uma cópia incompleta do arquivo. Quando
tentar usar “wget -c” para obter o resto do arquivo o proxy irá
verificar a sua cache e informar erradamente que o arquivo completo
já foi transferido. Pode conseguir que a maioria dos proxyes não passe
pelo cache, adicionando um cabeçalho especial ao pedido de
transferência de arquivos:
wget -c –header=”Pragma: no-cache” http://coloque.o.seu.url/aqui

– A opção “–header” pode adicionar qualquer número e tipos de cabeçalhos
pelos quais podemos modificar o comportamento dos servidores de rede e
dos proxies. Alguns sítios recusam-se a servir arquivos via uma ligação
externa; o conteúdo é entregue somente a navegadores se acederem a
página via outra página no mesmo sítio. Pode contornar isto adicionando
um cabeçalho ‘Referer:’
wget –header=”Referer: http://site.com/pagina&#8221;
http://navegar.para.esta/pagina

– Alguns sites na rede particularmente anti-sociais irão fornecer
conteúdo somente a um tipo específico de navegador. Contorne isto com
um cabeçalho “User-Agent:” header:
wget –header=”User-Agent: Mozilla/4.0 (compatible; MSIE 5.0; WindowsNT; DigExt)” http://so.url.msie/aqui

Aviso: a dica acima pode ser considerada um mecanismo para evitar
licenciamento de conteúdo e existem sistemas legais anti-sociais que
consideram estas acções ilegais. Verifique a legislação local.

– A opção “-N” para o wget irá verificar o selo temporal do objectivo
e parar a transferência se eles coincidirem, o que é uma indicação
que o ficheior completo foi transferido. Por isso pode activa-lo e
esquece-lo
wget -c -N http://coloque.o.seu.url/aqui

– Recuperando downloads interrompidos – uma das características que tornam
interessantes o uso do wget é sua capacidade para recuperar downloads inter-
rompidos, desde, é claro, que o servidor suporte este recurso. Você pode
recuperar downloads perdidos especificando a opção ‘-c’ na linha de comando
do wget
wget -c http://www.dominio.com/arquivo.tar.gz

– Espelhamento de sites – outro recurso interessante é o espelhamento de
sites, também conhecido como mirror. O wget é capaz de fazer espelhamento
de sites, mas tenha cuidado: um espelhamento mal projetado pode contribuir
para encher seu disco rígido com material não desejado, além de sobrecarregar
a Internet e o servidor sendo espelhado. Você faz um espelhamento utilizando
a opção -m (de mirror). Lembre-se que nem todos os sites estão abertos para
espelhamento. Existem sites que possuem arquivos ‘robots.txt’ que especificam
quais partes do site podem ser copiadas e quais não. Portanto, não se sur-
preenda se descobrir que determinado site ou página não pode ser recuperado
wget -m http://www.dominio.com/diretorio/

– O comando ‘at’ pode ser utilizado para agendar uma tarefa em um momento
específico do dia. Este comando vai agendar para a 1 hora da madrugada o
download do arquivo ‘http://www.dominio.com/file01.tar.gz&#8217;. O resultado do
download (no caso, mensagens do wget), serão enviados para voce via comando
‘mail’
echo “wget http://www.dominio.com/file01.tar.gz&#8221; | at 01:00

– Uma ‘aranha’, no contexto da Internet, é um programa que serve para
verificar se os links de uma página estão ativos. A referência surgiu por
que o programa examina a página como se fosse um ponto de uma teia (web),
verificando se cada fio (vínculo HREF) está conectado (ativo). Para utilizar
o wget como aranha, usamos a opção ‘–spider’. Para verificar se os links
de uma determinada página local, chamada de ‘bookmark.html’ estão ativos,
basta digitar o comando acima. A opção ‘–force-html’ obriga o arquivo
local ‘bookmark.html’ a ser tratado como arquivo HTML
wget –spider –force-html -i bookmark.html
Se o arquivo reside na Internet, a sintaxe pode ser simplificada
wget –spider http://www.dominio.com/linuxlinks.html

– Baixa o conteúdo de um web site
wget -c -t70 -r -np http://www.dominio.com.br

– Passa alguns parametros como usuário e senha para poder baixar o
conteúdo de um site
wget -c -r –http-user=usuario –http-passwd=senha link

-c : esta opção informa ao wget para continuar o download de onde terminou
se encontrar um arquivo parcial. Se não fosse informada esta opção, ele
criaria novo arquivo e começaria o download do início.

-t0 : com esta opção, estou informando ao wget que, caso o download falhe,
ele deve repetir indefinidamente o mesmo. É preciso cuidado com esta opção,
principalmente se o comando será executado em uma sexta-feira para ser
verificado somente na segunda feira – se a URL estiver errada, o wget vai
ficar tentando encontrar o arquivo indefinidamente.

-T30 : o wget utiliza a facilidade de timeout, mas seus limites de tempo
não são satisfatórios, pelo menos não para mim. Com esta opção, estou
informando ao wget que, se não houver fluxo de dados por 30 segundos, ele
deve refazer a conexão.

-i get-list.txt : esta opção informa ao wget que este deve ler as URL’s
a serem baixadas a partir de um arquivo, a saber, get-list.txt (pode ser
qualquer nome), em vez de receber a mesma na linha de comando.
8.34 – comando lynx = browser web de interface texto.

– Algumas vezes estamos interessados em fazer a transferência de um
grande número de arquivos cujos URLs estão numa dada página da rede
mas não queremos fazer um espelho total do sítio. Um exemplo será a
transferência dos arquivos de música no top 20 de um sítio que mostra
o top 100 ordenados. Aqui as opções ‘–accept’ e ‘–reject’ não funcio-
narão porque somente funcionam com extensões de arquivos. Por isso use
‘lynx -dump’
lynx -dump ftp://ftp.ssc.com/pub/lg/ |grep ‘gz$’ |tail -10 |awk ‘{print $2}’ > listaurl.txt
O resultado do lynx pode então ser filtrado usando vários utilitários
de processamento de texto GNU. No exemplo acima, extraimos os URLs que
terminam em “gz” e guardamos os últimos 10 desses num arquivo. Um
pequeno comando de scripting bash irá automaticamente transferir
qualquer URL listado neste arquivo
bash$ for x in $(cat listaurl.txt)
do
wget $x
done

Conseguimos transferir os últimos 10 números da Linux Gazette.
8.35 – comando xhost = cada servidor X mantém uma lista de hosts que podem ou
não ter acesso. O programa xhost é usado para alterar esta lista.

– Exibe a lista dos hosts que tem permissão de acesso a este servidor X
xhost

– Acrescentar o host “bar.foo.org”. Então, qualquer usuário e programa
naquela máquina pode se comunicar com nosso servidor X
xhost +bar.foo.org
– Remove o host “bar.foo.org”
xhost -bar.foo.org
– Possiblita que qualquer máquina de qualquer lugar da Internet possa
se conectar ao servidor X de seu PC, exibindo a seguinte mensagem:
“access control disabled, clients can connect from any host”
xhost +

– Somente as máquinas que estão listadas com o comando
“xhost +nome-da-maquina” poderão acessar o servidor X deste PC, exibindo
a msg: “access control enabled, only authorized clients can connect”
xhost –
8.36 – comando mii-tool = serve para verificar e alterar o estado de uma
interface de rede. O MII é um recurso utilizado pela maioria dos adaptadores
fast ethernet para negociar a velocidade do link e o full/half duplex. Nem
todos os adaptadores suportam esse recurso

– Para verificar o estado da primeira interface de rede(eth0)
mii-tool eth0

– Para forçar que uma placa de rede anuncie somente certas capacidades, ou
para desabilitar completamente a auto-negociaçõ e forçar uma certa velocidade,
use os parâmetros ‘-A’ e ‘-F’ respectivamente

– Para configurar uma placa de rede para 100Mbit/s half e full duplex
mii-tool -A 100BaseTx-FD, 100BaseTx-HD eth0

– Para configurar uma placa de rede para 10Mbit/s full duplex
mii-tool -F 10BaseT-FD eth0
8.37 – comando tcpdump = este comando faz um dump do tráfego de rede. Na sua
operação normal ele coloca a interface de rede em modo promíscuo e exibe na
tela uma breve descrição de todos os pacotes que chegam à interface

– Exibe os pacotes do tipo ICMP que estão chegando na interface eth0
tcpdump -i eth0 icmp

– Exibe os pacotes com origem na maquina com o IP 192.168.7.5
tcpdump src 192.168.7.5

– Exibe os pacotes que tenham como origem ou destino a maquina 192.168.7.5
tcpdump host 192.168.7.5
8.38 – comando ip = este comando reune todas as funcionalidades dos comandos
ifconfig, arp e route além de permitir a manipulação das tabelas de rotas
especiais e túneis. Sintaxe:
ip [ opções ] OBJETO { COMMAND | help }

onde:
objeto = link, addr, neigh e route

– Obtendo ajuda de um determinado objeto
ip nome_do_objeto help

– O objeto link serve para exibir e manipular opções dos dispositivos de
rede. Através dele é possível ativar ou desativar uma interface, alterar
seus endereços MAC, opções de arp e multicast e até mesmo renomear uma
interface

– Exibe os todos os dispositivos de rede (ativos e inativos)
ip link show

– Ativando uma interface de rede
ip link set eth0 up

– Alterando a mtu de uma interface de rede
ip link set eth0 mtu 1480

– O objeto addr serve para exibir e alterar os endereços IPv4 e IPv6 das in-
terfaces virtuais ou não. Ao contrário do comando ifconfig, o comando ip addr
é capaz de atribuir e exibir mais de um endereço IPv4 para a mesma interface.
OBS: este comando exibe e espera como entrada de dados endereços IP no formato
addr/masklen.

– Exibe os endereços das interfaces de rede
ip addr show

– Adiciona um endereço em uma interface de rede
ip addr add 192.168.0.1/24 dev eth0

– Deleta um endereço em uma interface de rede
ip addr del 192.168.0.1/24 dev eth0

– Adiciona um endereço ponto-a-ponto
ip addr add 192.168.0.2 peer 192.168.0.1

– Exibe a tabela arp associada a uma interface de rede (o objeto neigh,
semelhante ao comando arp, serve para exibir e manipular a tabela arp)
ip neigh show dev eth0

– Adicionando uma entrada na tabela arp
ip neigh add 10.0.0.1 lladdr 00:11:22:33:44:55 dev eth0

– Deletando uma entrada na tabela arp
ip neigh del 10.0.0.1 lladdr 00:11:22:33:44:55 dev eth0

– Deletando toda a tabela arp associada a uma interface de rede
ip neigh flush dev eth0

– O objeto route = serve para exibir e modificar as tabelas de roteamento do
kernel linux. Ao contrario do comando route que apenas manipula a tabela de
rotas principal, este objeto consegue manipular todas as tabelas de rotas.

– Exibe a tabela de rotas do kernel linux
ip route show

– Exibe a rota para uma determinada rede ou host
ip route get 200.251.142.1

– Adiciona uma rota
ip route add 10.0.0.0/24 via 192.168.1.200

– Deleta uma rota
ip route del 10.0.0.0/24 via 192.168.1.200

– Adiciona uma rota do tipo blackhole onde os pacote são silenciosamente
descartados
ip route add blackhole 10.0.1.0/24

– Adiciona uma rota do tipo ‘unreachable’ onde é gerado um ICMP host
unreachable
ip route add unreachable 10.0.2.0/24

#######################################################################

9 – EDITORES DE TEXTO

– No GNU/Linux, existem diversos editores de textos. Iremos descrever:
emacs
vi
mcedit
pico
nano
9.1 – editor emacs
CTRL + e + CTRL + e = sai do emacs
CTRL + x + CTRL + f = abrir um arquivo
CTRL + x + CTRL + s = salva um arquivo
CTRL + x + CTRL + w = salvar como um outro nome o arquivo
CTRL + k = apaga a linha corrente colocando-a no buffer
CTRL + y = cola a ultima entrada colocada no buffer
ALT + y = cola a penultima entrada colocada no buffer
CTRL + x + i = insere arquivo no ponto onde está o cursor
CTRL + s = procura o padrao de caracteres informado
CTRL +r = semelhante ao CTRL + s
CTRL + x + u = desfaz a ultima acao efetuada
9.2 – editor vi
:q = sai do vi sem salvar
:q!= sai do vi forçado sem salvar
:qw = sai do vi salvando o arquivo que esta sendo editado
:e file1.txt = abre o arquivo file1.txt
:w = salva o arquivo
:w outro-nome.txt = salva o arquivo corrente com outro nome
:r file1.txt = insere o arquivo file1.txt aonde se encontra o cursor
:u = desfaz a ultima acao

<esc>i – Entra no modo — INSERT — (insert)

<esc>:q – Sair, quando nada foi alterado (quit)

<esc>:q! – Sair forçado, quando um texto foi alterado mas não deseja-se
salvar (quit!)

<esc>:w – Salvar alterações correntes (write)

<esc>:w <nome_do_novo_arquivo> – Salvar o arquivo corrente com outro nome
(mantém o arquivo corrente)

<esc>:w! <nome_do_arquivo> – Salvar o arquivo corrente com outro nome (não
mantém o arquivo corrente)

<esc>:wq – Salvar e sair (write & quit)

<esc>:# – Vai para o número da linha indicado onde # é o número da linha

<esc>:split <nome_de_outro_arquivo> – Divide o arquivo atual com outro
arquivo na mesma tela

<esc>:!<comando> – Comando no shell (você mesmo dentro do vim pode dar um
comando no shell, sem sair dele)

<esc>dd – Deleta a linha que o cursor está

<esc>v – Seleção de caractéres — VISUAL —

<esc>Shift+v – Seleção de linhas — VISUAL LINE —

<esc>Ctrl+v – Seleção em bloco — VISUAL BLOCK —

O vi pode ser usado para criptografar arquivos. Basta usar a opção
:X no modo de comando e digitar a senha.

Imagine que você precisa inverter a ordem das linhas de um arquivo texto,
de forma que a primeira linha passe a ser a ultima. Isso pode ser feito
facilmente com o vi. Abra o arquivo, digite “:” para entrar no modo de
comando e digite: g/^/m0
9.3 – editor mcedit
F2 = salva o arquivo
F3 = marca o ponto inicial do bloco a ser movimentado, e repetindo-se a
tecla F3 marca o final do bloco
F4 = substitui palavras em um texto
F5 = copia o texto que estiver selecionado com a tecla F3
F6 = move o texto que estiver selecionado com a tecla F3
F7 = procura palavras em um texto
F8 = apaga a linha corrente
F9 = acessa o menu com as opcoes do mcedit
F10 = sai do mcedit
CTRL + u = desfaz a ultima acao efetuada
9.4 – editor pico
pico nome-do-arquivo
9.5 – editor nano
9.6 – comando touch – cria arquivos com tamanho igual a 0 e efetua
alteracoes de data e hora em arquivos

– Cria o arquivo ‘file23.txt’
touch file23.txt

– Altera a data e a hora do arquivo para 01/10 12:30
touch -t 10011230 file23.txt

– Altera a data, hora, ano e seguindos do arquivo ‘file23.txt’ para
01/12/1999 e 12:30:30
touch -t 120112301999.30 file23.txt

– Cria um comentário no diretório corrente
touch “zzz*** isto é um comentario ***zzz”

– Altera a data e a hora de criação do arquivo ‘file23.txt’ para
os dados atuais
touch -m file23.txt

– Altera a data de modificação do arquivo ‘file23.txt’ para o
dia 23/05/1999
touch -m 05231999 file23.txt

#######################################################################

10 – CAMINHOS DE ARQUIVOS IMPORTANTES NO GNU/LINUX

– histórico de comandos digitados por um usuário
~/.bash_history

– exibe informações de quem logou no sistema
/var/log/auth.log
– usuarios cadastrados no sistema
/etc/passwd

– grupos cadastrados no sistema
/etc/group

– senhas criptografadas cadastradas no sistema
/etc/shadow

– serviços e portas disponíveis
/etc/services

– visualiza as irq’s
/proc/interrupts

– arquivo de trava do fax-modem
/etc/ppp/options

– numeros ip’s das maquinas na rede
/etc/host

– nome da maquina local em uso
/etc/HOSTNAME

– Caminho dos papeis de parede do WindowMaker
/usr/X11R6/share/WindowMaker/Backgrounds

– Caminho para os estilos de menu do WindowMaker
/usr/X11R6/share/WindowMaker/Styles

– Caminho para o arquivo de menu do BlackBox
/etc/X11/blackbox/blackbox-menu

– Caminho das imagens de fundo de tela do Eterm
/usr/share/Eterm/pix

– Caminho de papeis de parede diversificados
/usr/share/wallpapers

– Caminho dos pacotes do kernel
/usr/src/linux

– Caminho dos modulos do kernel
/lib/modules/versao-do-kernel

– Caminho dos modulos ativados do Kernel
/etc/modules.conf
– Caminho do arquivo de configuraco do SendMail
/etc/sendmail.cw
– Caminho dos arquivos de configuração de serviços
/etc/inetd.conf
/usr/sbin/tcpd.tcpd
– Arquivo que permite acesso de usuários a sua máquina
/etc/hosts.allow
– Arquivo que permite negar acesso de usuários a sua máquina
/etc/hosts.deny
– Arquivos de configuracao do FTP ANONIMO
/etc/ftpaccess
/etc/ftphosts
/etc/ftpusers

– Caminho dos logs do sistema
/var/log/

– Caminho dos arquivos/diretorios cache do browser konqueror
/root/.kde/share/apps/kio_http/cache

– Arquivo de configuracao do apt-get
/etc/apt/sources.list
– Exibe seu conteudo apos o ato de efetuar o login na maquina
/etc/motd

– Se existir este arquivo, ninguém exceto o superusuário poderá acessar
o sistema. Quando um usuário tentar efetuar login, o conteúdo deste arquivo
será exibido no terminal
/etc/nologin

– Os usuários conectados estão listados no arquivo
/var/run/utmp
que pode ser acessado através dos comandos w e who

– O arquivo ‘/var/log/wtmp’ mantém o registro dos acessos bem-sucedidos
ao sistema, e pode ser acessado com o comando last

– Arquivo que serve para controlar o acesso a sistema de arquivos que
estão sendo exportados para clientes NFS
/etc/exports

– Configurações relacionadas ao sistema de janelas X, como por exemplo
configuração do teclado e comportamento de alguns programas no ambiente
gráfico
/etc/X11

– Arquivo de configuração do cron, que é o servidor utilizado para executar
serviços agendados
/etc/crontab

– Contém informações sobre os usuários da máquina. Nesse arquivo ficam
armazenados o nome do usuário, seu nome real, diretório pessoal, senha,
interpretador de comandos a ser usado e outras informações específicas
do usuário
/etc/passwd

– Parecido com o arquivo passwd, porém, trabalha com grupos de usuários
ao invés de usuários individuais
/etc/group

– Contém uma lista com os sistemas de arquivos e opções padrão para a
montagem de sistema de arquivos
/etc/fstab

– Contém a relação dos sistemas de arquivos atualmente montados, junta-
mente com opções de montagem e o estado em que se encontram
/etc/mtab

– Arquivo de configuração dos níveis de execução (runlevel) do sistema
/etc/inittab

– Contém as configuração para as impressoras ligadas ao sistema ou à rede.
Nesses arquivos são configurados filtros e alguns outros recursos adminis-
trativos relativo a impressoras
/etc/printcap

– Contém a relação de terminais considerados seguros. O superusuário só
poderá acessar a máquina a partir desses terminais. Geralmente são listados
apenas terminais acessíveis localmente
/etc/securetty

– Arquivo de configuração dos módulos do kernel, composto por várias diretivas
que adicionam, direcionam e carregam os módulos
/etc/modules.conf
– Lista dos interpretadores de comando válidos. Alguns servidores e comandos
restringem o acesso do usuário aos interpretadores de comando relacionados
nesse arquivo
/etc/shells

– Diretório contendo arquivos do sistema de janelas X. Esse diretório contém
diversos outros pelos quais se espalham os arquivos do X
/usr/X11R6

– Contém praticamente todos os comandos de usuários. Alguns outros podem
ficar no diretório ‘/bin’ ou, com menos frequência, no diretório
‘/usr/local/bin’
/usr/bin

– Possui os comandos de administração do sistema que não necessitam estar
no diretório raiz e que são exclusivos do superusuário
/usr/sbin

– É usado para armazenar os programas instalados localmente e que não se
encontravam empacotados com o RPM
/usr/local

– Neste diretório se encontra a maioria da documentação disponível da
distribuição, como páginas de manual (manpages) e arquivos Como Fazer
(HOWTOs), entre outros
/usr/share/doc

– Contém arquivos de bloqueio. Muitos programas seguem uma convenção
criando arquivos de bloqueio nesse diretório para sinalizar que estão
usando um dispositivo específico (como o modem, por exemplo) ou um
arquivo especial. Quando os programas detectam a presença desse
bloqueio eles não usam o mesmo dispositivo ou arquivo
/var/lock

– Possui os arquivos de registro e/ou históricos de programas. Os arquivos
desse diretório tendem a crescer indefinidamente, o que faz necessária
uma limpeza periódica nesse diretório. No Conectiva Linux o aplicativo
logrotate faz esse serviço automaticamente de acordo com configurações
preestabelecidas ou configurações definidas pelo administrador
/var/log

– Armazena as diversas filas de tarefas como e-mail, notícias, impressão,
etc. Cada fila fica armazenada em seu próprio diretório
/var/spool

– Registra todos os comandos da ultima secao do usuario. Este é criado pelo
proprio usuario que pode simplesmente alterá-lo
~/.bash_history

– Conjunto de comandos para serem executados na entrada do usuario.
~/.bash_profile

EX:
echo “hehehehe!!”
echo “Voce nao fez por merecer essa shell.”
echo “Good Bye”
exit

– Adicione comandos a serem executados quando o usuario sair
~/.bash_logout

#######################################################################

12 – COMANDOS PARA MODULOS (DRIVERS)
————————————
12.1 – comando modprobe = carrega um módulo e checa suas dependencias
referentes ao funcionamento do dispositivo especificado desde que
haja suporte para ele no kernel linux.

– Carrega o modulo sb (relativo a placa de som Sound Blaster) usando as
flags io, irq, dma, dma16 e mpuio relativos à configuração da placa de som
modprobe sb io=0x220 irq=5 dma=1 dma16=5 mpuio=0x300

– Carrega o modulo aha1542 referente a uma placa SCSI ISA
modprobe aha1542 irq=5 io=0x300 dma=3

– Carrega o módulo parport_pc referente ao funcionamento de uma impressora
conectada na porta LPT1(/dev/lp0)
modprobe parport_pc io=0x378 irq=7

– Se ISA:
modprobe <modulo> io=<0x123> irq=<9>

– Se PCI
modprobe <modulo>

onde:
modulo = é o modulo usado pela sua placa de rede, no meu caso, eu uso
ne2k-pci, que é a compatívem com minha placa(NE2000 PCI ou Realtek).
12.2 – comando lsmod = exibe os módulos ativos (carregados atualmente
no kernel linux)
lsmod
12.3 – comando rmmod = descarrega(remove) módulos que estão ativos
(carregados atualmente) no kernel linux. Esse comando é usado seguido
do módulo a ser descarregado do kernel linux
rmmod modulo-a-descarregar

– Descarrega(remove) o modulo ne relativo a placa de rede
rmmod ne
12.4 – comando depmod = retorna dependencias de modulos na saida padrão.
Pode ser armazenado em um arquivo e depois usado pelo comando modprobe
para carregar modulos. As dependencias dos modulos sao verificadas pelos
scripts em /etc/init.d usando o comando “depmod -a” e o resultado é
gravado no arquivo “/lib/modules/versao-do-kernel/modules.dep”. Esta
checagem serve para que todas as dependencias de modulos estejam
corretamente disponiveis na inicializacao do sistema.
depmod -a

depmod module1.o module2.o
12.5 – comando modinfo = exibe uma lista de parametros que um módulo(driver)
possui

modinfo -p 3c59x

debug:3c59x debug level (0-6)
options:3c59x: Bits 0-3: media type, bit 4: bus mastering, bit 9: full duplex
global_options:3c59x: same as options, but applies to all NICs if options is unset
full_duplex:3c59x full duplex setting(s) (1)

modinfo 3c59x

filename: /lib/modules/2.6.8-2-686-smp/kernel/drivers/net/3c59x.ko
author: Donald Becker <becker@scyld.com>
description: 3Com 3c59x/3c9xx ethernet driver LK1.1.19 10 Nov 2002
license: GPL
vermagic: 2.6.8-2-686-smp SMP preempt 686 gcc-3.3
depends:
alias: pci:v000010B7d00005900sv*sd*bc*sc*i*

#######################################################################

13 – COMANDOS DE REDIRECIONAMENTO E PIPE
—————————————-
Tente ao invés de somente “>” use “2> /arquivo”. Normalmente o “>”
somente pega a saida de comandos executados com sucesso em quanto
o “2>” eh a saida de erro padrão.

13.1 – “>” = redireciona a saída de um programa/comando/script para algum
dispositivo ou arquivo ao invés do dispositivo de saída padrão(monitor de
video). Quando é usado com arquivos este redirecionamento cria ou substitui
o conteúdo do arquivo

EX: você pode usar o comando “ls” para listar arquivos e usar
ls > listagem.txt
para enviar a saída do comando para o arquivo listagem.txt
O mesmo comando pode ser redirecionado para o segundo console “/dev/tty2”
usando:
ls > /dev/tty2
o resultado do comando “ls” será exibido no segundo console
13.2 – “>>” = redireciona a saída de um programa/comando/script para algum
dispositivo ou final de arquivo ao invés do dispositivo de saída padrão
(monitor de video). A diferença entre este redirecionamento duplo e o
simples, é se caso for usado com arquivos, adiciona a saída do comando
ao final do arquivo existente ao invés de substituir seu conteúdo.

EX: você pode acrescentar a saída do comando “ls” ao arquivo listagem.txt
do capítulo anterior usando:
ls / >> listagem.txt
O mesmo comando pode ser redirecionado para o segundo console “/dev/tty2”
usando:
ls > /dev/tty2
o resultado do comando “ls” será exibido no segundo console
13.3 – “<” = direciona a entrada padrão de arquivo/dispositivo para um
comando. Este comando faz o contrário do anterior ele envia dados ao comando.
Você pode usar o comando
cat < file4.txt
para enviar o conteúdo do arquivo “file4.txt” ao comando “cat” que mostrará
seu conteúdo
13.4 – “2>” = redireciona a saida de erro padrao
/usr/programa1.sh 2> /home/arquivos/erros.txt = envia a saida de erro padrao
do comando programa1.sh para o arquivo erros.txt
13.5 – “&>” = envia a saida padrao e tambem o erro padrao para um
determinado arquivo
13.6 – “2>>” = o direcionamento não destrutivo dá um append(adicionamento)
de sua saída de erro no arquivo erros.txt – script 2>> erros.txt
13.7 – “|” (pipe) = envia a saída de um comando para a entrada do próximo
comando para continuidade do processamento. Os dados enviados são processados
pelo próximo comando que mostrará o resultado do processamento.

EX:
ls -la | more = este comando faz a listagem longa de arquivos que é enviado
ao comando `more’ (que tem a função de efetuar uma pausa a cada 25 linhas
do arquivo).

A principal diferença entre o “|” e o “>”, é que o Pipe envolve processamento
entre comandos, a saída de um comando é enviado a entrada do próximo e o
“>” redireciona a saída de um comando para um arquivo/dispositivo.

Você pode notar pelo exemplo acima “ls -la | more” que ambos “ls” e “more”
são comandos porque estão separados por um “|” Se um deles não existir ou
estiver digitado incorretamente, será mostrada uma mensagem de erro.

Um resultado diferente seria obtido usando um “>” no lugar do “|” A saída
do comando “ls -la” seria gravada em um arquivo chamado “more”.

#######################################################################

14 – TECLAS DE ATALHO DO KDE 3.X
—————————————-
ALT + F1 = exibe o menu de opcoes do KDe 3.x

ALT + F2 = exibe a janela “Comando de execução” para que
você digite um comando à executar

ALT + F3 = tem a mesma função do botão direito do mouse

ALT + F4 = fecha(encerra) um determinado programa em uso

ALT + TAB = exibe uma janela para escolher outro programa
que esteja rodando em background.

#######################################################################

15 – METACARACTERES
——————-
Os metacaracteres são caracteres que representam o nome de um
grupo de arquivos.

* = substitui todos os caracteres
[] = intervalo de caracteres
? = substitui por um caracter qualquer

#######################################################################

16 – COMANDOS PARA GRAVAÇÃO DE CD’S
———————————–
16.1 – comando mkisofs = permite criar imagens ISO a partir de um
diretório no HD
mkisofs -r -J -o arquivoISO.iso /usr/imagem1/

-r: permite que qualquer cliente possa ler o conteúdo do arquivo e também
evita problemas ao tentar ler o arquivo no Win

-J: mais uma opção para manter compatibilidade com o Win ativando as
extensões Joilet

-o: especifica o nome do arquivo ISO que será criado

arquivoISO.iso: nome do arquivo ISO. Nunca esqueça de incluir a
extensão ‘.iso’. O arquivo é criado no diretório corrente

/usr/imagem1/: diretório onde estão os arquivos que serão incluidos
no arquivo ISO ‘arquivoISO.iso’
16.2 – comando cdrecord = permite gravar arquivos em um CDR[W]

– Exibe informações durante a gravação (-v), especifica o tamanho do buffer
na memória RAM em MegaBytes. Substitua o 16 por um número menor caso você
tenha pouca memória RAM (-fs=16), a velocidade de gravação. Pode ser qualquer
número suportado pelo gravador. Graças ao cache de memória é à multitarefa
real, o Linux oferece uma tolerância muito maior durante a gravação. Quase
sempre você conseguirá gravar a 6x ou mais, mesmo que continue usando o
PC normalmente o que não é recomendável (speed=6), especifica a localização
do gravador. O ‘0,0,0’ é o padrão para gravadores IDE na maioria das dis-
tribuições (dev=0,0,0). Se não funcionar, use o comando ‘cdrecord -scanbus’
para visualizar onde está instalado o seu gravador, especifica o arquivo
ISO que será gravado (-data), o nome do arquivo imagem que será gravado
(arquivoISO.iso)
cdrecord -v -fs=16M speed=6 dev=0,0,0 -data arquivoISO.iso
– Efetua a cópia de todas as musicas wav para o CDR
cdrecord -v -fs=16M speed=8 dev=0,0,0 -audio *

– Efetua a cópia das faixas(arquivos) “01.wav”, “04.wav”, “09.wav”
cdrecord -v -fs=16M speed=8 dev=0,0,0 -audio 01.wav 04.wav 09.wav
16.3 – comando dd = para copiar um CD já gravado, você deve primeiro gerar
a imagem do conteúdo deste CD usando o comando dd e, em seguida, gravá-lo
normalmente usando o comando cdrecord. Para gerar uma imagem digite

dd if=/dev/cdrom of=/imagemCD.iso
O comando acima serve apenas para copiar CD’s de dados, pois faz uma cópia
exata do mesmo, coisa impossível de ser realizada em um CD musical, onde
não existem os códigos de correção de erro necessários.
16.4 – comando cdparanoia = para copiar CD’s musicais pode-se usar o ripador
cdparanoia. Para ripar todas as faixas do CD de música, basta colocá-lo na
bandeija do seu CD-ROM e digitar:
cdparanoia -B

isto irá extrair todas as faixas do CD para o diretório corrente, ou seja,
o diretório atual que você se encontre, salvando-as com os nomes
‘track01.cdda.wav’, ‘track02.cdda.wav’ etc.

– Extrai apenas a faixa número 2 do CD musical salvando-a com o nome de
‘faixa2.wav’
cdparanoia 2 faixa2.wav

#######################################################################

17 – COMANDOS DA DISTRIBUIÇÃO DEBIAN
————————————
17.1 – comando apt-get = atualiza/instala pacotes no sistema

– Atualiza o banco de dados local do apt-get. Deve-se executar este
comando frequentemente (eu executo diariamente) para que o apt-get
busque sempre a lista de pacotes DEB mais recente
apt-get update

– Atualiza todos os pacotes que estão instalados no sistema
apt-get upgrade

– Atualiza apenas o pacote especificado
apt-get upgrade nome_do_pacote

– Checa a integridade dos pacotes do sistema, ou seja, verifica se não há
dependências quebradas
apt-get check

– Instala um novo pacote solucionando automaticamente os pacotes dos quais
o aplicativo a ser instalado depende. Caso o pacote algum-pacote já esteja
instalado, o apt-get tentará atualizá-lo
apt-get install pacote

– Para reinstalar um pacote
apt-get install –reinstall nome_do_pacote

– Saber status do cache, como versões distintas, dependências
apt-cache stats

– Para procurar um pacote
apt-cache search nome_do_pacote

– Procurar pacotes apenas pelo nome
apt-cache search –names-only nomedopacote

– Faz uma busca pelo pacote e exibe alguns dados relacionados com o pacote
apt-cache show nome-do-pacote

– Exibe mais detalhes (dependências e versão) sobre um determinado pacote
apt-cache showpkg nome_do_pacote
EX:
apt-cache showpkg kmail

– Exibe apenas os pacotes que depende
apt-cache showpkg nome_do_pacote
EX:
apt-cache depends kmail

– Instala os pacotes básicos e tenta atualizar todo o sistema
apt-get dist-upgrade

– Remove o pacote e todas as suas dependencias criadas
apt-get remove nome-do-pacote

– Remove o pacote e todas as suas dependencias criadas incluindo arquivos
de configuração
apt-get remove –purge nome-do-pacote

– Visualiza os pacotes que voce poderá atualizar
apt-get -S upgrade

– Verifica as dependências automaticamente
apt-get -f install

– Instala o kernel no sistema
apt-get -f install kernel

– Apenas efetua o download do pacote para o diretório
‘/var/cache/apt/archives’ cabendo ao usuário instalá-lo posteriormente
apt-get install -d nome_do_pacote

– Tambem instala o kernel no sistema
apt-get -f install kernel#1:2.2.18-6cl

– Para reinstalar um pacote
apt-get install –reinstall nome_do_pacote

– Para apenas fazer o download de um pacote (A opção “-d” ou
“–download-only” no apt-get faz apenas o dowload sem instalar nada)
apt-get –download-only install nome_do_pacote

– Qual pacote devo instalar pra ter o comando import?
apt-file search bin/import
imagemagick: usr/bin/import

– Adiciona o suporte ao apt para instalar pacotes via CD-ROM
apt-cdrom add

– Para remover arquivos de pacotes baixados pelo apt-get ou aptitude
(que serão armazenados no diretório /var/cache/apt/archives/) digite:
apt-get clean
apt-get autoclean

– Para fazer o download do código-fonte de um pacote (OBS: será feito
o download para o diretório atual)
apt-get source nome_do_pacote

note que serão copiados/baixados 3 arquivos
.orig.tar.gz
.dsc
.diff.gz
– Para descobrir o nome de um pacote (que não está instalado no sistema)
que um arquivo pertence
apt-file search nome_do_arquivo

OBS1: Antes disso, por favor, execute o comando
apt-file update
para atualizar a base de dados dos arquivos que os pacotes contém.

OBS2: Este comando é similar ao ‘dpkg -S’ mas exibirá os pacotes não
instalados que contêm o arquivo. Pode ser usado também para procurar
por um pacote que contém arquivos necessários que estejam faltando
quando se compila alguns programas

– Para exibir o conteúdo de um pacote
apt-file list nome_do_pacote
17.2 – comando aptitude = gerenciador de pacotes padrão do Debian GNU/Linux
versão sarge/testing. É o substituto do software ‘dselect’. Pode-se utilizar
o aptitude ao invés do apt-get para gerenciar os pacotes ‘*.deb’ no sistema.
Possui duas interfaces: baseada em menus de comandos e a outra totalmente em
modo texto, ou seja, via linha de comando.

1 – Interface via texto
———————–
– Atualiza o banco de dados local do aptitude
aptitude update

– Atualiza todos os pacotes que estão instalados no sistema
aptitude upgrade

– Para instalar um pacote
aptitude install nome_do_pacote

– Para remover um pacote instalado no sistema
aptitude remove nome_do_pacote

– Para remover um pacote instalado no sistema incluindo seus
arquivos de configuração
aptitude purge nome_do_pacote

– Para manter a versão atual de um pacote instalado no sistema, basta
digitar
aptitude hold nome_do_pacote1 nome_do_pacote2 nome_do_pacote3

Assim uma atualização do pacote selecionado não será instalado no sistema.

– Para remover arquivos de pacotes baixados pelo apt-get ou aptitude
(que serão armazenados no diretório /var/cache/apt/archives/) digite:
aptitude clean
aptitude autoclean

– Para procurar um pacote
aptitude search nome_do_pacote

– Faz uma busca pelo pacote e exibe alguns dados relacionados com o pacote
aptitude show nome-do-pacote

2 – Interface via menus
———————–
– Para executar o aptitude através da interface via menus:
aptitude

basta acessar os menus apertando a tecla tecla ‘F10’.

– Para instalar um pacote selecionado, pressione a tecla ‘+’ e logo após,
pressione a tecla ‘g’ duas vezes. Então aguarde o download e a instalação.

– Para remover um pacote instalado no sistema, basta selecioná-lo e logo
após pressionar a tecla ‘-‘. Caso você queira remover também seus arquivos
de configuração, pressione a tecla ‘_’ ao invés da tecla ‘-‘.

– Para manter a versão atual de um pacote instalado no sistema, basta
selecioná-lo e depois pressionar a tecla ‘=’. Assim uma atualização
do pacote selecionado não será instalado no sistema.

– Para remover arquivos de pacotes baixados pelo apt-get ou aptitude
(que serão armazenados no diretório /var/cache/apt/archives/) clique
na tecla ‘F10’, selecione o menu ‘Actions’ e escolha as opções
‘Clean package cache’ e depois ‘Clean obsolete files’.
17.3 – comando dpkg = ferramenta completa para gerenciamento de pacotes
utilizando o Sistema de Pacotes Debian (Debian Package System)

– Para instalar um pacote no formato ‘deb’
dpkg -i nome_do_pacote.deb
ou
dpkg –install nome_do_pacote.deb
– Para remover um pacote no formato ‘deb’ mantendo os arquivos de
configuração relacionados ao pacote
dpkg -r nome_do_pacote
ou
dpkg –remove nome_do_pacote

– Para remover um pacote no formato ‘deb’ removendo também todos os arquivos
de configuração relacionados ao pacote
dpkg -P nome_do_pacote
ou
dpkg –purge nome_do_pacote

– Para exibir detalhes sobre um determinado pacote
dpkg -p nome_do_pacote
ou
dpkg –print-avail nome_do_pacote

– Para exibir todos os pacotes instalados no computador
dpkg -l
ou
dpkg –list

– Para exibir todos os pacotes que contenham em seu nome a palavra
‘mozilla’
dpkg -l | grep mozilla
ou
dpkg –list | grep mozilla

ii kaffeine-mozil 0.4.3.1-1 mozilla plugin that lanches kaffeine for sup
ii mozilla-browse 1.7.3-5 The Mozilla Internet application suite – cor
ii mozilla-psm 1.7.3-5 The Mozilla Internet application suite – Per

mas para que o nome do pacote seja exibido por completo, basta digitar
COLUMNS=95 dpkg -l | grep mozilla

ii kaffeine-mozilla 0.4.3.1-1 mozilla plugin that lanches kaffeine for supported
ii mozilla-browser 1.7.3-5 The Mozilla Internet application suite – core and
ii mozilla-psm 1.7.3-5 The Mozilla Internet application suite – Personal

– Para exibir todos os pacotes que comecem com a palavra ‘postgre’
dpkg -l postgre*
ou
dpkg –list postgre*

Desired=Unknown/Install/Remove/Purge/Hold
| Status=Not/Installed/Config-files/Unpacked/Failed-config/Half-installed
|/ Err?=(none)/Hold/Reinst-required/X=both-problems (Status,Err: uppercase=bad)
||/ Name Version Description
+++-==================-==================-====================================================
un postgres95 <none> (no description available)
ii postgresql 7.4.6-5 object-relational SQL database management system
ii postgresql-client 7.4.6-5 front-end programs for PostgreSQL
un postgresql-contrib <none> (no description available)
un postgresql-dev <none> (no description available)
un postgresql-doc <none> (no description available)
un postgresql-pl <none> (no description available)
un postgresql-test <none> (no description available)

– Para exibir os arquivos que um determinado pacote possui
dpkg -L nome_do_pacote
ou
dpkg -listfiles nome_do_pacote

– Para exibir o nome do pacote que contem os arquivos todos os ‘kmail_*.sh’
dpkg -S kmail_*.sh
ou
dpkg –search kmail_*.sh

kmail: /usr/bin/kmail_antivir.sh
kmail: /usr/bin/kmail_sav.sh
kmail: /usr/bin/kmail_fprot.sh
kmail: /usr/bin/kmail_clamav.sh
– Para exibir uma descrição mais detalhada do pacote ‘postgresql’
dpkg -s postgresql

– Para exibir o conteúdo de um pacote DEB
dpkg -c nome_do_pacote.deb
dpkg -S /usr/include/locale.h
libc6-dev: /usr/include/locale.h

– Para exibir todos os pacotes instalados no sistema
dpkg –get-selections >> lista_de_pacotes.txt
– Para obter uma lista de pacotes instalados no sistema:
dpkg –get-selections > lista_de_pacotes.txt
#####################################################################3

ARRUMAR!!! EDER JORDAM PAREI AQUI

– Para saber as depedencias de um pacote:
apt-cache show kernel-image-2.6.10-1-k7 | grep Depends
Depends: initrd-tools (>= 0.1.76), coreutils | fileutils (>= 4.0),
module-init-tools (>= 0.9.13)

– Conta qtde de bytes no diretório:
du -Sh | tail -n 1 | awk ‘{ print $1 ” bytes no diretório” }’

– Conta qtde de bytes no total:
du -Shc | tail -n 1 | awk ‘{ print $1 ” bytes com os subdiretórios”}’

– Máquinas nesta faixa de rede:
nmap -v -Ss -o 192.168.1.0/24 ‘192.168.1.*’

– Mounting ISO Images
If you are already running Linux, you can save an ISO image to a directory
on your machine or another machine on the network. You may then mount
the ISO image to look at or copy files. To mount an ISO image, use the
following command:
mount -o loop -t iso9660 <isofilename> <mountpoint>

– Monitora a memoria
xterm -e watch -n 0 cat /proc/meminfo &

– Monitora o uptime (quanto tempo ja esta ligado):
xterm -e watch -n 0 cat /proc/uptime &
– Apaga a rota desconhecida:
route del -net 169.254.0.0 netmask 255.255.0.0 eth1
– Exibindo a licenca de um software:
rpm -qi yast2 | grep -E ‘(Name|License)’
Name : yast2 Relocations: /usr
Size : 1074160 License: GPL
iptables -L = exibe as regras
iptables -F = limpa as regras
iptables -t nat -L = exibe as regras de NAT
iptables -t nat -F = limpa as regras de NAT
iptables -L -vn -t filter = exibe a tabela filter

2. “bz2” é geralmente extensão de arquivo compactado com o bzip2.
“gz” é geralmente extensão de arquivo compactado com o gzip
“tar” é geralmente extensão de arquivos aglutinados com o tar
“md5” é geralmente extensão do arquivo com o hash MD5 para verificar
a integridade dos arquivos distribuídos
– Exibe todos os processos que estao sendo executados na maquina:
ps -a

iptables -A OUTPUT -s 10.1.67.21 -d http://www.unipac.br -j DROP
ou
iptables -A OUTPUT -d http://www.unipac.br -j DROP

comando lsof -i = exibe todas as portas que estao sendo usadas

pstree – mostra uma árvore ordenada do que esta em execução no momento.
Uma alternativa para o “ps”.

socklist – mostra uma lista dos sockets abertos. Para se ter idéia, toda
comunicação é feita através de sockets.

vmstat – um relatório sobre a utilização da memória. A primeira vista
parece ser bastante completo, não se restringindo a utilização da memória
$ dpkg -S `which passwd`; # PRA ver o nome do pacote que mexe com senhas
$ dpkg -L passwd | grep bin; # PRA ver os programas do pacote
$ zcat README.debian.gz
Como saber a qual pacote, determinado arquivo pertence?

1) Para arquivos de pacotes que NÃO estão instalados: Instale o apt-file.
bash$ apt-get install apt-file
bash$ apt-file update

a) Para descobrir a qual pacote determinado arquivo pertence:
bash$ apt-file search <arquivo>
b) Para listar os arquivos que um pacote possui:
bash$ apt-file list <pacote>

2) Para arquivos de pacotes que ESTÃO instalados: use o dpkg
a) Para descobrir a qual pacote determinado arquivo pertence:
bash$ dpkg -S <arquivo>
b) Para listar os arquivos que um pacote possui:
bash$ dpkg -L <pacote>

– Exibe uma descrição das versões de todos os pacotes instalados:
dpkg –list
ou
dpkg -l
– Exibe uma descrição do pacote ‘php4’:
dpkg –list ‘php4’
– Exibe uma descrição detalhada do pacote ‘php4’:
dpkg –status php4
– Para exibir o nome do pacote .deb (desde que o mesmo esteja instalado
no sistema) que contem um determinado arquivo:
dpkg –search nome_do_arquivo
Este comando é equivalente a procurar todos os arquivos que possuam a
extensão ‘.list’ no diretório ‘/var/lib/dpkg/info/’
– Para obter o código fonte de um determinado pacote:
apt-get source nome_do_pacote

– Para exibir a ajuda do comando ‘dpkg’:
dpkg –help
– Para exibir o arquivo de controle de um pacote .deb:
dpkg –info nome_do_pacote.deb
– Para instalar um pacote .deb:
dpkg –install nome_do_pacote.deb
– Para extrair um único arquivo chamado ‘imagem.jpg’:
dpkg –fsys-tarfile nome_do_pacote.deb | tar -xf – imagem.jpg
– Para remover um pacote instalado no sistema (este comando não
remove os arquivos de configuração do pacote):
dpkg –remove nome_do_pacote
– Para remover um pacote instalado no sistema incluindo todos os
seus arquivos de configuração:
dpkg –purge nome_do_pacote
– Para forçar a remoção de um pacote instalado no sistema incluindo
todos os seus arquivos de configuração:
dpkg –purge –force-remove-essential nome_do_pacote
– Para exibir o estado de instalação dos pacotes instalados no sistema
contendo a string (ou expressão regular) ‘php*’:
dpkg –list ‘php*’
– O programa ‘dpkg-deb’ serve para manipular arquivos de pacotes .deb.
Para exibir a ajuda do comando ‘dpkg-deb’:
dpkg-deb –help
– Para exibir todos os arquivos que estão contidos em pacote .deb:
dpkg-deb –contens nome_do_pacote.deb
– Para extrair todos os arquivos contidos em um pacote .deb para
um determinado diretorio no sistema:
dpkg-deb –extract nome_do_pacote.deb /tmp/pacotes/pacote1

Excelente caso você deseje visualizar e manipular o conteúdo de
um pacote .deb sem ter que instalá-lo no sistema.
– Depois de atualizar o Debian GNU/Linux com os comandos:
apt-get update
e
apt-get upgrade

digite:
apt-get clean

para apagar os pacotes ‘.deb’ que foram baixados para o seu computador.
Assim liberará espaço no disco rígido (HD).

Procure assim:
dpkg -S ipatables

* ou *
dpkg -l *iptables*

Aparecerão todos os arquivos deste pacote e voce poderá verificar onde
se encontram os scripts que procura.

#######################################################################

comando locale = a base de dados do locate é atualizada apenas uma vez
por dia, é um job cron que roda (normalmente) as 4 e pouco da manha. Se
voce deixa seu micro desligado de noite, voce vai receber uns avisos quando
ela estiver a mais de 8 dias sem atualizar a base de dados. Nesses casos,
basta rodar o comando ‘updatedb’ como root antes de usar o locate.

#######################################################################

comando showmount = exibe os pontos de montagem (protocolo NFS) de uma
máquina na rede. EX:

showmount -a 192.168.0.23

All mount points on 192.168.0.23:
jordan.chicago:/home/edersg

#######################################################################

Bloqueando usúarios com o usermod
———————————
Para bloquear um usuário temporariamente com o comando “usermod” é muito
simples. Por exemplo, tenho um usuário chamado “casa” e quero que este
usuário fique um tempo sem acessar o sistema. Para isso abro um terminal
e digito o seguinte comando:
# usermod -L casa

Com este comando o usuário perde o acesso ao sistema temporariamente. Agora
eu quero que este usuário volte a ter acesso ao sistema. Então, digito o
seguinte comando:
# usermod -U casa

Este comando pode ser muito útil. Por exemplo: Tenho um usuário que ficará
temporariamente fora da empresa, então, em vez de excluir a conta deste
usuário, eu simplesmente “desativo” esta conta por um tempo.

#######################################################################

>Um estagiário aqui na empresa recebeu a função de fazer backup dos
>servidores de firewall, no arquivo ‘excluir’ tinha a lista para o tar
>não copiar e segundo ele:
>- Eu sei fazer o backup com as duas mãos nas costas!!!
>
>Só que o infeliz colocou a opção ‘–exclude-from=excluir’ no lugar
>errado e foi criado um arquivo ‘–exclude-from=excluir’ que não apaga
>de jeito nenhum, alguém tem uma solução para este problema?

Você quer dizer isso:
$ ls -l
total 0
– -rw-rw-r– 1 thiago thiago 0 2004-12-17 17:09 –exclude-from=excluir

E aí:
$ rm –exclude-from\=excluir
rm: opção não reconhecida `–exclude-from=excluir’
Try `rm –help’ for more information.

É isso?

Soluções:
$ rm $PWD/–exclude-from\=excluir
$ rm ./–exclude-from\=excluir
$ rm — –exclude-from\=excluir

Ou use um gerenciador de arquivos.

Dica: opções SEMPRE precedem os nomes de arquivos:
$ touch abc
$ ls
abc
$ ls -l abc
– -rw-rw-r– 1 thiago thiago 0 2004-12-17 17:11 abc
$ ls abc -l
– -rw-rw-r– 1 thiago thiago 0 2004-12-17 17:11 abc
$ export POSIXLY_CORRECT=1
$ ls -l abc
– -rw-rw-r– 1 thiago thiago 0 2004-12-17 17:11 abc
$ ls abc -l
ls: -l: Arquivo ou diretório não encontrado
abc

################################################################

> To precisando de arrumar um jeito de copiar uma serie de
> arquivos que estão listados em um arquivo .txt
> Já procurei na sintaxe do cp e não vi nenhuma opção para isto.
> Se alguém tiver alguma sugestão,
> valeu.

Use crases, como no exemplo:

cp `cat arquivo.txt` /tmp

################################################################

Comandos de impressão!!!

Para limpar a fila de impressão:
lprm

Para exibir a fila de impressão:
lpstat

################################################################

O que eh o SUDO?
Sudo habilita usuarios nao privilegiados a executarem tarefas que
por default o usuario nao poderia faze-la.

O que o SUDO me oferece?
– Dar permissoes de “root” a um usuario que necessite fazer algo
importante,mas somente nos comandos realmente necessitados.

– Fazer auditoria dos comandos utilizados pelo usuario, ja que o SUDO cria
um log claro de facil interpretacao.

Arquivo de configuracao do Sudo?
É o /etc/sudoers

Abaixo exemplo:
[root@queen /root]# cat /etc/sudoers
# sudoers file.
#
# This file MUST be edited with the ‘visudo’ command as root.
#
# See the sudoers man page for the details on how to write a sudoers file.
#
# Host alias specification
# User alias specification
# Cmnd alias specification
# Defaults specification
# User privilege specification
root ALL=(ALL) ALL
# Uncomment to allow people in group wheel to run all commands
# %wheel ALL=(ALL) ALL
# Same thing without a password
# %wheel ALL=(ALL) NOPASSWD: ALL
# Samples
# %users ALL=/sbin/mount /cdrom,/sbin/umount /cdrom
# %users localhost=/sbin/shutdown -h now

Exemplos de uso do SUDO:
————————
1-) Vamos imaginar a situacao: voce tem um admin que precisar mudar as
senhas dos usuario (mail, ftp, shell), mas voce nao confia nele o
suficiente para dar root. O que fazer? Usuaremos o usuario spooker como
sendo o admin (voce podem me dar root ta? Ehehehhe).

Num primeiro momento, se eu tentasse mudar a senha de um usuario do server
logado como spooker (vou usar usuario spookerlabs).
[spooker@queen spooker]$ sudo passwd spookerlabs
spooker is not in the sudoers file. This incident will be reported.

[spooker@queen spooker]$

Perfeito!!! =)))) Era pra dar isso mesmo. Mas agora, quero que meu admin
possa mudar a senha de qualquer um dos meus usuario. Primeiramente edite
o arquivo /etc/sudoers e adicione a seguinte entrada.
spooker ALL = /usr/bin/passwd [A-z]* , ! /usr/bin/passwd root

Adicionando isso, veja o que acontece:

[spooker@queen spooker]$ sudo passwd spookerlabs

We trust you have received the usual lecture from the local System
Administrator. It usually boils down to these two things:

# 1) Respect the privacy of others.
# 2) Think before you type.
Password:
Changing password for user spookerlabs
New password:
BAD PASSWORD: it does not contain enough DIFFERENT characters
Retype new password:
passwd: all authentication tokens updated successfully

[spooker@queen spooker]$

Ele me pedira meu password novamente, para ter certeza que eh o usuario
sentado na frente da shell, e depois pedira pra entrar com o novo password.
Pronto …nosso “admin” agora pode adminstrar as contas de FTP, mail!

Entendendo um pouco a linha adicionada, primeiramente vem o nome do usuario
que tera direto a usar o comando, segundo a partir de qual host e apos isso
o comando(o ! /usr/bin/passwd root exclui a possibilidade de mudar a senha
do root =PP ).
2-) Vamos imaginar que voce quer que um grupo possa executar determinados
comandos. Considerando que o grupo seria spookerteam, ao inves de somente
colocar o nome do usuario como coloquei no exemplo assim,colocaria o sinal
de porcentagem (%) seguido do nome do grupo.

%spookerteam ALL = /usr/bin/passwd [A-z]* , ! /usr/bin/passwd root

Conclusao:
———-
O texto é totalmente basico , e voce pode usar o comando que quiser e
necessitar, como iptables, shutdown entre muitos outros. Somente fiz uma
visao rapida, e quem sabe com isso voces nao leiam alguma leitura avancada
e usem e abusem dessa execelente ferramenta. Criticas, sugestoes sao bem
vindas!

################################################################

login = Faz o login no sistema.

login -h mercurio = faz o login no computador chamado mercurio
logout = Faz o logout no sistema.
exit = Encerra a sessao atual.
shutdown = Desliga ou reinicia o sistema com agendamento.

shutdown -t 30 -h 19:00 = o sistema sera desligado para manutencao.
Este comando envia um aviso (-t) 30 segundos antes de desligar o
sistema (-h) as 19:00 horas e envia uma mensagem personalizada.

halt = Desliga o sistema imediatamente.
poweroff = Desliga o sistema imediatamente.
reboot = Reinicia o sistema imediatamente.

Listar pastas
$ ls */ -d

Copiar um pasta
$ cp -R pasta

Lista partiçoes
$ df -hT

Número de arquivos em uma pasta
$ ls |wc -l

Tamanho dos arquivos de uma pasta (MB)
$ ls -lh

Tamanho de um pasta (MB)
$ du -sh

Processos que impedem de desmontar (busy)
$ fuser -mv /dev/X (onde X é partição)

* Comando uptime = exibe o tempo que o servidor está no ar sem ser
desligado.

* Cria os diretórios ‘joao’, ‘maria’, ‘jose’, e ‘jordan’ dentro
do diretório ‘home’:
mkdir /home/{joao,maria,jose,jordan}

touch -t 10011230 teste = altera data e hora do arquivo para
01/10 e 12:30

touch -t 120112301999 = altada a data, hora, ano e segundos
do arquivo para 01/12/1999 e 12:30:30
cd ~ = retorna ao diretório home do usuário
cd / = retorna ao diretório raiz
cd – = volta ao diretório acessado anteriormente
cd .. = sobre um diretório
cd ../diretorio = sobe um diretório e entra imediatamente no segundo
cat -n arquivo.txt = exibe o número de linhas enquanto o conteúdo
do arquivo é exibido

cat -s = não exibe mais que uma linha em branco
df -m = exibe o espaço em MB
import -w root -quality 85 /home/edersg/imagem1.png

Pacote sysutils
===============
Colaboração: Rubens Queiroz de Almeida

O pacote sysutils da distribuição Debian, contém um aplicativo
bastante útil chamado fromdos, que realiza funções de
conversão de formatos entre sistemas Unix e Dos.

Por default, ele elimina todos os CR (carriage return)
de um arquivo e permite também o caminho reverso, isto é,
a conversão do formato Unix para DOS.
# fromdos -u fromdos.txt
# cat -v fromdos.txt
Usage: fromdos [options] [file…]^M
-a Always convert (DOS to Unix: kill all CRs;^M
Unix to DOS: convert all LFs to CRLFs)^M
-b Make backup of original file (.bak).^M
-d Convert DOS to Unix.^M
-e Abort processing files on error in any file.^M
-f Force: convert even if file is not writeable.^M
-h Display help on usage and quit.^M
-o Overwrite original file (no backup).^M
-p Preserve file owner and time.^M
-u Convert Unix to DOS.^M
-v Verbose.^M
-V Show version and quit.^M
^M
Usamos o comando cat com a opção -v, para que os
caracteres não imprimíveis sejam exibidos na tela.

Note o caractere ^M no final de cada linha. Este caractere
indica o <CR><LF> (Carriage Return, Line Feed), indicativo
de final de linha em arquivos gerados em sistemas DOS e
posteriores.

Para remover este caractere e voltar para o formato Unix:
# fromdos fromdos.txt
# cat -v fromdos.txt
Usage: fromdos [options] [file…]
-a Always convert (DOS to Unix: kill all CRs;
Unix to DOS: convert all LFs to CRLFs)
-b Make backup of original file (.bak).
-d Convert DOS to Unix.
-e Abort processing files on error in any file.
-f Force: convert even if file is not writeable.
-h Display help on usage and quit.
-o Overwrite original file (no backup).
-p Preserve file owner and time.
-u Convert Unix to DOS.
-v Verbose.
-V Show version and quit.
O pacote sysutils é originário de sistemas BSD. Além do programa fromdos, ele
traz também os programas lsdev e procinfo. O programa fromdos pode também
ser invocado através dos nomes dos2unix, unix2dos e todos. Eu particularmente
conhecia os nomes dos2unix e unix2dos que são mais intuitivos.

É claro que este comando realiza tarefas extremamente simples e que podem ser
feitas muito bem por sed, e outros, porém eu sempre gostei de ter este comando
ao meu alcance.

Para quem usa outros sistemas e desejar usar este pacote, eu coloquei o fonte em
http://www.Dicas-L.unicamp.br/download/sysutils_1.3.8.5.1.tar.gz

É só fazer o download e se divertir.
Comando top:
————
Tente ordenar por consumo de memória no TOP, apertando M.
Veja qual processo está consumindo a memória e utilize o comando lsof
para ver o que esse processo está utilizando.
lsof -p PID
dpkg –get-selections > ~/perfil_pacotes_final.txt = ???
http://lists.debian.org/debian-user-portuguese/2005/02/msg00369.html
O arquivo ‘squid.conf’ original está no diretório
‘/usr/share/doc/squid/examples/’. Veja:

dpkg -L squid | grep squid.conf
> Gostaria de uma ajuda, para saber qual a forma que eu posso usar para saber
> todos os arquivos de um servidor que foram mudados no dia de ontem ou
> acessados, e se existe a possibilidade de se criar um aquivo dizendo quais
> foram os arquivos mudados ou acessados.

Utilize o comando:

find / -atime 1 e $find / -ctime 1
Todos os arquivos modificados no último dia:

find / -mtime -1

Todos os arquivos acessados nas últimas 24h:

find / -atime
Para descobrir os arquivos acessados nas últimas 24h, visualizando na tela e
ao mesmo tempo armazenando em um arquivo txt:

find / -atime -1 -type f | tee lista-de-arquivos-acessados.txt
Para descobrir os arquivos alterados nas últimas 24h, visualizando na tela e
ao mesmo tempo armazenando em um arquivo txt:

find / -mtime -1 -type f | tee lista-de-arquivos-alterados.txt
Qualquer que seja o método usado para atualização, recomenda-se que
você verifique o estado de todos os pacotes antes, e verifique se
todos os pacotes estão em um estado atualizável. O comando seguinte
exibirá qualquer pacote cujo estado seja de semi-instalado ou falha na
configuração, e aqueles com qualquer estado de erro.

# dpkg –audit

Você também pode inspecionar o estado de todos os pacotes em seu
sistema usando o `dselect’, o `aptitude’ ou com comandos como

# dpkg -l | pager

ou

# dpkg –get-selections > ~/curr-pkgs.txt
É desejável remover qualquer hold antes da atualização. Se algum
pacote essencial para a atualização estiver em hold, a atualização
falhará. Você pode identificar pacotes em hold com

# dpkg –audit

Se você mudou e recompilou um pacote localmente, e não mudou seu nome
nem colocou uma data na versão, você deve colocá-lo em hold para
evitar que seja atualizado. O estado `hold’ do pacote pode ser
alterado usando o `aptitude’. Com

aptitude hold | unhold <package>

Novas versões de pacotes já instalados que não podem ser atualizados
sem mudar o estado de instalação de outro pacote serão deixados na
versão atual (exibidos como “held back” ou “mantidos”).
Isso pode ser
resolvido usando o `aptitude’ para selecionar esses pacotes para
instalação ou tentando o comando `aptitude -f install <package>’.

A opção `–fix-broken’ (ou apenas `-f’) faz com que o `apt’ tente
corrigir um sistema com dependências quebradas. O `apt’ não permite
que existam dependências quebradas em um sistema.

Algumas vezes é necessário habilitar a opção APT::Force-LoopBreak no
APT para poder remover temporariamente um pacote essencial devido a um
loop de Conflitos/Pré-Dependências. O `aptitude’ o alertará sobre
isso e abortará a atualização. Você pode resolver isso especificando
a opção `-o APT::Force-LoopBreak=1′ na linha de comando do `aptitude’.

É possível que a estrutura de dependências de um sistema possa estar
tão corrompida que a ponto de requerer intervenção manual. Geralmente
isso significa usar o `aptitude’ ou

dpkg –remove <nome_do_pacote>

para eliminar alguns dos pacotes problemáticos, ou

aptitude –fix-broken install
dpkg –configure –pending

Em casos extremos você pode ter que forçar a reinstalação com um
comando como

dpkg –install /caminho/para/nome_do_pacote.deb
Depois de consertar as coisas, você deve ser capaz de terminar a
atualização repetindo os comandos `aptitude’ previamente descritos.
Para configurar o teclado no debian:

dpkg-reconfigure console-data

– Para colocar uma imagem como wallpaper do desktop:

Esetroot -center imagem.jpg
Tente usar o seguinte comando no seu script:

who|grep alex|wc -l

esse comando irá retornar a quantidade de seções para o usuario “alex”
com base nisso você pode fazer um pequeno if para verificar se seu
usuario está logado antes de executar o ppp e o bittorrent, algo como:

TESTE=`who|grep alex|wc -l`
if [ $TESTE -eq 0 ]
then
Conecta
Autentica
Iniciar_torrent
else
echo “Usuario alex logado, Abortando…”
fi

podes incrementar o script utilizando o comando sleep e um loop para
que, se o usuario estiver logado, ele aguarda 10 minutos e testa
novamente se voce ainda está logado, assim, quando voce fizer o LOGOUT
depois que o script foi disparado pelo cron, ele inicia o bittorrent e a
conexao.

Subject: Re: (linux-br)Cadê o libGL.la no Conectiva?

$ rpm -qf /usr/lib/libGL.la
libgl-xfree86-devel-4.4.0-63152U10_3cl

apt-get install libgl-xfree86-devel
usermod -L usuario = bloqueia o acesso do usuario temporariamente
usermod -U usuario = desbloqueia o acesso do usuario
import -window root imagem.png = tira um screenshot da tela

> Qual o comando similar ao “rpm -qf pacote.rpm” para ser usado no
> debian ?

dpkg-query -L pacote
Para procurar o pacote:

apt-cache search string => procura na lista de repositórios por pacotes
com string
apt-cache show pacote => exibe informações sobre o pacote
apt-get install pacote => instala o pacote

Para informações sobre o pacote instalado:

dpkg -S string => exibe os pacotes instalados que possuem string
dpkg -c pacote => exibe quais arquivos pertencem a um pacote instalado.
Aqui você tem que fornecer o caminho completo para o pacote. Normalmente
após baixados com apt-get os pacotes ficam em /var/cache/apt/archives/,
assim este comando deve ser algo como:

dpkg -c /var/cache/apt/archives/pacote

* comandos uteis:
apt-cache search palavra (tipo apropos)

apt-cache show package_name (mostra info do pacote(s))

apt-get -u install package_name (instala pacote mostrando o q vai atualizar)

apt-get -u –reinstall install package_name (reinstalar pacote)

apt-get -t unstable -u install package_name (esse é legal! instala um pacote
qquer do unstable – tipo, eu peguei o mozilla por aqui. O legal eh q jah cria
icone no menu e tudo, mto pratico. Lembre-se de adicionar um mirror unstable
no seu sources.list)

dpkg -l (lista todos os pacotes = rpm -qa)

dpkg -L package_name (lista os arquivos do pacote)

dpkg-reconfigure package_name (qdo vc quiser voltar pra aquela tela azul que
reconfigura alguma coisa, use esse comando. Ex:
dpkg-reconfigure xserver-xfree86 )

apt-get update (pra atualizar a lista de pacotes existentes nos servidores)

apt-get upgrade (pra atualizar os pacotes instalados)

A maioria dos comandos apt-get vc pode substituir por aptitude:
http://people.debian.org/~andrelop/txt/aptitude-tips-pt_BR.txt

Rode o comando:

base-config

no base config vai em “select and install packages” (selecionar e
instalar pacotes). Marca o “Desktop environment” (ambiente desktop)
e clica no OK.
– Exibe todas as placas PCI digite
———————————————
lspci
lspci -v
lspci -vv
lspci -vvv
– Para impedir que a proteção de tela do terminal seja executada depois de
um certo tempo de inatividade:
setterm -blank 0
setterm -powersave off

No lugar do 0 voce pode especificar os minutos… quando coloca 0 fica
desabilitado. No X: desative seu protetor de telas e DPMS. Caso você não
tenha um widget de controle do DPMS, o seguinte comando também o desativa:
xset -dpms
comando rename = altera a extensão de um arquivo.
rename .htm .html *.htm = substitui todos os arquivos terminados em .htm
por .html.

ls
jose.txt joseovaldo.txt josenir.txt
rename jose joao jose.???
ls
joao.txt josenir.txt joseovaldo.txt
rename jose ricardo *ovaldo.txt
```
