#include "graph.h"


/**
 * Creation and initialization
 */
graph_t* graph_new(char mask, int initial_num_vertices, int SYNC_MODE)
{
    graph_t *g = (graph_t*)malloc(sizeof(graph_t));
    
    if((mask & GRAPH_MIXED_DIRECTED) == GRAPH_MIXED_DIRECTED)
        g->directed = GRAPH_MIXED_DIRECTED;
    else if(mask & GRAPH_DIRECTED)
        g->directed = GRAPH_DIRECTED;
    else
        g->directed = GRAPH_NON_DIRECTED;	//default value
    
    g->cyclic = (mask & GRAPH_ACYCLIC)? 0: 1;
    //g->multiple = (mask & GRAPH_MULTIPLE)? 1: 0;
    g->multiple = 0;
    g->strict = mask & GRAPH_STRICT;
    g->non_negative = mask & GRAPH_NON_NEGATIVE_WEIGHT;
    
    g->num_edges = 0;
    g->num_vertices = 0;
    
    g->sync_mode = SYNC_MODE;
    g->vertices = array_list_new(initial_num_vertices,1.5,SYNC_MODE);
    g->removed_vertices = linked_list_new (SYNC_MODE);
    g->dict = kh_init(gr);
    
    return g;
    
}
/**
 * Destruction
 */

int graph_free(void (*vertex_data_callback) (void* vertex_data), void (*edge_data_callback) (void* edge_data), graph_t* graph_p)
{
    assert(graph_p);
    graph_clear(vertex_data_callback,edge_data_callback,graph_p);
    array_list_free(graph_p->vertices, NULL);
    linked_list_free(graph_p->removed_vertices, NULL);
    kh_destroy(gr, graph_p->dict);
    free(graph_p);
}


int graph_clear(void (*vertex_data_callback) (void* vertex_data), void (*edge_data_callback) (void* edge_data), graph_t* graph_p)
{
    assert(graph_p);
    int i;
    vertex_t *v;
    edge_t* e;
    linked_list_iterator_t *iter;
    
    if(graph_p->num_vertices)
        iter = (linked_list_iterator_t *)malloc(sizeof(linked_list_iterator_t));
    
    for (i = 0; i < graph_p->num_vertices; i++)
    {
        
        v = (vertex_t*)array_list_get(i, graph_p->vertices);
        if(v->src == NULL){
            free(v);
            continue;
        }
        if(edge_data_callback)
        {
            iter = linked_list_iterator_init(v->dst, iter);	// free dst data
            e = (edge_t*) linked_list_iterator_curr(iter);
            
            while (e != NULL)
            {
                edge_data_callback(e->data);
                e = (edge_t*)linked_list_iterator_next(iter);
            }
            
            
            iter = linked_list_iterator_init(v->nd, iter);	// free nd data and edge (only when e->src_id==-1, else sets to -1)
            e = (edge_t*) linked_list_iterator_curr(iter);
            while (e != NULL)
            {
                if(e->src_id != -1)
                    e->src_id = -1;
                else{
                    edge_data_callback(e->data);
                    free(e);
                }
                e = (edge_t*)linked_list_iterator_next(iter);
                
            }
        }
        else
        {
            iter = linked_list_iterator_init(v->nd, iter); // free nd edge (only when e->src_id==-1, else sets to -1)
            e = (edge_t*) linked_list_iterator_curr(iter);
            while (e != NULL)
            {
                if(e->src_id != -1)
                    e->src_id = -1;
                else
                    free(e);
                
                e = (edge_t*)linked_list_iterator_next(iter);
            }
        }
        
        linked_list_free(v->src, NULL);
        linked_list_free(v->dst, free);	// free dst edge
        linked_list_free(v->nd, NULL);
        
        free(v->name);
        if(vertex_data_callback)
            vertex_data_callback(v->data);
            
        free(v);
    
        
    }
    if(graph_p->num_vertices)
        linked_list_iterator_free(iter);
    array_list_clear(graph_p->vertices, NULL);
    linked_list_clear(graph_p->removed_vertices, NULL);
    
    kh_clear(gr, graph_p->dict);
    graph_p->num_edges = 0;
    graph_p->num_vertices = 0;

}

/**
 * Vertex Functions
 */
 

int graph_find_vertex(char* name, graph_t* graph_p){
    assert(graph_p);
    
    khiter_t k = kh_get(gr,graph_p->dict,name);
    
    if(k == kh_end(graph_p->dict))	//If it was not found, ret -1
        return -1;
    else
        return kh_value(graph_p->dict, k);
}

