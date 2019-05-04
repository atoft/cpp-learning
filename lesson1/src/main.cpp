// This is a comment.

/* This is a
   multi-line
      comment */

// This is a preprocessor include directive.
// (We'll explain more later!)
#include <iostream>

// This is a function taking no arguments and returning an integer.
int main()
{
    // Defining local variables.
    int myVariable = 5;
    int myOtherVariable = 6;

    // Example of an arithemtic expression.
    int result = (myVariable + myOtherVariable) * 2;

    // By default, variables can be changed again after they are defined.
    result = result + 2;

    // Writing to cout, the standard output (e.g. your terminal).
    // cout is an example of a "stream" and << is an operator used to write to a stream.
    // You won't encounter these too often so don't worry about it for now.
    std::cout << "Hello world, the value is: " << result << std::endl;

    // Return a value from the function.
    // For historical reasons, returning 0 from your main() function means
    // the program was successful.
    return 0;
}