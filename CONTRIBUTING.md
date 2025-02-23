# Contributing to the Damm Algorithm CLI Tool

Thank you for your interest in contributing to this project. Please be aware that this project is largely unmaintained, and pull requests, feature requests, and bug reports may not be dealt with in a timely manner.

## Code Cleanliness
- Keep the code as clean and readable as possible.
- Follow existing code conventions and maintain consistency throughout your changes.

## Coding Style
All code contributions must adhere to the project's coding style. Please use the `indent` command-line utility with the following options:

```sh
indent --gnu-style \
       --dont-break-procedure-type \
       --indent-level2 \
       --no-tabs \
       --line-length100
```

These settings ensure that:
- This project's coding style is followed.
- Procedure types remain on the same line as their names.
- Indentation uses 2 spaces per level.
- Tabs are replaced with spaces. (because I'm anal and because I prefer precision; I just don't understand why anyone would use tabs over spaces, if it's all the same [to the compiler], why not just use spaces; why would anyone use tabs over spaces, I mean why not just Emacs over vim!)
- The maximum line length is 100 characters for non-comment lines.

## Commit Guidelines
- Keep your commits focused and relevant.
- **Do not** commit large blocks of insignificant changes, such as pure indentation fixes.
- Clearly describe the purpose of each commit in the commit message.

## Pull Requests
- Before submitting a pull request, ensure your changes adhere to the coding style and commit guidelines.
- If applicable, provide a clear explanation of your changes in the pull request description.
- Expect delays in review and feedback.

Thank you for your understanding and contributions!