vertex_t* graph_get_vertex_s(char* vertex_name, graph_t * graph_p)
{
    assert(graph_p);
    int id = graph_find_vertex(vertex_name, graph_p);
    if(id < 0)
        return NULL;
    else
        return graph_get_vertex_i(id, graph_p);
}
vertex_t* graph_get_vertex_i(int vertex_id, graph_t * graph_p)
{
    assert(graph_p);
    vertex_t* v = NULL;
    
    if (vertex_id < graph_p->num_vertices && vertex_id >= 0)
    {
        v = (vertex_t*)array_list_get(vertex_id, graph_p->vertices);
        if (v != NULL)
            if (v->src == NULL)	// v is in the removed_vertex list
                v = NULL;
    }
    return v;
}

int graph_exists_vertex_s(char* name, graph_t* graph_p)
{
    int id = graph_find_vertex(name, graph_p);
    if(id >= 0)
    {
        return graph_exists_vertex_i(id, graph_p);
    }
    else
        return -1;
}

int graph_exists_vertex_i(int id, graph_t* graph_p)
{
    assert(graph_p);
    if( graph_get_vertex_i(id, graph_p) != NULL)
        return 0;
    else
        return -1;
}


int graph_reachable_vertex(int src, int dst, graph_t* graph_p){
    
    if(src == dst)
        return 0;
    
    linked_list_t* queue = linked_list_new(graph_p->sync_mode);
    vertex_t* v, *v_dst;
    edge_t *e;
    linked_list_iterator_t *iter = (linked_list_iterator_t*)malloc(sizeof(linked_list_iterator_t));
    int i, fin = 0, dst_id;
    char *c = (char*)calloc(graph_p->num_vertices, sizeof(char));

    v = graph_get_vertex_i(src, graph_p);
    v_dst = graph_get_vertex_i(dst, graph_p);
    if(v != NULL && v_dst != NULL)
    {
        linked_list_insert_last(v, queue);
        c[v->id] = 1;
        while(v = (vertex_t*)linked_list_remove_first(queue))
        {
            linked_list_iterator_init(v->dst, iter);
            e = (edge_t*)linked_list_iterator_curr(iter);
            while(e != NULL)
            {
                if(c[e->dst_id]==0){
                    if(e->dst_id == dst){
                        fin = 1;
                        break;
                    }
                    linked_list_insert_last(graph_get_vertex_i(e->dst_id, graph_p),queue);
                    c[e->dst_id] = 1;
                }
                e=(edge_t*)linked_list_iterator_next(iter);
            }
            if(!fin){
                linked_list_iterator_init(v->nd, iter);
                e = (edge_t*)linked_list_iterator_curr(iter);
                while(e != NULL)
                {
                    dst_id = (e->dst_id != v->id)? e->dst_id: e->src_id; 
                    if(c[dst_id]==0){
                        if(dst_id == dst){
                            fin = 1;
                            break;
                        }
                        linked_list_insert_last(graph_get_vertex_i(dst_id, graph_p),queue);
                        c[dst_id] = 1;
                    }
                    e=(edge_t*)linked_list_iterator_next(iter);
                }
            }
        }
    }
    linked_list_iterator_free(iter);
    linked_list_free(queue, NULL);
    free(c);
    return fin-1;
}



