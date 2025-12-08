---
sidebar_position: 2
---

# (Opcional) Configurando o ambiente

:::warning

Você não precisa configurar o ambiente no seu computador para seguir este guia; use esta página apenas se sua
preferência pessoal for executar o código localmente em seu computador. Os exercícios podem ser executados diretamente
do navegador.

:::

Se você é novo no TypeScript, não se preocupe! Vamos trazer explicações e exemplos a cada passo do caminho para
ajudá-lo a entender os fundamentos. Se você já está familiarizado com TypeScript, recomendamos ir direto para a próxima
página.

### O que você vai precisar

- [Node.js](https://nodejs.org/en/download/) versão 20.0 ou superior:
  - Ao instalar o Node.js, é recomendável marcar todas as caixas de seleção relacionadas às dependências.
  - Após a instalação, verifique se os comandos `node -v` e `npm -v` estão funcionando no seu terminal. Você pode precisar reiniciar seu sistema para que esses comandos funcionem corretamente.
- Qualquer editor de código ou IDE de sua escolha. Recomendamos o uso do [Visual Studio Code](https://code.visualstudio.com/), mas aqui estão algumas outras opções populares:
  - [Fleet](https://www.jetbrains.com/fleet/)
  - [WebStorm](https://www.jetbrains.com/webstorm/)
  - [Zed](https://zed.dev/)
  - [Sublime Text](https://www.sublimetext.com/)

:::info

Você pode optar por instalar um gerenciador de versões para o Node.js, como o [nvm](https://github.com/nvm-sh/nvm) ou
[nvm-windows](https://github.com/coreybutler/nvm-windows). Essas ferramentas permitem alternar facilmente entre
diferentes versões do Node.js, sendo muito úteis ao trabalhar em vários projetos com diferentes versões do Node.js.

:::

### Executando código TypeScript

Para executar os códigos, você precisa ter o TypeScript instalado. Abaixo estão os métodos de instalação:

#### 1. Instalação por projeto (recomendado):
  - Crie um diretório vazio para o seu projeto e navegue até ele no seu terminal.
  - Execute os seguintes comandos no seu terminal:
    ```bash
    npm init -y
    npm install typescript tsx -D
    ```
  - Após a instalação, verifique se os comandos `npx tsc -v` e `npx tsx -v` estão funcionando no seu terminal, retornando a versão do TypeScript instalada.

#### 2. Instalação global:
  - Execute o seguinte comando no seu terminal:
    ```bash
    npm install typescript tsx -g
    ```
  - Após a instalação, verifique se os comandos `tsc -v` e `tsx -v` estão funcionando no seu terminal, retornando a versão do TypeScript instalada.

A primeira abordagem é recomendada porque permite ter diferentes versões do TypeScript para diferentes projetos. O prefixo `npx` executa a versão do TypeScript instalada no diretório `node_modules` do projeto.

Ter o TypeScript instalado globalmente também é aceitável, mas não é recomendado porque pode levar a conflitos de versão entre projetos.

:::important

Se você estiver usando o método de instalação no projeto, precisa executar os comandos relacionados a `tsc` e `tsx` com o prefixo `npx` no diretório do projeto. Se você estiver usando o método de instalação global, pode executar o comando `tsc` ou `tsx` de qualquer diretório.
O guia usará o prefixo `npx` para o método de instalação por projeto, então certifique-se de remover o prefixo `npx` se estiver usando o método de instalação global.

:::

#### 3. Hello World

Crie um novo arquivo chamado `hello.ts` com o seguinte conteúdo:

```typescript
const message: string = 'Hello, world!'
console.log(message)
```

Com o terminal aberto no mesmo diretório do arquivo, execute o seguinte comando:

```bash
npx tsx hello.ts
```

Você deverá ver a seguinte saída se tudo estiver configurado corretamente:

```bash
Hello, world!
```

### Opcional: Executando código TypeScript diretamente com o Visual Studio Code

Se você deseja executar código TypeScript dentro do VSCode, precisará instalar globalmente o pacote `ts-node` e a extensão Code Runner. Execute o seguinte comando no seu terminal:

```bash
npm i -g ts-node
```

Em seguida, instale a extensão [Code Runner](https://marketplace.visualstudio.com/items?itemName=formulahendry.code-runner) no VSCode. Depois de instalada, você pode executar seu código clicando com o botão direito do mouse no editor e selecionando "Run Code", ou pressionando Ctrl + Alt + N, ou clicando no ícone de execução no canto superior direito.

### O que é tsc, tsx, npm e npx?

- `tsc` é o compilador TypeScript. Ele compila código TypeScript para código JavaScript. Se você executar no seu terminal `tsc hello.ts`, ele irá gerar um arquivo `hello.js`.
- `tsx` compila e executa código TypeScript. Se você executar no seu terminal `tsx hello.ts`, ele irá compilar e executar o arquivo `hello.ts`, sem gerar um arquivo `hello.js`.
- `npm` é o gerenciador de pacotes do Node.js. É usado para instalar e gerenciar pacotes. Ele vem com o Node.js, então você não precisa instalá-lo separadamente.
- `npx` é uma ferramenta de execução de pacotes que vem com o npm. É usado para executar pacotes sem instalá-los globalmente. Você o usará para executar pacotes instalados no diretório `node_modules` do seu projeto.
