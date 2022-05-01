#include "animate.h"
#include "constants.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;
#include "system.h"


animate::animate():sidebar(WORK_PANEL, SIDE_BAR)

{
    cout<<"animate CTOR: TOP"<<endl;
    window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "SFML window!");
    //VideoMode class has functions to detect screen size etc.
    //RenderWindow constructor has a third argumnet to set style
    //of the window: resize, fullscreen etc.

    //System will be implemented to manage a vector of objects to be animated.
    //  at that point, the constructor of the System class will take a vector
    //  of objects created by the animate object.
    //  animate will

    system = System();
    window.setFramerateLimit(60);

    mouseIn = true;
  //  Plot a();




    mousePoint = sf::CircleShape();
    mousePoint.setRadius(5.0);
    mousePoint.setFillColor(sf::Color::Red);

    cout<<"Geme CTOR. preparing to load the font."<<endl;
    //--- FONT ----------
    //font file must be in the "working directory:
    //      debug folder
    //Make sure working directory is where it should be and not
    //  inside the app file:
    //  Project->RUN->Working Folder
    //
    //font must be a member of the class.
    //  Will not work with a local declaration
    if (!font.loadFromFile("arial.ttf")){
        cout<<"animate() CTOR: Font failed to load"<<endl;
        cin.get();
        exit(-1);
    }
    sidebar_store_number = 12;
 //   sidebar_store_number += 4;

    sidebar[10] = "HISTORY";
    sidebar[36] = "Polar";

  //  Save();

   // Load();
    update_click = false;







    cout<<"animate instantiated successfully."<<endl;
}

void animate::Draw(){
    //Look at the data and based on the data, draw shapes on window object.
    system.Draw(window);
    if (mouseIn){
        window.draw(mousePoint);
    }

    sidebar.draw(window);
    //- - - - - - - - - - - - - - - - - - -
    //getPosition() gives you screen coords, getPosition(window) gives you window coords
    //cout<<"mosue pos: "<<sf::Mouse::getPosition(window).x<<", "<<sf::Mouse::getPosition(window).y<<endl;
    //- - - - - - - - - - - - - - - - - - -

    //drawing Test: . . . . . . . . . . . .
    //This is how you draw text:)
    //. . . . . . . . . . . . . . . . . . .
    //cout<<"sideber "<<sidebar[1]<<endl;
}

void animate::update(){
    //cause changes to the data for the next frame
    system.Step(command);
    command = 0;
    if (mouseIn){
        //mousePoint red dot:
        mousePoint.setPosition(sf::Mouse::getPosition(window).x-5,
                               sf::Mouse::getPosition(window).y-5);

        //mouse location text for sidebar:
        sidebar[SB_MOUSE_POSITION] = mouse_pos_string(window);


    }
  //  cout<<"update: "<<a<<endl;


    if(update_click)
    {
        system.pass_update_equation(true_equation);
        a = true_equation;
    }
    else
    {
        system.pass_update_equation(a);

    }
    update_click = false;



    if(sidebar_store_number==20)
    {
        sidebar_store_number = 12;
    }
    sidebar[30] =  system.see_domain();

    sidebar[32] =  system.see_range();

}
void animate::render(){
       window.clear();
       Draw();
       window.display();
}



