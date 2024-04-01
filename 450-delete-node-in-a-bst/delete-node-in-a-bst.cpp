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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root != NULL){
            if(key > root->val){
                root->right = deleteNode(root->right,key);
            }else if(key < root->val){
                root->left = deleteNode(root->left, key);
            }else{
                if(!root->left and !root->right){
                    return NULL;
                }else if(!root->left){
                    return root->right;
                }else if(!root->right){
                    return root->left;
                }

                TreeNode* nde = root->left;
                while(nde->right){
                    nde = nde->right;
                }
                root->val = nde->val;
                root->left = deleteNode(root->left, nde->val);
            }
        }
        return root;
    }
};