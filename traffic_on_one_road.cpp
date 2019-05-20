//
// Created by maria_soroka on 09.05.19.
//
#include "car.h"
#include "road.h"
#include <list>
#include <iostream>
#include<sys/times.h>
#include <unistd.h>
#include <iomanip>
using namespace::std;

//void traffic_on_one_road() {
//    int N = 4;
//    double road_length = 5.7;
//    double delta_t = 0.1;            ;
//    double a = 2.0;
//    double b = 2.0;
//    double d = 7.5;
//    double T = 1;
//    double v = 16.67;
//    double vel_current;
//    double position_current;
//    double vel_forward;
//    double position_forward;
//    double changed_acceleration;
//    double changed_velocity;
//    double changed_position;
//    FILE * file;
//    file = fopen("out.txt", "w+");
//    list<car> cars_on_the_road;
//    vector<int> route;
//    cars_on_the_road.insert(cars_on_the_road.end(), car(0, 1000, route, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0));
//    for(int i = 1; i < N; i++){
//        cars_on_the_road.insert(cars_on_the_road.end(), car(i, -100 * i, route, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0));
//    }
//    struct tms *start_times = (struct tms *) malloc(sizeof(struct tms));
//    struct tms *finish_times = (struct tms *) malloc(sizeof(struct tms));
//    struct result_times{
//        double real;
//        double user;
//        double sys;
//    };
//    clock_t start = times(start_times);
//    for(int j = 0; j < 3600; j++){
//        auto it = cars_on_the_road.begin();
//        it++;
//        for(it; it != cars_on_the_road.end(); it++){
//          //  printf("%lf %lf %lf\n", it->get_position_on_the_current_road(), it->get_velocity(), it->get_acceleration());
//
//            auto it_forward = it;
//            advance(it_forward, -1);
//            vel_current = it->get_velocity();
//            vel_forward = (it_forward)->get_velocity();
//            position_current = it->get_position_on_the_current_road();
//            position_forward = (it_forward)->get_position_on_the_current_road();
////            printf("%lf %lf %lf %lf\n", vel_current, vel_forward, position_current, position_forward);
//            changed_acceleration = a*(1 - vel_current/v - (d + (T - ((vel_forward - vel_current)/2 * a))*vel_current)/(position_forward - position_current));
//            it->set_changed_acceleration(changed_acceleration);
//            changed_velocity = vel_current + delta_t * it->get_acceleration();
//            changed_position = position_current + delta_t * vel_current + delta_t * delta_t * it->get_acceleration() / 2;
//            it->set_changed_velocity(changed_velocity);
//            it->set_changed_position_on_the_current_road(changed_position);
//            printf("%lf %lf %lf\n", changed_position, changed_velocity, changed_acceleration);
//            fprintf(file, "%lf ", changed_position);
//        }
//        for(it = ++cars_on_the_road.begin(); it != cars_on_the_road.end(); it++){
//            it->update_car();
//            printf("%lf %lf %lf\n", it->get_changed_position_on_the_current_road(), it->get_velocity(), it->get_acceleration());
//        }
//        fprintf(file, "\n");
//        printf("\n");
//    }
//    clock_t finish = times(finish_times);
//    result_times times;
//    times.real = ((double) (finish - start)) / CLOCKS_PER_SEC;
//    times.user =
//            ((double) (finish_times->tms_utime - start_times->tms_utime)) / sysconf(_SC_CLK_TCK);
//    times.sys =
//            ((double) (finish_times->tms_stime - start_times->tms_stime)) / sysconf(_SC_CLK_TCK);
//    cout<< "real:\n" << fixed << setprecision(6) << times.real << "\n";
//    cout << "user:\n" << times.user << "\n";
//    cout << "sys:\n" << times.sys << "\n";
//    free(start_times);
//    free(finish_times);
//
//    //fclose(file);
//}