#include "tokenize.h"

Tokenize::Tokenize(string equation):Token ()
{
    _equation = equation;
}

Queue<Token*> Tokenize::Infix_Token()
{
    Queue<Token*> return_me;
    for (int i = 0; i < _equation.length();i++)
    {
        if(isdigit(_equation[i]))
        {
            vector<int> a;
            int length = 0;
            while(isdigit(_equation[i]))
            {
                int x = _equation[i]-'0';
                a.push_back(x);
                i++;
                length++;
            }
            double value = 0;
            int run = 0;
          //  cout<<"length: "<<length<<endl;
            length--;
            while(length >= 0)
            {
             //   cout<<"a.run: "<<a[run]<<endl;
                value += pow(10,length) * a[run];
                run++;
                length--;
            //    cout<<"value inside: "<<value<<endl;

            }

            //cout<<"value: "<<value<<endl;
            return_me.Push(new Integer_Number(value));

        }
        if(_equation[i] == 'e')
        {
            return_me.Push(new Integer_Number(2.71));

        }
        if(_equation[i] == 'p')
        {
            if(_equation[i+1] == 'i')
            {
                return_me.Push(new Integer_Number(3.14));
                i++;
            }

        }

        if(_equation[i]=='-')
        {
            if (i==0)
            {

                if(_equation[i+1] == 's'||_equation[i+1] == 'c'||_equation[i+1] == 't')
                {
                    cout<<"haha";
                    return_me.Push(new Integer_Number(-1));
                    return_me.Push(new Operator("*"));

                }
                else
                {
                    double num = _equation[i+1]-'0';
    //                cout<<"num::"<< num<<endl;
                    num = num*-1;
                    i++;
                    return_me.Push(new Integer_Number(num));
                }


            }
            else if(_equation[i-1]=='+'||_equation[i-1]=='-'||_equation[i-1]=='*'||_equation[i-1]=='/'||_equation[i-1]=='^')
            {
                double num = _equation[i+1]-'0';
              //  cout<<"num::"<< num<<endl;
                num = num*-1;
                i++;
                return_me.Push(new Integer_Number(num));

            }

            else
            {
                return_me.Push(new Operator("-"));
            }

        }
        if(_equation[i]=='+')
        {
            return_me.Push(new Operator("+"));
        }
        if(_equation[i]=='*')
        {
            return_me.Push(new Operator("*"));
        }
        if(_equation[i]=='/')
        {
            return_me.Push(new Operator("/"));
        }
        if(_equation[i]=='^')
        {
            return_me.Push(new Operator("^"));
        }
        if(_equation[i] =='s')
        {
            if(_equation[i+1]=='i')
            {
                if(_equation[i+2] == 'n')
                {
                    if(_equation[i+3] == 'h')
                    {
                        i+=3;
                        return_me.Push(new Function("sinh"));
                    }
                    else
                    {
                        i+=2;
                        return_me.Push(new Function("sin"));
                    }
                }
            }

        }
        if(_equation[i] =='c')
        {
            if(_equation[i+1]=='o')
            {
                if(_equation[i+2] == 's')
                {
                    if(_equation[i+3] == 'h')
                    {
                        i+=3;
                        return_me.Push(new Function("cosh"));
                    }
                    else
                    {
                        i+=2;
                        return_me.Push(new Function("cos"));
                    }
                }
            }

        }
        if(_equation[i] =='t')
        {
            if(_equation[i+1]=='a')
            {
                if(_equation[i+2] == 'n')
                {
                    if(_equation[i+3] == 'h')
                    {
                        i+=3;
                        return_me.Push(new Function("tanh"));
                    }
                    else
                    {
                        i+=2;
                        return_me.Push(new Function("tan"));
                    }
                }
            }

        }
        if(_equation[i] =='l')
        {
            if(_equation[i+1]=='n')
            {

                return_me.Push(new Function("ln"));
                i++;

            }


        }
        if(_equation[i] =='l')
        {
            if(_equation[i+1]=='o')
            {
                if(_equation[i+2] =='g')
                {
                    return_me.Push(new Function("log"));
                    i+=2;
                }
            }

        }
        if(_equation[i] == '(')
        {
            return_me.Push(new LEFT_P("("));
        }
        if(_equation[i] == ')')
        {
            return_me.Push(new RIGHT_P(")"));
        }
        if(_equation[i] == 'x')
        {
            return_me.Push(new Variable("x"));
        }

//        if(_equation[i] == '.')
//        {
//            double pop = return_me.Pop()._item->get_num();
//            i++;
//            int decimal = 1;
//            if(isdigit(_equation[i]))
//            {
//                double value = (_equation[i]*1.0)/()
//            }
//        }

    }
    return return_me;
}

