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
    unordered_map<int,int> mpp; // node,depth
    int maxD = 0;
    
    TreeNode* LCA(TreeNode* root){
        if(root==NULL || mpp[root->val]==maxD){
            return root;
        }

        TreeNode* l = LCA(root->left);
        TreeNode* r = LCA(root->right);

        if(l && r){
            return root;
        }

        return l != NULL ? l : r;
    }
    
    void findDepth(TreeNode* root,int depth){
        if(root==NULL){
            return;
        }
        mpp[root->val] = depth;
        maxD = max(maxD,depth); // finding max depth
        findDepth(root->left,depth+1);
        findDepth(root->right,depth+1);
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        findDepth(root,0);

        return LCA(root);
    }
};