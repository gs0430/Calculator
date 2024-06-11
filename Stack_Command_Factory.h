#ifndef _STACK_COMMAND_FACTORY_H_
#define _STACK_COMMAND_FACTORY_H_

#include "Command_Factory.h"
#include "Stack.h"

#include "Add.h"
#include "Subtract.h"
#include "Divide.h"
#include "Multiply.h"
#include "Modulus.h"
#include "Number.h"


class Stack_Command_Factory : public Command_Factory 
{
public:
    Stack_Command_Factory (Stack<int>& s);
    virtual ~Stack_Command_Factory (void);
    // factory methods to create command objects using the stack
    virtual Add* create_add(void);
    virtual Subtract* create_subtract(void);
    virtual Divide* create_divide(void);
    virtual Multiply* create_multiply(void);
    virtual Modulus* create_modulus(void);
    virtual Number* create_number(int n);

private:
    Stack<int>& stack;
};

#endif