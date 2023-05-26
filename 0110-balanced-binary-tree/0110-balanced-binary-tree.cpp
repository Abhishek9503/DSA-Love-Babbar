/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
int height(TreeNode* root)
{
    if(root==NULL) return 0;
    
    int leftHeight=height(root->left);
        int rightHeight=height(root->right);
    int ans= 1+max(leftHeight,rightHeight);
    
    return ans;
}
    
    
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
        
         int leftHeight=height(root->left);
        int rightHeight=height(root->right);
        int diff=abs(leftHeight-rightHeight);
        
        bool ans1=(diff<=1);
        
        //recursino
        int leftAns=isBalanced(root->left);
        int rightAns=isBalanced(root->right);
        
        
        if(leftAns&& rightAns &&ans1)
        {
            
            return true;
            
        }
        
        else{
            return false;
        }
        
    }
};