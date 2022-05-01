#include "operator.h"

Operator::Operator():Token(1)
{
    _op = "";
    _precedence = 1;
}

Operator::Operator(string op):Token (1)
{
    _op = op;
    if(_op == "+" || _op == "-")
    {
        _precedence = 1;
    }
    else if (_op == "*" || _op == "/")
    {
        _precedence = 2;
    }
    else if(_op == "^")
    {
        _precedence = 3;
    }


}

int Operator::prec()
{
    return _precedence;
}

int Operator::get_type()
{
    return 1;
}
string Operator:: get_oper() const
{
    return _op;
}
void Operator:: print(ostream& outs) const
{
    outs<<_op;
}
