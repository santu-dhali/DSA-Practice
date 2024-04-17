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
    void solve(TreeNode* root, string str, string &ans){
        if(root==NULL){
            return;
        }
        str = char('a' + root->val) + str;

        if(root->left==NULL and root->right==NULL){
            if(str<ans or ans.size()==0){
                ans = str;
            }
        }
        solve(root->left, str,ans);
        solve(root->right, str,ans);
    }
    string smallestFromLeaf(TreeNode* root) {
        if(root == NULL){
            return "";
        }
        string ans="";
        solve(root, "", ans);
        return ans;
    }
};