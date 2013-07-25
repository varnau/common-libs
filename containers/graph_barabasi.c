
#include "graph_barabasi.h"


int __graph_add_edge(int src, int dst, void* edge_data, enum EdgeType edge_type, float weight, graph_t* graph_p);

graph_t* graph_generate_ergdos_renyi_V1(int m0, float p, int sync_mode, enum EdgeType edgetype)
{
	int i, j;
	void* vertex_data;
	void* edge_data;
	char edge_type;
	char ss1[MAX_CHAR_VERTEX];
	char mask ; 
//-------------- auxiliar variables:
	int counter=0;

	printf("\n-----------------------------------------------------");
 	printf("\nErgdos-Reny Graph Generator\n");
	printf("N_nodes(m0)=  %d \t p=%6.4f \t Edge_type=%d \n", m0, p, edgetype);

//-------------- random variable:
	gsl_rng *r;

	srand(time(NULL));
	r=gsl_rng_alloc(gsl_rng_mt19937);
	
	unsigned long int s=314159265;
	s= ((rand()*1.0)/(RAND_MAX)*1.0) * s;

	gsl_rng_set (r, s);

  	// printf ("generator type: %s\n", gsl_rng_name (r));
	// printf ("seed = %lu\n", s);

	// printf ("seed = %lu\n", gsl_rng_default_seed);

/* 	//	See N randoms numbers:
	double randdd;
	for (i=0; i<1000; i++){
		randdd=gsl_rng_uniform(r);
		printf("\n [%3d] randdd = %6.4f", i, randdd);
		}
	}
********/

	if ((p>1.0) || (p<=0.0)) 
		return NULL;
	if(edgetype != GRAPH_EDGE_NON_DIRECTED && edgetype != GRAPH_EDGE_DIRECTED)
		return NULL;
	if (m0<2)
		return NULL;

	//--> create a new graph -------------------
	graph_t *g = graph_new(mask, m0, sync_mode);

	//--> create the m0 vertex:
	// printf("\nCreate vertex: ");
	for (i=0; i<m0; i++)	{
		sprintf(ss1,"v%d", i);
		// printf("[%s] ", ss1);
		graph_add_vertex(ss1, NULL, g); //--> add a new vertex to the graph
	}
	printf("\n");

	// printf("\nCreate links . . . ");
	//--> create the links with p distribution:
	if(edgetype == GRAPH_EDGE_NON_DIRECTED)
		for (i=0; i<m0; i++)	{
			// printf("\n");
			for (j=i+1; j<m0; j++){
				if (gsl_rng_uniform(r)<p) {
					// printf("[%d-%d] ", i, j); //--> link created (i, j)
					__graph_add_edge(i, j, NULL, GRAPH_EDGE_NON_DIRECTED, 1, g);
					counter++;
				}
			}
		}
	else
		for (i=0; i<m0; i++)	{
			// printf("\n");	
			for (j=0; j<m0; j++){
				if (gsl_rng_uniform(r)<p) {		
					// printf("[%d-%d] ", i, j); //--> link created (i, j)
					__graph_add_edge(i, j, NULL, GRAPH_EDGE_DIRECTED, 1, g);
					counter++;
				}
			}
		}

  	printf("Number of links created = %d [n_vertex=%d]\n", counter, m0);
	gsl_rng_free(r); // dealloc the rng 
	printf("\nErgdos-Reny Graph Completed");
	printf("\n-----------------------------------------------------");
	return(g);
}


