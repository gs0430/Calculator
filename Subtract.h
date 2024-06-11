#ifndef _SUBTRACT_H_
#define _SUBTRACT_H_

#include "Command.h"

class Subtract : public Command 
{
public:
    Subtract(Stack<int>& s);
    virtual void execute(void) override;

private:
    Stack<int>& stack;
};

#endif