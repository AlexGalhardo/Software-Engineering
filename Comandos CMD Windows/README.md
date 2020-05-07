## Windows CMD Commands

 - A maioria dos comando tem seus atributos(parâmetro), e para saber como usa-las basta colocar na frente do comando o   /? , com isso ele abrirá o ajuda(Help) do comando digitado. Exemplo: dir /? 

#### Source/Credits: https://tutorti.com.br/portal/todos-comandos-do-prompt-de-comando-do-windows/

```
Mudando a cor do prompt temporariamente
A opção /t:fg executada no campo de pesquisa do menu iniciar ou pela função executar(WinKey+R) permite alterar as cores do prompt de comando temporariamente. Por exemplo, digite cmd /t:0A e a tela ficar com o fundo preto e as letras verde claro. O f representa a cor do fundo e o g a cor do texto, ao fecha e abrir ele novamente, mas dessa fez usando somente o comando cmd, o prompt de comando aparecerá original(texto cinza e  fundo preto).

Relação das cores a serem usada:

0 – preto
1 – Azul
2 – Verde
3 – Ciano
4 – Vermelho
5 – Roxo
6 – Amarelo
7 – Branco
8 – Cinza
9 – Azul claro
A – Verde claro
B – Ciano claro
C – Vermelho claro
D – Roxo claro
E – Amarelo claro
F – Branco claro

DIR: – Listando arquivos e pastas
COPY: – Copiar arquivos
MOVE: Mover arquivos ou renomear pastas
MD:– Criar uma Nova pasta
CD: Entrar em uma pasta
CD..: Retornar para a pasta anterior
RD:  Remover pastas
Erase: Deletar arquivos
del:  Deletar arquivos
ren: Renomear arquivos (EX: ren imagem.jpg foto.jpg)
TIME:  O comando time permite acertar a hora e o comando date permite corrigir a data.
Bootcfg: Permite ver as configurações do seu menu de boot
Defrag: Desfragmentador de disco.
Diskpart: Gerencia as partições de um disco.
Driverquery: Mostra a lista de drivers instalados no Windows e as respectivas propriedades.
Fsutil: O comando fsutil tem vários complementos que serão listados digitando-o sem nenhum parâmetro. Digite fsutil fsingo drives e terá a lista dos drives no seu micro.(executar o cmd como administrador)
Gepresult: Este comando mostrará configurações de usuários e de diretivas de grupos.
Recover: Permite a recuperação de arquvios em disco danificado.
Reg: Comando para exportar chaves do registro, copiar, restaurar, comparar, etc.
Schtasks: Para agendar, executar, alterar ou deletar tarefas numa máquina local ou remota com Windows.
SFC: Comando que permite verificar arquivos de sistemas alterados de forma indevida e recuperar os arquivos originais e oficiais da Microsoft., o que nem sempre será recomendável. Por exemplo, o arquivo uxtheme.dll modificado para permitir o uso de temas voltaria a ser substituído pelo original.
Shutdown: O comando shutdown permite desligar ou reiniciar o computador de forma imediata ou agendada.
Systeminfo: Fornece informações básicas sobre o sistema.
Tasklist: Mostra a lista de processos sendo executados no Windows.
Taskkill: Permite finalizar algum processo. O comando é quase sempre usado com base nas informações fornecidas pelo tasklist. Por exemplo, para finalizar o Messenger digite “taskkill /PID 1680”. A identificação do PID de cada processo sendo executado você ficará sabendo com o comando tasklist.
ASSOC: Exibe ou modifica associações de extensões de arquivo.
AT: Agenda comandos e programas para serem executados em um computador.
ATTRIB: Exibe ou altera atributos de arquivos.
BOOTCFG: Mostra o boot.ini no prompt de comando
BREAK: Define ou limpa a verificação estendida CTRL+C.
CACLS: Exibe ou modifica listas de controle de acesso (ACLs) de arquivos.
CALL: Chama um programa em lotes a partir de outro.
CHCP: Exibe ou define o número da página de código ativa.
CHKDSK: Verifica um disco e exibe um relatório de status.
CHKNTFS: Exibe ou modifica a verificação do disco na inicialização.
CLS: Limpa a tela
CMD: Abre uma outra janela de prompt.
COLOR: Define as cores padrão de primeiro plano e do plano de fundo do console
COMP: Compara o conteúdo de dois arquivos ou grupos de arquivos.
COMPACT: Exibe ou altera a compactação de arquivos.
CONVERT: Converte volumes FAT em NTFS.
COPY: Copia um ou mais arquivos para outro local.
DATE: Mostra a data atual e permite alterá-la.
DISKCOMP: Compara o conteúdo de dois disquetes.
DISKCOPY: Copia o conteúdo de um disquete para outro.
DISKPART: Faz particionamento de disco
DOSKEY: Edita linhas de comando, volta a chamar comandos do Windows e cria macros.
ECHO: Exibe mensagens ou ativa ou desativa o eco de comandos.
ENDLOCAL: Encerra a localização de alterações de ambiente em um arquivo em lotes.
EXIT: Sai do programa CMD.EXE (interpretador de comandos).
FC: Compara dois arquivos ou grupos de arquivos e exibe as diferenças entre eles.
FIND: Procura uma seqüência de texto em um arquivo ou arquivos.
FINDSTR: Procura seqüências de texto em arquivos.
FOR: Executa um determinado comando para cada arquivo em um grupo de arquivos.
FORMAT: Formata um disco rígido ou disquete.
FTYPE: Exibe ou modifica os tipos de arquivo utilizados em associações de extensões de arquivos.
GOTO: Direciona o interpretador de comandos do Windows para uma linha identificada em um programa em lotes.
GRAFTABL: Permite que o Windows exiba um conjunto de caracteres estendidos em modo gráfico.
HELP: Fornece informações de ajuda sobre comandos do Windows.
HOSTNAME: Dá o nome do host
IF: Realiza processamento condicional em arquivos em lotes.
IPCONFIG: Mostra detalhes das configurações de IP
LABEL: Cria, altera ou exclui o rótulo de volume de um disco.
MODE: Configura um dispositivo do sistema.
MORE: Exibe a saída fazendo pausa a cada tela.
MOVE: Move um ou mais arquivos de uma pasta para outra pasta.
PAGEFILECONFIG: Configura memória virtual
PATH: Exibe ou define um caminho de pesquisa para arquivos executáveis.
PAUSE: Suspende o processamento de um arquivo em lotes e exibe uma mensagem.
PING: Checa sua conexão de rede disponível
POPD: Restaura o valor anterior da pasta atual salva por PUSHD.
PRINT: Imprime um arquivo de texto.
PROMPT: Altera o prompt de comando do Windows.
PUSHD: Salva a pasta atual e, em seguida, altera a mesma.
REM: Grava comentários (observações) em arquivos em lotes.
REPLACE: Substitui arquivos.
ROUT: Mostra detalhes do parâmetro da interface de rede
SCHTASKS: Agenda e executa algum processo
SET: Exibe, define ou remove variáveis de ambiente do Windows.
SETLOCAL: Inicia a localização de alterações de ambiente em um arquivo em lotes.
SHIFT: Altera a posição dos parâmetros substituíveis em um arquivo em lotes.
SORT: Classifica a entrada.
START: Inicia uma janela separada para executar um programa ou comando especificado.
SUBST: Associa um caminho a uma letra de unidade.
TITLE: Define o título da janela para uma sessão do CMD.EXE.
TREE: Exibe graficamente a estrutura de pastas de uma unidade ou caminho.
TYPE: Exibe o conteúdo de um arquivo de texto.
VER: Mostra a versão do Windows.
VERIFY: Faz com que o Windows verifique se os arquivos estão gravados corretamente em um disco.
VOL: Exibe um rótulo e número de série de volume de disco.
XCOPY: Copia diretórios com seus subdiretórios.

Os comandos abaixo listam comandos adicionais do Windows XP Pro:
eventcreate: Permite ao administrador criar uma mensagem e identificação do evento personalizadas em um log de eventos especificado.
eventquery: Lista os eventos ou as propriedades de um evento de um ou mais arquivo log.
eventtriggers: Mostra e configura disparadores de evento.
getmac: Mostra o endereço MAC de um ou mais adaptador de rede.
helpctr: Inicia o Centro de Ajuda e Suporte.
ipseccmd: Configura o Internet Protocol Security (IPSec)
logman: Gerencia o serviço Logs e alertas de desempenho.
openfiles: Busca, mostra ou termina arquivos abertos compartilhados.
pagefileconfig: Mostra e configura a memória virtual.
perfmon: Abre o monitor do sistema.
prncnfg: Configure ou mostra as configurações de impressora.
prndrvr: Adiciona, deleta e lista drivers de impressoras.
prnjobs: Pausa, continua ou cancela lista de documentos a serem impressos.
prnmngr: Adiciona, deleta e lista impressoras conectadas, além da impressora default.
prnport: Cria, deleta e lista portas de impressora TCP/IP
prnqctl: Imprime uma página de teste, pausa ou reinicia um documento a ser impresso.
schtasks: Permite que um administrador crie, exclua, consulte, altere, execute e termine tarefas agendadas em um sistema local ou remoto.
systeminfo: Busca no sistema informação sobre configurações básicas.
typeperf: grava dados de desempenho na janela de comando ou em um arquivo de log. Para interromper Typeperf, pressione CTRL+C.




 

Comandos do Painel de controle
ACCESS.CPL: abre as opções de acesso
APPWIZ.CPL: abre a ferramenta Adicionar/Excluir um programa
AZMAN.MSC: abre o gerenciador de autorizações (Só no Vista)
CERTMGR.MSC: abre os certificados para o usuário atual
CLICONFG: abre a configuração dos clientes SQL
COLLAB.CPL: abre a vizinhança imediata (Só no Vista)
COMEXP.MSC ou DCOMCNFG: abre a ferramenta serviços e componentes (Só no Vista)
COMPMGMT.MSC: abre a ferramenta de gestão do computador
COMPUTERDEFAULTS: abre a ferramenta dos programas padrão (Só no Vista)
CONTROL /NAME MICROSOFT.BACKUPANDRESTORECENTER: abre o centro de backup e de restauração (Só no Vista).
CONTROL ADMINTOOLS: abre as ferramentas de administração
CONTROL COLOR: abre as configurações de aparência
CONTROL FOLDERS: abre as opções de pastas
CONTROL FONTS: abre o gerenciador de caracteres
CONTROL INTERNATIONAL ou INTL.CPL: abre as opções regionais e linguísticas
CONTROL KEYBOARD: abre as propriedades do teclado
CONTROL MOUSE ou MAIN.CPL: abre as propriedades do mouse
CONTROL PRINTERS: abre as impressoras e os faxes disponíveis
CONTROL USERPASSWORDS: abre o editor de contas dos usuários
CONTROL USERPASSWORDS2 ou NETPLWIZ: controla os usuários e seus acessos
CONTROL: abre o Painel de controle
CREDWIZ: abre a ferramenta de backup e de restauração de senhas dos usuários (Só no Vista)
DESK.CPL: abre as configurações de exibição
DEVMGMT.MSC: abre o gerenciador de periféricos.
DRWTSN32: abre o Dr. Watson (Só no XP)
DXDIAG: abre a ferramenta de diagnóstico DirectX
EVENTVWR ou EVENTVWR.MSC: abre o observador de eventos
FSMGMT.MSC: abre as pastas compartilhadas
GPEDIT.MSC: abre o editor de estratégias de grupo (Para as edições profissionais e mais do Windows)
HDWWIZ.CPL: abre o assistente “adicionar hardware”
INFOCARDCPL.CPL: abre o assistente “compatibilidade de programas”
IRPROPS.CPL: abre o gerenciador de infravermelho
ISCSICPL: abre a ferramenta de configuração do iniciador ISCI Microsoft (Só no Vista)
JOY.CPL: abre a ferramenta do controlador de jogos
LPKSETUP: abre o assistente de instalação e desinstalação dos idiomas de exibição (Só no Vista)
LUSRMGR.MSC: abre o editor dos usuários e grupos locais
MDSCHED: abre a ferramenta de diagnósticos da memória Windows (Só no Vista)
MMC: abre um novo console vazio
MMSYS.CPL: abre as configurações de som
MOBSYNC: abre o centro de sincronização
MSCONFIG: abre a ferramenta de configuração do sistema
NAPCLCFG.MSC: abre a ferramenta de configuração do cliente NAP (Só no Vista)
NTMSMGR.MSC: abre o gerenciador de suporte de armazenamento removível
NTMSOPRQ.MSC: abre as solicitações do operador de armazenamento removível
ODBCAD32: abre o administrador de fonte de dados ODBC
OPÇÃOALFEATURES: abre a ferramenta Adicionar/Excluír componentes do Windows (Só no Vista)
PERFMON ou PERFMON.MSC: abre o monitor de confiabilidade e de desempenho Windows.
POWERCFG.CPL: abre o gerenciador de modos de alimentação (Só no Vista)
REGEDITou REGEDT32: abre o editor de registro (Só no Vista)
REKEYWIZ: abre o gerenciador de certificados de criptografia de arquivos (Só no Vista)
RSOP.MSC: abre o jogo de estratégia resultante
SECPOL.MSC: abre as configurações de segurança local
SERVICES.MSC: abre o gerenciador de serviços
SLUI: abre o assistente de ativação do Windows (Só no Vista)
SYSDM.CPL: abre as propriedades do sistema
SYSEDIT: abre o editor de configuração do sistema (Atenção, manipular com cautela)
SYSKEY: abre o utilitário de proteção do banco de dados das contas Windows (Atenção, manipular com extrema cautela !)
SYSPREP: abre a pasta com a ferramenta de preparação do sistema (Só no Vista)
TABLETPC.CPL: abre as configurações para o Tablet pc (Só no Vista)
TASKSCHD.MSC ou CONTROL SCHEDTASKS: abre o planejador de tarefas (Só no Vista)
TELEPHON.CPL: abre a ferramenta de conexão telefônica
TIMEDATE.CPL: abre as configurações da hora e da data
TPM.MSC: abre a ferramenta de gestão do módulo de plataforma segura no computador local (Só no Vista)
UTILMAN: abre as opções de ergonomia (Só no Vista)
VERIFICAR: abre o gerenciador de verificação dos drivers
WMIMGMT.MSC: abre o “Windows Management Infrastructure”
WSCUI.CPL: abre o centro de segurança Windows
WUAUCPL.CPL: abre o serviço de atualização do Windows (Só no XP)




 

Comandos de Programas e ferramentas Windows
%WINDIR%\SYSTEM32\RESTORE\RSTRUI.EXE: abre a ferramenta de restauração do sistema (Só no XP).
CALC: abre a calculadora
CHARMAP: abre a tabela de caracteres
CLIPBRD: abre a área de transferência (Só no XP, para adicionar no Vista
CMD: abra o interpretador de comandos (prompt)
DIALER: abre o numerador telefônico do Windows
DVDPLAY: abre seu leitor DVD
EUDCEDIT: abre o editor de caracteres privados
EXPLORER: abre o Windows Explorer
FSQUIRT: Assistente de transferência Bluetooth
IEXPLORE: abre Internet Explorer
IEXPRESS: abre o assistente de criação dos arquivos auto-extraíveis.
JOURNAL: abre um novo registrador (Só no Vista)
MAGNIFY: abre a lupa
MBLCTR: abre o centro de mobilidade do Windows (Só no Vista)
MIGWIZ: abre a ferramenta de transferência de arquivos e de configurações Windows (Só no Vista)
MIGWIZ.EXE: abre a ferramenta de transferência de arquivos e de configurações Windows (Só no XP)
MOVIEMK: abre o Windows Movie Maker
MRT: executa o utilitário de remoção de malwares.
MSDT: abre a ferramenta de diagnósticos e suporte da Microsoft
MSINFO32: abre as informações do sistema
MSPAINT: abre o “Paint”
MSRA: abre a assistência remota do Windows
MSTSC: abre a ferramenta de conexão da assistência remota
NOTEPAD: abre o bloco de notas
OSK: abre o teclado visual.
PRINTBRMUI: abre o assistente de migração da impressora (Só no Vista)
RSTRUI: abre a ferramenta de restauração do sistema (Só no Vista)
SIDEBAR: abre o sidebar do Windows (Só no Vista)
SIGVERIF: abre a ferramenta de verificação das assinaturas de arquivos
SNDVOL: abre o misturador de volume
SNIPPINGTOOL: abre a ferramenta captura de tela (Só no Vista).
SOUNDRECORDER: abre o gravador
STIKYNOT: abre o post-it (Só no Vista)
TABTIP: abre o painel de entrada Tablet PC (Só no Vista)
TASKMGR: abre o gerenciador de tarefas do Windows
WAB: abre os contatos (Só no Vista)
WERCON: abre a ferramenta de relatórios e de soluções de problemas (Só no Vista)
WINCAL: abre o calendário do Windows (Só no Vista)
WINCHAT: abre o software Microsoft de bate-papo (chat) na net (Só no XP)
WINDOWSANYTIMEUPGRADE: permite a atualização do Windows Vista
WINVER: abre a janela para que você conheça a versão do seu Windows
WINWORD: abre o Word (se estiver instalado)
WMPLAYER: abre o leitor Windows Media
WRITE ou Wordpad: abre o Wordpad

Comandos de Gestão de discos
CHKDSK: realiza uma análise da partição especificada nas configurações do comando (Para mais informações, digite CHKDSK /? no interpretador de comandos CMD)
CLEANMGR: abre a ferramenta de limpeza do disco
DEFRAG: Desfragmenta o disco rígido
DFRG.MSC: abre a ferramenta de desfragmentação do disco
DISKMGMT.MSC: abre o gerenciador de discos
DISKPART: abre a ferramenta de particionamento (manipulação pesada)

Comandos de Gestão das redes e Internet
CONTROL NETCONNECTIONS ou NCPA.CPL: abre as conexões da rede
FIREWALL.CPL: abre o firewall do Windows
INETCPL.CPL: abre as propriedades da internet
IPCONFIG: exibe as configuraçãos dos endereços IP no computador
NETSETUP.CPL: abre o assistente de configuração de rede (Só no XP)
WF.MSC: abre as funções avançadas do firewall do Windows (Só no Vista)

Atalhos e comandos
%HOMEDRIVE%: abre o explorador na partição onde o sistema operacional está instalado
%HOMEPATH%: abre a pasta do usuário conectado C:\Documents and settings\[nome do usuário]
%PROGRAMFILES%: abre a pasta de instalação de outros programas (Program Files)
%TEMP% ou %TMP%: abre a pasta temporária
%USERPROFILE%: abre a pasta do perfil do usuário conectado
%WINDIR% ou %SYSTEMROOT% : abre a pasta de instalação do Windows
%WINDIR%\system32\rundll32.exe shell32.dll,Control_RunDLL hotplug.dll: exibe a janela “Retirar o dispositivo com segurança”
AC3FILTER.CPL: abre as propriedades do filtro AC3 (se estiver instalado)
FIREFOX: executa Mozilla FireFox (se estiver instalado)
JAVAWS: Visualiza o cache do software JAVA (se estiver instalado)
LOGOFF: fecha a sessão
NETPROJ: autoriza ou não a conexão a um projetor de rede (Só no Vista)
SFC /SCANNOW: varre, imediatamente, todos os arquivos do sistema e localiza os que estão danificados
SFC/VERIFYONLY: varre apenas os arquivos do sistema
SFC/SCANFILE=”nome e caminho do arquivo”: varre o arquivo especificado e repara, caso esteja danificado
SFC/VERIFYFILE=”nome e caminho do arquivo”: varre apenas o arquivo especificado
SFC/SCANONCE: varre os arquivos do sistema no arranque seguinte
SFC/REVERT: repõe a configuração inicial (Para mais informações, digite SFC /? no interpretador de comandos
SHUTDOWN: desliga o Windows
SHUTDOWN-A: interrompe a desconexão do Windows
VSP1CLN: remove o cache de instalação do serviço pack 1 do Vista

Driverquery:  O driverquery é uma ferramenta que fornece informações sobre os drivers de hardware instalados em seu computador. Você pode usar o comando driverquery -v ou driverquery -si

Powercfg:  é um comando que lhe ajuda a habilitar recursos e obter várias informações sobre a energia do computador, como habilitar a hibernação e obter informações sobre o consumo de energia do Windows.

Pathping: O “pathping” é uma versão avançada do ping que exibe várias informações sobre a rota dos pacotes e lhe ajuda a descobrir onde está o problema. Como o ping, digite “pathping” + o nome ou o endereço IP do host.



 

Outros Comandos:
Abre filtro AC3 (se instalado) = ac3filter.cpl
Acerca do Windows (Ver a versão do Windows) = winver
Actualizações automáticas = wuaucpl.cpl
Adicionar ou remover programas = appwiz.cpl
Administrador da origem de dados de ODBC = odbccp32.cpl
Ajuda e suporte = msinfo32
Armazenamento amovível = ntmsmgr.msc
Assistente de acessibilidade = accwiz
Assistente de câmara ou scanner = wiaacmgr
Assistente de configuração de rede = netsetup.cpl
Assistente de cópia de segurança ou restauro = ntbackup
Assistente de ligação à Internet = icwconn1 / inetwiz
Assistente de transferência de definições e de ficheiros = migwiz
Assistente de transferência de ficheiros do Bluetooth = fsquirt
Assistente para adicionar hardware = hdwwiz.cpl
Calculadora= calc
Centro de segurança do Windows = wscui.cpl
Certificados = certmgr.msc
Cliente Telnet = telnet
Configuração de protocolo de Internet (apagar informações de DNS ) = ipconfig /flushdns
Configuração de protocolo de Internet (Todas as conexões ) = ipconfig /release
Configuração de protocolo de Internet (ver DNS ) = ipconfig /displaydns
Configuração de protocolo de Internet (ver tudo) = ipconfig /all
Configuração de protocolo de Internet (Modificar DHCP Class ID) = ipconfig /setclassid
Configuração do IP = ipconfig
Conjunto de politicas resultante (XP Prof) = rsop.msc
Constas de utilizadores = nusrmgr.cpl
Controladores de jogos = joy.cpl
Definições da segurança local = secpol.msc
Desfragmentador do disco = dfrg.msc
Desliga o utilizador do Windows = logoff
Editor de carácter privado = eudcedit
Editor de configuração do sistema = sysedit
Editor de registo = regedit / regedit32
Encerramento do Windows = shutdown
Explorador do Windows = explorer
Ferramenta de diagnóstico do Direct X = dxdiag
Ferramenta de importação de livro de endereços = wabmig
Ferramenta de remoção de software malicioso Microsoft Windows = mrt
Ferramentas administrativas = control admintools
Firewall do Windows = firewall.cpl
Fontes = fonts
Gestão de computadores = compmgmt.msc
Gestão de discos = diskmgmt.msc
Gestor de dispositivos = devmgmt.msc
Gestor de objectos – pacote = packager
Gestor de partições do disco = diskpart
Gestor de tarefas do Windows = taskmgr
Gestor de utilitários = utilman
Gestor de verificador de controladores = verifier
HyperTerminal = hypertrm
Iexpress Wizard = iexpress
Impressoras e faxes = control printers
Infra-estrutura de gestão do Windows = wmimgmt.msc
Iniciar Windows Update = wupdmgr
Itens a sincronizar = mobsync
Internet Explorer = iexplore
Introdução do Windows XP = tourstart
Jogo de cartas Copas = mshearts
Jogo de cartas FreeCell = freecell
Jogo de cartas Spider Solitare = spider
Jogo Minesweeper = winmine
Ligação ao ambiente de trabalho remoto = mstsc
Ligações de rede = ncpa.cpl / control netconnections
Limpeza do disco = cleanmgr
Linha de comandos = cmd
Lista telefónica = rasphone
Livro de endereços = wab
Mapa de caracteres = charmap
Marcador telefónico = dialer
Microsoft Access (se instalado ) = access.cpl
Microsoft Chat = winchat
Microsoft Excel (se instalado ) = excel
Microsoft Frontpage (se instalado ) = frontpg
Microsoft Movie Maker = moviemk
Microsoft Paint = mspaint
Microsoft Powerpoint (se instalado ) = powerpnt
Microsoft Word (se instalado ) = winword
Nero (se instalado) = nero
Netmeeting = conf
Notepad = notepad
Nview Desktop Manager (se instalado) = nvtuicpl.cpl
Opções de acessibilidade = access.cpl
Opções de pastas = control folders
Opções regionais e de idioma = intl.cpl
Outlook Express = msimn
Painel de controlo = control
Painel de controlo Direct X (se instalado) = directx.cpl
Painel de controlo Java (se instalado) = jpicpl32.cpl
Paint = pbrush
Partilhas DDE = ddeshare
Pasta de impressoras = printers
Pastas partilhadas = fsmgmt.msc
Pedidos do operador de armazenamento amovível = ntmsoprq.msc
Performance Monitor = perfmon
Performance Monitor = perfmon.msc
Phone and Modem Options = telephon.cpl
Pinball para Windows = pinball
Politica de grupo (XP Prof) = gpedit.msc
Power Configuration = powercfg.cpl
Procura rápida (quando ligada) = findfast.cpl
Propriedade des visualização = control color
Propriedades da internet = inetcpl.cpl
Propriedades de data e hora = timedate.cpl
Propriedades de senhas = password.cpl
Propriedades de som e dispositivos de áudio = mmsys.cpl
Propriedades de visualização = control desktop/desk.cpl
Propriedades do Mouse = main.cpl / control mouse
Propriedades do sistema = sysdm.cpl
Propriedades do teclado = control keyboard
Protecção de base de dados do Windows = syskey
Protecção de ficheiros do Windows (analisar em cada arranque) sfc /scanboot
Protecção de ficheiros do Windows (analisar no próximo arranque) = sfc /scanonce
Protecção de ficheiros do Windows (analisar) = sfc /scannow
Protecção de ficheiros do Windows (repor configuração de fábrica) = sfc /revert
Quicktime (se instalado) = QuickTime.cpl
Real Player (se instalado) = realplay
Scanners e câmaras = sticpl.cpl
Serviço de indexação = ciadv.msc
Serviços = services.msc
Serviços componentes = dcomcnfg
Tarefas agendadas = control schedtasks
Teclado Virtual = osk
Tipos de letra = control fonts
Tweak UI (se instalado ) = tweakui
Utilitário de configuração do sistema = msconfig
Utilitário de rede do cliente de SQL Server = cliconfg
Utilitário de verificação de ficheiros do sistema = sfc
Utilitário de verificação do disco = chkdsk
Utilitário Dr. Watson para o Windows = drwtsn32
Utilizadores e grupos locais = lusrmgr.msc
Verificação de assinatura do ficheiro = sigverif
Visualizador da área de armazenamento = clipbrd
Visualizador de aplicações de java (se instalado) = javaws
Visualizador de eventos = eventvwr.msc
Windows Magnifier = magnify
Windows Media Player = wmplayer
Windows Messenger (Executar MSN) = msmsgs
Windows XP Tour Wizard (Tour Windows) = tourstart
Wordpad = write
```