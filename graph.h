//
// Created by mmiknich on 09.05.19.
//

#include <vector>
#include <utility>
#include "road.h"

#define SPEEDLIMIT 0
#define STANDARTCIRCLELEN 15
#ifndef TRAFFIC_DONKEY_GRAPH_H
#define TRAFFIC_DONKEY_GRAPH_H
#define lli long long int

class graph  {
public:

    std::vector<std::vector<road>> graphModel;
    /*
     *     | A | B | C | D | E | ....
     *     |ptr|ptr|ptr|...
     *       |
     *       |
     *       vector of edges: road1 | road2 | road3 |
     */


    struct adj_element{
        lli tVertexID; // ID or the end of edge
        double weight; // Well it's weight of the edge (Length of the street)
        //char speedLimit; // speed limit;
        adj_element* next; //Pointer to the next edge from the same vertex
    };

    lli VertNumber = 0;
    lli EdgeNumber = 0;


    std::vector<adj_element*>vert;
    /*
     *    VERT
     *    |1|2|3|4|5|.... <-VERTEX ID
     *    |a|b|c|d|e|.... <-Pointer to edge
     */

    std::vector<adj_element> adj;
    /*
     *    ADJ
     *    |6|8|4|7|0|..... <-ID of the end of edge
     *    |9|6|2|6|6|..... <-Edge weight
     *    |a|b|c|d|e|..... <-Pointer to the next edge
     *
     */
    graph(lli *List, lli list_size);
    lli getVertexDegree(lli Vertex_ID); // counts vertex degree
    lli getNumofVertexout(lli Vertex_ID); // counts number of outer edges
    lli getNumofVertexinp(lli Vertex_ID); // counts number of inter edges
    graph *prepeir(); // rebuilds this graph into model-prepared graph
    adj_element *addtoEdge(lli oVertex_ID, lli iVertex_ID, double weight);
};


#endif //TRAFFIC_DONKEY_GRAPH_H
