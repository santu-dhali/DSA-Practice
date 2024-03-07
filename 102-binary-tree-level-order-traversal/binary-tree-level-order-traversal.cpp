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
    vector<vector<int>> levelOrder(TreeNode* root) {
       map<int, vector<int>>mp;
       vector<vector<int>>ans;
       queue<pair<TreeNode*, int>>q;
       
       if(root == NULL){
           return ans;
       }
       
       q.push({root, 0});
       
       while(!q.empty()){
           TreeNode* nde = q.front().first;
           int level = q.front().second;
           q.pop();

           mp[level].push_back(nde->val);
           
           if(nde->left){
               q.push({nde->left, level+1});
           }
           if(nde->right){
               q.push({nde->right, level+1});
           }
       }
       for(auto it: mp){
           vector<int>temp;
           for(auto i: it.second){
               temp.push_back(i);
           }
           ans.push_back(temp);
       }
       return ans;
        // queue<TreeNode*>q;
        // vector<vector<int>> ans;
        // vector<int> nodes;
        
        // if (root != NULL) {
        //     q.push(root);
        //     q.push(NULL);
        // }
        
        // while (!q.empty()) {
            
        //     TreeNode* temp = q.front();
        //     if (temp == NULL) {
        //         ans.push_back(nodes);
        //         nodes.clear();
        //         q.pop();
        //         if (!q.empty()) {
        //             q.push(NULL);
        //         }
        //     } else {
        //         if (temp->left) {
        //             q.push(temp->left);
        //         }
                
        //         if (temp->right) {
        //             q.push(temp->right);
        //         }
        //         nodes.push_back(temp->val);
        //         q.pop();
        //     }
        // }
        // return ans;
    }
};