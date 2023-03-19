#ifndef myAlgo_H
#define myAlgo_H
#define MAX_algorithm 2
char algo_name[MAX_algorithm][10];
int relation_map[MAX_person][MAX_person];
//extern int visited[];
void _map_init();
void algo_init();
BOOL _DFS(int , int);
BOOL _BFS(int , int);
#endif
