
#line 1 "graph.ragel"
#include "graph.h"
#include "graph_ragel.h"



#line 9 "graph_ragel.c"
static const int graph_dot_start = 1;
static const int graph_dot_first_final = 147;
static const int graph_dot_error = 0;

static const int graph_dot_en_graph_dot = 1;


#line 185 "graph.ragel"


graph_t* graph_read_dot(char* file_name)
{    
    FILE* fd = fopen(file_name, "rb");
    if(!fd) printf("ERROR in open\n");
    
    fseek (fd , 0 , SEEK_END);
    int size = ftell (fd);
    rewind (fd);
    
    char* file = malloc(size); 
    
    int n =-1;
    n = fread(file, 1, size, fd);
    
    //if(!fgets(file, size, fd))
        //printf("ERROR lectura\n");
    
    //printf("size: %d, n=%d. :%s\n",size, n, file);
    
    enum {TYPE_LABEL,TYPE_DIR, TYPE_NONE};
    enum {ID_NUM,ID_STR};

    int label_type;
    const size_t MAX_SIZE = 256;
    size_t MAX_NUM_NODE = 256;
    char last_identifier[MAX_SIZE];
    int curr_node;
    int last_node;
    int edge_type;
    float weight = 1;
    float default_weight = 1;
    int *v_node = malloc(sizeof(int)*MAX_NUM_NODE);
    int n_node = 0;
    graph_t *g = graph_new(GRAPH_MIXED_DIRECTED,5,COLLECTION_MODE_ASYNCHRONIZED);
    
    int cs;
    char *p = file;
    char *pe = p + size;
    char *eof = pe;
    char *ts, *te;
    //int stack[4];
    //int top, act;

    
#line 64 "graph_ragel.c"
	{
	cs = graph_dot_start;
	}

#line 69 "graph_ragel.c"
	{
	if ( p == pe )
		goto _test_eof;
	switch ( cs )
	{
case 1:
	switch( (*p) ) {
		case 100: goto st2;
		case 103: goto st4;
		case 115: goto st141;
	}
	goto st0;
tr9:
#line 123 "graph.ragel"
	{ printf("ERROR %s:%d Pos: %ld State: %d\n", __FILE__,__LINE__, p-file, cs); }
	goto st0;
tr19:
#line 123 "graph.ragel"
	{ printf("ERROR %s:%d Pos: %ld State: %d\n", __FILE__,__LINE__, p-file, cs); }
#line 58 "graph.ragel"
	{ printf("ERROR %s:%d Pos: %ld State: %d\n", __FILE__,__LINE__, p-file, cs); }
	goto st0;
tr29:
#line 58 "graph.ragel"
	{ printf("ERROR %s:%d Pos: %ld State: %d\n", __FILE__,__LINE__, p-file, cs); }
#line 79 "graph.ragel"
	{ printf("ERROR %s:%d Pos: %ld State: %d\n", __FILE__,__LINE__, p-file, cs); }
#line 101 "graph.ragel"
	{ printf("ERROR %s:%d Pos: %ld State: %d\n", __FILE__,__LINE__, p-file, cs); }
	goto st0;
tr36:
#line 79 "graph.ragel"
	{ printf("ERROR %s:%d Pos: %ld State: %d\n", __FILE__,__LINE__, p-file, cs); }
#line 101 "graph.ragel"
	{ printf("ERROR %s:%d Pos: %ld State: %d\n", __FILE__,__LINE__, p-file, cs); }
	goto st0;
tr38:
#line 79 "graph.ragel"
	{ printf("ERROR %s:%d Pos: %ld State: %d\n", __FILE__,__LINE__, p-file, cs); }
#line 123 "graph.ragel"
	{ printf("ERROR %s:%d Pos: %ld State: %d\n", __FILE__,__LINE__, p-file, cs); }
#line 58 "graph.ragel"
	{ printf("ERROR %s:%d Pos: %ld State: %d\n", __FILE__,__LINE__, p-file, cs); }
#line 101 "graph.ragel"
	{ printf("ERROR %s:%d Pos: %ld State: %d\n", __FILE__,__LINE__, p-file, cs); }
	goto st0;
tr44:
#line 123 "graph.ragel"
	{ printf("ERROR %s:%d Pos: %ld State: %d\n", __FILE__,__LINE__, p-file, cs); }
#line 58 "graph.ragel"
	{ printf("ERROR %s:%d Pos: %ld State: %d\n", __FILE__,__LINE__, p-file, cs); }
#line 101 "graph.ragel"
	{ printf("ERROR %s:%d Pos: %ld State: %d\n", __FILE__,__LINE__, p-file, cs); }
	goto st0;
tr48:
#line 79 "graph.ragel"
	{ printf("ERROR %s:%d Pos: %ld State: %d\n", __FILE__,__LINE__, p-file, cs); }
#line 58 "graph.ragel"
	{ printf("ERROR %s:%d Pos: %ld State: %d\n", __FILE__,__LINE__, p-file, cs); }
#line 101 "graph.ragel"
	{ printf("ERROR %s:%d Pos: %ld State: %d\n", __FILE__,__LINE__, p-file, cs); }
	goto st0;
tr53:
#line 123 "graph.ragel"
	{ printf("ERROR %s:%d Pos: %ld State: %d\n", __FILE__,__LINE__, p-file, cs); }
#line 101 "graph.ragel"
	{ printf("ERROR %s:%d Pos: %ld State: %d\n", __FILE__,__LINE__, p-file, cs); }
	goto st0;
tr66:
#line 101 "graph.ragel"
	{ printf("ERROR %s:%d Pos: %ld State: %d\n", __FILE__,__LINE__, p-file, cs); }
	goto st0;
tr69:
#line 123 "graph.ragel"
	{ printf("ERROR %s:%d Pos: %ld State: %d\n", __FILE__,__LINE__, p-file, cs); }
#line 27 "graph.ragel"
	{ printf("ERROR %s:%d Pos: %ld State: %d\n", __FILE__,__LINE__, p-file, cs); }
#line 101 "graph.ragel"
	{ printf("ERROR %s:%d Pos: %ld State: %d\n", __FILE__,__LINE__, p-file, cs); }
	goto st0;
tr78:
#line 27 "graph.ragel"
	{ printf("ERROR %s:%d Pos: %ld State: %d\n", __FILE__,__LINE__, p-file, cs); }
#line 101 "graph.ragel"
	{ printf("ERROR %s:%d Pos: %ld State: %d\n", __FILE__,__LINE__, p-file, cs); }
	goto st0;
tr81:
#line 123 "graph.ragel"
	{ printf("ERROR %s:%d Pos: %ld State: %d\n", __FILE__,__LINE__, p-file, cs); }
#line 48 "graph.ragel"
	{ printf("ERROR %s:%d Pos: %ld State: %d\n", __FILE__,__LINE__, p-file, cs); }
#line 101 "graph.ragel"
	{ printf("ERROR %s:%d Pos: %ld State: %d\n", __FILE__,__LINE__, p-file, cs); }
	goto st0;
tr90:
#line 123 "graph.ragel"
	{ printf("ERROR %s:%d Pos: %ld State: %d\n", __FILE__,__LINE__, p-file, cs); }
#line 27 "graph.ragel"
	{ printf("ERROR %s:%d Pos: %ld State: %d\n", __FILE__,__LINE__, p-file, cs); }
#line 48 "graph.ragel"
	{ printf("ERROR %s:%d Pos: %ld State: %d\n", __FILE__,__LINE__, p-file, cs); }
#line 101 "graph.ragel"
	{ printf("ERROR %s:%d Pos: %ld State: %d\n", __FILE__,__LINE__, p-file, cs); }
	goto st0;
tr117:
#line 79 "graph.ragel"
	{ printf("ERROR %s:%d Pos: %ld State: %d\n", __FILE__,__LINE__, p-file, cs); }
#line 123 "graph.ragel"
	{ printf("ERROR %s:%d Pos: %ld State: %d\n", __FILE__,__LINE__, p-file, cs); }
#line 101 "graph.ragel"
	{ printf("ERROR %s:%d Pos: %ld State: %d\n", __FILE__,__LINE__, p-file, cs); }
	goto st0;
tr146:
#line 123 "graph.ragel"
	{ printf("ERROR %s:%d Pos: %ld State: %d\n", __FILE__,__LINE__, p-file, cs); }
#line 27 "graph.ragel"
	{ printf("ERROR %s:%d Pos: %ld State: %d\n", __FILE__,__LINE__, p-file, cs); }
	goto st0;
tr155:
#line 27 "graph.ragel"
	{ printf("ERROR %s:%d Pos: %ld State: %d\n", __FILE__,__LINE__, p-file, cs); }
	goto st0;
tr158:
#line 123 "graph.ragel"
	{ printf("ERROR %s:%d Pos: %ld State: %d\n", __FILE__,__LINE__, p-file, cs); }
#line 48 "graph.ragel"
	{ printf("ERROR %s:%d Pos: %ld State: %d\n", __FILE__,__LINE__, p-file, cs); }
	goto st0;
tr167:
#line 123 "graph.ragel"
	{ printf("ERROR %s:%d Pos: %ld State: %d\n", __FILE__,__LINE__, p-file, cs); }
#line 27 "graph.ragel"
	{ printf("ERROR %s:%d Pos: %ld State: %d\n", __FILE__,__LINE__, p-file, cs); }
#line 48 "graph.ragel"
	{ printf("ERROR %s:%d Pos: %ld State: %d\n", __FILE__,__LINE__, p-file, cs); }
	goto st0;
tr194:
#line 123 "graph.ragel"
	{ printf("ERROR %s:%d Pos: %ld State: %d\n", __FILE__,__LINE__, p-file, cs); }
#line 79 "graph.ragel"
	{ printf("ERROR %s:%d Pos: %ld State: %d\n", __FILE__,__LINE__, p-file, cs); }
#line 101 "graph.ragel"
	{ printf("ERROR %s:%d Pos: %ld State: %d\n", __FILE__,__LINE__, p-file, cs); }
	goto st0;
tr212:
#line 123 "graph.ragel"
	{ printf("ERROR %s:%d Pos: %ld State: %d\n", __FILE__,__LINE__, p-file, cs); }
#line 58 "graph.ragel"
	{ printf("ERROR %s:%d Pos: %ld State: %d\n", __FILE__,__LINE__, p-file, cs); }
#line 79 "graph.ragel"
	{ printf("ERROR %s:%d Pos: %ld State: %d\n", __FILE__,__LINE__, p-file, cs); }
#line 101 "graph.ragel"
	{ printf("ERROR %s:%d Pos: %ld State: %d\n", __FILE__,__LINE__, p-file, cs); }
	goto st0;
#line 224 "graph_ragel.c"
st0:
cs = 0;
	goto _out;
st2:
	if ( ++p == pe )
		goto _test_eof2;
case 2:
	if ( (*p) == 105 )
		goto st3;
	goto st0;
st3:
	if ( ++p == pe )
		goto _test_eof3;
case 3:
	if ( (*p) == 103 )
		goto st4;
	goto st0;
st4:
	if ( ++p == pe )
		goto _test_eof4;
case 4:
	if ( (*p) == 114 )
		goto st5;
	goto st0;
st5:
	if ( ++p == pe )
		goto _test_eof5;
case 5:
	if ( (*p) == 97 )
		goto st6;
	goto st0;
st6:
	if ( ++p == pe )
		goto _test_eof6;
case 6:
	if ( (*p) == 112 )
		goto st7;
	goto st0;
st7:
	if ( ++p == pe )
		goto _test_eof7;
case 7:
	if ( (*p) == 104 )
		goto st8;
	goto st0;
st8:
	if ( ++p == pe )
		goto _test_eof8;
case 8:
	switch( (*p) ) {
		case 32: goto st8;
		case 34: goto st9;
		case 45: goto tr11;
		case 95: goto tr13;
		case 123: goto st12;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 10 )
			goto st8;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr13;
		} else if ( (*p) >= 65 )
			goto tr13;
	} else
		goto tr12;
	goto tr9;
st9:
	if ( ++p == pe )
		goto _test_eof9;
case 9:
	switch( (*p) ) {
		case 32: goto tr15;
		case 95: goto tr15;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr15;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr15;
		} else if ( (*p) >= 65 )
			goto tr15;
	} else
		goto tr15;
	goto tr9;
tr15:
#line 121 "graph.ragel"
	{ ts = p; }
	goto st10;
st10:
	if ( ++p == pe )
		goto _test_eof10;
case 10:
#line 321 "graph_ragel.c"
	switch( (*p) ) {
		case 32: goto st10;
		case 34: goto tr17;
		case 95: goto st10;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st10;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st10;
		} else if ( (*p) >= 65 )
			goto st10;
	} else
		goto st10;
	goto tr9;
tr17:
#line 122 "graph.ragel"
	{ strncpy(last_identifier, ts, p-ts);last_identifier[p-ts]=0; }
	goto st11;
st11:
	if ( ++p == pe )
		goto _test_eof11;
case 11:
#line 347 "graph_ragel.c"
	switch( (*p) ) {
		case 32: goto st11;
		case 123: goto st12;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st11;
	goto st0;
tr197:
#line 122 "graph.ragel"
	{ strncpy(last_identifier, ts, p-ts);last_identifier[p-ts]=0; }
	goto st12;
tr33:
#line 51 "graph.ragel"
	{
        //printf("node_end: Nodo apilado: = %s",last_identifier);
        graph_add_vertex(last_identifier, NULL, g);
        //last_node = curr_node;
        curr_node = graph_find_vertex(last_identifier, g);
        //printf("  curr: = %d   last: = %d\n",curr_node, last_node);
    }
	goto st12;
tr51:
#line 51 "graph.ragel"
	{
        //printf("node_end: Nodo apilado: = %s",last_identifier);
        graph_add_vertex(last_identifier, NULL, g);
        //last_node = curr_node;
        curr_node = graph_find_vertex(last_identifier, g);
        //printf("  curr: = %d   last: = %d\n",curr_node, last_node);
    }
#line 81 "graph.ragel"
	{
        v_node[n_node]=curr_node;
        n_node++;
        if(n_node >= MAX_NUM_NODE)
            v_node = realloc(v_node, MAX_NUM_NODE*=2);
        printf("edge_end: Nodo apilado: = %d  [",curr_node);
        for(int i = 0; i < n_node; i++)
            printf("%d, ", v_node[i]);
        printf("]\n");
        printf("{\n");
        for(int i = 0; i < n_node-1; i++)
        {
            graph_add_edge_iw(v_node[i], v_node[i+1], NULL, edge_type,weight, g);
            printf("   Edge added (%d, %d)\tw:%f\n" , v_node[i], v_node[i+1], weight);
        }
        printf("}\n\n");
        weight = default_weight;
        n_node = 0;
        
    }
	goto st12;
tr64:
#line 81 "graph.ragel"
	{
        v_node[n_node]=curr_node;
        n_node++;
        if(n_node >= MAX_NUM_NODE)
            v_node = realloc(v_node, MAX_NUM_NODE*=2);
        printf("edge_end: Nodo apilado: = %d  [",curr_node);
        for(int i = 0; i < n_node; i++)
            printf("%d, ", v_node[i]);
        printf("]\n");
        printf("{\n");
        for(int i = 0; i < n_node-1; i++)
        {
            graph_add_edge_iw(v_node[i], v_node[i+1], NULL, edge_type,weight, g);
            printf("   Edge added (%d, %d)\tw:%f\n" , v_node[i], v_node[i+1], weight);
        }
        printf("}\n\n");
        weight = default_weight;
        n_node = 0;
        
    }
	goto st12;
tr121:
#line 122 "graph.ragel"
	{ strncpy(last_identifier, ts, p-ts);last_identifier[p-ts]=0; }
#line 81 "graph.ragel"
	{
        v_node[n_node]=curr_node;
        n_node++;
        if(n_node >= MAX_NUM_NODE)
            v_node = realloc(v_node, MAX_NUM_NODE*=2);
        printf("edge_end: Nodo apilado: = %d  [",curr_node);
        for(int i = 0; i < n_node; i++)
            printf("%d, ", v_node[i]);
        printf("]\n");
        printf("{\n");
        for(int i = 0; i < n_node-1; i++)
        {
            graph_add_edge_iw(v_node[i], v_node[i+1], NULL, edge_type,weight, g);
            printf("   Edge added (%d, %d)\tw:%f\n" , v_node[i], v_node[i+1], weight);
        }
        printf("}\n\n");
        weight = default_weight;
        n_node = 0;
        
    }
	goto st12;
tr215:
#line 122 "graph.ragel"
	{ strncpy(last_identifier, ts, p-ts);last_identifier[p-ts]=0; }
#line 51 "graph.ragel"
	{
        //printf("node_end: Nodo apilado: = %s",last_identifier);
        graph_add_vertex(last_identifier, NULL, g);
        //last_node = curr_node;
        curr_node = graph_find_vertex(last_identifier, g);
        //printf("  curr: = %d   last: = %d\n",curr_node, last_node);
    }
	goto st12;
tr128:
#line 122 "graph.ragel"
	{ strncpy(last_identifier, ts, p-ts);last_identifier[p-ts]=0; }
#line 51 "graph.ragel"
	{
        //printf("node_end: Nodo apilado: = %s",last_identifier);
        graph_add_vertex(last_identifier, NULL, g);
        //last_node = curr_node;
        curr_node = graph_find_vertex(last_identifier, g);
        //printf("  curr: = %d   last: = %d\n",curr_node, last_node);
    }
#line 81 "graph.ragel"
	{
        v_node[n_node]=curr_node;
        n_node++;
        if(n_node >= MAX_NUM_NODE)
            v_node = realloc(v_node, MAX_NUM_NODE*=2);
        printf("edge_end: Nodo apilado: = %d  [",curr_node);
        for(int i = 0; i < n_node; i++)
            printf("%d, ", v_node[i]);
        printf("]\n");
        printf("{\n");
        for(int i = 0; i < n_node-1; i++)
        {
            graph_add_edge_iw(v_node[i], v_node[i+1], NULL, edge_type,weight, g);
            printf("   Edge added (%d, %d)\tw:%f\n" , v_node[i], v_node[i+1], weight);
        }
        printf("}\n\n");
        weight = default_weight;
        n_node = 0;
        
    }
	goto st12;
tr254:
#line 116 "graph.ragel"
	{
        printf("ALLERT!! weight default changed: %d\n", default_weight);
        default_weight = weight;
    }
	goto st12;
st12:
	if ( ++p == pe )
		goto _test_eof12;
case 12:
#line 504 "graph_ragel.c"
	switch( (*p) ) {
		case 32: goto st12;
		case 34: goto st13;
		case 45: goto tr21;
		case 95: goto tr23;
		case 101: goto tr24;
		case 125: goto st147;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 10 )
			goto st12;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr23;
		} else if ( (*p) >= 65 )
			goto tr23;
	} else
		goto tr22;
	goto tr19;
