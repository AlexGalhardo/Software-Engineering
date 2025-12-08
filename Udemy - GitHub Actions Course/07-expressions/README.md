# Using Expressions in GitHub Actions

GitHub Actions provides a powerful feature called expressions that allows you to dynamically evaluate and manipulate data within your workflows. Expressions enable you to create more flexible and intelligent automation. This README provides an overview of how to use expressions effectively in GitHub Actions.

## Understanding Expressions

Expressions in GitHub Actions are enclosed within `${{ }}` and can be used to access and transform data from GitHub contexts, environment variables, inputs, and more. They are evaluated at runtime and can be used in various workflow scenarios, such as conditional statements, setting variables, or generating dynamic content.

## Common Use Cases

Here are some common use cases for using expressions in GitHub Actions:

### 1. Dynamic Variable Assignment

You can use expressions to assign dynamic values to variables within your workflow:

```yaml
jobs:
  build:
    runs-on: ubuntu-latest
    steps:
      - name: Set Variable Using an Expression
        run: |
          # Define a dynamic variable using an expression
          MY_VAR="Hello, ${{ github.actor }}!"

          # Use the variable in an echo statement
          echo $MY_VAR
```

## 2. Conditional Steps

Expressions allow you to create conditional steps based on GitHub context or other data:

```yaml
jobs:
  build:
    runs-on: ubuntu-latest
    steps:
      - name: Conditional Step Using an Expression
        run: |
          if [[ "${{ github.event_name }}" == "push" && "${{ github.ref }}" == "refs/heads/main" ]]; then
            echo "This is a push to the main branch."
          fi
```

We can also use expressions in `if` statements when deciding whether to execute a step or a job. Under the `if` key, we don't need to add the special `${{ <expression> }}` syntax.

```yaml
jobs:
  build:
    runs-on: ubuntu-latest
    steps:
      - name: Conditional Step Using an Expression
        if: github.event_name == "push" && github.ref == "refs/heads/main"
        run: echo "This is a push to the main branch."
```
