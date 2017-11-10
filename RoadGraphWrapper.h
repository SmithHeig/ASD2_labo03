/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Wrapper.h
 * Author: Jeremie
 *
 * Created on 10. novembre 2017, 09:02
 */

#include "RoadNetwork.h"

#ifndef WRAPPER_H
#define WRAPPER_H


class RoadGraphWrapper{
    
private:
    // Type queue de priorite. MinPQ::top() retourne l'élément le plus petit.
    typedef std::priority_queue<Edge,std::vector<Edge>,std::greater<Edge>> MinPQ;
    typedef 
    Edge;
        
private:
    
    RoadNetwork *rn;
    MinPQ pq;
    
public:
    RoadGraphWrapper(RoadNetwork &rn) : rn(rn) {
    }
    
    int V();
    
    void forEachEdge(void (*f) (const Edge&));
    
    void forEachAdjacentEdge(int v, void (*f) (const Edge&));
    
    Edge roadToEdge(const RoadNetwork::Road rn);
    
    
};

#endif /* WRAPPER_H */

