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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* nde = new TreeNode(val);
        TreeNode* node = root;
        nde->left = NULL;
        nde->right  = NULL;

        if(root == NULL){
            return nde;
        }

        while(root != NULL){
            if(val > root->val){
                if(root->right == NULL){
                    root->right = nde;
                    break;
                }
                root = root->right;
            }else{
                if(root->left == NULL){
                    root->left = nde;
                    break;
                }
                root = root->left;
            }
        }
        return node;
    }
};