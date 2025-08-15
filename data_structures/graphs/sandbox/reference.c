#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

typedef struct Edge {
    int to; // neighbors ID
    struct Edge* next; // Single linked list for adjacent nodes
} Edge;

typedef struct Vertex {
    char* name; 
    Edge* head; // Head of linked list - outgoing edges
} Vertex;

typedef struct Graph {
    size_t n_vertices; // number of vertices
    Vertex* adj; // array of n vertices
    bool directed; // true if edges are one way
} Graph;

Graph* generate_graph(size_t n_vertices, bool directed) {
    Graph* g = malloc(sizeof *g);
    g->n_vertices = n_vertices;
    g->directed = directed;
    g->adj = malloc(n_vertices * sizeof *g->adj);

    for (size_t i = 0; i < n_vertices; i++) {
        g->adj[i].name = NULL;
        g->adj[i].head = NULL;
    }

    return g;
}

void add_edge(Graph* g, size_t u, size_t v) {
    Edge* e = malloc(sizeof *e);
    e->to = v;
    e->next = g->adj[u].head;
    g->adj[u].head = e;

    if (!g->directed) {
        Edge* r = malloc(sizeof *r);
        r->to = u;
        r->next = g->adj[v].head;
        g->adj[v].head = r;
    }
}

void print_graph(const Graph* g) {
    printf("Vertex: Connected to\n");
    for (size_t u = 0; u < g->n_vertices; u++) {
        printf("%zu", u);
        if (g->adj[u].name) {
            printf(" (%s)", g->adj[u].name);
        }
        printf(":");
        Edge* e = g->adj[u].head;
        while(e != NULL) {
            printf(" -> %d", e->to);
            e = e->next;
        }
        printf("\n");
    }
}

int main(void) {

    Graph* g = generate_graph(4, false);

    add_edge(g, 0, 1);
    print_graph(g);
    add_edge(g, 0, 2);
    print_graph(g);
    add_edge(g, 1, 5);
    print_graph(g);
    
    free(g->adj);
    free(g);
    return 0;
}