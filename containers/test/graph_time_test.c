#include <time.h>
//#include <stdlib.h>
#include "../graph.h"

//#define TIME_TEST(f) void f()

//#define START_TIME_TEST(f) struct timespec f(char* mensaje, ...) {\
                                //va_list a_list;\
                                //va_start(a_list,ini_time);\
                                //struct timespec ini_time;\
                                //clock_gettime(CLOCK_REALTIME, &ini_time);
                                
                                
//#define END_TIME_TEST return stop_crono_v(mensaje, ini_time, a_list);}

#define RUN_TIME_TEST(test, time, mensaje, ...) \
                {struct timespec end_time;\
                clock_gettime(CLOCK_REALTIME, &time);\
                test;\
                clock_gettime(CLOCK_REALTIME, &end_time);\
                time.tv_sec = end_time.tv_sec - time.tv_sec;\
                time.tv_nsec = end_time.tv_nsec - time.tv_nsec;\
                if (time.tv_nsec < 0){time.tv_nsec += 1000000000;time.tv_sec--;}\
                printf(" :::::: [ %f s ] :: ", time.tv_sec+time.tv_nsec*1e-9 );\
                printf(mensaje, ##__VA_ARGS__);}
                
//struct timespec stop_crono_v(char* mensaje, struct timespec ini_time,struct timespec fin_time, va_list a_list);

//struct timespec time_test( void f(), char* mensaje, ...)
//{
	//va_list a_list;
    //va_start(a_list,mensaje);
    
    //struct timespec ini_time, fin_time;
    //clock_gettime(CLOCK_REALTIME, &ini_time);
    //f();
    //clock_gettime(CLOCK_REALTIME, &fin_time);
    //return stop_crono_v(mensaje, ini_time, fin_time, a_list);
//}


//struct timespec stop_crono(char* mensaje, struct timespec ini_time, ... )
//{
	//va_list a_list;
    //va_start(a_list,ini_time);
	//struct timespec fin_time;
    //clock_gettime(CLOCK_REALTIME, &fin_time);
    //return stop_crono_v(mensaje,  ini_time,fin_time, a_list);
//}
//struct timespec stop_crono_v(char* mensaje, struct timespec ini_time,struct timespec fin_time, va_list a_list)
//{
	//struct timespec difftime;
	//difftime.tv_sec = fin_time.tv_sec - ini_time.tv_sec;
	//difftime.tv_nsec = fin_time.tv_nsec - ini_time.tv_nsec;
	//if (difftime.tv_nsec < 0)
	//{
		//difftime.tv_nsec += 1000000000;
		//difftime.tv_sec--;
	//}
	////printf(" :::::: [t = %d s, %ld ns] :: %f s :: ", difftime.tv_sec, difftime.tv_nsec, difftime.tv_sec+difftime.tv_nsec*1e-9 );
	//printf(" :::::: [ %f s ] :: ", difftime.tv_sec+difftime.tv_nsec*1e-9 );
	//vprintf(mensaje, a_list);
    //return difftime;
//}
void graph_aleale(int num_v, float connectivity, enum EdgeType edge_type, graph_t* g);



graph_t *g;
graph_path_t * path_l ;
long int num_vertices = 2000;
int num_edges = 2000000;
int name_length = 255;
char ** names;
int i, nt;
float p, speed;


void generacion_grafo()
{
    g = graph_new (GRAPH_NON_NEGATIVE_WEIGHT | GRAPH_CYCLIC | GRAPH_DIRECTED, num_vertices, COLLECTION_MODE_ASYNCHRONIZED);
}

void rellena_vertices()
{
    for (i = 0; i < num_vertices; i++)
        graph_add_vertex (names[i], NULL, g);
}



void dijkstras(int num)
{return;
    #pragma omp parallel for private(i, path_l) shared(g)
    for(i = 0; i < num; i++)
    {
        graph_run_dijkstra(graph_get_vertex_i(i,g), GRAPH_EDGE_NON_DIRECTED, g);
    }
}

int main (void)
{
	struct timespec ini_time;
	struct timespec base_time;
	
    p = (1.0*num_edges)/(num_vertices*num_vertices);
    p = 0.002;
    
	srand(time(NULL));
	
	names = (char**) malloc (sizeof(char*)*num_vertices);
	
	for (i = 0; i < num_vertices; i++)
	{
		//itoa(i, names[i], 10);
		names[i] = (char*) malloc (sizeof(char)*name_length);
		sprintf(names[i], "%d", i);
		//printf ("name[%d] = %s\n", i, names[i]);
	}
	
	printf("grafo con %ld nodos\n", num_vertices);
	
	RUN_TIME_TEST(generacion_grafo(),ini_time, "Tiempo crear grafo\n");
	RUN_TIME_TEST(rellena_vertices(),ini_time, "Tiempo rellenar vertices aleatorios\n");
    RUN_TIME_TEST(graph_aleale(num_vertices, p, GRAPH_EDGE_NON_DIRECTED, g);,ini_time, "Tiempo en rellenar edges aleatorios con p:%f. solo cumplian las condiciones %d edges\n", p, g->num_edges);
	//for (i = 0; i < num_edges; i++)
        //graph_add_edge_iw(rand()%num_vertices, rand()%num_vertices, NULL, GRAPH_EDGE_DIRECTED, 1, g);
        
    
    omp_set_num_threads(1);
    RUN_TIME_TEST(dijkstras(1000),base_time,"tiempo en 1000 Dijkstras         \n");
    
	for(nt=32; nt>1; nt/=2)
    {
        omp_set_num_threads(nt);
        RUN_TIME_TEST(dijkstras(1000),ini_time, "tiempo en 1000 Dijkstras en hilos.  Hilos: %d Speed-up:\t%f, Rendimiento %f\n", nt, (base_time.tv_sec+base_time.tv_nsec*1e-9)/(ini_time.tv_sec+ini_time.tv_nsec*1e-9), (base_time.tv_sec+base_time.tv_nsec*1e-9)/(ini_time.tv_sec+ini_time.tv_nsec*1e-9)/nt);
    }

    //printf("ID\t\tDist\t\tFather\n");
    //for (i = 0; i < graph_get_order(g); i++)
    //{
        //printf("%d\t\t%f\t\t%d\n", i, path_l[i].distance, path_l    [i].father);
    //}
    
    omp_set_num_threads(4);
    RUN_TIME_TEST(graph_run_path_stats(g), base_time, "tiempo en calcular estadisticas con todos los hilos\n");
    
    
    int chunk[] = {500,200,100,50,30,20,10,5};
    nt = 4;
	//for(nt=32; nt>1; nt/=2)
    for(i = 0; i < 8; i++){
        omp_set_num_threads(nt);
        g->chunk = chunk[i];
        //RUN_TIME_TEST(graph_run_path_stats(g), ini_time, "Tiempo en calcular estadisticas   Hilos: %d chunk: %d  Speed-up:\t%f\n",nt, chunk[i], speed= (base_time.tv_sec+base_time.tv_nsec*1e-9)/(ini_time.tv_sec+ini_time.tv_nsec*1e-9), (base_time.tv_sec+base_time.tv_nsec*1e-9)/(ini_time.tv_sec+ini_time.tv_nsec*1e-9)/nt); 
    }
    
    
    RUN_TIME_TEST(
    {
        //graph_print_dot_w("grafo_tiempo.gv", g);
        graph_plot("grade_tiempo.plt",PLOT_GRADE, g);
        graph_plot("jumps_tiempo.plt",PLOT_JUMPS, g);
        graph_plot("bt_tiempo.plt",PLOT_BETWEENNESS, g);
        graph_plot("w_tiempo.plt",PLOT_WEIGHT, g);
        graph_plot("nr_tiempo.plt",PLOT_NON_REACHABLE, g);
    }, ini_time, "Tiempo en print dot\n");
    
	RUN_TIME_TEST(graph_free(NULL, NULL, g), ini_time, "Tiempo en liberar grafo\n");
	
	for (i = 0; i < num_vertices; i++)
		free(names[i]);
		
	free (names);
	
	printf("\n");
	
    return 0;
}
