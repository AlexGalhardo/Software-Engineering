# Working with Custom Actions in GitHub Actions

GitHub Actions allows you to create custom actions, which are individual tasks that you can combine to automate your workflows. This README provides an overview of how to work with custom actions.

## About Custom Actions

Custom actions in GitHub Actions are your own tasks that interact with your repository in any way you want. You can use them to integrate with GitHub's APIs and third-party APIs. For example, you can create actions to publish npm modules, send alerts, or deploy code.

### Sharing Custom Actions

- You can create actions for your workflows or share them with the GitHub community.
- To share actions with everyone, your repository must be public.

## Types of Actions

You can build three types of actions in GitHub Actions:

1. **Composite Actions:**
    - Combine multiple workflow steps into a single action.
    - Useful for bundling multiple run commands into one action.
    - Simplify workflow configuration.
   
2. **Docker Container Actions:**
    - Package the environment with the action's code.
    - Provide a consistent and reliable unit of work.
    - Ideal for actions that require specific environment configurations.
    - Only execute on runners with a Linux operating system.

3. **JavaScript Actions:**
    - Run directly on runner machines.
    - Separate the action code from the environment.
    - Execute faster than Docker container actions.
    - Simplify the action code.

## Choosing a Location for Your Action

- For actions intended for public use, keep them in their own public repository.
- This allows versioning, tracking, and releasing the action just like any other software.
- Makes it easier for the GitHub community to discover and contribute to the action.
- For private use:
  - If the action is needed in a single repository, it can be created within that repository.
  - If the action is needed in more than one repository, it must be in its own repository with the correct access permissions.

## Release Management for Actions

- Use release management to control how you distribute updates to your actions.
- Users should specify a major version when using your action and update it only if needed.

### Using Tags for Release Management

- Create releases and tags using semantic versioning.
- Move major version tags to point to the Git ref of the current release.

### Using Branches for Release Management

- Users can reference a named branch for the action.
- Recommended for users who prefer using branch names.

### Using a Commit's SHA for Release Management

- Each Git commit has a unique SHA.
- Users can reference a commit's full SHA value.
- Useful when users want to ensure stability.

It is recommended to create a README file for your action which includes a description, input/output arguments, secrets, environment variables, and workflow examples. This makes it easier for other users to understand what the action does and how to customize it.