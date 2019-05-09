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
void car::set_car_id(int car_id){
    this->car_id = car_id;
}
void car::set_position_on_the_current_road(double position_on_the_current_road){
    this->position_on_the_current_road = position_on_the_current_road;
}
void car::set_route(vector<int> route){
    this->route = route;
}
void car::set_current_road_number_in_the_route(int current_road_number_in_the_route){
    this->current_road_number_in_the_route = current_road_number_in_the_route;
}
void car::set_acceleration(double acceleration){
    this->acceleration = acceleration;
}
void car::set_velocity(double velocity){
    this->velocity = velocity;
}
int car::get_car_id(){
    return this->car_id;
}
double car::get_position_on_the_current_road(){
    return this->position_on_the_current_road;
}
vector<int> car::get_route(){
    return this->route;
}
int car::get_current_road_number_in_the_route(){
    return this->current_road_number_in_the_route;
}
double car::get_acceleration(){
    return this->acceleration;
}
double car::get_velocity(){
    return this->velocity;
}