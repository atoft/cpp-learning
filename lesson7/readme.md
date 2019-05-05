# Memory in practice
Let's get back to looking at actual code.

## The stack
Recall that local variables are allocated in the current _stack frame_. So in the
function
```C++
int DoSomethingAmazing(int amazingArgument)
{
    const int localVariable = GetAmazingInt();
    
    return localVariable + amazingArgument;
}
```
the memory for ```localVariable``` will be allocated at the top of the stack in
the stack frame for the function, when the line defining ```localVariable```
is executed.

Recall also that arguments are copied into the stack frame for the function. So
```amazingArgument``` will also be in the stack frame, and contain a copy of 
whatever value was passed in to the function when it was called.

Finally, the return value will be copied out into the stack frame below when
the function returns, so that it can be used by whatever was calling the 
function.

The same is also true for objects. So if we write
```C++
Worm player1Worm;
```
the memory for the worm is allocated in the current stack frame, including the
member variables that are inside it. As above, if it's passed into or out of
a function all the data must be copied in and out of the relevant stack frames.

Remember we mentioned the possibility of there being too many frames on the 
stack? What happens if you run this program?
```C++
#include <iostream>

int RecursiveFunction(int argument)
{
    std::cout << "Called function " << argument << std::endl;

    return RecursiveFunction(argument + 1);
}

int main()
{
    return RecursiveFunction(0);
}
```

## The heap
So you want to store something on the heap? We'll start with the way this is
done in old school C++, and then present some modern (often better)
alternatives.

For these examples we'll use ```Worm``` again, but you can put any object on 
the heap, and even primitive types too (although there are few reasons to do
that).

```C++
Worm* worm1 = new Worm();

const float position = worm1->GetPosition();

std::cout << "Heap worm is at position " << position << std::endl;
```
Ooh, exciting! The ```new``` keyword is the traditional C++ way to ask for 
an object to be constructed on the heap instead of on the stack.

It returns a _pointer_ to the object on the heap. Pointers have some different
syntax and behaviour.

The ```*``` after the type name means "pointer to". So in this example, 
```worm1``` is of type "pointer to ```Worm```". There's a new operator being 
introduced here too, the ```->```. It's the same as using ```.``` but on the 
object that's being pointed to.

Notice that while your ```Worm``` is on the heap, your ```Worm*``` variable
(the pointer, rather than the object itself) is still being stored on the stack.

So, if we have a function:

```C++
void UpdateWorms(Worm* worm1, Worm* worm2)
{
    worm1->MoveRight();
    worm2->MoveLeft();
    
    if (worm1->GetPosition() == worm2->GetPosition())
    {
        std::cout << "Worms are friends!" << std::endl;
    }
}
``` 
The arguments are still copied into the stack frame, but these arguments are
only the _pointers to the objects_ and not the objects themselves.

This function modifies the objects on the heap, and those modifications will
be seen by any other code looking at the objects on the heap.

## What's in a pointer?
Last lesson we were referring to memory addresses, and now we've switched to
using pointers. It turns out that a pointer is just a variable containing a
memory address.

Pointers are integers, where each integer value is a unique location in 
memory. Pointers are 32-bit or 64-bit integers, depending on whether your 
computer and operating system is 32-bit or 64-bit. In fact, that's exactly 
what the difference is between them, 64-bit computers have longer memory 
addresses so they can support more memory!