st13:
	if ( ++p == pe )
		goto _test_eof13;
case 13:
	switch( (*p) ) {
		case 32: goto tr26;
		case 95: goto tr26;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr26;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr26;
		} else if ( (*p) >= 65 )
			goto tr26;
	} else
		goto tr26;
	goto tr19;
tr26:
#line 121 "graph.ragel"
	{ ts = p; }
	goto st14;
st14:
	if ( ++p == pe )
		goto _test_eof14;
case 14:
#line 553 "graph_ragel.c"
	switch( (*p) ) {
		case 32: goto st14;
		case 34: goto tr28;
		case 95: goto st14;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st14;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st14;
		} else if ( (*p) >= 65 )
			goto st14;
	} else
		goto st14;
	goto tr19;
tr28:
#line 122 "graph.ragel"
	{ strncpy(last_identifier, ts, p-ts);last_identifier[p-ts]=0; }
	goto st15;
st15:
	if ( ++p == pe )
		goto _test_eof15;
case 15:
#line 579 "graph_ragel.c"
	switch( (*p) ) {
		case 32: goto st15;
		case 45: goto tr31;
		case 58: goto tr32;
		case 59: goto tr33;
		case 61: goto st97;
		case 91: goto tr35;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st15;
	goto tr29;
tr31:
#line 51 "graph.ragel"
	{
        //printf("node_end: Nodo apilado: = %s",last_identifier);
        graph_add_vertex(last_identifier, NULL, g);
        //last_node = curr_node;
        curr_node = graph_find_vertex(last_identifier, g);
        //printf("  curr: = %d   last: = %d\n",curr_node, last_node);
    }
#line 60 "graph.ragel"
	{ ts = p; }
	goto st16;
tr62:
#line 60 "graph.ragel"
	{ ts = p; }
	goto st16;
tr118:
#line 122 "graph.ragel"
	{ strncpy(last_identifier, ts, p-ts);last_identifier[p-ts]=0; }
#line 60 "graph.ragel"
	{ ts = p; }
	goto st16;
tr125:
#line 122 "graph.ragel"
	{ strncpy(last_identifier, ts, p-ts);last_identifier[p-ts]=0; }
#line 51 "graph.ragel"
	{
        //printf("node_end: Nodo apilado: = %s",last_identifier);
        graph_add_vertex(last_identifier, NULL, g);
        //last_node = curr_node;
        curr_node = graph_find_vertex(last_identifier, g);
        //printf("  curr: = %d   last: = %d\n",curr_node, last_node);
    }
#line 60 "graph.ragel"
	{ ts = p; }
	goto st16;
st16:
	if ( ++p == pe )
		goto _test_eof16;
case 16:
#line 631 "graph_ragel.c"
	switch( (*p) ) {
		case 45: goto st17;
		case 62: goto st17;
	}
	goto tr36;
st17:
	if ( ++p == pe )
		goto _test_eof17;
case 17:
	switch( (*p) ) {
		case 9: goto st17;
		case 32: goto st17;
		case 34: goto tr39;
		case 45: goto tr40;
		case 95: goto tr42;
		case 101: goto tr43;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr41;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr42;
	} else
		goto tr42;
	goto tr38;
tr39:
#line 61 "graph.ragel"
	{
        if(!strncmp(ts, "--", p-ts))
            edge_type = GRAPH_EDGE_NON_DIRECTED;
        else
            edge_type = GRAPH_EDGE_DIRECTED;
            
        v_node[n_node]=curr_node;
        n_node++;
        if(n_node >= MAX_NUM_NODE)
            v_node = realloc(v_node, MAX_NUM_NODE*=2);
        
        printf("edge_type_end: Nodo apilado: = %d  [",curr_node);
        for(int i = 0; i < n_node; i++)
            printf("%d, ", v_node[i]);
        printf("]\n");
        //printf("find -- or ->. curr= %d\n",curr_node);
        
    }
	goto st18;
st18:
	if ( ++p == pe )
		goto _test_eof18;
case 18:
#line 683 "graph_ragel.c"
	switch( (*p) ) {
		case 32: goto tr45;
		case 95: goto tr45;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr45;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr45;
		} else if ( (*p) >= 65 )
			goto tr45;
	} else
		goto tr45;
	goto tr44;
tr45:
#line 121 "graph.ragel"
	{ ts = p; }
	goto st19;
st19:
	if ( ++p == pe )
		goto _test_eof19;
case 19:
#line 708 "graph_ragel.c"
	switch( (*p) ) {
		case 32: goto st19;
		case 34: goto tr47;
		case 95: goto st19;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st19;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st19;
		} else if ( (*p) >= 65 )
			goto st19;
	} else
		goto st19;
	goto tr44;
tr47:
#line 122 "graph.ragel"
	{ strncpy(last_identifier, ts, p-ts);last_identifier[p-ts]=0; }
	goto st20;
st20:
	if ( ++p == pe )
		goto _test_eof20;
case 20:
#line 734 "graph_ragel.c"
	switch( (*p) ) {
		case 32: goto st20;
		case 45: goto tr31;
		case 58: goto tr50;
		case 59: goto tr51;
		case 91: goto tr52;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st20;
	goto tr48;
tr50:
#line 51 "graph.ragel"
	{
        //printf("node_end: Nodo apilado: = %s",last_identifier);
        graph_add_vertex(last_identifier, NULL, g);
        //last_node = curr_node;
        curr_node = graph_find_vertex(last_identifier, g);
        //printf("  curr: = %d   last: = %d\n",curr_node, last_node);
    }
	goto st21;
tr127:
#line 122 "graph.ragel"
	{ strncpy(last_identifier, ts, p-ts);last_identifier[p-ts]=0; }
#line 51 "graph.ragel"
	{
        //printf("node_end: Nodo apilado: = %s",last_identifier);
        graph_add_vertex(last_identifier, NULL, g);
        //last_node = curr_node;
        curr_node = graph_find_vertex(last_identifier, g);
        //printf("  curr: = %d   last: = %d\n",curr_node, last_node);
    }
	goto st21;
st21:
	if ( ++p == pe )
		goto _test_eof21;
case 21:
#line 771 "graph_ragel.c"
	switch( (*p) ) {
		case 34: goto st22;
		case 45: goto tr55;
		case 95: goto tr57;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr56;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr57;
	} else
		goto tr57;
	goto tr53;
st22:
	if ( ++p == pe )
		goto _test_eof22;
case 22:
	switch( (*p) ) {
		case 32: goto tr58;
		case 95: goto tr58;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr58;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr58;
		} else if ( (*p) >= 65 )
			goto tr58;
	} else
		goto tr58;
	goto tr53;
tr58:
#line 121 "graph.ragel"
	{ ts = p; }
	goto st23;
st23:
	if ( ++p == pe )
		goto _test_eof23;
case 23:
#line 814 "graph_ragel.c"
	switch( (*p) ) {
		case 32: goto st23;
		case 34: goto tr60;
		case 95: goto st23;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st23;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st23;
		} else if ( (*p) >= 65 )
			goto st23;
	} else
		goto st23;
	goto tr53;
tr60:
#line 122 "graph.ragel"
	{ strncpy(last_identifier, ts, p-ts);last_identifier[p-ts]=0; }
	goto st24;
st24:
	if ( ++p == pe )
		goto _test_eof24;
case 24:
#line 840 "graph_ragel.c"
	switch( (*p) ) {
		case 32: goto st24;
		case 45: goto tr62;
		case 58: goto st25;
		case 59: goto tr64;
		case 91: goto st27;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st24;
	goto tr36;
tr120:
#line 122 "graph.ragel"
	{ strncpy(last_identifier, ts, p-ts);last_identifier[p-ts]=0; }
	goto st25;
st25:
	if ( ++p == pe )
		goto _test_eof25;
case 25:
#line 859 "graph_ragel.c"
	switch( (*p) ) {
		case 95: goto st26;
		case 99: goto st26;
		case 101: goto st26;
		case 110: goto st50;
		case 115: goto st50;
		case 119: goto st26;
	}
	goto tr66;
st26:
	if ( ++p == pe )
		goto _test_eof26;
case 26:
	switch( (*p) ) {
		case 45: goto tr62;
		case 59: goto tr64;
		case 91: goto st27;
	}
	goto tr36;
tr122:
#line 122 "graph.ragel"
	{ strncpy(last_identifier, ts, p-ts);last_identifier[p-ts]=0; }
	goto st27;
tr52:
#line 51 "graph.ragel"
	{
        //printf("node_end: Nodo apilado: = %s",last_identifier);
        graph_add_vertex(last_identifier, NULL, g);
        //last_node = curr_node;
        curr_node = graph_find_vertex(last_identifier, g);
        //printf("  curr: = %d   last: = %d\n",curr_node, last_node);
    }
	goto st27;
tr93:
#line 30 "graph.ragel"
	{
        
        switch(label_type)
        {
            case TYPE_LABEL:
                weight = atof(last_identifier);
                printf("weight: %f, \"%s\"\n", weight, last_identifier);
                break;
            case TYPE_DIR:
                //if (!strncmp(last_identifier, "none",sizeof(field_name)))
                    
                break;
            case TYPE_NONE:
            default:
                
                break;
        }
    }
	goto st27;
tr104:
#line 122 "graph.ragel"
	{ strncpy(last_identifier, ts, p-ts);last_identifier[p-ts]=0; }
#line 30 "graph.ragel"
	{
        
        switch(label_type)
        {
            case TYPE_LABEL:
                weight = atof(last_identifier);
                printf("weight: %f, \"%s\"\n", weight, last_identifier);
                break;
            case TYPE_DIR:
                //if (!strncmp(last_identifier, "none",sizeof(field_name)))
                    
                break;
            case TYPE_NONE:
            default:
                
                break;
        }
    }
	goto st27;
tr129:
#line 122 "graph.ragel"
	{ strncpy(last_identifier, ts, p-ts);last_identifier[p-ts]=0; }
#line 51 "graph.ragel"
	{
        //printf("node_end: Nodo apilado: = %s",last_identifier);
        graph_add_vertex(last_identifier, NULL, g);
        //last_node = curr_node;
        curr_node = graph_find_vertex(last_identifier, g);
        //printf("  curr: = %d   last: = %d\n",curr_node, last_node);
    }
	goto st27;
st27:
	if ( ++p == pe )
		goto _test_eof27;
case 27:
#line 953 "graph_ragel.c"
	switch( (*p) ) {
		case 32: goto st27;
		case 34: goto tr70;
		case 45: goto tr71;
		case 93: goto st39;
		case 95: goto tr73;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 10 )
			goto st27;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr73;
		} else if ( (*p) >= 65 )
			goto tr73;
	} else
		goto tr72;
	goto tr69;
tr70:
#line 16 "graph.ragel"
	{ ts = p; }
	goto st28;
tr92:
#line 30 "graph.ragel"
	{
        
        switch(label_type)
        {
            case TYPE_LABEL:
                weight = atof(last_identifier);
                printf("weight: %f, \"%s\"\n", weight, last_identifier);
                break;
            case TYPE_DIR:
                //if (!strncmp(last_identifier, "none",sizeof(field_name)))
                    
                break;
            case TYPE_NONE:
            default:
                
                break;
        }
    }
#line 16 "graph.ragel"
	{ ts = p; }
	goto st28;
tr103:
#line 122 "graph.ragel"
	{ strncpy(last_identifier, ts, p-ts);last_identifier[p-ts]=0; }
#line 30 "graph.ragel"
	{
        
        switch(label_type)
        {
            case TYPE_LABEL:
                weight = atof(last_identifier);
                printf("weight: %f, \"%s\"\n", weight, last_identifier);
                break;
            case TYPE_DIR:
                //if (!strncmp(last_identifier, "none",sizeof(field_name)))
                    
                break;
            case TYPE_NONE:
            default:
                
                break;
        }
    }
#line 16 "graph.ragel"
	{ ts = p; }
	goto st28;
st28:
	if ( ++p == pe )
		goto _test_eof28;
case 28:
#line 1029 "graph_ragel.c"
	switch( (*p) ) {
		case 32: goto tr75;
		case 95: goto tr75;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr75;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr75;
		} else if ( (*p) >= 65 )
			goto tr75;
	} else
		goto tr75;
	goto tr69;
tr75:
#line 121 "graph.ragel"
	{ ts = p; }
	goto st29;
st29:
	if ( ++p == pe )
		goto _test_eof29;
case 29:
#line 1054 "graph_ragel.c"
	switch( (*p) ) {
		case 32: goto st29;
		case 34: goto tr77;
		case 95: goto st29;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st29;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st29;
		} else if ( (*p) >= 65 )
			goto st29;
	} else
		goto st29;
	goto tr69;
tr77:
#line 122 "graph.ragel"
	{ strncpy(last_identifier, ts, p-ts);last_identifier[p-ts]=0; }
	goto st30;
st30:
	if ( ++p == pe )
		goto _test_eof30;
case 30:
#line 1080 "graph_ragel.c"
	switch( (*p) ) {
		case 32: goto st30;
		case 61: goto tr80;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st30;
	goto tr78;
tr80:
#line 17 "graph.ragel"
	{ 
        //printf("attr: %s\n", last_identifier);
        if (!strncmp(last_identifier, "label",sizeof(last_identifier))) 
            label_type = TYPE_LABEL;
        else if (!strncmp(last_identifier, "dir",sizeof(last_identifier))) 
            label_type = TYPE_DIR;
        else
            label_type = TYPE_NONE;
            
    }
	goto st31;
tr100:
#line 122 "graph.ragel"
	{ strncpy(last_identifier, ts, p-ts);last_identifier[p-ts]=0; }
#line 17 "graph.ragel"
	{ 
        //printf("attr: %s\n", last_identifier);
        if (!strncmp(last_identifier, "label",sizeof(last_identifier))) 
            label_type = TYPE_LABEL;
        else if (!strncmp(last_identifier, "dir",sizeof(last_identifier))) 
            label_type = TYPE_DIR;
        else
            label_type = TYPE_NONE;
            
    }
	goto st31;
st31:
	if ( ++p == pe )
		goto _test_eof31;
case 31:
#line 1120 "graph_ragel.c"
	switch( (*p) ) {
		case 32: goto st31;
		case 34: goto tr83;
		case 45: goto tr84;
		case 95: goto tr86;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 10 )
			goto st31;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr86;
		} else if ( (*p) >= 65 )
			goto tr86;
	} else
		goto tr85;
	goto tr81;
tr83:
#line 29 "graph.ragel"
	{ ts = p; }
	goto st32;
