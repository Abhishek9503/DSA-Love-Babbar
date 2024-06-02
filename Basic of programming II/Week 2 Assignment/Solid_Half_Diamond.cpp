#include <iostream>
using namespace std;

int main()
{

    int n;
    cout << "eneter value of n";
    cin >> n;

    for (int row = 0; row < 2 * n - 1; row++)
    {

        for (int col = 0; col < row + 1; col++)
        {
            cout << "*";
        }
        cout << endl;

        for (int col = 2 * n - 1; col >= 1; col--)
        {
            cout << "*";
        }
    }
}