//
// Created by Erkut on 14.12.2025.
//

#include "linked_list.h"
#include <stddef.h>
#include <stdlib.h>

node_t* create_node(int value) {
    node_t* node = malloc(sizeof(*node));
    //don't know why but there is a chance that malloc might fail to allocate memory
    if (node == NULL) {return NULL;}
    node->value = value;
    node->next = NULL;
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

    while (current != NULL) {
        if (current->next == NULL) {
            current->next = node;
            return;
        }
        current = current->next;
    }
}
void insert_node_to_a_position(linked_list_t* list, node_t* node, int position) {

    /*
     * If the list is empty, just add the node and return.
     * If the given position is greater than the number of elements, add the node to the end.
     * Assume the first element has index 0.
     * For example, insert_node_to_a_position(list, node, 3) inserts the new node at index 3 and shifts the following nodes one position to the right.
     */

    if (position == 0) {
        add_node_to_start_of_list(list, node);
        return;
    }

    node_t* fast = list->head;
    node_t* slow = NULL;
    for (int counter = 0; fast != NULL; slow = fast, fast = fast->next, counter++) {
        if (counter == position) {
            node->next = fast;
            if (slow != NULL) {
                slow->next = node;
            }
            return;
        }
    }

    //if code didn't hit the return statement it means either list is empty or the position exceeds the size
    add_node_to_end_of_list(list, node);
}
void remove_tail_node(linked_list_t* list) {
    if (list->head == NULL || list == NULL) { return; }
    node_t* fast = list->head;
    node_t* slow = NULL;
    //if list has only one element
    if (fast->next == NULL) {
        //remove that single node from the list
        list->head = NULL;
        return;
    }
    for (; fast != NULL; slow = fast, fast = fast->next) {
        if (fast->next == NULL) {
            if (slow != NULL) { slow->next = NULL; free(fast); return; }
        }
    }
}
void remove_head_node(linked_list_t* list) {
    /*
     *As the name suggest removes the head node.
     *If list head is empty, then do nothing
     *If list has only one node, then let the head point to NULL
     */

    if (list->head == NULL || list == NULL) {
        return;
    }
    node_t* new_head = list->head->next;
    free(list->head);
    list->head = new_head;
}
void remove_node_from_a_position(linked_list_t* list, int position);
void reverse_list(linked_list_t* list);
void print_out_list(linked_list_t* list);