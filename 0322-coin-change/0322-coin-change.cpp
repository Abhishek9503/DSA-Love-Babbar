class Solution {
public:
    
    int solveUsingRecursion(vector<int>&coins , int amount){
        //base case
        
        if(amount==0){
            return 0;
        } 
        
        if(amount<0){
            return INT_MAX;
        }
        
        int mini= INT_MAX;

        for(int i=0; i< coins.size();i++)
        {
            int ans= solveUsingRecursion(coins, amount-coins[i]);
            if(ans!=INT_MAX){
                mini= min(mini, ans +1);
            }
        }
        return mini;
        }
    
    
    //Solve memorizatoin
    
    
    int solveMem(vector<int>&coins , int amount ,vector<int>&dp){
          if(amount==0){
            return 0;
        } 
        
        if(amount<0){
            return INT_MAX;
        }
        
        // check kro ans already exits kra h ki nhni krtra
        if(dp[amount]!= -1){
           return dp[amount]; 
        }
        
        int mini= INT_MAX;

        for(int i=0; i< coins.size();i++)
        {
            int ans= solveMem(coins, amount-coins[i],dp);
            if(ans!=INT_MAX){
                mini= min(mini, ans +1);
            }
        }
        
        dp[amount]=mini;
        return mini;
        
    }
    
    int coinChange(vector<int>& coins, int amount) {
//          int ans= solveUsingRecursion(coins, amount);
        
//         if(ans==INT_MAX)
//             return -1;
//         else
//          return ans;
        
        //memorizaton
        
        vector<int> dp(amount+1,-1);
        
        int ans= solveMem(coins, amount, dp);
        
        if(ans==INT_MAX)
            return -1;
        else
         return ans;
    
        
        
    }
};