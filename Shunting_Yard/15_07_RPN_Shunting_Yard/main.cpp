#include <iostream>
#include "rpn.h"
#include "token.h"
#include "operator.h"
#include "variable.h"
#include "integer_number.h"
#include "shunting_yard.h"
#include "function.h"
#include "left_p.h"
#include "tokenize.h"
#include "right_p.h"
#include "tokenize.h"
using namespace std;

int main()
{
    string equation;
    cout<<"input string: "<<endl;
    cin>>equation;
    Tokenize a(equation);
    Queue<Token*> Infix1 = a.Infix_Token();
    cout<<"Infix1: "<<Infix1<<endl;




//    Queue<Token*> Infix1;
//    Infix1.Push(new Variable("x"));
//    Infix1.Push(new Operator("*"));
//    Infix1.Push(new Function("cos"));
//    Infix1.Push(new LEFT_P("("));
//    Infix1.Push(new Integer_Number(1));
//    Infix1.Push(new Operator("/"));
//    Infix1.Push(new Variable("x"));
//    Infix1.Push(new RIGHT_P(")"));
 //   Infix1.Push(new Operator("-"));
//    Infix1.Push(new Operator("-"));
//    Infix1.Push(new Variable("x"));

//    Queue<Token*> Postfix1;

//     Shunting_Yard a (Infix1);
//     Postfix1 = a.postfix();
//     cout<<"Postfix: "<<Postfix1<<endl;

//     RPN rpn1 (Postfix1);
//     double y1;
//        // for (int i = 0;i < 10;i++)
//         {
//            y1 = rpn1.evaluate(1);
//            cout<<"y1: "<<y1<<endl;

//         }


  //  3/(5-(6+7)/(2+8*4))*9

//    Queue<Token*> Infix;

//    Infix.Push(new Integer_Number(3));
//    Infix.Push(new Operator("/"));
//    Infix.Push(new LEFT_P("("));
//    Infix.Push(new Integer_Number(5));
//    Infix.Push(new Operator("-"));
//    Infix.Push(new LEFT_P("("));

//    Infix.Push(new Integer_Number(6));
//    Infix.Push(new Operator("+"));
//    Infix.Push(new Integer_Number(7));
//    Infix.Push(new RIGHT_P(")"));
//    Infix.Push(new Operator("/"));
//    Infix.Push(new LEFT_P("("));
//    Infix.Push(new Integer_Number(2));
//    Infix.Push(new Operator("+"));
//    Infix.Push(new Integer_Number(8));
//    Infix.Push(new Operator("*"));
//    Infix.Push(new Integer_Number(4));
//    Infix.Push(new RIGHT_P(")"));
//    Infix.Push(new RIGHT_P(")"));

//    Infix.Push(new Operator("*"));
//    Infix.Push(new Integer_Number(9));

//    cout<<"infix: "<<Infix<<endl;





//   Queue<Token*> Postfix;

//    Shunting_Yard a (Infix);
//    Postfix = a.postfix();
//    cout<<"Postfix: "<<Postfix<<endl;


//     //  2 3 + 4 6 3 / - * x +

//    Postfix.Push(new Integer_Number(2));
//    Postfix.Push(new Integer_Number(3));

//    Postfix.Push(new Operator("+"));
//    Postfix.Push(new Integer_Number(4));
//    Postfix.Push(new Integer_Number(6));
//    Postfix.Push(new Integer_Number(3));

//    Postfix.Push(new Operator("/"));
//    Postfix.Push(new Operator("-"));
//    Postfix.Push(new Operator("*"));
//    Postfix.Push(new Variable("x"));
//    Postfix.Push(new Operator("+"));





//       Postfix.Push(new Integer_Number(2));
//       Postfix.Push(new Variable("x"));
//       Postfix.Push(new Integer_Number(3));

//    cout<<Postfix;





//    RPN rpn (Postfix);
//    double y;
////    for (int i = 0;i < 10;i++)
////    {
//        cout<<"varibale x = 4\n";
//       y = rpn.evaluate(1);
//       cout<<"y: "<<y<<endl;

//    }



    return 0;
}
