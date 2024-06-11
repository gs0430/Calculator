#ifndef _MULTIPLY_H_
#define _MULTIPLY_H_

#include "Command.h"

class Multiply : public Command 
{
public:
    Multiply(Stack<int>& s);
    virtual void execute(void) override;

private:
    Stack<int>& stack;
};

#endif