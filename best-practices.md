# Best Practices

<img width="100%" alt="img"  src="https://alexgalhardo.vercel.app/images/best-practices.png">

## **Clean Code**

#### Clear Names:

- What it is: Choosing descriptive and meaningful names for variables, functions, classes, etc.
- Why it's important: Clear names help anyone reading the code quickly understand what it does, without needing extra explanations.
- How it's done: Avoid abbreviations and generic names. Choose names that explain exactly what the variable or function is for, such as calculateTotal instead of calc.

#### Baby Steps:

- What it is: Breaking down work into small, manageable chunks.
- Why it's important: Makes the code easier to understand and maintain. If something goes wrong, it's easier to find and fix the bug.
- How it's done: Write and test small chunks of code frequently. Refactor (improve) those chunks as needed.

#### Short Functions:

- What it is: Keeping functions small and focused on a single task.
- Why it's important: Short functions are easier to read, understand, test, and reuse.
- How to: A good rule of thumb is that a function should do only one thing, and it should do it well. If a function is getting long, break it into smaller functions.

#### Use Comments Only When Necessary:

- What it is: Write comments only when the code cannot be self-explanatory.
- Why it matters: Comments can become outdated or misinterpreted. Clear, well-written code is better than obscure code with too many comments.
- How to: Write code that is easy to understand on its own. Use comments to explain the "why" of certain decisions, not the "how."

#### Organization Matters:

- What it is: Keep code organized and structured in a logical way.
- Why it matters: Well-organized code is easier to navigate and understand.
- How to: Group related functions, maintain a logical order in function declarations, and follow a consistent pattern throughout the code.

#### Avoid Repetition:

- What it is: Don't duplicate code unnecessarily.
- Why it matters: Duplicate code increases the chance of errors and makes maintenance more difficult.
- How to do it: Use functions and classes to encapsulate reusable code. Whenever you find duplicate code, consider refactoring it to remove it.

#### Use Objects:

- What it is: Use object-oriented programming to organize your code.
- Why it matters: Objects help structure your code so that different parts have clear, separate responsibilities.
- How to do it: Create classes that represent entities in your problem and distribute responsibilities so that each class has a clear function.

#### Test Your Code:

- What it is: Write tests to ensure that your code works as expected.
- Why it matters: Tests help identify problems before code is used in production and make future changes easier.
- How to do it: Write automated tests for the most critical parts of your code and test frequently as you develop.

#### Clean Code Matters:

- What it is: Write code in a clear, organized manner.
- Why it matters: Clean code is easier to understand, maintain, and evolve.
- How to do it: Follow good coding practices such as consistency, clarity, and simplicity. Review and refactor your code regularly.

#### Learn and Improve:

- What it is: Continue learning and improving your coding skills.
- Why it’s important: Technology is always evolving, and improving your skills helps you stay current and efficient.
- How to do it: Read books, take courses, collaborate with other developers, and review your own code to identify improvements.

## **Keep It Simple Stupid - KISS**

<p>Clean tests follow the rules of the acronym FIRST (Fast, Indepedent, Repeatable, Self-validation, Timely).</p>
<ul>
<li>Speed: tests must be fast so that they can be executed several times;</li>
<li>Independence: when tests are dependent, a failure can cause a domino effect, making individual analysis difficult;</li>
<li>Repeatability: it must be possible to repeat the test in any environment;</li>
<li>Self validation: good tests result in “true” or “false” answers. Otherwise, failure may become subjective;</li>
<li>Timeliness: tests need to be written before the production code, where the tests will be applied. Otherwise, the code may become too complex to be tested or the code may not be testable at all.</li>
</ul>

## **Don't Repeat Yourself - DRY**

<p>DRY is the acronym for Don’t repeat yourself. It is the concept that says that each part of the system's knowledge must have only one representation. This way, avoiding code ambiguity. In other words, there must not be two parts of the program that perform the same function, that is, the famous copy and paste in the code.

<p>But why avoid repetition? Simple!</p>

<p>Anyone who has a second home on the beach, or in the countryside, knows how complicated it is to ensure the maintenance of both. Even though repetition may seem harmless in simpler programs, it can become a problem as the software grows and maintenance and development become increasingly complex.</p>

<p>A good way to avoid code duplication is to correctly apply the single responsibility technique. For each function or method, use only one part of the method (or function). The correct thing is to abstract just this part and create a new one!</p>

<p>Some condition ambiguities are not so destructive to the code, but over time they can be. Therefore, try to avoid them as much as possible.</p>

<p>Better safe than sorry. This famous saying applies to software development as well. Good developers think that things can go wrong, because they will eventually. This way, the code must be prepared to deal with these problems that arise.</p>

<p>Today most languages have resources to handle errors in code through Exceptions and try-catch blocks.</p>

<p>Exceptions: mechanism that signals exceptional events. For example, trying to insert the character “a” into an integer variable;</p>

<p>Try-catch blocks: catch the aforementioned exceptions. Therefore, they must be used globally. After all, the methods already have their functions (which is not to handle errors).</p>

<p>To conclude this topic, an excellent tip to avoid generating errors in your code is simply not to use “null”, either as a parameter or as a return in functions. These returns often require unnecessary checks that, if not done, can generate errors.</p>

## **YAGNI - You Aren't Gona Need It**

<p>"You aren't gonna need it" (YAGNI) is a principle of Extreme Programming (XP) that states that the programmer should not add any functionality until it is actually needed.</p>
<p>"Always implement features when you really need them, and never when you anticipate you will need them."</p>
<p>It seems obvious, doesn't it, but think about it. How many times have you implemented a feature in a project just because you thought the client would love it, or that it would give the project that edge?</p>
<p>This doesn't mean you should avoid writing flexible code.
<p>It means that you should not include features in your code based on the fact that you may need them later.</p>
<p>There are two main reasons for practicing YAGNI:</p>
<p>You save time, because you avoid writing code that you won't need at the moment;</p>
<p>Your code gets better, because you avoid polluting the code with 'guesses' that end up, in most cases, being wrong guesses;</p>
<p>1- If you don't need the functionality now then don't implement it. You don't need it.</p>
<p>2- Do you really think you will save time overall by spending more time now than in the future?</p>

## [Semantic Version 2.0.0](https://semver.org/lang/pt-BR/)

<p>Given a MAJOR.MINOR.PATCH version number, increment the:</p>

<ol>
   <li>Major version (MAJOR): when you make incompatible changes to the API,</li>
   <li>Minor version(MINOR): when adding features while maintaining
compatibility, and</li>
   <li>Correction version (PATCH): when correcting errors while maintaining compatibility.</li>
</ol>

<p>Additional labels for pre-release and metadata
build are available as an extension to the MAJOR.MINOR.PATCH format.</p>

<br><br>
