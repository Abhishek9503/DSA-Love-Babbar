#include <iostream>
#include <stack>

using namespace std;

void insertAtBottom(stack<int> &st, int target)
{

    if (st.empty())
    {
        st.push(target);
        return;
    }

    int topElement = st.top();
    st.pop();

    insertAtBottom(st, target);
    st.push(topElement);
}

void reverse(stack<int> &st)
{

    if (st.empty())
    {
        return;
    }
    int target = st.top();
    st.pop();

    reverse(st);

    insertAtBottom(st, target);
}

int main()
{

    stack<int> st;

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);

    reverse(st);

    cout << "Printing after reversing" << endl;
    while (!st.empty())
    {
        cout << st.top() << endl;
        st.pop();
    }
}
