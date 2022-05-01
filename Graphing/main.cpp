#include <iostream>
#include "animate.h"
#include "plot.h"
using namespace std;

int main()
{
    Plot t;
    animate game;
    game.run();
    cout<<endl<<endl<<"------ MAIN EXITING --------------------------"<<endl;
    return 0;
}

