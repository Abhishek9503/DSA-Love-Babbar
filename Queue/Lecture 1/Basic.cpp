#include <iostream>
#include <queue>

using namespace std;

class Queue
{
public:
    int *arr;
    int size;
    int front;
    int rear;

    Queue(int size)
    {
        this->size = size;
        arr = new int[size];
        front = 0;
        rear = 0;
    }

    void push(int data)
    {
        if (rear == size)
        {
            cout << "q is full" << endl;
        }
        else
        {
            arr[rear] = data;
            rear++;
        }
    }

    void pop()
    {
        if (front == rear)
        {
            cout << "q is empty" << endl;
        }
        else
        {
            arr[front] = -1;
            front++;
            if (front == rear)
            {
                front = 0;
                rear = 0;
            }
        }
    }

    int getFront()
    {
        if (front == rear)
        {
            cout << "Q is empty" << endl;
            return -1;
        }
        else
        {
            return arr[front];
        }
    }

    bool isEmpty()
    {
        if (front == rear)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int getSize()
    {

        int size = rear - front;
        return size;
    }
};

int main()
{

    // // creation of queue
    // queue<int> q;

    // q.push(5);
    // q.push(10);
    // q.push(15);
    // q.push(20);

    // cout << "Size of queue is " << q.size() << endl;
    // q.pop();
    // cout << "Size of queue is " << q.size() << endl;

    // if (q.empty())
    // {

    //     cout << "Queue is  empty" << endl;
    // }
    // else
    // {
    //     cout << "Q is not empty" << endl;
    // }

    Queue q(10);

    q.push(5);
    q.push(15);
    q.push(25);
    q.push(35);

    // size
    cout << "Size of queue is " << q.getSize() << endl;

    q.pop();

    cout << "Size of queue is " << q.getSize() << endl;

    // front element is
    cout << "Fron  of queue is " << q.getFront() << endl;

    if (q.isEmpty())
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        cout << "Queue is not empty" << endl;
    }

    return 0;
}