linked_list_t* graph_get_neighborhood_v(vertex_t* vertex_p, enum EdgeDirection edge_type, int k, graph_t* graph_p)
{
    assert(graph_p);
    if(vertex_p == NULL)
        return NULL;
    
    linked_list_t *queue = linked_list_new(COLLECTION_MODE_ASYNCHRONIZED); 
    if(k <= 0){
        linked_list_insert_last(vertex_p, queue);
        return queue;
    }
    
    khash_t(ii) *visited = kh_init(ii);
    
    linked_list_iterator_t *iter = linked_list_iterator_new(queue);
    linked_list_iterator_t *iter_edge = linked_list_iterator_new(queue);
    vertex_t *v = vertex_p;
    edge_t *e;
    
    int in = edge_type & GRAPH_EDGE_IN;
    int out = edge_type & GRAPH_EDGE_OUT;
    int dst, ret;
    
    //Insert a NULL to indicate the distance from the origin was increased.
    //You can know the distance to the origin counting the NULLs 
    //(in fact, you can't, because those NULL are deleted)
    linked_list_insert_last(v, queue);
    linked_list_insert_last(NULL, queue);
    linked_list_iterator_first(iter);
    
    kh_put(ii,visited,v->id,&ret);
    //printf("k = %d\n",k);
    while(1)
    {
        //printf("\n\n");
        if(v == NULL){
            k--;
            //printf("k = %d\n",k);
            linked_list_iterator_remove(iter);
            if(linked_list_iterator_curr(iter) == NULL)	//If it was the last NULL, break;
                break;
        
            if(k <= 0)
                break;
            else
            {
                linked_list_insert_last(NULL, queue);
                v = (vertex_t*)linked_list_iterator_curr(iter);
                continue;
            }
        }
        
        //printf("--VERTEX-- %d\n", v->id);
        if(in)
        {
            linked_list_iterator_init(v->src, iter_edge);
            e = linked_list_iterator_curr(iter_edge);
            while(e != NULL)
            {
                kh_put(ii,visited,e->src_id,&ret);
                if(ret != 0)
                    linked_list_insert_last( array_list_get(e->src_id, graph_p->vertices), queue); 	//inserts in the queue

                e= (edge_t*)linked_list_iterator_next(iter_edge);
            }
        }
        if(out)
        {
            linked_list_iterator_init(v->dst, iter_edge);
            e = linked_list_iterator_curr(iter_edge);
            while(e != NULL)
            {
                kh_put(ii,visited,e->dst_id,&ret);
                if(ret != 0)
                    linked_list_insert_last( array_list_get(e->dst_id, graph_p->vertices), queue); 	//inserts in the queue
                
                e= (edge_t*)linked_list_iterator_next(iter_edge);
            }
        }
        if(in || out){
            linked_list_iterator_init(v->nd, iter_edge);
            e = linked_list_iterator_curr(iter_edge);
            while(e != NULL)
            {
                dst = (e->dst_id!=v->id)? e->dst_id: e->src_id;
                
                kh_put(ii,visited,dst,&ret);
                if(ret != 0){
                    linked_list_insert_last( array_list_get(dst, graph_p->vertices), queue); 	//inserts in the queue
                }
                //printf("Inserted %d, ret=%d\n", dst, ret);

                e= (edge_t*)linked_list_iterator_next(iter_edge);
            }
        }
        
        v = (vertex_t*)linked_list_iterator_next(iter);
    }
    
    linked_list_iterator_free(iter);
    kh_destroy(ii,visited);
    
    return queue;
}
linked_list_t* graph_get_neighborhood_s(char* name, enum EdgeDirection edge_type, int k_jumps, graph_t* graph_p)
{
    return graph_get_neighborhood_v(graph_get_vertex_s(name, graph_p), edge_type, k_jumps, graph_p);
}
linked_list_t* graph_get_neighborhood_i(int vertex_id, enum EdgeDirection edge_type, int k_jumps, graph_t* graph_p)
{
    return graph_get_neighborhood_v(graph_get_vertex_i(vertex_id, graph_p), edge_type, k_jumps, graph_p);
}

linked_list_t* graph_get_adjacents_v(vertex_t* vertex_p, graph_t* graph_p)
{
    return graph_get_neighborhood_v(vertex_p, GRAPH_EDGE_OUT, 1, graph_p);
}
linked_list_t* graph_get_adjacents_s(char* name, graph_t* graph_p)
{
    return graph_get_neighborhood_v(graph_get_vertex_s(name, graph_p), GRAPH_EDGE_OUT, 1, graph_p);
}
linked_list_t* graph_get_adjacents_i(int id, graph_t* graph_p)
{
    return graph_get_neighborhood_v(graph_get_vertex_i(id, graph_p), GRAPH_EDGE_OUT, 1, graph_p);
}

/*!
 * @abstract
 * 
 * @return	>= 0 : vertex index
 * 			-1   : Error at array_list_insert
 * 			-2   : Error at kh_put. It already exists on the hash_table
 * 			-3   : Error name == NULL
 */
int graph_add_vertex(char* name_p, void* vertex_data, graph_t* graph_p){
    
    vertex_t *v;
    
    if (name_p == NULL)
        return -3;
    
    char *name = strndup (name_p, GRAPH_MAX_NAME_LENGTH +1);
    
    int ret;
    khiter_t k = kh_put(gr, graph_p->dict, name, &ret);
    if (!ret){
        //kh_del(gr, graph_p->dict, k);
        free(name);
        return -2;
    }
    
    if (linked_list_size(graph_p->removed_vertices))
    {
        v = linked_list_get_first(graph_p->removed_vertices);
        linked_list_remove_first(graph_p->removed_vertices);
    }
    else
    {
        v = (vertex_t*)malloc(sizeof(vertex_t));
        if(array_list_insert(v, graph_p->vertices) == 0){
            free(v);
            free(name);
            return -1;
        }
        
        graph_p->num_vertices++;
        v->id = array_list_size(graph_p->vertices)-1;
    }
    //int id = graph_find_vertex(name_p, g); // Even if it already exists, it has to create a new one
    
     

    //Created && appended OK

    
    v->data = vertex_data;
    
    v->src = linked_list_new(graph_p->sync_mode);
    v->dst = linked_list_new(graph_p->sync_mode);
    v->nd = linked_list_new(graph_p->sync_mode);
    
    v->name = name;
    
    kh_value(graph_p->dict,k) = v->id;
    
    return v->id;
}


/**
 * @return	0	OK
 * 			-1	Not existing vertex
 */
