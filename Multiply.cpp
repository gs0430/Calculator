#include "Multiply.h"

//precedence value of 2 for multiply
Multiply::Multiply(Stack<int>& s):
stack(s),
Command(2)
{
}

//multiply the top two numbers on the stack
void Multiply::execute(void) 
{
    int num2 = stack.top();
    stack.pop();
    int num1 = stack.top();
    stack.pop();
    stack.push(num1 * num2);
}