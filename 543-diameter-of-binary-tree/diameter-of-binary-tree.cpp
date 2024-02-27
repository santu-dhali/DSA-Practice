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
private:
    int Height(TreeNode* root){
        int x=0, y=0;
        if(root==0){
            return NULL;
        }
        x= Height(root->left);
        y= Height(root->right);
        return max(x,y)+1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int op1=0,op2=0,op3=0;
        if(root==0){
            return NULL;
        }
        op1 = diameterOfBinaryTree(root->left);
        op2 = diameterOfBinaryTree(root->right);
        op3 = Height(root->left)+Height(root->right);
        return max(op1,max(op2,op3));
    }
};