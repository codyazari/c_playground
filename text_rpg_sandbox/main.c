#include <stdio.h>
#include <stdlib.h>

typedef struct Room {
    int room_index;
    struct Room* prev_room;
    struct Room* next_room;
} Room;

Room* create_room(void) {
    Room* first_room = malloc(sizeof *first_room);
    if (first_room == NULL) {
        fprintf(stderr, "Mem allocation failed");
        exit(EXIT_FAILURE);
    }
    first_room -> room_index = 0;
    first_room -> next_room = NULL;
    return first_room;
}

Room* append_node(Room* prev_room) {
    Room* new_room = create_room();
    prev_room->next_node = new_room;
    new_node->node_index = prev_node->node_index + 1;
    new_node->next_node = NULL;

    return new_node;
}

int main(void) {
    

    return 0;
}