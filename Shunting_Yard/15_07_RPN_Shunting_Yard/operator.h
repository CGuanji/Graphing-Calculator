#ifndef OPERATOR_H
#define OPERATOR_H

#include <iostream>
#include "token.h"
using namespace std;

class Operator: public Token
{
public:
    Operator();
    Operator(string op);

    void print(ostream& outs) const;
    int prec();
    int get_type();
    string get_oper() const;
private:
    string _op;
    int _precedence;
};

#endif // OPERATOR_H
