//
// Created by Erkut on 14.12.2025.
//

#include "linked_list.h"
#include <stddef.h>

node_t create_node(int value) {
    node_t node = {
        .value = value,
        .next = NULL
    };
    return node;
}
void add_node_to_start_of_list(linked_list_t* list, node_t* node) {
    if (list->head == NULL) {
        list->head = node;
    } else {
        node->next = list->head;
        list->head = node;
    }
}
void add_node_to_end_of_list(linked_list_t* list, node_t* node) {
    node_t* current = list->head;
    //if list is empty than directly assign the node and end the function
    if (current == NULL) {
        current = node;
        list->head = current;
        return;
    }
    //ya hani varya allah bile şuan ne yaptığımı bilmiyor olabilir
    while (current != NULL) {
        if (current->next == NULL) {
            current->next = node;
            return;
        }
        current = current->next;
    }
}


void insert_node_to_a_position(linked_list_t* list, node_t node, int position);
void remove_tail_node(linked_list_t* list);
void remove_head_node(linked_list_t* list);
void remove_node_from_a_position(linked_list_t* list, int position);
void reverse_list(linked_list_t* list);
void print_out_list(linked_list_t* list);