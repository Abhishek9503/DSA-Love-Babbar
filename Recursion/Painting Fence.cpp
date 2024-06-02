#include <iostream>

using namespace std;

int solve(int n, int k)
{
    if (n == 1)
        return k;

    if (n == 2)
        return k * k;

    int same = solve(n - 2, k) * (k - 1);
    int diff = solve(n - 1, k) * (k - 1);

    int ans = same + diff;
    return ans;
}

int main()
{

    int n = 5;
    int k = 3;

    int ans = solve(n, k);
    cout << "Ans is " << ans << endl;

    return 0;
}