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
    TreeNode* solve(TreeNode* root, int val, int depth, int curr){
        if(root == NULL){
            return NULL;
        }
        if(curr == depth-1){
            TreeNode* lnde = root->left;
            TreeNode* rnde = root->right;

            TreeNode* nde = new TreeNode(val);
            TreeNode* nde1 = new TreeNode(val);
            root->left = nde;
            root->right = nde1;

            root->left->left = lnde;
            root->right->right = rnde;

            return root;
        }
        solve(root->left, val, depth, curr+1);
        solve(root->right, val, depth, curr+1);

        return root;
    }
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(root == NULL){
            return NULL;
        }
        if(depth == 1){
            TreeNode* nde = new TreeNode(val);
            nde->left = root;
            return nde;
        }
        
        return solve(root, val, depth, 1);
    }
};