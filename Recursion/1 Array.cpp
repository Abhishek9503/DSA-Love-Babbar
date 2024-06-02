#include <iostream>
using namespace std;

void print(int n)
{

    if (n == 0)
        return;

    cout << n << endl;

    print(n - 1);
    cout << n << endl;
}

int main()
{

    int n;
    cout << "ENter the value of n" << endl;

    cin >> n;

    // cout<<"Printing in Decreasing order "<<endl;
    cout << "Printing in Increasing  order " << endl;

    print(n);
}