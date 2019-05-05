#include <iostream>

// This code example will crash!

int RecursiveFunction(int argument)
{
    std::cout << "Called function " << argument << std::endl;

    return RecursiveFunction(argument + 1);
}

int main()
{
    return RecursiveFunction(0);
}