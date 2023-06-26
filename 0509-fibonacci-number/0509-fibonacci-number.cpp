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
    
    int fib(int n) {
        
        int ans= recSolve(n);
        return ans;
        
    }
};