In fact, we can see this quite easily. Try writing:
```C++
Worm* worm = new Worm();
std::cout << worm << std::endl;
```
What's printed is actually the memory address of the worm. It's 
written in a [hexadecimal](https://en.wikipedia.org/wiki/Hexadecimal) format
but effectively you're just seeing the integer representing the worm's 
location in memory.

## What's a null pointer?
I'm sure you've heard about problems relating to "null pointers" before. But
what's a null pointer? Pointers are just integers, and one integer value is 
reserved to mean nowhere, or not valid. That integer is called ```nullptr```
(it's usually an address of all zeroes).

There's a few reasons we might have a ```nullptr``` in our program. Maybe 
there's a function that returns a pointer to an object, but sometimes 
(maybe if there's an error or a certain special case) there might be nothing
for it to point to. The function can return ```nullptr``` as sort of an
"empty" or invalid value. Similarly, maybe we have a class with a pointer as a
member variable. Maybe ```Worm``` has a pointer to its image that will appear
on the screen. But we need a default value to set that pointer to at the 
start of the program, before we've allocated the image in memory. So the 
pointer is initialized to ```nullptr``` until we set up the object with 
a valid pointer later.

The problems arise when we try to use a pointer that is set to ```nullptr```.
If we try to access the object pointed to by a null pointer, the program will
crash. For example, running the program:
```C++
Worm* worm = nullptr;

worm->MoveLeft();
```
on my Linux computer crashes with the message
```
Segmentation fault (core dumped)
```
which is telling us that the program was stopped because it tried to access
some memory that it wasn't allowed to (the memory at address zero).
This is why code taking a pointer will often contain null checks:
```C++
void UpdateWorms(Worm* worm1, Worm* worm2)
{
    if (worm1 != nullptr && worm2 != nullptr)
    {
        worm1->MoveRight();
        worm2->MoveLeft();
        
        if (worm1->GetPosition() == worm2->GetPosition())
        {
            std::cout << "Worms are friends!" << std::endl;
        }
    }
}
```
to be sure there won't be a crash if it is given a null pointer.

## Deallocating memory
We used ```new``` to allocate some memory on the heap. Remember that this 
memory stays allocated until the end of the program unless we explicitly
deallocate it, even if there are no pointers left around to point to it.

The keyword to deallocate an object from the heap is ```delete```.

```C++
Worm* yetAnotherWorm = new Worm();

yetAnotherWorm->MoveLeft();
std::cout << yetAnotherWorm->GetPosition() << std::endl;

// We've finished with the object

delete(yetAnotherWorm);

// Uh oh...
yetAnotherWorm->MoveLeft();
```
After the call to ```delete``` the memory pointed to by our pointer is no
longer allocated for us to use. But notice that we still have the local
variable containing the pointer. This is known as a _dangling pointer_. 
It's not set to ```nullptr```, but the address it contains is no longer a 
valid piece of memory for us to use.

If we accidentally use the pointer like we do in the code above, it's undefined
behaviour. The program could crash, or it could keep on running but reading 
memory that no longer contains a valid object.

## Other pointer operations
There's a couple of other, slightly less common, operators relating to pointers.

The ```&``` operator lets us get a pointer to an object that we have locally.
```C++
Worm wormLocalVariable;

Worm* wormPointer = &wormLocalVariable;
```
```&wormLocalVariable``` can be read as "address of ```wormLocalVariable```".
Notice that this has given us a pointer to an object which is on the stack!

The ```*``` operator is the opposite. It lets us get an object from a pointer.
Personally I found this one confusing when first learning about pointers, because
of the similarity between having a ```*``` in the type name and a ```*``` as
an operator. It'll become less confusing with time!
```C++
Worm* wormPointer = new Worm();

Worm wormLocalVariable = *wormPointer;
```
You can read ```*wormPointer``` as "dereference the ```wormPointer```" or
"get the object pointed to by ```wormPointer```". 

```wormLocalVariable``` now contains a _copy_ of the object that was on the 
heap.

## Still to come
Hopefully you've seen how the ideas from last lesson are important when writing
code in C++. You've also seen how many headaches and potential problems they
can cause! And if you find them challenging, don't worry, even the most 
large and complex C++ projects still have crashes and bugs from dangling 
pointers and the like (I'm not sure if that's meant to be reassuring or 
not...). Anyway, next time we'll look at some ways that people have tried to 
deal with these problems, in particular how the modern standard library can
avoid _some_ of the headaches.
