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

 // dfs using preorder traversal
class Solution {
public:
    map<int,int> mpp;
    void DFS(TreeNode* root,int level){
        if(!root){ // base case
            return;
        }
        mpp[level] += root->val;
        DFS(root->left,level+1); // inorder traversal
        DFS(root->right,level+1);

    }
    int maxLevelSum(TreeNode* root) {
        mpp.clear();

        DFS(root,1);

        int maxSum = INT_MIN;
        int resultLevel = 0;
        for(auto &it : mpp){ // ordered map used
            int level = it.first;
            int sum = it.second;
            if(sum > maxSum){
                resultLevel = level;
                maxSum = sum;
            }
        }
        return resultLevel;
    }
};


// bfs using queue
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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*>q;
        int maxSum = INT_MIN;
        int resultLevel = 0;
        q.push(root);

        int currLevel = 1;
        while(!q.empty()){
            
            int n = q.size();

            int sum = 0;
            // traversing all elements on currLevel
            while(n--){
                TreeNode* node = q.front();
                q.pop();
                sum += node->val;
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            if(sum > maxSum){
                maxSum = sum;
                resultLevel = currLevel;
            }
            currLevel++;
        }
        return resultLevel;
    }
};