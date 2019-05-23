//
// Created by mmiknich on 09.05.19.
//

#include "graph.h"
#include <vector>
#include <cassert>
#include <limits>
#include <random>

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
    lli gMs = graphModel.size();
    if (this->graphModel.size() <= num)
        for (lli i = 0; i <= num - gMs; i++) {
            auto Newvec = new vector<graph::edge *>;
            this->graphModel.push_back(Newvec);
        }
    this->graphModel[num]->push_back(edgeptr);
    return this;
}

graph* graph::addVertex(lli num) {
    lli gMs = graphModel.size();
    if (this->graphModel.size() <= num)
        for (lli i = 0; i <= num - gMs; i++) {
            auto newVec = new vector<graph::edge *>;
            this->graphModel.push_back(newVec);
        }
    return this;
}

lli graph::getVertexDegree(lli Vertex_ID) {
    assert(Vertex_ID < this->graphModel.capacity());
    return this->graphModel[Vertex_ID]->size();
}

lli graph::getNumofVertexout(lli Vertex_ID) {
    lli output = 0;
    for (auto & i : *this->graphModel[Vertex_ID])
        if(i->roadType == OUTPUT)
            output++;
    return output;
}

lli graph::getNumofVertexinp(lli Vertex_ID) {
    lli output = 0;
    for (auto & i : *this->graphModel[Vertex_ID])
        if(i->roadType == INPUT)
            output++;
    return output;
}

graph* graph::addEdge(lli S, lli T, road *pRoad) {

    //Idiot check:
    assert(S != T);


    road *rd = pRoad;

    // adding S->T
    edge *ed = new edge();
    ed->roadType = OUTPUT;
    ed->vertex = T;
    ed->edgeRoad = rd;
    this->addtoVertex(S, ed);

    // adding T<-S
    ed = new edge();
    ed->roadType = INPUT;
    ed->vertex = S;
    ed->edgeRoad = rd;
    this->addtoVertex(T, ed);
    return this;
}

graph* graph::addEdge(lli S, lli T, double weight, int priority = 0) {

    //Idiot check:
    assert(S != T);

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
    this->addtoVertex(S, ed);

        // adding T<-S
    ed = new edge();
    ed->roadType = INPUT;
    ed->vertex = S;
    ed->edgeRoad = rd;
    this->addtoVertex(T, ed);
    return this;
}

