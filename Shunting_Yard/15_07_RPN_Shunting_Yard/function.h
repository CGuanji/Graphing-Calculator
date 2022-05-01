#ifndef FUNCTION_H
#define FUNCTION_H


#include <iostream>
#include "token.h"
using namespace std;

class Function:public Token
{
public:
    Function(string f);

    int get_type();
    string get_function() const;
    int prec();
    void print(ostream &outs) const;


private:
    string _function;
    int _precendence;

};
#endif // FUNCTION_H
