#ifndef LEFT_P_H
#define LEFT_P_H

#include "token.h"
#include <iostream>

class LEFT_P: public Token
{
public:
    LEFT_P(string s);

    int get_type();
    string get_p()
    {
        return "(";
    }
    void print(ostream& outs) const;


private:
    string _s;
};

#endif // LEFT_P_H
