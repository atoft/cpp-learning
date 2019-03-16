# Types and variables

## Types in C++
C++ is a strongly-typed, statically-typed language. 

Strongly-typed basically means that types are important, and values are not 
allowed to implicitly change types (which is different from other languages such 
as JavaScript).

Statically-typed means that the type of a value must be known at compile-time 
(as in when the program is being compiled, as opposed to runtime, when the 
program is being executed). This means that type-checking can be done by the 
compiler, so type errors will be found during compilation. An example of a 
type error could be trying to pass a string into a function that expects an 
integer, or trying to modify a variable that is constant. 

All this means that if your program has a type error, it can't even be compiled,
so you'll never have a program fail at runtime due to a type error (which could 
happen in JavaScript).

TODO finish the lesson