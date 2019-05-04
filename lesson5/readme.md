# Defining your own types
Until now we've been working exclusively with _primitive_ types, that is types
which are built in to the language. One of the most important features of C++
is the ability to define your own types. Writing new types allows you to create
new _abstractions_ within a program. Abstractions make a program more scalable
by introducing separation between different parts, and make it
easier to reason about by introducing higher level concepts that you can 
interact with. By hiding part of your program's functionality within an 
abstraction, you reduce the mental load of working within your code, and make it
easier to maintain by preventing interdependencies between different concepts.

If that all sounds a bit wooly, then try reading this Wikipedia article [TODO 
LINK], which I'm pretty sure is even less concrete :P. But if the idea doesn't
sound convincing to you, hopefully it will when you start to work within
larger codebases.

## Enums
An enum (short for enumeration) is the simplest kind of user defined type.
An enum type defines a list of possible named values. An enum variable then 
has one of those values at any time.

For example, a couple of lessons back I gave an example about days of the 
week. It defined the following variable:
```C++
const int day = 1;
```
where different numbers represented the different days of the week. But that
sucks; how do we know which number corresponds to which day? Is Monday 0 or
1? This knowledge is something implicit rather than explicit. Also, what if
the value is outside of the range of 0-6 (or 1-7)?

We can avoid these problems by defining a new type for days of the week. This
type will be an enum. The type is defined like this:
```C++
enum class Day
{
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday
}
```

We can create variables of this type and use them like you might expect:
```C++
const Day currentDay = Day::Tuesday;

if (currentDay == Day::Saturday || currentDay == Day::Sunday)
{
    std::cout << "It's the weekend!" << std::endl;
}
```

At runtime, enums are simply represented as integer values (eg. Monday might 
be 0 etc.) which means using them is very efficient. In fact you can 
explicitly convert them to integers at any time (a process called _casting_)
which can allow for some clever tricks, but that's a story for another time.

_Aside: ```enum class``` is the modern way of defining an enum type. ```enum```
is the way you will see in older code. ```enum```s can be _implicitly_ 
converted to integer types and vice versa, which makes using them more 
error prone. For example, it would be valid to write ```Day today = 100;```. 
Also, ```enum class``` names are scoped (you have to write ```Day::Monday``` 
rather than just ```Monday```) whereas ```enum```s are not, which can lead to
name clashing problems. There are very few cases where it makes sense to use 
```enum``` instead of ```enum class```._

## Classes
Classes are far more complex custom types. First some terminology; a value 
having a class type is commonly referred as an _object_ (or an instance of
the class).

A class allows you to _encapsulate state and behaviour_. In layman's terms, 
an object of a class can contain other data (state) and can have functions
associated with it (behaviour). It's encapsulated, because you (or 
other users of your class) can interact with objects of that class without 
caring how it's implemented on the inside. (It's a level of abstraction!)

Here's a stupid example of a class in C++. It's an example of some code for
an imaginary game where you play as a worm. Note that the code is split 
between a header and a cpp file.

```C++
// Worm.h

public class Worm
{
public:
    void MoveLeft();
    void MoveRight();
    
    float GetPosition() const;
    
private:
    float m_Position = 0.f;
    
    static constexpr WORM_SPEED = 2.5f;
}

```

```C++
// Worm.cpp

#include "Worm.h"

void Worm::MoveLeft()
{
    m_Position -= WORM_SPEED;
}

void Worm::MoveRight()
{
    m_Position += WORM_SPEED;
}
    
float GetPosition() const
{
    return m_Position;
}
```

Wow, there's so much to unpack here. 

First, let's look at the header. The header contains the _definition_ of the
class, but notice that like in previous lessons, the functions are only
_declared_ in the header, and will be defined in the cpp.

### Members
Objects of the ```Worm``` class have some state associated with them: each
```Worm``` contains a variable called ```m_Position```. Variables belonging 
to a class are called _member variables_. Programmers often make member
variables more obvious by starting their names with ```m_```.

Notice that ```m_Position``` is in a section of the class marked 
```private:```. That means that this variable is *not accessible* to parts of
the program outside of the class. Only methods in the class are able to 
read or modify this variable. ```private:``` is an _access modifier_. Member 
variables can also be ```public:```; anyone can access an object's public 
members.

You should assign members a default value where possible, to avoid the 
possibility of them containing uninitialized data.

