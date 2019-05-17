//
// Created by mmiknich on 09.05.19.
//

#include <vector>
#include <utility>
#include <iostream>
#include "road.h"

#define SPEEDLIMIT 0
#define STANDARTCIRCLELEN 15
#ifndef TRAFFIC_DONKEY_GRAPH_H
#define TRAFFIC_DONKEY_GRAPH_H
#define lli long long int

class graph {
public:
    enum road_type {
        INPUT, OUTPUT
    };

    struct edge {
        road_type roadType;
        lli vertex;
        road *edgeRoad;
    };

    std::vector<std::vector<edge*>*> graphModel;
    /*     graphModel
     *     | A | B | C | D | E | ....
     *     |ptr|ptr|ptr|...
     *       |
     *       |
     *       vector of edges: edge1 | edge2 | edge3 |
     */

    lli roadID_recerved = 0;

    graph(lli *ListS, lli *ListT, double *ListWeight, lli list_size);
    graph *normalize(); //makes sutable for our model
    graph *addEdge(lli S, lli T, road *pRoad);
    graph *addEdge(lli S, lli T, double weight, int priority);//adds edge
    graph *moveEdge(lli S, lli T, lli newS, lli newT);
    graph *moveEdge(lli roadID, lli newS, lli newT);

    graph *addtoVertex(lli num, edge* edgeptr);
    graph *addVertex(lli num);


    lli getRoadID(lli S, lli T);
    road *getRoadptr(lli roadID);
    pair<lli, lli> getEdge(lli roadID);


    void print();
    lli getVertexDegree(lli Vertex_ID); // counts vertex degree
    lli getNumofVertexout(lli Vertex_ID); // counts number of outer edges
    lli getNumofVertexinp(lli Vertex_ID); // counts number of inter edges




};

#endif //TRAFFIC_DONKEY_GRAPH_H
