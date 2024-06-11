#include "Number.h"

// precedence value of 0 for number, the default precedence value passed from Command constructor
Number::Number(Stack<int>& s, int n): 
stack(s), 
number(n)
{
}

// push the number onto the stack
void Number::execute(void) {
    stack.push(number);
}