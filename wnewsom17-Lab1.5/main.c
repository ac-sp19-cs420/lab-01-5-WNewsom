//
//  main.c
//  wnewsom17-Lab1.5
//
//  Created by William D. Newsom on 3/4/19.
//  Copyright © 2019 William D. Newsom. All rights reserved.
//

#include <stdio.h>
#include "LinkedList.h"


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
    
    printf("Is key of 3 in the list = %d \n", is_in_list(l, 3));
    printf("Data of key of 3 in the list = %d\n", find(l, 3));
    
    return 0;
}
