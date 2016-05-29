#RShell (Turtle Shell)
Full Documentation of RShell (Turtle Shell) designs and coding strategies can be found in

https://drive.google.com/open?id=0B63l6C_S7h9vTTU5UERYaWpPZFU

Installation
------------
Please run the following commands in terminal to run our RShell (Turtle Shell) on your computer
```Installation
$ git clone https://github.com/jkuzn001/rshell.git

$ cd rshell

$ make

$ bin/rshell
```

Introduction
------------
This is the RShell (Turtle Shell) project of Jacob Kuznicki and Lam Duy Le (aka Patrick Le) for CS 100 Spring 2016. It takes in commands (from bash and special comands such as exit) and connectors and executes them.  We accomplished this by using a composite design pattern consisting of connector class (which acts as the composite class) and a command class (which acts as the leaf).

For the second part of this assignment we added some functionality to our Rshell.  We added in the test command that can be called using either the command "test" or by using [].  This command will test if a given file or directory exists in a given path.  The test command's behavior can be augmented by giving it one of the following flags: -e tests if the file or directory exists (is assumed if no flag is provided), -f tests if the file or directory given is a regular file, -d tests if the file or directory given is a directory.  We also added in precedence of commands with ().

UML DIAGRAM
------------

![Alt text](/pictures/UML_Diagram.png?raw=true "Optional Title")

Parsing with Tokens!!!
------------
We used the C Token library to help us parse the user's string. From there we combined the Tokens to create both our Cmd's objects and Connector's objects

![Alt text](/pictures/Tokens.png?raw=true "Optional Title")

Execute based on Tree Representation
------------
From there we will construct a tree that will recursively call execute(), which will call execvp to run the specific commands and flags. Each iteration of a leaf will return a boolean value which will be evaluated by the Connectors to determine whether the tree should travel to the right leaf or skip and return back up the tree.

![Alt text](/pictures/tree.png?raw=true "Optional Title")

RShell (Turtle Shell) Features
------------
Can run all bash commands within /bin

Can support all connectors such as;
* ";" = The following command will always be exectued.
* "||" = If the current command fails, the following command will be executed.
* "&&" = If the current command succeeds, the following command will be executed.
* "#" = Everything after "#" will be a comment.

User information work!!!
Instead of having RShell (Turtle Shell) print a boring "$" before each command.
Our RShell (Turtle Shell) can print out your entire user's info.

For example, suppose your username is "Turtle" and that you're logged into the machine named "shellTheFirst",
our RShell (Turtle Shell) will prompt "Turtle@shellTheFirst$ " on your terminal!
Bugs
------------
RShell (Turtle Shell) does not support quotes combined flags.
* Normal Shell: cat "food in can" => cat: can't open food in cans
* RShell (Turtle Shell): cat "food in can" => cat: "food: No such file or directory...cans": No such file or directory

A bug was encountered where a child process would not properly exit on a failed call to execvp but this was fixed by changing the wait system call to waitpid and using the WEXITSTATUS macro to determine the success of the child process which was killed using the exit command.

Authors
------------
Jacob Kuznicki: https://github.com/jkuzn001

Lam Duy Le (aka Patrick Le): https://github.com/lepatrick714
