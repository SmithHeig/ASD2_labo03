/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   WrapperRoad.h
 * Author: James
 *
 * Created on 26. novembre 2017, 14:31
 */

#ifndef WRAPPERROAD_H
#define WRAPPERROAD_H

#include "RoadNetwork.h"
#include <iostream>
#include "WrapperRoadCommon.h"

template <typename T>
class WrapperRoad : public WrapperRoadCommon<T>{
    
public:
    typedef WrapperRoadCommon<T> BASE;
    
    WrapperRoad(){
        BASE();
    };
    
    WrapperRoad(RoadNetwork::Road &r, T (*f)(const RoadNetwork::Road&)) {
        BASE(r,f);
    }
    
    WrapperRoad(const WrapperRoad& orig){
        BASE(orig.r,orig.f);
    }
    virtual ~WrapperRoad();
    
    int Either() const { return BASE::r->cities.first; };
    int Other(int v) const { return (v == BASE::r->cities.first) ? BASE::r->cities.second : BASE::r->cities.first; };
    
    // Affiche "v1->v2 (weight)"
    friend std::ostream& operator << (std::ostream& s, const WrapperRoad& r) {
            return s << r.Either() << "->" << r.Other(r.Either()) << " (" << r.Weight() << ")";
    }

};

#endif /* WRAPPERROAD_H */

