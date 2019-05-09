//
// Created by mmiknich on 09.05.19.
//
#include <stdio.h>
#include "road.h"
road::road() {
        road_id = -1;
        length = 0;
        first_car = NULL;
        last_car = NULL;
        priority = 0;
        relative_road_id_1 = -1;
        relative_road_id_2 = -1;
    }
void road::set_road_id(int road_id) {
        this->road_id = road_id;
}
void road::set_length(double length) {
        this->length = length;
}
void road::set_first_car(car *first_car) {
    this->first_car = first_car;
}
void road::set_last_car(car *last_car) {
    this->last_car = last_car;
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
int road::get_road_id() {
    return this->road_id;
}
double road::get_length() {
    return this->length;
}
car * road::get_first_car() {
    return this->first_car;
}
car * road::get_last_car() {
    return this->last_car;
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