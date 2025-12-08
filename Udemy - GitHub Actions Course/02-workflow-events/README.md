# GitHub Actions Workflow Triggers

GitHub Actions workflows are triggered by specific events that occur within your repository. These triggers define when a workflow should run, automating various tasks like continuous integration, testing, and deployment.

Here are some common triggers for GitHub Actions workflows:

## 1. Push Events

Trigger a workflow when code is pushed to a specific branch.

Example YAML:
```yaml
on:
  push:
    branches:
      - main
      - release/*
```

## 2. Pull Request Events

Trigger a workflow when pull requests are opened, updated, or synchronized.

Example YAML:

```yaml
on:
  pull_request:
    branches:
      - main
```

## 3. Scheduled Events

Schedule workflows to run at specific times or intervals using cron expressions.

Example YAML:

```yaml
on:
  schedule:
    - cron: '0 0 * * *' # Run every day at midnight UTC
```

## 4. Issue Comment Events

Trigger workflows when comments are made on issues or pull requests.

Example YAML:

```yaml
on:
  issue_comment:
    types:
      - created
```

## 5. Webhook Events

Trigger workflows in response to custom webhook payloads sent to your repository.

Example YAML:

```yaml
on:
  repository_dispatch:
    types:
      - my-custom-event
```

## 6. Manual Triggers
   
Allow manual triggering of workflows through the GitHub Actions UI or API.

Example YAML:

```yaml
on:
  workflow_dispatch:
```

These examples demonstrate various ways to trigger GitHub Actions workflows based on specific events and conditions. You can customize them to suit your project's needs and automate your development processes effectively.
