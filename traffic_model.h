//
// Created by maria_soroka on 09.05.19.
//

#ifndef TRAFFIC_DONKEY_TRAFFIC_MODEL_H
#define TRAFFIC_DONKEY_TRAFFIC_MODEL_H
class car{
    int
};
class road{
    int road_id;
    double length;
    car * first_car;
    car * last_car
    bool priority;
    int relative_roads_id[2];
public:
    road(){
        road_id = -1;
        length = 0;
        first_car = NULL;
        last_car = NULL;
        priority = 0;
        relative_roads_id = {-1, -1};
    }
    road(int road_id, double length, car * first_car, car * last_car, bool priority, int relative_road_id_1, int relative_road_id_2):
    road_id(road_id), length(length), first_car(first_car), last_car(last_car), priority(priority), relative_roads_id[1](relative_roads_id_1), relative_roads_id[2](relative_roads_id_2){}
    void set_road_id(int road_id){};
    void set_length(double length){};
    void set_first_car(car * first_car);
    void set_last_car(car * last_car);
    void set_priority(bool priority);
    void set_relative_roads_id(int relative_road_id_1, inr relative_road_id_2){};
    int get_road_id(){};
    double get_road_length(){};
    car * get_first_car(){};
    car * get_last_car(){};
    bool get_priority(){};
    int * get_relative_roads_id(){};
    ~road(){};
};

#endif //TRAFFIC_DONKEY_TRAFFIC_MODEL_H
