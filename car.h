//
// Created by mmiknich on 09.05.19.
//

#pragma once
#include <vector>
using namespace::std;

    class car{
        int car_id; // car individual number
        double position_on_the_current_road;
        vector<pair<int, double>> route;
        int current_road_number_in_the_route;
        double acceleration;
        double velocity;
        int changed_current_road_number_in_the_route;
        double changed_position_on_the_current_road;
        double changed_velocity;
        double changed_acceleration;
        bool reached_destination;
        int start;
        int finish;
    public:
        car();
        car(int car_id, double position_on_the_current_road, vector<pair<int, double>> route, int current_road_number_in_the_route, double acceleration, double velocity,
            double changed_position_on_the_current_road, int changed_current_road_number_in_the_route, double changed_acceleration, double changed_velocity, bool reached_destination, int start, int finish):
                car_id(car_id), position_on_the_current_road(position_on_the_current_road), route(route), current_road_number_in_the_route(current_road_number_in_the_route),
                acceleration(acceleration), velocity(velocity), changed_position_on_the_current_road(changed_position_on_the_current_road),
                        changed_current_road_number_in_the_route(changed_current_road_number_in_the_route), changed_acceleration(changed_acceleration), changed_velocity(changed_velocity), reached_destination(reached_destination),
                        start(start), finish(finish){};
        void set_car_id(int car_id);
        void set_position_on_the_current_road(double position_on_the_current_road);
        void set_route(vector<pair<int, double>> route);
        void set_current_road_number_in_the_route(int current_road_number_in_the_route);
        void set_acceleration(double acceleration);
        void set_velocity(double velocity);
        void set_changed_acceleration(double acceleration);
        void set_changed_velocity(double velocity);
        void set_changed_position_on_the_current_road(double position_on_the_current_road);
        void set_changed_current_road_number_in_the_route(int current_road_number_in_the_route);
        void set_start(int start);
        void set_finish(int finish);
        void set_reached_distination(bool reached_distination);


        int get_car_id();
        double get_position_on_the_current_road();
        vector<pair<int, double>> *get_route();
        int get_current_road_number_in_the_route();
        double get_acceleration();
        double get_velocity();
        double get_changed_acceleration();
        double get_changed_velocity();
        double get_changed_position_on_the_current_road();
        int get_changed_current_road_number_in_the_route();
        int get_start();
        int get_finish();
        bool get_reached_distination();

        void update_car();
        //car& operator=(car &example);
        ~car(){};
    };
