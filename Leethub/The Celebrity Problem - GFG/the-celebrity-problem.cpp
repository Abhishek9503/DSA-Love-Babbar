//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int>st;
        
        // push kr denge all person in the stack
        for(int i=0;i<n;i++)
        {
            st.push(i);
        }
        
        // run discard method, to get the  might be celebrity point
        
        
        while(st.size()!=1)
        {
            int a=st.top(); st.pop();
             int b=st.top(); st.pop();
             
             // if a know b?
             if(M[a][b])
             {
                 st.push(b);
             }
             else
             {
                 // b is  not celebrity  a might be
                 st.push(a);
             }
             
        }
             // check that single perosn remainnign is acutally celebrity
             int mightBeCelebrity=st.top();
             st.pop();
             
             
             // cel should not know anyone 
             for(int i=0;i<n;i++)
             {
                 if(M[mightBeCelebrity][i]!=0)
                 {
                     return -1;
                 }
             }
             
             // everyone sh oudl know the celebrityi it means each column should be 1 excep t diagonal
             
             for(int i=0;i<n;i++)
             {
                 if(M[i][mightBeCelebrity]==0 &&  i!= mightBeCelebrity )
                 {
                     return -1;
                 }
             }
             // aftet al;l this is confirm that out might be clebiryut is the real celebritiy
             
        return mightBeCelebrity;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends