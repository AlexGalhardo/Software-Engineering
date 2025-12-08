# Working with Matrices in GitHub Actions

A matrix strategy in GitHub Actions allows you to define variations for each job by using variables. This feature is incredibly useful when you need to test your code across multiple versions of a language or on different operating systems.

## About Matrix Strategies

Matrix strategies enable you to use variables in a single job definition to create multiple job runs based on combinations of those variables. For instance, you can use a matrix to test your code in multiple versions of a language (e.g., Node.js) or on various operating systems.

## Using a Matrix Strategy

To create a matrix in your GitHub Actions workflow, use `jobs.<job_id>.strategy.matrix`. Within your matrix, define one or more variables followed by an array of values. For example:

```yaml
jobs:
  example_matrix:
    strategy:
      matrix:
        version: ['16.x', '18.x', '20.x']
        os: [ubuntu-latest, windows-latest]
```

In this example, your workflow will run six jobs, one for each combination of the version and os variables.

The variables defined in your matrix become properties in the `matrix` context. You can reference these properties in other areas of your workflow file. For instance, you can use `matrix.version` and `matrix.os` to access the current values of version and os that the job is using.

## Adding or Removing Matrix Configurations

You can expand existing matrix configurations or add new ones using `jobs.<job_id>.strategy.matrix.include`. This allows you to include additional key-value pairs for matrix combinations without overwriting any original matrix values.

To remove specific configurations from the matrix, use `jobs.<job_id>.strategy.matrix.exclude`. Excluded configurations do not run.

## Handling Failures

You can control how job failures are handled with jobs.`<job_id>.strategy.fail-fast` and `jobs.<job_id>.continue-on-error`. These settings enable you to decide whether a job failure should affect the entire matrix and whether specific jobs should continue running after a failure.