# Concurrency Management in GitHub Actions

Concurrency management in GitHub Actions allows you to control and limit the number of jobs or workflows that can run simultaneously. This is useful to prevent job conflicts and resource contention, especially in multi-job workflows.

## Overview

Concurrency management in GitHub Actions is controlled using the `concurrency` keyword in your workflow YAML file. With this feature, you can specify which jobs or workflows should be allowed to run concurrently and which should be queued.

By defining a concurrency group, which can be any string or expression, you ensure that only one job or workflow using the same concurrency group will run at a time. If a job or workflow is queued and another with the same concurrency group is in progress, the queued one will be pending. It's possible to cancel any currently running job or workflow in the same concurrency group using the `cancel-in-progress: true` option.

### Notes:
- Concurrency group names are case-insensitive.
- Ordering is not guaranteed for jobs or runs using concurrency groups; they are handled in the order they are processed.