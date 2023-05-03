# Simple Shell

Introduction

This project is a Holberton School assignment that consists of writing a simple command-line shell in C, using a limited number of standard library functions. The goal of this project is to understand how a shell works and how to create processes using execve.

Usage

To start the shell, simply type ./simple_shell at the command prompt. Once the shell has started, you can enter commands and view the output of those commands.

Commands

The simple_shell supports the following commands:

cd <directory>:

            Change the current working directory.
            ls: List the files in the current directory.
echo <text>:

            Display a message on the screen.
            exit [exitstatus]: Exit from the program with exitstatus value. 0 by default.
env:

        Displays the environment variable
        getenv NAME: Return the value of the NAME variable if it is in the environment
help [command]:

            Displays the syntax for the command, or all commands.
            history: Displays the last typed user commands.
The simple_shell also supports any program in $PATH, such as pwd, cat, date, etc.

Options

            The simple_shell does not support any options.
Examples

            To change to the “/usr/local/bin” directory, type:
            $ cd /usr/local/bin
            To display a message on the screen, type:

            $ echo "Hello, world!"
            Hello, world!
            To exit the shell, type:
            $ exit
Files

main.c:

            sets up the shell loop and calls the loop function.
loop.c:

            the main function where the loop, loop everything.
execute.c:

            execute commande where the the function execute everything.
readline.c:

            reads a line of input from stdin.
parsing.c:

            tokenizes the input line into individual arguments.
free_line.c:

            free
env.c:

            function that print the cuurent environment.
path.c:

            get the full path of a command.
builtin.c:

            check the code.
main.h:

            SHELL HEADER FILE.
man_1_simple_shell:

            The manual page for the simple_shell.
License

            This project is licensed under the MIT License - see the LICENSE file for details.