### Methods
You should be able to spot some function declarations inside ```Worm```. 
Functions belonging to a class are called _methods_. As mentioned, methods 
of an object can access member variables of that object, even if they're 
```private:```. The method declarations look mostly like function declarations
you've seen before. One that looks a bit different is
```C++
float GetPosition() const;
```
What does ```const``` mean when used here? It means that this is a constant
function, that is, that calling ```GetPosition()``` on an object is 
"guaranteed"* not to modify the state of that object. Marking methods as 
```const``` is another way to make your program easier to reason about, and 
the compiler will complain if a method marked as ```const``` is trying to modify
the object's state.

These methods are all marked as ```public:```, anyone with a ```Worm``` can
call these methods on it. But methods can also be ```private:```, so that 
they can only be called by other methods within the class.

*_Guaranteed is in quotes because almost nothing is ever truly guaranteed in 
C++; see ```const_cast``` if you want to be sad._

Swapping over to the cpp now, we can see that it just contains the definitions
of these methods. What they do should be quite self-explanatory, and taking 
a look at them should help us understand why this class structure is useful.

Worms can only move at a particular speed; they can only squirm so fast. 
Because ```m_Position``` is a private member variable, other parts of your 
code can't modify it directly; some other piece of code can't fling your 
worm miles away. The worm's position can _only_ be moved by calling 
```MoveLeft``` so we can reason much more easily about how it can change.
This also means we could change the way that position is represented 
internally without affecting other areas of our code.

(We can also imagine the move methods including other side effects, such
as playing the worm's movement animation on the screen and making a 
squishy sound effect.)

Note that other parts of the codebase can still _read_ the worm's position 
using ```GetPosition()``` but because it returns a _copy_ of the original 
value they can't change it using this method. Methods and other functions 
return copies by default; this is something we'll discuss more when we 
come to learn about memory in a future lesson.

### Static members and methods
There's just one more thing to look at in the definition of our class. There's
another member variable ```WORM_SPEED``` which is declared as `static`.
Both methods and members can be ```static```. In this case, static means that
the variable does not belong to a specific object. There is only one value of
```WORM_SPEED``` and it is shared between all objects of the class. Static methods
are similar; you can call them without having a specific object of the class,
but they can't access non-static members or call non-static methods. They can
be useful for defining helper methods that are related to a particular class
but not intended to be called on a specific object.

## Using ```Worm```
Hopefully all that made sense, but let's see how you might use this class.
Here it is being used in our Worm game, which it turns out is a text 
adventure...
```C++
Worm worm;

bool shouldQuit = false;
while (!shouldQuit)
{
    std::string userInput;
    std::cin >> userInput;
    
    if (userInput == "go left")
    {
        worm.MoveLeft();
    }
    else if (userInput == "go right")
    {
        worm.MoveRight();
    }
    
    std::cout << "Worm is at " << worm.GetPosition() << std::endl;
}
```
We create a ```Worm``` object called ```worm``` and call methods on it using
the ```.``` operator.

We could create multiple objects of the```Worm``` type; it would be easy 
to turn this into a multiplayer game just by defining several ```Worm```
objects and calling methods on each of them.

You might have spotted an annoying C++ quirk here. We said before never to
write ```int x;``` because without assigning to it the value might contain
uninitialized data. But for class types writing ```Worm worm;``` will 
_construct_ a ```Worm``` in ```worm```.

Notice that our code to run the game doesn't know or care how fast the 
worm moves, or how the move methods work. We don't need to worry about those
details when writing this code.

## Just scratching the surface...
With classes and object oriented programming being a core paradigm of the 
language, there's a lot we haven't touched on here. A couple of key areas 
that we'll hopefully come back to later:
- Constructors and destructors: defining what happens when an object is
made and when it's destroyed.
- Inheritance and polymorphism: making objects that are extended versions
of other objects, and using objects as if they were of a different type.
- Operator overloading: Letting you define the value of ```worm + worm;```.

A lot of this will be familiar if you've seen code in Java or C# among others, 
but to cover some of them properly in C++ there's a few other topics we ought to 
discuss first.

## Your own example class
If for some reason worms weren't your cup of tea, here's a task for you to 
try. Have a go at defining a class representing a complex number.

It should be clear what the state of the class should be. Think about some 
operations you might want to perform on a complex number. You can implement 
them as methods (and some of them might be better as static methods). This 
might also be a case where it's easier to have ```public:``` member variables,
but that's for you to decide as you write it.

Try writing an algorithm that uses complex numbers as objects of your 
class. Is your class easy to use? What makes it awkward to write code with 
these objects, and can you change the class to make it easier to use?
