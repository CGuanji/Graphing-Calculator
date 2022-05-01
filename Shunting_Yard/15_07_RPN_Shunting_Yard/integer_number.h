#ifndef INTEGER_NUMBER_H
#define INTEGER_NUMBER_H

#include <iostream>
#include "token.h"
using namespace std;

class Integer_Number:public Token
{
public:
    Integer_Number(double num);
    Integer_Number(string num);
    //accessor

    int get_type() const;
    double get_num() const;

    int prec();
    void print(ostream &outs) const;
private:
    double _num;
    int _precendence;


};

#endif // INTEGER_NUMBER_H
