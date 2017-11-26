/* 
 * File:   WrapperDiGraph.h
 * Author: James Smith, Adrien Alleman et Jérémie Chatillon
 *
 * Created on 10. novembre 2017, 14:00
 * 
 * Permet de wrapper un EdgeWeightedDigraph (graph orienté)
 */

#ifndef WRAPPERDIGRAPH_H
#define WRAPPERDIGRAPH_H

#include "RoadNetwork.h"
#include "EdgeWeightedDigraph.h"

template <typename F>
class WrapperDiGraph {
private:
    RoadNetwork rn; // RoadNetwork wrapper
    F calculCout; // Type de la fonction permettant de calculer le cout
    
public:
    // Type queue de priorite. MinPQ::top() retourne l'élément le plus petit.
    //typedef std::priority_queue<Edge,std::vector<Edge>,std::greater<Edge>> MinPQ;
    typedef WeightedDirectedEdge<double> Edge;
    
    // Construction du Wrapper
    WrapperDiGraph(RoadNetwork& rn, F f): rn(rn), calculCout(f){}
    
    // retourne le nombre de sommet
    int V() const {
        return int(rn.cities.size());
    }
    
    // Permet d'appliquer une fonction f à tous les edges adjacent à v
    template<typename Func>
    void forEachAdjacentEdge(int v, Func f) const{
        for(int id_road : rn.cities.at(v).roads){
            RoadNetwork::Road r = rn.roads.at(id_road);
            f(Edge(r.cities.first,r.cities.second,calculCout(r)));   
        }
    };
    
    // Permet d'appliquer une fonction f à tous les sommets
    template<typename Func>
    void forEachVertex(Func f) const{
        for(int id_city = 0; id_city < rn.cities.size(); ++id_city){
            f(id_city);
        }
    }
};

#endif /* WRAPPERDIGRAPH_H */

