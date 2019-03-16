# Hello world

## A Hello World program
Here's our first C++ program. You will want to write this in a new file called
`main.cpp`. This file is always the root of your C++ program and will contain 
a `main()` method which is where execution of your program begins.

We'll give the whole program below and then explain some of its parts later.

_The source code for each lesson is in the subfolder `src`._

``` C++
// This is a comment.

/* This is a
   multi-line
      comment */

#include <iostream>  // This is a preprocessor include directive.
                     // (We'll explain more later!)

int main()       // This is a function taking no arguments and returning an integer.
{                // The syntax should be familiar from Java or C#.

    int myVariable = 5;         // Declaring local variables.
    int myOtherVariable = 6;

    int result = (myVariable + myOtherVariable) * 2; // Example of an arithemtic expression.

    result = result + 2;                             // Variables are mutable by default :(


    // Writing to the standard output (e.g. your terminal).
    // cout is an example of a "stream" and << is an operator used to write to a stream.
    // You won't encounter these too often so don't worry about it for now.
    std::cout << "Hello world, the value is: " << result << std::endl;

    return 0;
}

```

`main.cpp` is a C++ source file. Unlike in an interpreted language like Python, 
this file is not used directly when running the program. Instead, it must be
given to a compiler in order to produce an executable binary to be run by your
computer.

We could have a whole series of lessons just on compilers, linkers and ways to
efficiently build more complex C++ projects. For now we'll just do the simplest
steps to get the program built into an executable for your computer.

I'm assuming you're on Mac or Linux, in which case you should have the GNU C++
compiler, G++, installed by default.

Open a terminal, navigate to the directory containing your source code file, and
run `g++ -o executable main.cpp`. This is telling G++ to compile your source file
`main.cpp` and output a binary called `executable`. If the compilation was 
successful, G++ won't say anything. You should now be able to run your program
by typing `./executable`, and it should print its result to your terminal.

Congratulations, you're a C++ programmer!