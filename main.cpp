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
#include <sys/times.h>
#include <unistd.h>
#include <iomanip>
#include <fstream>
#define lli long long int
#define NUMBER_OF_DAYS 1;
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;
extern double all_the_roads(int number_of_cars, graph * G, counting_average_velocities * average_velocities);
int main(){


    FILE *fule;
    fule = fopen("Barcelona", "r+");
    lli Svertexes[2524];
    lli Tverexes[2524];
    double roadLenght[2524];
    for (int ilk = 0; ilk < 2523; ilk++) {
        int S, T, tr1;
        double len = 678, dtr1, dtr2,  tr2, tr3, tr4, tr5;
        fscanf(fule,"%d %d %d %lf %lf %lf %lf %lf %lf %lf\n", &S, &T, &tr1, &len, &dtr1, &dtr2, &tr2, &tr3, &tr4, &tr5);
        Svertexes[ilk]=S;
        Tverexes[ilk]=T;
        roadLenght[ilk]=len*1000;
    }
    fclose(fule);
    int number_of_days = NUMBER_OF_DAYS;
    double average_times[number_of_days];

    Svertexes[2523] = 0;
    Tverexes[2523]  = 1;


    long long int number_of_edges = 2524;
//    long long int ListS[25] = {0,0,1,1,6,6,6,9,6,8,5,2,2,5,4,4,3,3,5,11, 13,13,11,9,9};
//    long long int ListT[25] = {1,2,6,2,7,5,9,8,8,5,8,5,3,3,3,12,12,11,11,8,11,12,12,13,10};
//    double length[25] = {100, 200, 300, 100,1000, 180,400,800,650, 700, 1500, 687,688, 3000, 500, 670, 400, 2000, 1000, 678, 805, 767, 3456, 5678, 4566};
    graph G(Svertexes, Tverexes, roadLenght, number_of_edges);
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
    int number_of_cars;
    int real_number_of_cars;
    printf("print number_of_cars:");
    scanf("%d", &number_of_cars);
    real_number_of_cars = number_of_cars;

    struct tms *start_times = (struct tms *) malloc(sizeof(struct tms));
    struct tms *finish_times = (struct tms *) malloc(sizeof(struct tms));
    struct result_times{
        double real;
        double user;
        double sys;
    };
    clock_t start = times(start_times);
    car * array_of_cars[number_of_cars];
    for(int j = 0; j < number_of_cars; j++){
        int start = possible_start_points[round(double((rand() * (number_of_possible_start_points - 1)))/RAND_MAX)];
        int finish = round(double(rand() * (G.roadID_recerved))/RAND_MAX);
        printf("%d %d\n", start, finish);
        array_of_cars[j] = new car(j, 0, 0, 0, 0, 0, 0, 0, 0, 0, start, finish);
    }

    for(int j = 0; j < number_of_days; j++){
        real_number_of_cars = number_of_cars;
        cout << j << "\n";
        for(int k = 0; k < number_of_cars; k++){
            vector<long long int> way = G.findWay(array_of_cars[k]->get_start(), array_of_cars[k]->get_finish(), average_velocities);
            if(way.empty() == 0 && G.getEdge(way[way.size() - 1]).second == G.getEdge(array_of_cars[k]->get_finish()).second) {
                array_of_cars[k]->set_route(way);
                (G.getRoadptr(array_of_cars[k]->get_start())->get_cars_on_the_road())->push_back(array_of_cars[k]);
                array_of_cars[k]->set_position_on_the_current_road(
                        -7.5 * ((G.getRoadptr(array_of_cars[k]->get_start())->get_cars_on_the_road())->size() - 1));
                array_of_cars[k]->set_reached_distination(0);
                array_of_cars[k]->set_current_road_number_in_the_route(0);
                array_of_cars[k]->set_changed_current_road_number_in_the_route(0);
                array_of_cars[k]->set_acceleration(0);
                array_of_cars[k]->set_velocity(0);
            }
            else{
               // printf("impossible to rich distinstion %d %d %d\n", k, array_of_cars[k]->get_start(), array_of_cars[k]->get_finish());
                real_number_of_cars--;
            }
        }
        average_times[j] = all_the_roads(real_number_of_cars, &G, average_velocities);
    }
    for(int j = 0; j < number_of_cars; j++){
        delete array_of_cars[j];
    }
    for(int j = 0; j < number_of_days; j++){
        printf("%lf ", average_times[j]);
    }
    clock_t finish = times(finish_times);


    ///Writing into file
    ofstream averTimes;
    averTimes.open ("AverageTimes");
    for(int itr = 0; itr < number_of_days; itr++)
        averTimes << average_times[itr] << ' ';
    averTimes.close();
    ///======

    result_times times;
    times.real = ((double) (finish - start)) / CLOCKS_PER_SEC;
    times.user =
            ((double) (finish_times->tms_utime - start_times->tms_utime)) / sysconf(_SC_CLK_TCK);
    times.sys =
            ((double) (finish_times->tms_stime - start_times->tms_stime)) / sysconf(_SC_CLK_TCK);
    cerr << "real:\n" << fixed << setprecision(6) << times.real << "\n";
    cerr << "user:\n" << times.user << "\n";
    cerr << "sys:\n" << times.sys << "\n";
    free(start_times);
    free(finish_times);
}
