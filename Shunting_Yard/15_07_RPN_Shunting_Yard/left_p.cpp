#include "left_p.h"

LEFT_P::LEFT_P(string s):Token (5)
{
    _s = s;
}

int LEFT_P::get_type()
{
    return 5;
}

void LEFT_P::print(ostream &outs) const
{
    outs<<_s;
}
