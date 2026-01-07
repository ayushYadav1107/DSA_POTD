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
    int MOD = 1e9 + 7;
    long long Sum = 0; // total sum of the tree
    long long maxP = 0;

    int findProduct(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int leftSum = findProduct(root->left);
        int rightSum = findProduct(root->right);
        long long S1 = root->val + leftSum + rightSum;
        long long S2 = Sum - S1;
        
        maxP = max(maxP,S1*S2);

        return S1;
    }
    int totalSum(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int leftSubTreeSum = totalSum(root->left);
        int rightSubTreeSum = totalSum(root->right);
        int sum = root->val + leftSubTreeSum + rightSubTreeSum;

        return sum;
    }
    int maxProduct(TreeNode* root) {
        if(root==NULL){
            return 0;
        }

        Sum = totalSum(root);

        findProduct(root);

        return maxP%MOD;
    }
};