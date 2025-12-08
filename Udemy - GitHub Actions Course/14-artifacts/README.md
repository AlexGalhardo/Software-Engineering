# Working with Artifacts in GitHub Actions

Artifacts in GitHub Actions allow you to persist data between workflow jobs and share data with other jobs in the same workflow. They are helpful for storing build outputs, test results, logs, and more.

## About Workflow Artifacts

- Artifacts are files or collections of files produced during a workflow run.
- Common use cases include saving build and test outputs.
- Artifacts can be uploaded during a workflow run and downloaded later.

## Uploading Artifacts

You can use the `upload-artifact` action to upload artifacts. These artifacts can then be retrieved later in the same workflow with the `download-artifact` action. Retrieving artifacts from other workflows is, as of the date of this document, not supported out of the box and requires custom logic (there are actions in the GitHub Actions Marketplace that serve this purpose). Here's an example of uploading a build artifact:

```yaml
- name: Archive production artifacts
  uses: actions/upload-artifact@v4
  with:
    name: dist-without-markdown
    path: |
      dist
      !dist/**/*.md
```

Three aspects can be highlighted:

- We have to specify a name for the artifact (e.g., `dist-without-markdown`).
- We also have to define the path or files we want to include.
- We can also specify files or directories to exclude.
- Glob patterns can be used to specify both include and exclude collections of files.

## Managing Artifacts

You can set a custom retention period for an artifact using the retention-days option:

```yaml
- name: Upload Artifact
  uses: actions/upload-artifact@v4
  with:
    name: my-artifact
    path: my_file.txt
    retention-days: 5
```

Once artifacts are uploaded, they can be downloaded or deleted via the GitHub API or via the UI.

## Passing Data Between Jobs

Outputs offer a way to share data between jobs, but they are not well-suited for sharing large amounts of data nor for sharing entire directories.

You can use the `upload-artifact` and `download-artifact` actions as an alternative to share data between jobs in a workflow. Ensure that dependent jobs wait for the previous job to complete.
