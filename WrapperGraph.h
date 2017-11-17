///*
// * To change this license header, choose License Headers in Project Properties.
// * To change this template file, choose Tools | Templates
// * and open the template in the editor.
// */
//
///* 
// * File:   Wrapper.h
// * Author: Jeremie
// *
// * Created on 10. novembre 2017, 09:02
// */
//
//#include "RoadNetwork.h"
//
//#ifndef WRAPPER_H
//#define WRAPPER_H
//
//typedef RoadNetwork::Road Edge;
//
//class RoadGraphWrapper{
//    
//private:
//    // Type queue de priorite. MinPQ::top() retourne l'élément le plus petit.
//    //typedef std::priority_queue<Edge,std::vector<Edge>,std::greater<Edge>> MinPQ;
//    
//        
//private:
//    
//    RoadNetwork *rn;
//    
//public:
//    RoadGraphWrapper(RoadNetwork rn) : rn(&rn) {
//    }
//    
//    int V();
//    
//    void forEachEdge(void (*f) (const Edge&));
//    
//    void forEachAdjacentEdge(int v, void (*f) (const Edge&));
//    
//    Edge roadToEdge(const RoadNetwork::Road rn);
//    
//    
//};
//
//#endif /* WRAPPER_H */
//

/* 
 * File:   Wrapper.h
 * Author: Jeremie
 *
 * Created on 10. novembre 2017, 09:02
 */


#ifndef WRAPPERGRAPH_H
#define WRAPPERGRAPH_H

#include "RoadNetwork.h"
#include "WrapperDiRoad.h"

template <typename T, template<typename> class F>
class WrapperGraph{

private:
    typedef WrapperDiRoad<T,F> Edge;
    RoadNetwork *rn;
    
public:
    WrapperGraph(RoadNetwork *rn) : rn(rn) {};
    
    int V();
    
    void forEachEdge(void (*f) (const Edge&));
    
    void forEachAdjacentEdge(int v, void (*f) (const Edge&));    
};

#endif /* WRAPPERGRAPH_H */
