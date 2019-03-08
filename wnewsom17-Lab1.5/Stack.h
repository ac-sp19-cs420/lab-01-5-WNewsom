//
//  Stack.h
//  wnewsom17-Lab1.5
//
//  Created by William D. Newsom on 3/6/19.
//  Copyright © 2019 William D. Newsom. All rights reserved.
//

/*
 * A stack is an implemetation of a linked list that pops off nodes on a LIFO system.
 */
#ifndef Stack_h
#include "LinkedList.h"

#define Stack_h

/*
 * All a stack needs is a link list, and an index to organize the nodes in the linked list, to insure that the last inserted node is being removed.
 */
typedef struct Stack{
    LinkedList* link;
    int index;
} Stack;

/*
 * Many are just implemetations of the linked list methods
 */
void stack_push(Stack* stack, int data);
int stack_pop(Stack* stack);
int stack_top(Stack* stack);
int is_stack_empty(Stack* stack);
void free_stack(Stack* stack);
void print_stack(Stack* stack);


#endif /* Stack_h */
