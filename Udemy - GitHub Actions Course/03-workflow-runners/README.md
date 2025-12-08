# GitHub Actions Runners

GitHub Actions provides the flexibility to run your workflows on different types of runners. Runners are the compute environments where your workflow jobs execute. There are two main categories of runners: GitHub-hosted runners and self-hosted runners.

## GitHub-Hosted Runners

### What are GitHub-Hosted Runners?

GitHub-hosted runners are virtual machines provided and managed by GitHub. They are available for your use without the need for any additional setup. These runners come in various environments, including Ubuntu, Windows, and macOS, allowing you to build, test, and deploy your code in a familiar environment.

### Key Aspects of GitHub-Hosted Runners

- **Availability**: GitHub-hosted runners are readily available, making them a convenient choice for many projects.

- **Maintenance**: GitHub takes care of the maintenance, updates, and scaling of these runners, ensuring they are always up to date and available for your workflows.

- **Usage Limitations**: There are usage limitations for GitHub-hosted runners, including maximum execution time and the number of concurrent jobs per repository.

## Self-Hosted Runners

### What are Self-Hosted Runners?

Self-hosted runners are machines that you provision and manage yourself, either on your own infrastructure or in a cloud environment. These runners give you full control over the runner environment, allowing you to customize it to match your project's specific requirements.

### Key Aspects of Self-Hosted Runners

- **Customization**: Self-hosted runners can be customized with the software, tools, and configurations needed for your project. This makes them suitable for projects with specific dependencies or hardware requirements.

- **Security**: You have full control over the security and access controls of self-hosted runners. You can choose where they run and who has access to them.

- **Maintenance**: Self-hosted runners require ongoing maintenance, including updates and monitoring, which is your responsibility.

## Choosing Between GitHub-Hosted and Self-Hosted Runners

The choice between GitHub-hosted and self-hosted runners depends on your project's needs:

- Use **GitHub-Hosted Runners** if your project is hosted on GitHub, and you need a convenient and managed environment for common use cases. These runners are a great choice for most projects.

- Use **Self-Hosted Runners** if you require custom configurations, have specific hardware requirements, or need full control over the runner environment. Self-hosted runners are suitable for complex or specialized projects.

## Configuring Runners in Your Workflow

You can specify the runner environment for your workflow jobs using the `runs-on` key in your workflow configuration file (e.g., `.github/workflows/main.yml`). Here's an example:

```yaml
jobs:
  build:
    runs-on: ubuntu-latest
    # ...
```