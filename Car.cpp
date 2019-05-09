//
// Created by mmiknich on 09.05.19.
//

#include "Car.h"

car::car(){ car_id = -1;
    position_on_the_current_road = 0;
    vector<int> route;
    current_road_number_in_the_route = -1;
    acceleration = 0;
    velocity = 0;
}
