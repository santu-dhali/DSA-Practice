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
    TreeNode* solve(vector<int>&preorder, int &ind, int bound){
        if(ind>=preorder.size() or preorder[ind]>bound){
            return NULL;
        }
        TreeNode* nde = new TreeNode(preorder[ind++]);
        nde->left = solve(preorder, ind, nde->val);
        nde->right = solve(preorder, ind, bound);

        return nde;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int ind = 0;
        return solve(preorder, ind, INT_MAX);
    }
};