#include "Divide.h"

//precedence value of 2 for divide
Divide::Divide(Stack<int>& s):
stack(s),
Command(2)
{
}

//divide the top two numbers on the stack, throw exception if division by zero
void Divide::execute(void)
{
    int num2 = stack.top();
    if (num2 == 0)
    {
        throw std::runtime_error("Error: Division by zero");
    }
    stack.pop();
    int num1 = stack.top();
    stack.pop();
    stack.push(num1 / num2);
}