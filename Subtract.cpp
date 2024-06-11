#include "Subtract.h"

// precedence value of 1 for subtract
Subtract::Subtract(Stack<int>& s):
stack(s),
Command(1)
{
}

// subtract the top two numbers on the stack
void Subtract::execute(void)
{
    int num2 = stack.top();
    stack.pop();
    int num1 = stack.top();
    stack.pop();
    stack.push(num1 - num2);
}