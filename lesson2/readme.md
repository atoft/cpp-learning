# Types and variables

## Types in C++
C++ is a strongly-typed, statically-typed language. 

Strongly-typed basically means that types are important, and values are not 
(generally) allowed to implicitly change types (which is different from other 
languages such as JavaScript).

Statically-typed means that the type of a value must be known at compile-time 
(as in when the program is being compiled, as opposed to runtime, when the 
program is being executed). This means that type-checking can be done by the 
compiler, so type errors will be found during compilation. An example of a 
type error could be trying to pass a string into a function that expects an 
integer, or trying to modify a variable that is constant. 

All this means that if your program has a type error, it can't even be compiled,
so you'll never have a program fail at runtime due to a type error (which could 
happen in JavaScript).

_Aside: There are ways to write C++ code that is not type-safe. Code can
discard the type of a variable or force a value to be assigned to a variable
of another type. Some of this is for historical reasons (such as backwards 
compatibility with the C programming language) or to allow you to perform 
low level operations on the computer's memory._

## Examples of primitive types
Primitive types are the most basic types that are built into the language. 
You'll recognise some of these, `int` (the basic integer type), `float` 
(for floating-point numbers), and `bool` (for true/false values).

There are also some variations of these; `long` for larger integers and `double`
for double precision floating-point numbers. Integers can also be preceded by
`unsigned` to represent only values greater than or equal to zero.

You'll also encounter `char`, which is often used to represent an alphanumeric
character but is actually a smaller capacity integer type. There are other
some other primitive types, a full list is TODO

_Aside: Slightly confusingly, the C++ standard doesn't actually define the 
size (in terms of bits or bytes) of each type, only their size relative to 
a `char`. As a result there can be differences in their sizes between
platforms, which can cause problems for some types of programs. To address 
this, some programs and libraries define their own primitive types so they
can control the size on each platform._ 