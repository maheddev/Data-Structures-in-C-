#include<iostream>
#include<Stack>
using namespace std;
class Node{
    public:
        int data;
        Node* next;
};
void insertAtStart(Node** Head, int Data){
    Node* new_Node = new Node();
    new_Node->data = Data;
    new_Node->next = *Head;
    *Head = new_Node;
}
void insertAfter(Node* head, int Data, int pos){
    Node* new_Node = new Node();
    Node* temp = head;
    for(int i = 1; i<(pos-1) ;i++){
        temp = temp->next;
    }
    new_Node->data = Data;

    new_Node->next = temp->next;
    temp->next = new_Node;
}
void InsertAtEnd(Node** head, int Data){
    Node* new_Node = new Node();
    Node* temp = *head;
    new_Node->data = Data;
    new_Node->next = NULL;
    if(*head == NULL){
        *head = new_Node;
        return;
    }
    while(temp->next != NULL){
        temp= temp->next;
    }
    temp->next=new_Node;
    return;
}
void Display(Node* node){
    while(node != NULL){
        cout<<" "<<node->data;
        node = node->next;
    }
}

int main(int argc, char const *argv[])
{
    Node* head = NULL;
    InsertAtEnd(&head,6);
    insertAtStart(&head,1);
    InsertAtEnd(&head,2);
    insertAtStart(&head,3);
    insertAfter(head,10,2);
    Display(head);
    return 0;
}
