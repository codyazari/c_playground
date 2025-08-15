#include <stdio.h>
#include <stdlib.h>

typedef enum {
    DIR_NONE = 0,
    DIR_NORTH,
    DIR_SOUTH,
    DIR_EAST,
    DIR_WEST,
    DIR_UP,
    DIR_DOWN,
} Direction;

typedef struct edge {
    int dest_room_id;
    Direction direction;
    bool is_locked;
} edge;

typedef struct room {
    char* name;
    int room_id;
    int neighbor_count;
    edge* neighbors;
} room;

typedef struct graph {
    int n_edges;
    bool is_directed;
    int room_count;
    room* rooms;
} graph;

graph build_graph(void) {
    graph g;
    g.n_edges = 0;
    g.room_count = 0;
    g.is_directed = false;
    g.rooms = NULL;
    return g;
}

void add_room(graph *g, char* name, int room_id) {
    g->rooms = realloc(g->rooms, sizeof(room) * (g->room_count + 1));
    if (!g->rooms) {
        fprintf(stderr, "Mem Alloc failed\n");
        return;
    }

    // Look at new room
    room* new_room = &g->rooms[g->room_count];
    new_room->name = name;
    new_room->room_id = room_id;
    new_room->neighbor_count = 0;
    new_room->neighbors = NULL;
    
    g->room_count++;
}

int main(void) {

    graph new = build_graph();

    add_room(&new, "room 1", 0);
    add_room(&new, "room 2", 1);
    
    printf("Graph has %d rooms\n", new.room_count);
    printf("First room name: %s\n", new.rooms[0].name);
    return 0;
}