#include <iostream>
#include <vector>

using namespace std;

int solve(int dividend, int divisor)
{
    int s = 0;
    int e = dividend;
    int ans = -1;
    int mid = s + (e - s) / 2;

    while (s <= e)
    {
        if (mid * divisor == dividend)
        {
            return mid;
        }
        if (mid * divisor > dividend)
        {
            e = mid - 1;
        }
        else
        {
            ans = mid;
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

int main()
{
    int dividend = 22;
    int divisor = 7;

    int ans = solve(dividend, divisor);

    cout << "Ans is " << ans << endl;

    double finalAns = ans;
    double step = 0.1;
    int n;
    cout << "Write the total no. of float vlaues you want " << endl;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (double j = finalAns; j * divisor <= dividend; j = j + step)
        {
            finalAns = j;
        }
        step = step / 10;
    }
    cout << finalAns << endl;

     return 0;
}