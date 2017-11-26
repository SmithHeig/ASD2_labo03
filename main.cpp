


///--------------------------------------------------------

/* 
 * File:   main.cpp
 * ASD 2 - Labo 3
 * Author: Olivier Cuisenaire
 *
 * Created on 18. novembre 2014, 14:58
 */

#include <cstdlib>
#include <iostream>
#include <ctime>

#include "RoadNetwork.h"
#include "MinimumSpanningTree.h"
#include "ShortestPath.h"

#include "EdgeWeightedGraph.h"
#include "EdgeWeightedDiGraph.h"

#include "WrapperDiGraph.h"
#include "WrapperGraph.h"

using namespace std;

// Calcule et affiche le plus court chemin de la ville depart a la ville arrivee
// en passant par le reseau routier rn. Le critere a optimiser est la distance.

#define HIGHWAY_SPEED 120.0
#define NORMAL_ROAD_SPEED 70.0
#define HIGHWAY_RENOVATION_PRICE 15.0      // IN MILLIONS
#define NORMAL_ROAD_RENOVATION_PRICE 7.0   // IN MILLIONS

typedef WeightedDirectedEdge<double> DiEdge;


double LengthToWeight(const RoadNetwork::Road &r){
    return r.length;
}

// Calcule et affiche le plus court chemin de la ville depart a la ville arrivee
// en passant par le reseau routier rn. Le critere a optimiser est la distance.

void PlusCourtChemin(const string& depart, const string& arrivee, RoadNetwork& rn) {   
   
   const int DEP = rn.cityIdx.at(depart);
   const int DEST = rn.cityIdx.at(arrivee);
   
   WrapperDiGraph<double (*)(const RoadNetwork::Road&)> wdg(rn, LengthToWeight);
   
   DijkstraSP<WrapperDiGraph<double (*)(const RoadNetwork::Road&)>> dsp(wdg, DEP);
   
   cout << "Longeur de chemin le plus court de " << depart << " a " << arrivee << ": " << dsp.DistanceTo(DEST) << "\n";
    cout << "Route: ";
    
    for(WeightedDirectedEdge<double> e : dsp.PathTo(DEST)){
        cout << rn.cities.at(e.From()).name << " -> ";
    }
    cout << arrivee << endl;
}

// Calcule et affiche le plus rapide chemin de la ville depart a la ville arrivee via la ville "via"
// en passant par le reseau routier rn. Le critere a optimiser est le temps de parcours
// sachant que l'on roule a 120km/h sur autoroute et 70km/h sur route normale.

double TimeToWeight(const RoadNetwork::Road &r){
    return (r.length * r.motorway.Value() / HIGHWAY_SPEED) + (r.length * (1 - r.motorway.Value()) / NORMAL_ROAD_SPEED);
}
void PlusRapideChemin(const string& depart, const string& arrivee, const string& via, RoadNetwork& rn) {
    /* A IMPLEMENTER */
    const int s = rn.cityIdx.at(depart);
    const int t = rn.cityIdx.at(arrivee);
    const int p = rn.cityIdx.at(via);
    
    WrapperDiGraph<double (*)(const RoadNetwork::Road&)> wdg(rn, TimeToWeight);
    DijkstraSP<WrapperDiGraph<double (*)(const RoadNetwork::Road&)>> dsp1(wdg, s);
    
    DijkstraSP<WrapperDiGraph<double (*)(const RoadNetwork::Road&)>> dsp2(wdg, p);
    
    cout << "Temps pris pour aller de " << depart << " a " << arrivee << " via " << via << ": " << dsp1.DistanceTo(p) + dsp2.DistanceTo(t) << "\n";
    cout << "Route: ";
    
    for(WeightedDirectedEdge<double> e : dsp1.PathTo(p)){
        cout << rn.cities.at(e.From()).name << " -> ";
    }
    for(WeightedDirectedEdge<double> e : dsp2.PathTo(t)){
        cout << rn.cities.at(e.From()).name << " -> ";
    }
    cout << arrivee << endl;
    
}

