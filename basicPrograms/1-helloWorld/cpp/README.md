## Today I will help you learn the first code in Cpp that is "helloWorld.cpp"

The hello world program is one of the simplest programs, but it already contains the fundamental components that every C++ program has. Don’t be overwhelmed, we will take a look at the code line by line.

Type the code in your favorite editor (always type, don’t use cut/paste. This is better for learning purposes).
Save the program with the name: hello.cpp.

## #include<iostream>

Lines beginning with a pound sign (#) are used by the compilers pre-processor. In this case the directive #include tells the pre-processor to include the iostream standard file.
This file iostream includes the declarations of the basic standard input/output library in C++. (See it as including extra lines of code that add functionality to your program).

## std::cout << "Hello, world!" << std::endl;

This line is a C++ statement. A statement is a simple expression that can produce an effect. In this case the statement will print something to our screen.

cout represents the standard output stream in C++.
 In this a sequence of characters (Hello World) will be send to the standard output stream (in most cases this will be your screen).
The words Hello World have to be between ” “, but the ” ” will not be printed on the screen. They indicate that the sentence begins and where it will end.

cout is declared in the iostream standard file within the std namespace. This is the reason why we needed to include that specific file. This is also the reason why we had to declare this specific namespace.

As you can see the statement ends with a semicolon (;). The semicolon is used to mark the end of the statement. The semicolon must be placed behind all statements in C++ programs. So, remember this.
One of the common errors is to forget to include a semicolon after a statement.

We could have used using namespace std; and then we could have used only cout. But since std is not being used, be have to use its reference to the cout funtion.

## return 0;

The return statement causes the main function to finish. You may return a return code (in this case a zero) but it depends on how you start your function main( ). We said that main ( ) will return an int (integer).
So we have to return something (in this case a zero). A zero normally indicates that everything went ok and a one normally indicates that something has gone wrong. (This is standard practice. After running an UNIX/Linux program there is often a check on the return code).