int graph_remove_vertex_s(char* vertex_name, void (*vertex_data_callback) (void* vertex_data),void (*edge_data_callback) (void* edge_data), graph_t* graph_p)
{
    int vertex_id = graph_find_vertex(vertex_name,graph_p);
    return graph_remove_vertex_i(vertex_id, vertex_data_callback, edge_data_callback, graph_p);
}
int graph_remove_vertex_i(int vertex_id, void (*vertex_data_callback) (void* vertex_data),void (*edge_data_callback) (void* edge_data), graph_t* graph_p)
{
    assert(graph_p);
    if(vertex_id < 0 || vertex_id >= graph_p->num_vertices)
        return -1;
    
    vertex_t *v = graph_get_vertex_i(vertex_id, graph_p);
    if(v == NULL)
        return 0;
    linked_list_iterator_t *iter = linked_list_iterator_new(v->src);
    edge_t *e = (edge_t*)linked_list_iterator_curr(iter);
    while(e != NULL)
    {
        linked_list_iterator_next(iter);
        graph_remove_edge_e(e, GRAPH_EDGE_DIRECTED, edge_data_callback, graph_p);
        e = (edge_t*)linked_list_iterator_curr(iter);
    }
    
    iter = linked_list_iterator_init(v->dst, iter);
    e = linked_list_iterator_curr(iter);
    while(e != NULL)
    {
        linked_list_iterator_next(iter);
        graph_remove_edge_e(e, GRAPH_EDGE_DIRECTED, edge_data_callback, graph_p);
        e = (edge_t*)linked_list_iterator_curr(iter);
    }
    
    iter = linked_list_iterator_init(v->nd, iter);
    e = linked_list_iterator_curr(iter);
    while(e != NULL)
    {
        linked_list_iterator_next(iter);
        graph_remove_edge_e(e, GRAPH_EDGE_NON_DIRECTED, edge_data_callback, graph_p);
        e = (edge_t*)linked_list_iterator_curr(iter);
    }
    linked_list_iterator_free(iter);
    
    linked_list_free(v->src, NULL);
    linked_list_free(v->dst, NULL);	// free dst edge
    linked_list_free(v->nd, NULL);
    v->src = v->dst = v->nd = NULL;
    
    kh_del(gr,graph_p->dict, kh_get(gr,graph_p->dict, v->name));
    
    free(v->name);
    v->name = NULL;
    if(vertex_data_callback)
        vertex_data_callback(v->data);
    v->data = NULL;
    linked_list_insert(v, graph_p->removed_vertices);
    
    return 0;
}

/**
 * Edge Functions
 */

int graph_add_edge_i(int src, int dst, void* edge_data, enum EdgeType edge_type, graph_t* graph_p)
{
    return graph_add_edge_iw(src, dst, edge_data, edge_type, 1, graph_p);
}
int graph_add_edge_s(char* src, char* dst, void* edge_data, enum EdgeType edge_type, graph_t* graph_p)
{
    return graph_add_edge_sw(src, dst, edge_data, edge_type, 1, graph_p);
}
int graph_add_edge_sw(char* src, char* dst, void* edge_data, enum EdgeType edge_type, float weight, graph_t* graph_p)
{
    assert(graph_p);
    int s = graph_find_vertex(src,graph_p);
    int d = graph_find_vertex(dst,graph_p);
    return graph_add_edge_iw(s, d, edge_data, edge_type, weight, graph_p);
}
 
/**
 * 
 * 
 * @return 0    : OK
 * 			-1   : src or dst are not in graph
 * 			-2   : edge_type non supported
 * 			-3   : edge_type non compatible with the graph directed type
 * 			-4   : edge breaks acyclity
 * 			-5   : edge breaks multiplicity
 * 			-6   : Weight must be possitive
 */
