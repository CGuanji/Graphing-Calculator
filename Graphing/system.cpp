#include "system.h"
#include "random.h"

#include <iostream>

#include <constants.h>
System::System()
{
    cout<<"CONSTRUCT SYSTEM!!!"<<endl;
    Random r;
//    draw_graph = sf::RectangleShape(sf::Vector2f(plot.info.window_dimension.x,plot.info.window_dimension.y));


    // plot.info.origin.x = ((abs(plot.info.domain.x)+abs(plot.info.domain.y))/2 - plot.info.domain.x)* plot.info.window_delta.x;
    x_axis=sf::RectangleShape(sf::Vector2f(plot.info.window_dimension.x, 2));
    x_axis.setPosition(sf::Vector2f(0, plot.info.origin.y));
    x_axis.setFillColor(sf::Color::Red);

    y_axis=sf::RectangleShape(sf::Vector2f(2, plot.info.window_dimension.y));
    y_axis.setPosition(sf::Vector2f(plot.info.origin.x, 0));
    y_axis.setFillColor(sf::Color::Red);
    draw_graph = sf::RectangleShape(sf::Vector2f(1200,800));
    draw_graph.setPosition(sf::Vector2f(0, 0));
    draw_graph.setFillColor(sf::Color(222,184,135));

    count = 0;
    ok = false;
   // _equation = "x^2";
    _equation = "x";
    _change = false;
    _update_equation = " ";
    polar = false;

    if (!font.loadFromFile("arial.ttf")){
        cout<<"animate() CTOR: Font failed to load"<<endl;
        cin.get();
        exit(-1);
    }

}


//------------------------------------------------------------------
//------------------------------------------------------------------

