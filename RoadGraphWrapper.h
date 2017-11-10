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
#include "EdgeWeightedGraphCommon.h"

#ifndef WRAPPER_H
#define WRAPPER_H

template <typename T, F>
class RoadGraphWrapper{

private:
    typedef RoadWrapper<F> Edge;
    RoadNetwork *rn;
    
public:
    RoadGraphWrapper(RoadNetwork &rn) : rn(rn) {
    }
    
    int V();
    
    void forEachEdge(void (*f) (const Edge&));
    
    void forEachAdjacentEdge(int v, void (*f) (const Edge&));    
};

#endif /* WRAPPER_H */

