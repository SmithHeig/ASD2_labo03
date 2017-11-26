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
            //vecteur a retourner
            Edges pathTo;
            
            Edge e = edgeTo.at(v);
            
            while(e.From() != e.To()){
                pathTo.push_back(e);
                e = edgeTo.at(e.From());
            }
            
            std::reverse(pathTo.begin(), pathTo.end()); 
            
            return pathTo;
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
            std::set<std::pair<Weight,int>> processList;
            BASE::distanceTo.resize(g.V());
            BASE::edgeTo.resize(g.V());
            
            for(int i = 0; i < g.V(); ++i){
                this->distanceTo.at(i) = std::numeric_limits<Weight>::max();
            }
            
            this->distanceTo.at(v) = 0;
            this->edgeTo.at(v) = Edge(v,v,0);
            
            g.forEachVertex([&](const int tmpV){               
                processList.insert(std::make_pair(this->distanceTo[tmpV], tmpV));
            });
            
            //this->distanceTo.at(v) = 0;
            
            
            while(!processList.empty()){
                // Extract min
                int vToProcess = processList.begin()->second;
                processList.erase(processList.begin());
                
                //std::cout << "V" << vToProcess << ": " << this->DistanceTo(vToProcess) << "\n";
                
                g.forEachAdjacentEdge(vToProcess, [&](const Edge& e){
                    
                    Weight dist = this->distanceTo.at(e.From()) + e.Weight();
                    //std::cout << "this->distanceTo.at(vToProcess) + e.Weight(): " << this->distanceTo.at(vToProcess) + e.Weight() << "\n";
                    if(dist < this->distanceTo.at(e.To())){
                        processList.erase(processList.find(std::make_pair(this->distanceTo.at(e.To()), e.To())));
                        this->distanceTo.at(e.To()) = dist;
                        this->edgeTo.at(e.To()) = e;
                        processList.insert(std::make_pair(dist, e.To()));                        
                    }
                });
            }
            
            /*
            BASE::distanceTo.resize(g.V());
            BASE::edgeTo.resize(g.V());
            BASE::distanceTo.at(v) = 0;
            std::set<std::pair<Weight,int>> processList;
            
            for(int i = 0; i < g.V(); ++i){
                BASE::distanceTo.at(i) = std::numeric_limits<Weight>::max();
            }
            
            BASE::edgeTo.at(v) = Edge(v, v, 0);
            
            BASE::distanceTo.at(v) = 0;
            processList.insert(std::make_pair(BASE::distanceTo.at(v), v));
            while(!processList.empty()){
                int vToProcess = processList.begin()->second;
                
                if(processList.size() == 1){
                    processList.clear();
                } else {
                    processList.erase(processList.begin()); // Supprime l'élément traité
                }
                
                g.forEachAdjacentEdge(vToProcess, [&](const Edge& e){
                    
                    
                    if(this->distanceTo.at(e.To()) > this->distanceTo.at(e.From()) + e.Weight()){
                        
                        if(this->distanceTo.at(e.To()) != std::numeric_limits<Weight>::max()){
                            processList.erase(processList.find(std::make_pair(BASE::distanceTo.at(e.To()), e.To())));
                        }
                        this->distanceTo.at(e.To()) = this->distanceTo.at(vToProcess) + e.Weight();
                        processList.insert(std::make_pair(this->distanceTo.at(e.From()), e.To()));
                        
                        this->edgeTo.at(e.To()) = e;
                    }
                });
                
            }
            */
            
            
            /* to do*/
	}
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
