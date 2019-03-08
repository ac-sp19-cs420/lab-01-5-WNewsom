//
//  LinkedList.c
//  wnewsom17-Lab1.5
//
//  Created by William D. Newsom on 3/4/19.
//  Copyright © 2019 William D. Newsom. All rights reserved.
//

#include "LinkedList.h"
#define MAX_ARRAY_SIZE 20

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
 * This method will test to see if a node with the given key is in the list.
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

/*
 * This will return the data of the given node if the given key value is in the list
 */
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

/*
 * This method will create the first node in the linked list.
 */
void create_new_List(LinkedList* l, int data, int key){
    l->head = (Node*)malloc(sizeof(Node)); //allocating data for the head
    Node* nextNode=(Node*)malloc(sizeof(Node)); //creating the next node after the head
    nextNode->data = data;
    nextNode->key = key;
    l->head->next = nextNode;
    nextNode->next = NULL;
    
}

/*
 * This method will print the list. It will give a the node's key and data values.
 */
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

/*
 * This will remove a node with the key value from the list.
 */
int remove_from_list(LinkedList *l, int key){
    Node* nextNode = l->head->next;
    Node* prevNode = l->head;
    while (nextNode != NULL) {
        if(nextNode->key == key){
            prevNode->next =nextNode->next; //skips the deleted node
            free(nextNode);
            return 1;
        }
        prevNode = prevNode->next;
        nextNode = nextNode->next;
    }
    
    return 0;
}

/*
 * This method will return a int pointer to an array.
 */
int* create_array(LinkedList *l){
    Node* nextNode = l->head->next;
    static int array[MAX_ARRAY_SIZE]; //Will create an array of the max size
   
    nextNode = l->head->next;
    int i =0;
    while (nextNode != NULL) {
        array[i] = nextNode->data; // Writes to the array
        nextNode = nextNode->next;
        i++;
    }
    
    return array;
    
}

/*
 * THis will free all of the nodes in the list
 */
void free_nodes(LinkedList *l){
    // frees all the nodes other than the head
    while (l->head-> next != NULL) {
        Node* tempNode = l->head->next;
        l->head->next = tempNode->next;
        free(tempNode);
    }
    free(l->head); // frees the head
    // Now free the list itself
}