graph* graph::moveEdge(lli S, lli T, lli newS, lli newT) {

    //Dumb check:
    assert(S != T);

    road *movingRoad = nullptr;

        //Deleting old edge, moving road struct
    for ( lli i = 0; i < this->graphModel[S]->size(); i++) {

        if (this->graphModel[S]->at(i)->vertex == T) {
            movingRoad = this->graphModel[S]->at(i)->edgeRoad;
            free(this->graphModel[S]->at(i));
            this->graphModel[S]->erase(this->graphModel[S]->begin() + i);
            break;
        }
    }
    for ( lli i = 0; i < this->graphModel[T]->size(); i++) {
        if (this->graphModel[T]->at(i)->vertex == S) {
            free(this->graphModel[T]->at(i));
            this->graphModel[T]->erase(this->graphModel[T]->begin() + i); //TODO: ПАдает тут
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

    pair<lli, lli> inp = this->getEdge(roadID);
    return moveEdge(inp.first, inp.second, newS, newT);
}

pair<lli, lli> graph::getEdge(lli roadID) {
    assert(roadID <= this->roadID_recerved);

    for(int i = 0; i < this->graphModel.size(); i++)
        for(auto & j : *this->graphModel[i])
            if(j->edgeRoad->get_road_id() == roadID)
            {
                if(j->roadType == OUTPUT)
                    return {i, j->vertex};
                else
                    return {j->vertex, i};
            }
    return {-1, -1};

}

lli graph::getRoadID(lli S, lli T) {

    assert(this->graphModel.capacity() + 1 >= S > T ? S : T);

    for (auto & i : *this->graphModel[S])
        if(i->vertex == T)
            return i->edgeRoad->get_road_id();

        //in case no such edge
    return -1;

}

road* graph::getRoadptr(lli roadID)
{
    assert(roadID <= this->roadID_recerved);

    for(auto & i : this->graphModel)
        for(auto & a : *i)
            if(a->edgeRoad->get_road_id() == roadID)
                return a->edgeRoad;
    return nullptr;
}

void graph::print() {
    std::cout << this->graphModel.size() << "\n";
    for (lli j = 0; j < this->graphModel.size(); j++) {
        std::cout << '[' << j << "]: ";
        for (auto & i : *this->graphModel[j])
            std::cout << i->vertex << " " << i->roadType << " | "; //TODO: ТУт тоже падает
        std::cout << "\n";
    }
}

graph* graph::normalize() {
    for (int i = 0; i < this->graphModel.size(); i++)
    {
        lli degree = this->getVertexDegree(i);
        if (degree > 3)
        {
            lli Sfirst = this->graphModel.size();

            //rebuilding of vertex
            addVertex(Sfirst + degree - 2);  //adding new $(degree)-1 vertexes

            //building of circle
            this->addEdge(i, Sfirst, STANDARTCIRCLELEN, 1); //give high priority to circle  s->s1

            for(lli j = 0; j < degree - 2; j++)
                this->addEdge(Sfirst + j, Sfirst + j + 1, STANDARTCIRCLELEN, 1); //building circle -->s_j->s_j+1

            this->addEdge(Sfirst + degree - 2, i, STANDARTCIRCLELEN, 1);// "end" of circle -->s_degree-1 -> s-->s1-->

            //moving edges
            for(lli j = 0; j < degree - 1; j++)
            {
                if(this->graphModel[i]->at(0)->roadType == OUTPUT) {
                    moveEdge(this->graphModel[i]->at(0)->edgeRoad->get_road_id(),
                            Sfirst + j,             //S
                            this->graphModel[i]->at(0)->vertex); //T
                } else
                {
                    moveEdge(this->graphModel[i]->at(0)->edgeRoad->get_road_id(),
                            this->graphModel[i]->at(0)->vertex, //S
                            Sfirst + j);           //T
                }
            }
        }
    }

    // for 3degree

    for (int i = 0; i < this->graphModel.size(); i++)
    {
        lli degree = this->getVertexDegree(i);
        if (degree == 3 && this->graphModel.at(i)->at(0)->edgeRoad->get_priority() == 0
                           && this->graphModel.at(i)->at(1)->edgeRoad->get_priority() == 0
                              && this->graphModel.at(i)->at(2)->edgeRoad->get_priority() == 0)
        {
            {
                lli Sfirst = this->graphModel.size();

                //rebuilding of vertex
                addVertex(Sfirst + degree - 2);  //adding new $(degree)-1 vertexes

                //building of circle
                this->addEdge(i, Sfirst, STANDARTCIRCLELEN, 1); //give high priority to circle  s->s1

                for(lli j = 0; j < degree - 2; j++)
                    this->addEdge(Sfirst + j, Sfirst + j + 1, STANDARTCIRCLELEN, 1); //building circle -->s_j->s_j+1

                this->addEdge(Sfirst + degree - 2, i, STANDARTCIRCLELEN, 1);// "end" of circle -->s_degree-1 -> s-->s1-->

                //moving edges
                for(lli j = 0; j < degree - 1; j++)
                {
                    if(this->graphModel[i]->at(0)->roadType == OUTPUT) {
                        moveEdge(this->graphModel[i]->at(0)->edgeRoad->get_road_id(),
                                 Sfirst + j,             //S
                                 this->graphModel[i]->at(0)->vertex); //T
                    } else
                    {
                        moveEdge(this->graphModel[i]->at(0)->edgeRoad->get_road_id(),
                                 this->graphModel[i]->at(0)->vertex, //S
                                 Sfirst + j);           //T
                    }
                }
            }
        }
    }


    //adding reletive roads

    for (auto  vertex : this->graphModel)
    {
        if(vertex->size() == 3)
        {
            int lowP_ID = -1;
            int inp_ID = -1;
            for(auto a : *vertex) {
                if(a->roadType == INPUT && a->edgeRoad->get_priority() == 0)
                    lowP_ID = a->edgeRoad->get_road_id(); //find low preor id
                else if(a->roadType == INPUT)
                    inp_ID = a->edgeRoad->get_road_id();
            }
            if(lowP_ID != -1)
                this->getRoadptr(lowP_ID)->set_relative_road_id_1(inp_ID);
            cout << lowP_ID <<"--"<<inp_ID<<" \n";

        }
        if(vertex->size() == 2)
        {
            vertex->at(0)->edgeRoad->set_relative_road_id_1(-1);
            vertex->at(0)->edgeRoad->set_relative_road_id_2(-1);
            vertex->at(1)->edgeRoad->set_relative_road_id_1(-1);
            vertex->at(1)->edgeRoad->set_relative_road_id_2(-1);
        }

    }
}

double graph::getWeight(int roadID, counting_average_velocities *cav) {
    assert(roadID <= this->roadID_recerved);
    double length = this->getRoadptr(roadID)->get_length();

    double avrSpeed = cav[roadID].average_speed;
    return (length / avrSpeed);
}

std::vector<lli> graph::findWay(int roadID_S, int roadID_T, counting_average_velocities *cav) {

    assert(roadID_S <= this->roadID_recerved && roadID_T <= this->roadID_recerved);

    lli S_point = this->getEdge(roadID_S).first; //start point
    lli T_point = this->getEdge(roadID_T).second; //end point

    ///---====Deikstra1====---
    std::vector<bool> visitedVert1(this->graphModel.size()); //vector of visited Vertexes
    std::vector<double> vertexFactor1(this->graphModel.size());    //vector of vector numbers
    std::vector<std::vector<lli>> ways1(this->graphModel.size()); //vector of ways

    // cleaning space
    for (auto &&i : visitedVert1) i = false;
    for (auto &&a : vertexFactor1) a =  std::numeric_limits<double>::max();
    // --------------

    //filling starting information
    for (auto a : *this->graphModel.at(S_point))
        if(a->roadType == OUTPUT) {
            vertexFactor1[a->vertex] = this->getWeight(a->edgeRoad->get_road_id(), cav);
            ways1[a->vertex].push_back(a->edgeRoad->get_road_id());
        }

    visitedVert1[S_point] = true;
    vertexFactor1[S_point] = 0;


    lli gSize = this->graphModel.size();

    for (int i = 1; i < gSize; i++) {

        lli nextVertex = -1;
        double minWeight =  std::numeric_limits<double>::max();


        // --------------------
        for (auto j = 0; j < gSize; j++) {
            if (!visitedVert1[j] && minWeight > vertexFactor1[j]) {
                minWeight = vertexFactor1[j];
                nextVertex = j;
            }
        }
        // Found the next vertex

        if(nextVertex == -1) break;

        visitedVert1[nextVertex] = true; //marking next vertex
        for (auto j = 0; j < this->graphModel[nextVertex]->size(); j++)
        {
            auto chEdge = this->graphModel[nextVertex]->at(j); // рассматириваемое ребро
            auto rID = chEdge->edgeRoad->get_road_id();        // and it's road

            if(vertexFactor1[chEdge->vertex] > vertexFactor1[nextVertex] + this->getWeight(rID, cav) && chEdge->roadType == OUTPUT) {
                vertexFactor1[chEdge->vertex] = vertexFactor1[nextVertex] + this->getWeight(rID, cav);
                ways1[chEdge->vertex].clear();
                ways1[chEdge->vertex] = ways1[nextVertex];
                ways1[chEdge->vertex].push_back(rID);
            }
        }

    }


    ///---==HardestWay==---
    double maxWeight = -1;
    lli hardestWay = -1;
    for(auto a : ways1[T_point])
        if(this->getWeight(a, cav) > maxWeight && this->getRoadptr(a)->get_priority() == 0)
            hardestWay = a;



    ///---====Deikstra2====---
    std::vector<bool> visitedVert2(this->graphModel.size()); //vector of visited Vertexes
    std::vector<double> vertexFactor2(this->graphModel.size());    //vector of vector numbers
    std::vector<std::vector<lli>> ways2(this->graphModel.size()); //vector of ways

    // cleaning space
    for (auto &&i : visitedVert2) i = false;
    for (auto &&a : vertexFactor2) a =  std::numeric_limits<double>::max();
    // --------------

    //filling starting information
    for (auto a : *this->graphModel.at(S_point))
        if(a->roadType == OUTPUT && a->edgeRoad->get_road_id() != hardestWay) {
            vertexFactor2[a->vertex] = this->getWeight(a->edgeRoad->get_road_id(), cav);
            ways2[a->vertex].push_back(a->edgeRoad->get_road_id());
        }

    visitedVert2[S_point] = true;
    vertexFactor2[S_point] = 0;


    lli gSize2 = this->graphModel.size();

    for (int i = 1; i < gSize2; i++) {

        lli nextVertex = -1;
        double minWeght =  std::numeric_limits<double>::max();


        // --------------------
        for (auto j = 0; j < gSize2; j++) {
            if (!visitedVert2[j] && minWeght > vertexFactor2[j]) { //TODO
                minWeght = vertexFactor2[j];
                nextVertex = j;
            }
        }
        // Found the next vertex

        if(nextVertex == -1) break;

        visitedVert2[nextVertex] = true; //marking next vertex
        for (auto j = 0; j < this->graphModel[nextVertex]->size(); j++)
        {
            auto chEdge = this->graphModel[nextVertex]->at(j); // рассматириваемое ребро
            auto rID = chEdge->edgeRoad->get_road_id();        // and it's road

            if(vertexFactor2[chEdge->vertex] > vertexFactor2[nextVertex] + this->getWeight(rID, cav)
                && chEdge->roadType == OUTPUT
                && rID != hardestWay) //ignoring the hardest way
            {
                vertexFactor2[chEdge->vertex] = vertexFactor2[nextVertex] + this->getWeight(rID, cav);
                ways2[chEdge->vertex].clear();
                ways2[chEdge->vertex] = ways2[nextVertex];
                ways2[chEdge->vertex].push_back(rID);
            }
        }

    }


    if(vertexFactor2[T_point] != std::numeric_limits<double>::max())
    {
        int a = random()/RAND_MAX;
        if (a > 0.5)
            return ways1[T_point];
        else
            return ways2[T_point];
    }else
        return ways1[T_point];


}

std::vector<lli> graph::possibleHomes() {
    vector<lli> output;

    for(auto vertex : this->graphModel)
    {
        int flag = 0;
        for(auto edge : *vertex) flag += edge->roadType == OUTPUT ? 0 : 1;

        if(flag == 0)
            for(auto edge : *vertex)
                output.push_back(edge->edgeRoad->get_road_id());
    }

    return output;
}





