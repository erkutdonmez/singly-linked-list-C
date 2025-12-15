#include <stdio.h>
#include "linked_list.h"

int main(void) {
    linked_list_t linked_list = {.head = NULL};

    node_t* node0 = create_node(333);
    node_t* node1 = create_node(5);
    node_t* node2 = create_node(3);
    node_t* node3 = create_node(17);
    node_t* node4 = create_node(31);
    node_t* node5 = create_node(0);
    node_t* node6 = create_node(404);
    node_t* node7 = create_node(500);
    node_t* node8 = create_node(12);


    add_node_to_start_of_list(&linked_list, node0);
    remove_tail_node(&linked_list);
    add_node_to_end_of_list(&linked_list, node1);
    add_node_to_end_of_list(&linked_list, node2);
    add_node_to_end_of_list(&linked_list, node3);
    add_node_to_end_of_list(&linked_list, node4);
    remove_head_node(&linked_list);
    add_node_to_start_of_list(&linked_list, node5);
    //till now 0 -> 333 -> 5 -> 3 -> 17 -> 31
    insert_node_to_a_position(&linked_list, node6, 0);
    insert_node_to_a_position(&linked_list, node7, 123);
    insert_node_to_a_position(&linked_list, node8, 8);

    printf("Yuppi birinci sınıfa geri döndüm");

}