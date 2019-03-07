//
//  main.c
//  wnewsom17-Lab1.5
//
//  Created by William D. Newsom on 3/4/19.
//  Copyright © 2019 William D. Newsom. All rights reserved.
//

#include <stdio.h>
#include "LinkedList.h"
#include "Stack.h"


int main(int argc, const char * argv[]) {
    LinkedList*l = (LinkedList*)malloc(sizeof(LinkedList));
    l->head = NULL;
    
    insert_into_List(l, 2, 2);
    insert_into_List(l, 5, 5);
    insert_into_List(l, 4, 4);
    insert_into_List(l, 3, 3);
    
    insert_into_List(l,1, 1);
    insert_into_List(l,6, 6);
    print_list(l);
    
    remove_from_list(l, 6);
    remove_from_list(l, 2);
    remove_from_list(l, 5);
    
    print_list(l);
    
    printf("Is key of 3 in the list = %d \n", is_in_list(l, 3));
    printf("Data of key of 3 in the list = %d\n", find(l, 3));
    
    free_nodes(l);
    print_list(l);
    free(l);
    
    Stack* st = (Stack*)malloc(sizeof(Stack));
    st->link = NULL;
    
    printf("Is stack st empty? %d.\n\n",is_stack_empty(st));
    
    stack_push(st, 4);
    stack_push(st, 1);
    stack_push(st, 6);
    print_stack(st);
    
    printf("The top of the stack is %d, and the value popped of of the stack is %d. They should be the same. That value is now removed.\n",stack_top(st), stack_pop(st));
    printf("The next value on the stack is %d.\n\n",stack_top(st));
    print_stack(st);
    
    printf("Is stack st empty? %d.\n\n",is_stack_empty(st));
    
    
    return 0;
}
