//
//  Stack.c
//  wnewsom17-Lab1.5
//
//  Created by William D. Newsom on 3/6/19.
//  Copyright © 2019 William D. Newsom. All rights reserved.
//

#include "Stack.h"
void stack_push(Stack* stack, int data){
    if(stack->link == NULL){
        stack->link = (LinkedList*)malloc(sizeof(LinkedList));
        stack->index = 1;
    }
    insert_into_List(stack->link, data, stack->index);
    stack->index ++;
}

void print_stack(Stack* stack){
    printf("This stack contains this linked list.\n");
    print_list(stack->link);
}
int stack_top(Stack* stack){
    return find(stack->link, stack->index-1);
}

int stack_pop(Stack* stack){
    int ret = find(stack->link, stack->index-1);
    remove_from_list(stack->link, stack->index-1);
    stack->index --;
    return ret;
}

int is_stack_empty(Stack* stack){
    if(stack->link == NULL){
        return 1;
    }
    if (stack->link->head->next == NULL) {
        return 1;
    }
    return 0;
}
void free_stack(Stack* stack){
    free_nodes(stack->link);
    free(stack->link);
    free(stack);
}
