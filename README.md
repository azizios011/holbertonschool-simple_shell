#UNIX Shell Command Line Interpreter

Ever wondered what happens behind the screen after you type something in the command line prompt? If you are like me, you provably did not.
I used to think that programs magically executed after you typed something in the terminal, but an eye opening project I had to work on, had me learning all the intricacies behind a Command Line Interpreter(CLI).

Let’s learn how an UNIX’s shell CLI works!

Shell (CLI)

Let’s start with the basics, what is a CLI (a.k.a. shell)? Well, in order for your operating system to execute the programs you want it to, it first needs to go over several steps after you type in the commands in the command prompt:

1. Read your input.
2. Search a program that matches your input.
3. Execute the program (or error message in case no program was found).
4. Display the prompt so you can input another command.

The CLI will do all of the above. The two most common are Bourne Shell (sh) and Bourne Again Shell (bash).

Let’s go over every step using a practical example!


1.0 Reading the input

The CLI needs to read and store the stream you are feeding it. For this the function getline() will be used.

                    char *line = NULL;
                    size_t size = 0;
                    int readsize = 0;

                    readsize = getline(&line, &size, stdin);

In this example, Line will be the first argument of getline() and it will store a buffer with the input from the user. the second argument, size, will store the size in bytes of the input and the last argument, stdin, corresponds to the stream being input bi the user in the standard input.
On success, getline(), returns the number of characters read from the input, in this case stored in readsize.


1.1 Parsing the buffer into tokens

By now we should have a buffer with the input from the user that looks like this:

                        char *line = "ls - l *.c";

The CLI now needs to split this string into single commands and arguments. We will call this single sub-strings tokens. To split line into tokens we will use the function strtok().

                        char *token = NULL;
                        token = strtok(line, " ");

On the first call to strtok(), the string to be parsed should be specified in the first argument (line) and the character that will delimit each token in the second argument (space in this case). In each subsequent call strtok should parse the same string, so the first argument must be NULL.

We then need to store the parsed tokens into an array of strings for later usage.

                        char **tokens = NULL;
                        
                        while (token != NULL)
                        {
                            tokens[pos] = token;
                            pos++;
                            token = stdtok(NULL, " ");
                        }


2.0 Searching a program that matches the input


Great, so what started as a simple string should be now an array of strings that looks something like this:

                        char tokens [3] = {"ls", "-l", "*.c"};

Where tokens[0] should be the program the user wants to execute and tokens[1] and tokens[2] should be the arguments the user wants to pass to that program, 
what now?

Now the CLI must search in its database to see if tokens[0](ls) is a built-in application, a system application, or if it even is something that can be 
executed!


2.1 Is it a built-in application?


This is the easiest check the CLI must do. Depending on the architecture of the shell, this check can be made using strcmp() to compare tokens[0] with an index of built-in functions. If found, the CLI just need to execute the function, and being a built-in function, the CLI can continue operating without ever finishing the process that started the CLI in the first place.

Sadly for us, this is not the case. ls was nowhere to be found in the built-in index, so our CLI must search for it elsewhere.


2.2 is it a System Application?


System applications are stored in the environment variable PATH, so we will use a function to search tokens[0] there. In this case we choose the function stat().

                            struct start st;
                            if (stat(tokens[0], &st) != 0);

stat() will take our token[0] string as a first argument and the address of a built-in structure st. It will return 0 if it found token[0] in the environment variable $PATH. If it does not find a match we do not want to discard it right away. More often than not the user will input only the name of the executable instead of the whole path of it (i.e. we used ls instead of /usr/bin/ls) so we need to tokenize every directory from $PATH in order to concatenate it with tokens[0] and recheck the new string with stat(). until the CLI finds a match.

Once it does, let’s store that newly found address in a pointer for latter.

                            char *path = "usr/bin/ls";

3.0 Execute the program


The CLI has finally found the path for the executable the user has requested, now how can we execute it if we are currently inside a program ourselves?(yes the CLI is actually just a program). Well, there is an useful function the CLI can use called execve().

execve() can execute a program if we give it a path to its executable. The problem is, when you call it, the newly called program will hijack the PID of the program who called it. In other words, using execve now will execute the command the user input but will end the CLI process at the same time. If you recall correctly, we need to display the prompt again after executing ls so we need to do something first:

3.1 Fork out of the parent process


The fork() function creates an identical copy of the parent process (in this case the CLI) and continues reading the code after it was called. If we use this function, we can use execve() inside the child process while the original CLI process waits for the child process to end. We can do this with the wait() function.

                            pid_t = 0;
                            pid = fork();

First we declare a variable type pid_t (which is an integer) and we initialize it with fork(). fork() takes no arguments and returns the pid if we are currently in the parent process, or 0 if we are inside the child process.


                            int execute = 0;

                            if (pid == 0)
                            {
                                execute(path, tokens, environ);
                            }

Now that the CLI has created a child it can execve() the requested program but first making sure it is in the child process using an if statement.


execve() will take the path of the program we want to execute as a first argument. The arguments we want to pass to that program as a second argument. And the environment where this program will be executed.

Using the information the CLI has gathered so far execve() should look like this at this point:

                            execve(
                                "/usr/bin/ls,
                                tokens[0] = "ls"
                                tokens[1] = "-l"
                                tokens[2] = "*.c",
                                extern char environ);


4.0 Display the prompt again


While all that was happening, the parent process waited like so:

                                int wait_child;
                                
                                else
                                {
                                    wait(&wait_child);
                                }

And once the child process ends, the CLI can display the prompt again after executing what it was asked.

                        sh





And all that, magically, in the blink of an eye.