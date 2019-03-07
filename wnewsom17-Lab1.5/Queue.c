//
//  Queue.c
//  wnewsom17-Lab1.5
//
//  Created by William D. Newsom on 3/7/19.
//  Copyright © 2019 William D. Newsom. All rights reserved.
//

#include "Queue.h"

void queue_push(Queue* q, int data){
    if(q->link == NULL){
        q->link = (LinkedList*)malloc(sizeof(LinkedList));
        q->index = 1;
    }
    insert_into_List(q->link, data, q->index);
    q->index ++;
}
void print_queue(Queue* q){
    printf("This Queue contains this linked list.\n");
    print_list(q->link);
}
int queue_last(Queue* q){
    return q->link->head->next->data;
}

int queue_pop(Queue* q){
    int ret = q->link->head->next->data;
    remove_from_list(q->link, q->link->head->next->key);
    q->index --;
    return ret;
}

int is_empty_queue(Queue* q){
    if(q->link == NULL){
        return 1;
    }
    if (q->link->head->next == NULL) {
        return 1;
    }
    return 0;
}
void free_queue(Queue* q){
    free_nodes(q->link);
    free(q->link);
    free(q);
}
