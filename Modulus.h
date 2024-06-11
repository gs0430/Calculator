#ifndef _MODULUS_H_
#define _MODULUS_H_

#include "Command.h"

class Modulus : public Command 
{
public:
    Modulus(Stack<int>& s);
    virtual void execute(void) override;

private:
    Stack<int>& stack;
};

#endif