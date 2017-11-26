/* 
 * File:   RoadDigraphWrapper.h
 * Author: James Smith, Adrien Alleman et Jérémie Chatillon
 *
 * Created on 10. novembre 2017, 14:00
 * 
 * Permet de Wrapper un  EdgeWeightedGraph (graph non-orienté)
 */

#include "RoadNetwork.h"
#include "EdgeWeightedGraph.h"
#include "EdgeWeightedDigraph.h"

#ifndef WRAPPERGRAPH_H
#define WRAPPERGRAPH_H

template <typename F>
class WrapperGraph {
private:
    RoadNetwork rn; // RoadNetwork wrapper
    F calculeCout; // Type de la fonction permettant de calculer le cout
    
public:
    // Type queue de priorite. MinPQ::top() retourne l'élément le plus petit.
    //typedef std::priority_queue<Edge,std::vector<Edge>,std::greater<Edge>> MinPQ;
    typedef WeightedEdge<double> Edge;
    
    // Constructeur du wrapper
    WrapperGraph(const RoadNetwork& rn, F f): rn(rn), calculeCout(f){}
    
    // nombre de sommet du graph
    int V() const {
        return int(rn.cities.size());
    }
    
    // permet d'appliquer la fonction f à tous les aretes (Edge) du graph
    template<typename Func>
    void forEachEdge(Func f) const{
        for(RoadNetwork::Road r : rn.roads){
            Edge temp(r.cities.first,r.cities.second,calculeCout(r));
            f(temp);
        }
    }
};

#endif /* WRAPPERGRAPH_H */