int graph_add_edge_iw(int src, int dst, void* edge_data, enum EdgeType edge_type, float weight, graph_t* graph_p){
    
    //if(array_list_size(graph_p->vertices) <= src || array_list_size(graph_p->vertices) <= dst || src < 0 || dst < 0)
    //	return -1;
    if (graph_get_vertex_i(src, graph_p) == NULL || graph_get_vertex_i(src, graph_p) == NULL)
        return -1;
    
    
    edge_t * e;
    
    //if(!graph_p->multiple)
        if(graph_get_edge_i(src,dst,edge_type, graph_p) != NULL)
            return -5;
    
    if(!graph_p->cyclic && graph_p->strict){//if acyclic
        if(edge_type == GRAPH_EDGE_NON_DIRECTED)
            if(graph_reachable_vertex(src, dst, graph_p)==0)
                return -4;
        if(graph_reachable_vertex(dst, src, graph_p)==0)
            return -4;
    }

    if(graph_p->non_negative && weight < 0)	//FIXME weight < 0 || weight <= 0 ??
        return -6;

    //if(graph_exists_vertex_i(src, graph_p) < 0 || graph_exists_vertex_i(dst, graph_p) < 0 )
    //	return -6;
    
    e = (edge_t*)malloc(sizeof(edge_t));
    e->src_id = src;
    e->dst_id = dst;
    e->data = edge_data;
    e->weight = weight;
    
    switch(edge_type)// TODO comprobacion multiple...
    {
        case GRAPH_EDGE_DIRECTED:
            if(graph_p->directed == GRAPH_NON_DIRECTED && graph_p->strict == GRAPH_STRICT){
                free(e);
                return -3;
            }

            linked_list_insert(e,(graph_get_vertex_i(src,graph_p))->dst);
            linked_list_insert(e,(graph_get_vertex_i(dst,graph_p))->src);
            break;
        case GRAPH_EDGE_NON_DIRECTED:
            if(graph_p->directed == GRAPH_DIRECTED && graph_p->strict == GRAPH_STRICT){
                free(e);
                return -3;
            }
            linked_list_insert(e,(graph_get_vertex_i(src,graph_p))->nd);
            linked_list_insert(e,(graph_get_vertex_i(dst,graph_p))->nd);

            break;
        default:
            free(e);
            return -2;
    }
    graph_p->num_edges++;
    return 0;

}



edge_t* graph_get_edge_s(char* src, char* dst, enum EdgeType edge_type, graph_t* graph_p)
{
    vertex_t* v_src = graph_get_vertex_s (src, graph_p);
    vertex_t* v_dst = graph_get_vertex_s (dst, graph_p);
    if (v_src == NULL || v_dst == NULL)
        return NULL;
    else
        return graph_get_edge_v (v_src, v_dst, edge_type, graph_p);
}

edge_t* graph_get_edge_i(int src, int dst, enum EdgeType edge_type, graph_t* graph_p)
{
    vertex_t* v_src = graph_get_vertex_i (src, graph_p);
    vertex_t* v_dst = graph_get_vertex_i (dst, graph_p);
    if (v_src == NULL || v_dst == NULL)
        return NULL;
    else
        return graph_get_edge_v (v_src, v_dst, edge_type, graph_p);
}

edge_t* graph_get_edge_v(vertex_t* v_src, vertex_t* v_dst, enum EdgeType edge_type, graph_t* graph_p)
{
    assert(graph_p);
    linked_list_iterator_t *iter;
    
    if (v_src == NULL || v_dst == NULL)
        return NULL;
    
    edge_t *e;
    if(edge_type == GRAPH_EDGE_DIRECTED)
    {
        iter = linked_list_iterator_new(v_src->dst);
        e = (edge_t*)linked_list_iterator_curr(iter);
        while(e != NULL)
        {
            if(e->dst_id == v_dst->id)
            {
                linked_list_iterator_free(iter);
                return e;
            }
            e = (edge_t*)linked_list_iterator_next(iter);
        }
        linked_list_iterator_free(iter);
    }
    else if(edge_type == GRAPH_EDGE_NON_DIRECTED){
        int nd_dst;
        
        iter = linked_list_iterator_new(v_src->nd);
        e = (edge_t*)linked_list_iterator_curr(iter);
        while(e != NULL)
        {
            nd_dst = (e->src_id==v_src->id)? e->dst_id: e->src_id;
            if(nd_dst == v_dst->id)
            {
                linked_list_iterator_free(iter);
                return e;
            }
            e = (edge_t*)linked_list_iterator_next(iter);
        }
        linked_list_iterator_free(iter);
    }
    return NULL;
}


/*linked_list_t* graph_get_edge(int src, int dst, char edge_type, graph_t* graph_p)
{
    linked_list_t *l = linked_list_new(graph_p->sync_mode);
    if(array_list_size(graph_p->vertices) <= src || array_list_size(graph_p->vertices) <= dst || src < 0 || dst < 0)
        return l;
    
    linked_list_iterator_t *iter;
    
    vertex_t *v = (vertex_t*)graph_get_vertex_i(src,graph_p);
    edge_t *e;
    if(edge_type & GRAPH_DIRECTED)
    {
        iter = linked_list_iterator_new(v->dst);
        e = (edge_t*)linked_list_iterator_curr(iter);
        while(e != NULL)
        {
            if(e->dst_id == dst)
            {
                linked_list_insert(e->data,l);
            }
            e = (edge_t*)linked_list_iterator_next(iter);
        }
        linked_list_iterator_free(iter);
    }
    if(edge_type & GRAPH_NON_DIRECTED)
    {
        int nd_dst;
        
        iter = linked_list_iterator_new(v->nd);
        e = (edge_t*)linked_list_iterator_curr(iter);
        while(e != NULL)
        {
            nd_dst = (e->src_id==src)? e->dst_id: e->src_id;
            if(nd_dst == dst)
            {
                linked_list_insert(e->data,l);
            }
            e = (edge_t*)linked_list_iterator_next(iter);
        }
        linked_list_iterator_free(iter);
    }
    return l;
}
*/