st32:
	if ( ++p == pe )
		goto _test_eof32;
case 32:
#line 1147 "graph_ragel.c"
	switch( (*p) ) {
		case 32: goto tr87;
		case 95: goto tr87;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr87;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr87;
		} else if ( (*p) >= 65 )
			goto tr87;
	} else
		goto tr87;
	goto tr81;
tr87:
#line 121 "graph.ragel"
	{ ts = p; }
	goto st33;
st33:
	if ( ++p == pe )
		goto _test_eof33;
case 33:
#line 1172 "graph_ragel.c"
	switch( (*p) ) {
		case 32: goto st33;
		case 34: goto tr89;
		case 95: goto st33;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st33;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st33;
		} else if ( (*p) >= 65 )
			goto st33;
	} else
		goto st33;
	goto tr81;
tr89:
#line 122 "graph.ragel"
	{ strncpy(last_identifier, ts, p-ts);last_identifier[p-ts]=0; }
	goto st34;
st34:
	if ( ++p == pe )
		goto _test_eof34;
case 34:
#line 1198 "graph_ragel.c"
	switch( (*p) ) {
		case 32: goto st34;
		case 34: goto tr92;
		case 44: goto tr93;
		case 45: goto tr94;
		case 93: goto tr97;
		case 95: goto tr96;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 10 )
			goto st34;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr96;
		} else if ( (*p) >= 65 )
			goto tr96;
	} else
		goto tr95;
	goto tr90;
tr71:
#line 16 "graph.ragel"
	{ ts = p; }
#line 121 "graph.ragel"
	{ ts = p; }
	goto st35;
tr94:
#line 30 "graph.ragel"
	{
        
        switch(label_type)
        {
            case TYPE_LABEL:
                weight = atof(last_identifier);
                printf("weight: %f, \"%s\"\n", weight, last_identifier);
                break;
            case TYPE_DIR:
                //if (!strncmp(last_identifier, "none",sizeof(field_name)))
                    
                break;
            case TYPE_NONE:
            default:
                
                break;
        }
    }
#line 16 "graph.ragel"
	{ ts = p; }
#line 121 "graph.ragel"
	{ ts = p; }
	goto st35;
tr105:
#line 122 "graph.ragel"
	{ strncpy(last_identifier, ts, p-ts);last_identifier[p-ts]=0; }
#line 30 "graph.ragel"
	{
        
        switch(label_type)
        {
            case TYPE_LABEL:
                weight = atof(last_identifier);
                printf("weight: %f, \"%s\"\n", weight, last_identifier);
                break;
            case TYPE_DIR:
                //if (!strncmp(last_identifier, "none",sizeof(field_name)))
                    
                break;
            case TYPE_NONE:
            default:
                
                break;
        }
    }
#line 16 "graph.ragel"
	{ ts = p; }
#line 121 "graph.ragel"
	{ ts = p; }
	goto st35;
st35:
	if ( ++p == pe )
		goto _test_eof35;
case 35:
#line 1281 "graph_ragel.c"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st36;
	goto tr69;
tr72:
#line 16 "graph.ragel"
	{ ts = p; }
#line 121 "graph.ragel"
	{ ts = p; }
	goto st36;
tr95:
#line 30 "graph.ragel"
	{
        
        switch(label_type)
        {
            case TYPE_LABEL:
                weight = atof(last_identifier);
                printf("weight: %f, \"%s\"\n", weight, last_identifier);
                break;
            case TYPE_DIR:
                //if (!strncmp(last_identifier, "none",sizeof(field_name)))
                    
                break;
            case TYPE_NONE:
            default:
                
                break;
        }
    }
#line 16 "graph.ragel"
	{ ts = p; }
#line 121 "graph.ragel"
	{ ts = p; }
	goto st36;
st36:
	if ( ++p == pe )
		goto _test_eof36;
case 36:
#line 1320 "graph_ragel.c"
	switch( (*p) ) {
		case 32: goto tr77;
		case 46: goto st37;
		case 61: goto tr100;
	}
	if ( (*p) > 10 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st36;
	} else if ( (*p) >= 9 )
		goto tr77;
	goto tr69;
st37:
	if ( ++p == pe )
		goto _test_eof37;
case 37:
	switch( (*p) ) {
		case 32: goto tr77;
		case 61: goto tr100;
	}
	if ( (*p) > 10 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st37;
	} else if ( (*p) >= 9 )
		goto tr77;
	goto tr69;
tr73:
#line 16 "graph.ragel"
	{ ts = p; }
#line 121 "graph.ragel"
	{ ts = p; }
	goto st38;
tr96:
#line 30 "graph.ragel"
	{
        
        switch(label_type)
        {
            case TYPE_LABEL:
                weight = atof(last_identifier);
                printf("weight: %f, \"%s\"\n", weight, last_identifier);
                break;
            case TYPE_DIR:
                //if (!strncmp(last_identifier, "none",sizeof(field_name)))
                    
                break;
            case TYPE_NONE:
            default:
                
                break;
        }
    }
#line 16 "graph.ragel"
	{ ts = p; }
#line 121 "graph.ragel"
	{ ts = p; }
	goto st38;
tr108:
#line 122 "graph.ragel"
	{ strncpy(last_identifier, ts, p-ts);last_identifier[p-ts]=0; }
#line 30 "graph.ragel"
	{
        
        switch(label_type)
        {
            case TYPE_LABEL:
                weight = atof(last_identifier);
                printf("weight: %f, \"%s\"\n", weight, last_identifier);
                break;
            case TYPE_DIR:
                //if (!strncmp(last_identifier, "none",sizeof(field_name)))
                    
                break;
            case TYPE_NONE:
            default:
                
                break;
        }
    }
#line 16 "graph.ragel"
	{ ts = p; }
#line 121 "graph.ragel"
	{ ts = p; }
	goto st38;
st38:
	if ( ++p == pe )
		goto _test_eof38;
case 38:
#line 1408 "graph_ragel.c"
	switch( (*p) ) {
		case 32: goto tr77;
		case 61: goto tr100;
		case 95: goto st38;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 10 )
			goto tr77;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st38;
		} else if ( (*p) >= 65 )
			goto st38;
	} else
		goto st38;
	goto tr69;
tr97:
#line 30 "graph.ragel"
	{
        
        switch(label_type)
        {
            case TYPE_LABEL:
                weight = atof(last_identifier);
                printf("weight: %f, \"%s\"\n", weight, last_identifier);
                break;
            case TYPE_DIR:
                //if (!strncmp(last_identifier, "none",sizeof(field_name)))
                    
                break;
            case TYPE_NONE:
            default:
                
                break;
        }
    }
	goto st39;
tr109:
#line 122 "graph.ragel"
	{ strncpy(last_identifier, ts, p-ts);last_identifier[p-ts]=0; }
#line 30 "graph.ragel"
	{
        
        switch(label_type)
        {
            case TYPE_LABEL:
                weight = atof(last_identifier);
                printf("weight: %f, \"%s\"\n", weight, last_identifier);
                break;
            case TYPE_DIR:
                //if (!strncmp(last_identifier, "none",sizeof(field_name)))
                    
                break;
            case TYPE_NONE:
            default:
                
                break;
        }
    }
	goto st39;
st39:
	if ( ++p == pe )
		goto _test_eof39;
case 39:
#line 1474 "graph_ragel.c"
	switch( (*p) ) {
		case 32: goto st39;
		case 59: goto tr64;
		case 91: goto st27;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st39;
	goto tr66;
tr84:
#line 29 "graph.ragel"
	{ ts = p; }
#line 121 "graph.ragel"
	{ ts = p; }
	goto st40;
st40:
	if ( ++p == pe )
		goto _test_eof40;
case 40:
#line 1493 "graph_ragel.c"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st41;
	goto tr81;
tr85:
#line 29 "graph.ragel"
	{ ts = p; }
#line 121 "graph.ragel"
	{ ts = p; }
	goto st41;
st41:
	if ( ++p == pe )
		goto _test_eof41;
case 41:
#line 1507 "graph_ragel.c"
	switch( (*p) ) {
		case 32: goto tr89;
		case 34: goto tr103;
		case 44: goto tr104;
		case 45: goto tr105;
		case 46: goto st42;
		case 93: goto tr109;
		case 95: goto tr108;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 10 )
			goto tr89;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr108;
		} else if ( (*p) >= 65 )
			goto tr108;
	} else
		goto tr107;
	goto tr90;
st42:
	if ( ++p == pe )
		goto _test_eof42;
case 42:
	switch( (*p) ) {
		case 32: goto tr89;
		case 34: goto tr103;
		case 44: goto tr104;
		case 45: goto tr105;
		case 93: goto tr109;
		case 95: goto tr108;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 10 )
			goto tr89;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr108;
		} else if ( (*p) >= 65 )
			goto tr108;
	} else
		goto tr110;
	goto tr90;
tr110:
#line 122 "graph.ragel"
	{ strncpy(last_identifier, ts, p-ts);last_identifier[p-ts]=0; }
#line 30 "graph.ragel"
	{
        
        switch(label_type)
        {
            case TYPE_LABEL:
                weight = atof(last_identifier);
                printf("weight: %f, \"%s\"\n", weight, last_identifier);
                break;
            case TYPE_DIR:
                //if (!strncmp(last_identifier, "none",sizeof(field_name)))
                    
                break;
            case TYPE_NONE:
            default:
                
                break;
        }
    }
#line 16 "graph.ragel"
	{ ts = p; }
#line 121 "graph.ragel"
	{ ts = p; }
	goto st43;
st43:
	if ( ++p == pe )
		goto _test_eof43;
case 43:
#line 1584 "graph_ragel.c"
	switch( (*p) ) {
		case 32: goto tr111;
		case 34: goto tr103;
		case 44: goto tr104;
		case 45: goto tr105;
		case 46: goto st37;
		case 61: goto tr100;
		case 93: goto tr109;
		case 95: goto tr108;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 10 )
			goto tr111;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr108;
		} else if ( (*p) >= 65 )
			goto tr108;
	} else
		goto tr110;
	goto tr90;
tr111:
#line 122 "graph.ragel"
	{ strncpy(last_identifier, ts, p-ts);last_identifier[p-ts]=0; }
	goto st44;
st44:
	if ( ++p == pe )
		goto _test_eof44;
case 44:
#line 1615 "graph_ragel.c"
	switch( (*p) ) {
		case 32: goto st44;
		case 34: goto tr92;
		case 44: goto tr93;
		case 45: goto tr94;
		case 61: goto tr80;
		case 93: goto tr97;
		case 95: goto tr96;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 10 )
			goto st44;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr96;
		} else if ( (*p) >= 65 )
			goto tr96;
	} else
		goto tr95;
	goto tr90;
tr107:
#line 122 "graph.ragel"
	{ strncpy(last_identifier, ts, p-ts);last_identifier[p-ts]=0; }
#line 30 "graph.ragel"
	{
        
        switch(label_type)
        {
            case TYPE_LABEL:
                weight = atof(last_identifier);
                printf("weight: %f, \"%s\"\n", weight, last_identifier);
                break;
            case TYPE_DIR:
                //if (!strncmp(last_identifier, "none",sizeof(field_name)))
                    
                break;
            case TYPE_NONE:
            default:
                
                break;
        }
    }
#line 16 "graph.ragel"
	{ ts = p; }
#line 121 "graph.ragel"
	{ ts = p; }
	goto st45;
st45:
	if ( ++p == pe )
		goto _test_eof45;
case 45:
#line 1668 "graph_ragel.c"
	switch( (*p) ) {
		case 32: goto tr111;
		case 34: goto tr103;
		case 44: goto tr104;
		case 45: goto tr105;
		case 46: goto st46;
		case 61: goto tr100;
		case 93: goto tr109;
		case 95: goto tr108;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 10 )
			goto tr111;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr108;
		} else if ( (*p) >= 65 )
			goto tr108;
	} else
		goto tr107;
	goto tr90;
st46:
	if ( ++p == pe )
		goto _test_eof46;
case 46:
	switch( (*p) ) {
		case 32: goto tr111;
		case 34: goto tr103;
		case 44: goto tr104;
		case 45: goto tr105;
		case 61: goto tr100;
		case 93: goto tr109;
		case 95: goto tr108;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 10 )
			goto tr111;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr108;
		} else if ( (*p) >= 65 )
			goto tr108;
	} else
		goto tr110;
	goto tr90;
tr86:
#line 29 "graph.ragel"
	{ ts = p; }
#line 121 "graph.ragel"
	{ ts = p; }
	goto st47;
st47:
	if ( ++p == pe )
		goto _test_eof47;
case 47:
#line 1726 "graph_ragel.c"
	switch( (*p) ) {
		case 32: goto tr89;
		case 34: goto tr103;
		case 44: goto tr104;
		case 45: goto tr105;
		case 93: goto tr109;
		case 95: goto tr115;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 10 )
			goto tr89;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr115;
		} else if ( (*p) >= 65 )
			goto tr115;
	} else
		goto tr114;
	goto tr90;
tr114:
#line 122 "graph.ragel"
	{ strncpy(last_identifier, ts, p-ts);last_identifier[p-ts]=0; }
#line 30 "graph.ragel"
	{
        
        switch(label_type)
        {
            case TYPE_LABEL:
                weight = atof(last_identifier);
                printf("weight: %f, \"%s\"\n", weight, last_identifier);
                break;
            case TYPE_DIR:
                //if (!strncmp(last_identifier, "none",sizeof(field_name)))
                    
                break;
            case TYPE_NONE:
            default:
                
                break;
        }
    }
#line 16 "graph.ragel"
	{ ts = p; }
#line 121 "graph.ragel"
	{ ts = p; }
	goto st48;
st48:
	if ( ++p == pe )
		goto _test_eof48;
case 48:
#line 1778 "graph_ragel.c"
	switch( (*p) ) {
		case 32: goto tr111;
		case 34: goto tr103;
		case 44: goto tr104;
		case 45: goto tr105;
		case 46: goto st37;
		case 61: goto tr100;
		case 93: goto tr109;
		case 95: goto tr115;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 10 )
			goto tr111;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr115;
		} else if ( (*p) >= 65 )
			goto tr115;
	} else
		goto tr114;
	goto tr90;
tr115:
#line 122 "graph.ragel"
	{ strncpy(last_identifier, ts, p-ts);last_identifier[p-ts]=0; }
#line 30 "graph.ragel"
	{
        
        switch(label_type)
        {
            case TYPE_LABEL:
                weight = atof(last_identifier);
                printf("weight: %f, \"%s\"\n", weight, last_identifier);
                break;
            case TYPE_DIR:
                //if (!strncmp(last_identifier, "none",sizeof(field_name)))
                    
                break;
            case TYPE_NONE:
            default:
                
                break;
        }
    }
#line 16 "graph.ragel"
	{ ts = p; }
#line 121 "graph.ragel"
	{ ts = p; }
	goto st49;
st49:
	if ( ++p == pe )
		goto _test_eof49;
case 49:
#line 1832 "graph_ragel.c"
	switch( (*p) ) {
		case 32: goto tr111;
		case 34: goto tr103;
		case 44: goto tr104;
		case 45: goto tr105;
		case 61: goto tr100;
		case 93: goto tr109;
		case 95: goto tr115;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 10 )
			goto tr111;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr115;
		} else if ( (*p) >= 65 )
			goto tr115;
	} else
		goto tr114;
	goto tr90;
st50:
	if ( ++p == pe )
		goto _test_eof50;
case 50:
	switch( (*p) ) {
		case 45: goto tr62;
		case 59: goto tr64;
		case 91: goto st27;
		case 101: goto st26;
		case 119: goto st26;
	}
	goto tr36;
tr55:
#line 121 "graph.ragel"
	{ ts = p; }
	goto st51;
st51:
	if ( ++p == pe )
		goto _test_eof51;
case 51:
#line 1874 "graph_ragel.c"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st52;
	goto tr53;
tr56:
#line 121 "graph.ragel"
	{ ts = p; }
	goto st52;
st52:
	if ( ++p == pe )
		goto _test_eof52;
case 52:
#line 1886 "graph_ragel.c"
	switch( (*p) ) {
		case 32: goto tr60;
		case 45: goto tr118;
		case 46: goto st53;
		case 58: goto tr120;
		case 59: goto tr121;
		case 91: goto tr122;
	}
	if ( (*p) > 10 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st52;
	} else if ( (*p) >= 9 )
		goto tr60;
	goto tr117;
st53:
	if ( ++p == pe )
		goto _test_eof53;
case 53:
	switch( (*p) ) {
		case 32: goto tr60;
		case 45: goto tr118;
		case 58: goto tr120;
		case 59: goto tr121;
		case 91: goto tr122;
	}
	if ( (*p) > 10 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st53;
	} else if ( (*p) >= 9 )
		goto tr60;
	goto tr117;
