//
//  LinkedList.c
//  wnewsom17-Lab1.5
//
//  Created by William D. Newsom on 3/4/19.
//  Copyright © 2019 William D. Newsom. All rights reserved.
//

#include "LinkedList.h"

/*
 * The insert into the list will handle the situations when a node is inserted into the list.
 */
int insert_into_List(LinkedList* l, int data, int key){
    //The first case is if the list has no values, not even a head yet.
    if(l->head == NULL){
        create_new_List(l, data, key);
        return 1;
    //The second case is if the list already has a head node.
    }else{
        Node* nextNode = l->head->next;
        Node* prevNode = l->head;
        while (nextNode != NULL) {
            //if the key already exists in the linked list
            if (nextNode->key == key) {
                printf("Key Value exists in Linked List");
                return 0;
            }
            //I am organizing the list from low key value to high, so if the next node as a highter key, then the node will be inserted befor that next node
            if (nextNode->key > key) {
                Node* insertNode = (Node*)malloc(sizeof(Node));
                insertNode->data = data;
                insertNode->key = key;
                prevNode->next = insertNode;
                insertNode->next = nextNode;
                return 1;
                
            }
            // This happens if the search ends at the end of the list, so that the inserted node's key value is higher than all other nodes.
            if (nextNode->next ==NULL) {
                Node* insertNode = (Node*)malloc(sizeof(Node));
                insertNode->data = data;
                insertNode->key = key;
                nextNode->next = insertNode;
                insertNode->next = NULL;
                return 1;
            }
            prevNode= prevNode->next;
            nextNode= nextNode->next;
        }
        
    }

    return 0;
}
/*
 *
 */
int is_in_list(LinkedList *l, int key){
    Node* nextNode = l->head->next;
    while (nextNode != NULL) {
        if (nextNode->key == key){
            return 1;
        }
        nextNode = nextNode->next;
    }
    return 0;
}

int find(LinkedList* l, int key){
    Node* nextNode = l->head->next;
    while (nextNode != NULL) {
        if (nextNode->key == key){
            return nextNode->data;
        }
        nextNode = nextNode->next;
    }
    return 0;
}

void create_new_List(LinkedList* l, int data, int key){
    l->head = (Node*)malloc(sizeof(Node));
    Node* nextNode=(Node*)malloc(sizeof(Node));
    nextNode->data = data;
    nextNode->key = key;
    l->head->next = nextNode;
    nextNode->next = NULL;
    
}

void print_list(LinkedList *l){
    Node* nextNode = l->head->next;
    int x= 0;
    while (nextNode != NULL) {
        x++;
        printf("Node %d has data %d and a key of %d.\n", x,nextNode->data,nextNode->key);
        nextNode= nextNode->next;
    }
    printf("\n");
}

int remove_from_list(LinkedList *l, int key){
    Node* nextNode = l->head->next;
    Node* prevNode = l->head;
    while (nextNode != NULL) {
        if(nextNode->key == key){
            prevNode->next =nextNode->next;
            free(nextNode);
            return 1;
        }
        prevNode = prevNode->next;
        nextNode = nextNode->next;
    }
    
    return 0;
}

int* create_array(LinkedList *l){
    Node* nextNode = l->head->next;
    int x = 0;
    
    while (nextNode != NULL) {
        x++;
        nextNode = nextNode->next;
    }
    int array[x];
    
    int i =0;
    while (nextNode != NULL) {
        array[i] = nextNode->data;
        nextNode = nextNode->next;
        i++;
    }
    
    return array;
    
}

void free_nodes(LinkedList *l){
    
    while (l->head-> next != NULL) {
        Node* tempNode = l->head->next;
        l->head->next = tempNode->next;
        free(tempNode);
    }
    free(l->head);
    // Now free the list itself
}
