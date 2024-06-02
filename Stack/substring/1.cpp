class Solution
{
public:
    bool isValid(string s)
    {
        if (s[0] != 'a')
            return false;

        stack<char> st;

        for (char ch : s)
        {
            if (ch == 'a')
            {
                st.push(ch);
            }
            else if (ch == 'b')
            {
                if (!st.empty() && st.top() == 'a')
                {
                    st.push('b');
                }
                else
                {
                    return false;
                }
            }
            else
            {
                if (!st.empty() && st.top() == 'b')
                {
                    st.pop();
                    if (!st.empty() && st.top() == 'a')
                    {
                        st.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};