tr57:
#line 121 "graph.ragel"
	{ ts = p; }
	goto st54;
st54:
	if ( ++p == pe )
		goto _test_eof54;
case 54:
#line 1926 "graph_ragel.c"
	switch( (*p) ) {
		case 32: goto tr60;
		case 45: goto tr118;
		case 58: goto tr120;
		case 59: goto tr121;
		case 91: goto tr122;
		case 95: goto st54;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 10 )
			goto tr60;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st54;
		} else if ( (*p) >= 65 )
			goto st54;
	} else
		goto st54;
	goto tr117;
tr40:
#line 61 "graph.ragel"
	{
        if(!strncmp(ts, "--", p-ts))
            edge_type = GRAPH_EDGE_NON_DIRECTED;
        else
            edge_type = GRAPH_EDGE_DIRECTED;
            
        v_node[n_node]=curr_node;
        n_node++;
        if(n_node >= MAX_NUM_NODE)
            v_node = realloc(v_node, MAX_NUM_NODE*=2);
        
        printf("edge_type_end: Nodo apilado: = %d  [",curr_node);
        for(int i = 0; i < n_node; i++)
            printf("%d, ", v_node[i]);
        printf("]\n");
        //printf("find -- or ->. curr= %d\n",curr_node);
        
    }
#line 121 "graph.ragel"
	{ ts = p; }
	goto st55;
st55:
	if ( ++p == pe )
		goto _test_eof55;
case 55:
#line 1974 "graph_ragel.c"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st56;
	goto tr44;
tr41:
#line 61 "graph.ragel"
	{
        if(!strncmp(ts, "--", p-ts))
            edge_type = GRAPH_EDGE_NON_DIRECTED;
        else
            edge_type = GRAPH_EDGE_DIRECTED;
            
        v_node[n_node]=curr_node;
        n_node++;
        if(n_node >= MAX_NUM_NODE)
            v_node = realloc(v_node, MAX_NUM_NODE*=2);
        
        printf("edge_type_end: Nodo apilado: = %d  [",curr_node);
        for(int i = 0; i < n_node; i++)
            printf("%d, ", v_node[i]);
        printf("]\n");
        //printf("find -- or ->. curr= %d\n",curr_node);
        
    }
#line 121 "graph.ragel"
	{ ts = p; }
	goto st56;
st56:
	if ( ++p == pe )
		goto _test_eof56;
case 56:
#line 2005 "graph_ragel.c"
	switch( (*p) ) {
		case 32: goto tr47;
		case 45: goto tr125;
		case 46: goto st57;
		case 58: goto tr127;
		case 59: goto tr128;
		case 91: goto tr129;
	}
	if ( (*p) > 10 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st56;
	} else if ( (*p) >= 9 )
		goto tr47;
	goto tr38;
st57:
	if ( ++p == pe )
		goto _test_eof57;
case 57:
	switch( (*p) ) {
		case 32: goto tr47;
		case 45: goto tr125;
		case 58: goto tr127;
		case 59: goto tr128;
		case 91: goto tr129;
	}
	if ( (*p) > 10 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st57;
	} else if ( (*p) >= 9 )
		goto tr47;
	goto tr38;
tr42:
#line 61 "graph.ragel"
	{
        if(!strncmp(ts, "--", p-ts))
            edge_type = GRAPH_EDGE_NON_DIRECTED;
        else
            edge_type = GRAPH_EDGE_DIRECTED;
            
        v_node[n_node]=curr_node;
        n_node++;
        if(n_node >= MAX_NUM_NODE)
            v_node = realloc(v_node, MAX_NUM_NODE*=2);
        
        printf("edge_type_end: Nodo apilado: = %d  [",curr_node);
        for(int i = 0; i < n_node; i++)
            printf("%d, ", v_node[i]);
        printf("]\n");
        //printf("find -- or ->. curr= %d\n",curr_node);
        
    }
#line 121 "graph.ragel"
	{ ts = p; }
	goto st58;
st58:
	if ( ++p == pe )
		goto _test_eof58;
case 58:
#line 2064 "graph_ragel.c"
	switch( (*p) ) {
		case 32: goto tr47;
		case 45: goto tr125;
		case 58: goto tr127;
		case 59: goto tr128;
		case 91: goto tr129;
		case 95: goto st58;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 10 )
			goto tr47;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st58;
		} else if ( (*p) >= 65 )
			goto st58;
	} else
		goto st58;
	goto tr38;
tr43:
#line 61 "graph.ragel"
	{
        if(!strncmp(ts, "--", p-ts))
            edge_type = GRAPH_EDGE_NON_DIRECTED;
        else
            edge_type = GRAPH_EDGE_DIRECTED;
            
        v_node[n_node]=curr_node;
        n_node++;
        if(n_node >= MAX_NUM_NODE)
            v_node = realloc(v_node, MAX_NUM_NODE*=2);
        
        printf("edge_type_end: Nodo apilado: = %d  [",curr_node);
        for(int i = 0; i < n_node; i++)
            printf("%d, ", v_node[i]);
        printf("]\n");
        //printf("find -- or ->. curr= %d\n",curr_node);
        
    }
#line 121 "graph.ragel"
	{ ts = p; }
	goto st59;
st59:
	if ( ++p == pe )
		goto _test_eof59;
case 59:
#line 2112 "graph_ragel.c"
	switch( (*p) ) {
		case 32: goto tr47;
		case 45: goto tr125;
		case 58: goto tr127;
		case 59: goto tr128;
		case 91: goto tr129;
		case 95: goto st58;
		case 100: goto st60;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 10 )
			goto tr47;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st58;
		} else if ( (*p) >= 65 )
			goto st58;
	} else
		goto st58;
	goto tr38;
st60:
	if ( ++p == pe )
		goto _test_eof60;
case 60:
	switch( (*p) ) {
		case 32: goto tr47;
		case 45: goto tr125;
		case 58: goto tr127;
		case 59: goto tr128;
		case 91: goto tr129;
		case 95: goto st58;
		case 103: goto st61;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 10 )
			goto tr47;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st58;
		} else if ( (*p) >= 65 )
			goto st58;
	} else
		goto st58;
	goto tr38;
st61:
	if ( ++p == pe )
		goto _test_eof61;
case 61:
	switch( (*p) ) {
		case 32: goto tr47;
		case 45: goto tr125;
		case 58: goto tr127;
		case 59: goto tr128;
		case 91: goto tr129;
		case 95: goto st58;
		case 101: goto st62;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 10 )
			goto tr47;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st58;
		} else if ( (*p) >= 65 )
			goto st58;
	} else
		goto st58;
	goto tr38;
st62:
	if ( ++p == pe )
		goto _test_eof62;
case 62:
	if ( (*p) == 95 )
		goto st58;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st58;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st58;
	} else
		goto st58;
	goto tr44;
tr32:
#line 51 "graph.ragel"
	{
        //printf("node_end: Nodo apilado: = %s",last_identifier);
        graph_add_vertex(last_identifier, NULL, g);
        //last_node = curr_node;
        curr_node = graph_find_vertex(last_identifier, g);
        //printf("  curr: = %d   last: = %d\n",curr_node, last_node);
    }
	goto st63;
tr214:
#line 122 "graph.ragel"
	{ strncpy(last_identifier, ts, p-ts);last_identifier[p-ts]=0; }
#line 51 "graph.ragel"
	{
        //printf("node_end: Nodo apilado: = %s",last_identifier);
        graph_add_vertex(last_identifier, NULL, g);
        //last_node = curr_node;
        curr_node = graph_find_vertex(last_identifier, g);
        //printf("  curr: = %d   last: = %d\n",curr_node, last_node);
    }
	goto st63;
st63:
	if ( ++p == pe )
		goto _test_eof63;
case 63:
#line 2225 "graph_ragel.c"
	switch( (*p) ) {
		case 34: goto st64;
		case 45: goto tr135;
		case 95: goto tr137;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr136;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr137;
	} else
		goto tr137;
	goto tr9;
st64:
	if ( ++p == pe )
		goto _test_eof64;
case 64:
	switch( (*p) ) {
		case 32: goto tr138;
		case 95: goto tr138;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr138;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr138;
		} else if ( (*p) >= 65 )
			goto tr138;
	} else
		goto tr138;
	goto tr9;
tr138:
#line 121 "graph.ragel"
	{ ts = p; }
	goto st65;
st65:
	if ( ++p == pe )
		goto _test_eof65;
case 65:
#line 2268 "graph_ragel.c"
	switch( (*p) ) {
		case 32: goto st65;
		case 34: goto tr140;
		case 95: goto st65;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st65;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st65;
		} else if ( (*p) >= 65 )
			goto st65;
	} else
		goto st65;
	goto tr9;
tr140:
#line 122 "graph.ragel"
	{ strncpy(last_identifier, ts, p-ts);last_identifier[p-ts]=0; }
	goto st66;
st66:
	if ( ++p == pe )
		goto _test_eof66;
case 66:
#line 2294 "graph_ragel.c"
	switch( (*p) ) {
		case 32: goto st66;
		case 45: goto tr62;
		case 58: goto st67;
		case 59: goto st12;
		case 91: goto st69;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st66;
	goto tr36;
tr196:
#line 122 "graph.ragel"
	{ strncpy(last_identifier, ts, p-ts);last_identifier[p-ts]=0; }
	goto st67;
st67:
	if ( ++p == pe )
		goto _test_eof67;
case 67:
#line 2313 "graph_ragel.c"
	switch( (*p) ) {
		case 95: goto st68;
		case 99: goto st68;
		case 101: goto st68;
		case 110: goto st92;
		case 115: goto st92;
		case 119: goto st68;
	}
	goto st0;
st68:
	if ( ++p == pe )
		goto _test_eof68;
case 68:
	switch( (*p) ) {
		case 45: goto tr62;
		case 59: goto st12;
		case 91: goto st69;
	}
	goto tr36;
tr198:
#line 122 "graph.ragel"
	{ strncpy(last_identifier, ts, p-ts);last_identifier[p-ts]=0; }
	goto st69;
tr35:
#line 51 "graph.ragel"
	{
        //printf("node_end: Nodo apilado: = %s",last_identifier);
        graph_add_vertex(last_identifier, NULL, g);
        //last_node = curr_node;
        curr_node = graph_find_vertex(last_identifier, g);
        //printf("  curr: = %d   last: = %d\n",curr_node, last_node);
    }
	goto st69;
tr170:
#line 30 "graph.ragel"
	{
        
        switch(label_type)
        {
            case TYPE_LABEL:
                weight = atof(last_identifier);
                printf("weight: %f, \"%s\"\n", weight, last_identifier);
                break;
            case TYPE_DIR:
                //if (!strncmp(last_identifier, "none",sizeof(field_name)))
                    
                break;
            case TYPE_NONE:
            default:
                
                break;
        }
    }
	goto st69;
tr181:
#line 122 "graph.ragel"
	{ strncpy(last_identifier, ts, p-ts);last_identifier[p-ts]=0; }
#line 30 "graph.ragel"
	{
        
        switch(label_type)
        {
            case TYPE_LABEL:
                weight = atof(last_identifier);
                printf("weight: %f, \"%s\"\n", weight, last_identifier);
                break;
            case TYPE_DIR:
                //if (!strncmp(last_identifier, "none",sizeof(field_name)))
                    
                break;
            case TYPE_NONE:
            default:
                
                break;
        }
    }
	goto st69;
tr217:
#line 122 "graph.ragel"
	{ strncpy(last_identifier, ts, p-ts);last_identifier[p-ts]=0; }
#line 51 "graph.ragel"
	{
        //printf("node_end: Nodo apilado: = %s",last_identifier);
        graph_add_vertex(last_identifier, NULL, g);
        //last_node = curr_node;
        curr_node = graph_find_vertex(last_identifier, g);
        //printf("  curr: = %d   last: = %d\n",curr_node, last_node);
    }
	goto st69;
st69:
	if ( ++p == pe )
		goto _test_eof69;
case 69:
#line 2407 "graph_ragel.c"
	switch( (*p) ) {
		case 32: goto st69;
		case 34: goto tr147;
		case 45: goto tr148;
		case 93: goto st81;
		case 95: goto tr150;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 10 )
			goto st69;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr150;
		} else if ( (*p) >= 65 )
			goto tr150;
	} else
		goto tr149;
	goto tr146;
tr147:
#line 16 "graph.ragel"
	{ ts = p; }
	goto st70;
tr169:
#line 30 "graph.ragel"
	{
        
        switch(label_type)
        {
            case TYPE_LABEL:
                weight = atof(last_identifier);
                printf("weight: %f, \"%s\"\n", weight, last_identifier);
                break;
            case TYPE_DIR:
                //if (!strncmp(last_identifier, "none",sizeof(field_name)))
                    
                break;
            case TYPE_NONE:
            default:
                
                break;
        }
    }
#line 16 "graph.ragel"
	{ ts = p; }
	goto st70;
tr180:
#line 122 "graph.ragel"
	{ strncpy(last_identifier, ts, p-ts);last_identifier[p-ts]=0; }
#line 30 "graph.ragel"
	{
        
        switch(label_type)
        {
            case TYPE_LABEL:
                weight = atof(last_identifier);
                printf("weight: %f, \"%s\"\n", weight, last_identifier);
                break;
            case TYPE_DIR:
                //if (!strncmp(last_identifier, "none",sizeof(field_name)))
                    
                break;
            case TYPE_NONE:
            default:
                
                break;
        }
    }
#line 16 "graph.ragel"
	{ ts = p; }
	goto st70;
st70:
	if ( ++p == pe )
		goto _test_eof70;
case 70:
#line 2483 "graph_ragel.c"
	switch( (*p) ) {
		case 32: goto tr152;
		case 95: goto tr152;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr152;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr152;
		} else if ( (*p) >= 65 )
			goto tr152;
	} else
		goto tr152;
	goto tr146;
tr152:
#line 121 "graph.ragel"
	{ ts = p; }
	goto st71;
st71:
	if ( ++p == pe )
		goto _test_eof71;
case 71:
#line 2508 "graph_ragel.c"
	switch( (*p) ) {
		case 32: goto st71;
		case 34: goto tr154;
		case 95: goto st71;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st71;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st71;
		} else if ( (*p) >= 65 )
			goto st71;
	} else
		goto st71;
	goto tr146;
tr154:
#line 122 "graph.ragel"
	{ strncpy(last_identifier, ts, p-ts);last_identifier[p-ts]=0; }
	goto st72;
st72:
	if ( ++p == pe )
		goto _test_eof72;
case 72:
#line 2534 "graph_ragel.c"
	switch( (*p) ) {
		case 32: goto st72;
		case 61: goto tr157;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st72;
	goto tr155;
tr157:
#line 17 "graph.ragel"
	{ 
        //printf("attr: %s\n", last_identifier);
        if (!strncmp(last_identifier, "label",sizeof(last_identifier))) 
            label_type = TYPE_LABEL;
        else if (!strncmp(last_identifier, "dir",sizeof(last_identifier))) 
            label_type = TYPE_DIR;
        else
            label_type = TYPE_NONE;
            
    }
	goto st73;
tr177:
#line 122 "graph.ragel"
	{ strncpy(last_identifier, ts, p-ts);last_identifier[p-ts]=0; }
#line 17 "graph.ragel"
	{ 
        //printf("attr: %s\n", last_identifier);
        if (!strncmp(last_identifier, "label",sizeof(last_identifier))) 
            label_type = TYPE_LABEL;
        else if (!strncmp(last_identifier, "dir",sizeof(last_identifier))) 
            label_type = TYPE_DIR;
        else
            label_type = TYPE_NONE;
            
    }
	goto st73;
st73:
	if ( ++p == pe )
		goto _test_eof73;
case 73:
#line 2574 "graph_ragel.c"
	switch( (*p) ) {
		case 32: goto st73;
		case 34: goto tr160;
		case 45: goto tr161;
		case 95: goto tr163;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 10 )
			goto st73;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr163;
		} else if ( (*p) >= 65 )
			goto tr163;
	} else
		goto tr162;
	goto tr158;
tr160:
#line 29 "graph.ragel"
	{ ts = p; }
	goto st74;
st74:
	if ( ++p == pe )
		goto _test_eof74;
case 74:
#line 2601 "graph_ragel.c"
	switch( (*p) ) {
		case 32: goto tr164;
		case 95: goto tr164;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr164;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr164;
		} else if ( (*p) >= 65 )
			goto tr164;
	} else
		goto tr164;
	goto tr158;
tr164:
#line 121 "graph.ragel"
	{ ts = p; }
	goto st75;
