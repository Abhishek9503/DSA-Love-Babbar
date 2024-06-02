#include <iostream>
#include <queue>
#include <stack>

using namespace std;

void reversek(queue<int> &q, int k)
{

    stack<int> s;
    int count = 0;
    int n = q.size();

    if (k == 0 || k > n)
    {
        return;
    }

    // step 1 queue se stack me dali
    while (!q.empty())
    {
        int temp1 = q.front();
        q.pop();

        s.push(temp1);
        count++;

        if (count == k)
        {
            break;
        }
    }

    // step 2 put all the element from stack to queu
    while (!s.empty())
    {
        int temp = s.top();
        s.pop();

        q.push(temp);
    }

    // step 2 push n-k element from front to back of the queue
    count = 0;
    while (!q.empty() && n - k != 0)
    {
        int element = q.front();
        q.pop();

        q.push(element);
        count++;

        if (count == n - k)
        {
            break;
        }
    }
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
    reversek(q, 5);

    cout << "Printing revesed queue" << endl;
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}