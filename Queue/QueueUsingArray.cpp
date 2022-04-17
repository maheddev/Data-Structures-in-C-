#include <iostream>
using namespace std;
#define size 5
int Arr[size];
int front, rear = -1;
bool isEmpty()
{
    if (front == -1 && rear == -1)
        return true;
    else
        return false;
}

void enqueue(int num)
{
    if (rear == size - 1)
    {
        cout << "Queue is Full\n";
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }
        rear++;
        Arr[rear] = num;
    }
}
void dequeue()
{
    if (front == -1 && rear == -1)
    {
        cout << "Queue is Empty\n";
    }
    else
    {
        if (front == rear)
        {
            front = rear = -1;
        }
        else
            front++;
    }
}
void getFront(){
    if(front == -1 && rear == -1){
        cout<<"Queue is Empty\n";
    }
    else{
        cout<<"Front = "<<Arr[front]<<endl;
    }
}
void Display(){
    cout<<"Queue is:";
    for (int i=front; i <= rear; i++)
    {
        cout<<" "<<Arr[i];
    }
    
}

int main(int argc, char const *argv[])
{
    enqueue(12);
    enqueue(13);
    enqueue(14);
    enqueue(15);
    dequeue();
    enqueue(16);
    getFront();
    Display();
    return 0;
}
