# Simple Shell

## Description
This project is a simple UNIX command interpreter written in C, developed as part of the Holberton School curriculum.

The shell replicates basic functionalities of `/bin/sh`. It works in both **interactive** and **non-interactive** modes, allowing users to execute commands, manage processes, and interact with the system environment.

---

## Features
- Displays a prompt and waits for user input
- Executes commands using `execve`
- Handles commands with arguments
- Searches executables using the `PATH` environment variable
- Works in interactive and non-interactive mode
- Proper error handling
- No memory leaks

---

## Usage

### Compilation
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

# Interactive Mode
$ ./hsh
($) ls
file1 file2
($) exit

# Non-Interactive Mode
$ echo "ls" | ./hsh
file1 file2
