#ifndef _CALCULATOR_H_
#define _CALCULATOR_H_

#include <string>          
#include <iostream>         
#include <sstream>			
#include "Stack.h"
#include "Array.h"
#include "Queue.h"
#include "Command.h"
#include "Command_Factory.h"
#include "Stack_Command_Factory.h"

class Calculator 
{
public:
    Calculator (void);
    ~Calculator (void);
    // infix to postfix conversion, takes in infix string, factory object, and postfix array, returns postfix array
    Array <Command*> infix_to_postfix (const std::string& infix, Command_Factory& factory, Array <Command*>& postfix);
    // evaluate postfix expression, takes in postfix array and executes commands
    void evaluate_postfix (Array <Command*>& postfix);
    // runs calculator
    void calculate (void);

};

#endif