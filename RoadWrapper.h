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

#ifndef ROADWRAPPER_H
#define ROADWRAPPER_H

#include "RoadNetwork.h"

template <F>
class RoadWrapper {
public:
    RoadWrapper(RoadNetwork::Road &r);
    RoadWrapper(const RoadWrapper& orig);
    virtual ~RoadWrapper();
private:
    RoadNetwork::Road &r;
    
    int From() { return r.cities.first; };
    int To() { return r.cities.second; };
    int Weight() { return F(&r); }
    
    

};

#endif /* ROADWRAPPER_H */

