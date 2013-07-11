#include <time.h>
//#include <stdlib.h>
#include "../graph.h"

void stop_crono(char* mensaje, struct timespec * ini_time)
{
	struct timespec timedif, fin_time;
	
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &fin_time);//-----------------------
	timedif.tv_sec = fin_time.tv_sec - ini_time->tv_sec;
	timedif.tv_nsec = fin_time.tv_nsec - ini_time->tv_nsec;
	if (timedif.tv_nsec < 0)
	{
		timedif.tv_nsec += 1000000000;
		timedif.tv_sec--;
	}
	printf(mensaje, (int)timedif.tv_sec, timedif.tv_nsec);
}
void graph_aleale(int num_v, float connectivity, enum EdgeType edge_type, graph_t* g);
int main (void)
{
	struct timespec ini_time;
	
	graph_t *g;
	long int num_vertices = 2000;
	int num_edges = 20000;
	int name_length = 255;
	char ** names;
	int i;
	float p;
    p = (1.0*num_edges)/(num_vertices*num_vertices);
    //p = 0.01;
    
	srand(time(NULL));
	
	names = (char**) malloc (sizeof(char*)*num_vertices);
	
	for (i = 0; i < num_vertices; i++)
	{
		//itoa(i, names[i], 10);
		names[i] = (char*) malloc (sizeof(char)*name_length);
		sprintf(names[i], "%d", i);
		//printf ("name[%d] = %s\n", i, names[i]);
	}
	
	printf("grafo con %d nodos\n", num_vertices);
	
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &ini_time);//+++++++++++++++++++++++++++++++++++
	
	g = graph_new (GRAPH_NON_NEGATIVE_WEIGHT | GRAPH_CYCLIC | GRAPH_DIRECTED, num_vertices, COLLECTION_MODE_ASYNCHRONIZED);
	
	stop_crono("tiempo en crear el grafo: t =  %d s y %ld ns\n", &ini_time);//-----------------------
	
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &ini_time);//++++++++++++++++++++++++++++++++++
	
	for (i = 0; i < num_vertices; i++)
		graph_add_vertex (names[i], NULL, g);
	
	stop_crono("tiempo rellenar vertices aleatorios: t =  %d s y %ld ns\n", &ini_time);//-----------------------
	
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &ini_time);//+++++++++++++++++++++++++++++++++
	
	//for (i = 0; i < num_edges; i++)
		//graph_add_edge_iw(rand()%num_vertices, rand()%num_vertices, NULL, GRAPH_EDGE_DIRECTED, 1, g);
	
    
    printf("%f\n",p);
    graph_aleale(num_vertices, p, GRAPH_EDGE_DIRECTED, g);
    
	stop_crono("tiempo en relenar edges aleatorios =  %d s y %ld ns\n", &ini_time);//-----------------
	
	printf("solo cumplian las condiciones %d edges\n", g->num_edges);
	

	
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &ini_time);//+++++++++++++++++++++++++++++++++++
	
	graph_path_t * path_l = graph_run_dijkstra((vertex_t*)(g->vertices->items[0]), GRAPH_EDGE_DIRECTED, g);

	stop_crono("tiempo en Dijkstra: t =  %d s y %ld ns\n", &ini_time);//-----------------------

    //printf("ID\t\tDist\t\tFather\n");
    //for (i = 0; i < graph_get_order(g); i++)
    //{
        //printf("%d\t\t%f\t\t%d\n", i, path_l[i].distance, path_l    [i].father);
    //}
    
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &ini_time);//+++++++++++++++++++++++++++++++++++
    
    graph_run_path_stats(g);
	
    stop_crono("tiempo en calcular estadisticas: t =  %d s y %ld ns\n", &ini_time);//-----------------------
    
    	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &ini_time);//+++++++++++++++++++++++++++++++++++
	
	graph_print_dot_w("grafo_tiempo.gv", g);
    graph_plot("grade_tiempo.plt",PLOT_GRADE, g);
    graph_plot("jumps_tiempo.plt",PLOT_JUMPS, g);
    graph_plot("bt_tiempo.plt",PLOT_BETWEENNESS, g);

	stop_crono("tiempo en print dot: t =  %d s y %ld ns\n", &ini_time);//-----------------------
    
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &ini_time);//+++++++++++++++++++++++++++++++++++
	
	graph_free(NULL, NULL, g);
	
	stop_crono("tiempo en liberar grafo: t =  %d s y %ld ns\n", &ini_time);//-----------------------
	
	for (i = 0; i < num_vertices; i++)
		free(names[i]);
		
	free (names);
	
	printf("\n");
	return 0;
}
