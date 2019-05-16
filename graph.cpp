//
// Created by mmiknich on 09.05.19.
//

#include "graph.h"
#include <vector>
#include <assert.h>

graph::graph(lli *ListS, lli *ListT, double *ListWeight, lli list_size) {

    //reserving space
    lli maxS = ListS[0];
    for (int i = 0; i < list_size; i++)
        maxS = maxS > ListS[i] ? maxS : ListS[i];

    lli maxT = ListT[0];
    for (int i = 0; i < list_size; i++)
        maxT = maxT > ListT[i] ? maxT : ListT[i];

    this->graphModel.reserve(1 + (maxS > maxT ? maxS : maxT));


    for (lli i = 0; i < list_size; i++){

        //Idiot check:
        assert(ListS[i] != ListT[i]);

        road *rd = new road();
        rd->set_length(ListWeight[i]);
        rd->set_road_id(i);

        // adding A->B
        edge *ed = new edge();
        ed->roadType = OUTPUT;
        ed->vertex = ListT[i];
        ed->edgeRoad = rd;

        this->addtoVertex(ListS[i], ed);

        // adding B<-A
        ed = new edge();
        ed->roadType = INPUT;
        ed->vertex = ListS[i];
        ed->edgeRoad = rd;
        this->addtoVertex(ListT[i], ed);
    }

    this->roadID_recerved = list_size - 1;
}

graph* graph::addtoVertex(lli num, edge* edgeptr) {
    if (this->graphModel.size() <= num)
        for (int i = 0; i <= num - graphModel.size(); i++) {
            auto Newvec = new vector<graph::edge *>;
            this->graphModel.push_back(Newvec);
        }
    this->graphModel[num]->push_back(edgeptr);
    return this;
}

void graph::print() {
    std::cout << "\n";
    for (lli j = 0; j < this->graphModel.size(); j++) {
        std::cout << '[' << j << "]: ";
        for (auto & i : *this->graphModel[j])
            std::cout << i->vertex << " " << i->roadType << " | "; //TODO: ТУт тоже падает
        std::cout << "\n";
    }
}

lli graph::getVertexDegree(lli Vertex_ID) {
    assert(Vertex_ID < this->graphModel.capacity());
    return this->graphModel[Vertex_ID]->size();
}

lli graph::getNumofVertexout(lli Vertex_ID) {
    lli output = 0;
    for (int i = 0; i < this->graphModel[Vertex_ID]->size(); i++)
        if(this->graphModel[Vertex_ID]->at(i)->roadType == OUTPUT)
            output++;
    return output;
}

lli graph::getNumofVertexinp(lli Vertex_ID) {
    lli output = 0;
    for (int i = 0; i < this->graphModel[Vertex_ID]->size(); i++)
        if(this->graphModel[Vertex_ID]->at(i)->roadType == INPUT)
            output++;
    return output;
}

graph* graph::addEdge(lli S, lli T, road *pRoad) {

    //Idiot check:
    assert(S != T);
    this->graphModel.reserve(1+(S > T ? S : T));


    road *rd = pRoad;

    // adding S->T
    edge *ed = new edge();
    ed->roadType = OUTPUT;
    ed->vertex = T;
    ed->edgeRoad = rd;
    this->graphModel[S].push_back(ed);

    // adding T<-S
    ed = new edge();
    ed->roadType = INPUT;
    ed->vertex = S;
    ed->edgeRoad = rd;
    this->graphModel[T].push_back(ed);
    return this;
}

graph* graph::addEdge(lli S, lli T, double weight, int priority = 0) {

    //Idiot check:
    assert(S != T);
    this->graphModel.reserve(1+(S > T ? S : T));

        //creating new road class
    road *rd = new road();
    rd->set_length(weight);
    this->roadID_recerved++;
    rd->set_road_id(this->roadID_recerved);
    rd->set_priority(priority);

        // adding S->T
    edge *ed = new edge();
    ed->roadType = OUTPUT;
    ed->vertex = T;
    ed->edgeRoad = rd;
    this->graphModel[S].push_back(ed);

        // adding T<-S
    ed = new edge();
    ed->roadType = INPUT;
    ed->vertex = S;
    ed->edgeRoad = rd;
    this->graphModel[T].push_back(ed);
    return this;
}

