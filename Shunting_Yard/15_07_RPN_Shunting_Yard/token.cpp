#include "token.h"

Token::Token()
{
    _type = 0;
    _precendence = 0;
}
Token::Token(int type)
{
   _type = type;

}


Token::~Token()
{

}
string Token:: get_p()
{

}

int Token::get_type() const
{
    return  _type;
}

void Token::set_type(int type)
{
    _type  = type;
}

void Token::print(ostream &outs) const
{
    outs<<" vitural ";
}

int Token::prec()
{
    return _precendence;
}
string Token::get_oper() const
{
    cout<<"Token class:: get_operator"<<endl;
}
string Token::get_function() const
{
    cout<<"get functions"<<endl;
}
double Token:: get_num() const
{

}
ostream& operator <<(ostream& outs,Token* n_ptr)
{
    n_ptr->print(outs);
    return outs;
}