st75:
	if ( ++p == pe )
		goto _test_eof75;
case 75:
#line 2626 "graph_ragel.c"
	switch( (*p) ) {
		case 32: goto st75;
		case 34: goto tr166;
		case 95: goto st75;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st75;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st75;
		} else if ( (*p) >= 65 )
			goto st75;
	} else
		goto st75;
	goto tr158;
tr166:
#line 122 "graph.ragel"
	{ strncpy(last_identifier, ts, p-ts);last_identifier[p-ts]=0; }
	goto st76;
st76:
	if ( ++p == pe )
		goto _test_eof76;
case 76:
#line 2652 "graph_ragel.c"
	switch( (*p) ) {
		case 32: goto st76;
		case 34: goto tr169;
		case 44: goto tr170;
		case 45: goto tr171;
		case 93: goto tr174;
		case 95: goto tr173;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 10 )
			goto st76;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr173;
		} else if ( (*p) >= 65 )
			goto tr173;
	} else
		goto tr172;
	goto tr167;
tr148:
#line 16 "graph.ragel"
	{ ts = p; }
#line 121 "graph.ragel"
	{ ts = p; }
	goto st77;
tr171:
#line 30 "graph.ragel"
	{
        
        switch(label_type)
        {
            case TYPE_LABEL:
                weight = atof(last_identifier);
                printf("weight: %f, \"%s\"\n", weight, last_identifier);
                break;
            case TYPE_DIR:
                //if (!strncmp(last_identifier, "none",sizeof(field_name)))
                    
                break;
            case TYPE_NONE:
            default:
                
                break;
        }
    }
#line 16 "graph.ragel"
	{ ts = p; }
#line 121 "graph.ragel"
	{ ts = p; }
	goto st77;
tr182:
#line 122 "graph.ragel"
	{ strncpy(last_identifier, ts, p-ts);last_identifier[p-ts]=0; }
#line 30 "graph.ragel"
	{
        
        switch(label_type)
        {
            case TYPE_LABEL:
                weight = atof(last_identifier);
                printf("weight: %f, \"%s\"\n", weight, last_identifier);
                break;
            case TYPE_DIR:
                //if (!strncmp(last_identifier, "none",sizeof(field_name)))
                    
                break;
            case TYPE_NONE:
            default:
                
                break;
        }
    }
#line 16 "graph.ragel"
	{ ts = p; }
#line 121 "graph.ragel"
	{ ts = p; }
	goto st77;
st77:
	if ( ++p == pe )
		goto _test_eof77;
case 77:
#line 2735 "graph_ragel.c"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st78;
	goto tr146;
tr149:
#line 16 "graph.ragel"
	{ ts = p; }
#line 121 "graph.ragel"
	{ ts = p; }
	goto st78;
tr172:
#line 30 "graph.ragel"
	{
        
        switch(label_type)
        {
            case TYPE_LABEL:
                weight = atof(last_identifier);
                printf("weight: %f, \"%s\"\n", weight, last_identifier);
                break;
            case TYPE_DIR:
                //if (!strncmp(last_identifier, "none",sizeof(field_name)))
                    
                break;
            case TYPE_NONE:
            default:
                
                break;
        }
    }
#line 16 "graph.ragel"
	{ ts = p; }
#line 121 "graph.ragel"
	{ ts = p; }
	goto st78;
st78:
	if ( ++p == pe )
		goto _test_eof78;
case 78:
#line 2774 "graph_ragel.c"
	switch( (*p) ) {
		case 32: goto tr154;
		case 46: goto st79;
		case 61: goto tr177;
	}
	if ( (*p) > 10 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st78;
	} else if ( (*p) >= 9 )
		goto tr154;
	goto tr146;
st79:
	if ( ++p == pe )
		goto _test_eof79;
case 79:
	switch( (*p) ) {
		case 32: goto tr154;
		case 61: goto tr177;
	}
	if ( (*p) > 10 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st79;
	} else if ( (*p) >= 9 )
		goto tr154;
	goto tr146;
tr150:
#line 16 "graph.ragel"
	{ ts = p; }
#line 121 "graph.ragel"
	{ ts = p; }
	goto st80;
tr173:
#line 30 "graph.ragel"
	{
        
        switch(label_type)
        {
            case TYPE_LABEL:
                weight = atof(last_identifier);
                printf("weight: %f, \"%s\"\n", weight, last_identifier);
                break;
            case TYPE_DIR:
                //if (!strncmp(last_identifier, "none",sizeof(field_name)))
                    
                break;
            case TYPE_NONE:
            default:
                
                break;
        }
    }
#line 16 "graph.ragel"
	{ ts = p; }
#line 121 "graph.ragel"
	{ ts = p; }
	goto st80;
tr185:
#line 122 "graph.ragel"
	{ strncpy(last_identifier, ts, p-ts);last_identifier[p-ts]=0; }
#line 30 "graph.ragel"
	{
        
        switch(label_type)
        {
            case TYPE_LABEL:
                weight = atof(last_identifier);
                printf("weight: %f, \"%s\"\n", weight, last_identifier);
                break;
            case TYPE_DIR:
                //if (!strncmp(last_identifier, "none",sizeof(field_name)))
                    
                break;
            case TYPE_NONE:
            default:
                
                break;
        }
    }
#line 16 "graph.ragel"
	{ ts = p; }
#line 121 "graph.ragel"
	{ ts = p; }
	goto st80;
st80:
	if ( ++p == pe )
		goto _test_eof80;
case 80:
#line 2862 "graph_ragel.c"
	switch( (*p) ) {
		case 32: goto tr154;
		case 61: goto tr177;
		case 95: goto st80;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 10 )
			goto tr154;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st80;
		} else if ( (*p) >= 65 )
			goto st80;
	} else
		goto st80;
	goto tr146;
tr174:
#line 30 "graph.ragel"
	{
        
        switch(label_type)
        {
            case TYPE_LABEL:
                weight = atof(last_identifier);
                printf("weight: %f, \"%s\"\n", weight, last_identifier);
                break;
            case TYPE_DIR:
                //if (!strncmp(last_identifier, "none",sizeof(field_name)))
                    
                break;
            case TYPE_NONE:
            default:
                
                break;
        }
    }
	goto st81;
tr186:
#line 122 "graph.ragel"
	{ strncpy(last_identifier, ts, p-ts);last_identifier[p-ts]=0; }
#line 30 "graph.ragel"
	{
        
        switch(label_type)
        {
            case TYPE_LABEL:
                weight = atof(last_identifier);
                printf("weight: %f, \"%s\"\n", weight, last_identifier);
                break;
            case TYPE_DIR:
                //if (!strncmp(last_identifier, "none",sizeof(field_name)))
                    
                break;
            case TYPE_NONE:
            default:
                
                break;
        }
    }
	goto st81;
st81:
	if ( ++p == pe )
		goto _test_eof81;
case 81:
#line 2928 "graph_ragel.c"
	switch( (*p) ) {
		case 32: goto st81;
		case 59: goto st12;
		case 91: goto st69;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st81;
	goto st0;
tr161:
#line 29 "graph.ragel"
	{ ts = p; }
#line 121 "graph.ragel"
	{ ts = p; }
	goto st82;
st82:
	if ( ++p == pe )
		goto _test_eof82;
case 82:
#line 2947 "graph_ragel.c"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st83;
	goto tr158;
tr162:
#line 29 "graph.ragel"
	{ ts = p; }
#line 121 "graph.ragel"
	{ ts = p; }
	goto st83;
st83:
	if ( ++p == pe )
		goto _test_eof83;
case 83:
#line 2961 "graph_ragel.c"
	switch( (*p) ) {
		case 32: goto tr166;
		case 34: goto tr180;
		case 44: goto tr181;
		case 45: goto tr182;
		case 46: goto st84;
		case 93: goto tr186;
		case 95: goto tr185;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 10 )
			goto tr166;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr185;
		} else if ( (*p) >= 65 )
			goto tr185;
	} else
		goto tr184;
	goto tr167;
st84:
	if ( ++p == pe )
		goto _test_eof84;
case 84:
	switch( (*p) ) {
		case 32: goto tr166;
		case 34: goto tr180;
		case 44: goto tr181;
		case 45: goto tr182;
		case 93: goto tr186;
		case 95: goto tr185;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 10 )
			goto tr166;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr185;
		} else if ( (*p) >= 65 )
			goto tr185;
	} else
		goto tr187;
	goto tr167;
tr187:
#line 122 "graph.ragel"
	{ strncpy(last_identifier, ts, p-ts);last_identifier[p-ts]=0; }
#line 30 "graph.ragel"
	{
        
        switch(label_type)
        {
            case TYPE_LABEL:
                weight = atof(last_identifier);
                printf("weight: %f, \"%s\"\n", weight, last_identifier);
                break;
            case TYPE_DIR:
                //if (!strncmp(last_identifier, "none",sizeof(field_name)))
                    
                break;
            case TYPE_NONE:
            default:
                
                break;
        }
    }
#line 16 "graph.ragel"
	{ ts = p; }
#line 121 "graph.ragel"
	{ ts = p; }
	goto st85;
st85:
	if ( ++p == pe )
		goto _test_eof85;
case 85:
#line 3038 "graph_ragel.c"
	switch( (*p) ) {
		case 32: goto tr188;
		case 34: goto tr180;
		case 44: goto tr181;
		case 45: goto tr182;
		case 46: goto st79;
		case 61: goto tr177;
		case 93: goto tr186;
		case 95: goto tr185;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 10 )
			goto tr188;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr185;
		} else if ( (*p) >= 65 )
			goto tr185;
	} else
		goto tr187;
	goto tr167;
tr188:
#line 122 "graph.ragel"
	{ strncpy(last_identifier, ts, p-ts);last_identifier[p-ts]=0; }
	goto st86;
st86:
	if ( ++p == pe )
		goto _test_eof86;
case 86:
#line 3069 "graph_ragel.c"
	switch( (*p) ) {
		case 32: goto st86;
		case 34: goto tr169;
		case 44: goto tr170;
		case 45: goto tr171;
		case 61: goto tr157;
		case 93: goto tr174;
		case 95: goto tr173;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 10 )
			goto st86;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr173;
		} else if ( (*p) >= 65 )
			goto tr173;
	} else
		goto tr172;
	goto tr167;
tr184:
#line 122 "graph.ragel"
	{ strncpy(last_identifier, ts, p-ts);last_identifier[p-ts]=0; }
#line 30 "graph.ragel"
	{
        
        switch(label_type)
        {
            case TYPE_LABEL:
                weight = atof(last_identifier);
                printf("weight: %f, \"%s\"\n", weight, last_identifier);
                break;
            case TYPE_DIR:
                //if (!strncmp(last_identifier, "none",sizeof(field_name)))
                    
                break;
            case TYPE_NONE:
            default:
                
                break;
        }
    }
#line 16 "graph.ragel"
	{ ts = p; }
#line 121 "graph.ragel"
	{ ts = p; }
	goto st87;
st87:
	if ( ++p == pe )
		goto _test_eof87;
case 87:
#line 3122 "graph_ragel.c"
	switch( (*p) ) {
		case 32: goto tr188;
		case 34: goto tr180;
		case 44: goto tr181;
		case 45: goto tr182;
		case 46: goto st88;
		case 61: goto tr177;
		case 93: goto tr186;
		case 95: goto tr185;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 10 )
			goto tr188;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr185;
		} else if ( (*p) >= 65 )
			goto tr185;
	} else
		goto tr184;
	goto tr167;
st88:
	if ( ++p == pe )
		goto _test_eof88;
case 88:
	switch( (*p) ) {
		case 32: goto tr188;
		case 34: goto tr180;
		case 44: goto tr181;
		case 45: goto tr182;
		case 61: goto tr177;
		case 93: goto tr186;
		case 95: goto tr185;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 10 )
			goto tr188;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr185;
		} else if ( (*p) >= 65 )
			goto tr185;
	} else
		goto tr187;
	goto tr167;
tr163:
#line 29 "graph.ragel"
	{ ts = p; }
#line 121 "graph.ragel"
	{ ts = p; }
	goto st89;
st89:
	if ( ++p == pe )
		goto _test_eof89;
case 89:
#line 3180 "graph_ragel.c"
	switch( (*p) ) {
		case 32: goto tr166;
		case 34: goto tr180;
		case 44: goto tr181;
		case 45: goto tr182;
		case 93: goto tr186;
		case 95: goto tr192;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 10 )
			goto tr166;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr192;
		} else if ( (*p) >= 65 )
			goto tr192;
	} else
		goto tr191;
	goto tr167;
tr191:
#line 122 "graph.ragel"
	{ strncpy(last_identifier, ts, p-ts);last_identifier[p-ts]=0; }
#line 30 "graph.ragel"
	{
        
        switch(label_type)
        {
            case TYPE_LABEL:
                weight = atof(last_identifier);
                printf("weight: %f, \"%s\"\n", weight, last_identifier);
                break;
            case TYPE_DIR:
                //if (!strncmp(last_identifier, "none",sizeof(field_name)))
                    
                break;
            case TYPE_NONE:
            default:
                
                break;
        }
    }
#line 16 "graph.ragel"
	{ ts = p; }
#line 121 "graph.ragel"
	{ ts = p; }
	goto st90;
st90:
	if ( ++p == pe )
		goto _test_eof90;
case 90:
#line 3232 "graph_ragel.c"
	switch( (*p) ) {
		case 32: goto tr188;
		case 34: goto tr180;
		case 44: goto tr181;
		case 45: goto tr182;
		case 46: goto st79;
		case 61: goto tr177;
		case 93: goto tr186;
		case 95: goto tr192;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 10 )
			goto tr188;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr192;
		} else if ( (*p) >= 65 )
			goto tr192;
	} else
		goto tr191;
	goto tr167;
tr192:
#line 122 "graph.ragel"
	{ strncpy(last_identifier, ts, p-ts);last_identifier[p-ts]=0; }
#line 30 "graph.ragel"
	{
        
        switch(label_type)
        {
            case TYPE_LABEL:
                weight = atof(last_identifier);
                printf("weight: %f, \"%s\"\n", weight, last_identifier);
                break;
            case TYPE_DIR:
                //if (!strncmp(last_identifier, "none",sizeof(field_name)))
                    
                break;
            case TYPE_NONE:
            default:
                
                break;
        }
    }
#line 16 "graph.ragel"
	{ ts = p; }
#line 121 "graph.ragel"
	{ ts = p; }
	goto st91;
st91:
	if ( ++p == pe )
		goto _test_eof91;
case 91:
#line 3286 "graph_ragel.c"
	switch( (*p) ) {
		case 32: goto tr188;
		case 34: goto tr180;
		case 44: goto tr181;
		case 45: goto tr182;
		case 61: goto tr177;
		case 93: goto tr186;
		case 95: goto tr192;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 10 )
			goto tr188;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr192;
		} else if ( (*p) >= 65 )
			goto tr192;
	} else
		goto tr191;
	goto tr167;
st92:
	if ( ++p == pe )
		goto _test_eof92;
case 92:
	switch( (*p) ) {
		case 45: goto tr62;
		case 59: goto st12;
		case 91: goto st69;
		case 101: goto st68;
		case 119: goto st68;
	}
	goto tr36;
tr135:
#line 121 "graph.ragel"
	{ ts = p; }
	goto st93;
st93:
	if ( ++p == pe )
		goto _test_eof93;
case 93:
#line 3328 "graph_ragel.c"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st94;
	goto tr9;
tr136:
#line 121 "graph.ragel"
	{ ts = p; }
	goto st94;
st94:
	if ( ++p == pe )
		goto _test_eof94;
case 94:
#line 3340 "graph_ragel.c"
	switch( (*p) ) {
		case 32: goto tr140;
		case 45: goto tr118;
		case 46: goto st95;
		case 58: goto tr196;
		case 59: goto tr197;
		case 91: goto tr198;
	}
	if ( (*p) > 10 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st94;
	} else if ( (*p) >= 9 )
		goto tr140;
	goto tr194;
st95:
	if ( ++p == pe )
		goto _test_eof95;
case 95:
	switch( (*p) ) {
		case 32: goto tr140;
		case 45: goto tr118;
		case 58: goto tr196;
		case 59: goto tr197;
		case 91: goto tr198;
	}
	if ( (*p) > 10 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st95;
	} else if ( (*p) >= 9 )
		goto tr140;
	goto tr194;
tr137:
#line 121 "graph.ragel"
	{ ts = p; }
	goto st96;
st96:
	if ( ++p == pe )
		goto _test_eof96;
