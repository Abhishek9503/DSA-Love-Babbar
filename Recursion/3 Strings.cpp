// Recursion using strings

#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

void solve(string &str, int i, int j)
{
    if (i >= j)
    {
        return;
    }

    swap(str[i], str[j]);

    solve(str, i + 1, j - 1);
}

// void reverse(string str, int index, string &ans)
// {
//     // base case

//     if (index == str.length())
//         return;

//     // Head rec
//     reverse(str, index + 1, ans);

//     ans.push_back(str[index]);

//     // head;
// }

void subSequence(string str, int index, string ans, vector<string> &output)
{
    // base case

    if (index == str.length())
    {
        // cout << ans << endl;
        output.push_back(ans);
        return;
    }

    // include
    subSequence(str, index + 1, ans + str[index], output);

    // exclude
    subSequence(str, index + 1, ans, output);
}

void addString(string a, string b, int carry, string &ans, int i, int j)
{
    // base case

    if (i < 0 && j < 0 && carry == 0)
    {
        return;
    }

    int first = 0;
    int second = 0;

    if(i >= 0)
    {
        first = a[i] - '0';
    }
    if (j >= 0)
    {
        second = b[j] - '0';
    }

    int sum = first + second + carry;
    int lastDigit = sum % 10;
    carry = sum / 10;

    ans.push_back(lastDigit + '0');

    addString(a, b, carry, ans, i - 1, j - 1);
}

int main()
{

    // string str = "Abhishek";
    // string str = "abc";

    // string ans = "";

    // vector<string> output;

    // reverse(str, 0, ans);

    // subSequence(str, 0, ans, output);
    // cout << "The reversed string : " << ans << endl;

    // cout << "Printing the string vector output  ";
    // for (int i = 0; i < output.size(); i++)
    // {
    //     cout << output[i] << " ";
    // }
    // cout << endl;

    string a = "43";
    string b = "343";

    string ans = "";

    addString(a, b, 0, ans, a.length() - 1, b.length() - 1);
    reverse(ans.begin(), ans.end());
    cout << "Sum is  " << ans << endl;

    return 0;
}