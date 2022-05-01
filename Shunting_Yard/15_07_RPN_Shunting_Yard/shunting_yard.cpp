#include "shunting_yard.h"

Shunting_Yard::Shunting_Yard(Queue<Token*> infix)
{
    _infix = infix;
}

Queue<Token*> Shunting_Yard::postfix()
{
    Stack<Token*> oper_stack;


    while (!_infix.empty())
    {
        Token* temp = _infix.Pop()._item;
       // cout<<"temp.type: "<<temp->get_type()<<endl;

        switch (temp->get_type())
        {
            case 1:         //operator
            {
                if(oper_stack.empty())
                {
                    oper_stack.Push(temp);
                }
                else
                {
                    Token* top = *oper_stack.top();
                    if(top->get_type() == 5)
                    {
                        oper_stack.Push(temp);
                    }
                    else if (top->prec() >= temp->prec())
                    {
                            Token* r;
                            r = oper_stack.Pop()._item;
                            _postfix.Push(r);
                            oper_stack.Push(temp);

                    }
                    else if(top->prec() < temp->prec())
                    {
                        oper_stack.Push(temp);
                    }
            }
            break;

            case 2:         //number
            {
                _postfix.Push(temp);
            }
            break;

            case 3:         //variable
            {
                _postfix.Push(temp);
            }
            break;

            case 4:
            {
                oper_stack.Push(temp);
            }
            break;

            case 5:     // '('
            {
                 oper_stack.Push(temp);
            }
            break;

            case 6:     //')'
            {
                Token* top = *oper_stack.top();
                while (top->get_type() != 5)
                {
                    Token* p = oper_stack.Pop()._item;
                    _postfix.Push(p);
                    top = *oper_stack.top();
                }
                oper_stack.Pop();
            }
            break;


            }

        }
//        cout<<"infix: ";
//        cout<<_infix<<endl;
//        cout<<"stack: ";
//        cout<<oper_stack<<endl;
//        cout<<"postfix: ";
//        cout<<_postfix<<endl;
//        cout<<endl;
    }

        //everything in infix is gone

        while (!oper_stack.empty())
        {
            _postfix.Push(oper_stack.Pop()._item);
        }

    return _postfix;
}
