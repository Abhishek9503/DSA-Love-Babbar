class Solution {
public:
    string removeDuplicates(string s) {
    int i=0;
    string ans="";
    
        while(i<s.length())
        {
         if ( (ans.length()>0) && ans[ans.length()-1]==s[i])
         {
             ans.pop_back();
         }
            else
            {
                ans.push_back(s[i]);
            }
        i++;
        }
        return ans;
        
    }
};
        
        
        
        
        //         int i=0;
//         int n=s.length();
//           string ans="";

//         for(int i=0;i<n;i++) 
//         {
            
//             if(ans.length() > 0 )
//             {
//                   if(ans[ans.length()-1]==s[i])
//                   {
//                    ans.pop_back();
//                   }
//                 else
//                 {
//                 ans.push_back(s[i]);
//                 }
//             }
//             else
//             {
//                 ans.push_back(s[i]);
//             }
//         }
//         return ans;
        
        
//     }
// };