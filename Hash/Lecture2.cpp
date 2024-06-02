#include <iostream>
#include <queue>

using namespace std;

int main()
{
    priority_queue<int> pq;
    pq.push(2);
    pq.push(3);
    pq.push(4);
    pq.push(5);
    pq.push(6);

    cout << "Top Element" << pq.top() << endl;
    pq.pop();

    cout << "Top Element" << pq.top() << endl;
    pq.pop();

    cout << "Top Element" << pq.top() << endl;
    pq.pop();

    cout << "Top Element" << pq.top() << endl;
    pq.pop();

    cout << "Size is :" << pq.size()
         << endl;

    if (pq.empty())
    {
        cout << "Max heap is emmpty";
    }
    else
    {
        cout << "Max is not emptys";
    }
}
