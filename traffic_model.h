//
// Created by maria_soroka on 09.05.19.
//
#include <vector>
using namespace::std;
#ifndef TRAFFIC_DONKEY_TRAFFIC_MODEL_H
#define TRAFFIC_DONKEY_TRAFFIC_MODEL_H
class car{
    int car_id;
    double position_on_the_current_road;
    vector<int> route;
    int current_road_number_in_the_route;
    double acceleration;
    double velocity;
public:
    car(){
        car_id = -1;
        position_on_the_current_road = 0;
        current_road_number_in_the_route = -1;
        acceleration = 0;
        velocity = 0;
    }
    car(int car_id, double position_on_the_current_road, vector<int> route, int current_road_number_in_the_route, double acceleration, double velocity):
    car_id(car_id), position_on_the_current_road(position_on_the_current_road), route(route), current_road_number_in_the_route(current_road_number_in_the_route), acceleration(acceleration), velocity(velocity){};
    void set_car_id(int car_id);
    void set_position_on_the_current_road(double position_on_the_current_road);
    void set_route(vector<int> route);
    void set_current_road_number_in_the_route(int current_road_id);
    void set_acceleration(double acceleration);
    void set_velocity(double velocity);
    int get_car_id();
    double get_position_on_the_current_road();
    vector<int> get_route();
    int get_current_road_number_in_the_route();
    double get_acceleration();
    double get_velocity();
};
class road{
    int road_id;
    double length;
    car * first_car;
    car * last_car;
    bool priority;
    int relative_road_id_1;
    int relative_road_id_2;
public:
    road(){
        road_id = -1;
        length = 0;
        first_car = NULL;
        last_car = NULL;
        priority = 0;
        relative_road_id_1 = -1;
        relative_road_id_2 = -1;
    }
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
    double get_road_length();
    car * get_first_car();
    car * get_last_car();
    bool get_priority();
    int * get_relative_roads_id();
    ~road();
};

#endif //TRAFFIC_DONKEY_TRAFFIC_MODEL_H
