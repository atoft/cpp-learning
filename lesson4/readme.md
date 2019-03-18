# Structure of a C++ project
So far you've been adding new functions into your `main.cpp` file, up above the
`main()` function. But as your project grows, this is going to become unwieldy.
For many reasons, we'd like to have some logical separation of our code into
multiple different files.

Let's say you've written a bunch of functions to help with mathematical 
computations, like `gcd()`, `lcm()`, `lengthOfVector()`, or whatever you've 
been writing. You'll probably want to reuse them a whole bunch, and it might 
make sense to group them together in some way. So you make a new file called
`NumberHelpers.cpp` and move the functions into there.

Here's our first problem. When you give the compiler a bunch of `.cpp` files, it
will compile each of them separately. Then, once they are compiled, they will
be "linked" together to form an executable. But now if you try and call `gcd()`
from your code in `main.cpp` the compiler will complain. We need to tell the 
compiler that `gcd()` is a function that exists, and will be defined in another
file.

This is where `#include`s come in. Unfortunately, we can't (or shouldn't) just 
include your other `.cpp` file directly. Instead we need to write a header, 
or `.h` file and include that. We need a quick diversion to understand why.

## Introducing the preprocessor
The preprocessor is a process that happens before compilation when you run the 
compiler. The preprocessor is very dumb; it mostly does something similar
to copy-paste operations to alter the text of your program, before it is passed
to the compiler itself.

Lines beginning with `#` are not part of the C++ language itself, instead they
are directives for the preprocessor. When you write `#include <something>`, this 
tells the preprocessor to replace this line with the contents of the file
`something`. That's all it does; the language itself doesn't know anything 
about this. 

If we just `#include`d cpp files whenever we wanted to use a function from them,
we'd have a problem. If they were used in multiple files, we'd have to compile
them many times, and we would end up with many definitions of the same functions
in our program. So, we never `#include` cpp files directly. Instead, we write a 
"header" or `.h` file and `#include` that.

## Header files
Headers contain _declarations_ of functions, rather than definitions. A 
declaration looks a lot like a function with its body missing. Then, the 
_definition_ of the functions are in the `.cpp` file corresponding to that header.

For example, your `NumberHelpers.h` might look like this:
```C++
#pragma once

int gcd(int x, int y);

int lcm(int x, int y);
```
And your `NumberHelpers.cpp` might look like this:
```C++
#include "NumberHelpers.h"

int gcd(int x, int y)
{
    // Actual code of your function...
    return result;
}

int lcm(int x, int y)
{
    // Actual code of your function...
    return result;
}
```
To use these functions in your `main.cpp` you just need to `#include "NumberHelpers.h"`
in that file.

Compile your program with `g++ -o executable main.cpp NumberHelpers.cpp`.

What does `#pragma once` mean? Basically, when you start getting more complex
cpp files, you could end up with the same header being included multiple times,
causing multiple declarations of the same function, which isn't allowed. 
Just put `#pragma once` at the start of every header file and don't think about
this problem again.

If headers seem kind of annoying and fiddly, yes, they are. And you'll find
yourself constantly switching between headers and cpp files. But you get used to
it, I guess. And when we come to implementing _classes_, seeing the definition of the 
class all together in its header can be useful.

## What is `std::`?
Another way to help organize your code is to use _namespaces_. A namespace can
group a set of types and functions together, and avoid problems with functions
having matching names (which was a common problem in big projects written in C).

`std` is the namespace used by the standard library. By writing `std::` you are
saying that you want to use a function, object or type that is inside the 
`std` namespace. You could add a new namespace for your helper functions. Take 
a look at the example code in the `src/` subfolder for this lesson to see how 
it would work.

## Aside: Difference between `#include <something>` and `#include "something"`?
Who knows, honestly. Apparently the difference depends on which compiler
you're using. `<>` is usually used for system includes like the standard library,
and `"""` for files that are part of your project. Whatever works, I guess...?