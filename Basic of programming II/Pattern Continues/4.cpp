#include <iostream>
using namespace std;

int main()
{

    int n;
    cout << "Enter value of n";
    cin >> n;
    for (int row = 0; row < n; row++)
    {

        /// half pyramid

        for (int col = 0; col < n - row; col++)
        {
            cout << "*";
        }

        // Space wla pyramid

        for (int col = 0; col < 2 * row + 1; col++)
        {
            cout << " ";
        }

        for (int col = 0; col < n - row; col++)
        {
            cout << "*";
        }
        cout << endl;
    }

    for (int row = 0; row < n; row++)
    {

        /// half pyramid

        for (int col = 0; col < row + 1; col++)
        {
            cout << "*";
        }

        // Space wla pyramid

        for (int col = 0; col < 2 * n - 2 * row - 1; col++)
        {
            cout << " ";
        }

        for (int col = 0; col < row + 1; col++)
        {
            cout << "*";
        }
        cout << endl;
    }
}
