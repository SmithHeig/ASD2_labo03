/* 
 * File:   ShortestPath.h
 * Author: Olivier Cuisenaire
 *
 * Created on 5. novembre 2014, 10:16
 */

#ifndef ASD2_ShortestPath_h
#define ASD2_ShortestPath_h

#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <functional>
#include <list>


// Classe parente de toutes les classes de plus court chemin.
// Defini les membres edgeTo et distanceTo commun à toutes ces
// classes, ainsi que les methodes DistanceTo, EdgeTo et PathTo
// qui permettent de les interroger.
//
// Le calcul des plus courts chemins est fait dans les constructeurs
// des classes derivees.

template<typename GraphType>   // Type du graphe pondere oriente a traiter
							   // GraphType doit se comporter comme un
							   // EdgeWeightedDiGraph et definir le
							   // type GraphType::Edge
class ShortestPath {
public:
	// Type des arcs. Normalement ASD2::DirectedEdge<double>
	typedef typename GraphType::Edge Edge;
	
	// Type des poids. Normalement double ou int.
	typedef typename Edge::WeightType Weight;

	// Listes d'arcs et de poids
	typedef std::vector<Edge> Edges;
	typedef std::vector<Weight> Weights;

	// Renvoie la distance du chemin le plus court du sommet source a v
	Weight DistanceTo(int v) {
		return distanceTo.at(v);
	}
	
	// Renvoie le dernier arc u->v du chemin le plus court du sommet source a v
	Edge EdgeTo(int v) {
		return edgeTo.at(v);
	}
	
	// Renvoie la liste ordonnee des arcs constituant un chemin le plus court du
	// sommet source à v.
	Edges PathTo(int v) {
		/* A IMPLEMENTER */
	}

protected:
	Edges edgeTo;
	Weights distanceTo;
};

// Classe a mettre en oeuvre au labo 3. S'inspirer de BellmaFordSP pour l'API

template<typename GraphType>
class DijkstraSP : public ShortestPath<GraphType> {
public:
	typedef ShortestPath<GraphType> BASE;
	typedef typename BASE::Edge Edge;
	typedef typename BASE::Weight Weight;
        
        // Type queue de priorite. MinPQ::top() retourne l'élément le plus petit.
	typedef std::priority_queue<Edge,std::vector<Edge>,std::greater<Edge>> MinPQ;
        typedef std::pair<Edge,int> EdgeVertex;     // paire arc/sommet.
        
	DijkstraSP(const GraphType& g, int v)  {
            
            doDjikstra(g, v);
            
            
            /* to do*/
	}
        
        void doDjikstra(const GraphType& g, int v){
            
            std::priority_queue<EdgeVertex, Weight> q;
            
            
            Weight distTo[g.V()];
            Edge edgeTo[g.V()];
            
            distTo[v] = 0.0;
            g.forEachVertex(v, [&](const Edge& e){
                if( e != v){
                    distTo[e] = -1;
                    edgeTo[e] = NULL;
                }
                q.emplace(e, g.distTo(e));
            });
            
            
            int monSommet;
            while(!q.empty()){
                monSommet = q.top();
                q.pop();
                
                for(Edge e : g.adjacentEdges(monSommet)){
                    Weight dittThruE = distTo(v) + e.wheigt;
                    if(dittThruE < distTo(e.to()){
                        distTo[e.to()] = dittThruE;
                        edgeTo[e.to()] = e;
                    }
                    q.emplace(e.to(), distTo(e.to()));
                }
            }

            
            
            std::priority_queue<int, int> pq;
            g.forEachVertex(pq.push({}, -1));
            pq.emplace(v, 0);
            
            while(!pq.empty()){
                pq.pop();
                int *lanbI = pq.top();
                if(*lanbI == -1){
                    break;
                }
                g.forEachEdge(
                
            }
            
            size_t k = 0;
            bool hasToContinue = true;
            std::vector<int> sommetsWight;
            std::vector<int> parent(g.V(), -1);
            sommetsWight.resize(g.V(), -1);
            
            sommetsWight.at(v) = 0;
            
            while(k < g.V() && hasToContinue){
                
                hasToContinue = false;
                ++k;
                g.forEachEdge({
                    
                    
                    
                    
                    
                });
                
                
                
            }
            
            std::priority_queue<int> q;
            double distTo[g.V()];
            Edge Egges[g.V()];
            
            g.forEachVertex();
            
            
        }
        
        void funct modifier()
};

// Algorithme de BellmanFord.

template<typename GraphType> // Type du graphe pondere oriente a traiter
							 // GraphType doit se comporter comme un
							 // EdgeWeightedDiGraph et definir forEachEdge(Func),
							 // ainsi que le type GraphType::Edge. Ce dernier doit
							 // se comporter comme ASD2::DirectedEdge, c-a-dire definir From(),
							 // To() et Weight()

class BellmanFordSP : public ShortestPath<GraphType> {

private:
	typedef ShortestPath<GraphType> BASE;
	typedef typename BASE::Edge Edge;
	typedef typename BASE::Weight Weight;
	
	// Relachement de l'arc e
	void relax(const Edge& e) {
		int v = e.From(), w = e.To();
		Weight distThruE = this->distanceTo[v]+e.Weight();
		
		if(this->distanceTo[w] > distThruE) {
			this->distanceTo[w] = distThruE;
			this->edgeTo[w] = e;
		}
	}
	
public:
	
	// Constructeur a partir du graphe g et du sommet v a la source
	// des plus courts chemins
	BellmanFordSP(const GraphType& g, int v) {
		
		this->edgeTo.resize(g.V());
		this->distanceTo.assign(g.V(),std::numeric_limits<Weight>::max());

		this->edgeTo[v] = Edge(v,v,0);
		this->distanceTo[v] = 0;
		
		for(int i=0;i<g.V();++i)
			g.forEachEdge([this](const Edge& e){
				this->relax(e);
			});
	}
};


/* Fera l'objet d'un exercice de programmation
// Algorithme de BellmanFord avec queue simple reprenant les sommets ayant
// ete modifies par la derniere iteration.
template<typename GraphType> // Type du graphe pondere oriente a traiter
							 // GraphType doit se comporter comme un
							 // EdgeWeightedDiGraph et definir forEachAdjacentEdge(int,Func),
							 // ainsi que le type GraphType::Edge. Ce dernier doit
							 // se comporter comme ASD2::DirectedEdge, c-a-dire definir From(),
							 // To() et Weight()

class BellmanFordQueueSP : public ShortestPath<GraphType> {

private:
	typedef ShortestPath<GraphType> BASE;
	typedef typename BASE::Edge Edge;
	typedef typename BASE::Weight Weight;
	
public:
	BellmanFordQueueSP(const GraphType& g, int v) {
		
	}
};
*/

#endif
