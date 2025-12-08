# Git Commands Cheat Sheet

## Getting & Creating Projects

- **Clone an existing repository**

  ```sh
  git clone <repository-url>
  ```

- **Create a new local repository**
  ```sh
  git init
  ```

## Basic Snapshotting

- **Add file contents to the index (staging area)**

  ```sh
  git add <filename>
  git add .
  ```

- **Record changes to the repository**

  ```sh
  git commit -m "Commit message"
  ```

- **Show the current status of the repository**

  ```sh
  git status
  ```

- **Show changes between commits, commit and working tree, etc**
  ```sh
  git diff
  ```

## Branching & Merging

- **List all branches**

  ```sh
  git branch
  ```

- **Create a new branch**

  ```sh
  git branch <branch-name>
  ```

- **Switch to a branch**

  ```sh
  git checkout <branch-name>
  ```

- **Create and switch to a new branch**

  ```sh
  git checkout -b <branch-name>
  ```

- **Merge a branch into the current branch**

  ```sh
  git merge <branch-name>
  ```

- **Delete a branch**
  ```sh
  git branch -d <branch-name>
  ```

## Sharing & Updating Projects

- **Push local changes to the remote repository**

  ```sh
  git push origin <branch-name>
  ```

- **Pull changes from the remote repository**

  ```sh
  git pull
  ```

- **Fetch changes from the remote repository**
  ```sh
  git fetch
  ```

## Inspecting & Comparing

- **Show commit logs**

  ```sh
  git log
  ```

- **Show commit logs with a graphical representation**

  ```sh
  git log --graph --oneline --all
  ```

- **Show a specific commit**

  ```sh
  git show <commit-hash>
  ```

- **Show changes over time for a specific file**
  ```sh
  git log -p <filename>
  ```

## Undoing Changes

- **Unstage a file (keep the changes)**

  ```sh
  git reset <filename>
  ```

- **Undo the last commit (keep the changes)**

  ```sh
  git reset --soft HEAD~1
  ```

- **Undo the last commit (discard the changes)**

  ```sh
  git reset --hard HEAD~1
  ```

- **Revert a commit by creating a new commit**
  ```sh
  git revert <commit-hash>
  ```

## Stashing

- **Stash changes**

  ```sh
  git stash
  ```

- **List stashes**

  ```sh
  git stash list
  ```

- **Apply a stash**

  ```sh
  git stash apply <stash@{0}>
  ```

- **Apply and drop a stash**

  ```sh
  git stash pop
  ```

- **Drop a stash**
  ```sh
  git stash drop <stash@{0}>
  ```

## Remote Repositories

- **Add a remote repository**

  ```sh
  git remote add <remote-name> <remote-url>
  ```

- **Show remote repositories**

  ```sh
  git remote -v
  ```

- **Rename a remote repository**

  ```sh
  git remote rename <old-name> <new-name>
  ```

- **Remove a remote repository**
  ```sh
  git remote remove <remote-name>
  ```

## Advanced Commands

- **Rebase current branch onto another branch**

  ```sh
  git rebase <branch-name>
  ```

- **Squash commits**

  ```sh
  git rebase -i <commit-hash>
  ```

- **Cherry-pick a commit**

  ```sh
  git cherry-pick <commit-hash>
  ```

- **Create a tag**

  ```sh
  git tag <tag-name>
  ```

- **Push tags to remote**

  ```sh
  git push origin --tags
  ```

- **Delete a local tag**

  ```sh
  git tag -d <tag-name>
  ```

- **Delete a remote tag**

  ```sh
  git push origin :refs/tags/<tag-name>
  ```

- **Clean untracked files**

  ```sh
  git clean -f
  ```

- **Interactive rebase**
  ```sh
  git rebase -i HEAD~<number-of-commits>
  ```

## Merge vs Rebase

<img width="100%" alt="img"  src="https://alexgalhardo.vercel.app/images/git-merge-vs-rebase.png">

<br><br>
