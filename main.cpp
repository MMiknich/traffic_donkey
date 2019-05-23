//
// Created by mmiknich on 09.05.19.
//
//#include <python2.7/Python.h>
#include <iostream>
#include <cassert>
#include "graph.h"
#include "car.h"
#include "road.h"
#include <string>
#include <stdlib.h>
#include <random>
#define lli long long int
//#define CRITICAL_DISTANCE 0.3
//#define CRITICAL_TIME_TO_MAKE_A_TURN 5.0;
#define NUMBER_OF_DAYS 1;
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;
extern int all_the_roads(int number_of_cars, graph * G, counting_average_velocities * average_velocities);
int main(){
    int number_of_days = NUMBER_OF_DAYS;
    double average_times[number_of_days];
    long long int number_of_edges = 4;
    long long int ListS[4] = {1, 2, 4, 2};
    long long int ListT[4] = {2, 3, 2, 5};
    double length[4] = {100, 200, 300, 100};


    graph G(ListS, ListT, length, number_of_edges);
    G.normalize();
    counting_average_velocities average_velocities[G.roadID_recerved + 1];
    vector<long long int> possible_start_points = G.possibleHomes();
    unsigned long long int number_of_possible_start_points = possible_start_points.size();
    for(int i = 0; i <= G.roadID_recerved; i++){
        average_velocities[i].sum = 0;
        average_velocities[i].number_of_counts = 0;
        //average_velocities[i].average_speed = G.getRoadptr(i)->get_velocity_restrictions();
        average_velocities[i].average_speed = 16.67;
    }
//    G.getRoadptr(G.getRoadID(1, 6))->set_relative_road_id_1(G.getRoadID(2, 6));
//    vector<int> route_t;
//    route_t.push_back(G.getRoadID(1, 6));
//    route_t.push_back(G.getRoadID(6, 7));
//    route_t.push_back(G.getRoadID(7, 8));
//    route_t.push_back(G.getRoadID(8, 4));
//    car *one_car= new car(1, 0, route_t, 0,0,0,0,0,0,0,0, 0, 0);
//    (G.getRoadptr(G.getRoadID(1, 6))->get_cars_on_the_road())->push_back(one_car);

    int number_of_cars;
    scanf("%d", &number_of_cars);
    car * array_of_cars[number_of_cars];
    for(int j = 0; j < number_of_cars; j++){
        int start = possible_start_points[round(double((rand() * (number_of_possible_start_points - 1)))/RAND_MAX)];
        int finish = round(double(rand() * (G.roadID_recerved))/RAND_MAX);
        printf("%d %d\n", start, finish);
        array_of_cars[j] = new car(j, 0, 0, 0, 0, 0, 0, 0, 0, 0, start, finish);
    }

    for(int j = 0; j < number_of_days; j++){
        for(int k = 0; k < number_of_cars; k++){
            vector<long long int> way = G.findWay(array_of_cars[k]->get_start(), array_of_cars[k]->get_finish(), average_velocities);
            if(way.empty() == 0) {
                array_of_cars[k]->set_route(way);
                (G.getRoadptr(array_of_cars[k]->get_start())->get_cars_on_the_road())->push_back(array_of_cars[k]);
                array_of_cars[k]->set_position_on_the_current_road(
                        -7.5 * ((G.getRoadptr(array_of_cars[k]->get_start())->get_cars_on_the_road())->size() - 1));
            }
            else{
                printf("impossible to rich distinstion %d %d %d\n", k, array_of_cars[k]->get_start(), array_of_cars[k]->get_finish());
            }
        }
        average_times[j] = all_the_roads(number_of_cars, &G, average_velocities);
    }
    for(int j = 0; j < number_of_cars; j++){
        delete array_of_cars[j];
    }
    for(int j = 0; j < number_of_days; j++){
        printf("%lf ", average_times[j]);
    }
}
