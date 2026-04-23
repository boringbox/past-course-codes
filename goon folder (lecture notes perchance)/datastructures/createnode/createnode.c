#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data; 
    // pointer to the next node
    struct node* next; //Node* invalid because it has not been defined yet
} Node;

typedef struct list{
    Node* head;
} Linkedlist;


Node* createNode(int value){
    Node* newNode = (Node*) malloc(sizeof(Node));
    if(newNode != NULL){
        newNode->data = value;
        newNode->next = NULL;
    }
    return newNode; 
}

bool insertAtFront(Linkedlist *list, int value){
    Node* temp = createNode(value);
    if(temp == NULL){
        return false;
    }
    temp->next = list->head;
    list->head = temp;
    return true;
}

// Function that prints a linked lsit 
void printList(Linkedlist *list){
    Node* Current = list->head;
    while(Current != NULL){
        printf("%d", Current->data);
        Current = Current->next;
    }
}

// Function that inserts at back of the list 
bool insertAtBack(Linkedlist* list, int value){
    Node* current = list->head; 
    while(current->next != NULL){
        current = current->next;
    }
    current->next = createNode(value);
    if(current->next == NULL){
        return insertAtFront(list,value);
    }
}

// Functipn find a node with a value
Node* findFirstNode(Linkedlist* list, int value){
    Node* current = list->head;
    while(current != NULL){
        if(current->data == value){
            return current;
        }
        else
            {current = current->next;
        }
    }
    return NULL;    
}



int main(void){
    Node* head = NULL;
    printf("%d",insertAtFront(&head, 1));
    return 0;
}