case 96:
#line 3380 "graph_ragel.c"
	switch( (*p) ) {
		case 32: goto tr140;
		case 45: goto tr118;
		case 58: goto tr196;
		case 59: goto tr197;
		case 91: goto tr198;
		case 95: goto st96;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 10 )
			goto tr140;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st96;
		} else if ( (*p) >= 65 )
			goto st96;
	} else
		goto st96;
	goto tr194;
tr216:
#line 122 "graph.ragel"
	{ strncpy(last_identifier, ts, p-ts);last_identifier[p-ts]=0; }
	goto st97;
st97:
	if ( ++p == pe )
		goto _test_eof97;
case 97:
#line 3409 "graph_ragel.c"
	switch( (*p) ) {
		case 32: goto st97;
		case 34: goto st98;
		case 45: goto tr201;
		case 95: goto tr203;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 10 )
			goto st97;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr203;
		} else if ( (*p) >= 65 )
			goto tr203;
	} else
		goto tr202;
	goto tr9;
st98:
	if ( ++p == pe )
		goto _test_eof98;
case 98:
	switch( (*p) ) {
		case 32: goto tr204;
		case 95: goto tr204;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr204;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr204;
		} else if ( (*p) >= 65 )
			goto tr204;
	} else
		goto tr204;
	goto tr9;
tr204:
#line 121 "graph.ragel"
	{ ts = p; }
	goto st99;
st99:
	if ( ++p == pe )
		goto _test_eof99;
case 99:
#line 3456 "graph_ragel.c"
	switch( (*p) ) {
		case 32: goto st99;
		case 34: goto tr206;
		case 95: goto st99;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st99;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st99;
		} else if ( (*p) >= 65 )
			goto st99;
	} else
		goto st99;
	goto tr9;
tr206:
#line 122 "graph.ragel"
	{ strncpy(last_identifier, ts, p-ts);last_identifier[p-ts]=0; }
	goto st100;
st100:
	if ( ++p == pe )
		goto _test_eof100;
case 100:
#line 3482 "graph_ragel.c"
	switch( (*p) ) {
		case 32: goto st100;
		case 59: goto st12;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st100;
	goto st0;
tr201:
#line 121 "graph.ragel"
	{ ts = p; }
	goto st101;
st101:
	if ( ++p == pe )
		goto _test_eof101;
case 101:
#line 3498 "graph_ragel.c"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st102;
	goto tr9;
tr202:
#line 121 "graph.ragel"
	{ ts = p; }
	goto st102;
st102:
	if ( ++p == pe )
		goto _test_eof102;
case 102:
#line 3510 "graph_ragel.c"
	switch( (*p) ) {
		case 32: goto tr206;
		case 46: goto st103;
		case 59: goto tr197;
	}
	if ( (*p) > 10 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st102;
	} else if ( (*p) >= 9 )
		goto tr206;
	goto tr9;
st103:
	if ( ++p == pe )
		goto _test_eof103;
case 103:
	switch( (*p) ) {
		case 32: goto tr206;
		case 59: goto tr197;
	}
	if ( (*p) > 10 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st103;
	} else if ( (*p) >= 9 )
		goto tr206;
	goto tr9;
tr203:
#line 121 "graph.ragel"
	{ ts = p; }
	goto st104;
st104:
	if ( ++p == pe )
		goto _test_eof104;
case 104:
#line 3544 "graph_ragel.c"
	switch( (*p) ) {
		case 32: goto tr206;
		case 59: goto tr197;
		case 95: goto st104;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 10 )
			goto tr206;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st104;
		} else if ( (*p) >= 65 )
			goto st104;
	} else
		goto st104;
	goto tr9;
tr21:
#line 121 "graph.ragel"
	{ ts = p; }
	goto st105;
st105:
	if ( ++p == pe )
		goto _test_eof105;
case 105:
#line 3570 "graph_ragel.c"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st106;
	goto tr19;
tr22:
#line 121 "graph.ragel"
	{ ts = p; }
	goto st106;
st106:
	if ( ++p == pe )
		goto _test_eof106;
case 106:
#line 3582 "graph_ragel.c"
	switch( (*p) ) {
		case 32: goto tr28;
		case 45: goto tr125;
		case 46: goto st107;
		case 58: goto tr214;
		case 59: goto tr215;
		case 61: goto tr216;
		case 91: goto tr217;
	}
	if ( (*p) > 10 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st106;
	} else if ( (*p) >= 9 )
		goto tr28;
	goto tr212;
st107:
	if ( ++p == pe )
		goto _test_eof107;
case 107:
	switch( (*p) ) {
		case 32: goto tr28;
		case 45: goto tr125;
		case 58: goto tr214;
		case 59: goto tr215;
		case 61: goto tr216;
		case 91: goto tr217;
	}
	if ( (*p) > 10 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st107;
	} else if ( (*p) >= 9 )
		goto tr28;
	goto tr212;
tr23:
#line 121 "graph.ragel"
	{ ts = p; }
	goto st108;
st108:
	if ( ++p == pe )
		goto _test_eof108;
case 108:
#line 3624 "graph_ragel.c"
	switch( (*p) ) {
		case 32: goto tr28;
		case 45: goto tr125;
		case 58: goto tr214;
		case 59: goto tr215;
		case 61: goto tr216;
		case 91: goto tr217;
		case 95: goto st108;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 10 )
			goto tr28;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st108;
		} else if ( (*p) >= 65 )
			goto st108;
	} else
		goto st108;
	goto tr212;
tr24:
#line 121 "graph.ragel"
	{ ts = p; }
	goto st109;
st109:
	if ( ++p == pe )
		goto _test_eof109;
case 109:
#line 3654 "graph_ragel.c"
	switch( (*p) ) {
		case 32: goto tr28;
		case 45: goto tr125;
		case 58: goto tr214;
		case 59: goto tr215;
		case 61: goto tr216;
		case 91: goto tr217;
		case 95: goto st108;
		case 100: goto st110;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 10 )
			goto tr28;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st108;
		} else if ( (*p) >= 65 )
			goto st108;
	} else
		goto st108;
	goto tr212;
st110:
	if ( ++p == pe )
		goto _test_eof110;
case 110:
	switch( (*p) ) {
		case 32: goto tr28;
		case 45: goto tr125;
		case 58: goto tr214;
		case 59: goto tr215;
		case 61: goto tr216;
		case 91: goto tr217;
		case 95: goto st108;
		case 103: goto st111;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 10 )
			goto tr28;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st108;
		} else if ( (*p) >= 65 )
			goto st108;
	} else
		goto st108;
	goto tr212;
st111:
	if ( ++p == pe )
		goto _test_eof111;
case 111:
	switch( (*p) ) {
		case 32: goto tr28;
		case 45: goto tr125;
		case 58: goto tr214;
		case 59: goto tr215;
		case 61: goto tr216;
		case 91: goto tr217;
		case 95: goto st108;
		case 101: goto st112;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 10 )
			goto tr28;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st108;
		} else if ( (*p) >= 65 )
			goto st108;
	} else
		goto st108;
	goto tr212;
st112:
	if ( ++p == pe )
		goto _test_eof112;
case 112:
	switch( (*p) ) {
		case 32: goto tr222;
		case 61: goto tr216;
		case 91: goto st114;
		case 95: goto st108;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 10 )
			goto tr222;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st108;
		} else if ( (*p) >= 65 )
			goto st108;
	} else
		goto st108;
	goto tr19;
tr222:
#line 122 "graph.ragel"
	{ strncpy(last_identifier, ts, p-ts);last_identifier[p-ts]=0; }
	goto st113;
st113:
	if ( ++p == pe )
		goto _test_eof113;
case 113:
#line 3759 "graph_ragel.c"
	switch( (*p) ) {
		case 32: goto st113;
		case 61: goto st97;
		case 91: goto st114;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st113;
	goto st0;
tr245:
#line 30 "graph.ragel"
	{
        
        switch(label_type)
        {
            case TYPE_LABEL:
                weight = atof(last_identifier);
                printf("weight: %f, \"%s\"\n", weight, last_identifier);
                break;
            case TYPE_DIR:
                //if (!strncmp(last_identifier, "none",sizeof(field_name)))
                    
                break;
            case TYPE_NONE:
            default:
                
                break;
        }
    }
	goto st114;
tr257:
#line 122 "graph.ragel"
	{ strncpy(last_identifier, ts, p-ts);last_identifier[p-ts]=0; }
#line 30 "graph.ragel"
	{
        
        switch(label_type)
        {
            case TYPE_LABEL:
                weight = atof(last_identifier);
                printf("weight: %f, \"%s\"\n", weight, last_identifier);
                break;
            case TYPE_DIR:
                //if (!strncmp(last_identifier, "none",sizeof(field_name)))
                    
                break;
            case TYPE_NONE:
            default:
                
                break;
        }
    }
	goto st114;
st114:
	if ( ++p == pe )
		goto _test_eof114;
case 114:
#line 3816 "graph_ragel.c"
	switch( (*p) ) {
		case 32: goto st114;
		case 34: goto tr225;
		case 45: goto tr226;
		case 93: goto st126;
		case 95: goto tr228;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 10 )
			goto st114;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr228;
		} else if ( (*p) >= 65 )
			goto tr228;
	} else
		goto tr227;
	goto tr146;
tr225:
#line 16 "graph.ragel"
	{ ts = p; }
	goto st115;
tr244:
#line 30 "graph.ragel"
	{
        
        switch(label_type)
        {
            case TYPE_LABEL:
                weight = atof(last_identifier);
                printf("weight: %f, \"%s\"\n", weight, last_identifier);
                break;
            case TYPE_DIR:
                //if (!strncmp(last_identifier, "none",sizeof(field_name)))
                    
                break;
            case TYPE_NONE:
            default:
                
                break;
        }
    }
#line 16 "graph.ragel"
	{ ts = p; }
	goto st115;
tr256:
#line 122 "graph.ragel"
	{ strncpy(last_identifier, ts, p-ts);last_identifier[p-ts]=0; }
#line 30 "graph.ragel"
	{
        
        switch(label_type)
        {
            case TYPE_LABEL:
                weight = atof(last_identifier);
                printf("weight: %f, \"%s\"\n", weight, last_identifier);
                break;
            case TYPE_DIR:
                //if (!strncmp(last_identifier, "none",sizeof(field_name)))
                    
                break;
            case TYPE_NONE:
            default:
                
                break;
        }
    }
#line 16 "graph.ragel"
	{ ts = p; }
	goto st115;
st115:
	if ( ++p == pe )
		goto _test_eof115;
case 115:
#line 3892 "graph_ragel.c"
	switch( (*p) ) {
		case 32: goto tr230;
		case 95: goto tr230;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr230;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr230;
		} else if ( (*p) >= 65 )
			goto tr230;
	} else
		goto tr230;
	goto tr146;
tr230:
#line 121 "graph.ragel"
	{ ts = p; }
	goto st116;
st116:
	if ( ++p == pe )
		goto _test_eof116;
case 116:
#line 3917 "graph_ragel.c"
	switch( (*p) ) {
		case 32: goto st116;
		case 34: goto tr232;
		case 95: goto st116;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st116;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st116;
		} else if ( (*p) >= 65 )
			goto st116;
	} else
		goto st116;
	goto tr146;
tr232:
#line 122 "graph.ragel"
	{ strncpy(last_identifier, ts, p-ts);last_identifier[p-ts]=0; }
	goto st117;
st117:
	if ( ++p == pe )
		goto _test_eof117;
case 117:
#line 3943 "graph_ragel.c"
	switch( (*p) ) {
		case 32: goto st117;
		case 61: goto tr234;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st117;
	goto tr155;
tr234:
#line 17 "graph.ragel"
	{ 
        //printf("attr: %s\n", last_identifier);
        if (!strncmp(last_identifier, "label",sizeof(last_identifier))) 
            label_type = TYPE_LABEL;
        else if (!strncmp(last_identifier, "dir",sizeof(last_identifier))) 
            label_type = TYPE_DIR;
        else
            label_type = TYPE_NONE;
            
    }
	goto st118;
tr252:
#line 122 "graph.ragel"
	{ strncpy(last_identifier, ts, p-ts);last_identifier[p-ts]=0; }
#line 17 "graph.ragel"
	{ 
        //printf("attr: %s\n", last_identifier);
        if (!strncmp(last_identifier, "label",sizeof(last_identifier))) 
            label_type = TYPE_LABEL;
        else if (!strncmp(last_identifier, "dir",sizeof(last_identifier))) 
            label_type = TYPE_DIR;
        else
            label_type = TYPE_NONE;
            
    }
	goto st118;
st118:
	if ( ++p == pe )
		goto _test_eof118;
case 118:
#line 3983 "graph_ragel.c"
	switch( (*p) ) {
		case 32: goto st118;
		case 34: goto tr236;
		case 45: goto tr237;
		case 95: goto tr239;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 10 )
			goto st118;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr239;
		} else if ( (*p) >= 65 )
			goto tr239;
	} else
		goto tr238;
	goto tr158;
tr236:
#line 29 "graph.ragel"
	{ ts = p; }
	goto st119;
st119:
	if ( ++p == pe )
		goto _test_eof119;
case 119:
#line 4010 "graph_ragel.c"
	switch( (*p) ) {
		case 32: goto tr240;
		case 95: goto tr240;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto tr240;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr240;
		} else if ( (*p) >= 65 )
			goto tr240;
	} else
		goto tr240;
	goto tr158;
tr240:
#line 121 "graph.ragel"
	{ ts = p; }
	goto st120;
st120:
	if ( ++p == pe )
		goto _test_eof120;
case 120:
#line 4035 "graph_ragel.c"
	switch( (*p) ) {
		case 32: goto st120;
		case 34: goto tr242;
		case 95: goto st120;
	}
	if ( (*p) < 48 ) {
		if ( 45 <= (*p) && (*p) <= 46 )
			goto st120;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st120;
		} else if ( (*p) >= 65 )
			goto st120;
	} else
		goto st120;
	goto tr158;
tr242:
#line 122 "graph.ragel"
	{ strncpy(last_identifier, ts, p-ts);last_identifier[p-ts]=0; }
	goto st121;
st121:
	if ( ++p == pe )
		goto _test_eof121;
case 121:
#line 4061 "graph_ragel.c"
	switch( (*p) ) {
		case 32: goto st121;
		case 34: goto tr244;
		case 44: goto tr245;
		case 45: goto tr246;
		case 93: goto tr249;
		case 95: goto tr248;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 10 )
			goto st121;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr248;
		} else if ( (*p) >= 65 )
			goto tr248;
	} else
		goto tr247;
	goto tr167;
tr226:
#line 16 "graph.ragel"
	{ ts = p; }
#line 121 "graph.ragel"
	{ ts = p; }
	goto st122;
tr246:
#line 30 "graph.ragel"
	{
        
        switch(label_type)
        {
            case TYPE_LABEL:
                weight = atof(last_identifier);
                printf("weight: %f, \"%s\"\n", weight, last_identifier);
                break;
            case TYPE_DIR:
                //if (!strncmp(last_identifier, "none",sizeof(field_name)))
                    
                break;
            case TYPE_NONE:
            default:
                
                break;
        }
    }
#line 16 "graph.ragel"
	{ ts = p; }
#line 121 "graph.ragel"
	{ ts = p; }
	goto st122;
tr258:
#line 122 "graph.ragel"
	{ strncpy(last_identifier, ts, p-ts);last_identifier[p-ts]=0; }
#line 30 "graph.ragel"
	{
        
        switch(label_type)
        {
            case TYPE_LABEL:
                weight = atof(last_identifier);
                printf("weight: %f, \"%s\"\n", weight, last_identifier);
                break;
            case TYPE_DIR:
                //if (!strncmp(last_identifier, "none",sizeof(field_name)))
                    
                break;
            case TYPE_NONE:
            default:
                
                break;
        }
    }
#line 16 "graph.ragel"
	{ ts = p; }
#line 121 "graph.ragel"
	{ ts = p; }
	goto st122;
st122:
	if ( ++p == pe )
		goto _test_eof122;
case 122:
#line 4144 "graph_ragel.c"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st123;
	goto tr146;
tr227:
#line 16 "graph.ragel"
	{ ts = p; }
#line 121 "graph.ragel"
	{ ts = p; }
	goto st123;
tr247:
#line 30 "graph.ragel"
	{
        
        switch(label_type)
        {
            case TYPE_LABEL:
                weight = atof(last_identifier);
                printf("weight: %f, \"%s\"\n", weight, last_identifier);
                break;
            case TYPE_DIR:
                //if (!strncmp(last_identifier, "none",sizeof(field_name)))
                    
                break;
            case TYPE_NONE:
            default:
                
                break;
        }
    }
#line 16 "graph.ragel"
	{ ts = p; }
#line 121 "graph.ragel"
	{ ts = p; }
	goto st123;
st123:
	if ( ++p == pe )
		goto _test_eof123;
