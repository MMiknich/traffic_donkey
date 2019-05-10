//
// Created by mmiknich on 09.05.19.
//

#include "graph.h"
#include <vector>

//graph::graph(lli *List, lli list_size) {
//    char adjSize = SPEEDLIMIT ? 4 : 3;
//    std::vector<bool> vertexnum;
//    for (int i = 0; i < list_size; i++)
//    {
//
//    }
//}

lli graph::getNumofVertexout(lli Vertex_ID) {
    if(Vertex_ID >= this->VertNumber)
        return 0;
    lli Output = 0;
    graph::adj_element * ptr = this->vert[Vertex_ID];

    while (ptr != nullptr)
    {
        ptr = ptr->next;
        Output++;
    }

    return Output;
}
lli graph::getNumofVertexinp(lli Vertex_ID) {
    if(Vertex_ID >= this->VertNumber)
        return 0;
    lli Output = 0;
    for (auto a : this->adj)
        if(a.tVertexID == Vertex_ID) Output++;
    return Output;
}

lli graph::getVertexDegree(lli Vertex_ID) {
    return getNumofVertexinp(Vertex_ID) + getNumofVertexout(Vertex_ID);
}

graph* graph::prepeir() {
    lli vertNum = this->vert.size();
    for (int i = 0; i < vertNum; i++)
    {
        lli degree = getVertexDegree(i);
        if(degree > 3)
        {
            addtoEdge(this->vert.size(), i, STANDARTCIRCLELEN);
            for (int j = 1; j <= degree-2; j++) {
                addtoEdge(this->vert.size(), this->vert.size()-1 , STANDARTCIRCLELEN);
            }
            addtoEdge(i, this->vert.size() - 1, STANDARTCIRCLELEN);

        }

    }
}

graph::adj_element* graph::addtoEdge(lli oVertex_ID, lli iVertex_ID, double weight) {

}


