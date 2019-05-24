//
// Created by mmiknich on 09.05.19.
//
#include <iostream>
#include <cassert>
#include "graph.h"
#include "car.h"
#include "road.h"
#define lli long long int
#define CRITICAL_DISTANCE 0.5
double all_the_roads(int number_of_cars, graph * G, counting_average_velocities * average_velocities)
{
    int number_of_cars_reached_destination = 0;
    double delta_t = 0.1;
    double a = 2.0;
    double b = 2.0;
    double d = 7.5;
    double T = 1;
    double v;
    long long int number_of_updates = 0;
    double total_time = 0;
    double average_time = 0;
    double sum_time = 0;
    double vel_current;
    double position_current;
    double vel_forward;
    double position_forward;
    double changed_acceleration;
    double changed_velocity;
    double changed_position;
    double temp_value;
    road *r;
    road *next_r;
    int Iretator=0;
    cout<<"loading:\n";
    while(number_of_cars_reached_destination != number_of_cars) {
        Iretator++;
        cout <<Iretator<<"*\n";
        total_time += delta_t;
        number_of_updates++;
        for(long long int edges_iterator = 0; edges_iterator <= G->roadID_recerved; edges_iterator++) {
            r = G->getRoadptr(edges_iterator);
            //r->set_velocity_restrictions(16.67);
            //v = r.get_velocity_restrictions();
            v = 16.67;
            if(r->get_cars_on_the_road()->empty() == 0) {
                car *head_car = ((r->get_cars_on_the_road())->front());
                if(head_car->get_current_road_number_in_the_route() == head_car->get_route()->size() - 1) { //if this road is the last one in the route
                    vel_current = head_car->get_velocity();
                    position_current = head_car->get_position_on_the_current_road();
                    vel_forward = 0;
                    position_forward = r->get_length() + d - 0.5;
                    temp_value = (d +
                                  (T - ((vel_forward - vel_current) / (2 * a))) * vel_current) /
                                 (position_forward - position_current);
                    changed_acceleration = a * (1 - vel_current / v - temp_value * temp_value);
                    head_car->set_changed_acceleration(changed_acceleration);
                    changed_velocity = vel_current + delta_t * head_car->get_acceleration();
                    changed_position =
                            position_current + delta_t * vel_current +
                            delta_t * delta_t * head_car->get_acceleration() / 2;
                    head_car->set_changed_velocity(changed_velocity);
                    head_car->set_changed_position_on_the_current_road(changed_position);
                    if(changed_position + CRITICAL_DISTANCE >= r->get_length()) {
                        number_of_cars_reached_destination++;
                        head_car->set_reached_distination(1);
                    }
                }
                else if(r->get_priority() == 0 &&    //this road is NOT the last one, current road priority is 0 and priority of the next road is also 0
                        head_car->get_current_road_number_in_the_route() != head_car->get_route()->size() - 1 &&
                        (G->getRoadptr(((*head_car->get_route())[head_car->get_current_road_number_in_the_route() +
                                                                1])))->get_priority() == 0) {
                    vel_current = head_car->get_velocity();
                    position_current = head_car->get_position_on_the_current_road();
                    next_r = G->getRoadptr((*head_car->get_route())[head_car->get_current_road_number_in_the_route() + 1]);
                    if(next_r->get_cars_on_the_road()->empty() == 0) {
                        vel_forward = (*next_r->get_cars_on_the_road()->back()).get_velocity();
                        position_forward = (*next_r->get_cars_on_the_road()->back()).get_position_on_the_current_road();
                    }
                    else {
                        vel_forward = 33;
                        position_forward = 500;
                    }
                    temp_value = (d +
                                  (T - ((vel_forward - vel_current) / 2 * a)) * vel_current) /
                                 (position_forward + r->get_length() - position_current);
                    changed_acceleration = a * (1 - vel_current / v - temp_value * temp_value);
                    head_car->set_changed_acceleration(changed_acceleration);
                    changed_velocity = vel_current + delta_t * head_car->get_acceleration();
                    changed_position =
                            position_current + delta_t * vel_current +
                            delta_t * delta_t * head_car->get_acceleration() / 2;
                    head_car->set_changed_velocity(changed_velocity);
                    head_car->set_changed_position_on_the_current_road(changed_position);
                    printf("changed %lf %lf %lf\n", head_car->get_changed_position_on_the_current_road(),
                           head_car->get_changed_velocity(), head_car->get_changed_acceleration());
                    if(changed_position + CRITICAL_DISTANCE >= r->get_length()) {
                        head_car->set_changed_current_road_number_in_the_route(
                                head_car->get_current_road_number_in_the_route() + 1);
                        head_car->set_changed_position_on_the_current_road(
                                head_car->get_changed_position_on_the_current_road() - r->get_length());
                    }
                }
                else if(r->get_priority() == 0 && head_car->get_current_road_number_in_the_route() != head_car->get_route()->size() - 1 && //if head_car is NOT last road, current road priority is 0 and next road priority is 1
                        (G->getRoadptr((*head_car->get_route())[head_car->get_current_road_number_in_the_route() + 1]))->get_priority() == 1){
                    vel_current = head_car->get_velocity();
                    position_current = head_car->get_position_on_the_current_road();
                    vel_forward = 0;
                    position_forward = r->get_length() + d - 0.5; //before turning to the circle the car should stop
                    temp_value = (d +
                                  (T - ((vel_forward - vel_current) / (2 * a))) * vel_current) /
                                 (position_forward - position_current);
                    changed_acceleration = a * (1 - vel_current / v - temp_value * temp_value);
                    head_car->set_changed_acceleration(changed_acceleration);
                    changed_velocity = vel_current + delta_t * head_car->get_acceleration();
                    changed_position =
                            position_current + delta_t * vel_current +
                            delta_t * delta_t * head_car->get_acceleration() / 2;
                    head_car->set_changed_velocity(changed_velocity);
                    head_car->set_changed_position_on_the_current_road(changed_position);
                    if(changed_position + CRITICAL_DISTANCE >= r->get_length()){
                        if(G->getRoadptr(r->get_relative_road_id_1())->get_cars_on_the_road()->empty() == 0) {
                            car *car_to_wait = G->getRoadptr(r->get_relative_road_id_1())->get_cars_on_the_road()->front();
                            next_r = G->getRoadptr((*head_car->get_route())[head_car->get_current_road_number_in_the_route() + 1]);
                            double time_for_a_turn = ((G->getRoadptr(r->get_relative_road_id_1()))->get_length() -
                                                      car_to_wait->get_position_on_the_current_road() )/ car_to_wait->get_velocity();
                            if(next_r->get_cars_on_the_road()->empty() == 0) {
                                if(5.0 < time_for_a_turn &&
                                   next_r->get_cars_on_the_road()->back()->get_position_on_the_current_road() > 5) {
                                    head_car->set_changed_current_road_number_in_the_route(
                                            head_car->get_current_road_number_in_the_route() + 1);
                                    head_car->set_changed_position_on_the_current_road(
                                            head_car->get_changed_position_on_the_current_road() - r->get_length());
                                }
                            }
                            else{
                                if(5.0 < time_for_a_turn) {
                                    head_car->set_changed_current_road_number_in_the_route(
                                            head_car->get_current_road_number_in_the_route() + 1);
                                    head_car->set_changed_position_on_the_current_road(
                                            head_car->get_changed_position_on_the_current_road() - r->get_length());
                                }
                            }
                        }
                        else{
                            head_car->set_changed_current_road_number_in_the_route(
                                    head_car->get_current_road_number_in_the_route() + 1);
                            head_car->set_changed_position_on_the_current_road(
                                    head_car->get_changed_position_on_the_current_road() - r->get_length());
                        }
                    }
                }
                else if(r->get_priority() == 1 &&    //this road is NOT the last one, current road priority is 1 and priority of the next road is also 1
                        head_car->get_current_road_number_in_the_route() != head_car->get_route()->size() - 1 &&
                        (G->getRoadptr(((*head_car->get_route())[head_car->get_current_road_number_in_the_route() +
                                                                1])))->get_priority() == 1) {
                    vel_current = head_car->get_velocity();
                    position_current = head_car->get_position_on_the_current_road();
                    next_r = G->getRoadptr((*head_car->get_route())[head_car->get_current_road_number_in_the_route() + 1]);
                    if(next_r->get_cars_on_the_road()->empty() == 0) {
                        vel_forward = (*next_r->get_cars_on_the_road()->back()).get_velocity();
                        position_forward = (*next_r->get_cars_on_the_road()->back()).get_position_on_the_current_road();
                    }
                    else {
                        vel_forward = 33;
                        position_forward = 500;
                    }
                    temp_value = (d +
                                  (T - ((vel_forward - vel_current) / 2 * a)) * vel_current) /
                                 (position_forward + r->get_length() - position_current);
                    changed_acceleration = a * (1 - vel_current / v - temp_value * temp_value);
                    head_car->set_changed_acceleration(changed_acceleration);
                    changed_velocity = vel_current + delta_t * head_car->get_acceleration();
                    changed_position =
                            position_current + delta_t * vel_current +
                            delta_t * delta_t * head_car->get_acceleration() / 2;
                    head_car->set_changed_velocity(changed_velocity);
                    head_car->set_changed_position_on_the_current_road(changed_position);
                    if(changed_position + CRITICAL_DISTANCE >= r->get_length()) {
                        head_car->set_changed_current_road_number_in_the_route(
                                head_car->get_current_road_number_in_the_route() + 1);
                        head_car->set_changed_position_on_the_current_road(
                                head_car->get_changed_position_on_the_current_road() - r->get_length());
                    }
                }
                else if(r->get_priority() == 1 &&    //this road is NOT the last one, current road priority is 1 and priority of the next road is also 1
                        head_car->get_current_road_number_in_the_route() != head_car->get_route()->size() - 1 &&
                        (G->getRoadptr(((*head_car->get_route())[head_car->get_current_road_number_in_the_route() +
                                                                1])))->get_priority() == 0) {
                    vel_current = head_car->get_velocity();
                    position_current = head_car->get_position_on_the_current_road();
                    next_r = G->getRoadptr((*head_car->get_route())[head_car->get_current_road_number_in_the_route() + 1]);
                    if(next_r->get_cars_on_the_road()->empty() == 0) {
                        vel_forward = (*next_r->get_cars_on_the_road()->back()).get_velocity();
                        position_forward = (*next_r->get_cars_on_the_road()->back()).get_position_on_the_current_road();
                    }
                    else {
                        vel_forward = 33;
                        position_forward = 500;
                    }
                    temp_value = (d +
                                  (T - ((vel_forward - vel_current) / 2 * a)) * vel_current) /
                                 (position_forward + r->get_length() - position_current);
                    changed_acceleration = a * (1 - vel_current / v - temp_value * temp_value);
                    head_car->set_changed_acceleration(changed_acceleration);
                    changed_velocity = vel_current + delta_t * head_car->get_acceleration();
                    changed_position =
                            position_current + delta_t * vel_current +
                            delta_t * delta_t * head_car->get_acceleration() / 2;
                    head_car->set_changed_velocity(changed_velocity);
                    head_car->set_changed_position_on_the_current_road(changed_position);
                    if(changed_position + CRITICAL_DISTANCE >= r->get_length()) {
                        head_car->set_changed_current_road_number_in_the_route(
                                head_car->get_current_road_number_in_the_route() + 1);
                        head_car->set_changed_position_on_the_current_road(
                                head_car->get_changed_position_on_the_current_road() - r->get_length());
                    }
                }
                auto it = r->get_cars_on_the_road()->begin();
                if(r->get_cars_on_the_road()->size() > 1) {
                    it++;
                    auto it_forward = it;
                    advance(it_forward, -1);
                    for(it; it != r->get_cars_on_the_road()->end(); it++, it_forward++) {
                        vel_current = (*it)->get_velocity();
                        position_current = (*it)->get_position_on_the_current_road();
                        vel_forward = (*it_forward)->get_velocity();;
                        position_forward = (*it_forward)->get_position_on_the_current_road();
                        temp_value = (d +
                                      (T - ((vel_forward - vel_current) / (2 * a))) * vel_current) /
                                     (position_forward - position_current);
                        changed_acceleration = a * (1 - vel_current / v - temp_value * temp_value);
                        (*it)->set_changed_acceleration(changed_acceleration);
                        changed_velocity = vel_current + delta_t * head_car->get_acceleration();
                        changed_position =
                                position_current + delta_t * vel_current +
                                delta_t * delta_t * head_car->get_acceleration() / 2;
                        (*it)->set_changed_velocity(changed_velocity);
                        (*it)->set_changed_position_on_the_current_road(changed_position);
                    }
                }
            }
        }
        for(long long int edges_iterator = 0; edges_iterator <= G->roadID_recerved; edges_iterator++) {
            r = G->getRoadptr(edges_iterator);
            if(r->get_cars_on_the_road()->empty() == 0) {
                auto it = r->get_cars_on_the_road()->begin();
                if((*it)->get_changed_current_road_number_in_the_route() !=
                   (*it)->get_current_road_number_in_the_route()) {
                    next_r = G->getRoadptr(
                            (*(*it)->get_route())[(*it)->get_current_road_number_in_the_route() + 1]);
                    next_r->get_cars_on_the_road()->push_back(*it);
                    r->get_cars_on_the_road()->pop_front();
                }
                else if((*it)->get_reached_distination() == 1) {
                    r->get_cars_on_the_road()->pop_front();
                    sum_time += total_time;
                }
                (*it)->update_car();
            }
        }
        for(long long int edges_iterator = 0; edges_iterator <= G->roadID_recerved; edges_iterator++) {
            r = G->getRoadptr(edges_iterator);
            if(r->get_cars_on_the_road()->empty() == 0) {
                auto it = r->get_cars_on_the_road()->begin();
                for(it; it != r->get_cars_on_the_road()->end(); it++) {
                    (*it)->update_car();
                    if(number_of_updates % 10 == 0){
                        average_velocities[edges_iterator].sum += (*it)->get_velocity();
                        average_velocities[edges_iterator].number_of_counts++;
                    }
                }
            }
        }
    }
    for(int i = 0; i <= G->roadID_recerved; i++){
        if(average_velocities[i].number_of_counts != 0){
            average_velocities[i].average_speed = average_velocities[i].sum / average_velocities[i].number_of_counts;
        }
        //printf("%d %lf \n", i, average_velocities[i].average_speed);
    }
    average_time = sum_time / number_of_cars;
    //printf("average_time %lf\n", average_time);
    return average_time;
}