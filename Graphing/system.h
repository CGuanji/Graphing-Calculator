#ifndef SYSTEM_H
#define SYSTEM_H
#include <vector>
#include <SFML/Graphics.hpp>
#include "plot.h"
#include <sstream>


using namespace std;
class System
{
public:
    System();
    void Step(int command);
    int Size();
    void Draw(sf::RenderWindow& widnow);
    void Pass_Equation(string equation);
    void draw_new(bool change);
    string get_string();
    void pass_update_equation(string update_equation);
    bool is_ok(bool k);
    bool ok;    //for graph the update-equation

    void reset_domain_range();

    //accessor
    string see_domain();
    string see_range();
    float round(float x);



private:
//    vector<Particle> system;
    bool _change;

    sf::CircleShape shape;
    sf::Vector2f vel;
    vector<sf::CircleShape> graph;
    sf::Text myTextLabel;               //text to draw on main screen
    sf::Font font;                      //font to draw on main screen

    int count;

    int size_of_draw;
    string _update_equation;

    //axis
    string _equation;

    sf::RectangleShape draw_graph;
    sf::RectangleShape x_axis;
    sf::RectangleShape y_axis;

    Plot plot;
  //  Plot plot_first(string equation);
    sf::CircleShape push_val;
    sf::Vector2f a;
    vector<sf::Vector2f> pop_v;

    //function bar
    sf::RectangleShape function_bar;

    //polar
    bool polar;


};

#endif // SYSTEM_H
