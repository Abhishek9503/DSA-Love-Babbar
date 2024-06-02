#include <iostream>
#include <stack>

using namespace std;

void InsertSorted(stack<int> &st, int target)
{
    if (st.empty())
    {
        st.push(target);
        return;
    }

    if (st.top() >= target)
    {
        st.push(target);
        return;
    }

    int topElement = st.top();
    st.pop();

    InsertSorted(st, target);

    st.push(topElement);
}

void sortstack(stack<int> &st)
{

    if (st.empty())
    {
        return;
    }

    int topElement = st.top();
    st.pop();

    sortstack(st);

    InsertSorted(st, topElement);
}

int main()
{

    stack<int> st;

    st.push(100);
    st.push(20);
    st.push(50);
    st.push(40);

    // int target = 35;

    sortstack(st);
    while (!st.empty())
    {
        cout << st.top() << endl;
        st.pop();
    }
}
