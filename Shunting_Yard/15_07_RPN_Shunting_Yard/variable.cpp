#include "variable.h"

Variable::Variable(string x):Token (3)
{
    _x = x;
    _precendence = 0;
}

void Variable::print(ostream& outs) const
{
    outs<<_x;
}
int Variable:: prec()
{
    return _precendence;
}
int Variable::get_type() const
{
    return 3;
}