graph_t* graph_generate_barabasi(int m0, float p, int t, float m, int sync_mode, enum EdgeType edgetype)
{
	int i, j, k;
	int total_links;
	int index_top; //--> actual number of links
	char ss1[MAX_CHAR_VERTEX];

	if (m>m0) {
		printf("\n Error: m>m0\n");
		return NULL;
	}

	printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
 	printf("\nBarabasi-Albert Graph Generator\n");
	printf(" N_nodes(m0+t)= %d \t m=%6.4f \t Edge_type=%d \n", m0+t, m, edgetype);


	graph_t* graph_p = graph_generate_ergdos_renyi_V1(m0, p, sync_mode, edgetype);

	if (graph_p== NULL) return NULL; 

	int *aa; // memory to aux_array
	int *bb; // memory to aux_array

	total_links = (graph_p->num_edges*2) + (t*ceil(m) * 2); //--> final maximum number of links
	index_top= (graph_p->num_edges)*2;

	// printf("\n index_top= %d\n", index_top);

	aa = (int*)malloc(total_links*sizeof(int));
	if (aa==NULL) {
		printf("\n Memory allocation failed.\n");
		return NULL;
	}

	bb = (int*)malloc(ceil(m)*sizeof(int));
	if (bb==NULL) {
		printf("\n Memory allocation failed.\n");
		return NULL;
	}

//------> Random Numbers:

	gsl_rng *r;

	r=gsl_rng_alloc(gsl_rng_mt19937);
	
	unsigned long int s=314159265;
	srand(time(NULL));
	s= ((rand()*1.0)/(RAND_MAX)*1.0) * s;

	gsl_rng_set (r, s);

  	// printf ("generator type: %s\n", gsl_rng_name (r));
	// printf ("seed = %lu\n", s);

	//----->> walk the graph and add vertices and links

	if (graph_p->num_edges>0){ 
		int index=0; 
		int numedges;
		int k;
		for (i = 0; i < graph_p->num_vertices; i++){
			numedges = graph_get_vertex_grade_i(i, GRAPH_EDGE_IN_OUT, graph_p);
			for (k=0; k < numedges; k++){
				aa[index++]=i;  
			}
		}
	}
	else 
		return NULL;


	int aux_k;
	int aux_int;
	double masuno;
	int limitesup;
	double var = m - (int)(m);
	int destino;


	printf("\nAdd new %d vertex ... ", t);

	//--->> add  new vertex:
	for (i=m0; i<(m0+t); i++){
		masuno= gsl_rng_uniform(r);
		limitesup = (int)(m)+((masuno<var)?1:0);

		// printf("\n [i=%3d] \t limite_sup= %d ", i, limitesup);

		sprintf(ss1,"v%d", i);
		graph_add_vertex(ss1, NULL, graph_p); //--> add a new vertex to the graph

		for (k=0; k<limitesup; k++){
		aux_int = (int) (gsl_rng_uniform(r) * index_top);
		destino = aa[aux_int];

			if(k==0){
				aa[index_top++]= destino; 
				aa[index_top++]= i;
				bb[0]= destino;
				// printf("\n Caso_k=0: %d - %d", i, destino); //--> link created (i, source)
				__graph_add_edge(i, destino, NULL, GRAPH_EDGE_NON_DIRECTED, 1, graph_p);
			}
			else	if(k==1){
						while((destino==bb[0]) || (destino==i)){  //--> para evitar bucles.	
							// printf("---> coincide destino=%d con bb[0]=%d <---", destino, bb[0]);			
							aux_int = (int) (gsl_rng_uniform(r) * index_top);
							destino = aa[aux_int];
						}		
						aa[index_top++]= destino; 
						aa[index_top++]= i;
						bb[1]= destino;
						// printf("\n Caso_k=1: %d - %d", i, destino); //--> link created (i, source)
						__graph_add_edge(i, destino, NULL, GRAPH_EDGE_NON_DIRECTED, 1, graph_p);
					}
					else {//---> k>=2 :
						for (aux_k=0; aux_k<k; aux_k++)
							if ((destino==bb[aux_k]) || (destino==i)) {//--> SI YA LO TENGO: inicio bucle de nuevo + genero destino
								// printf(" ---> destino=%d == bb[%d]=%d <---", destino, aux_k, bb[aux_k]);							
								aux_k=-1;
								aux_int = (int) (gsl_rng_uniform(r) * index_top);
								destino = aa[aux_int];
							}

/*----------> Alternative code:
						int lotengo;
						do {
							lotengo=0;
							for (aux_k=0; (aux_k<k)&&(!lotengo); aux_k++)
								if ((destino==bb[aux_k] || (destino==i)) {
									lotengo= 1;
								aux_int = (int) (gsl_rng_uniform(r) * index_top);
								destino = aa[aux_int];
								}
						}while(lotengo);
-------------------------------*/

						aa[index_top++]= destino; 
						aa[index_top++]= i;
						bb[k]= destino;
						// printf("\n Caso_K>2: %d - %d", i, destino); //--> link created (i, source)
						__graph_add_edge(i, destino, NULL, GRAPH_EDGE_NON_DIRECTED, 1, graph_p);
					}
		}
	}
	
	printf("\nTotal vertex created= %d --> index_top= %d  m=%5.3f\n", i, index_top, m);

 	free(aa); free(bb); 
	gsl_rng_free(r); // dealloc the rng 

	printf("\nBarabasi-Albert Graph Completed");
	printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n");
	return graph_p;
}


