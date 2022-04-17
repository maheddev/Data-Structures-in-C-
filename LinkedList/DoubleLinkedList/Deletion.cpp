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
void deletes(Node **head, int loc){
    Node* del = *head;
    
    //for(int i = 1; i<loc; i++){
    //    del=del->next;
    //}

    while(del->data != loc){
        del=del->next;
    }
    if(*head == NULL || del == NULL)
        return;
    if(*head == del)
        *head = del->next;
    if (del->next != NULL)
        del->next->previous = del->previous;
    if (del->previous != NULL)
        del->previous->next = del->next;
    free(del);
    return;
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
    printList(head);
    deletes(&head,13);
    printList(head);
    return 0;
}
