#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "ENTer value of n";
    cin >> n;

    for (int row = 0; row < n; row++)
    {
        // spaces
        for (int col = 0; col < row; col++)
        {
            cout << " ";
        }

        // stars
        for (int col = 0; col < n - row; col++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}