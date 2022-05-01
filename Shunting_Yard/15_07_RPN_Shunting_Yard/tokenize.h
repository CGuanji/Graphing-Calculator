#ifndef TOKENIZE_H
#define TOKENIZE_H

#include <iostream>
#include "token.h"
#include "../../../Ch.13/Stack_and_Queue/Stack_and_Queue/queue.h"
#include "function.h"
#include "integer_number.h"
#include "left_p.h"
#include "right_p.h"
#include "operator.h"
#include "variable.h"
#include <vector>
#include <math.h>

using namespace std;
class Tokenize:public Token
{
public:
    Tokenize(string equation);
    Queue<Token*> Infix_Token();


private:
    string _equation;
};

#endif // TOKENIZE_H
