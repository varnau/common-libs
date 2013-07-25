#ifndef _GRAPH_BARABASI_H_
#define _GRAPH_BARABASI_H_

#include "graph.h"
#include <gsl/gsl_rng.h>
#include <gsl/gsl_randist.h>

//--> you can used 1 billion of vertex: "vnumber" number=[1..10Gnodes[
#define  MAX_CHAR_VERTEX 12

graph_t* graph_generate_ergdos_renyi_V1(int m0, float p, int sync_mode, enum EdgeType edgetype);
// Gerated a random graph, an Ergdos-Remyi Graph.
// m0: number of vertices. m0 = [2, 9.000.000.000] 
// p : conectivity between vertices. p=[0, 1]


graph_t* graph_generate_barabasi(int m0, float p, int t, float m, int sync_mode, enum EdgeType edgetype);
// Gerated a Barabai-Albert random Graph.
// m0: number of initial vertices. m0 
// p : conectivity between m0 vertices. p=[0, 1]
// t : number of vertices to add
// m : conectivity of the each new vertex t. m=[0.0 ... m0]

#endif //_GRAPH_BARABASI_H_

