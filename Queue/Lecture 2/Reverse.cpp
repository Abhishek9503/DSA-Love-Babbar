#include <iostream>
#include <queue>
#include <stack>

using namespace std;

void reverseQueue(queue<int> &q)
{
    stack<int> s;

    // step 1 queue se stack me dali
    while (!q.empty())
    {
        int element = q.front();
        q.pop();

        s.push(element);
    }

    // step 2 put all the element from stack to queu
    while (!s.empty())
    {
        int temp = s.top();
        s.pop();

        q.push(temp);
    }
}

void reverseRecursion(queue<int> &q)
{
    // base case
    if (q.empty())
    {
        return;
    }

    // step A
    int temp = q.front();
    q.pop();

    // stepB
    reverseRecursion(q);

    // step C
    q.push(temp);
}

int main()
{
    queue<int> q;
    q.push(3);
    q.push(6);
    q.push(9);
    q.push(2);
    q.push(8);

    // reverseQueue(q);
    reverseRecursion(q);

    cout << "Printing revesed queue" << endl;
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}