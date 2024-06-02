#include <iostream>
using namespace std;

int main()
{

    int n;
    cout << "Enter value of n";
    cout << endl;
    cin >> n;
    cout << endl;
    for (int row = 0; row < n; row++)
    {
        // spaces

        for (int col = 0; col < n - row - 1; col++)
        {
            cout << " ";
        }

        // starrs
        for (int col = 0; col < 2 * row + 1; col++)
        {
            if (col == 0)
            {
                cout << "*";
            }
            if (col == 2 * row)
            {
                cout << "* ";
            }
            else
            {
                cout << " ";
            }
        }

        cout << endl;
    }

    // Down part

    // Spaces
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < row; col++)
        {
            cout << " ";
        }

        // Star
        for (int col = 0; col < 2 * n - 2 * row - 1; col++)
        {
            if (col == 0 || col == 2 * n - 2 * row - 2)
            {
                cout << "* ";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}