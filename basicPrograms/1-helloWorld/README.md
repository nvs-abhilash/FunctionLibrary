## Hello C

### Today, I will help you understand the very first code in C which is "helloWorld.c".
____________________________________________________________________________________________________________________________________

## #include<stdio.h>

With this line of code we include a file called stdio.h. (Standard Input/Output header file). This file lets us use certain commands for input or output which we can use in our program. (Look at it as lines of code commands) that have been written for us by someone else). For instance it has commands for input like reading from the keyboard and output commands like printing things on the screen.

## int main()

The int is what is called the return value (in this case of the type integer). Where it used for will be explained further down. Every program must have a main(). It is the starting point of every program. The round brackets are there for a
reason, in a later tutorial it will be explained, but for now it is enough to know that they have to be there.

## {}

The two curly brackets (one in the beginning and one at the end) are used to group all commands together. In this case all the commands between the two curly brackets belong to main(). The curly brackets are often used in the C language to group commands together. (To mark the beginning and end of a
group or function.).

## printf(“Hello World!\n”);

The printf is used for printing things on the screen, in this case the words: Hello World. As you can see the data that is to be printed is put inside round brackets. The words Hello World are inside inverted ommas, because they are what is called a string. (A single letter is called a character and a series of characters is called a string). Strings must always be put between inverted commas. The \n is called an escape sequence. In this case it represents a newline character. After printing something to the screen you usually want to print something on the next line. If there is no \n then a next printf command will print the string on the same line.

## Commonly used escape sequences are:

\n (newline)
\t (tab)
\v (vertical tab)
\f (new page)
\b (backspace)
\r (carriage return)
After the last round bracket there must be a semi-colon. The semi-colon shows that it is the end of the command. (So in the future, don’t forget to put a semi-colon if a command ended).

## return 0;

When we wrote the first line “int main()”, we declared that main must return an integer int main(). (int is short for integer which is another word for number). With the command return 0; we can return the value null to the operating system. When you return with a zero you tell the operating system that there were no errors while running the program. (Take a look at the C tutorial – variables and constants for more information on integer variables).

## Compile

If you have typed everything correct there should be no problem to compile your program. After compilation you now should have a hello.exe (Windows) or hello binary (UNIX/Linux). You can now run this program by typing hello.exe (Windows) or ./hello (UNIX/Linux).

If everything was done correct, you should now see the words “Hello World” printed on the screen.

## Congratulations!!!!!
You have just made your first program in C.
