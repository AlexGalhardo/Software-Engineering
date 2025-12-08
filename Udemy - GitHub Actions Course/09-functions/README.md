# Using Functions in Workflows

GitHub Actions offers a set of built-in functions that you can use in expressions. These functions allow you to perform various operations, including comparisons, string manipulations, and data transformations.

## Data Type Conversions

Before diving into the functions, it's essential to understand how GitHub Actions converts data types when working with functions:

- **Null**: Converts to an empty string `''`.
- **Boolean**: Converts to `'true'` or `'false'`.
- **Number**: Converts to decimal format or exponential notation for large numbers.
- **Array**: Not converted to a string.
- **Object**: Not converted to a string.

## Commonly Used Functions
- `contains`: checks if a value contains another value. It returns `true` if the search value is found in the target value.
- `fromJSON`: converts a value into a JSON object or data type. It's used to work with JSON data in expressions or convert environment variables from strings to JSON.
- `startsWith`: checks if a string starts with a specified substring. It returns true if the string starts with the given substring.
- `hashFiles`: used to generate a hash based on a single or multiple files. One use-case is to generate caching keys based on dependency lock files.

For a full list of available functions, check GitHub Actions's [functions page](https://docs.github.com/en/actions/learn-github-actions/expressions#functions).

## Status Check Functions

These functions are used in if conditionals to determine the success or failure of previous steps or jobs.
- `success()`: returns `true` when none of the previous steps have failed or been canceled.
- `failure()`: returns `true` when any previous step of a job fails.
- `cancelled()`: returns `true` if the workflow was canceled.
- `always()`: always returns `true` and ensures that a step executes, even if previous steps failed or if the workflow was canceled.