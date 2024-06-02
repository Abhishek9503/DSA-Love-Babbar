// Max sun of non adjacent element?

#include <iostream>
#include <vector>

using namespace std;

int solve(vector<int> &arr, int index)
{

    // base case

    if (index >= arr.size())
    {
        return 0;
    }

    int incl = arr[index] + solve(arr, index + 2);
    int excl = 0 + solve(arr, index + 1);

    return max(incl, excl);
}

int solveMem(vector<int> &arr, int index, vector<int> &dp)
{

    // base case

    if (index >= arr.size())
    {
        return 0;
    }

    if (dp[index] != -1)
    {
        return dp[index];
    }

    int incl = arr[index] + solveMem(arr, index + 2, dp);
    int excl = 0 + solveMem(arr, index + 1, dp);

    return dp[index] = max(incl, excl);
}

int solveTab(int arr[], int n)
{

    cout << "Phuch gye kay" << endl;

    vector<int> dp(n + 2, 0);

    // base case

    for (int i = n - 1; i >= 0; i--)
    {
        int incl = arr[i] + dp[i + 2];
        int excl = 0 + dp[i + 1];
        dp[i] = max(incl, excl);
    }

    return dp[0];
}

int solveVar(vector<int> arr)
{
    int next1 = 0;
    int next2 = 0;

    int curr;

    int n = arr.size();

    for (int index = n - 1; index >= 0; index--)
    {

        int incl = arr[index] + solve(arr, index + 2);
        int excl = 0 + solve(arr, index + 1);

        curr = max(incl, excl);
        next2 = next1;
        next1 = curr;
    }
    cout << "Returning from varaible function " << endl;
    return curr;
}

int main()
{

    vector<int> arr;

    arr.push_back(2);
    arr.push_back(1);
    arr.push_back(4);
    arr.push_back(9);

    // int arr[] = {2, 1, 4, 9};
    // int n = 4;
    // vector<int> dp(arr.size(), -1);
    // cout << "Answer is  " << solve(arr, 0);
    // cout << "Answer is  " << solveMem(arr, 0, dp);
    // cout << "Answer is  " << solveTab(arr, n);
    cout << "Answer is  " << solveVar(arr);
    return 0;
}
