#ifndef GRAPH_INFO_H
#define GRAPH_INFO_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <math.h>
#include "constants.h"
using namespace std;

struct graph_info
{
public:
    graph_info();
//    graph_info(int i, int j);

   // string _equation;
    sf::Vector2f window_dimension;
    sf::Vector2f origin;
    sf::Vector2f delta;
    sf::Vector2f window_delta;
    sf::Vector2f domain;
    sf::Vector2f range;
    sf::Vector2f ratio;
    int points;
    float points_delta;
//    sf::Vector2f vec;

};



#endif // GRAPH_INFO_H
