#pragma once

typedef struct node {
    int value;
    struct node* next;
} node_t;

typedef struct linked_list {
    struct node* head;
} linked_list_t;


node_t* create_node(int value);
void add_node_to_start_of_list(linked_list_t* list, node_t* node);
void add_node_to_end_of_list(linked_list_t* list, node_t* node);
void insert_node_to_a_position(linked_list_t* list, node_t* node, int position);
void remove_tail_node(linked_list_t* list);
void remove_head_node(linked_list_t* list);
void remove_node_from_a_position(linked_list_t* list, int position);
void reverse_list(linked_list_t* list);
void print_out_list(linked_list_t* list);