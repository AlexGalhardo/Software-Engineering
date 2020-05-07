## Roadmap Software Engineering

- [Teach Yourself Programming in Ten Years - Peter Norvig](http://norvig.com/21-days.html)
- [Coding Interview University](https://github.com/jwasham/coding-interview-university)
- [Teach Yourself CS](https://teachyourselfcs.com/)
- [Web Developer Roadmap](https://github.com/kamranahmedse/developer-roadmap)

## Ferramentas Úteis

- [Anki](https://apps.ankiweb.net/)
 
 
## Algoritmos e Estrutura de Dados

 - YouTube
    - [Linguagem C Programação Descomplicada](https://www.youtube.com/user/progdescomplicada/videos)
 - Sites
    - [GeeksForGeeks](https://www.geeksforgeeks.org/)
    - [AssemblyProgressivo.net](https://www.assemblyprogressivo.net/)
- Treinamento de Código
    - [Project Euler](https://projecteuler.net/)
    - [HackerRank](https://www.hackerrank.com/)
    - [Edabit](https://edabit.com)
    - [URI Online Judge](https://www.urionlinejudge.com.br/judge/en/login)
- KhanAcademy 
   - [Computer Science](https://www.khanacademy.org/computing/computer-science)
   - [Notação assintótica](https://pt.khanacademy.org/computing/computer-science/algorithms/asymptotic-notation/a/asymptotic-notation)
- Recursão :skull:
   - [O que é recursão? Teste de Mesa com Fatorial - Softblue](https://www.youtube.com/watch?v=V60g61dhKmg)
- Visualização de Estruturas de Dados :skull:
   - [VisualGo](https://visualgo.net/en)
   - [University of San Francisco - CS](https://www.cs.usfca.edu/~galles/visualization/Algorithms.html)
- Big O Notation :skull: 
   - [bigocheatsheet.com](http://bigocheatsheet.com/)
   - [A coffee-break introduction to time complexity of algorithms](https://dev.to/vickylai/a-coffee-break-introduction-to-time-complexity-of-algorithms-160m?utm_source=digest_mailer&utm_medium=email&utm_campaign=digest_email)
   - O(1) Constant Time
      - Melhor caso possível
      - Se um algoritmo possui tempo constante, significa que sempre vai levar o mesmo tempo para produzir o resultado.
      - Exemplo: array.pop() -> tirar último item de um array, independente do tamanho, levará sempre o mesmo tempo!
   - Logarithms O(log n)
      - Preferível na maioria das vezes
      - Logaritimos são o inverso da exponenciação.
      - Exemplo: Algoritmo de busca binária -> dividir para conquistar
      - <img src="ologn.png" alt="ologn">
   - Linear time O(n)
      - Preferível na maioria das vezes
      - Se um algoritmo possui tempo linear, significa que o tempo de execução aumenta linearmente de acordo com o tamanho do input.
      - Exemplo: array.forEach() soma de todos os valores
   - Linear Logarithms O(n log n)
      - Aceitável
      ```
      x = n
      while ( x > 0 ) {
        y = x
        while ( y > 0 ) {
           y = y / 2
        }
        x -= 1
      }
      ```
      - Examples: Quicksort, Mergesort and Heapsort  -> dividir para conquistar
   - Quadratic time O(n²) :skull:
      - Bom evitar
      - O tempo de execução desse algoritmo é diretamente proporcional ao o quadrado do input.
      - Ou seja: 2->4  3->9  4->16  5->25 etc
      - Exemplo: Soma de matrizes
      ```
      for (var outer = 0; outer < elements.Count; outer++){
        for (var inner = 0; inner < elements.Count; inner++){
          ...
        }
      }
      ```
   - Exponential Time O(2^n) :skull: :skull:
      - Um dos piores casos, sempre é bom evitar
      - Indica um algoritmo cujo crescimento dobra a cada adição ao conjunto de dados de entrada. A curva de crescimento de uma função O (2N) é exponencial - começando muito rasa e depois subindo meteoricamente
      - Exemplo: recursive calculation of Fibonacci numbers
      ```
      int Fibonacci(int number){
          if (number <= 1) return number;
          return Fibonacci(number - 2) + Fibonacci(number - 1);
      }
      ```
   - Factorial Time O(n!) :skull: :skull: :skull:
     - Pior caso possível, sempre tente evitar!
     - Extremamente não perfomático
     - Vai executar em tempo fatorial para cada operação
     - Exemplo: Problema do vendedor viajante
        - "Dada uma lista de cidades e as distâncias entre cada par de cidades, qual é o caminho mais curto possível que visita cada cidade e retorna à cidade de origem?"
   - <strong>Resumo</strong>
      - <img src="big-o-names.jpeg" alt="Big(O) Names">
      - <img src="big-o-graphic.jpeg" alt="Big(O) Graphic">

## Segurança da Informação

 - Sites
    - [OWASP](https://www.owasp.org/index.php/Main_Page)
    - [EUGDPR.org](https://eugdpr.org/)
    - [LGPD - Lei Geral de Proteção de Dados Pessoais](http://www.planalto.gov.br/ccivil_03/_Ato2015-2018/2018/Lei/L13709.htm)
    - [Haveibeenpwned](https://haveibeenpwned.com/)
    - [Livro - Fundamentos de Engenharia Reversa - Mente Binária](https://mentebinaria.gitbook.io/engenharia-reversa/antes-de-comecar)
    - [Forum CaveiraTech](https://caveiratech.com/forum/)
    - [Oauth2](https://oauth.net/2/)
    - [Practical Cryptography for Developers - Free Book](https://cryptobook.nakov.com/)
 - Videos
    - [Gabriel Pato](https://www.youtube.com/channel/UC70YG2WHVxlOJRng4v-CIFQ)
    - [CaveiraTech](https://www.youtube.com/user/caveiratech2/playlists)
    - [Curso de Engenharia Reversa Online - Papo Binário](https://www.youtube.com/watch?v=IkUfXfnnKH4&list=PLIfZMtpPYFP6zLKlnyAeWY1I85VpyshAA)
 - Cursos 
    - [Fundamentos de Ethical Hacking - Udemy](https://www.udemy.com/fundamentos-de-ethical-hacking/learn/v4/)
    - [Solyd.com.br](https://solyd.com.br)
    - [Técnicas de Invasão](https://tecnicasdeinvasao.com/)
    - [Desenvolimento de Software Seguro - Curso Online Gratuito - ICA Instituto ](https://desenvolvimentoseguro.icainstituto.com.br/)
 - [DAT Protocol](https://www.datprotocol.com/)
    - [DatProject.org](https://datproject.org)
    - [Try Dat](https://try-dat.com/)
 - Banco de dados
    - World's Fastest Password Cracker
       - [HashCat](https://hashcat.net/hashcat/)
       - [HashKiller](https://hashkiller.co.uk/md5-decrypter.aspx)
    - Encriptação Recomendada
       - [Argon2](https://github.com/P-H-C/phc-winner-argon2)
       - [PBKDF2](https://en.wikipedia.org/wiki/PBKDF2)
       - [Scrypt](https://en.wikipedia.org/wiki/Scrypt)
       - [BCrypt](https://en.wikipedia.org/wiki/Bcrypt)
    - Não Recomendado :skull:
       - [MD5](https://pt.wikipedia.org/wiki/MD5)
       - [SHA1](https://www.thesslstore.com/blog/difference-sha-1-sha-2-sha-256-hash-algorithms/)
       - [SHA2](https://www.thesslstore.com/blog/difference-sha-1-sha-2-sha-256-hash-algorithms/)
       - [SHA256](https://www.thesslstore.com/blog/difference-sha-1-sha-2-sha-256-hash-algorithms/)
 - Ferramentas
    - Operation Systems
       - [Kali Linux](https://www.kali.org/)
       - [Tails Linux](https://tails.boum.org/index.pt.html)
    - Virtual Machines for Pentest
       - [PentesterLab](https://www.pentesterlab.com/exercises/)
       - [PentestBox](pentestbox.org)
          - [tools.pentestbox.org](https://tools.pentestbox.org/)
    - Transport Layer Security/Secure Sockets Layer
       - [Let's Encrypt](https://letsencrypt.org/)
    - Softwares
       - [WireShark](https://www.wireshark.org/)
       - [AngryIP Scanner](https://angryip.org/)
       - [metasploit](https://www.metasploit.com/)
	   - DataBases
	      - [Exploit-DB](https://www.exploit-db.com/)
	      - [SQLMap](http://sqlmap.org/)
	   - Useful CLI Commands
	      - [$ nmap site_url](https://nmap.org/)
	      - [$ traceroute site_url](https://www.lifewire.com/traceroute-linux-command-4092586)
        - [$ nmap localhost](https://nmap.org/)
	      - [$ curl site_url](https://curl.haxx.se/)
	      - [$ whafw00f site_url](https://github.com/EnableSecurity/wafw00f)
	      - [$ ping site_url](https://www.wikiwand.com/en/Ping)
	      - [$ host site_url](https://www.computerhope.com/unix/host.htm)
	      - [$ whois site_url](https://who.is/)
	   - Browsers
	      - [DuckDuckGo](https://duckduckgo.com)
	      - [Bernes Lee Solid](https://solid.mit.edu/)
	      - [Beaker Browser](https://beakerbrowser.com)
	      - [TorProject](https://www.torproject.org/)
	         - [TheHiddenWiki](https://thehiddenwiki.org/)
          
## Programação Funcional
  - [Aprender Haskell será um grande bem para você](http://haskell.tailorfontela.com.br/)

## Open Source
  - [OpenSource.org](https://opensource.org/)
  - [OpenSource.guide](https://opensource.guide/)
  - [Creative Commons](https://creativecommons.org/)
  - [Scrum Poker Online](https://scrumpoker.online/)