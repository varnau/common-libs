
/**
 * @file graph.h
 *
 * Generic graph data structure with handling and algorithms functions 
 *
 */
/*
 * Podemos dar la opcion a cambiar el tipo de grafo despues de crearlo,
 * es decir, si se permite el cambio automatico/manual de modo de grafo "si" "no" "depende"
 * 
 * 
 * //typedef int vertex_id; ??
 *
 * 
 * TODO:
 * 		Darle coherencia
 * 		Correcto sincronismo (sync_mode)
 * 		doc
 * 
 * DUDAS:
 */

#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <float.h>
#include "linked_list.h"
#include "array_list.h"
#include "containers.h"
#include "khash.h"
#include "heap.h"

KHASH_MAP_INIT_STR(gr,int)
KHASH_MAP_INIT_INT(ii,int)


typedef struct edge {
    int src_id;
    int dst_id;
    void *data;
    float weight;
    //char* name;
    
} edge_t;

typedef int vertex_id_t;

typedef struct vertex {
    void *data;
    linked_list_t *src;
    linked_list_t *dst;
    linked_list_t *nd;
    char* name;
    vertex_id_t id;
} vertex_t;

typedef struct graph_stats{
    char valid;
    
    int *grade;
    float mean_grade;
    
    int * betweenness;
    int *max_jumps; 
    float *max_w;
    
    int   max_jumps_graph;
    float max_w_graph;
} graph_stats_t;

typedef struct graph {
    khash_t(gr) *dict;
    array_list_t *vertices;
    linked_list_t *removed_vertices;
    int num_vertices;	//()
    int num_edges;		//()
    
    short int directed;	//si, no y mixto
    short int cyclic;
    short int multiple;
    short int strict;
    short int non_negative;
    //reemplazar todo por una mascara?
    
    graph_stats_t stats;
    
    int sync_mode;
} graph_t;


typedef struct graph_path{
    float distance;
    int father;
} graph_path_t;

#define GRAPH_MAX_NAME_LENGTH 256

/// Wether an edge allows leaving a vertex, or reaching a vertex.
enum EdgeDirection {GRAPH_EDGE_IN = 1, GRAPH_EDGE_OUT = 2, GRAPH_EDGE_IN_OUT = 3};

/// Wether an edge has directionality or not.
enum EdgeType {GRAPH_EDGE_DIRECTED = 1, GRAPH_EDGE_NON_DIRECTED = 2, GRAPH_EDGE_ALL = 3};

/// Features of the graph, expressed in a mask.
enum GraphType {
    GRAPH_NON_DIRECTED			= 0b00000001,
    GRAPH_DIRECTED				= 0b00000010,
    GRAPH_MIXED_DIRECTED		= 0b00000011,
    GRAPH_CYCLIC				= 0b00000000,
    GRAPH_ACYCLIC				= 0b00000100,
    GRAPH_STRICT				= 0b00001000,
    GRAPH_NON_NEGATIVE_WEIGHT	= 0b00010000
    //GRAPH_MULTIPLE			0b00010000
};

///Plot Types
enum Plot_Type {PLOT_GRADE, PLOT_BETWEENNESS, PLOT_JUMPS};

/**
 * Creation and initialization
 */
graph_t* graph_new(enum GraphType mask, int initial_num_vertices, int SYNC_MODE);

/**
 * Destruction
 */

int graph_free(void (*vertex_data_callback) (void* vertex_data), void (*edge_data_callback) (void* edge_data), graph_t*);

int graph_clear(void (*vertex_data_callback) (void* vertex_data), void (*edge_data_callback) (void* edge_data), graph_t*);

/**
 * Vertex Functions
 */
int graph_add_vertex(char* name, void* vertex_data, graph_t*);

int graph_find_vertex(char* name, graph_t*);	// assumes only one ocurrence

int graph_exists_vertex_s(char* name, graph_t*);
int graph_exists_vertex_i(int id, graph_t*);
//contains??

int graph_reachable_vertex(int src, int dst, graph_t*);

vertex_t* graph_get_vertex_s(char* vertex_name, graph_t * graph_p);
vertex_t* graph_get_vertex_i(int vertex_id, graph_t * graph_p);

void* graph_get_vertex_data_s(char* name, graph_t*);
void* graph_get_vertex_data_i(int id, graph_t*);



linked_list_t* graph_get_neighborhood_v(vertex_t* vertex_p, enum EdgeDirection edge_type, int k_jumps, graph_t*);
linked_list_t* graph_get_neighborhood_s(char* name, enum EdgeDirection edge_type, int k_jumps, graph_t*);
linked_list_t* graph_get_neighborhood_i(int vertex_id, enum EdgeDirection edge_type, int k_jumps, graph_t*);

