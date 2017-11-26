/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   WrapperRoadCommon.h
 * Author: James
 *
 * Created on 26. novembre 2017, 14:36
 */

#ifndef WRAPPERROADCOMMON_H
#define WRAPPERROADCOMMON_H

template <typename T>
class WrapperRoadCommon {
public:
    // Type de donnée pour les poids.
    typedef T WeightType;
    

public:
    RoadNetwork::Road& r;
    T (*f)(RoadNetwork::Road&);
    
public:  
    WrapperRoadCommon(){
        r = NULL;
    }
    // Constructeur spécifiant les deux sommets et le poids
    WrapperRoadCommon(RoadNetwork::Road &r, WeightType (*f)(const RoadNetwork::Road&)) : r(r), f(f) { }
    
    // renvoie la valeur du poids
    WeightType Weight() const { return f(r); }
    
    // opérations de comparaison entre edges en fonction de leur poids.
    inline bool operator< (const WrapperRoadCommon<T>& rhs) const { return Weight() < rhs.Weight(); }
    inline bool operator> (const WrapperRoadCommon<T>& rhs) const {return rhs < *this;}
    inline bool operator<=(const WrapperRoadCommon<T>& rhs) const {return !(*this > rhs);}
    inline bool operator>=(const WrapperRoadCommon<T>& rhs) const {return !(*this < rhs);}
};

#endif /* WRAPPERROADCOMMON_H */

