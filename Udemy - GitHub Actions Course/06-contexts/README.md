# Working with GitHub Contexts in GitHub Actions Workflows

GitHub Actions provides access to a variety of GitHub contexts that allow you to access information related to the workflow, the event that triggered it, and the repository itself. This README provides an overview of different GitHub contexts, including the `github` context, `env` context, `inputs` context, and `vars` context, and how to work with them within your workflows.

## Understanding GitHub Contexts

GitHub contexts are predefined variables that contain information about the current workflow run, the event that triggered the workflow, and the repository where the workflow is hosted. These contexts are accessible as variables and can be used to customize and parameterize your workflows.

## Common GitHub Contexts

Here are some common GitHub contexts that you can use within your workflows:

- **`github` Context**: Contains various properties related to the workflow run, event, and repository. For example, `github.event_name`, `github.ref`, and `github.sha`.

- **`env` Context**: Allows you to access environment variables and secrets securely. For example, `env.MY_SECRET`.

- **`inputs` Context**: Provides access to input variables defined in your workflow file. For example, `inputs.my_input`.

- **`vars` Context**: Provides a way to define and access workflow-level variables. For example, `vars.my_var`.

## Examples

Here are some examples of how to work with different GitHub contexts within your workflows:

### Example 1: Access `github` Context

You can access properties from the `github` context, such as the event name, reference, and SHA:

```yaml
jobs:
  build:
    runs-on: ubuntu-latest
    steps:
    - name: Display Event Information
      run: |
        echo "Event Name: ${{ github.event_name }}"
        echo "Ref: ${{ github.ref }}"
        echo "SHA: ${{ github.sha }}"
```

### Example 2: Use env Context

Access environment variables and secrets using the env context:

```yaml
jobs:
  build:
    runs-on: ubuntu-latest
    steps:
      - name: Use Secret
        run: |
          echo "My Secret: ${{ env.MY_SECRET }}"
        env:
          MY_SECRET: ${{ secrets.MY_SECRET }}
```

Example 3: Utilize inputs Context

Retrieve input values defined in your workflow using the inputs context:

[//]: # (TODO: Add link to inputs folder)

```yaml
jobs:
  build:
    runs-on: ubuntu-latest
    steps:
      - name: Use Workflow Input
        run: |
          echo "Input Value: ${{ inputs.my_input }}"
```

### Example 4: Define and Access outputs Context

Define workflow-level outputs using the `outputs` context:

```yaml
jobs:
  build:
    runs-on: ubuntu-latest
    steps:
      - name: Define Workflow Variable
        id: set_var
        run: |
          echo "Setting Workflow Variable"
          echo "name=Max" >> "$GITHUB_OUTPUT"
    - name: Use Workflow Variable
      run: |
        echo "Workflow Variable Value: ${{ steps.set_var.outputs.name }}"
```