#ifndef RIGHT_P_H
#define RIGHT_P_H
#include "token.h"
#include <iostream>
using namespace std;

class RIGHT_P:public Token
{
public:
    RIGHT_P(string s);
    int get_type() ;
    string get_p()
    {
        return ")";
    }
    void print(ostream& outs) const;


private:
    string _s;

};

#endif // RIGHT_P_H
