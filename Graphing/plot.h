#ifndef PLOT_H
#define PLOT_H
#include <SFML/Graphics.hpp>
#include "../../Ch.15/Shunting_Yard/15_07_RPN_Shunting_Yard/rpn.h"
#include "../../Ch.15/Shunting_Yard/15_07_RPN_Shunting_Yard/shunting_yard.h"
#include "graph_info.h"
#include "../../Ch.15/Shunting_Yard/15_07_RPN_Shunting_Yard/tokenize.h"

using namespace std;
class Plot
{
public:
    Plot();
    void change_equation(string equation);
    vector<sf::Vector2f> coordinate(bool polar);
    graph_info info;

private:

    string _equation;
    vector<sf::Vector2f> _coordinate;
    Queue<Token*> Infix;
    Queue<Token*> Postfix;
};

#endif // PLOT_H
