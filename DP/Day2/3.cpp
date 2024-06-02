// minimum number of coins

// Rod of n length  cut in size a, b , c  the tast is to maximize the number of cuts

#include <iostream>
#include <vector>

using namespace std;

int minCoin(int target, vector<int> &arr)
{
    if (target == 0)
        return 0;

    if (target < 0)
        return INT_MAX;

    int mini = INT_MAX;

    for (int i = 0; i < arr.size(); i++)
    {
        int ans = min(ans, minCoin(target - arr[i], arr));

        // u r aable to build up target
        if (ans != INT_MAX)
        {
            mini = min(mini, 1 + ans);
        }
    }

    return mini;
}

int minCoinTab(int target, vector<int> &arr, vector<int> &dp)
{
    if (target == 0)
        return 1;

    if (target < 0)
    {
        return INT_MIN;
    }
    if (dp[target] != -1)
    {
        return dp[target];
    }
    int mini = INT_MAX;

    for (int i = 0; i < arr.size(); i++)
    {
        int ans = min(ans, minCoin(target - arr[i], arr));

        // u r aable to build up target
        if (ans != INT_MAX)
        {
            mini = min(mini, 1 + ans);
        }
    }

    return dp[target] = mini;
}

int main()
{

    int target = 7;
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);

    // int ans = minCoin(target, arr);

    // cout << "Answer is :" << ans << endl;

    vector<int> dp(target + 1, -1);

    int ans = minCoinTab(target, arr, dp);

    cout << "MAx cuts are " << ans << endl;

    return 0;
}
