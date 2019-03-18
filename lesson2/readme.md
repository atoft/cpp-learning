# Types, variables and operators

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
primitive types, a full list is 
[here](https://en.cppreference.com/w/cpp/language/types).

_Aside: Slightly confusingly, the C++ standard doesn't actually define the 
size (in terms of bits or bytes) of each type, only their size relative to 
a `char`. As a result there can be differences in their sizes between
platforms, which can cause problems for some types of programs. To address 
this, some programs and libraries define their own primitive types so they
can control the size on each platform._ 

## Variables
As you saw in your hello world program, you can define a local variable
as follows:
```C++
int x = 5;
```
You can also _declare_ a variable without defining its value, as in:
```C++
int x;      // Bad.
```
This is bad practice, because the value of `x` may not have been initialized to
anything meaningful; it could just be the value of whatever data was in 
memory before. Using `x` without writing to it could cause _undefined behaviour_
in your program. Basically, don't do it.

When defining a variable, you can also make it constant:
```C++
const int numberOfDogs = 6;
```
This means that `numberOfDogs` can't be written to after it has been defined.
Making variables constant can make it easier for you to reason about your
program, as there are fewer "moving parts". It helps to avoid certain types of
bugs where a value has been changed when you weren't expecting it to, and 
can sometimes help the compiler to optimize your program.

An even stronger restriction is to define a _constant expression_. This is a
relatively new feature that means the value of your constant can be evaluated
at compile-time. A constant expression can just be a number or an expression
that the compiler can evaluate. For example:
```C++
constexpr double PI = 3.14159;
constexpr double TAU = 2.0 * PI;
```

## Operators
Let's cover some of the basic operators in C++ so that you have something to 
do with all your variables.

The obvious arithmetic operators are present:

`+`, `-`, `*` (multiply), `/` (divide), and `%` (modulo).

The same operators are used for integers and floating point numbers, but will
obviously give you different results.
```C++
const float dividedFloat = 7.0f / 2.0f;
const int dividedInteger = 7 / 2;

std::cout << "Float division: " << dividedFloat << std::endl;
std::cout << "Int division: " << dividedInteger << std::endl;

```
Note the `f` on the end of the numbers above; it just means that they are 
interpreted as `float`s rather than `double`s.

Also of note are the increment and decrement operators:
```C++
int x = 1;

++x;

int y = 2;

--y;

```
They will increase and decrease a variable by one, respectively. They can be 
written as prefix or postfix (`++x` or `x++`) and there is a subtle 
difference, but we don't need to worry about it.

There are also logical operators:

`&&` (logical AND)

`||` (logical OR)

`!` (logical NOT)

These can operate on `bool` values (or things that can be treated as `bool`s).

And comparison operators:

`==` (equals)

`!=` (not equals)

`>` and `<` (strictly greater and strictly lesser)

`>=` and `<=` (greater or equal and lesser or equal).

Don't get `=` (assignment) confused with `==` (equality)!

Try experimenting with each of these yourself.