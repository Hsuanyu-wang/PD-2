#ifndef myAlgo_H
#define myAlgo_H
#define MAX_algorithm 2
extern char algo_name[MAX_algorithm][10];
extern int relation_map[MAX_person][MAX_person];
void _map_init();
void algo_init();
BOOL _DFS(int , int);
BOOL _BFS(int , int);
#endif
