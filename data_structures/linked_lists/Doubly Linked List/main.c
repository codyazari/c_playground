#include <stdio.h>
#include <stdlib.h>

typedef struct DNode{
    int node_index;
    struct DNode* next; // head
    struct DNode* prev; // tail
} DNode;

typedef struct DList {
    DNode* head; // first node in chain
    DNode* tail; // last node in chain
    int length;  // length of chain
} DList;

DNode* create_dnode(void) {
    DNode* node = malloc(sizeof *node);
    if (node == NULL) {
        fprintf(stderr, "Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    node->node_index = 0;
    node->prev = NULL; // tail
    node->next = NULL; // head
    return node;
}

DList* create_dlist(void) {
    DList* list = malloc(sizeof *list);
    if (list == NULL) {
        fprintf(stderr, "Memory allocation for list wrapper failed");
    }
    list->head = NULL;
    list->tail = NULL;
    list->length = 0;
    return list;
}

DList* append_dnode(DList* list) {
    DNode* dnode = create_dnode();

    if (list->head == NULL) {
        // Empty list, new node is head
        list->tail = dnode;
        list->head = dnode;
        list->length += 1;
        return list;
    } else {
        list->tail->prev = dnode;
        dnode->next = list->tail;
        dnode->node_index = list->tail->node_index + 1;
        list->tail = dnode;
        list->length += 1;
    }

    return list;
}

void view_list(DList* list) {
    DNode* current = list->head;

    while (current != NULL) {

        printf("%d\n", current->node_index);
        current = current->prev;
    }
}

void scrub_list(DList* list) {
    DNode* current = list->head;
    while (current != NULL) {
        DNode* next = current->prev;
        printf("Node %d scrubbed\n", current->node_index);
        free(current);
        current = next;
    }
    free(list);
    printf("List scrubbed\n");
}

// DNode* insert_node(DNode* head, int index) {
//     DNode* new_node = create_dnode();
//     DNode* current_node = head;

//     if ()
// }

int main(void) {
    DList* list = create_dlist();
    list = append_dnode(list);
    printf("%d\n", list->length);
    list = append_dnode(list);
    printf("%d\n", list->length);
    list = append_dnode(list);
    printf("%d\n", list->length);
    list = append_dnode(list);
    printf("%d\n", list->length);
    view_list(list);
    scrub_list(list);
    return 0;
}