linked_list_t* graph_get_adjacents_v(vertex_t* vertex_p, graph_t*);
linked_list_t* graph_get_adjacents_s(char* name, graph_t*);
linked_list_t* graph_get_adjacents_i(int id, graph_t*);

/*
linked_list_t* graph_vertex_neighborhood_s(char* name, graph_t*);
linked_list_t* graph_vertex_neighborhood_i(int id, graph_t*);

linked_list_t* graph_vertex_neighborhood_out_s(char* name, graph_t*);
linked_list_t* graph_vertex_neighborhood_out_i(int id, graph_t*);

linked_list_t* graph_vertex_neighborhood_in_s(char* name, graph_t*);
linked_list_t* graph_vertex_neighborhood_in_i(int id, graph_t*);
//adjacent

linked_list_t* graph_vertex_adjacents_s(char* name, graph_t*);
linked_list_t* graph_vertex_adjacents_i(int id, graph_t*);

linked_list_t* graph_vertex_adjacents_out_s(char* name, graph_t*);
linked_list_t* graph_vertex_adjacents_out_i(int id, graph_t*);

linked_list_t* graph_vertex_adjacents_in_s(char* name, graph_t*);
linked_list_t* graph_vertex_adjacents_in_i(int id, graph_t*);
*/

int graph_remove_vertex_s(char* vertex_name, void (*vertex_data_callback) (void* vertex_data),void (*edge_data_callback) (void* edge_data), graph_t*);
int graph_remove_vertex_i(int vertex_id, void (*vertex_data_callback) (void* vertex_data),void (*edge_data_callback) (void* edge_data), graph_t*);


/**
 * Edge Functions
 */
int graph_add_edge_s(char* src, char* dst, void* edge_data, enum EdgeType edge_type, graph_t*);
int graph_add_edge_i(int src, int dst, void* edge_data, enum EdgeType edge_type, graph_t*);
int graph_add_edge_sw(char* src, char* dst, void* edge_data, enum EdgeType edge_type, float weight, graph_t*);
int graph_add_edge_iw(int src, int dst, void* edge_data, enum EdgeType edge_type, float weight, graph_t*);

int graph_remove_edge_s(char* src, char* dst, enum EdgeType edge_type, void (*edge_data_callback) (void* edge_data), graph_t*);
int graph_remove_edge_i(int src, int dst, enum EdgeType edge_type, void (*edge_data_callback) (void* edge_data), graph_t*);
int graph_remove_edge_e(edge_t *edge_p, enum EdgeType edge_type, void (*edge_data_callback) (void* edge_data), graph_t*);

edge_t* graph_get_edge_s(char* src, char* dst, enum EdgeType edge_type, graph_t*);
edge_t* graph_get_edge_i(int src, int dst, enum EdgeType edge_type, graph_t*);
edge_t* graph_get_edge_v(vertex_t* v_src, vertex_t* v_dst, enum EdgeType edge_type, graph_t*);

/**
 * Path Functions
 */
//linked_list_t* graph_path_get(int src, int dst, graph_t*);

/**
 * Others
 */
void graph_print(graph_t*);	
void graph_print_dot(char* file_name, graph_t*);
void graph_print_dot_w(char* file_name, graph_t*);
int graph_get_order (graph_t*);	// vertex number
int graph_get_size (graph_t*);	// edge number

/**
 * Profiling
 */

int graph_vertex_grade_s(char* vertex_name, enum EdgeDirection edge_type, graph_t*);
int graph_vertex_grade_i(int vertex_id, enum EdgeDirection edge_type, graph_t*);
int graph_vertex_grade_v(vertex_t* v, enum EdgeDirection edge_type, graph_t*);

float graph_vertex_clustering_coefficient_s(char* vertex_name, enum EdgeDirection edge_type, graph_t*);
float graph_vertex_clustering_coefficient_i(int vertex_id, enum EdgeDirection edge_type, graph_t*);
float graph_vertex_clustering_coefficient_v(vertex_t* v, enum EdgeDirection edge_type, graph_t*);
float graph_clustering_coefficient(enum EdgeDirection edge_type, graph_t*);     //FIXME


void graph_plot(char* filename, enum Plot_Type, graph_t*);

graph_path_t * graph_run_dijkstra (vertex_t *orig, enum EdgeType edge_type, graph_t * graph_p);

void graph_run_path_stats(graph_t *graph_p);
void graph_run_grade_stats(graph_t *graph_p);

#endif //_GRAPH_H_
