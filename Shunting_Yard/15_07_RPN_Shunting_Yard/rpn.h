#ifndef RPN_H
#define RPN_H

#include  "../../../Ch.13/Stack_and_Queue/Stack_and_Queue/queue.h"
#include  "../../../Ch.13/Stack_and_Queue/Stack_and_Queue/stack.h"
#include "token.h"
#include "operator.h"
#include "variable.h"
#include "integer_number.h"
#include "math.h"
#include "right_p.h"
#include "left_p.h"
#include "function.h"
using namespace std;

class RPN
{
public:
    RPN();
    RPN(Queue<Token*> expression);

    double evaluate(double value);
private:
    Queue<Token*> Postfix;
    Stack<double> _result;
};

#endif // RPN_H
