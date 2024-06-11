#ifndef _ADD_H_
#define _ADD_H_

#include "Command.h"

class Add : public Command 
{
public:
    Add(Stack<int>& s);
    virtual void execute(void) override;

private:
    Stack<int>& stack;
};

#endif