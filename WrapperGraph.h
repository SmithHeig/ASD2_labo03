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

#include "RoadNetwork.h"
#include "EdgeWeightedGraph.h"
#include "EdgeWeightedDigraph.h"

#ifndef WRAPPERGRAPH_H
#define WRAPPERGRAPH_H

template <typename F>
class WrapperGraph {
private:
    RoadNetwork rn;
    F calculeCout;
    
public:
    // Type queue de priorite. MinPQ::top() retourne l'élément le plus petit.
    //typedef std::priority_queue<Edge,std::vector<Edge>,std::greater<Edge>> MinPQ;
    typedef WeightedEdge<double> Edge;
    
    
    WrapperGraph(const RoadNetwork& rn, F f): rn(rn), calculeCout(f){}
    
    int V() const {
        return int(rn.cities.size());
    }
    
    template<typename Func>
    void forEachEdge(Func f) const{
        for(RoadNetwork::Road r : rn.roads){
            Edge temp(r.cities.first,r.cities.second,calculeCout(r));
            f(temp);
        }
    }
};

#endif /* WRAPPERGRAPH_H */

