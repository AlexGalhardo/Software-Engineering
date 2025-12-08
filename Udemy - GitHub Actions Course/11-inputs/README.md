# Working with Inputs in GitHub Actions

Inputs are a valuable feature in GitHub Actions, enabling workflows and custom actions to accept and utilize input parameters. It can be used in custom actions, reusable workflows, and manually triggered workflows.

## Overview

- The `inputs` object becomes accessible in a workflow when triggered, allowing users to define input parameters.
- Each entry `inputs.<name>` represent individual input values passed from an external workflow or trigger event.

### Reusable Workflows:

Inputs are defined under the `workflow_call` key in the `on` definition of the workflow.

### Manually Triggered Workflows:

Inputs are defined under the `workflow_dispatch` key in the `on` definition of the workflow.

### Custom Actions

Inputs are defined in the `action.yaml` file in the custom action definition.
