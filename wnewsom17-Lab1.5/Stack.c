//
//  Stack.c
//  wnewsom17-Lab1.5
//
//  Created by William D. Newsom on 3/6/19.
//  Copyright © 2019 William D. Newsom. All rights reserved.
//

#include "Stack.h"

/*
 * The push method will insert a node into the linked list. It will give that node a key value that increases with each addition. This makes it so that we can keep track of what should be removed first on the LIFO system.
 */
void stack_push(Stack* stack, int data){
    if(stack->link == NULL){
        stack->link = (LinkedList*)malloc(sizeof(LinkedList));
        stack->index = 1;
    }
    insert_into_List(stack->link, data, stack->index);
    stack->index ++;
}

/*
 * Prints the stack by calling the linked list print method
 */
void print_stack(Stack* stack){
    printf("This stack contains this linked list.\n");
    print_list(stack->link);
}

/*
 * Peeks at the top of the stack, returning the nodes data
 */
int stack_top(Stack* stack){
    return find(stack->link, stack->index-1);
}

/*
 * Removes the latest inserted node into the stack, and then returns it's data value. The node with the greatest key value is the last node inserted.
 */
int stack_pop(Stack* stack){
    int ret = find(stack->link, stack->index-1);
    remove_from_list(stack->link, stack->index-1);
    stack->index --;
    return ret;
}

/*
 * Will check to see if the stack is empty.
 */
int is_stack_empty(Stack* stack){
    //The linked list isnt allocated
    if(stack->link == NULL){
        return 1;
    }
    //The linked list has been allocated, but has no nodes.
    if (stack->link->head->next == NULL) {
        return 1;
    }
    return 0;
}

/*
 * Frees the stack.
 */
void free_stack(Stack* stack){
    free_nodes(stack->link);
    free(stack->link);
    free(stack);
}
