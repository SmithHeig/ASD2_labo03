/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RoadDigraphWrapper.h
 * Author: James
 *
 * Created on 10. novembre 2017, 14:00
 */

#ifndef WRAPPERDIGRAPH_H
#define WRAPPERDIGRAPH_H

#include "RoadNetwork.h"
#include "EdgeWeightedDigraph.h"

template <typename F>
class WrapperDiGraph {
private:
    RoadNetwork rn;
    F calculCout;
    
public:
    // Type queue de priorite. MinPQ::top() retourne l'élément le plus petit.
    //typedef std::priority_queue<Edge,std::vector<Edge>,std::greater<Edge>> MinPQ;
    typedef WeightedDirectedEdge<double> Edge;
    
    
    WrapperDiGraph(RoadNetwork& rn, F f): rn(rn), calculCout(f){}
    
    int V() const {
        return int(rn.cities.size());
    }
    
    //  void (*func) (const Edge&)
    template<typename Func>
    void forEachAdjacentEdge(int v, Func f) const{
        for(int id_road : rn.cities.at(v).roads){
            RoadNetwork::Road r = rn.roads.at(id_road);
            f(Edge(r.cities.first,r.cities.second,calculCout(r)));   
        }
    };
    
    template<typename Func>
    void forEachVertex(Func f) const{
        for(int id_city = 0; id_city < rn.cities.size(); ++id_city){
            f(id_city);
        }
    }
};

#endif /* WRAPPERDIGRAPH_H */

