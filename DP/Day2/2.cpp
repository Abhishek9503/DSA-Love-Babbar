// Rod of n length  cut in size a, b , c  the tast is to maximize the number of cuts

#include <iostream>
#include <vector>

using namespace std;

int solve(int n, int a, int b, int c)
{
    if (n == 0)
        return 0;

    if (n < 0)
    {
        return INT_MIN;
    }

    int first = solve(n - a, a, b, c);
    int second = solve(n - b, a, b, c);
    int third = solve(n - c, a, b, c);

    return 1 + max(first, max(second, third));
}

int solveMem(int n, int a, int b, int c, vector<int> &dp)
{
    if (n == 0)
        return 1;

    if (n < 0)
    {
        return INT_MIN;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    int first = solveMem(n - a, a, b, c, dp);
    int second = solveMem(n - b, a, b, c, dp);
    int third = solveMem(n - c, a, b, c, dp);

    return dp[n] = 1 + max(first, max(second, third));
}

int main()
{

    int n = 17;

    int a = 10;
    int b = 11;
    int c = 3;

    // int ans = solve(n, a, b, c);

    // if (ans <= 0)
    // {
    //     ans = -1;
    // }

    // cout << "Answer is :" << ans << endl;

    vector<int> dp(n + 1, -1);

    int ans = solveMem(n, a, b, c, dp);

    if (ans <= 0)
        ans = -1;

    cout << "MAx cuts are " << ans << endl;

    return 0;
}
