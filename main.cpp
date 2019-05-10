//
// Created by mmiknich on 09.05.19.
//
#include <iostream>
#include "road.h"

int main()
{
    car x;
    vector<int> route;
    route.push_back(5);
    route.push_back(8);
    x.set_route(route);
    cout << x.get_route()[0];
}