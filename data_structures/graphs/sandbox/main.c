#include <stdio.h>
#include <stdlib.h>

// EDGE
typedef struct Hallway {
    int room_id;
    int weight;
    struct Hallway* next;
} Hallway;

// Node or Vertices
typedef struct Room {
    int room_id;
    int n_neighbors;
    Hallway* head;
} Room;

typedef struct Graph {
    size_t n_rooms;
    size_t n_hallways;
    bool is_directed;
    Room* adj_rooms;
} Graph;

Graph* generate_graph(size_t n_rooms, bool is_directed) {
    Graph* g = malloc(sizeof *g);
    if (!g) {
        fprintf(stderr, "Could not allocate memory for graph");
        exit(EXIT_FAILURE);
    }
    g->n_rooms = n_rooms;
    g->n_hallways = 0;
    g->is_directed = is_directed;
    g->adj_rooms = malloc(n_rooms * sizeof *g->adj_rooms);
    if (!g->adj_rooms) {
        fprintf(stderr, "Could not allocate memory for Room Adjacency list");
        exit(EXIT_FAILURE);
    }

    for (size_t i = 0; i < g->n_rooms; i++) {
        g->adj_rooms[i].head = NULL;
        g->adj_rooms[i].room_id = i;
        g->adj_rooms[i].n_neighbors = 0;
    }
    return g;
}

// ADD EDGE -- CONNECT TWO NODES
void add_hallway(Graph* g, int x, int y) {

}

int main(void) {
    Graph* g = generate_graph(100, false);
    printf("%d\n", g->adj_rooms[99].room_id);
    return 0;
}