void animate::processEvents()
{
   sf::Event event;
   float mouseX, mouseY;
   while (window.pollEvent(event))//or waitEvent
       {
       // check the type of the event...
           switch (event.type)
           {
           // window closed
           case sf::Event::Closed:
               window.close();
               break;

           // key pressed
           case sf::Event::KeyPressed:
               switch(event.key.code)
               {
                case sf::Keyboard::Left:
                   sidebar[SB_KEY_PRESSED] = "Shift Left";
                   command = 4;
                   break;
               case sf::Keyboard::Right:
                   sidebar[SB_KEY_PRESSED] = "Shift Right";
                   command = 5;
                   break;
               case sf::Keyboard::Up:
                  sidebar[SB_KEY_PRESSED] = "Shift Up";
                  command = 6;
                  break;
              case sf::Keyboard::Down:
                  sidebar[SB_KEY_PRESSED] = "Shift Down";
                  command = 7;
                  break;

               case sf::Keyboard::Period:
                   sidebar[SB_KEY_PRESSED] = "Zoom in";
//                   cout<<"shshshsh"<<endl;
                   command = 8;
                   break;
               case sf::Keyboard::Comma:
                   sidebar[SB_KEY_PRESSED] = "Zoom out";
                   command = 9;
                   break;
               case sf::Keyboard::F:
                   sidebar[SB_KEY_PRESSED] = "Function Entering... ";


                   command = 11;

                   break;


               case sf::Keyboard::Escape:
                   sidebar[SB_KEY_PRESSED] = "ESC: EXIT";
                   window.close();
                break;
               }

               break;
           case sf::Event::MouseEntered:
               mouseIn = true;
               break;


           case sf::Event::TextEntered:
           {
             //  if(command == 11)
               {
                   sidebar[SB_KEY_PRESSED] = "Function Entering... ";

                    if(event.text.unicode==44||event.text.unicode==46)
                    {

                    }
                    else if(event.text.unicode == 8 && s.getSize()>0)//delete
                    {
                        s.erase(s.getSize()-1,s.getSize());
                    }
                    else if (event.text.unicode >= 32  &&event.text.unicode <= 126)

                    {
                        s += static_cast<char>(event.text.unicode);

                    }

                    if((event.text.unicode == 70 || event.text.unicode == 102)  && s.getSize()==1)
                    {
                        s.erase(s.getSize()-1,s.getSize());
                    }


                    a = s;
                    cout<<"\na: "<<a<<endl;




                    if(event.text.unicode == 10)
                    {
                        cout<<"enter"<<endl;
                        if(a != "")
                        {
                            cout<<"sidebar_number: "<<sidebar_store_number<<endl;
                            sidebar[sidebar_store_number] = system.get_string();
                            sidebar_store_number+=2;
                          //  Save();
                            true_equation = a;

                            system.Pass_Equation(true_equation);

                            system.draw_new(true);
                            Save();
                            s.clear();
                            cout<<"cleared"<<endl;
                            command = 10;
                        }
                    }

                    break;
               }

           }


           case sf::Event::MouseLeft:
               mouseIn = false;
               break;

           case sf::Event::MouseMoved:
                mouseX = event.mouseMove.x;
                mouseY = event.mouseMove.y;
                //Do something with it if you need to...
               break;
           case sf::Event::MouseButtonReleased:
                   if (event.mouseButton.button == sf::Mouse::Right)
                   {
                      // sidebar[SB_MOUSE_CLICKED] = "RIGHT CLICK " +
                               mouse_pos_string(window);

                   }
                   else
                   {
                       cout<<"outside: "<<endl;
                    //   sidebar[SB_MOUSE_CLICKED] = "LEFT CLICK " +
                               mouse_pos_string(window);
                       Load_Button();
                   }
                   break;


               default:
                   break;
           }
       }
}
void animate::run()
{
   while (window.isOpen())
   {
       processEvents();
       update();
       render(); //clear/draw/display
   }
   cout<<endl<<"-------ANIMATE MAIN LOOP EXITING ------------"<<endl;
}

