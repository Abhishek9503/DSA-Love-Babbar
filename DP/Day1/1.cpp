#include <iostream>
#include <vector>

using namespace std;

// int solve(int n)
// {

//     if (n <= 1)
//     {
//         return n;
//     }

//     int ans = solve(n - 1) + solve(n - 2);

//     return ans;
// }

// TOP DOWN APPOROACH

//  Rec + Mem
//  step 1: create a dp array
//  step 2: store the ans
//  step 3: check if dp array already has anser , if yes then reutrn

// int solveMem(int n, vector<int> &dp)
// {

//     if (n <= 1)
//     {
//         return n;
//     }

//     if (dp[n] != -1)
//     {
//         return dp[n];
//     }

//     int ans = solveMem(n - 1, dp) + solveMem(n - 2, dp);
//     // dp[n]= ans;
//     return dp[n] = ans;
// }

// Bottom up approach

// step 1: dp array creation
// step 2: Base case analysis of Rec code and update dp array accordingly
// stpe 3:Find the reange for the changing varibale and copy paste the logic in rec code accordingly

int solveTab(int nthTerm)
{

    // step:1
    vector<int> dp(nthTerm + 1, 0);

    // step 2
    dp[0] = 0;
    dp[1] = 1;

    // step 3:
    for (int n = 2; n <= nthTerm; n++)
    {
        int ans = dp[n - 1] + dp[n - 2];
        dp[n] = ans;
    }

    return dp[nthTerm];
}

int solveVar(int nthTerm)
{
    int prev1 = 1;
    int prev2 = 0;

    cout << "inside var ";
    int curr;

    for (int n = 2; n <= nthTerm; n++)
    {
        int ans = prev1 + prev2;

        curr = ans;
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

int main()
{

    int n;
    cout << "ENter the value of n " << endl;

    cin >> n;

    // step 1;
    // vector<int> dp(n + 1, -1);

    // int ans = solveMem(n, dp);
    // int ans = solveTab(n);
    // int ans = (n);

    // cout << "Ans is  ->  " << solveTab(n) << endl;
    cout << "Ans is  ->  " << solveVar(n) << endl;
    return 0;
}