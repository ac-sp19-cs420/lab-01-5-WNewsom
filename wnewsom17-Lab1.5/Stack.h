//
//  Stack.h
//  wnewsom17-Lab1.5
//
//  Created by William D. Newsom on 3/6/19.
//  Copyright © 2019 William D. Newsom. All rights reserved.
//

#ifndef Stack_h
#include "LinkedList.h"

#define Stack_h

typedef struct Stack{
    LinkedList* link;
    int index;
} Stack;

void stack_push(Stack* stack, int data);
int stack_pop(Stack* stack);
int stack_top(Stack* stack);
int is_stack_empty(Stack* stack);
void free_stack(Stack* stack);
void print_stack(Stack* stack);


#endif /* Stack_h */
