//
//  Queue.h
//  wnewsom17-Lab1.5
//
//  Created by William D. Newsom on 3/7/19.
//  Copyright © 2019 William D. Newsom. All rights reserved.
//

#ifndef Queue_h

#include "LinkedList.h"

#define Queue_h
typedef struct Queue{
    LinkedList* link;
    int index;
} Queue;

void queue_push(Queue* q, int data);
int queue_pop(Queue* q);
void print_queue(Queue* q);
int queue_last(Queue* q);
int is_empty_queue(Queue* q);
void free_queue(Queue* q);

#endif /* Queue_h */
