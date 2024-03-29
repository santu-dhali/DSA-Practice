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
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* nde = root;
        while(nde!=NULL){
            if(val == nde->val){
                return nde;
            }else if(val < nde->val){
                nde = nde->left;
            }else if(val > nde->val){
                nde = nde->right;
            }
        }
        return NULL;
    }
};