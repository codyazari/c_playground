#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Hallway {
    int to_id;
    int from_id;
    struct Hallway* next;
} Hallway;

typedef struct Room {
    Hallway* head;
    char* name;
    int x, y;
} Room;

// 
typedef struct Graph {
    int n_rooms;
    bool is_directed;
    Room* neighbors[];
} Graph;

Graph* generate_graph(size_t n_rooms, bool is_directed) {
    Graph* g = malloc(sizeof *g);
    if (!g) perror("Failed to allocate memory for graph"); exit(EXIT_FAILURE);

    g->n_rooms = n_rooms;
    g->is_directed = false;
    g->adj = calloc(n_rooms, )
}

int main(void) {
    printf("Hello\n");
    return 0;
}