#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* previous;
        Node* next;
};
void insertAtStart(Node **head, int Data){
    Node* newNode = new Node();
    newNode->data = Data;
    newNode->previous = NULL;
    newNode->next = *head;
    if(*head != NULL){
        (*head)->previous = newNode;
    }
    *head = newNode;
}
void insertAfter(Node **head, int Data, int pos){
    Node* newNode = new Node();
    Node* temp = *head;
    newNode->data=Data;
    for(int i = 1; i<pos ; i++){
        temp = temp->next; 
    }
    (temp->previous)->next = newNode;
    newNode->previous = temp->previous;
    temp->previous = newNode;
    newNode->next = temp;
}
void insertAtEnd(Node **head, int Data){
    Node* newNode = new Node();
    Node* temp = *head;
    newNode->data=Data;
    if(head == NULL){
        *head = newNode;
        return;
    }
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next=newNode;
    newNode->previous=temp;
}
void printList(Node* node){
    Node* last;
    cout<<"\nTraversal in forward direction \n";
    while (node != NULL){
        cout<<" "<<node->data<<" ";
        last = node;
        node = node->next;
    }
    cout<<"\nTraversal in reverse direction \n";
    while (last != NULL){
        cout<<" "<<last->data<<" ";
        last = last->previous;
    }
}

int main(int argc, char const *argv[]){
    Node* head = new Node();
    insertAtStart(&head,12);
    insertAtStart(&head,13);
    insertAtStart(&head,14);
    insertAfter(&head,1,3);
    insertAtEnd(&head,16);
    printList(head);
    return 0;
}
