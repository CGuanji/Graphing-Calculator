#include "rpn.h"

RPN::RPN()
{
  //  cout<<endl<<"焱之狂喜 - The Felo'melorn Constructed!!"<<endl;

}

RPN::RPN(Queue<Token*> expression)
{
   // cout<<endl<<"霜之哀伤 - The Frostmourne Constructed!!"<<endl;
    Postfix = expression;
  //  _result.empty();
}

double RPN::evaluate(double value)
{
    Stack<Token*> stack;
    Token* var1;
    Token* var2;
   // Token* var3;
   // Token* return_val;
    double return_this;
    Queue<Token*> copy = Postfix;
    if(copy.empty())
    {
        return 0;
    }
   // cout<<"copy: "<<copy<<endl;
    while (!copy.empty())
    {
        Token* temp;
        temp = *copy.front();
        int type = temp->get_type();

        switch (type)
        {
            case 1: //operator
            {
                var1 = stack.Pop()._item;
                var2 = stack.Pop()._item;
                copy.Pop()._item;
                if(static_cast<Operator*>(temp)->get_oper() == "+")
                {
                    double push_var = var1->get_num() + var2->get_num();
                    stack.Push(new Integer_Number(push_var));
                }
                else if(static_cast<Operator*>(temp)->get_oper() == "-")
                {
                    double push_var = var2->get_num()- var1->get_num();
                    stack.Push(new Integer_Number(push_var));
                }
                else if(static_cast<Operator*>(temp)->get_oper() == "*")
                {
                    double push_var = var1->get_num() * var2->get_num();
                    stack.Push(new Integer_Number(push_var));
                }
                else if(static_cast<Operator*>(temp)->get_oper() == "/")
                {
                    double push_var = var2->get_num() / var1->get_num();
                    stack.Push(new Integer_Number(push_var));
                }
                else if(static_cast<Operator*>(temp)->get_oper() == "^")
                {
                    double push_var = pow(var2->get_num(),var1->get_num());
                    stack.Push(new Integer_Number(push_var));
                }

            }
            break;

            case 2: //integer
            {
                Token* integer;
                integer = copy.Pop()._item;
                stack.Push(integer);

            }
            break;

            case 3: //variable
            {
                stack.Push(new Integer_Number(value));
                copy.Pop();

            }
            break;
            case 4: //Functions
            {
                double x = stack.Pop()._item->get_num();
                if(static_cast<Function*>(temp)->get_function() == "cos")
                {
//                    cout<<"implement\n";
                    double y = cos(x);
                    stack.Push(new Integer_Number(y));

                }
                else if(static_cast<Function*>(temp)->get_function() == "tan")
                {
//                    cout<<"implement\n";
                    double y = tan(x);
                    stack.Push(new Integer_Number(y));

                }
                else if(static_cast<Function*>(temp)->get_function() == "sin")
                {
//                    cout<<"implement\n";
                    double y = sin(x);
                    stack.Push(new Integer_Number(y));

                }
                else if(static_cast<Function*>(temp)->get_function() == "sinh")
                {
//                    cout<<"implement\n";
                    double y = sinh(x);
                    stack.Push(new Integer_Number(y));

                }
                else if(static_cast<Function*>(temp)->get_function() == "tanh")
                {
//                    cout<<"implement\n";
                    double y = tanh(x);
                    stack.Push(new Integer_Number(y));

                }
                else if(static_cast<Function*>(temp)->get_function() == "cosh")
                {
//                    cout<<"implement\n";
                    double y = cosh(x);
                    stack.Push(new Integer_Number(y));

                }
                else if(static_cast<Function*>(temp)->get_function() == "ln")
                {
//                    cout<<"implement\n";
//                    cout<<"ln: "<<endl;

                    double y = log(x);
                    stack.Push(new Integer_Number(y));

                }
                else if(static_cast<Function*>(temp)->get_function() == "log")
                {
//                    cout<<"implement\n";
                    cout<<"log10: "<<endl;
                    double y = log10(x);
                    stack.Push(new Integer_Number(y));

                }
                copy.Pop();
            }
            break;

        default:
            cout<<"default "<<endl;
            copy.Pop();
            break;
        }

     }
    return_this =  static_cast<Integer_Number*>(stack.Pop()._item)->get_num();

    return return_this;

}
