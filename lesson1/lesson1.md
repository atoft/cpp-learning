# Hello world

Here's our first C++ program. You will want to write this in a new file called
main.cpp. This file is always the root of your C++ program and will contain 
a `main()` method which is where execution of your program begins.

We'll give the whole program below and then explain some of its parts later.

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

main.cpp is a C++ source file. Unlike in an interpreted language like Python, 
this file is not used directly when running the program. Instead, it must be
given to a compiler in order to produce an executable binary to be run by your
computer.

TODO how to compile.