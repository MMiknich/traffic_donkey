//
// Created by mmiknich on 09.05.19.
//
#include <iostream>
#include <cassert>
int main()
{
   lli A[9] = {0,2,3,1,1,4,3,6,4 };
   lli B[9] = {1,1,1,5,6,1,5,5,5 };
   double C[9] = {0.5,0.5,0.5,0.5,0.5,0.5,1,1,9};

   graph N(A, B, C, 9);
   N.print();
   N.normalize();
    N.print();
//   N.graphModel.insert(N.graphModel.begin() + 7, N.graphModel[0]);



   //N.addEdge(3, 4, 0.5, 0);

   //std::vector<int> G = {0};
   return 0;

}