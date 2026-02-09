class Solution {
public:
    vector<int>BSTArray;
    void inorder(TreeNode* root){
        if(root == NULL) return;

        inorder(root->left);
        BSTArray.push_back(root->val);
        inorder(root->right);
    }
    TreeNode* construct(int l,int r){
        if(l > r) return NULL;

        int mid = l + (r-l)/2;

        TreeNode* root = new TreeNode(BSTArray[mid]);

        root->left = construct(l,mid-1);
        root->right = construct(mid+1,r);

        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);

        int l = 0;
        int r = BSTArray.size()-1;

        return construct(l,r);

        
    }
};