#include "integer_number.h"

Integer_Number::Integer_Number(double num):Token(2)
{
    _num = num;
    _precendence = 0;

}
Integer_Number::Integer_Number(string num):Token (2)
{
    _num = stod(num);
    _precendence = 0;
}
int Integer_Number::get_type() const
{
    return 2;
}
int Integer_Number::prec()
{
    return _precendence;
}
void Integer_Number:: print(ostream& outs) const
{
    outs<<_num;
}
double Integer_Number:: get_num() const
{
   return _num;
}