/**
 * @return	0	OK
 * 			-1	Edge doesn't exist
 * 			-2	Corrupted edge
 */
int graph_remove_edge_s(char* src, char* dst, enum EdgeType edge_type, void (*edge_data_callback) (void* edge_data), graph_t* graph_p)
{
    edge_t* e = graph_get_edge_s( src, dst, edge_type, graph_p);
    if(e!=NULL)
        return graph_remove_edge_e(e,edge_type, edge_data_callback, graph_p);
    else
        return -1;
}
int graph_remove_edge_i(int src, int dst, enum EdgeType edge_type, void (*edge_data_callback) (void* edge_data), graph_t* graph_p)
{
    edge_t *e = graph_get_edge_i( src, dst, edge_type, graph_p);
    
    if(e!=NULL)
        return graph_remove_edge_e(e,edge_type, edge_data_callback, graph_p);
    else
        return -1;
}
int graph_remove_edge_e(edge_t *edge_p, enum EdgeType edge_type, void (*edge_data_callback) (void* edge_data), graph_t* graph_p)
{
    assert(graph_p);
    if(edge_p == NULL)
        return -1;
    
    
    linked_list_iterator_t *iter;
    vertex_t *v_src = graph_get_vertex_i(edge_p->src_id, graph_p);
    vertex_t *v_dst = graph_get_vertex_i(edge_p->dst_id, graph_p);
    if(v_src == NULL || v_dst == NULL)
        return -2;
    if(edge_type & GRAPH_EDGE_DIRECTED){
        linked_list_remove(edge_p, v_src->dst);
        linked_list_remove(edge_p, v_dst->src);
    }
    else if(edge_type & GRAPH_EDGE_NON_DIRECTED)
    {
        linked_list_remove(edge_p, v_src->nd);
        linked_list_remove(edge_p, v_dst->nd);
    }
    if(edge_data_callback)
        edge_data_callback(edge_p->data);
    free(edge_p);
    graph_p->num_edges--;
    return 0;
}




/**
 * Others
 */

void graph_print(graph_t* graph_p)
{
    assert(graph_p);
    int i;
    vertex_t *v;
    edge_t* e;
    linked_list_iterator_t *iter;
    if(graph_p->num_vertices)
        iter = (linked_list_iterator_t *)malloc(sizeof(linked_list_iterator_t));
    
    for (i = 0; i < graph_p->num_vertices; i++)
    {
        v = graph_get_vertex_i(i, graph_p);
        if(v == NULL)
            continue;
        printf("%s _____ id(%d)\n   src\n", v->name, v->id);
        
        iter = linked_list_iterator_init(v->src, iter);
        e = (edge_t*) linked_list_iterator_curr(iter);
        while (e != NULL)
        {
            printf ("\t%s <- %s\n"
                    , (graph_get_vertex_i(e->dst_id, graph_p))->name
                    , (graph_get_vertex_i(e->src_id, graph_p))->name);
            e = (edge_t*)linked_list_iterator_next(iter);
        }
        printf("   dst\n");
        
        iter = linked_list_iterator_init(v->dst, iter);
        e = (edge_t*) linked_list_iterator_curr(iter);
        while (e != NULL)
        {
            printf ("\t%s -> %s\n"
                    , (graph_get_vertex_i(e->src_id, graph_p))->name
                    , (graph_get_vertex_i(e->dst_id, graph_p))->name);
            e = (edge_t*)linked_list_iterator_next(iter);
        }
        printf("   nd\n");
        
        iter = linked_list_iterator_init(v->nd, iter);
        e = (edge_t*) linked_list_iterator_curr(iter);
        while (e != NULL)
        {
            printf ("\t%s -- %s\n"
                    , (graph_get_vertex_i(e->src_id, graph_p))->name
                    , (graph_get_vertex_i(e->dst_id, graph_p))->name);
            e = (edge_t*)linked_list_iterator_next(iter);
        }
        printf("\n");
        printf("\n");
    }
    
    if(graph_p->num_vertices)
        linked_list_iterator_free(iter);
}



