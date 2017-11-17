<<<<<<< Updated upstream:RoadDigraphWrapper.h
///*
// * To change this license header, choose License Headers in Project Properties.
// * To change this template file, choose Tools | Templates
// * and open the template in the editor.
// */
//
///* 
// * File:   RoadDigraphWrapper.h
// * Author: James
// *
// * Created on 10. novembre 2017, 14:00
// */
//
//#ifndef ROADDIGRAPHWRAPPER_H
//#define ROADDIGRAPHWRAPPER_H
//
//class RoadDigraphWrapper{
//    
//private:
//    // Type queue de priorite. MinPQ::top() retourne l'élément le plus petit.
//    typedef std::priority_queue<Edge,std::vector<Edge>,std::greater<Edge>> MinPQ;
//    typedef RoadNetwork::Road Edge;
//        
//private:
//    
//    RoadNetwork *rn;
//    MinPQ pq;
//    
//public:
//    RoadGraphWrapper(RoadNetwork &rn) : rn(rn) {
//    }
//    
//    int V();
//    
//    void forEachEdge(void (*f) (const Edge&));
//    
//    void forEachAdjacentEdge(int v, void (*f) (const Edge&));
//    
//};
//
//#endif /* ROADDIGRAPHWRAPPER_H */
//
=======
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RoadDigraphWrapper.h
 * Author: James
 *
 * Created on 10. novembre 2017, 14:00
 */

#ifndef WRAPPERDIGRAPH_H
#define WRAPPERDIGRAPH_H

class WrapperDigraph{
    
private:
    // Type queue de priorite. MinPQ::top() retourne l'élément le plus petit.
    typedef std::priority_queue<Edge,std::vector<Edge>,std::greater<Edge>> MinPQ;
    typedef RoadNetwork::Road Edge;
        
private:
    
    RoadNetwork *rn;
    MinPQ pq;
    
public:
    WrapperDigraph(RoadNetwork &rn) : rn(rn) {
    }
    
    int V();
    
    void forEachEdge(void (*f) (const Edge&));
    
    void forEachAdjacentEdge(int v, void (*f) (const Edge&));
    
};

#endif /* WRAPPERDIGRAPH_H */

>>>>>>> Stashed changes:WrapperDigraph.h
