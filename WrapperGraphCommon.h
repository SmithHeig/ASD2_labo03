/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RoadGraphWrapperCommon.h
 * Author: James
 *
 * Created on 10. novembre 2017, 14:04
 */

#ifndef WRAPPERGRAPHCOMMON_H
#define WRAPPERGRAPHCOMMON_H

#include "RoadNetwork.h"
#include "WrapperRoad.h"

template<typename F>
class WrapperGraphCommon{
protected:
    RoadNetwork &rn;
    F calculeCout;
    
    typedef RoadNetwork::City City;
    typedef RoadNetwork::Road Edge;
    
public:
    WrapperGraphCommon(){}
    WrapperGraphCommon(RoadNetwork& rn, F f){
        this->rn = rn;
        this->calculeCout = f;
    }

    //TO check
    int V() const {
        return int(rn.cities.size());
    }

    // TO DO
    template<typename Func>
    void forEachAdjacentEdge(int v, Func f) const  {
         for(int id_road : rn.cities.at(v).roads){
             
            f(WrapperRoad<double>(&(rn.roads.at(id_road)), calculeCout));
         }
    }

    template<typename Func>
    void forEachVertex(Func f) const  {
        for(City c : rn.cities){
            f(rn.cityIdx.at(c.name));
        }
    }

};


#endif /* ROADGRAPHWRAPPERCOMMON_H */
