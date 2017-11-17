///*
// * To change this license header, choose License Headers in Project Properties.
// * To change this template file, choose Tools | Templates
// * and open the template in the editor.
// */
//
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
//#include "RoadGraphWrapper.h"
//
//    
//int RoadGraphWrapper::V(){
//    return rn.cities.size();
//}
//    
//void RoadGraphWrapper::forEachEdge(void (*f) (const Edge&)){
//    for(Edge &e : rn->roads){               // PAS SUR COPIE?
//        f(e);
//    }
//}
//    
//void RoadGraphWrapper::forEachAdjacentEdge(int v, void (*f) (const Edge&)){
//    for(Edge &e : rn->cities[v].roads){     // PAS SUR COPIE?
//        f(e);
//    }
//}
//
//Edge RoadGraphWrapper::roadToEdge(const RoadNetwork::Road rn){
//    
//}

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

#include "RoadGraphWrapper.h"

    
template< typename T>
int RoadGraphWrapper::V(){
    return rn.cities.size();
}
    
template< typename T>
void RoadGraphWrapper::forEachEdge(void (*f) (const Edge&)){
    for(RoadNetwork::Road &r : rn->roads){               // PAS SUR COPIE?
        f(roadToEdge(r));
    }
}
    
template< typename T>
void RoadGraphWrapper::forEachAdjacentEdge(int v, void (*f) (const Edge&)){
    for(RoadNetwork::Road &r : rn->cities[v].roads){     // PAS SUR COPIE?
        f(new Edge(r.cities.first, r.cities.second,));
    }
}

