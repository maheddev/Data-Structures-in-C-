#include<iostream>
using namespace std;
class Node{
    public:
        int data;
        Node* next;
};
void insertNode(Node** Head, int Data){
    Node* new_Node = new Node();
    new_Node->data = Data;
    new_Node->next = *Head;
    *Head = new_Node;
}
void deleteNode(Node** head, int Data){
    Node* temp = *head;
    Node* previous = NULL;
    if(temp != NULL && temp->data == Data){
        *head = temp->next;
        delete temp;
        return;
    }
    else{
        while(temp != NULL && temp->data != Data){
            previous = temp;
            temp = temp->next;
        }
        if (temp == NULL){
            return;
        }
        previous->next = temp->next;
        delete temp;
        
    }
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
    insertNode(&head,1);
    insertNode(&head,2);
    insertNode(&head,3);
    insertNode(&head,4);
    insertNode(&head,5);
    insertNode(&head,6);
    cout<<"Before Deletion: ";
    Display(head);
    deleteNode(&head,3);
    cout<<"\nAfter Deletion: ";
    Display(head);
    return 0;
}