void __graph_print_dot(char* file_name, int print_weight, graph_t* graph_p)
{
    assert(graph_p);
    FILE *f;
    int i;
    vertex_t *v;
    edge_t* e;
    linked_list_iterator_t *iter;
    
    if(file_name == NULL)
        f = stdout;
    
    else
        f = fopen(file_name, "w");
    
    if(graph_p->num_vertices)
        iter = (linked_list_iterator_t *)malloc(sizeof(linked_list_iterator_t));
    
    fprintf(f,"digraph {\n");

    for (i = 0; i < graph_p->num_vertices; i++)
    {
        v = graph_get_vertex_i(i, graph_p);
        if(v == NULL)
            continue;
        
        if(!linked_list_size(v->src) && !linked_list_size(v->dst) && !linked_list_size(v->nd))
            fprintf(f,"\t\"%s\";\n", v->name);
        
        iter = linked_list_iterator_init(v->dst, iter);
        e = (edge_t*) linked_list_iterator_curr(iter);
        while (e != NULL)
        {
            if(print_weight)
                fprintf(f,"\t\"%s\" -> \"%s\" [label=\"%.2f\"];\n"
                        , (graph_get_vertex_i(e->src_id, graph_p))->name
                        , (graph_get_vertex_i(e->dst_id, graph_p))->name
                        , e->weight);
            else
                fprintf(f,"\t\"%s\" -> \"%s\" ;\n"
                        , (graph_get_vertex_i(e->src_id, graph_p))->name
                        , (graph_get_vertex_i(e->dst_id, graph_p))->name);
                        
            e = (edge_t*)linked_list_iterator_next(iter);
        }
        
        iter = linked_list_iterator_init(v->nd, iter);
        e = (edge_t*) linked_list_iterator_curr(iter);
        while (e != NULL)
        {
            if( e->src_id == v->id)
            {
                if(print_weight)
                    fprintf(f,"\t\"%s\" -> \"%s\" [dir=none,label=\"%.2f\"];\n"
                        , (graph_get_vertex_i(e->src_id, graph_p))->name
                        , (graph_get_vertex_i(e->dst_id, graph_p))->name
                        , e->weight);
                else
                    fprintf(f,"\t\"%s\" -> \"%s\" [dir=none];\n"
                        , (graph_get_vertex_i(e->src_id, graph_p))->name
                        , (graph_get_vertex_i(e->dst_id, graph_p))->name);
            }
            e = (edge_t*)linked_list_iterator_next(iter);
        }
    }
        fprintf(f,"}\n");
    if(file_name != NULL)
        fclose(f);
    if(graph_p->num_vertices)
        linked_list_iterator_free(iter);
}
void graph_print_dot(char* file_name, graph_t* graph_p)
{
    __graph_print_dot(file_name, 0, graph_p);
}

void graph_print_dot_w(char* file_name, graph_t* graph_p)
{
    __graph_print_dot(file_name, 1, graph_p);
}


int graph_get_order (graph_t* graph_p)
{
    assert(graph_p);
    return graph_p->num_vertices - linked_list_size(graph_p->removed_vertices);
}
int graph_get_size (graph_t* graph_p)
{
    assert(graph_p);
    return graph_p->num_edges;
}

/**
 * Profiling
 */

int graph_vertex_grade_s(char* vertex_name, enum EdgeDirection edge_type, graph_t* graph_p)
{
    vertex_t* v = graph_get_vertex_s (vertex_name, graph_p);
    
    if (v == NULL)
        return 0;
    else
        return graph_vertex_grade_v (v, edge_type, graph_p);
}

int graph_vertex_grade_i(int vertex_id, enum EdgeDirection edge_type, graph_t* graph_p)
{
    vertex_t* v = graph_get_vertex_i (vertex_id, graph_p);
    
    if (v == NULL)
        return 0;
    else
        return graph_vertex_grade_v (v, edge_type, graph_p);
}

int graph_vertex_grade_v(vertex_t * v, enum EdgeDirection edge_type, graph_t* graph_p)
{
    assert(graph_p);
    if (v == NULL)
        return 0;
    
    int n_edges;

    n_edges = linked_list_size(v->nd);

    if (edge_type & GRAPH_EDGE_IN)
        n_edges += linked_list_size(v->src);
    
    if (edge_type & GRAPH_EDGE_OUT)
        n_edges += linked_list_size(v->dst);
    
    return n_edges;
}

/**
 * Computes the cluster coefficient of a vertex.
 * This value is the connectivity among its neighbors divided by the 
 * maximum possible connectivity among its neighbors
 */
float graph_vertex_clustering_coefficient_s (char* vertex_name, enum EdgeDirection edge_type, graph_t* graph_p)
{
    return graph_vertex_clustering_coefficient_v (graph_get_vertex_s (vertex_name, graph_p), edge_type, graph_p);
}

float graph_vertex_clustering_coefficient_i (int vertex_id, enum EdgeDirection edge_type, graph_t* graph_p)
{
    return graph_vertex_clustering_coefficient_v (graph_get_vertex_i (vertex_id, graph_p), edge_type, graph_p);
}