void System::Step(int command)
{

    graph.clear();
    if(command == 4)    //shift left
    {
        float un_changed_x = plot.info.domain.x;
        float un_changed_y = plot.info.domain.y;
        float un_changed_range_x = plot.info.range.x;
        float un_changed_range_y = plot.info.range.x;

//        plot.info.domain.x+=0.3;
//        plot.info.domain.y+=0.3;
      //  if(plot.info.domain.y > 0)
        {
            plot.info.domain.x -= (abs(un_changed_x)+abs(un_changed_y))*0.05;
            plot.info.domain.y -= (abs(un_changed_x)+abs(un_changed_y))*0.05;
        }

       // plot.info.origin.x = ((abs(plot.info.domain.x)+abs(plot.info.domain.y))/2 + plot.info.domain.x)* plot.info.window_delta.x;

    }

    if(command == 5)        //shift right
    {

        float un_changed_x = plot.info.domain.x;
        float un_changed_y = plot.info.domain.y;
        float un_changed_range_x = plot.info.range.x;
        float un_changed_range_y = plot.info.range.x;
     //   if(plot.info.domain.x <0)
        {
            plot.info.domain.x += (abs(un_changed_x)+abs(un_changed_y))*0.05;
            plot.info.domain.y += (abs(un_changed_x)+abs(un_changed_y))*0.05;
        }

//        plot.info.domain.x-=0.3;
//        plot.info.domain.y-=0.3;
     //   plot.info.origin.y = ((abs(plot.info.domain.x)+abs(plot.info.domain.y))/2 + plot.info.domain.x)* plot.info.window_delta.x;


    }
    if(command == 6)        //shift up
    {
        float un_changed_x = plot.info.domain.x;
        float un_changed_y = plot.info.domain.y;
        float un_changed_range_x = plot.info.range.x;
        float un_changed_range_y = plot.info.range.x;
       // if(plot.info.range.x > 0)
        plot.info.range.x += (abs(un_changed_range_x)+abs(un_changed_range_y))*0.02;
        plot.info.range.y += (abs(un_changed_range_y)+abs(un_changed_range_x))*0.02;

//        plot.info.range.x+=0.3;
//        plot.info.range.y+=0.3;

//        plot.info.origin.y-=1*plot.info.ratio.y;

    }
    if(command == 7)        //shift down
    {
        float un_changed_x = plot.info.domain.x;
        float un_changed_y = plot.info.domain.y;
        float un_changed_range_x = plot.info.range.x;
        float un_changed_range_y = plot.info.range.x;
       // if(plot.info.range.y > 0)
        {
            plot.info.range.x -= (abs(un_changed_range_x)+abs(un_changed_range_y))*0.02;
            plot.info.range.y -= (abs(un_changed_range_y)+abs(un_changed_range_x))*0.02;
        }

//        plot.info.range.x-=0.3;
//        plot.info.range.y-=0.3;
      //  plot.info.origin.y+=1*plot.info.ratio.y;

    }
    if(command == 8)        //zoom in
    {
        float un_changed_x = plot.info.domain.x;
        float un_changed_y = plot.info.domain.y;
        float un_changed_range_x = plot.info.range.x;
        float un_changed_range_y = plot.info.range.x;

        plot.info.domain.x += (abs(un_changed_x)+abs(un_changed_y))*0.1;
        plot.info.domain.y -= (abs(un_changed_x)+abs(un_changed_y))*0.1;
        plot.info.range.x += (abs(un_changed_range_x)+abs(un_changed_range_y))*0.1;
        plot.info.range.y -= (abs(un_changed_range_x)+abs(un_changed_range_y))*0.1;

    }
    if(command == 9)    //zoom out
    {

        float un_changed_x = plot.info.domain.x;
        float un_changed_y = plot.info.domain.y;
        float un_changed_range_x = plot.info.range.x;
        float un_changed_range_y = plot.info.range.x;

        plot.info.domain.x -= (abs(un_changed_x)+abs(un_changed_y))*0.1;
        plot.info.domain.y += (abs(un_changed_x)+abs(un_changed_y))*0.1;
        plot.info.range.x -= (abs(un_changed_range_x)+abs(un_changed_range_y))*0.1;
        plot.info.range.y += (abs(un_changed_range_x)+abs(un_changed_range_y))*0.1;

    }
  //  cout<<"sum: "<<((abs(plot.info.domain.x)+abs(plot.info.domain.y))/2 /*+ plot.info.domain.x*/)<<endl;
  //  plot.info.origin.y = ((abs(plot.info.domain.x)+abs(plot.info.domain.y))/2 + plot.info.domain.x)* plot.info.window_delta.x;
    if(command == 10)
    {

//            _equation = "x^3";
           cout<<"_equation: "<<_equation<<endl;
            if(_change == true)
            {
                cout<<"_equation inside: "<<_equation<<endl;

                plot.change_equation(_equation);
                command = 0;
            }
            _change = false;


    }
    if(command == 11) //show
    {
        if(count == 0)
        {
            count++;
            ok = true;
        }
        else
        {
            count = 0;
            ok = false;
        }

        cout<<"count: "<<count<<endl;

            function_bar=sf::RectangleShape(sf::Vector2f(400, 100));

            function_bar.setPosition(sf::Vector2f(100, 100));
            function_bar.setFillColor(sf::Color::White);


    }
    //polar
    if(command == 13)
    {
        cout<<"polar: "<<endl;
        if(polar == true)
        {
            polar = false;
        }
        else
        {
            polar = true;
        }
        command = 0;
    }
    //drag
//    if(command == 15)
//    {

//    }



}
float System::round(float x)
{
    return floor(x+0.05f);
}
string System::see_domain()
{
    string rtv;
    std::ostringstream os;
    std::ostringstream oz;

    float x = round(plot.info.domain.x*100.0)/100.0;
    os<<x;
    float y = round(plot.info.domain.y*100.0)/100.0;
    oz<<y;
    string a = " do.min: "+os.str();
    string b = " do.max: "+oz.str();


    rtv = a+b;

    return rtv;
}
string System::see_range()
{
    string rtv;
    std::ostringstream os;
    std::ostringstream oz;
    double x = round(plot.info.range.x*100.0)/100.0;
    double y = round(plot.info.range.y*100.0)/100.0;
    os<<x;
    oz<<y;
    string a = " r.min: "+os.str()+"   ";
    string b = " r.max: "+oz.str();
    rtv = a+b;

    return rtv;
}
void System::reset_domain_range()
{
    plot.info.domain.x = -10;
    plot.info.domain.y = 10;
    plot.info.range.x = -10;
    plot.info.range.y = 10;

}

void System::Pass_Equation(string equation)
{
    _equation = equation;
    reset_domain_range();

}


void System::draw_new(bool change)
{
    _change = change;
}

string System:: get_string()
{
    return _equation;
}
void System::pass_update_equation(string update_equation)
{
    _update_equation = update_equation;
}
bool System:: is_ok(bool k)
{
    ok = k;
}

