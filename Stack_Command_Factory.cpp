#include "Stack_Command_Factory.h"

Stack_Command_Factory::Stack_Command_Factory(Stack<int>& s):
stack(s)
{
}

Stack_Command_Factory::~Stack_Command_Factory(void)
{
}

// methods to create command objects using the stack and return pointer to command object
Add* Stack_Command_Factory::create_add(void)
{
	return new Add(stack);
}

Subtract* Stack_Command_Factory::create_subtract(void)
{
	return new Subtract(stack);
}

Divide* Stack_Command_Factory::create_divide(void)
{
	return new Divide(stack);
}

Multiply* Stack_Command_Factory::create_multiply(void)
{
	return new Multiply(stack);
}

Modulus* Stack_Command_Factory::create_modulus(void)
{
	return new Modulus(stack);
}

Number* Stack_Command_Factory::create_number(int n)
{
	return new Number(stack, n);
}