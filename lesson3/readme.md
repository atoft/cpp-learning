# Functions and stuff
One of the most basic ways to organize and reuse your code is by writing 
functions. In this lesson we'll just use "free functions" (as opposed to methods)
but you'll use these less commonly in practice.

You already have one function in your `main.cpp` file:
```C++
int main()
{
    // Your code...
    
    return 0;
}
```

What does it mean? `main` is the name of the function. It is preceded by the
return type of the function, which is `int`. All paths of execution through
your function must `return` a value of the correct type, or the compiler will
complain. If you don't want your function to return anything, you can specify 
`void` as the return type. Then you can return from the function just using
`return;` or it will return anyway when execution reaches the end of the
function body.

The curly braces `{}` enclose the function body (i.e. the code that makes up 
the functionality of the function). Local variables defined inside here will be
within the _scope_ of the function - the compiler won't let you access them
outside of this scope of this function, and when your program is running, they
will all be removed from memory when the function returns. (With the exception
of the return value, which will be copied so that it can be used wherever the
function is _called_ from.)

Here's an example of defining and calling a function.
```C++
int computeSecondsInHour()
{
    const int secondsInMinute = 60;
    const int minutesInHour = 60;
    
    return secondsInMinute * minutesInHour;
}

// Some other code, such as in your main function
int main()
{
    const int seconds = computeSecondsInHour();

    // Do something with the return value...
}

```

What about those `()`? They contain the arguments to the function. In this 
case the function takes no arguments, but it can take many. For example:
```C++
// A really pointless function taking two arguments.
int add(int x1, int x2)
{
    return x1 + x2;
}
```
Functions can take as many arguments as you want, but can only have one return
value. There are several ways to get around that restriction, but we'll 
learn more later!

Can you write a function to return the length of a 3D vector? Hint, you may want 
to call the `std::sqrt()` function as part of your function, which means you'll
need to `#include<cmath>` at the start of the program.

## Control flow
TODO