void System::Draw(sf::RenderWindow& window)
{


    cout<<"domain.x : "<<plot.info.domain.x<<endl;
    cout<<"domain.y : "<<plot.info.domain.y<<endl;
    plot.info.window_delta.x = plot.info.window_dimension.x/(abs(plot.info.domain.x)+abs(plot.info.domain.y));
    plot.info.window_delta.y = plot.info.window_dimension.y/(abs(plot.info.range.x)+abs(plot.info.range.y));
 //   if(plot.info.domain.y <=20 /*&& plot.info.domain.y >0*/)
    {
        plot.info.origin.x = abs(plot.info.domain.x) * plot.info.window_delta.x;
        plot.info.origin.y = abs(plot.info.range.y) * plot.info.window_delta.y;

      //  plot.info.origin.y = abs(plot.info.range.y) * plot.info.window_delta.y;
//        plot.info.origin.x = ((plot.info.domain.x+plot.info.domain.y)) * plot.info.window_delta.x;
//        plot.info.origin.y = ((plot.info.range.x+plot.info.range.y)+10) * plot.info.window_delta.y;

    }
//    else if(plot.info.domain.y > 20)
//   {
//        plot.info.origin.x = -(plot.info.domain.x) * plot.info.window_delta.x;
// //       plot.info.origin.y = abs(plot.info.range.y) * plot.info.window_delta.y;
////        plot.info.origin.x = -(plot.info.domain.x) * plot.info.window_delta.x;
////        plot.info.origin.y = -(plot.info.range.y) * plot.info.window_delta.y;

//   }
//    if(plot.info.domain.x < 0 &&plot.info.domain.y < 0/*&& plot.info.domain.y >0*/)
//    {
//        plot.info.origin.x = (plot.info.domain.x) * plot.info.window_delta.x;

////        plot.info.origin.x = abs(plot.info.domain.x) * plot.info.window_delta.x;
////      //  plot.info.origin.y = abs(plot.info.range.y) * plot.info.window_delta.y;
//////        plot.info.origin.x = ((plot.info.domain.x+plot.info.domain.y)) * plot.info.window_delta.x;
//////        plot.info.origin.y = ((plot.info.range.x+plot.info.range.y)+10) * plot.info.window_delta.y;

//    }


//    if(plot.info.range.y <=20)
//    {
//        plot.info.origin.y = abs(plot.info.range.y) * plot.info.window_delta.y;

//    }
//    else if(plot.info.range.y>20)
//    {
//         plot.info.origin.y = -(plot.info.range.y) * plot.info.window_delta.y;
//    }


//    cout<<"delta x: "<<plot.info.window_delta.x<<endl;
//    cout<<"origin.x "<<plot.info.origin.x<<endl;
//    cout<<"origin.y "<<plot.info.origin.y<<endl;




//    plot.info.origin.x = ((abs(plot.info.domain.x)+abs(plot.info.domain.y))/2 + plot.info.domain.x+abs(plot.info.domain.x))* plot.info.window_delta.x;
//    plot.info.origin.y = ((abs(plot.info.range.x)+abs(plot.info.range.y))/2 + plot.info.range.x+abs(plot.info.range.x))* plot.info.window_delta.y;
//    cout<<plot.info.origin.x<<endl;
//    cout<<plot.info.origin.y<<endl;


    x_axis=sf::RectangleShape(sf::Vector2f(plot.info.window_dimension.x, 2));
    x_axis.setPosition(sf::Vector2f(0, plot.info.origin.y));
    x_axis.setFillColor(sf::Color::Red);

    y_axis=sf::RectangleShape(sf::Vector2f(2, plot.info.window_dimension.y));
    y_axis.setPosition(sf::Vector2f(plot.info.origin.x, 0));
    y_axis.setFillColor(sf::Color::Red);

    myTextLabel.setFont(font);

    if(_update_equation!="")
    {
        myTextLabel.setString(_update_equation);

    }
    else if (ok)
    {
        myTextLabel.setString(_equation);
    }
    else
    {
        myTextLabel.setString(_equation);
    }
    myTextLabel.setCharacterSize(40);
    myTextLabel.setFillColor(sf::Color::Red);
    myTextLabel.setPosition(100,100);



    pop_v.clear();
    plot.coordinate(polar).clear();
    pop_v = plot.coordinate(polar);
//    cout<<"capacity: "<<pop_v.capacity()<<endl;
    int i = 0;
    //int change_val = 2*info.ratio.x;


    while (i < pop_v.capacity())
    {
        a.x = pop_v[i].x;
        a.y = pop_v[i].y;
//        cout<<"a.x: " <<a.x<<endl;
//        cout<<"a.y: "<<a.y<<endl;
        i++;
        push_val = sf::CircleShape(2);
        push_val.setPosition(sf::Vector2f(a.x,a.y));

        push_val.setFillColor(sf::Color(220,20,60));
        graph.push_back(push_val);

    }

    size_of_draw = pop_v.capacity();
    pop_v.clear();


    window.draw(shape);

    window.draw(draw_graph);
    window.draw(x_axis);
    window.draw(y_axis);

    if(count == 1)
    {
        window.draw(function_bar);

        window.draw(myTextLabel);
    }

    for (int i = 0;i < size_of_draw;i++)
    {
        window.draw(graph[i]);
    }
    graph.clear();


}