// Calcule et affiche le plus reseau a renover couvrant toutes les villes le moins
// cher, en sachant que renover 1km d'autoroute coute 15 MF, et renover 1km de route normale
// coute 7 MF.

double CheapestToWeight(const RoadNetwork::Road &r) {
    return (r.length * r.motorway.Value() * HIGHWAY_RENOVATION_PRICE) + (r.length * (1 - r.motorway.Value()) * NORMAL_ROAD_RENOVATION_PRICE);
}
void ReseauLeMoinsCher(RoadNetwork &rn) {
    
    WrapperGraph<double (*)(const RoadNetwork::Road&)> wg(rn, CheapestToWeight);
    
    std::vector<WeightedEdge<double>> vwe = MinimumSpanningTree<WrapperGraph<double (*)(const RoadNetwork::Road&)>>::Kruskal(wg);
    
    double price = 0;
    for(WeightedEdge<double> e : vwe){
        std::cout << " de " << rn.cities.at(e.Either()).name << " a " << rn.cities.at(e.Other(e.Either())).name << " pour " << e.Weight() << " Millions CHF" << std::endl;
        price += e.Weight();
    }
    
    std::cout << " PRICE TOTAL : " << price << endl;
    
}

// compare les algorithmes Dijkstra et BellmanFord pour calculer les plus courts chemins au
// sommet 0 dans le graphe defini par filename.
// a utiliser pour tester votre implementation de Dijkstra

void testShortestPath(string filename)
{
    cout << "Testing " << filename << endl;
    
    bool ok = true;
    
    typedef EdgeWeightedDiGraph<double> Graph;
    Graph ewd(filename);
    
    cout<< "WSD>ASD1" <<endl;
    
    clock_t startTime = clock();

    BellmanFordSP<Graph> referenceSP(ewd,0);
    
    cout << "Bellman-Ford: " << double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
    startTime = clock();

    DijkstraSP<Graph> testSP(ewd,0);
    
    cout << "Dijkstra:     " << double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
     
    for (int v=0; v<ewd.V(); ++v) {
        if (referenceSP.DistanceTo(v) != testSP.DistanceTo(v) ) {
            cout << "Oops: vertex " << v << " has " << referenceSP.DistanceTo(v) << " != " <<  testSP.DistanceTo(v) << endl;
            ok = false;
            break;
        }
    }
    

    testSP.PathTo(6);
    
    if(ok) cout << " ... test succeeded " << endl << endl;
}

int main(int argc, const char * argv[]) {
    /*
    testShortestPath("tinyEWD.txt");
    testShortestPath("mediumEWD.txt");
    testShortestPath("1000EWD.txt");
    testShortestPath("10000EWD.txt");
    */
    RoadNetwork rn("reseau.txt");
    
    cout << "1. Chemin le plus court entre Geneve et Emmen" << endl;
    
    PlusCourtChemin("Geneve", "Emmen", rn);
    
    cout << endl << "2. Chemin le plus court entre Lausanne et Bale" << endl;
    
    PlusCourtChemin("Lausanne", "Basel", rn);
  
    cout << endl << "3. chemin le plus rapide entre Geneve et Emmen en passant par Yverdon" << endl;
    
    PlusRapideChemin("Geneve", "Emmen", "Yverdon-Les-Bains", rn);
    
    cout << endl << "4. chemin le plus rapide entre Geneve et Emmen en passant par Vevey" << endl;
    
    PlusRapideChemin("Geneve", "Emmen", "Vevey", rn);

    cout << endl << "5. Quelles routes doivent etre renovees ? Quel sera le cout de la renovation de ces routes ?" << endl;
    
    ReseauLeMoinsCher(rn);
    
    return EXIT_SUCCESS;
}
