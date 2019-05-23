//
// Created by mmiknich on 09.05.19.
//

#include "car.h"
#include "graph.h"
#include <list>
using namespace std;
car::car(){
    car_id = -1;
    position_on_the_current_road = 0;
    vector<long long int> route;
    current_road_number_in_the_route = -1;
    acceleration = 0;
    velocity = 0;
    changed_position_on_the_current_road = 0;
    changed_current_road_number_in_the_route = -1;
    changed_acceleration = 0;
    changed_velocity = 0;
    start = 0;
    finish = 0;
    reached_destination = 0;
}
void car::set_car_id(int car_id){
    this->car_id = car_id;
}
void car::set_position_on_the_current_road(double position_on_the_current_road){
    this->position_on_the_current_road = position_on_the_current_road;
}
void car::set_route(vector<long long int> route){
    this->route = route;
}
void car::set_current_road_number_in_the_route(int current_road_number_in_the_route){
    this->current_road_number_in_the_route = current_road_number_in_the_route;
}
void car::set_acceleration(double acceleration){
    this->acceleration = acceleration;
}
void car::set_velocity(double velocity){
    this->velocity = velocity;
}
void car::set_changed_position_on_the_current_road(double changed_position_on_the_current_road){
    this->changed_position_on_the_current_road = changed_position_on_the_current_road;
}
void car::set_changed_current_road_number_in_the_route(int changed_current_road_number_in_the_route){
    this->changed_current_road_number_in_the_route = changed_current_road_number_in_the_route;
}
void car::set_changed_acceleration(double changed_acceleration){
    this->changed_acceleration = changed_acceleration;
}
void car::set_changed_velocity(double changed_velocity){
    this->changed_velocity = changed_velocity;
}
void car::set_start(int start) {
    this->start = start;
}
void car::set_finish(int finish) {
    this->finish = finish;
}
void car::set_reached_distination(bool riched_distination){
    this->reached_destination = riched_distination;
}
int car::get_car_id(){
    return this->car_id;
}
double car::get_position_on_the_current_road(){
    return this->position_on_the_current_road;
}
vector<long long int> *car::get_route(){
    return &(this->route);
}
int car::get_current_road_number_in_the_route(){
    return this->current_road_number_in_the_route;
}
double car::get_acceleration(){
    return this->acceleration;
}
double car::get_velocity(){
    return this->velocity;
}
double car::get_changed_position_on_the_current_road(){
    return this->changed_position_on_the_current_road;
}
int car::get_changed_current_road_number_in_the_route(){
    return this->changed_current_road_number_in_the_route;
}
double car::get_changed_acceleration(){
    return this->changed_acceleration;
}
double car::get_changed_velocity(){
    return this->changed_velocity;
}
int car::get_start() {
    return this->start;
}
int car::get_finish() {
    return this->finish;
}
bool car::get_reached_distination() {
    return this->reached_destination;
}
void car::update_car(){
    //this->set_position_on_the_current_road(this->get_changed_position_on_the_current_road());
    //this->set_current_road_number_in_the_route(this->get_changed_current_road_number_in_the_route());
    this->set_velocity(this->get_changed_velocity());
    this->set_acceleration(this->get_changed_acceleration());
    this-> set_position_on_the_current_road(this->get_changed_position_on_the_current_road());
    this->set_current_road_number_in_the_route(this->get_changed_current_road_number_in_the_route());
//    road r = *G.getRoadptr(this->get_route()[this->get_current_road_number_in_the_route()].first);
//    road next_r = *G.getRoadptr(this->get_route()[this->get_current_road_number_in_the_route() + 1].first);
//    if(this->get_changed_position_on_the_current_road() + 0.5 >= r.get_length()) {
//        this->set_current_road_number_in_the_route() =
//                this->get_current_road_number_in_the_route() + 1;
//        this->set_position_on_the_current_road(
//                this->get_changed_position_on_the_current_road() - r.get_length());
//        r.get_cars_on_the_road().pop_front();
//        next_r.get_cars_on_the_road().push_back(this);
//    }
}
//car operator= (car example){

//}