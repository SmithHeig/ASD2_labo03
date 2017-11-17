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

template <typename T, template<typename> class F>
class WrapperDiRoad {
private:
    RoadNetwork::Road &r;
public:
    WrapperDiRoad(RoadNetwork::Road &r) : r(r) {};
    WrapperDiRoad(const WrapperDiRoad& orig) : r(orig.r){};
    virtual ~WrapperDiRoad();
    
    int From() { return r.cities.first; };
    int To() { return r.cities.second; };
    T Weight() { return F<T>(&r); }
    
    // Affiche "v1->v2 (weight)"
    friend std::ostream& operator << (std::ostream& s, const WrapperDiRoad& r) {
            return s << r.From() << "->" << r.To() << " (" << r.Weight() << ")";
    }

};

#endif /* WRAPPERDIROAD_H */