float graph_vertex_clustering_coefficient_v (vertex_t* v, enum EdgeDirection edge_type, graph_t* graph_p)
{
    assert(graph_p);
    if (v == NULL)
        return -1;
    
    linked_list_t * l = graph_get_neighborhood_v (v, edge_type, 1, graph_p);
    int num_adjacent = linked_list_size (l);
    int max_edges = (num_adjacent * (num_adjacent-1)/* / 2*/);
    int curr_edges = 0;
    linked_list_iterator_t* iter1 = linked_list_iterator_new (l);
    linked_list_iterator_t* iter2 = linked_list_iterator_new (l);
    vertex_t* v_neighbor1 = (vertex_t*)linked_list_iterator_curr(iter1);
    vertex_t* v_neighbor2 = (vertex_t*)linked_list_iterator_curr(iter2);
    
    while(v_neighbor1 != NULL)
    {
        while (v_neighbor2 != NULL)
        {
            if (graph_get_edge_v (v_neighbor1, v_neighbor2, edge_type, graph_p) != NULL)
            {
                curr_edges++;
            }
            v_neighbor2 = (vertex_t*) linked_list_iterator_next (iter2);
        }

        v_neighbor1 = (vertex_t*) linked_list_iterator_next (iter1);
        v_neighbor2 = (vertex_t*) linked_list_iterator_first (iter2);
    }
    linked_list_iterator_free(iter1);
    linked_list_iterator_free(iter2);
    linked_list_free (l, NULL);
    return (curr_edges/(float)max_edges);
}

/**
 * Computes the average clustering coefficient of the graph.
 * This value is the summation of the clustering coefficient of all vertices
 * divided by the quantity of vertices.
 */
float graph_clustering_coefficient (enum EdgeDirection edge_type, graph_t* graph_p)
{
    assert(graph_p);
    float cc = 0;
    int num_adjacent, i;

    for (i = 0; i < graph_p->num_vertices; i++)
        cc += graph_vertex_clustering_coefficient_i(i, edge_type, graph_p);
    
    cc /= graph_p->num_vertices;

    return cc;
}


path_node_t * graph_run_dijkstra (vertex_t *orig, enum EdgeType edge_type, graph_t * graph_p)
{
    assert(graph_p->non_negative);

    path_node_t * dists = (path_node_t*) calloc (graph_p->num_vertices, sizeof(path_node_t));   // distances table
    linked_list_t * unvisited = linked_list_new (COLLECTION_MODE_ASYNCHRONIZED);    // unvisited queue
    linked_list_iterator_t *iter = linked_list_iterator_new(unvisited); // unvisited iterator
    linked_list_iterator_t *iter_edge = linked_list_iterator_new(unvisited);    // edge iterator within a vertex
    
    int directed_path = edge_type & GRAPH_EDGE_DIRECTED;
    int non_directed_path = edge_type & GRAPH_EDGE_NON_DIRECTED;
    vertex_t *v;
    edge_t * e;
    
    int i;
    for (i = 0; i < graph_p->num_vertices; i++)
    {
        dists[i].distance = FLT_MAX;
        dists[i].father = -1;
        dists[i].visited = 0;
    }
    
    dists[orig->id].distance = 0;
    dists[orig->id].father = orig->id;
    dists[orig->id].visited = 1;
    
    linked_list_insert_last(v, unvisited);
    v = linked_list_iterator_first(iter);

    while (v)
    {
        if (dists[v->id].visited == 0)  // not visited yet
        {
            if(directed_path)
            {
                linked_list_iterator_init(v->dst, iter_edge);
                e = linked_list_iterator_curr(iter_edge);
                while(e != NULL)
                {
                    if (dists[e->dst_id].visited == 0)
                    {
                        linked_list_insert_last( array_list_get(e->dst_id, graph_p->vertices), unvisited); 	//inserts in the unvisited queue
                        dists[e->dst_id].visited = 1;
                    }
//FIXME preallocate values
                    if (dists[e->dst_id].distance == FLT_MAX || dists[e->dst_id].distance > dists[v->id].distance + e->weight)   // better path found
                    {
                        dists[e->dst_id].distance = dists[v->id].distance + e->weight;
                        dists[e->dst_id].father = v->id;
                    }
                    e = (edge_t*)linked_list_iterator_next(iter_edge);
                }
            }
            /*
            if(non_directed_path){
                linked_list_iterator_init(v->nd, iter_edge);
                e = linked_list_iterator_curr(iter_edge);
                while(e != NULL)
                {
                    dst = (e->dst_id!=v->id)? e->dst_id: e->src_id;

                    kh_put(ii,visited,dst,&ret);
                    if(ret != 0){
                        linked_list_insert_last( array_list_get(dst, graph_p->vertices), queue); 	//inserts in the queue
                    }
                    //printf("Inserted %d, ret=%d\n", dst, ret);

                    e= (edge_t*)linked_list_iterator_next(iter_edge);
                }
            }
*/
        }
        v = linked_list_iterator_first(iter);
    }
    linked_list_iterator_free(iter);
    linked_list_iterator_free(iter_edge);
    linked_list_free(unvisited, NULL);
    return dists;
}
