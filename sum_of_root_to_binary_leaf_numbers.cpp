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
    int solve(TreeNode* root,int val){
        if(root==NULL){
            return 0;
        }
        
        val = (2*val) + root->val; // for each bit it gets left shift by 1 and the current bit is placed at last

        if(root->left==NULL && root->right==NULL){ // leaf node
            return val;
        }

        return solve(root->left,val) + solve(root->right,val); // finds the sum from left and right subtrees
    }
    int sumRootToLeaf(TreeNode* root) {
        return solve(root,0);
    }
};