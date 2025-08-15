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
    Room* neighbors;
} Graph;

Graph* generate_graph(size_t n_initial_rooms, bool is_directed) {
    Graph* g = malloc(sizeof *g);
    if (!g) {
        perror("Failed to allocate memory for graph");
        exit(EXIT_FAILURE);
    }

    g->n_rooms = n_initial_rooms;
    g->is_directed = is_directed;
    g->neighbors = malloc(n_initial_rooms * sizeof *g->neighbors);
    if (!g->neighbors) {
        perror("Failed to allocate memory for n");
        exit(EXIT_FAILURE);
    }
    for (size_t i = 0; i < n_initial_rooms; i++) {
        g->neighbors[i].head = NULL;
        g->neighbors[i].name = NULL;
        g->neighbors[i].x = 0;
        g->neighbors[i].y = 0;
    }

    return g;
}

int main(void) {
    Graph* g = generate_graph(10, false);
    printf("%d\n", g->neighbors[1].x);
    return 0;
}