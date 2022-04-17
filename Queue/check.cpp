#include <iostream>
using namespace std;
#define SIZE 5
int A[SIZE];
int front = -1;
int rear = -1;

// Function to check if queue is empty or not
bool isempty()
{
    if (front == -1 && rear == -1)
        return true;
    else
        return false;
}

// function to enter elements in queue
void enqueue(int value)
{
    if ((rear + 1) % SIZE == front)
        cout << "Queue is full \n";
    else
    {
        // first element inserted
        if (front == -1)
            front = 0;
        // insert element at rear
        rear = (rear + 1) % SIZE;
        A[rear] = value;
    }
}

// function to delete/remove element from queue
void dequeue()
{
    if (isempty())
        cout << "Queue is empty\n";
    else
        // only one element
        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % SIZE;
}

// function to show the element at front
void showfront()
{
    if (isempty())
        cout << "Queue is empty\n";
    else
        cout << "element at front is:" << A[front];
}
void displayQueue()
{
    if (isempty())
        cout << "Queue is empty\n";
    else
    {
        int i;
        if (front <= rear)
        {
            for (i = front; i <= rear; i++)
                cout << A[i] << " ";
        }
        else
        {
            i = front;
            while (i < SIZE)
            {
                cout << A[i] << " ";
                i++;
            }
            i = 0;
            while (i <= rear)
            {
                cout << A[i] << " ";
                i++;
            }
        }
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
    dequeue();
    enqueue(20);
    enqueue(24);
    //getFront();
    displayQueue();
    getchar();
    return 0;
}