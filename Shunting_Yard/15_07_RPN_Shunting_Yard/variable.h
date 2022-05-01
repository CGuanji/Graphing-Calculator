#ifndef VARIABLE_H
#define VARIABLE_H

#include <iostream>
#include "token.h"
using namespace std;

class Variable: public Token
{
public:
    Variable(string x);

    void print(ostream& outs) const;
    int prec();
    int get_type() const;

private:
    int _precendence;
    string _x;
};

#endif // VARIABLE_H
