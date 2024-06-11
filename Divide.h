#ifndef _DIVIDE_H_
#define _DIVIDE_H_

#include "Command.h"

class Divide : public Command 
{
public:
    Divide(Stack<int>& s);
    virtual void execute(void) override;

private:
    Stack<int>& stack;
};

#endif