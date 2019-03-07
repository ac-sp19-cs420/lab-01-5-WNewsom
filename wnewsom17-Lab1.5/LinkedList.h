//
//  LinkedList.h
//  wnewsom17-Lab1.5
//
//  Created by William D. Newsom on 3/4/19.
//  Copyright © 2019 William D. Newsom. All rights reserved.
//

/*
 * The linked list header defines all of the linked list methods, the linked list, and the nodes in the list.
 */
#ifndef LinkedList_h
#define LinkedList_h

#include <stdio.h>
#include <stdlib.h>

/*
 * The node struct contains a poiter to the next node, a stored data value, and a key value.
 */
typedef struct Node{
    struct Node* next;
    int key;
    int data;
} Node;

/*
 * The linked list will hold onto a single head node that will hod onto the rest of the nodes.
 */
typedef struct LinkedList{
    struct Node* head;
} LinkedList;

int insert_into_List(LinkedList* l, int data, int key);
int is_in_list(LinkedList *l, int key);
int find(LinkedList* l, int key);
int remove_from_list(LinkedList *l, int key);
void print_list(LinkedList *l);
int* create_array(LinkedList *l);
void  create_new_List(LinkedList* l, int data, int key);
void free_nodes(LinkedList *l);

#endif /* LinkedList_h */
