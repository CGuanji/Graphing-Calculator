#include "right_p.h"

RIGHT_P::RIGHT_P(string s):Token (6)
{
    _s = s;
}
int RIGHT_P::get_type()
{
    return 6;
}

void RIGHT_P::print(ostream& outs) const
{
    outs<<_s;
}
