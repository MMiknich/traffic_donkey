//
// Created by mmiknich on 09.05.19.
//

#ifndef TRAFFIC_DONKEY_ROAD_H
#define TRAFFIC_DONKEY_ROAD_H

#include <Car.h>


class road {
    int road_id;
    double length;
    car * first_car;
    car * last_car;
    bool priority;
    int relative_road_id_1;
    int relative_road_id_2;
public:
    road();
    road(int road_id, double length, car * first_car, car * last_car, bool priority, int relative_road_id_1, int relative_road_id_2):
            road_id(road_id), length(length), first_car(first_car), last_car(last_car), priority(priority), relative_road_id_1(relative_road_id_1), relative_road_id_2(relative_road_id_2){}
    void set_road_id(int road_id);
    void set_length(double length);
    void set_first_car(car * first_car);
    void set_last_car(car * last_car);
    void set_priority(bool priority);
    void set_relative_road_id_1(int relative_road_id_1);
    void set_relative_road_id_2(int relative_road_id_2);
    int get_road_id();
    double get_length();
    car * get_first_car();
    car * get_last_car();
    bool get_priority();
    int get_relative_road_id_1();
    int get_relative_road_id_2();
    ~road(){};
};


#endif //TRAFFIC_DONKEY_ROAD_H
