#include <iostream>
using namespace std;

class DeQueue
{
public:
    int size;
    int *arr;
    int front;
    int rear;

    DeQueue(int size)
    {
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    void pushRear(int data)
    {
        // Queue full
        // Single element case
        // circular queue
        // normal flow

        if ((front == 0 && rear == size - 1))
        {
            cout << "Q is full ,cannot insert " << endl;
            return;
        }
        else if (front == -1)
        {
            front = rear = 0;
            arr[rear] = data;
        }

        else if (rear == size - 1 && front != 0)
        {
            rear = 0;
            arr[rear] = data;
        }
        else
        {
            rear++;
            arr[rear] = data;
        }
    }

    void pushFront(int data)
    {

        if ((front == 0 && rear == size - 1))
        {
            cout << "Q is full ,cannot insert " << endl;
            return ;
        }
        else if (front == -1)
        {
            front = rear = 0;
            arr[front] = data;
        }

        else if (front == 0 && rear != size - 1)
        {
            front = size - 1;
            arr[front] = data;
        }
        else
        {
            front--;
        }
        arr[front]=data;
      }

    void popFront()
    {
        // empyt check
        //  single element
        // circular flow
        // normal flow

        if (front == -1)
        {
            cout << "Queue is empty cannot  pop" << endl;
        }
        else if (front == rear)
        {
            arr[front] = -1;
            front = -1;
            rear = -1;
        }
        else if (front == size - 1)
        {
            front = 0;
        }

        else
        {
            front++;
        }
    }

    void popRear()
    {
        // empyt check
        //  single element
        // circular flow
        // normal flow

        if (front == -1)
        {
            cout << "Queue is empty cannot  pop" << endl;
            return;
        }
        else if (front == rear)
        {
            arr[front] = -1;
            front = -1;
            rear = -1;
        }
        else if (rear = 0)
        {
            rear = size - 1;
        }

        else
        {
            rear--;
        }
    }
};

int main()
{
    cout << "Hello world" << endl;
    return 0;
}