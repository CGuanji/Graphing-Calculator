#include "plot.h"

Plot::Plot()
{
//    string equation;
//    cout<<"give you equation: ";
//    cin>>equation;
//    Tokenize tok(equation);
//    Infix = tok.Infix_Token();


//        Infix.Push(new Variable("x"));
//        Infix.Push(new Operator("*"));


//        Infix.Push(new Function("cosh"));
//        Infix.Push(new LEFT_P("("));
//        Infix.Push(new Integer_Number(1));
//        Infix.Push(new Operator("/"));

//        Infix.Push(new Variable("x"));
//        Infix.Push(new RIGHT_P(")"));


//        Infix.Push(new Variable("x"));
//        Infix.Push(new Operator("*"));
//        Infix.Push(new Variable("x"));
//        Infix.Push(new Operator("*"));
//        Infix.Push(new Variable("x"));
//          Infix.Push(new Function("tanh"));
//          Infix.Push(new LEFT_P("("));
//          Infix.Push(new Variable("x"));
//          Infix.Push(new RIGHT_P(")"));

//        cout<<"infix: "<<Infix<<endl;
//    string equation;
        _equation = "x";
        Tokenize tok(_equation);
        Infix = tok.Infix_Token();

        Shunting_Yard a (Infix);
        Postfix = a.postfix();
        cout<<"Postfix: "<<Postfix<<endl;

//    Postfix.Push(nullptr);

}
void Plot::change_equation(string equation)
{
    _equation = equation;
    Tokenize tok(_equation);

    Infix = tok.Infix_Token();

    Shunting_Yard shunt (Infix);
    Postfix = shunt.postfix();
    cout<<"Postfix: "<<Postfix<<endl;

}

vector<sf::Vector2f> Plot::coordinate(bool polar) //get coordinate to stream
{
    RPN a(Postfix);
    sf::Vector2f screen;

    _coordinate.clear();

//    cout<<"domain.x: "<<info.domain.x<<endl;
//    cout<<"domain.y: "<<info.domain.y<<endl;

//    cout<<"origin.x: "<<info.origin.x<<endl;

//    cout<<"info points_delta: "<<info.points_delta<<endl;

    if(polar)
    {
        float incr = info.points_delta;
       // for (int j = 0;j < 360;j+=0.1)
        {
            for (float i = info.domain.x;
                    i < info.domain.y ;i+=incr)
            {
                float r;
                float x = i;

                float y = a.evaluate(x);

                r = y;

                float true_x;
                float true_y;

                true_x = r*cos(x);
                true_y = r*sin(x);


                screen.x = info.window_delta.x * (true_x - info.domain.x);
                screen.y = info.origin.y-info.window_delta.y * true_y;

               _coordinate.push_back(screen);
            }
            return _coordinate;
        }

    }
    else
    {
        float incr = info.points_delta;
        for (float i = info.domain.x;
                i < info.domain.y ;i+=incr)
        {
            float x = i;

            float y = a.evaluate(x);

            //screen delta * (x - x-min);


            screen.x = info.window_delta.x * (x - info.domain.x);
            screen.y = info.origin.y-info.window_delta.y * y;

           _coordinate.push_back(screen);
        }
        return _coordinate;
    }

}
