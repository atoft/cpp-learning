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

// Some other code
const int sum = add(1, 2);
```
Functions can take as many arguments as you want, but can only have one return
value. There are several ways to get around that restriction, but we'll 
learn more later!

Can you write a function to return the length of a 3D vector? Hint, you may want 
to call the `std::sqrt()` function as part of your function, which means you'll
need to `#include<cmath>` at the start of the program.

## Aside: reading user input
Here's a quick way for your program to read in values from the terminal input,
so that you can try out your program with multiple different values.
```C++
std::cout << "Enter a number:" << std::endl;

float userInput = 0.0f;

std::cin >> userInput;

```

Now `userInput` will contain a `float` typed in by the user. Please note that 
this is bad practice, because if the user doesn't type something that could be 
interpreted as a `float`, the program will continue running with a 
potentially invalid value in `userInput`. A real program should do some 
error handling to deal with the case of incorrect input.

## Control flow
What is control flow? It's things that control the flow of execution through
your program, such as by looping or branching. Here's some examples.

### If
This is a simple if statement. The body enclosed in `{}` is executed if the 
condition is true. As with functions, variables defined inside the curly 
braces will only exist within this scope.
```C++
const int input = 5
const bool isEven = (input % 2 == 0);

if (isEven)
{
    std::cout << input << " is even" << std::endl;
}
```
You can also execute something else if the condition is false:
```C++
if (isEven)
{
    std::cout << input << " is even" << std::endl;
}
else
{
    std::cout << input << " is odd" << std::endl;
}
```
or check multiple conditions in sequence:
```C++
if (isEven)
{
    std::cout << input << " is even" << std::endl;
}
else if(input == 3)
{
    std::cout << input << " is three" << std::endl;
}
else
{
    std::cout << input << " is odd and not three" << std::endl;
}
```

### Switch
A switch statement is another way of branching, based on the value of a
particular variable. It's often used with _enums_, which you'll encounter
later, but for now I'll just give an example.
```C++
const int day = 1;

// Print the name of the day.
switch(day)
{
case 0:
    std::cout << "Monday" << std::endl;
    break;
case 1:
    std::cout << "Tuesday" << std::endl;
    break;
case 2:
    std::cout << "Wednesday" << std::endl;
    break;
    
// Rest of the days of the week...

// Handles values that we didn't explicity consider
default:
    std::cout << "Invalid day" << std::endl;
    break;
}
```
The syntax of switch statements is widely regarded as poorly designed
in C++; if you miss out a `break;` your code will continue executing the next
branch of the switch, which is probably not what you intended. But switch
statements are still useful where otherwise you'd be stuck with a very long
sequence of `if`s.

### While
A while loop is the simplest way to repeatedly execute something. The code 
inside the loop will be run again and again until the condition becomes false.
```C++
const int secretNumber = 42;

bool secretGuessed = false;

while (!secretGuessed)
{
    int guess = 0;
    
    std::cin >> guess;
    
    secretGuessed = (guess == secretNumber);
}
std::cout << "You guessed the number!" << std::endl;
```

### For
Often a for loop is preferable to a while loop. A for loop gives you a 
structured way to define a variable, change its value, and give a condition
to terminate the loop.

```C++
// Count up
for (int index = 0; index < 5; ++index)
{
    std::cout << "Iteration " << index << std::endl;
}

// Count down
for (int count = 5; count > 0; --count)
{
    std::cout << count << std::endl;
}
std::cout << "Liftoff!" << std::endl;
```

In modern C++, it's generally preferred to instead use a _ranged-for loop_ 
whenever possible. A ranged-for lets you directly loop over the elements in 
an array or other collection, rather than manually handling an index. This
makes it less error prone and clearer to read.

We won't cover arrays yet, but here's a preview:
```C++
std::vector<int> mArray{5, 2, 19, 11};

for (int x : myArray)
{
    // Is run once for each element in myArray, with x set to the value 
    // of the current element.
    doSomethingWith(x);
}
```

### Loop operations
There are a couple of operations you need to know about for working with 
loops. Calling `break;` anywhere within a loop will end the loop, and your
program will move on to executing the code immediately after the loop body.
Calling `continue;` inside a loop will end the current iteration of the loop 
and continue on to the next iteration. Note if you are using a loop nested 
inside another loop, these operations will act on the innermost loop. Try 
using `break;` and `continue;` in your own loops.

### Writing an algorithm
You're now ready to implement some functions to run simple algorithms. Try 
writing a function to compute the greatest common divisor of two variables, 
using the control flow techniques you've learnt. Or implement something more 
mathematically interesting if you want. ¯\\_(ツ)_/¯