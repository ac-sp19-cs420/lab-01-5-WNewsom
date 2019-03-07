//
//  LinkedList.c
//  wnewsom17-Lab1.5
//
//  Created by William D. Newsom on 3/4/19.
//  Copyright © 2019 William D. Newsom. All rights reserved.
//

#include "LinkedList.h"
int insert_into_List(LinkedList* l, int data, int key){
    if(l->head == NULL){
        create_new_List(l, data, key);
        return 1;
    }else{
        Node* nextNode = l->head->next;
        Node* prevNode = l->head;
        while (nextNode != NULL) {
            if (nextNode->key == key) {
                printf("Key Value exists in Linked List");
                return 0;
            }
            if (nextNode->key > key) {
                Node* insertNode = (Node*)malloc(sizeof(Node));
                insertNode->data = data;
                insertNode->key = key;
                prevNode->next = insertNode;
                insertNode->next = nextNode;
                return 1;
                
            }
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
