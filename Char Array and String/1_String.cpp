#include <iostream>
#include <string>

using namespace std;
bool compareString(string a, string b)
{
    if (a.length() != b.length())
        return false;

    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] != b[i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string str;

    cin >> str;

    cout << str;

    cout << "  Length" << str.length() << endl;
    cout << "Is empty  ->" << str.empty() << endl;

    str.push_back('A');
    cout << str << endl;
    str.pop_back();
    cout << str << endl;

    cout << str.substr(0, 8) << endl;

    string x = "ab";
    string y = "ab";

    if (x.compare(y) == 0)
    {
        cout << "A and b are exactly same string" << endl;
    }
    else
    {
        cout << "a and b are not same" << endl;
    }

    return 0;
}