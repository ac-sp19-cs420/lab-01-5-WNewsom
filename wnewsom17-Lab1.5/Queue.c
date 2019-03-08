//
//  Queue.c
//  wnewsom17-Lab1.5
//
//  Created by William D. Newsom on 3/7/19.
//  Copyright © 2019 William D. Newsom. All rights reserved.
//

#include "Queue.h"

/*
 * In order to remove the modes in a FIFO system, to push a node on to the queue we use a constantly increasing key value.
 */
void queue_push(Queue* q, int data){
    if(q->link == NULL){
        q->link = (LinkedList*)malloc(sizeof(LinkedList));
        q->index = 1;
    }
    insert_into_List(q->link, data, q->index);
    q->index ++;
}
/*
 * Prints the queue by using the linked list print method
 */
void print_queue(Queue* q){
    printf("This Queue contains this linked list.\n");
    print_list(q->link);
}
/*
 * Looks at the node that will be removed next
 */
int queue_last(Queue* q){
    return q->link->head->next->data;
}

/*
 * Unlike in the stack, we dont have to keep track of index, because the First node inserted on the list is always going to be the one that the head node holds onto. So on the first removal, the key value of 1 will be removed, then on the second 2, and so on.
 */
int queue_pop(Queue* q){
    int ret = q->link->head->next->data;
    remove_from_list(q->link, q->link->head->next->key);
    q->index --;
    return ret;
}

/*
 * Checks to see if the linked list in the queue is emply or not yet allocated
 */
int is_empty_queue(Queue* q){
    if(q->link == NULL){
        return 1;
    }
    if (q->link->head->next == NULL) {
        return 1;
    }
    return 0;
}
/*
 * Frees the queue
 */
void free_queue(Queue* q){
    free_nodes(q->link);
    free(q->link);
    free(q);
}
