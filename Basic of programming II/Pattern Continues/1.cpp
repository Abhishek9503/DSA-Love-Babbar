#include <iostream>
using namespace std;

int main()
{

    int n;
    cout << "Enter the value of n  : ";
    cin >> n;

    for (int row = 0; row < n; row++)
    {
        // spce
        for (int col = 0; col < n - row - 1; col++)
        {
            cout << " ";
        }

        // stars
        for (int col = 0; col < row + 1; col++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}