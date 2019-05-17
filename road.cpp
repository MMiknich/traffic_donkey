//
// Created by mmiknich on 09.05.19.
//
#include "road.h"
road::road() {
        road_id = -1;
        length = 0;
        priority = 0;
        relative_road_id_1 = -1;
        relative_road_id_2 = -1;
        velocity_restrictions = 16.67;
    }
void road::set_road_id(int road_id) {
        this->road_id = road_id;
}
void road::set_length(double length) {
        this->length = length;
}
void road::set_cars_on_the_road(list<car> cars_on_the_road) {
    this->cars_on_the_road = cars_on_the_road;
}
void road::set_priority(bool priority) {
    this->priority = priority;
}
void road::set_relative_road_id_1(int relative_road_id_1) {
    this->relative_road_id_1 = relative_road_id_1;
}
void road::set_relative_road_id_2(int relative_road_id_2) {
    this->relative_road_id_2 = relative_road_id_2;
}
void road::set_velocity_restrictions(double velocity_restrictions) {
    this->velocity_restrictions = velocity_restrictions;
}
int road::get_road_id() {
    return this->road_id;
}
double road::get_length() {
    return this->length;
}
list<car> road::get_cars_on_the_road() {
    return this-> cars_on_the_road;
}
bool road::get_priority() {
    return this->priority;
}
int road::get_relative_road_id_1() {
    return this->relative_road_id_1;
}
int road::get_relative_road_id_2() {
    return this->relative_road_id_2;
}
double road::get_velocity_restrictions() {
    return this->velocity_restrictions;
}