string mouse_pos_string(sf::RenderWindow& window){
    return "(" +
            to_string(sf::Mouse::getPosition(window).x) +
            ", " +
            to_string(sf::Mouse::getPosition(window).y) +
            ")";
}
void animate::Save()
{
    ofstream oFile;

    oFile.open("functions.txt");

    for (int i = 10;i < 20;i+=2)   //the first one is "HISTORY"
    {

        if(!sidebar[i].empty())
        oFile<<sidebar[i]<<endl;
    }

    oFile.close();
    cout<<"file constructed ";
}
void animate::Load()
{
    ifstream iFile;
    iFile.open("functions.txt");
    int change_line = 10;
    string equation;
    while (iFile && change_line<20)
    {
        getline(iFile,equation);
        sidebar[change_line] = equation;
        change_line+=2;
    }
   // cout<<"\nequation: "<<equation<<endl;;
    iFile.close();
}
void animate::Load_Button()
{
    //sidebar range
    if(sf::Mouse::getPosition(window).x >1128
            && sf::Mouse::getPosition(window).x < 1420
                && sf::Mouse::getPosition(window).y > 0
                    &&sf::Mouse::getPosition(window).y < 800)
    {

        if(sf::Mouse::getPosition(window).x >1127
                && sf::Mouse::getPosition(window).x < 1226
                    && sf::Mouse::getPosition(window).y > 222
                        &&sf::Mouse::getPosition(window).y < 250)
        {
            cout<<"load"<<endl;
            Load();
        }

        if(sf::Mouse::getPosition(window).x >1127
                && sf::Mouse::getPosition(window).x < 1240
                    && sf::Mouse::getPosition(window).y > 265
                        &&sf::Mouse::getPosition(window).y < 290)
        {
            cout<<"sidebar number: "<<sidebar_store_number<<endl;
            //pass to history
            command = 10;
            cout<<"current string: "<<system.get_string();
            sidebar[sidebar_store_number] = system.get_string();
            sidebar_store_number+=2;

            true_equation = sidebar[12];
            cout<<"what is true equation: "<<true_equation<<endl;

            system.Pass_Equation(true_equation);
            system.is_ok(true);



            system.draw_new(true);
            update_click = true;
        }
        if(sf::Mouse::getPosition(window).x >1127
                && sf::Mouse::getPosition(window).x < 1240
                    && sf::Mouse::getPosition(window).y > 309
                        &&sf::Mouse::getPosition(window).y < 336)
        {
            cout<<"sidebar number: "<<sidebar_store_number<<endl;

            //pass to history
            command = 10;
            cout<<"current string: "<<system.get_string();
            sidebar[sidebar_store_number] = system.get_string();
            sidebar_store_number+=2;

            true_equation = sidebar[14];
            cout<<"what is true equation: "<<true_equation<<endl;

            system.Pass_Equation(true_equation);
            system.is_ok(true);



            system.draw_new(true);
            update_click = true;
        }
        if(sf::Mouse::getPosition(window).x >1127
                && sf::Mouse::getPosition(window).x < 1240
                    && sf::Mouse::getPosition(window).y > 356
                        &&sf::Mouse::getPosition(window).y < 386)
        {
            cout<<"sidebar number: "<<sidebar_store_number<<endl;

            //pass to history
            command = 10;
            cout<<"current string: "<<system.get_string();
            sidebar[sidebar_store_number] = system.get_string();
            sidebar_store_number+=2;

            true_equation = sidebar[16];
            cout<<"what is true equation: "<<true_equation<<endl;

            system.Pass_Equation(true_equation);
            system.is_ok(true);



            system.draw_new(true);
            update_click = true;
        }
        if(sf::Mouse::getPosition(window).x >1127
                && sf::Mouse::getPosition(window).x < 1240
                    && sf::Mouse::getPosition(window).y > 398
                        &&sf::Mouse::getPosition(window).y < 430)
        {
            cout<<"sidebar number: "<<sidebar_store_number<<endl;

            //pass to history
            command = 10;
            cout<<"current string: "<<system.get_string();
            sidebar[sidebar_store_number] = system.get_string();
            sidebar_store_number+=2;

            true_equation = sidebar[18];
            cout<<"what is true equation: "<<true_equation<<endl;

            system.Pass_Equation(true_equation);
            system.is_ok(true);



            system.draw_new(true);
            update_click = true;
        }


        Save();

    //polar
        if(sf::Mouse::getPosition(window).x > 1127
                &&sf::Mouse::getPosition(window).x < 1240
                    &&sf::Mouse::getPosition(window).y >730
                        &&sf::Mouse::getPosition(window).y < 770)
        {
            command = 13;
        }


    }
    if(sf::Mouse::getPosition(window).x > 0
            &&sf::Mouse::getPosition(window).x < 1140
                &&sf::Mouse::getPosition(window).y > 0
                    &&sf::Mouse::getPosition(window).y < 800)
    {
        command = 15;
    }


}
