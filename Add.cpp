#include "Add.h"

//precedence value of 1 for add
Add::Add(Stack<int>& s):
stack(s),
Command(1)
{
}

//add the top two numbers on the stack
void Add::execute(void)
{
    int num2 = stack.top();
    stack.pop();
    int num1 = stack.top();
    stack.pop();
    stack.push(num1 + num2);
}