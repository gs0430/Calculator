#include "Command.h"

// Constructor passes 0 as the default precedence value
Command::Command(void):
precedence(0)
{
}

Command::Command(int p):
precedence(p)
{
}

Command::~Command(void)
{
}

int Command::get_precedence(void)
{
    return precedence;
}
