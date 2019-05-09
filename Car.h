//
// Created by mmiknich on 09.05.19.
//

#ifndef TRAFFIC_DONKEY_CAR_H
#define TRAFFIC_DONKEY_CAR_H

#include <vector>

using namespace::std;

    class car{
        int car_id; // car individual number
        double position_on_the_current_road;
        vector<int> route;
        int current_road_number_in_the_route;
        double acceleration;
        double velocity;
    public:
        car();
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

#endif //TRAFFIC_DONKEY_CAR_H
