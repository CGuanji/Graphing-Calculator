#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include "system.h"
#include "sidebar.h"
#include <string>


class animate{
public:
    animate();
    void run();
    void processEvents();
    void update();
    void render();
    void Draw();
    void Save();
    void Load();
    void Load_Button();
private:
    bool update_click;
    sf::RenderWindow window;
    sf::CircleShape mousePoint;         //The little red dot
    System system;                      //container for all the animated objects
    int command;                        //command to send to system
    sf::Font font;                      //font to draw on main screen
    sf::Text myTextLabel;               //text to draw on main screen
    bool mouseIn;                       //mouse is in the screen
    Sidebar sidebar;                    //rectangular message sidebar
    sf:: String s;      //sfml
    std::string a;      //convertion
    std::string true_equation;      //convertion

    int sidebar_store_number;


};

string mouse_pos_string(sf::RenderWindow& window);

#endif // GAME_H
