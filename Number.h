#ifndef _NUMBER_H
#define _NUMBER_H

#include "Command.h"
#include "Stack.h"

class Number : public Command
{
public:

    Number(Stack<int>& s, int n);
    virtual void execute(void) override;

private:
    Stack<int>& stack;
    int number;
};

#endif