graph* graph::moveEdge(lli S, lli T, lli newS, lli newT) {

    //Dumb check:
    assert(S != T);
    lli mAx1 = S > T ? S : T;
    lli mAx2 = newS > newT ? newS : newT;
    mAx1 = mAx1 > mAx2 ? mAx1 : mAx2;
    this->graphModel.reserve(mAx1 + 1);

    road *movingRoad = nullptr;

        //Deleting old edge, moving road struct
    for ( lli i = 0; i < this->graphModel[S].size(); i++) {

        if (this->graphModel[S][i]->vertex == T) {
            movingRoad = this->graphModel[S][i]->edgeRoad;
            free(this->graphModel[S][i]);
            this->graphModel[S].erase(this->graphModel[S].begin() + i);
            break;
        }
    }
    for ( lli i = 0; i < this->graphModel[T].size(); i++) {
        if (this->graphModel[T][i]->vertex == S) {
            free(this->graphModel[T][i]);
            this->graphModel[T].erase(this->graphModel[T].begin() + i); //TODO: ПАдает тут
            break;
        }
    }

    assert(movingRoad != nullptr);
        //creating new edge with old road
    return this->addEdge(newS, newT, movingRoad);
}

graph* graph::moveEdge(lli roadID, lli newS, lli newT) {

    //Dumb check:
    assert(roadID <= this->roadID_recerved);
    assert(newS != newT);
    this->graphModel.reserve(1+(newS > newT ? newS : newT));

    pair<lli, lli> inp = this->getEdge(roadID);
    return moveEdge(inp.first, inp.second, newS, newT);
}

lli graph::getRoadID(lli S, lli T) {
    assert(this->graphModel.capacity() + 1 >= S > T ? S : T);

    for (auto a : this->graphModel[S])
        if(a->vertex == T)
            return a->edgeRoad->get_road_id();
        //in case no such edge
    return -1;

}

road* graph::getRoadptr(lli roadID)
{
    assert(roadID <= this->roadID_recerved);
    road *output = nullptr;
    for(int i = 0; i < this->graphModel.capacity(); i++)
        for(auto a : this->graphModel[i])
            if(a->edgeRoad->get_road_id() == roadID)
                return a->edgeRoad;
    return nullptr;
}

pair<lli, lli> graph::getEdge(lli roadID) {
    assert(roadID <= this->roadID_recerved);
    for(int i = 0; i < this->graphModel.capacity(); i++)
        for(int j : this->graphModel[i])
            if(a->edgeRoad->get_road_id() == roadID)
            {
                if(a->roadType == OUTPUT)
                    return {i, a->vertex};
                else
                    return {a->vertex, i};
            }
    return {-1, -1};

}

graph* graph::normalize() {
    for (int i = 0; i < this->graphModel.capacity(); i++)
    {
        print();
        lli degree = this->getVertexDegree(i);
        if (degree > 3)
        {
            lli oldCapacity = this->graphModel.capacity();
            //rebuilding of vertex
            this->graphModel.reserve(oldCapacity + degree - 1); //adding new $(degree)-1 vertexes
            lli a = this->graphModel.size();

            this->print();

            //building of circle
            this->addEdge(i, oldCapacity, STANDARTCIRCLELEN, 1); //give high priority to circle  s->s1
            this->print();

            for(lli j = 0; j < degree - 2; j++) {
                this->addEdge(oldCapacity + j, oldCapacity + j + 1, STANDARTCIRCLELEN,
                              1); //building circle -->s_j->s_j+1
            }
            this->addEdge(oldCapacity + degree - 2, i, STANDARTCIRCLELEN, 1);// "end" of circle -->s_degree-1 -> s-->s1-->
            this->print();
            //moving edges
            for(lli j = 1; j < degree; j++)
            {
                if(this->graphModel[i][j]->roadType == OUTPUT) {
                    moveEdge(this->graphModel[i][j]->edgeRoad->get_road_id(),
                            oldCapacity + j - 1,             //S
                            this->graphModel[i][j]->vertex); //T
                } else
                {
                    moveEdge(this->graphModel[i][j]->edgeRoad->get_road_id(),
                            this->graphModel[i][j]->vertex, //S
                            oldCapacity + j - 1);           //T
                }
            }
        }
    }
}



