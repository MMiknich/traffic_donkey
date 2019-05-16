//
// Created by mmiknich on 09.05.19.
//
#include <iostream>
#include <assert.h>
#include "road.h"
#include "graph.h"

int main()
{
   lli A[6] = {0, 2, 3, 1, 1, 4};
   lli B[6] = {1,1,1,5,6,1};
   double C[6] = {0.5,0.5,0.5,0.5,0.5,0.5};

   std::vector<int*> H;
   H.reserve(6);
   int *a = new int(10);
   H.push_back(a);
   lli a = H.size();
//   graph N(A, B, C, 6);
 //  N.print();
//   N.normalize();
//   N.graphModel.insert(N.graphModel.begin() + 7, N.graphModel[0]);



   //N.addEdge(3, 4, 0.5, 0);

   //std::vector<int> G = {0};
   return 0;
}