case 123:
#line 4183 "graph_ragel.c"
	switch( (*p) ) {
		case 32: goto tr232;
		case 46: goto st124;
		case 61: goto tr252;
	}
	if ( (*p) > 10 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st123;
	} else if ( (*p) >= 9 )
		goto tr232;
	goto tr146;
st124:
	if ( ++p == pe )
		goto _test_eof124;
case 124:
	switch( (*p) ) {
		case 32: goto tr232;
		case 61: goto tr252;
	}
	if ( (*p) > 10 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st124;
	} else if ( (*p) >= 9 )
		goto tr232;
	goto tr146;
tr228:
#line 16 "graph.ragel"
	{ ts = p; }
#line 121 "graph.ragel"
	{ ts = p; }
	goto st125;
tr248:
#line 30 "graph.ragel"
	{
        
        switch(label_type)
        {
            case TYPE_LABEL:
                weight = atof(last_identifier);
                printf("weight: %f, \"%s\"\n", weight, last_identifier);
                break;
            case TYPE_DIR:
                //if (!strncmp(last_identifier, "none",sizeof(field_name)))
                    
                break;
            case TYPE_NONE:
            default:
                
                break;
        }
    }
#line 16 "graph.ragel"
	{ ts = p; }
#line 121 "graph.ragel"
	{ ts = p; }
	goto st125;
tr261:
#line 122 "graph.ragel"
	{ strncpy(last_identifier, ts, p-ts);last_identifier[p-ts]=0; }
#line 30 "graph.ragel"
	{
        
        switch(label_type)
        {
            case TYPE_LABEL:
                weight = atof(last_identifier);
                printf("weight: %f, \"%s\"\n", weight, last_identifier);
                break;
            case TYPE_DIR:
                //if (!strncmp(last_identifier, "none",sizeof(field_name)))
                    
                break;
            case TYPE_NONE:
            default:
                
                break;
        }
    }
#line 16 "graph.ragel"
	{ ts = p; }
#line 121 "graph.ragel"
	{ ts = p; }
	goto st125;
st125:
	if ( ++p == pe )
		goto _test_eof125;
case 125:
#line 4271 "graph_ragel.c"
	switch( (*p) ) {
		case 32: goto tr232;
		case 61: goto tr252;
		case 95: goto st125;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 10 )
			goto tr232;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st125;
		} else if ( (*p) >= 65 )
			goto st125;
	} else
		goto st125;
	goto tr146;
tr249:
#line 30 "graph.ragel"
	{
        
        switch(label_type)
        {
            case TYPE_LABEL:
                weight = atof(last_identifier);
                printf("weight: %f, \"%s\"\n", weight, last_identifier);
                break;
            case TYPE_DIR:
                //if (!strncmp(last_identifier, "none",sizeof(field_name)))
                    
                break;
            case TYPE_NONE:
            default:
                
                break;
        }
    }
	goto st126;
tr262:
#line 122 "graph.ragel"
	{ strncpy(last_identifier, ts, p-ts);last_identifier[p-ts]=0; }
#line 30 "graph.ragel"
	{
        
        switch(label_type)
        {
            case TYPE_LABEL:
                weight = atof(last_identifier);
                printf("weight: %f, \"%s\"\n", weight, last_identifier);
                break;
            case TYPE_DIR:
                //if (!strncmp(last_identifier, "none",sizeof(field_name)))
                    
                break;
            case TYPE_NONE:
            default:
                
                break;
        }
    }
	goto st126;
st126:
	if ( ++p == pe )
		goto _test_eof126;
case 126:
#line 4337 "graph_ragel.c"
	switch( (*p) ) {
		case 32: goto st126;
		case 59: goto tr254;
		case 91: goto st114;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st126;
	goto st0;
tr237:
#line 29 "graph.ragel"
	{ ts = p; }
#line 121 "graph.ragel"
	{ ts = p; }
	goto st127;
st127:
	if ( ++p == pe )
		goto _test_eof127;
case 127:
#line 4356 "graph_ragel.c"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st128;
	goto tr158;
tr238:
#line 29 "graph.ragel"
	{ ts = p; }
#line 121 "graph.ragel"
	{ ts = p; }
	goto st128;
st128:
	if ( ++p == pe )
		goto _test_eof128;
case 128:
#line 4370 "graph_ragel.c"
	switch( (*p) ) {
		case 32: goto tr242;
		case 34: goto tr256;
		case 44: goto tr257;
		case 45: goto tr258;
		case 46: goto st129;
		case 93: goto tr262;
		case 95: goto tr261;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 10 )
			goto tr242;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr261;
		} else if ( (*p) >= 65 )
			goto tr261;
	} else
		goto tr260;
	goto tr167;
st129:
	if ( ++p == pe )
		goto _test_eof129;
case 129:
	switch( (*p) ) {
		case 32: goto tr242;
		case 34: goto tr256;
		case 44: goto tr257;
		case 45: goto tr258;
		case 93: goto tr262;
		case 95: goto tr261;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 10 )
			goto tr242;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr261;
		} else if ( (*p) >= 65 )
			goto tr261;
	} else
		goto tr263;
	goto tr167;
tr263:
#line 122 "graph.ragel"
	{ strncpy(last_identifier, ts, p-ts);last_identifier[p-ts]=0; }
#line 30 "graph.ragel"
	{
        
        switch(label_type)
        {
            case TYPE_LABEL:
                weight = atof(last_identifier);
                printf("weight: %f, \"%s\"\n", weight, last_identifier);
                break;
            case TYPE_DIR:
                //if (!strncmp(last_identifier, "none",sizeof(field_name)))
                    
                break;
            case TYPE_NONE:
            default:
                
                break;
        }
    }
#line 16 "graph.ragel"
	{ ts = p; }
#line 121 "graph.ragel"
	{ ts = p; }
	goto st130;
st130:
	if ( ++p == pe )
		goto _test_eof130;
case 130:
#line 4447 "graph_ragel.c"
	switch( (*p) ) {
		case 32: goto tr264;
		case 34: goto tr256;
		case 44: goto tr257;
		case 45: goto tr258;
		case 46: goto st124;
		case 61: goto tr252;
		case 93: goto tr262;
		case 95: goto tr261;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 10 )
			goto tr264;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr261;
		} else if ( (*p) >= 65 )
			goto tr261;
	} else
		goto tr263;
	goto tr167;
tr264:
#line 122 "graph.ragel"
	{ strncpy(last_identifier, ts, p-ts);last_identifier[p-ts]=0; }
	goto st131;
st131:
	if ( ++p == pe )
		goto _test_eof131;
case 131:
#line 4478 "graph_ragel.c"
	switch( (*p) ) {
		case 32: goto st131;
		case 34: goto tr244;
		case 44: goto tr245;
		case 45: goto tr246;
		case 61: goto tr234;
		case 93: goto tr249;
		case 95: goto tr248;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 10 )
			goto st131;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr248;
		} else if ( (*p) >= 65 )
			goto tr248;
	} else
		goto tr247;
	goto tr167;
tr260:
#line 122 "graph.ragel"
	{ strncpy(last_identifier, ts, p-ts);last_identifier[p-ts]=0; }
#line 30 "graph.ragel"
	{
        
        switch(label_type)
        {
            case TYPE_LABEL:
                weight = atof(last_identifier);
                printf("weight: %f, \"%s\"\n", weight, last_identifier);
                break;
            case TYPE_DIR:
                //if (!strncmp(last_identifier, "none",sizeof(field_name)))
                    
                break;
            case TYPE_NONE:
            default:
                
                break;
        }
    }
#line 16 "graph.ragel"
	{ ts = p; }
#line 121 "graph.ragel"
	{ ts = p; }
	goto st132;
st132:
	if ( ++p == pe )
		goto _test_eof132;
case 132:
#line 4531 "graph_ragel.c"
	switch( (*p) ) {
		case 32: goto tr264;
		case 34: goto tr256;
		case 44: goto tr257;
		case 45: goto tr258;
		case 46: goto st133;
		case 61: goto tr252;
		case 93: goto tr262;
		case 95: goto tr261;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 10 )
			goto tr264;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr261;
		} else if ( (*p) >= 65 )
			goto tr261;
	} else
		goto tr260;
	goto tr167;
st133:
	if ( ++p == pe )
		goto _test_eof133;
case 133:
	switch( (*p) ) {
		case 32: goto tr264;
		case 34: goto tr256;
		case 44: goto tr257;
		case 45: goto tr258;
		case 61: goto tr252;
		case 93: goto tr262;
		case 95: goto tr261;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 10 )
			goto tr264;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr261;
		} else if ( (*p) >= 65 )
			goto tr261;
	} else
		goto tr263;
	goto tr167;
tr239:
#line 29 "graph.ragel"
	{ ts = p; }
#line 121 "graph.ragel"
	{ ts = p; }
	goto st134;
st134:
	if ( ++p == pe )
		goto _test_eof134;
case 134:
#line 4589 "graph_ragel.c"
	switch( (*p) ) {
		case 32: goto tr242;
		case 34: goto tr256;
		case 44: goto tr257;
		case 45: goto tr258;
		case 93: goto tr262;
		case 95: goto tr268;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 10 )
			goto tr242;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr268;
		} else if ( (*p) >= 65 )
			goto tr268;
	} else
		goto tr267;
	goto tr167;
tr267:
#line 122 "graph.ragel"
	{ strncpy(last_identifier, ts, p-ts);last_identifier[p-ts]=0; }
#line 30 "graph.ragel"
	{
        
        switch(label_type)
        {
            case TYPE_LABEL:
                weight = atof(last_identifier);
                printf("weight: %f, \"%s\"\n", weight, last_identifier);
                break;
            case TYPE_DIR:
                //if (!strncmp(last_identifier, "none",sizeof(field_name)))
                    
                break;
            case TYPE_NONE:
            default:
                
                break;
        }
    }
#line 16 "graph.ragel"
	{ ts = p; }
#line 121 "graph.ragel"
	{ ts = p; }
	goto st135;
st135:
	if ( ++p == pe )
		goto _test_eof135;
case 135:
#line 4641 "graph_ragel.c"
	switch( (*p) ) {
		case 32: goto tr264;
		case 34: goto tr256;
		case 44: goto tr257;
		case 45: goto tr258;
		case 46: goto st124;
		case 61: goto tr252;
		case 93: goto tr262;
		case 95: goto tr268;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 10 )
			goto tr264;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr268;
		} else if ( (*p) >= 65 )
			goto tr268;
	} else
		goto tr267;
	goto tr167;
tr268:
#line 122 "graph.ragel"
	{ strncpy(last_identifier, ts, p-ts);last_identifier[p-ts]=0; }
#line 30 "graph.ragel"
	{
        
        switch(label_type)
        {
            case TYPE_LABEL:
                weight = atof(last_identifier);
                printf("weight: %f, \"%s\"\n", weight, last_identifier);
                break;
            case TYPE_DIR:
                //if (!strncmp(last_identifier, "none",sizeof(field_name)))
                    
                break;
            case TYPE_NONE:
            default:
                
                break;
        }
    }
#line 16 "graph.ragel"
	{ ts = p; }
#line 121 "graph.ragel"
	{ ts = p; }
	goto st136;
st136:
	if ( ++p == pe )
		goto _test_eof136;
case 136:
#line 4695 "graph_ragel.c"
	switch( (*p) ) {
		case 32: goto tr264;
		case 34: goto tr256;
		case 44: goto tr257;
		case 45: goto tr258;
		case 61: goto tr252;
		case 93: goto tr262;
		case 95: goto tr268;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 10 )
			goto tr264;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr268;
		} else if ( (*p) >= 65 )
			goto tr268;
	} else
		goto tr267;
	goto tr167;
st147:
	if ( ++p == pe )
		goto _test_eof147;
case 147:
	if ( (*p) == 32 )
		goto st147;
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st147;
	goto st0;
tr11:
#line 121 "graph.ragel"
	{ ts = p; }
	goto st137;
st137:
	if ( ++p == pe )
		goto _test_eof137;
case 137:
#line 4734 "graph_ragel.c"
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st138;
	goto tr9;
tr12:
#line 121 "graph.ragel"
	{ ts = p; }
	goto st138;
st138:
	if ( ++p == pe )
		goto _test_eof138;
case 138:
#line 4746 "graph_ragel.c"
	switch( (*p) ) {
		case 32: goto tr17;
		case 46: goto st139;
		case 123: goto tr197;
	}
	if ( (*p) > 10 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st138;
	} else if ( (*p) >= 9 )
		goto tr17;
	goto tr9;
st139:
	if ( ++p == pe )
		goto _test_eof139;
case 139:
	switch( (*p) ) {
		case 32: goto tr17;
		case 123: goto tr197;
	}
	if ( (*p) > 10 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st139;
	} else if ( (*p) >= 9 )
		goto tr17;
	goto tr9;
tr13:
#line 121 "graph.ragel"
	{ ts = p; }
	goto st140;
st140:
	if ( ++p == pe )
		goto _test_eof140;
case 140:
#line 4780 "graph_ragel.c"
	switch( (*p) ) {
		case 32: goto tr17;
		case 95: goto st140;
		case 123: goto tr197;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 10 )
			goto tr17;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st140;
		} else if ( (*p) >= 65 )
			goto st140;
	} else
		goto st140;
	goto tr9;
st141:
	if ( ++p == pe )
		goto _test_eof141;
case 141:
	if ( (*p) == 116 )
		goto st142;
	goto st0;
st142:
	if ( ++p == pe )
		goto _test_eof142;
case 142:
	if ( (*p) == 114 )
		goto st143;
	goto st0;
st143:
	if ( ++p == pe )
		goto _test_eof143;
case 143:
	if ( (*p) == 105 )
		goto st144;
	goto st0;
st144:
	if ( ++p == pe )
		goto _test_eof144;
case 144:
	if ( (*p) == 99 )
		goto st145;
	goto st0;
st145:
	if ( ++p == pe )
		goto _test_eof145;
case 145:
	if ( (*p) == 116 )
		goto st146;
	goto st0;
st146:
	if ( ++p == pe )
		goto _test_eof146;
