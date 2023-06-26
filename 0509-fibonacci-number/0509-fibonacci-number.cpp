class Solution {
public:
    
    int recSolve(int n){
        //base case
        if(n==1 || n==0){
            return n;
        }
        int ans= recSolve(n-1)+ recSolve(n-2);
        return ans;
    }
    
    int topDownSolve(int n, vector<int> &dp){
        
        if(n==1 || n==0){
            return n;
        }
        
        
        // step 3: check  if ans already exits
        if(dp[n] != -1){
            return dp[n];
        }
        
        //step 2: replace ans with dp[n]
        dp[n]= topDownSolve(n-1,dp)+ topDownSolve(n-2,dp);
            return dp[n];
       
}
    
    int fib(int n) {
        
        // int ans= recSolve(n);
        // return ans;
        
        //step1 create dp arry
        
        vector<int> dp(n+1, -1);
        int ans= topDownSolve(n, dp);
        return ans;
    }
};