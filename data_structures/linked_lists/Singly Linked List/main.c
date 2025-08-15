#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int node_index;
    struct Node* next_node;
} Node;

Node* create_node(void) {
    Node* first_node = malloc(sizeof *first_node);

    if (first_node == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    first_node->node_index = 0;
    first_node->next_node = NULL;

    return first_node;
}

Node* append_node(Node* prev_node) {
    Node* new_node = create_node();
    prev_node->next_node = new_node;
    new_node->node_index = prev_node->node_index + 1;
    new_node->next_node = NULL;

    return new_node;
}

Node* generate_linked_list (int number_of_nodes) {
    Node* first = create_node();
    Node* current = first;

    for (int i = 1; i < number_of_nodes; i++) {
        Node* new_node = append_node(current);
        current = new_node;
    }
    return first;
}

void view_nodes(Node* first_node) {
    Node* current_node = first_node;

    while(current_node != NULL) {
        printf("%d\n", current_node->node_index);
        current_node = current_node->next_node;
    }
}

void scrub_list(Node* first_node) {
    Node* current_node = first_node;
    Node* next_node = current_node->next_node;
    while (current_node != NULL) {
        next_node = current_node->next_node;
        printf("Scrubbed node %d from the list\n", current_node->node_index);
        free(current_node);
        current_node = next_node;
    }
}

int main(void) {
    Node* first = create_node();
    Node* second = append_node(first);
    Node* third = append_node(second);
    Node* four = append_node(third);

    view_nodes(first);
    scrub_list(first);

    Node* test = generate_linked_list(10);
    view_nodes(test);
    scrub_list(test);

    return 0;
}