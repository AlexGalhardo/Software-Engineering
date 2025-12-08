---
sidebar_position: 2
---

# (Optional) Setting the environment

:::warning

You don't need to set up the environment on your computer to follow this guide; use this page only if your personal
preference is to run the code locally on your computer. The exercises can be executed directly from the browser.

:::

If you're new to TypeScript, don't worry! We'll provide explanations and examples every step of the way to help you
understand the fundamentals. If you're already familiar with TypeScript, you can skip this getting started and jump
straight to the content.

### What you'll need

- [Node.js](https://nodejs.org/en/download/) version 20.0 or above:
  - When installing Node.js, you are recommended to check all checkboxes related to dependencies.
  - After installation, verify that the commands `node -v` and `npm -v` are functioning in your terminal. You may need to restart your system for these commands to work properly.
- Any code editor or IDE of your choice. We recommend using [Visual Studio Code](https://code.visualstudio.com/), but here are some other popular options:
  - [Fleet](https://www.jetbrains.com/fleet/)
  - [WebStorm](https://www.jetbrains.com/webstorm/)
  - [Zed](https://zed.dev/)
  - [Sublime Text](https://www.sublimetext.com/)

:::info

You may want to install a version manager for Node.js, such as [nvm](https://github.com/nvm-sh/nvm) or [nvm-windows](https://github.com/coreybutler/nvm-windows). These tools allow you to switch between different versions of Node.js easily, being very useful when working on multiple projects with different Node.js versions.

:::

### Running TypeScript code

To run TypeScript code, you need to have TypeScript installed. Below are the installation methods:

#### 1. Project installation (recommended):
  - Create an empty directory for your project, and navigate to it in your terminal.
  - Run the following commands in your terminal:
    ```bash
    npm init -y
    npm install typescript tsx -D
    ```
  - After installation, ensure that the commands `npx tsc -v` and `npx tsx -v` are functioning in your terminal, returning the version of TypeScript installed.

#### 2. Global installation:
  - Run the following command in your terminal:
    ```bash
    npm install typescript tsx -g
    ```
  - After installation, ensure that the commands `tsc -v` and `tsx -v` are functioning in your terminal, returning the version of TypeScript installed.

The first approach is recommended because it allows you to have different versions of TypeScript for different projects. The `npx` prefix runs the TypeScript version installed in the project's `node_modules` directory.

Having it installed globally is also fine, but it's not recommended because it can lead to version conflicts between projects.

:::important

If you're using the project installation method, you need to run the commands related to `tsc` and `tsx` with the `npx` prefix in the project's directory. If you're using the global installation method, you can run the `tsc` or `tsx` command from any directory.
The guide will use the `npx` prefix for the project installation method, so make sure to remove the `npx` prefix if you're using the global installation method.

:::

#### 3. Hello World

Create a new file named `hello.ts` with the following content:

```typescript
const message: string = 'Hello, world!'
console.log(message)
```

With the terminal open in the same directory as the file, run the following command:

```bash
npx tsx hello.ts
```

You should see the following output if everything is set up correctly:

```bash
Hello, world!
```

### Optional: Running TypeScript code directly with Visual Studio Code

If you wish to execute TypeScript code within VSCode, you'll need to install the [ts-node](https://www.npmjs.com/package/ts-node) package globally and the Code Runner extension. Execute the following command in your terminal:

```bash
npm i -g ts-node
```

Next, install the [Code Runner](https://marketplace.visualstudio.com/items?itemName=formulahendry.code-runner) extension in VSCode. Once installed, you can run your code by right-clicking on the editor and selecting Run Code, or by pressing Ctrl + Alt + N, or by clicking on the run icon in the top right corner.

### What is tsc, tsx, npm and npx?

- `tsc` is the TypeScript compiler. It compiles TypeScript code to JavaScript code. If you run in your terminal `tsc hello.ts`, it will generate a `hello.js` file.
- `tsx` is a TypeScript runner. It compiles and runs TypeScript code. If you run in your terminal `tsx hello.ts`, it will compile and run the `hello.ts` file, without generating a `hello.js` file.
- `npm` is the Node.js package manager. It is used to install and manage packages. It comes with Node.js, so you don't need to install it separately.
- `npx` is a package runner tool that comes with npm. It is used to execute packages without installing them globally. You will use it to run installed packages in your project's `node_modules` directory.
