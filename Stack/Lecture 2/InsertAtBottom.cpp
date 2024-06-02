#include <iostream>
#include <stack>

using namespace std;

void solve(stack<int> &st, int target)
{
    if (st.empty())
    {
        st.push(target);
        return;
    }
    int topElement = st.top();
    st.pop();

    solve(st, target);

    st.push(topElement);
}

void insertAtBottom(stack<int> &st)
{
    if (st.empty())
    {
        cout << "Stack is empty can't insert at boottom" << endl;
        return;
    }

    int target = 100;
    solve(st, target);
}

int main()
{

    stack<int> st;

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);

    insertAtBottom(st);

    cout << "Printing " << endl;

    while (!st.empty())
    {
        cout << st.top() << endl;
        st.pop();
    }

    return 0;
}
