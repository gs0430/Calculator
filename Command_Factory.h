#ifndef _COMMAND_FACTORY_H_
#define _COMMAND_FACTORY_H_

#include "Add.h"
#include "Subtract.h"
#include "Divide.h"
#include "Multiply.h"
#include "Modulus.h"
#include "Number.h"

class Command_Factory 
{
public:
    Command_Factory (void);
    virtual ~Command_Factory (void);

    // factory methods to create command objects
    virtual Add* create_add(void) = 0;
    virtual Subtract* create_subtract(void) = 0;
    virtual Divide* create_divide(void) = 0;
    virtual Multiply* create_multiply(void) = 0;
    virtual Modulus* create_modulus(void) = 0;
    virtual Number* create_number(int n) = 0;
};

#endif