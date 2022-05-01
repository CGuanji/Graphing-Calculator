#include "graph_info.h"

graph_info::graph_info()
{
    domain.x = -10;
    domain.y = 10;
    window_dimension.x = 1120;
    window_dimension.y = 800;
    origin.x = 560;
    origin.y = 400;
    delta.x = 1;
    delta.y = 1;
    window_delta.x = 1120/(20);
    window_delta.y = 800/(20);
    range.x = -10;
    range.y = 10;
    points = 1000;
    points_delta = 1.0/300;

//    cout<<"domain inside: "<<domain.x<<endl;
//    cout<<"domain inside: "<<domain.y<<endl;

    ratio.x = window_delta.x / delta.x;
    ratio.y = window_delta.y / delta.y;


}

