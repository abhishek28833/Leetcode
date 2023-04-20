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
    
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        queue<pair<TreeNode*,long>> q;
        q.push({root,0});
        int maxi = 0;
        while(!q.empty()){
            int n = q.size();
            int x = q.front().second;
            int first,last;
            for(int i=0;i<n;i++){
                long mi =  q.front().second-x;
                TreeNode* temp = q.front().first;
                if(i==0) first = mi;
                if(i==n-1) last = mi;
                if(temp->left) q.push({temp->left,mi*2+1});
                if(temp->right) q.push({temp->right,mi*2+2});
                q.pop();
            }
            maxi = max(maxi,last-first+1);
           
        }
        return maxi;
    }
};