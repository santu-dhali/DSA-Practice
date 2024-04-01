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
    void solve(vector<int>&val, TreeNode* &root){
        if(root==NULL){
            return;
        }

        solve(val, root->left);
        val.push_back(root->val);
        solve(val, root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int>val;
        solve(val, root);
        return val[k-1];
    }
};