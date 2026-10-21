# Minishell

A Unix shell written in C, inspired by Bash. Built as a collaborative project at Codam (42 Network) with [Sam Reerink](https://github.com/samreerink).

The project explores how shells parse user input, expand environment variables, construct commands, and interact with the operating system through processes, file descriptors, and signals.

## Features

- **Command parsing:** Tokenizes input, handles quoted strings, and checks command syntax.
- **Environment expansion:** Expands environment variables, exit status (`$?`), and process ID (`$$`).
- **Pipes and redirections:** Supports pipelines, input/output redirection, append mode, and heredocs.
- **Built-in commands:** Implements `echo`, `cd`, `pwd`, `export`, `unset`, `env`, and `exit`.
- **Signal handling:** Handles interactive signals such as `Ctrl+C` and `Ctrl+\`.
- **Environment management:** Maintains and updates environment variables throughout the shell session.

## 🔧 Built-in Commands

| Built-in | Description |
|---|---|
| `echo` | Prints text and supports the `-n` flag to omit the trailing newline. |
| `cd` | Changes the current working directory. |
| `pwd` | Displays the current working directory. |
| `export` | Sets environment variables for export and displays exported variables when invoked without arguments. |
| `unset` | Removes environment variables. |
| `env` | Displays the environment variables for the current shell session. |
| `exit` | Exits the shell. |

## My Contributions

I primarily worked on the input-processing pipeline, from tokenizing raw input to preparing commands for execution.

- **Tokenization:** Implemented lexical analysis, handling quotes, words, and shell operators.
- **Environment expansion:** Implemented variable and special parameter expansion ($?, $$), including quoted and adjacent quoted/unquoted segments.
- **Syntax checking:** Implemented validation of quotes and shell syntax before execution.
- **Heredoc expansion:** Handled variable expansion in heredoc input.
- **Command preparation:** Built command structures from expanded tokens, including arguments and redirections.

## Key learning areas 🎯

- Handling multiple processes and understanding how shells execute commands.
- Managing file descriptors and input/output redirection.
- Tokenization, parsing, and syntax validation.
- Expanding environment variables and special parameters.
- Implementing shell features such as pipes, redirections, and heredocs.
- Collaborating on a larger C project and integrating different parts of a shell.

## Build and Run

**Prerequisites:** A compatible Unix-like environment, a C compiler, Make, and the required Readline and terminal libraries.

Compile the project:

```bash
make
```

Start the shell:

```bash
./minishell
```

## Technologies

- C
- Unix / POSIX system calls
- Processes and file descriptors
- Pipes and I/O redirection
- GNU Readline
- Make
