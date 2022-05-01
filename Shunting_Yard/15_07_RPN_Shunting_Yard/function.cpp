#include "function.h"

Function::Function(string f):Token(4)
{
    _function = f;
    _precendence = 10;
}


int Function::get_type()
{
    return 4;
}

string Function::get_function() const
{
    return _function;
}

int Function::prec()
{
    return 10;
}

void Function::print(ostream& outs) const
{
    outs<<_function;
}
