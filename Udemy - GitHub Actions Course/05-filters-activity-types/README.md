# Using Event Filters and Activity Types

GitHub Actions workflows are highly customizable and can be triggered by various events and activities. In this guide, we'll explore how to use event filters and activity types to precisely control when your workflows run.

## Introduction

GitHub Actions allows you to automate your workflows based on specific events and activities. By defining event filters and activity types in your workflow configuration, you can precisely control when your actions run.

## Event Filters

### Using `on`

You can specify when a workflow should run by using the `on` keyword in your workflow YAML file. This is the primary way to define the event that triggers your workflow.

```yaml
on:
  push:
    branches:
      - main
```

In this example, the workflow is triggered on a push event to the main branch.

### Filtering by Event Types

GitHub Actions supports a wide range of event types, such as push, pull_request, release, and more. You can filter your workflow by these event types.

```yaml
on:
  push:
    branches:
      - main
```

### Filtering by Branches

You can further narrow down your workflow's trigger by specifying the branches on which the event should occur.

```yaml
on:
  push:
    branches:
      - main
      - feature/*
```

Here, the workflow runs on a push event to either the main branch or branches starting with "feature/."

### Filtering by Paths

If you want to trigger your workflow only when specific files or directories are modified, you can filter by paths.

```yaml
on:
  push:
    paths:
      - 'src/**'
      - 'docs/'
```

This workflow is triggered on a push event that modifies files under the src/ directory or any file or folder in the docs/ directory.

### Filtering by Tags

You can also use tags to trigger your workflow when specific tags are created.

```yaml
on:
  push:
    tags:
      - v*
```

In this example, the workflow runs when a tag starting with "v" is pushed.

## Activity Types

GitHub Actions provides several activity types per event. The best place to find a comprehensive list of all available activity types is the [GitHub Actions documentation](https://docs.github.com/en/actions/using-workflows/events-that-trigger-workflows).

### Pull Request Activity Types

Pull requests offer a variety of activity types. The example below filters the activity types down to `opened` and `synchronize`. This means that the workflow will trigger when a pull request is opened, or when a new commit is pushed to the `head` of the PR branch:

```yaml
on:
  pull_request:
    types:
      - opened
      - synchronize
```
