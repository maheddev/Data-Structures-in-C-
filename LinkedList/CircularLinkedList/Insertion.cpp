#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        struct Node *next_Node;
        struct Node *previous_Node;
};
void insert_At_Start(Node** head, int Data){
    Node *tail = (*head)->previous_Node;
    Node* new_node = new Node;
    new_node->data = Data;
    new_node->next_Node = *head;
    new_node->previous_Node = tail;

    tail->next_Node = (*head)->previous_Node;
    (*head)->previous_Node = new_node;
    *head = new_node;
}
void Insertion_At_End(Node** head, int Data){
    if (*head == NULL){
        Node* new_node = new Node;
        new_node->data = Data;
        new_node->next_Node = new_node->previous_Node = new_node;
        *head = new_node;
        return;
    }
    Node *tail = (*head)->previous_Node;
    Node* new_node = new Node;
    new_node->data = Data;
    new_node->next_Node = *head;
    (*head)->previous_Node = new_node;
    new_node->previous_Node = tail;
    tail->next_Node = new_node;
}
void insert_between(Node** head, int Data, int Loc){
    Node* new_node = new Node;
    new_node->data = Data;
    Node *temp = *head;
    while (temp->data != Loc){
        temp = temp->next_Node;
    }
    Node *next_Node = temp->next_Node;
    temp->next_Node = new_node;

    new_node->previous_Node = temp;
    new_node->next_Node = next_Node;
    next_Node->previous_Node = new_node;
}
void printer_function(struct Node* head){
    Node *temp = head;
    cout<<"Data Stored: ";
    while (temp->next_Node != head){
        cout<<" "<<temp->data;
        temp = temp->next_Node;
    }
    cout<<" "<<temp->data<<endl;
}
int main(int argc, char const *argv[]){
    Node* s = NULL;
    Insertion_At_End(&s, 1);
    insert_At_Start(&s, 2);
    Insertion_At_End(&s, 3);
    Insertion_At_End(&s, 4);
    insert_between(&s, 6, 3);
    printer_function(s);
    getchar();
    return 0;
}