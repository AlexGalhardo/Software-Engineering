# Reusable Workflows in GitHub Actions

Reusable workflows in GitHub Actions allow you to create modular, shareable workflow components that can be utilized across multiple repositories and workflows. These reusable workflows can help streamline your CI/CD processes and make your workflows more maintainable. This README provides an overview of key concepts and usage.

## Creating a Reusable Workflow

1. **Workflow File:** Reusable workflows are defined in YAML-formatted files, similar to regular workflow files. Place these files in the `.github/workflows` directory of your repository.

2. **`on` Event:** For a workflow to be reusable, include `workflow_call` in its `on` event. This specifies that the workflow can be called by other workflows.

3. **Inputs and Secrets:** Reusable workflows can accept inputs and secrets, which can be passed from the caller workflow and used within the called workflow. Define these inputs and secrets using the `inputs` and `secrets` keywords.

Here's an example:

```yaml
on:
  workflow_call:
    inputs:
      config-path:
        required: true
        type: string
    secrets:
      token:
        required: true
```

## Calling a Reusable Workflow

To call a reusable workflow within a workflow, use the uses keyword. Unlike actions, reusable workflows are called directly within a job, not from within job steps:

```yaml

jobs:
  call-reusable-workflow:
    uses: ./.github/workflows/reusable-workflow.yaml
```

## Passing Inputs and Secrets
To pass inputs to a reusable workflow, use the `with` keyword, and to specify secrets use the `secrets` keyword:

```yaml

jobs:
  call-reusable-workflow:
    uses: ./.github/workflows/reusable-workflow.yaml
    with:
      input-value: "hello world"
    secrets:
      secret-value: "I will not be visible"
```

## Using Outputs from a Reusable Workflow

You can capture outputs from a reusable workflow and use them in the caller workflow. The process is very similar to using outputs between different dependent jobs in the same workflow file, but here you also have to specify the outputs under the `outputs` keyword in the `workflow_call` definition. 

```yaml
# Reusable Workflow
on:
  workflow_call:
    outputs:
      my-output:
        value: ${{ jobs.my-job.outputs.my-output }}
        
jobs:
  my-job:
    runs-on: ubuntu-latest
    outputs:
      my-output: ${{ steps.my-step.outputs.my-output }}
    steps:
      - name: My Step
        id: my-step
        run: |
          # Do something
          echo "my-output=my-value" >> "$GITHUB_OUTPUT"
```
```yaml
# Caller Workflow
jobs:
  call-reusable-workflow:
    uses: ./.github/workflows/reusable-workflow.yaml
  use-outputs:
    needs: call-reusable-workflow
    runs-on: ubuntu-latest
    steps:
      - run: echo ${{ needs.call-reusable-workflow.outputs.my-output }}
```

## Nesting Reusable Workflows

You can nest reusable workflows, allowing a reusable workflow to call another reusable workflow. However, GitHub Actions supports only up to four levels of nesting.