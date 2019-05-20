//
// Created by mmiknich on 09.05.19.
//

#ifndef TRAFFIC_DONKEY_ROAD_H
#define TRAFFIC_DONKEY_ROAD_H

#pragma once
#include "car.h"
#include <list>
using namespace std;

class road {
    int road_id;
    double length;
    std::list<car*> cars_on_the_road;
    bool priority;
    int relative_road_id_1;
    int relative_road_id_2;
    double velocity_restrictions;
public:
    road();
    road(int road_id, double length, list<car*> cars_on_the_road, bool priority, int relative_road_id_1, int relative_road_id_2, double velocity_restrictions):
            road_id(road_id), length(length), cars_on_the_road(cars_on_the_road), priority(priority), relative_road_id_1(relative_road_id_1), relative_road_id_2(relative_road_id_2), velocity_restrictions(velocity_restrictions){}
    void set_road_id(int road_id);
    void set_length(double length);
    void set_cars_on_the_road(list<car*> cars_on_the_road);
    void set_priority(bool priority);
    void set_relative_road_id_1(int relative_road_id_1);
    void set_relative_road_id_2(int relative_road_id_2);
    void set_velocity_restrictions(double velocity_restrictions);
    int get_road_id();
    double get_length();
    list<car*> *get_cars_on_the_road();
    bool get_priority();
    int get_relative_road_id_1();
    int get_relative_road_id_2();
    double get_velocity_restrictions();
    ~road(){};
};


#endif //TRAFFIC_DONKEY_ROAD_H
