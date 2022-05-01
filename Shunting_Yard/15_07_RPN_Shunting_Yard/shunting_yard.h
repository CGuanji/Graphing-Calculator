#ifndef SHUNTING_YARD_H
#define SHUNTING_YARD_H

#include "../../../Ch.13/Stack_and_Queue/Stack_and_Queue/queue.h"
#include "../../../Ch.13/Stack_and_Queue/Stack_and_Queue/stack.h"
#include "token.h"
#include "integer_number.h"
#include "variable.h"
#include "function.h"
#include "operator.h"
#include "left_p.h"
#include "right_p.h"
using namespace std;
class Shunting_Yard
{
public:
    Shunting_Yard(Queue<Token*> infix);
    Queue<Token*> postfix();
private:
    Queue<Token*> _infix;
    Queue<Token*> _postfix;
};

#endif // SHUNTING_YARD_H