case 146:
	switch( (*p) ) {
		case 32: goto st146;
		case 100: goto st2;
		case 103: goto st4;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st146;
	goto st0;
	}
	_test_eof2: cs = 2; goto _test_eof; 
	_test_eof3: cs = 3; goto _test_eof; 
	_test_eof4: cs = 4; goto _test_eof; 
	_test_eof5: cs = 5; goto _test_eof; 
	_test_eof6: cs = 6; goto _test_eof; 
	_test_eof7: cs = 7; goto _test_eof; 
	_test_eof8: cs = 8; goto _test_eof; 
	_test_eof9: cs = 9; goto _test_eof; 
	_test_eof10: cs = 10; goto _test_eof; 
	_test_eof11: cs = 11; goto _test_eof; 
	_test_eof12: cs = 12; goto _test_eof; 
	_test_eof13: cs = 13; goto _test_eof; 
	_test_eof14: cs = 14; goto _test_eof; 
	_test_eof15: cs = 15; goto _test_eof; 
	_test_eof16: cs = 16; goto _test_eof; 
	_test_eof17: cs = 17; goto _test_eof; 
	_test_eof18: cs = 18; goto _test_eof; 
	_test_eof19: cs = 19; goto _test_eof; 
	_test_eof20: cs = 20; goto _test_eof; 
	_test_eof21: cs = 21; goto _test_eof; 
	_test_eof22: cs = 22; goto _test_eof; 
	_test_eof23: cs = 23; goto _test_eof; 
	_test_eof24: cs = 24; goto _test_eof; 
	_test_eof25: cs = 25; goto _test_eof; 
	_test_eof26: cs = 26; goto _test_eof; 
	_test_eof27: cs = 27; goto _test_eof; 
	_test_eof28: cs = 28; goto _test_eof; 
	_test_eof29: cs = 29; goto _test_eof; 
	_test_eof30: cs = 30; goto _test_eof; 
	_test_eof31: cs = 31; goto _test_eof; 
	_test_eof32: cs = 32; goto _test_eof; 
	_test_eof33: cs = 33; goto _test_eof; 
	_test_eof34: cs = 34; goto _test_eof; 
	_test_eof35: cs = 35; goto _test_eof; 
	_test_eof36: cs = 36; goto _test_eof; 
	_test_eof37: cs = 37; goto _test_eof; 
	_test_eof38: cs = 38; goto _test_eof; 
	_test_eof39: cs = 39; goto _test_eof; 
	_test_eof40: cs = 40; goto _test_eof; 
	_test_eof41: cs = 41; goto _test_eof; 
	_test_eof42: cs = 42; goto _test_eof; 
	_test_eof43: cs = 43; goto _test_eof; 
	_test_eof44: cs = 44; goto _test_eof; 
	_test_eof45: cs = 45; goto _test_eof; 
	_test_eof46: cs = 46; goto _test_eof; 
	_test_eof47: cs = 47; goto _test_eof; 
	_test_eof48: cs = 48; goto _test_eof; 
	_test_eof49: cs = 49; goto _test_eof; 
	_test_eof50: cs = 50; goto _test_eof; 
	_test_eof51: cs = 51; goto _test_eof; 
	_test_eof52: cs = 52; goto _test_eof; 
	_test_eof53: cs = 53; goto _test_eof; 
	_test_eof54: cs = 54; goto _test_eof; 
	_test_eof55: cs = 55; goto _test_eof; 
	_test_eof56: cs = 56; goto _test_eof; 
	_test_eof57: cs = 57; goto _test_eof; 
	_test_eof58: cs = 58; goto _test_eof; 
	_test_eof59: cs = 59; goto _test_eof; 
	_test_eof60: cs = 60; goto _test_eof; 
	_test_eof61: cs = 61; goto _test_eof; 
	_test_eof62: cs = 62; goto _test_eof; 
	_test_eof63: cs = 63; goto _test_eof; 
	_test_eof64: cs = 64; goto _test_eof; 
	_test_eof65: cs = 65; goto _test_eof; 
	_test_eof66: cs = 66; goto _test_eof; 
	_test_eof67: cs = 67; goto _test_eof; 
	_test_eof68: cs = 68; goto _test_eof; 
	_test_eof69: cs = 69; goto _test_eof; 
	_test_eof70: cs = 70; goto _test_eof; 
	_test_eof71: cs = 71; goto _test_eof; 
	_test_eof72: cs = 72; goto _test_eof; 
	_test_eof73: cs = 73; goto _test_eof; 
	_test_eof74: cs = 74; goto _test_eof; 
	_test_eof75: cs = 75; goto _test_eof; 
	_test_eof76: cs = 76; goto _test_eof; 
	_test_eof77: cs = 77; goto _test_eof; 
	_test_eof78: cs = 78; goto _test_eof; 
	_test_eof79: cs = 79; goto _test_eof; 
	_test_eof80: cs = 80; goto _test_eof; 
	_test_eof81: cs = 81; goto _test_eof; 
	_test_eof82: cs = 82; goto _test_eof; 
	_test_eof83: cs = 83; goto _test_eof; 
	_test_eof84: cs = 84; goto _test_eof; 
	_test_eof85: cs = 85; goto _test_eof; 
	_test_eof86: cs = 86; goto _test_eof; 
	_test_eof87: cs = 87; goto _test_eof; 
	_test_eof88: cs = 88; goto _test_eof; 
	_test_eof89: cs = 89; goto _test_eof; 
	_test_eof90: cs = 90; goto _test_eof; 
	_test_eof91: cs = 91; goto _test_eof; 
	_test_eof92: cs = 92; goto _test_eof; 
	_test_eof93: cs = 93; goto _test_eof; 
	_test_eof94: cs = 94; goto _test_eof; 
	_test_eof95: cs = 95; goto _test_eof; 
	_test_eof96: cs = 96; goto _test_eof; 
	_test_eof97: cs = 97; goto _test_eof; 
	_test_eof98: cs = 98; goto _test_eof; 
	_test_eof99: cs = 99; goto _test_eof; 
	_test_eof100: cs = 100; goto _test_eof; 
	_test_eof101: cs = 101; goto _test_eof; 
	_test_eof102: cs = 102; goto _test_eof; 
	_test_eof103: cs = 103; goto _test_eof; 
	_test_eof104: cs = 104; goto _test_eof; 
	_test_eof105: cs = 105; goto _test_eof; 
	_test_eof106: cs = 106; goto _test_eof; 
	_test_eof107: cs = 107; goto _test_eof; 
	_test_eof108: cs = 108; goto _test_eof; 
	_test_eof109: cs = 109; goto _test_eof; 
	_test_eof110: cs = 110; goto _test_eof; 
	_test_eof111: cs = 111; goto _test_eof; 
	_test_eof112: cs = 112; goto _test_eof; 
	_test_eof113: cs = 113; goto _test_eof; 
	_test_eof114: cs = 114; goto _test_eof; 
	_test_eof115: cs = 115; goto _test_eof; 
	_test_eof116: cs = 116; goto _test_eof; 
	_test_eof117: cs = 117; goto _test_eof; 
	_test_eof118: cs = 118; goto _test_eof; 
	_test_eof119: cs = 119; goto _test_eof; 
	_test_eof120: cs = 120; goto _test_eof; 
	_test_eof121: cs = 121; goto _test_eof; 
	_test_eof122: cs = 122; goto _test_eof; 
	_test_eof123: cs = 123; goto _test_eof; 
	_test_eof124: cs = 124; goto _test_eof; 
	_test_eof125: cs = 125; goto _test_eof; 
	_test_eof126: cs = 126; goto _test_eof; 
	_test_eof127: cs = 127; goto _test_eof; 
	_test_eof128: cs = 128; goto _test_eof; 
	_test_eof129: cs = 129; goto _test_eof; 
	_test_eof130: cs = 130; goto _test_eof; 
	_test_eof131: cs = 131; goto _test_eof; 
	_test_eof132: cs = 132; goto _test_eof; 
	_test_eof133: cs = 133; goto _test_eof; 
	_test_eof134: cs = 134; goto _test_eof; 
	_test_eof135: cs = 135; goto _test_eof; 
	_test_eof136: cs = 136; goto _test_eof; 
	_test_eof147: cs = 147; goto _test_eof; 
	_test_eof137: cs = 137; goto _test_eof; 
	_test_eof138: cs = 138; goto _test_eof; 
	_test_eof139: cs = 139; goto _test_eof; 
	_test_eof140: cs = 140; goto _test_eof; 
	_test_eof141: cs = 141; goto _test_eof; 
	_test_eof142: cs = 142; goto _test_eof; 
	_test_eof143: cs = 143; goto _test_eof; 
	_test_eof144: cs = 144; goto _test_eof; 
	_test_eof145: cs = 145; goto _test_eof; 
	_test_eof146: cs = 146; goto _test_eof; 

	_test_eof: {}
	if ( p == eof )
	{
	switch ( cs ) {
	case 72: 
	case 117: 
#line 27 "graph.ragel"
	{ printf("ERROR %s:%d Pos: %ld State: %d\n", __FILE__,__LINE__, p-file, cs); }
	break;
	case 25: 
	case 39: 
#line 101 "graph.ragel"
	{ printf("ERROR %s:%d Pos: %ld State: %d\n", __FILE__,__LINE__, p-file, cs); }
	break;
	case 8: 
	case 9: 
	case 10: 
	case 63: 
	case 64: 
	case 65: 
	case 93: 
	case 97: 
	case 98: 
	case 99: 
	case 101: 
	case 102: 
	case 103: 
	case 104: 
	case 137: 
	case 138: 
	case 139: 
	case 140: 
#line 123 "graph.ragel"
	{ printf("ERROR %s:%d Pos: %ld State: %d\n", __FILE__,__LINE__, p-file, cs); }
	break;
	case 30: 
#line 27 "graph.ragel"
	{ printf("ERROR %s:%d Pos: %ld State: %d\n", __FILE__,__LINE__, p-file, cs); }
#line 101 "graph.ragel"
	{ printf("ERROR %s:%d Pos: %ld State: %d\n", __FILE__,__LINE__, p-file, cs); }
	break;
	case 16: 
	case 24: 
	case 26: 
	case 50: 
	case 66: 
	case 68: 
	case 92: 
#line 79 "graph.ragel"
	{ printf("ERROR %s:%d Pos: %ld State: %d\n", __FILE__,__LINE__, p-file, cs); }
#line 101 "graph.ragel"
	{ printf("ERROR %s:%d Pos: %ld State: %d\n", __FILE__,__LINE__, p-file, cs); }
	break;
	case 69: 
	case 70: 
	case 71: 
	case 77: 
	case 78: 
	case 79: 
	case 80: 
	case 114: 
	case 115: 
	case 116: 
	case 122: 
	case 123: 
	case 124: 
	case 125: 
#line 123 "graph.ragel"
	{ printf("ERROR %s:%d Pos: %ld State: %d\n", __FILE__,__LINE__, p-file, cs); }
#line 27 "graph.ragel"
	{ printf("ERROR %s:%d Pos: %ld State: %d\n", __FILE__,__LINE__, p-file, cs); }
	break;
	case 73: 
	case 74: 
	case 75: 
	case 82: 
	case 118: 
	case 119: 
	case 120: 
	case 127: 
#line 123 "graph.ragel"
	{ printf("ERROR %s:%d Pos: %ld State: %d\n", __FILE__,__LINE__, p-file, cs); }
#line 48 "graph.ragel"
	{ printf("ERROR %s:%d Pos: %ld State: %d\n", __FILE__,__LINE__, p-file, cs); }
	break;
	case 12: 
	case 13: 
	case 14: 
	case 105: 
	case 112: 
#line 123 "graph.ragel"
	{ printf("ERROR %s:%d Pos: %ld State: %d\n", __FILE__,__LINE__, p-file, cs); }
#line 58 "graph.ragel"
	{ printf("ERROR %s:%d Pos: %ld State: %d\n", __FILE__,__LINE__, p-file, cs); }
	break;
	case 21: 
	case 22: 
	case 23: 
	case 51: 
#line 123 "graph.ragel"
	{ printf("ERROR %s:%d Pos: %ld State: %d\n", __FILE__,__LINE__, p-file, cs); }
#line 101 "graph.ragel"
	{ printf("ERROR %s:%d Pos: %ld State: %d\n", __FILE__,__LINE__, p-file, cs); }
	break;
	case 15: 
#line 58 "graph.ragel"
	{ printf("ERROR %s:%d Pos: %ld State: %d\n", __FILE__,__LINE__, p-file, cs); }
#line 79 "graph.ragel"
	{ printf("ERROR %s:%d Pos: %ld State: %d\n", __FILE__,__LINE__, p-file, cs); }
#line 101 "graph.ragel"
	{ printf("ERROR %s:%d Pos: %ld State: %d\n", __FILE__,__LINE__, p-file, cs); }
	break;
	case 20: 
#line 79 "graph.ragel"
	{ printf("ERROR %s:%d Pos: %ld State: %d\n", __FILE__,__LINE__, p-file, cs); }
#line 58 "graph.ragel"
	{ printf("ERROR %s:%d Pos: %ld State: %d\n", __FILE__,__LINE__, p-file, cs); }
#line 101 "graph.ragel"
	{ printf("ERROR %s:%d Pos: %ld State: %d\n", __FILE__,__LINE__, p-file, cs); }
	break;
	case 52: 
	case 53: 
	case 54: 
#line 79 "graph.ragel"
	{ printf("ERROR %s:%d Pos: %ld State: %d\n", __FILE__,__LINE__, p-file, cs); }
#line 123 "graph.ragel"
	{ printf("ERROR %s:%d Pos: %ld State: %d\n", __FILE__,__LINE__, p-file, cs); }
#line 101 "graph.ragel"
	{ printf("ERROR %s:%d Pos: %ld State: %d\n", __FILE__,__LINE__, p-file, cs); }
	break;
	case 76: 
	case 83: 
	case 84: 
	case 85: 
	case 86: 
	case 87: 
	case 88: 
	case 89: 
	case 90: 
	case 91: 
	case 121: 
	case 128: 
	case 129: 
	case 130: 
	case 131: 
	case 132: 
	case 133: 
	case 134: 
	case 135: 
	case 136: 
#line 123 "graph.ragel"
	{ printf("ERROR %s:%d Pos: %ld State: %d\n", __FILE__,__LINE__, p-file, cs); }
#line 27 "graph.ragel"
	{ printf("ERROR %s:%d Pos: %ld State: %d\n", __FILE__,__LINE__, p-file, cs); }
#line 48 "graph.ragel"
	{ printf("ERROR %s:%d Pos: %ld State: %d\n", __FILE__,__LINE__, p-file, cs); }
	break;
	case 27: 
	case 28: 
	case 29: 
	case 35: 
	case 36: 
	case 37: 
	case 38: 
#line 123 "graph.ragel"
	{ printf("ERROR %s:%d Pos: %ld State: %d\n", __FILE__,__LINE__, p-file, cs); }
#line 27 "graph.ragel"
	{ printf("ERROR %s:%d Pos: %ld State: %d\n", __FILE__,__LINE__, p-file, cs); }
#line 101 "graph.ragel"
	{ printf("ERROR %s:%d Pos: %ld State: %d\n", __FILE__,__LINE__, p-file, cs); }
	break;
	case 31: 
	case 32: 
	case 33: 
	case 40: 
#line 123 "graph.ragel"
	{ printf("ERROR %s:%d Pos: %ld State: %d\n", __FILE__,__LINE__, p-file, cs); }
#line 48 "graph.ragel"
	{ printf("ERROR %s:%d Pos: %ld State: %d\n", __FILE__,__LINE__, p-file, cs); }
#line 101 "graph.ragel"
	{ printf("ERROR %s:%d Pos: %ld State: %d\n", __FILE__,__LINE__, p-file, cs); }
	break;
	case 18: 
	case 19: 
	case 55: 
	case 62: 
#line 123 "graph.ragel"
	{ printf("ERROR %s:%d Pos: %ld State: %d\n", __FILE__,__LINE__, p-file, cs); }
#line 58 "graph.ragel"
	{ printf("ERROR %s:%d Pos: %ld State: %d\n", __FILE__,__LINE__, p-file, cs); }
#line 101 "graph.ragel"
	{ printf("ERROR %s:%d Pos: %ld State: %d\n", __FILE__,__LINE__, p-file, cs); }
	break;
	case 94: 
	case 95: 
	case 96: 
#line 123 "graph.ragel"
	{ printf("ERROR %s:%d Pos: %ld State: %d\n", __FILE__,__LINE__, p-file, cs); }
#line 79 "graph.ragel"
	{ printf("ERROR %s:%d Pos: %ld State: %d\n", __FILE__,__LINE__, p-file, cs); }
#line 101 "graph.ragel"
	{ printf("ERROR %s:%d Pos: %ld State: %d\n", __FILE__,__LINE__, p-file, cs); }
	break;
	case 17: 
	case 56: 
	case 57: 
	case 58: 
	case 59: 
	case 60: 
	case 61: 
#line 79 "graph.ragel"
	{ printf("ERROR %s:%d Pos: %ld State: %d\n", __FILE__,__LINE__, p-file, cs); }
#line 123 "graph.ragel"
	{ printf("ERROR %s:%d Pos: %ld State: %d\n", __FILE__,__LINE__, p-file, cs); }
#line 58 "graph.ragel"
	{ printf("ERROR %s:%d Pos: %ld State: %d\n", __FILE__,__LINE__, p-file, cs); }
#line 101 "graph.ragel"
	{ printf("ERROR %s:%d Pos: %ld State: %d\n", __FILE__,__LINE__, p-file, cs); }
	break;
	case 34: 
	case 41: 
	case 42: 
	case 43: 
	case 44: 
	case 45: 
	case 46: 
	case 47: 
	case 48: 
	case 49: 
#line 123 "graph.ragel"
	{ printf("ERROR %s:%d Pos: %ld State: %d\n", __FILE__,__LINE__, p-file, cs); }
#line 27 "graph.ragel"
	{ printf("ERROR %s:%d Pos: %ld State: %d\n", __FILE__,__LINE__, p-file, cs); }
#line 48 "graph.ragel"
	{ printf("ERROR %s:%d Pos: %ld State: %d\n", __FILE__,__LINE__, p-file, cs); }
#line 101 "graph.ragel"
	{ printf("ERROR %s:%d Pos: %ld State: %d\n", __FILE__,__LINE__, p-file, cs); }
	break;
	case 106: 
	case 107: 
	case 108: 
	case 109: 
	case 110: 
	case 111: 
#line 123 "graph.ragel"
	{ printf("ERROR %s:%d Pos: %ld State: %d\n", __FILE__,__LINE__, p-file, cs); }
#line 58 "graph.ragel"
	{ printf("ERROR %s:%d Pos: %ld State: %d\n", __FILE__,__LINE__, p-file, cs); }
#line 79 "graph.ragel"
	{ printf("ERROR %s:%d Pos: %ld State: %d\n", __FILE__,__LINE__, p-file, cs); }
#line 101 "graph.ragel"
	{ printf("ERROR %s:%d Pos: %ld State: %d\n", __FILE__,__LINE__, p-file, cs); }
	break;
#line 5246 "graph_ragel.c"
	}
	}

	_out: {}
	}

#line 233 "graph.ragel"
 
    return g;
}

