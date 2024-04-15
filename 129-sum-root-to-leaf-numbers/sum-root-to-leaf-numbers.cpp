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
    void solve(TreeNode* root, vector<string>&ans, string s){
        if(root==NULL){
            return;
        }

        s += to_string(root->val);

        if(root->left==NULL and root->right==NULL){
            ans.push_back(s);
        }else{
            solve(root->left, ans, s);
            solve(root->right, ans, s);
        }
    }
    int sumNumbers(TreeNode* root) {
        vector<string>ans;
        if(root==NULL){
            return 0;
        }
        solve(root, ans, "");
        int sum = 0;
        for(auto it: ans){
            cout<<it<<endl;
            sum += stoi(it);
        }
        return sum;
    }
};