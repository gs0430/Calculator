#include "Modulus.h"

//precedence value of 2 for modulus 
Modulus::Modulus(Stack<int>& s):
stack(s),
Command(2)
{
}

//modulus the top two numbers on the stack
void Modulus::execute(void) 
{
    int num2 = stack.top();
    if (num2 == 0) {
        throw std::runtime_error("Error: Modulus by zero");
    }
    stack.pop();
    int num1 = stack.top();
    stack.pop();
    stack.push(num1 % num2);
}