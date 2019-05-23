//
// Created by mmiknich on 09.05.19.
//
#include <iostream>
#include <cassert>
#include "graph.h"
#include "car.h"
#include "road.h"
#define lli long long int
//#define CRITICAL_DISTANCE 0.3
//#define CRITICAL_TIME_TO_MAKE_A_TURN 5.0;
extern int all_the_roads();
int main()
{
//    lli A[4] = {0,0,1,2};
//    lli B[4] = {1,2,3,3};
//    double C[4] = {1,2,3,1};

   lli A[10] = {0,2,3,1,1,4,3,6,4, 3 };
   lli B[10] = {1,1,1,5,6,1,5,5,5, 4 };
   double C[10] = {10, 10, 10, 10, 10, 10, 10, 10, 10, 10};

   graph N(A, B, C, 10);
   N.print();
   N.normalize();
    N.print();
    counting_average_velocities g[10];
    for(int i = 0; i < 10; i++)
    {
        g[i].average_speed = 60;
    }
    vector<lli> G = N.findWay(0, 18, g);

    return 0;

    //N.findWay(0, 15, G);
//   N.graphModel.insert(N.graphModel.begin() + 7, N.graphModel[0]);



   //N.addEdge(3, 4, 0.5, 0);

   //std::vector<int> G = {0};
   return 0 ;
}
//   long long int number_of_edges = 4;
//   long long int ListS[4] = {1, 2, 2, 2};
//   long long int ListT[4] = {2, 3, 4, 5};
//   double length[4] = {1000, 200, 300, 100};
//   graph G(ListS, ListT, length, number_of_edges);
//   G.normalize();
//   int number_of_cars = 2;
//   int number_of_cars_reached_destination = 0;
//   double delta_t = 0.1;
//   double a = 2.0;
//   double b = 2.0;
//   double d = 7.5;
//   double T = 1;
//   double v;
//   double vel_current;
//   double position_current;
//   double vel_forward;
//   double position_forward;
//   double changed_acceleration;
//   double changed_velocity;
//   double changed_position;
//   int changed_road;
//   double temp_value;
//   road *r;
//   road *next_r;
//   vector<pair<int, double>> route_t;
//   //cout << G.getRoadptr(G.getRoadID(6, 7))->get_length() << "\n";
//   route_t.push_back(make_pair(G.getRoadID(1, 6), 0));
//   route_t.push_back(make_pair(G.getRoadID(6, 7), 0));
//   route_t.push_back(make_pair(G.getRoadID(7, 8), 0));
//    route_t.push_back(make_pair(G.getRoadID(8, 4), 0));
//   car *one_car= new car(1, 0, route_t, 0,0,0,0,0,0,0,0, 0, 0);
//    vector<pair<int, double>> route_t2;
//    route_t2.push_back(make_pair(G.getRoadID(2, 6), 0));
//    route_t2.push_back(make_pair(G.getRoadID(6, 7), 0));
//    route_t2.push_back(make_pair(G.getRoadID(7, 3), 0));
//    car *one_car2= new car(2, 0, route_t2, 0,0,0,0,0,0,0,0, 0, 0);
//   //cout << one_car->get_route()->front().first;
//   //cout << one_car << "sdfgb\n";
//    G.getRoadptr(G.getRoadID(1, 6))->set_relative_road_id_1(G.getRoadID(2, 6));
//   (G.getRoadptr(G.getRoadID(1, 6))->get_cars_on_the_road())->push_back(one_car);
//    (G.getRoadptr(G.getRoadID(2, 6))->get_cars_on_the_road())->push_back(one_car2);
////    FILE * file;
////    file = fopen("out.txt", "w+");
////    list<car> cars_on_the_road;
////    vector<int> route;
////    cars_on_the_road.insert(cars_on_the_road.end(), car(0, 1000, route, 0, 0, 0, 0, 0, 0, 0));
////    for(int i = 1; i < N; i++){
////        cars_on_the_road.insert(cars_on_the_road.end(), car(i, -100 * i, route, 0, 0, 0, 0, 0, 0, 0));
////    }
////    struct tms *start_times = (struct tms *) malloc(sizeof(struct tms));
////    struct tms *finish_times = (struct tms *) malloc(sizeof(struct tms));
////    struct result_times{
////        double real;
////        double user;
////        double sys;
////    };
////    clock_t start = times(start_times);
//   while(number_of_cars_reached_destination != number_of_cars) {
////      number_of_cars_reached_destination++;
//      for(long long int edges_iterator = 0; edges_iterator <= G.roadID_recerved; edges_iterator++) {
//         r = G.getRoadptr(edges_iterator);
//         //cout << "road_length" << r->get_cars_on_the_road()->empty() << "\n";
//         //r.set_velocity_restrictions(16.67);
//         //v = r.get_velocity_restrictions();
//         v = 16.67;
//         if(r->get_cars_on_the_road()->empty() == 0) {
//            car *head_car = ((r->get_cars_on_the_road())->front());
//            if(head_car->get_current_road_number_in_the_route() == head_car->get_route()->size() - 1) { //if this road is the last one in the route
//               vel_current = head_car->get_velocity();
//               position_current = head_car->get_position_on_the_current_road();
//               vel_forward = 0;
//               position_forward = r->get_length() + d - 0.5;
//               temp_value = (d +
//                             (T - ((vel_forward - vel_current) / (2 * a))) * vel_current) /
//                            (position_forward - position_current);
//               changed_acceleration = a * (1 - vel_current / v - temp_value * temp_value);
//               head_car->set_changed_acceleration(changed_acceleration);
//               changed_velocity = vel_current + delta_t * head_car->get_acceleration();
//               changed_position =
//                       position_current + delta_t * vel_current +
//                       delta_t * delta_t * head_car->get_acceleration() / 2;
//               head_car->set_changed_velocity(changed_velocity);
//               head_car->set_changed_position_on_the_current_road(changed_position);
//               if(changed_position + CRITICAL_DISTANCE >= r->get_length()) {
//                  //r->get_cars_on_the_road()->pop_front();
//                  number_of_cars_reached_destination++;
//                  head_car->set_reached_distination(1);
//               }
//            }
//            else if(r->get_priority() == 0 &&    //this road is NOT the last one, current road priority is 0 and priority of the next road is also 0
//                    head_car->get_current_road_number_in_the_route() != head_car->get_route()->size() - 1 &&
//                    (G.getRoadptr(((*head_car->get_route())[head_car->get_current_road_number_in_the_route() +
//                                                      1]).first))->get_priority() == 0) {
//                vel_current = head_car->get_velocity();
//                position_current = head_car->get_position_on_the_current_road();
//                next_r = G.getRoadptr((*head_car->get_route())[head_car->get_current_road_number_in_the_route() + 1].first);
//                if(next_r->get_cars_on_the_road()->empty() == 0) {
//                    vel_forward = (*next_r->get_cars_on_the_road()->back()).get_velocity();
//                    position_forward = (*next_r->get_cars_on_the_road()->back()).get_position_on_the_current_road();
//                }
//                else {
//                    vel_forward = 33;
//                    position_forward = 500;
//                }
//                temp_value = (d +
//                              (T - ((vel_forward - vel_current) / 2 * a)) * vel_current) /
//                             (position_forward + r->get_length() - position_current);
//                // printf("current %lf %lf %lf %d\n", head_car->get_position_on_the_current_road(), head_car->get_velocity(), head_car->get_acceleration(), head_car->get_current_road_number_in_the_route());
//                changed_acceleration = a * (1 - vel_current / v - temp_value * temp_value);
//                head_car->set_changed_acceleration(changed_acceleration);
//                changed_velocity = vel_current + delta_t * head_car->get_acceleration();
//                changed_position =
//                        position_current + delta_t * vel_current +
//                        delta_t * delta_t * head_car->get_acceleration() / 2;
//                head_car->set_changed_velocity(changed_velocity);
//                head_car->set_changed_position_on_the_current_road(changed_position);
//
//                //printf("changed %lf %lf %lf\n", changed_position, changed_velocity, changed_acceleration);
//                printf("changed %lf %lf %lf\n", head_car->get_changed_position_on_the_current_road(),
//                       head_car->get_changed_velocity(), head_car->get_changed_acceleration());
//                //cout << r->get_length() << "\n";
//                if(changed_position + CRITICAL_DISTANCE >= r->get_length()) {
//                    head_car->set_changed_current_road_number_in_the_route(
//                            head_car->get_current_road_number_in_the_route() + 1);
//                    head_car->set_changed_position_on_the_current_road(
//                            head_car->get_changed_position_on_the_current_road() - r->get_length());
//                }
//            }
//            else if(r->get_priority() == 0 && head_car->get_current_road_number_in_the_route() != head_car->get_route()->size() - 1 && //if head_car is NOT last road, current road priority is 0 and next road priority is 1
//                       (G.getRoadptr((*head_car->get_route())[head_car->get_current_road_number_in_the_route() + 1].first))->get_priority() == 1){
//                  vel_current = head_car->get_velocity();
//                  position_current = head_car->get_position_on_the_current_road();
//                  vel_forward = 0;
//                  position_forward = r->get_length() + d - 0.5; //before turning to the circle the car should stop
//                temp_value = (d +
//                              (T - ((vel_forward - vel_current) / (2 * a))) * vel_current) /
//                             (position_forward - position_current);
//                changed_acceleration = a * (1 - vel_current / v - temp_value * temp_value);
//                  head_car->set_changed_acceleration(changed_acceleration);
//                  changed_velocity = vel_current + delta_t * head_car->get_acceleration();
//                  changed_position =
//                          position_current + delta_t * vel_current +
//                          delta_t * delta_t * head_car->get_acceleration() / 2;
//                  head_car->set_changed_velocity(changed_velocity);
//                  head_car->set_changed_position_on_the_current_road(changed_position);
//                  if(changed_position + CRITICAL_DISTANCE >= r->get_length()){
//
//                      if(G.getRoadptr(r->get_relative_road_id_1())->get_cars_on_the_road()->empty() == 0) {
//                          car *car_to_wait = G.getRoadptr(r->get_relative_road_id_1())->get_cars_on_the_road()->front();
//                          double time_for_a_turn = ((G.getRoadptr(r->get_relative_road_id_1()))->get_length() -
//                                                    car_to_wait->get_position_on_the_current_road() )/ car_to_wait->get_velocity();
//                          if(5.0 < time_for_a_turn) {
//                              head_car->set_changed_current_road_number_in_the_route(
//                                      head_car->get_current_road_number_in_the_route() + 1);
//                              head_car->set_changed_position_on_the_current_road(
//                                      head_car->get_changed_position_on_the_current_road() - r->get_length());
//                          }
//                      }
//                      else{
//                          //cout<< "sdf\n";
//                          head_car->set_changed_current_road_number_in_the_route(
//                                  head_car->get_current_road_number_in_the_route() + 1);
//                          head_car->set_changed_position_on_the_current_road(
//                                  head_car->get_changed_position_on_the_current_road() - r->get_length());
//                      }
//                  }
//            }
//            else if(r->get_priority() == 1 &&    //this road is NOT the last one, current road priority is 1 and priority of the next road is also 1
//                    head_car->get_current_road_number_in_the_route() != head_car->get_route()->size() - 1 &&
//                    (G.getRoadptr(((*head_car->get_route())[head_car->get_current_road_number_in_the_route() +
//                                                      1]).first))->get_priority() == 1) {
//                vel_current = head_car->get_velocity();
//                position_current = head_car->get_position_on_the_current_road();
//                next_r = G.getRoadptr((*head_car->get_route())[head_car->get_current_road_number_in_the_route() + 1].first);
//                if(next_r->get_cars_on_the_road()->empty() == 0) {
//                    vel_forward = (*next_r->get_cars_on_the_road()->back()).get_velocity();
//                    position_forward = (*next_r->get_cars_on_the_road()->back()).get_position_on_the_current_road();
//                }
//                else {
//                    vel_forward = 33;
//                    position_forward = 500;
//                }
//                temp_value = (d +
//                              (T - ((vel_forward - vel_current) / 2 * a)) * vel_current) /
//                             (position_forward + r->get_length() - position_current);
//                // printf("current %lf %lf %lf %d\n", head_car->get_position_on_the_current_road(), head_car->get_velocity(), head_car->get_acceleration(), head_car->get_current_road_number_in_the_route());
//                changed_acceleration = a * (1 - vel_current / v - temp_value * temp_value);
//                head_car->set_changed_acceleration(changed_acceleration);
//                changed_velocity = vel_current + delta_t * head_car->get_acceleration();
//                changed_position =
//                        position_current + delta_t * vel_current +
//                        delta_t * delta_t * head_car->get_acceleration() / 2;
//                head_car->set_changed_velocity(changed_velocity);
//                head_car->set_changed_position_on_the_current_road(changed_position);
//
//                //printf("changed %lf %lf %lf\n", changed_position, changed_velocity, changed_acceleration);
//                //printf("changed %lf %lf %lf\n", head_car->get_changed_position_on_the_current_road(),
//                  //     head_car->get_changed_velocity(), head_car->get_changed_acceleration());
//                //cout << r->get_length() << "\n";
//                if(changed_position + CRITICAL_DISTANCE >= r->get_length()) {
//                    head_car->set_changed_current_road_number_in_the_route(
//                            head_car->get_current_road_number_in_the_route() + 1);
//                    head_car->set_changed_position_on_the_current_road(
//                            head_car->get_changed_position_on_the_current_road() - r->get_length());
//                }
//            }
//            else if(r->get_priority() == 1 &&    //this road is NOT the last one, current road priority is 1 and priority of the next road is also 1
//                    head_car->get_current_road_number_in_the_route() != head_car->get_route()->size() - 1 &&
//                    (G.getRoadptr(((*head_car->get_route())[head_car->get_current_road_number_in_the_route() +
//                                                      1]).first))->get_priority() == 0) {
//                vel_current = head_car->get_velocity();
//                position_current = head_car->get_position_on_the_current_road();
//                next_r = G.getRoadptr((*head_car->get_route())[head_car->get_current_road_number_in_the_route() + 1].first);
//                if(next_r->get_cars_on_the_road()->empty() == 0) {
//                    vel_forward = (*next_r->get_cars_on_the_road()->back()).get_velocity();
//                    position_forward = (*next_r->get_cars_on_the_road()->back()).get_position_on_the_current_road();
//                }
//                else {
//                    vel_forward = 33;
//                    position_forward = 500;
//                }
//                temp_value = (d +
//                              (T - ((vel_forward - vel_current) / 2 * a)) * vel_current) /
//                             (position_forward + r->get_length() - position_current);
//                // printf("current %lf %lf %lf %d\n", head_car->get_position_on_the_current_road(), head_car->get_velocity(), head_car->get_acceleration(), head_car->get_current_road_number_in_the_route());
//                changed_acceleration = a * (1 - vel_current / v - temp_value * temp_value);
//                head_car->set_changed_acceleration(changed_acceleration);
//                changed_velocity = vel_current + delta_t * head_car->get_acceleration();
//                changed_position =
//                        position_current + delta_t * vel_current +
//                        delta_t * delta_t * head_car->get_acceleration() / 2;
//                head_car->set_changed_velocity(changed_velocity);
//                head_car->set_changed_position_on_the_current_road(changed_position);
//
//                //printf("changed %lf %lf %lf\n", changed_position, changed_velocity, changed_acceleration);
//                //printf("changed %lf %lf %lf\n", head_car->get_changed_position_on_the_current_road(),
//                //       head_car->get_changed_velocity(), head_car->get_changed_acceleration());
//                //cout << r->get_length() << "\n";
//                if(changed_position + CRITICAL_DISTANCE >= r->get_length()) {
//                    head_car->set_changed_current_road_number_in_the_route(
//                            head_car->get_current_road_number_in_the_route() + 1);
//                    head_car->set_changed_position_on_the_current_road(
//                            head_car->get_changed_position_on_the_current_road() - r->get_length());
//                }
//            }
//            auto it = r->get_cars_on_the_road()->begin();
//            if(r->get_cars_on_the_road()->size() > 1) {
//                it++;
//                auto it_forward = it;
//                advance(it_forward, -1);
//                for(it; it != r->get_cars_on_the_road()->end(); it++, it_forward++) {
//                    vel_current = (*it)->get_velocity();
//                    position_current = (*it)->get_position_on_the_current_road();
//                    vel_forward = (*it_forward)->get_velocity();;
//                    position_forward = (*it_forward)->get_position_on_the_current_road();
//                    temp_value = (d +
//                                  (T - ((vel_forward - vel_current) / (2 * a))) * vel_current) /
//                                 (position_forward - position_current);
//                    changed_acceleration = a * (1 - vel_current / v - temp_value * temp_value);
//                    (*it)->set_changed_acceleration(changed_acceleration);
//                    changed_velocity = vel_current + delta_t * head_car->get_acceleration();
//                    changed_position =
//                            position_current + delta_t * vel_current +
//                            delta_t * delta_t * head_car->get_acceleration() / 2;
//                    (*it)->set_changed_velocity(changed_velocity);
//                    (*it)->set_changed_position_on_the_current_road(changed_position);
//                }
//            }
//        }
//
////         printf("%lf %lf %lf %d\n", one_car.get_position_on_the_current_road(), one_car.get_velocity(), one_car.get_acceleration(), one_car.get_current_road_number_in_the_route());
//      }
//      for(long long int edges_iterator = 0; edges_iterator <= G.roadID_recerved; edges_iterator++) {
//          r = G.getRoadptr(edges_iterator);
//          if(r->get_cars_on_the_road()->empty() == 0) {
//              auto it = r->get_cars_on_the_road()->begin();
//              if((*it)->get_changed_current_road_number_in_the_route() !=
//                 (*it)->get_current_road_number_in_the_route()) {
//                  cout << "try to  change\n";
//                  next_r = G.getRoadptr(
//                          (*(*it)->get_route())[(*it)->get_current_road_number_in_the_route() + 1].first);
//                  next_r->get_cars_on_the_road()->push_back(*it);
//                  r->get_cars_on_the_road()->pop_front();
//              }
//              else if((*it)->get_reached_distination() == 1) {
//                  r->get_cars_on_the_road()->pop_front();
//              }
//              (*it)->update_car();
//              //printf("ready to update %lf %lf %lf %d\n", (*it)->get_position_on_the_current_road(),
//                   //  (*it)->get_velocity(),
//                    // (*it)->get_acceleration(), (*it)->get_changed_current_road_number_in_the_route());
//          }
//      }
//       for(long long int edges_iterator = 0; edges_iterator <= G.roadID_recerved; edges_iterator++) {
//           r = G.getRoadptr(edges_iterator);
//           if(r->get_cars_on_the_road()->empty() == 0) {
//               auto it = r->get_cars_on_the_road()->begin();
//               for(it; it != r->get_cars_on_the_road()->end(); it++) {
//                   (*it)->update_car();
//                   printf("ready to update %d %lf %lf %lf %d\n", (*it)->get_car_id(), (*it)->get_position_on_the_current_road(),
//                          (*it)->get_velocity(),
//                          (*it)->get_acceleration(), (*it)->get_changed_current_road_number_in_the_route());
//               }
//            }
//      }
//   }
//   delete(one_car);
//}