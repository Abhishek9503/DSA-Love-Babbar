#include <iostream>
#include <vector>

using namespace std;

void printAllPermutations(int index, vector<string> &output, string str)
{
    // base case
    if (index == str.length())
    {
        output.push_back(str);
        return;
    }

    for (int j = index; j < str.length(); j++)
    {
        swap(str[index], str[j]);

        printAllPermutations(index + 1, output, str);

        // backtrack
        swap(str[index], str[j]);
    }
}

int main()
{
    string str = "xyz";
    int index = 0;

    vector<string> output;

    printAllPermutations(index, output, str);

    cout << "Printing all perms " << endl;

    for (int i = 0; i < output.size(); i++)
    {
        cout << output[i] << " ";
    }

    cout << endl;
    return 0;
}
