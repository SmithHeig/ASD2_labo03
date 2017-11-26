/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RoadWrapper.h
 * Author: dname
 *
 * Created on November 10, 2017, 3:14 PM
 */

#ifndef WRAPPERDIROAD_H
#define WRAPPERDIROAD_H

#include "RoadNetwork.h"
#include <iostream>
#include "WrapperRoadCommon.h"

template <typename T>
class WrapperDiRoad : public WrapperRoadCommon<T>{
public :
	typedef T WeightType;
        typedef WrapperRoadCommon<T> BASE;
    
public:
    
    WrapperDiRoad(){
        BASE();
    };
    WrapperDiRoad(RoadNetwork::Road &r, WeightType (*f)(const RoadNetwork::Road&)){
        BASE(r,f);
    }
    
    /*WrapperDiRoad(const WrapperRoadCommon<T>& orig){
        BASE(orig.r, orig.f);
    }*/
    /*
    WrapperDiRoad(const WrapperDiRoad& orig) {
        BASE(orig.BASE::r, orig.BASE::f);
    }
    */
    virtual ~WrapperDiRoad();
    
    int From() const { return BASE::r->cities.first; };
    int To() const { return BASE::r->cities.second; };
    WeightType Weight() const { return BASE::f(BASE::r); };
    
    // Affiche "v1->v2 (weight)"
    friend std::ostream& operator << (std::ostream& s, const WrapperDiRoad& r) {
            return s << r.From() << "->" << r.To() << " (" << r.Weight() << ")";
    }

};

#endif /* WRAPPERDIROAD_H */

