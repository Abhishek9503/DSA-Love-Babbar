#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    stack<int> v;

    v.push(10);
    v.push(20);
    v.push(30);
    v.push(40);

    stack<int> s;
    s.push(-1);
    int n = v.size();

    vector<int> ans(v.size());
    for (int i = n; i >= 0; i--)
    {
        int curr = v[i];
        while (st.top() >= curr)
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(curr);
    }

    cout << "Printing" << endl;

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}