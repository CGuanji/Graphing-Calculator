#ifndef TOKEN_H
#define TOKEN_H
#include <iostream>
using namespace std;

class Token
{
public:
    Token();
    Token(int type);
    virtual ~Token();

    virtual int get_type() const;
    void set_type(int type);
    virtual void print(ostream& outs) const;
    virtual int prec();
    virtual string get_p();
    virtual string get_oper() const;
    virtual double get_num() const;
    virtual string get_function() const;

    friend ostream& operator <<(ostream& outs,Token* n_ptr);
private:
    int _type;
    int _precendence;

//    string _tok_str;

};

#endif // TOKEN_H
