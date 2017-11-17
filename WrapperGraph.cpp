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

#include "WrapperGraph.h"
#include "WrapperDiRoad.h"

template <typename T, template<typename> class F>
int WrapperGraph<T,F>::V(){
    return rn->cities.size();
}

template <typename T, template<typename> class F>
void WrapperGraph<T,F>::forEachEdge(void (*f) (const Edge&)){
    for(WrapperDiRoad<T,F> &r : rn->roads){               // PAS SUR COPIE?
        f(WrapperDiRoad<T,F>(r));
    }
}

template <typename T, template<typename> class F>
void WrapperGraph<T,F>::forEachAdjacentEdge(int v, void (*f) (const Edge&)){
    for(WrapperDiRoad<T,F> &r : rn->cities[v].roads){     // PAS SUR COPIE?
        f(WrapperDiRoad<T,F>(r));
    }
}

