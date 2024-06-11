#ifndef _COMMAND_H_
#define _COMMAND_H_

#include "Stack.h"

class Command 
{

public:
    Command (void);

    // Constructor that takes a precedence value
    Command (int p);
    ~Command (void);

    // execute the command using appropriate math operation, implemented by each child operator
    virtual void execute (void) = 0;

    // return the precedence of the command
    int get_precedence (void);

private:
    // precedence of the command to handle order of operations
    int precedence;
};
#endif