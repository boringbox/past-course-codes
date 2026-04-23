#include <stdio.h>

typedef struct node {
    int data; 
    // pointer to the next node
    struct node* next; //Node* invalid because it has not been defined yet
} Node;

int main(void){
    Node* listhead = NULL; // Node* listhead stores the address of the first node to help us get to other nodes
    Node* Node1 = (Node*) malloc(sizeof(Node));

    (*Node1).data = 1;
    Node1->next = NULL;
    listhead = Node1;


    Node* Node2 = (Node*) malloc(sizeof(Node));
    Node2->data =2;
    Node2->next = NULL;
    listhead->next = Node2;

    Node* Node3 = (Node*) malloc(sizeof(Node));
    Node3->data =5;
    Node3->next = NULL;
    listhead->next->next = Node3;
}
