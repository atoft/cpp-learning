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